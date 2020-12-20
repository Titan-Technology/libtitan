from __future__ import division
import os
import io
import re
import pyttsx3


def is_raspberry_pi(raise_on_errors=False):
    try:
        with io.open('/proc/cpuinfo', 'r') as cpuinfo:
            found = False
            for line in cpuinfo:
                if line.startswith('Hardware'):
                    found = True
                    label, value = line.strip().split(':', 1)
                    value = value.strip()
                    if value not in ('BCM2708','BCM2709','BCM2835','BCM2836'):
                        if raise_on_errors:
                            raise ValueError(
                                'This system does not appear to be a '
                                'Raspberry Pi.'
                            )
                        else:
                            return False
            if not found:
                if raise_on_errors:
                    raise ValueError('Unable to determine if this system is a Raspberry Pi.')
                else:
                    return False
    except IOError:
        if raise_on_errors:
            raise ValueError('Unable to open `/proc/cpuinfo`.')
        else:
            return False
    return True

def convert_bytes(num):
    #this function will convert bytes to MB.... GB... etc
    for x in ['bytes', 'KB', 'MB', 'GB', 'TB']:
        if num < 1024.0:
            return "%3.1f %s" % (num, x)
        num /= 1024.0

def file_size(file_path):
    #this function will return the file size
    if os.path.isfile(file_path):
        file_info = os.stat(file_path)
        return convert_bytes(file_info.st_size)
    
class SummaryTool(object):
    # Naive method for splitting a text into sentences
    def split_content_to_sentences(self, content):
        content = content.replace("\n", ". ")
        return content.split(". ")

    # Naive method for splitting a text into paragraphs
    def split_content_to_paragraphs(self, content):
        return content.split("\n\n")

    # Caculate the intersection between 2 sentences
    def sentences_intersection(self, sent1, sent2):
        # split the sentence into words/tokens
        s1 = set(sent1.split(" "))
        s2 = set(sent2.split(" "))
        # If there is not intersection, just return 0
        if (len(s1) + len(s2)) == 0:
            return 0
        # We normalize the result by the average number of words
        return len(s1.intersection(s2)) / ((len(s1) + len(s2)) / 2)

    # Format a sentence - remove all non-alphbetic chars from the sentence
    # We'll use the formatted sentence as a key in our sentences dictionary
    def format_sentence(self, sentence):
        sentence = re.sub(r'\W+', '', sentence)
        return sentence

    # Convert the content into a dictionary <K, V>
    # k = The formatted sentence
    # V = The rank of the sentence
    def get_senteces_ranks(self, content):
        # Split the content into sentences
        sentences = self.split_content_to_sentences(content)
        # Calculate the intersection of every two sentences
        n = len(sentences)
        values = [[0 for x in range(n)] for x in range(n)]
        for i in range(0, n):
            for j in range(0, n):
                values[i][j] = self.sentences_intersection(sentences[i], sentences[j])

        # Build the sentences dictionary
        # The score of a sentences is the sum of all its intersection
        sentences_dic = {}
        for i in range(0, n):
            score = 0
            for j in range(0, n):
                if i == j:
                    continue
                score += values[i][j]
            sentences_dic[self.format_sentence(sentences[i])] = score
        return sentences_dic

    # Return the best sentence in a paragraph
    def get_best_sentence(self, paragraph, sentences_dic):
        # Split the paragraph into sentences
        sentences = self.split_content_to_sentences(paragraph)
        # Ignore short paragraphs
        if len(sentences) < 2:
            return ""
        # Get the best sentence according to the sentences dictionary
        best_sentence = ""
        max_value = 0
        for s in sentences:
            strip_s = self.format_sentence(s)
            if strip_s:
                if sentences_dic[strip_s] > max_value:
                    max_value = sentences_dic[strip_s]
                    best_sentence = s
        return best_sentence

    # Build the summary
    def get_summary(self, title, content, sentences_dic):
        # Split the content into paragraphs
        paragraphs = self.split_content_to_paragraphs(content)
        # Add the title
        summary = []
        summary.append(title.strip())
        summary.append("")
        # Add the best sentence from each paragraph
        for p in paragraphs:
            sentence = self.get_best_sentence(p, sentences_dic).strip()
            if sentence:
                summary.append(sentence)
        return ("\n").join(summary)

def summarise(filetext):
    title = """
    
    """
    with open(filetext, 'r') as content_file:
        content = content_file.read()

    # Create a SummaryTool object
    st = SummaryTool()

    # Build the sentences dictionary
    sentences_dic = st.get_senteces_ranks(content)

    # Build the summary with the sentences dictionary
    summary = st.get_summary(title, content, sentences_dic)

    # Print the summary
    print(summary)
    # Print the ratio between the summary length and the original length
    '''print("")
    print("Original Length %s" % (len(title) + len(content)))
    print("Summary Length %s" % len(summary))
    print("Summary Ratio: %s" % (100 - (100 * (len(summary) / (len(title) + len(content))))))'''

def TTS(phase):
    engine = pyttsx3.init()
    engine.say(phase)
    engine.runAndWait()

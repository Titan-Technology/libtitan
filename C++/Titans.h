//Titan C++ Libary
#include<iostream>
#include<sstream>
#include<fstream>
#include<istream>
#include<string>
#include<vector>
#include<cmath>
#include<math.h>
#include<cassert>
#include<cstring>
#include<stdio.h>
//for date & time
#include<ctime>
#ifdef WIN32
    #include<dos.h>
#endif
//for sleep fuction
#include<conio.h>
#ifdef WIN32
    #include<windows.h>
    #include<unistd.h>
#else
    #include<unistd.h>
#endif
#ifdef WIN32
    #include<conio.h>
#else
    #include <termios.h>
#endif
//C libs to use system function
#include<cstdio>
#include<cstdlib>
//Clock Test
#include <time.h>
#ifdef WINDOWS
	#include<direct.h>
	#define GetCurrentDir _getcwd
#else
	#include<unistd.h>
	#define GetCurrentDir getcwd
#endif

using namesapce std;

namespace Titan
{
class AI
{
    void clock_test()
        {
            int frequency_of_primes (int n)
                {
                  int i,j;
                  int freq=n-1;
                  for (i=2; i<=n; ++i)
                    for (j=sqrt(i);j>1;--j)
                        if (i%j==0)
                            {
                                --freq;
                                break;
                            }
                  return freq;
                }
            clock_t t;
            int f;
            t = clock();
            printf ("Calculating...\n");
            f = frequency_of_primes (99999);
            printf ("The number of primes lower than 100,000 is: %d\n",f);
            t = clock() - t;
            printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
        }
}
class time
{
    string get_current_time()
    {
        char time [10];
        _strtime(time);
        return string(time);
    }
    
}
class encryption
{
    string decrypt(string const& msg, string const& key)
        {
            return encrypt(msg, key); 
        }
    string encrypt(string msg, string const& key)
        {
            if(!key.size())
                return msg;
            
            for (string::size_type i = 0; i < msg.size(); ++i)
                msg[i] ^= key[i%key.size()];
            return msg;
        }

class useful_functions
{
    int get_random_number(int lowest,int highest)
        {
            srand((unsigned)time(0));
            int random_integer;
            int range = (highest - lowest) + 1;
            for(int index = 0;index < 20;index++)
                {
                    random_integer = lowest + int(range* rand()/(RAND_MAX + 1.0));
                }
            return random_integer;
        }
    
    string GetCurrentWorkingDir()
        {
            char buff[FILENAME_MAX];
            GetCurrentDir( buff, FILENAME_MAX );
            string current_working_dir(buff);
            return current_working_dir;
        }
    
    string GetStdoutFromCommand(string cmd)
        {
            string data;
            FILE * stream;
            const int max_buffer = 256;
            char buffer[max_buffer];
            cmd.append(" 2>&1");

            stream = popen(cmd.c_str(), "r");
              if (stream)
                {
                    while (!feof(stream))
                        if (fgets(buffer, max_buffer, stream) != NULL)
                            data.append(buffer);
                    pclose(stream);
                }
            return data;
        }
    #ifdef __linux__
        int getch(void)
            {
                struct termios oldattr, newattr;
                int ch;
                tcgetattr( STDIN_FILENO, &oldattr );
                newattr = oldattr;
                newattr.c_lflag &= ~( ICANON | ECHO );
                tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
                ch = getchar();
                tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
                return ch;
            }

        int getche(void)
            {
                struct termios oldattr, newattr;
                int ch;
                tcgetattr( STDIN_FILENO, &oldattr );
                newattr = oldattr;
                newattr.c_lflag &= ~( ICANON );
                tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
                ch = getchar();
                tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
                return ch;
            }
    #endif
    int search_array(string AllTitles[],int TotalRec,string looking)
        {
            for(int i = 0; i < TotalRec; ++i)
                {
                    if (looking == AllTitles[i])
                        {
                            return i;
                        }
                }
        }
}
class cross_lang
{
    class python
    {
        void make_version_txt(string CompanyName,string ProductName,string ProductVersion,string InternalName,string OriginalFilename,string FileVersion,string FileDescription,string LegalCopyright,string LegalTrademarks)
            {
                ofstream myfile;
                myfile.open ("version.txt");
                myfile << "VSVersionInfo( ffi=FixedFileInfo( \n";
                myfile << "# filevers and prodvers should be always a tuple with four items: (1, 2, 3, 4) \n";
                myfile << "# Set not needed items to zero 0. \n";
                myfile << "filevers=(96, 12, 19, 1), prodvers=(4, 1, 2, 1), \n";
                myfile << "# Contains a bitmask that specifies the valid bits 'flags'\n";
                myfile << "mask=0x3f, \n";
                myfile << "# Contains a bitmask that specifies the Boolean attributes of the file. \n";
                myfile << "flags=0x0, \n";
                myfile << "# The operating system for which this file was designed. \n";
                myfile << "# 0x4 - NT and there is no need to change it. \n";
                myfile << "OS=0x4, \n";
                myfile << "# The general type of file. \n";
                myfile << "# 0x1 - the file is an application. \n";
                myfile << "fileType=0x1, \n";
                myfile << "# The function of the file. \n";
                myfile << "# 0x0 - the function is not defined for this fileType \n";
                myfile << "subtype=0x0, \n";
                myfile << "# Creation date and time stamp. \n";
                myfile << "date=(0, 0) ),\n"; 
                myfile << "kids=[\n";
                myfile << "StringFileInfo( [ \n";
                myfile << "StringTable( u'040904b0', [\n";
                myfile << "StringStruct(u'CompanyName', u'" + CompanyName + "'), \n";
                myfile << "StringStruct(u'ProductName', u'" + ProductName + "'), \n";
                myfile << "StringStruct(u'ProductVersion', u'" +  ProductVersion + "'), \n";
                myfile << "StringStruct(u'InternalName', u'" + InternalName + "'), \n";
                myfile << "StringStruct(u'OriginalFilename', u'" + OriginalFilename + "'), \n";
                myfile << "StringStruct(u'FileVersion', u'" + FileVersion + "'), \n";
                myfile << "StringStruct(u'FileDescription', u'" + FileDescription + "'), \n";
                myfile << "StringStruct(u'LegalCopyright', u'" + LegalCopyright + "'), \n";
                myfile << "StringStruct(u'LegalTrademarks', u'" + LegalTrademarks + "'),]) ]), \n";
                myfile << "VarFileInfo([VarStruct(u'Translation', [1033, 1200])]) ] )\n";
                myfile.close();
                cout << "Your version.txt has been Generated" << endl;
            }
    }
}
}
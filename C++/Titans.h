#ifndef Titans
#define Titans
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
#include <time.h>
#ifdef WIN32
    #include<dos.h>
#endif
//for sleep fuction
#ifdef WIN32
    #include<conio.h>
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
#include<SFML/Audio.hpp>
#include<string>
#include<iostream>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

namespace Titan
{
    namespace AI
        {
            int frequency_of_primes(int n);
            void clock_test();
            void addtoarray(string phasetoarray);
            void voice(const string& filename);
            void TTS(string phase);   
        };

    namespace time
        {
            string get_current_time();
        };

    namespace encryption
        {
            string encrypt(string msg, string const& key);
            string decrypt(string const& msg, string const& key);
        };

    namespace useful_functions
        {
            int get_random_number(int lowest,int highest);
            string GetCurrentWorkingDir();
            string GetStdoutFromCommand(string cmd);
            #ifdef __linux__
                int getch(void);
                int getche(void);
            #endif
            int search_array(string AllTitles[],int TotalRec,string looking);
        };

    namespace cross_lang
        {
            namespace python
                {
                    void make_version_txt(string CompanyName,string ProductName,string ProductVersion,string InternalName,string OriginalFilename,string FileVersion,string FileDescription,string LegalCopyright,string LegalTrademarks);
                };
        };
};

#ifdef __cplusplus
}
#endif
#endif

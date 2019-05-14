#ifndef EMOTIONS
#define EMOTIONS
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

using namespace std;

namespace Titan
{
    class AI
        {
            public:
                void clock_test();
            private:
                int frequency_of_primes(int n);
            
        };

    class time
        {
            public:
                string get_current_time();
        };

    class encryption
        {
            public:
                string decrypt(string const& msg, string const& key);
                string encrypt(string msg, string const& key);
        };

    class useful_functions
        {
            public:
                int get_random_number(int lowest,int highest);
                string GetCurrentWorkingDir();
                string GetStdoutFromCommand(string cmd);
                #ifdef __linux__
                    int getch(void);
                    int getche(void);
                #endif
                int search_array(string AllTitles[],int TotalRec,string looking);
        };

    class cross_lang
        {
            public:
                class python
                    {
                        public:
                            void make_version_txt(string CompanyName,string ProductName,string ProductVersion,string InternalName,string OriginalFilename,string FileVersion,string FileDescription,string LegalCopyright,string LegalTrademarks);
                    };
        };
};
#endif
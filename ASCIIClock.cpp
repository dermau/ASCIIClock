#include <iostream>
#include <ctime>
using namespace std;

#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

bool verboseflag = false; 
int screenheight = 5;

string digit[11][5];


int initAssets()
{
    
    // digit 0
    digit [0][0] = "  0000  ";
    digit [0][1] = " 00  00 ";
    digit [0][2] = " 00  00 ";
    digit [0][3] = " 00  00 ";
    digit [0][4] = "  0000  ";

    //digit 1
    digit [1][0] = "   11   ";
    digit [1][1] = "   11   ";
    digit [1][2] = "   11   ";
    digit [1][3] = "   11   ";
    digit [1][4] = "   11   ";

    //digit 2
    digit [2][0] = "   22   ";
    digit [2][1] = " 22  22 ";
    digit [2][2] = "    22  ";
    digit [2][3] = "  22    ";
    digit [2][4] = " 222222 ";

    //digit 3
    digit [3][0] = "   33   ";
    digit [3][1] = " 33  33 ";
    digit [3][2] = "    33  ";
    digit [3][3] = " 33  33 ";
    digit [3][4] = "   33   ";

    //digit 4
    digit [4][0] = "    444 ";
    digit [4][1] = "   4 44 ";
    digit [4][2] = "  4  44 ";
    digit [4][3] = " 4444444";
    digit [4][4] = "     44 ";

    //digit 5
    digit [5][0] = " 555555 ";
    digit [5][1] = " 5      ";
    digit [5][2] = " 55555  ";
    digit [5][3] = "     55 ";
    digit [5][4] = " 55555  ";

    //digit 6
    digit [6][0] = "  6666  ";
    digit [6][1] = " 66     ";
    digit [6][2] = " 66666  ";
    digit [6][3] = " 66  66 ";
    digit [6][4] = "  6666  ";

    //digit 7
    digit [7][0] = " 777777 ";
    digit [7][1] = "    77  ";
    digit [7][2] = "   77   ";
    digit [7][3] = "  77    ";
    digit [7][4] = " 77     ";

    //digit 8
    digit [8][0] = "  8888  ";
    digit [8][1] = " 88  88 ";
    digit [8][2] = "  8888  ";
    digit [8][3] = " 88  88 ";
    digit [8][4] = "  8888  ";

    //digit 9
    digit [9][0] = "  9999  ";
    digit [9][1] = " 99  99 ";
    digit [9][2] = "  99999 ";
    digit [9][3] = "     99 ";
    digit [9][4] = "  9999  ";

    //digit :
    digit [10][0] = "    ";
    digit [10][1] = " :: ";
    digit [10][2] = "    ";
    digit [10][3] = " :: ";
    digit [10][4] = "    ";

    

    return 1;
}



int main(int argc, char* argv[])
{
    int i;
    
    for(i=0; i<argc; ++i)
    {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;

        if(strcmp(argv[i], "-v")|| strcmp(argv[i], "--v") || strcmp(argv[i], "-verbose"))
            {
                verboseflag = true;
                std::cout << "Verbose true." << std::endl;
            }
    }

    if(initAssets())
    {
        if(verboseflag) { std::cout << "Assets initialised." << std::endl; }

        while(true)
        {
            // current date/time based on current system
            time_t now = time(0);
            tm *localtm = localtime(&now);

            int hours = (localtm->tm_hour);
            int minutes = (localtm->tm_min);
            int seconds =(localtm->tm_sec);


            system ("CLS");
            std::cout << '\r' << std::flush; // return to the beginning of the line
            //getAndPrintTime(); 

            // 09:25:38
            int hour0, hour1, minute0, minute1, second0, second1;
            hour0 = (hours/10)%10, hour1 = hours%10, minute0 = (minutes/10)%10, minute1 = minutes%10, second0 = (seconds/10)%10, second1 = seconds%10;

            for (int line = 0; line<screenheight; line++)
            {
                std::cout << digit[hour0][line] << digit[hour1][line] << digit[10][line] << digit[minute0][line] << digit[minute1][line] << digit[10][line] << digit[second0][line] << digit[second1][line] << std::endl;
                
            }

            Sleep(1000);

        }

    }
    else { std::cout << "failed to initialise assets"; }
    
    return 0;
}
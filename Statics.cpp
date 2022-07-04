#include <fstream>
#include <string>

#include "Statics.hpp"

std::string readFile(const std::string & filename)
{
    std::ifstream file;
    file.open(filename);

    std::string output;
    std::string oneLine;

    if (file.is_open())
    {
        while (file.good())
        {
            std::getline(file, oneLine);
            output.append(oneLine + '\n');
        }
    }
    else
    {
        throw std::invalid_argument("Can not open file " + filename);
    }

    return output;
}

#ifdef __unix__
#include <termios.h>
#include <unistd.h>


/*
    Taken from https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
*/


static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    current = old; /* make new settings same as old settings */
    current.c_lflag &= ~ICANON; /* disable buffered i/o */
    if (echo) {
        current.c_lflag |= ECHO; /* set echo mode */
    } else {
        current.c_lflag &= ~ECHO; /* set no echo mode */
    }
    tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

#endif

char getChar()
{
    #ifdef __unix__
    return getch_(0);
    

    #elif defined(_WIN32) || define(WIN32)
    #include <conio.h>
    return _getch();
    #endif
}
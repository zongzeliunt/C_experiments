#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include "soduku.h"
using namespace std;

string get_time() {
    struct timeval theTime;
    gettimeofday(&theTime, NULL);
    char timeStr[256];
    strftime(timeStr, 128, "[%F %X ", localtime(&theTime.tv_sec)); 

    stringstream oss;
    oss << theTime.tv_usec;

    // [2011-08-06 17:01:09 686888]
    string curTime = timeStr + oss.str() + "]";

    return curTime;
}

void search (soduku_class mi)
{ 
    int num;
    if (mi.board_is_complete()) {
        mi.board_display();
        string time = get_time();
        cout<<time<<endl;
        //exit (1);
    }
    else {
        for (num=1;num<=9;num++) {
            if (mi.number_check(num)) {
                soduku_class mi_new;
                mi_new.board_cp (mi);
                mi_new.board_add (num);
                search (mi_new);
            }
        }
    }
}

int main()
{
    string time = get_time();
    cout<<time<<endl;

//=============================================================
 int board_ut_most_hard[9][9] = {{8,0,0, 0,0,0, 0,0,0},
                       {0,0,3 ,6,0,0 ,0,0,0},
                       {0,7,0 ,0,9,0 ,2,0,0},

                       {0,5,0 ,0,0,7 ,0,0,0},
                       {0,0,0 ,0,4,5 ,7,0,0},
                       {0,0,0 ,1,0,0 ,0,3,0},

                       {0,0,1 ,0,0,0 ,0,6,8},
                       {0,0,8 ,5,0,0 ,0,1,0},
                       {0,9,0 ,0,0,0 ,4,0,0}};

 int board_ut[9][9] = {{0,0,0, 0,0,0, 0,1,5},
                       {7,9,0 ,0,0,0 ,0,0,0},
                       {5,1,0 ,2,0,0 ,0,0,0},

                       {0,0,0 ,0,0,8 ,7,0,6},
                       {0,0,1 ,0,0,0 ,0,0,0},
                       {0,0,0 ,0,0,0 ,9,0,0},

                       {0,7,0 ,0,0,0 ,8,3,0},
                       {4,0,0 ,1,5,0 ,0,0,0},
                       {0,0,0 ,3,0,0 ,0,0,0}};


    soduku_class mi;
    mi.board_cp (board_ut);
    search(mi);

//=============================================================



    return 0;
}

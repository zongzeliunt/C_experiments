#include <iostream>
#include <stdio.h>
#include "soduku.h"
using namespace std;

soduku_class::soduku_class()
{
    int i,j;
    for (i=0;i<9;i++) {
        for (j=0;j<9;j++) {
            board[i][j] = 0 ;
        }
    }

}

int soduku_class::board_is_complete ()
{
    int signal = 1;
    int i,j;
    for (i=0;i<9 && signal == 1;i++) {
        for (j=0;j<9 && signal == 1;j++) {
            if (board[i][j] == 0) {
                signal = 0;
            }
        }
    }
    return signal;
}


void soduku_class::board_display ()
{
    int i,j;
    for (i=0;i<9;i++) {
        for (j=0;j<9;j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void soduku_class::board_cp (int mi[9][9]) 
{
    int i,j;
    for (i=0;i<9;i++) {
        for (j=0;j<9;j++) {
            board[i][j] =  mi[i][j] ;
        }
    }
}

void soduku_class::board_cp (soduku_class mi) 
{
    int i,j;
    for (i=0;i<9;i++) {
        for (j=0;j<9;j++) {
            board[i][j] =  mi.board[i][j] ;
        }
    }
}

void soduku_class::board_add (int num)
{   
    int m=get_m();
    int n=get_n();
    board[m][n]=num;
}

int soduku_class::get_m ()
{
    int i,j;
    int m=9;
    for (i=0;i<9;i++) {
        for (j=0;j<9;j++) {
            if (board[i][j] == 0) {
                m=i;
            }
        }
    }
    return m;
}

int soduku_class::get_n ()
{
    int i,j;
    int n;
    for (i=0;i<9;i++) {
        for (j=0;j<9;j++) {
            if (board[i][j] == 0) {
                n=j;
            }
        }
    }
    return n;
}

int soduku_class::number_check (int num)
{
    int signal=1;
    int i,j;
    int m = get_m();
    int n = get_n();
    for (i=0;i<9;i++) {
        if(i==m ) {continue;}
        else {
            if (board[i][n] == num) { signal=0;}
        }
    }
    for (i=0;i<9;i++) {
        if (i==n) {continue;}
        else {
            if (board[m][i] == num) {signal=0;} 
        }
    }
    for (i=0;i<3;i++) {
        for (j=0;j<3;j++) {
            if (i == m%3 || j == n%3) { ;}
            else { 
                if ( board[(m/3)*3+i][(n/3)*3+j] ==num ) {signal=0;}
            }  
        }
    }  

    return signal;
}

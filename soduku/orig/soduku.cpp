#include <iostream>
#include <stdio.h>
using namespace std;
 int board[9][9] = {{3,0,0, 6,0,0, 0,8,0},
                    {9,8,7 ,0,1,4 ,0,0,0},
                    {2,0,0 ,0,3,0 ,1,0,0},

                    {0,7,0 ,0,0,6 ,5,0,0},
                    {5,0,0 ,4,0,9 ,0,0,6},
                    {0,0,9 ,3,5,0 ,0,2,0},

                    {0,9,8 ,0,4,0 ,0,0,5},
                    {4,0,0 ,7,6,5 ,9,1,8},
                    {0,5,0 ,0,0,3 ,0,0,2}};

void search (int mi[9][9])
{ int i=0, j=0, m=9, n=9;
  int signal = 0;
  int num;
  for (i=0;i<9 && signal == 0;i++) {
    for (j=0;j<9 && signal == 0;j++) {
       if (mi[i][j] == 0) {
           signal = 1;
           m=i , n=j;
       }
    }
  }
    if (m==9 && n==9) {
        for (i=0;i<9;i++) {
            for (j=0;j<9;j++) {
                cout<<mi[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    else {
        for (num=1;num<=9;num++) {
            signal=1;
            for (i=0;i<9;i++) {
                if(i==m ) {continue;}
                else {
                    if (mi[i][n] == num) { signal=0;}
                }
            }
            for (i=0;i<9;i++) {
                if (i==n) {continue;}
                else {
                    if (mi[m][i] == num) {signal=0;} 
                }
            }
            for (i=0;i<3;i++) {
                for (j=0;j<3;j++) {
                    if (i == m%3 || j == n%3) { ;}
                    else { 
                        if ( mi[(m/3)*3+i][(n/3)*3+j] ==num ) {signal=0;}
                    }  
                }
            }  
     // if (signal == 1) {mi[m][n] = num , search (mi);}
            if (signal == 1) {
                int mim[9][9];
                for (i=0;i<9;i++) {
                    for (j=0;j<9;j++) {
                        mim[i][j] =  mi[i][j] ;
                    }
                }
                mim[m][n] = num , search (mim);
            }

        }
    }
}

int main()
{
search (board);

 cout<<"hello world\n";
}

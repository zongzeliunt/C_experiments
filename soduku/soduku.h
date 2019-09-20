#include <iostream>
#include <stdio.h>
using namespace std;

class soduku_class {
    private:
        int m;
        int n;
        int board[9][9];
    public :
        void board_cp (soduku_class mi);
        void board_cp (int mi[9][9]);
        int number_check (int num );
        void board_display ();
        int board_is_complete ();
        int get_m();
        int get_n();
        void board_add(int num);
        soduku_class();
} ;


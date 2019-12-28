#include <iostream>
#include <string>
#include "sudoku_base.h"
using namespace std;

int main()
{
	string file_name;
	file_name = "2.txt";
	
	sudoku_base su(file_name);
	su.solver();
	su.show_board();

	return 0;
}

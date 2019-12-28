#include <iostream>
#include <string>
using namespace std;

class sudoku_base {
	private:
		//#define row_num 9
		//#define col_num 9	
		static const int row_num = 9;
		static const int col_num = 9;
		static const int limit = 9;
		static const int step = 3;
		int board[row_num][col_num];		

	public:
		void show_board();
		int* read_file(string file_name);

		sudoku_base(string file_name);
		int* rec_solver(int b[row_num][col_num]);
		void solver();
};

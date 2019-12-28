#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "sudoku_base.h"
using namespace std;
void sudoku_base::show_board() 
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row_num; i ++) {
		for (j = 0; j < col_num; j ++) {
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

void sudoku_base::solver()
{
	int *sol_result_p; 
	sol_result_p = rec_solver(board);
	int i,j;
	for (i = 0; i < row_num; i ++) {
		for (j = 0; j < col_num; j ++) {
			board[i][j] = *(sol_result_p + i * row_num + j);
		}
	}
}

int* sudoku_base::rec_solver(int b[row_num][col_num])
{
	int i,j;	
	int new_b[row_num][col_num];
	int change_i = -1, change_j = -1;
	for (i = 0; i < row_num; i ++) {
		for (j = 0; j < col_num; j ++) {
			new_b[i][j] = b[i][j];
			if (change_i == -1) {
				if (b[i][j] == 0) {
					change_i = i;
					change_j = j;
				}
			}
		}
	}
	int row_range_low, row_range_high;
	if (change_i % step == 0) {
		row_range_low = change_i;
		row_range_high = change_i + 2;
	}
	if (change_i % step == 1) {
		row_range_low = change_i - 1;
		row_range_high = change_i + 1;
	}
	if (change_i % step == 2) {
		row_range_low = change_i - 2;
		row_range_high = change_i;
	}
	int col_range_low, col_range_high;
	if (change_j % step == 0) {
		col_range_low = change_j;
		col_range_high = change_j + 2;
	}
	if (change_j % step == 1) {
		col_range_low = change_j - 1;
		col_range_high = change_j + 1;
	}
	if (change_j % step == 2) {
		col_range_low = change_j - 2;
		col_range_high = change_j;
	}


	int k = 0;
	bool jump = 0;
	for (k = 1; k <= limit; k ++) {
		jump = 0;
		for (i = 0; i < row_num; i ++) {
			if (new_b[i][change_j] == k) {
				jump = 1;
				break;
			}
		} 
		if (jump == 1) {
			continue;
		}

		for (j = 0; j < col_num; j ++) {
			if (new_b[change_i][j] == k) {
				jump = 1;
				break;
			}
		}
		if (jump == 1) {
			continue;
		}

		for (i = row_range_low; i <= row_range_high; i++) {
			for (j = col_range_low; j <= col_range_high; j++) {
				if (new_b[i][j] == k) {
					jump = 1;
					break;
				}
			}
		}
		if (jump == 1) {
			continue;
		}

		new_b[change_i][change_j] = k;
		int *result_pointer;
		if (change_i == row_num - 1 && change_j == col_num - 1) {	
			result_pointer = &new_b[0][0];
			return result_pointer;
		} else {
			result_pointer = rec_solver(new_b);
			if (result_pointer != NULL) {
				return result_pointer;
			}
		}
	} 
	return NULL;
}

int* sudoku_base::read_file(string file_name)
//{{{
{
	ifstream infile;
	infile.open(file_name);
	string tmp_word;
	int result[row_num][col_num];
	int row = 0, col = 0;
	while(!infile.eof())
	{
		infile>>tmp_word;
		result[row][col] = stoi(tmp_word);	
		if (col == 8) {
			row += 1;
			col = 0;
		} else{
			col += 1;
		}
		if (row == 9) {
			break;
		}
	}
	infile.close();
	
	int *result_p;
	result_p = &result[0][0];
	return result_p;
}
//}}}

sudoku_base::sudoku_base(string file_name) 
//{{{
{
	cout<<"this is class constructor"<<endl;
	int i = 0;
	int j = 0;
	for (i = 0; i < row_num; i ++) {
		for (j = 0; j < col_num; j ++) {
			board[i][j] = 0;
		}
	}
	int *read_result_p;
	read_result_p = read_file(file_name);
	
	for (i = 0; i < row_num; i ++) {
		for (j = 0; j < col_num; j ++) {
			//printf("%d ", read_result_p[i * row_num + j]);
			//printf("%d ", *(read_result_p + i * row_num + j));
			board[i][j] = *(read_result_p + i * row_num + j);
		}
	}
}
//}}}

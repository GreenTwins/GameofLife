#include "cell.h"

void cell::draw(int row, int col)const {
	//ansi commands
	//escape => n;mH to move cursor to row n, column m
	//1 based not 0
	std::cout << "\x1b[" << row + 1 << ";" << col + 1 << "H";
	std::cout << alive ? live_cell : dead_cell;
}
#pragma once
#ifndef GRID_H_
#define GRID_H_

#include <string>
#include <vector>
#include <cstdlib>
#include "cell.h"

class grid {
	//using a border that has inactive cells since we arent doing an infinite cell range to calculate next gen of cells
	cell cells[rowMax + 2][colMax + 2];
public:
	void create(int row, int col);
	void draw();
	void randomize();

	bool will_survive(int row, int col);
	bool will_create(int row, int col);

	void update(const grid& next);
};

void calculate(grid& oldgen, grid& newgen);

#endif


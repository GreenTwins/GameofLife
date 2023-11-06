#include "grid.h"

void grid::create(int row, int col) {
	cells[row][col].create();
}

void grid::draw() {
	// escape
	//[2J clears teh screen and returns cursor to home position
	std::cout << "\x1b[2J";

	for (int row = 0; row < rowMax; ++row) {
		for (int col = 0; col < colMax; ++col) {
			cells[row][col].draw(row, col);
		}
	}
}

void grid::randomize() {
	const int factor = 5; //20% population i.e 1/5
	const int cutoff = RAND_MAX / factor;

	time_t now;
	time(&now);
	srand(now);

	for (int row = 1; row < rowMax; ++row) {
		for (int col = 1; col < colMax; ++col) {
			if (rand() / cutoff == 0) {
				create(row, col);
			}
		}
	}
}
bool grid::will_create(int row, int col) {
	if (cells[row][col].is_alive()) {
		return false;
	}
}
bool grid::will_survive(int row, int col) {
	if (!cells[row][col].is_alive()) {
		return false;
	}
	//get num of alive neigh

	//  x  x  x
	//  x  o  x
	//  x  x  x

	int neighbors = cells[row - 1][col - 1].is_alive() +
		cells[row - 1][col].is_alive() +
		cells[row - 1][col + 1].is_alive() +
		cells[row][col - 1].is_alive() +
		cells[row][col + 1].is_alive() +
		cells[row + 1][col - 1].is_alive() +
		cells[row + 1][col].is_alive() +
		cells[row + 1][col + 1].is_alive();

	if (neighbors < min_neighbors || neighbors > max_neighbors) {
		return false;
	}
	return true;
}

void calculate(grid& oldgen, grid& newgen) {
	for (int row = 1; row < rowMax; ++row) {
		for (int col = 1; col < colMax; ++col) {
			//surivive?
			if (oldgen.will_survive(row, col)) {
				newgen.create(row, col);
			}
			//baren space turn to new populate
			else if (oldgen.will_create(row, col)) {
				newgen.create(row, col);
			}
		}
	}
}

void grid::update(const grid& next) {
	for (int row = 1; row < rowMax; ++row) {
		for (int col = 1; col < colMax; ++col) {
			cells[row][col] = next.cells[row][col];
		}
	}
}
#include <iostream>
#include <string>
#include "ansi_escapes.h"
#include "grid.h"


int main() {
	std::cout << "Conways game of Life\n";
	std::cout << "Press the return key to display each generation \n";

	std::cin.get();

	setupConsole();

	grid current_generation;

	current_generation.randomize();

	while (true) {

		current_generation.draw();

		std::cin.get();

		grid next_generation;
		calculate(current_generation, next_generation);
		current_generation.update(next_generation);
	}

	std::cout << "\x1b[" << 0 << ";" << rowMax - 1 << "H";

	restoreConsole();
	return 0;
}
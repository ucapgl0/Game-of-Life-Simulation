#include <iostream>
#include "Game.h"
#include "golGrid.h"
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using std::vector;

namespace gol {
	void validate_iteration(int iteration){
		if (iteration<0){
        throw std::invalid_argument("The number of iteration should be a non-negative integer.");
    }
	}

    Game::Game(gol::grid &g) : grid_data(g) {

	}

	vector<vector<string>> Game::get_grid_data(){
		return grid_data.get_position_data();
	}

	void Game::PrintGrid() {
		grid_data.print();
	}

    void Game::TakeStep() {
		grid temp_grid(grid_data);
		vector<vector<string>> temp_data = temp_grid.get_position_data();
		last_position_data = temp_data;
		int rows = temp_grid.get_rows();
		int cols = temp_grid.get_columns();		
		
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				
				if (temp_data[i][j] == "o") {
					if (temp_grid.alives_neighbour(i + 1, j + 1) < 2 || temp_grid.alives_neighbour(i + 1, j + 1) > 3) {
						grid_data.set_cell_content(i + 1, j + 1, "-");
					}
					}
					if (temp_data[i][j] == "-") {
						if (temp_grid.alives_neighbour(i + 1, j + 1) == 3) {
							grid_data.set_cell_content(i + 1, j + 1, "o");
						}
				}
				
			}
		}

	}

	int Game::Compare_grid() {
		if (grid_data.get_position_data() == last_position_data) {
			return 1;
		}
		else {
			return 0;
		}
	}
}
#include <iostream>
#include "Game.h"
#include "golGrid.h"
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using std::vector;

namespace gol {

	vector<string> Game::get_grid_data(){
		return grid_data.get_position_data();
	}

	void Game::PrintGrid() {
		grid_data.print();
	}

}
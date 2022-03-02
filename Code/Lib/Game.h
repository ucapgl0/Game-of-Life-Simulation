#ifndef Game_h
#define Game_h
#include "golGrid.h"
#include <iostream>
#include <vector>

using namespace std;
using std::vector;

namespace gol {

	class Game {
	
	public:
		void TakeStep();
		void PrintGrid();
		int Compare_grid();
		vector<vector<string>> get_grid_data();
        Game(gol::grid &g);

	private:
		grid grid_data;
		vector<vector<string>> last_position_data;

};

}
#endif
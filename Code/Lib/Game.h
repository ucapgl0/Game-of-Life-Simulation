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
		vector<string> get_grid_data();

	private:
		grid grid_data;
		vector<string> last_position_data;

};

}
#endif
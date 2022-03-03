#include <iostream>
#include "../Lib/Game.h"
#include "../Lib/golGrid.h"
#include <string>
#include <vector>

using namespace std;

static void show_usage(string name)
{
	std::cerr << "Usage: " << name << "\n"
		<< "Option1: input a text file and the number of generations\n"
		<< "Option2: input the number of rows, columns and alives of grid and the number of generations\n"
		<< "Option:\n"
		<< "\t-h,--help\t\tShow this help message\n" 
		<< std::endl;
}


int main(int argc, char* argv[]) {
	
	if (argc < 2 || argc>5 || argc==4) {
		show_usage(argv[0]);
		return 0;
	}
	
	if (argc == 2) {
		if ((argv[1] == "-h") || (argv[1] == "--help")) {
			show_usage(argv[0]);
			return 0;
		}
		else {
			show_usage(argv[0]);
			return 0;
		}
	}
	
	if (argc == 3) {
		string file = argv[1];
        gol::validate_iteration(stoi(argv[2]));
        int iteration = stoi(argv[2]);
        gol::grid grid_Data(file);
        gol::Game game(grid_Data);
        for(int i = 0; i < iteration; i++){
            game.TakeStep();
        }
        game.PrintGrid();
        return 1;
	}

    if (argc == 5) {
		gol::validate_iteration(stoi(argv[4]));
        int rows = stoi(argv[1]);
		int cols = stoi(argv[2]);
		int alives = stoi(argv[3]);
		int iteration = stoi(argv[4]);
		gol::grid grid_Data(rows, cols, alives);
		gol::Game game(grid_Data);
		for(int i = 0; i < iteration; i++){
			game.TakeStep();
		}
		game.PrintGrid();
		return 1;
    }
}
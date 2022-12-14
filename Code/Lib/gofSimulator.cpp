#include <iostream>
#include "Game.h"
#include "golGrid.h"
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
		cout << argv[0] << endl;
		return 0;
	}
	
	if (argc == 2) {
		if ((argv[1] == "-h") || (argv[1] == "--help")) {
			cout << argv[0] << endl;
			return 0;
		}
		else {
			cout << argv[0] << endl;
			return 0;
		}
	}
	
	if (argc == 3) {
		string file = argv[1];
        if(stoi(argv[2])<0){

        }
        int iteration = stoi(argv[2]);
        gol::grid grid_Data(file);
        gol::Game game(grid_Data);
        for(int i = 1; i < iteration; i++){
            game.TakeStep();
        }
        game.PrintGrid();
        return 1;
	}

    if (argc == 5) {
        
    }
}
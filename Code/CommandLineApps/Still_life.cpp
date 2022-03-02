#include <iostream>
#include "../Lib/Game.h"
#include "../Lib/golGrid.h"
#include <string>
#include <vector>

using namespace std;

static void show_usage(string name)
{
	cerr << "Usage: " << name << "\n"
		<< "User should input the number of alive cells, rows, columns of grid and generations."
		<< "Option:\n"
		<< "\t-h,--help\t\tShow this help message\n" 
		<< std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 2 && argc!= 5){
        show_usage(argv[0]);
            return 0;
    }

    if (argc == 2 ){
        if ((argv[1] == "-h") || (argv[1] == "--help")) {
            show_usage(argv[0]);
            return 0;
        }
    }   

    if (argc == 5){
        int alives = stoi(argv[1]);
        int row = stoi(argv[2]);
        int col = stoi(argv[3]);
        int iteration = stoi(argv[4]);
        
        gol::grid grid_Data(row, col, alives);
        gol::Game gol(grid_Data);
        for (int i=0;i<iteration;i++){
            gol.TakeStep();
            if (gol.Compare_grid()==1){
                gol.PrintGrid();
                break;
            }
        }
        return 1;
   
}
}
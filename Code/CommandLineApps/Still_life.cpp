#include <iostream>
#include "../Lib/Game.h"
#include "../Lib/golGrid.h"
#include <string>
#include <vector>
#include <thread>      
#include <chrono>

using namespace std;

static void show_usage(string name)
{
	cerr << "Usage: " << name << "\n"
		<< "User should input the number of alive cells, rows, columns of grid, generations and the number of pictures."
		<< "Option:\n"
		<< "\t-h,--help\t\tShow this help message\n" 
		<< std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 2 && argc!= 6){
        show_usage(argv[0]);
            return 0;
    }

    if (argc == 2 ){
        if ((argv[1] == "-h") || (argv[1] == "--help")) {
            show_usage(argv[0]);
            return 0;
        }
    }   

    if (argc == 6){
        if (stoi(argv[4]) < 0){
        throw invalid_argument("iteration should be a non-negative integer.");
    }
        int alives = stoi(argv[1]);
        int row = stoi(argv[2]);
        int col = stoi(argv[3]);
        int iteration = stoi(argv[4]);
        int number_grid = stoi(argv[5]);
        
        gol::grid grid_Data(row, col, alives);
        gol::Game gol(grid_Data);
        for (int n=0; n<number_grid;n++){
            int i = 0;
            while(i<iteration){
                gol.TakeStep();
                if (gol.Compare_grid()==1){
                    gol.PrintGrid();
                    
                    break;
                }
                i = i + 1;
            }

            gol::grid grid_Data(row, col, alives);
            gol::Game gol(grid_Data);
            this_thread::sleep_for(chrono::seconds(1));
    }
        
        return 1;
   
}
}
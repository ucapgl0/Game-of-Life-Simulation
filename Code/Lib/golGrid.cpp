#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm> 
#include "golGrid.h"
#include<fstream>
#include <cassert>
#include <string>

using namespace std;
using std::vector;

namespace gol {

	vector<string> grid::get_position_data() {
		return position_data;
	}

	int grid::get_rows() {
		return rows;
	}

	int grid::get_columns() {
		return cols;
	}

	grid::grid(int rows, int cols) :rows(rows), cols(cols) {
		for (int i = 0; i < rows*cols; i++) {
			position_data.push_back("o");
		}
	}

	void grid::set_cell_content(int row, int col, string content) {
		position_data[(row - 1)*cols + col - 1] = content;
	}

    void grid::print() {
		int i = 0;
		while (i < rows) {
			for (int j = 0; j < cols; j++) {
				int index = i * cols + j;
				cout << position_data[index] << ' ';
			}

			i = i + 1;
			cout << "\n";
		}
		cout << endl;
	}

}
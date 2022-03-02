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

    grid::grid(const grid &v) {
		this->position_data = v.position_data;
		this->rows = v.rows;
		this->cols = v.cols;
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

    grid::grid(int rows, int cols, int alives) :rows(rows), cols(cols) {
		//grid::grid(rows, cols, alive) {};
		srand(time(0));
		vector<string> random_v;
		for (int i = 0; i < alives; i++) random_v.push_back("o");
		for (int i = alives; i < rows*cols; i++)random_v.push_back("-");
		random_shuffle(random_v.begin(), random_v.end());

		position_data = random_v;
	}


	grid::grid(string file) {
		ifstream ifs;
		ifs.open(file, ios::in);
		if (!ifs.is_open()) {
			cout << "file open unsuccessfully" << endl;
		}

		char buf[1024] = { 0 };
		while (ifs.getline(buf, sizeof(buf))) {
			cout << buf << endl;
		}
	}


	int grid::alives_neighbour(int row, int col) {
		int count = 0;
		if (row > rows || col > cols) {

		}
		else if (row < 1 || col < 1) {

		}
		else {
			// left-up
			if (row - 2 > -1 && col - 2 > -1) {
				if (position_data[(row - 2)*cols+ col-2] == "o") {
					count = count + 1;
				}
			}
			// left-down
			if (row < rows && col - 2 > -1) {
				if (position_data[row*cols + col - 2] == "o") {
					count = count + 1;
				}
			}
			//left
			if (col - 2 > -1) {
				if (position_data[(row - 1)*cols + col - 2] == "o") {
						count = count + 1;
				}
			}
			//up
			if (row - 2 > -1) {
				if (position_data[(row - 2)*cols + col - 1] == "o") {
					count = count + 1;
				}
			}
			//down
			if (row < rows) {
				if (position_data[row*cols + col - 1] == "o") {
					count = count + 1;
				}
			}
			//right
			if (col < cols) {
				if (position_data[(row - 1)*cols + col] == "o") {
					count = count + 1;
				}
			}
			//right-up
			if (row - 2 > -1 && col < cols) {
				if (position_data[(row - 2)*cols + col] == "o") {
					count = count + 1;
				}
			}
			//right-down
			if (row < rows && col < cols) {
				if (position_data[row*cols + col] == "o") {
					count = count + 1;
				}
			}
			
		}
		return count;
	}

}
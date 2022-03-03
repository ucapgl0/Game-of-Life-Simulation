#include <iostream>
#include <vector>
#include <time.h>
#include<algorithm>
#include <fstream>
#include <sstream>
#include<cassert>
#include <stdexcept>
#include<exception> 
#include "golGrid.h"


using namespace std;
using std::vector;

namespace gol {

	vector<vector<string>> grid::get_position_data() {
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
		vector<string> t;
		for (int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++){
				t.push_back("o");
			}
			position_data.push_back(t);
			t.clear();
		}
	}

	void grid::set_cell_content(int row, int col, string content) {
		position_data[row - 1][col - 1] = content;
	}

    void grid::print() {
		int i = 0;
		while (i < rows) {
			for (int j = 0; j < cols; j++) {
				
				cout << position_data[i][j] << ' ';
			}

			i = i + 1;
			cout << "\n";
		}
		cout << endl;
	}

    grid::grid(int row, int col, int alives) :rows(row), cols(col) {
		if(row < 0 || col < 0){
			throw invalid_argument("the number of rows and columns should be positive integer.");
		}
		srand(time(0));
		vector<string> random_v;
		for (int i = 0; i < alives; i++) random_v.push_back("o");
		for (int i = alives; i < row*col; i++)random_v.push_back("-");
		random_shuffle(random_v.begin(), random_v.end());

		vector<string> t;
		for (int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++){
				t.push_back(random_v[i*cols + j]);
			}
			position_data.push_back(t);
			t.clear();
		}
	}


	grid::grid(string file) {
		ifstream ifs;
		ifs.open(file);
		if (!ifs.is_open()) {
			cout << "file open unsuccessfully" << endl;
		}

        vector<string> file_data;
		string temp;
        std::vector<std::string> temp_row, temp_row_num, temp_col_num;
		std::vector<int> column_vector;
		std::vector<std::vector<std::string>> celldata;
		
		int row_num = 0;
		int col_num = 0;
		while (getline(ifs, temp))
		{
			file_data.push_back(temp);
			row_num = row_num + 1;
			std::stringstream input(temp);
			std::string out;
			while (input >> out) {
				col_num = col_num + 1;
				temp_row.push_back(out);
			}
			celldata.push_back(temp_row);
			column_vector.push_back(col_num);
			temp_row.clear();
	}
			temp_row_num.push_back(std::to_string(row_num));
			temp_col_num.push_back(std::to_string(col_num / row_num));
			celldata.push_back(temp_row_num);
			celldata.push_back(temp_col_num);
			std::vector<std::string> row_num1;
			std::vector<std::string> col_num1;
			col_num1 = celldata.back();
			temp.pop_back();
			row_num1 = celldata.back();
			temp.pop_back();

			rows = std::stoi(row_num1[0]);
			cols = std::stoi(col_num1[0]);
			position_data = celldata;

		}
		

	int grid::alives_neighbour(int row, int col) {
		
		int count = 0;
		
		if (row < 1 || col < 1) {
			throw invalid_argument("the number of rows and columns should be positive integer.");
		}
		else {
			// left-up
			if (row - 2 > -1 && col - 2 > -1) {
				if (position_data[row - 2][col-2] == "o") {
					count = count + 1;
				}
			}
			// left-down
			if (row < rows && col - 2 > -1) {
				if (position_data[row][col - 2] == "o") {
					count = count + 1;
				}
			}
			//left
			if (col - 2 > -1) {
				if (position_data[row - 1][col - 2] == "o") {
						count = count + 1;
				}
			}
			//up
			if (row - 2 > -1) {
				if (position_data[row - 2][col - 1] == "o") {
					count = count + 1;
				}
			}
			//down
			if (row < rows) {
				if (position_data[row][col - 1] == "o") {
					count = count + 1;
				}
			}
			//right
			if (col < cols) {
				if (position_data[row - 1][col] == "o") {
					count = count + 1;
				}
			}
			//right-up
			if (row - 2 > -1 && col < cols) {
				if (position_data[row - 2][col] == "o") {
					count = count + 1;
				}
			}
			//right-down
			if (row < rows && col < cols) {
				if (position_data[row][col] == "o") {
					count = count + 1;
				}
			}
			
		}
		return count;
	}

}
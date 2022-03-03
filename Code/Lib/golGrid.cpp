#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>
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

	void validate_row_col(int row,int col){
		if (row <=0 or col <=0){
			throw invalid_argument("The number of row and column should be positive integers.");
		}
	}
	void validate_num_alive(int row,int col,int alive){
		if (alive>(row*col)){
			throw out_of_range("The number of alive cells should be less than the number of cells.");
		}
	}

	void validate_file(string file){
		ifstream ifs;
		ifs.open(file);
		if (!ifs.is_open()) {
			throw invalid_argument("The file does not exist.");
		}
		string temp;
        vector<string> temp_row, temp_row_num, temp_col_num;
		vector<int> column_v;
		vector<vector<string>> file_data;		
		int row_num = 0;
		int col_num = 0;
		while (getline(ifs, temp))
		{			
			row_num = row_num + 1;
			stringstream input(temp);
			string out;
			while (input >> out) {
				col_num = col_num + 1;
				temp_row.push_back(out);
			}
			file_data.push_back(temp_row);
			column_v.push_back(col_num);
			temp_row.clear();
		}
		if(row_num == 0){
			throw invalid_argument("The file is empty");
		}

		if (column_v.size()!=1){
			int diff = column_v[1]-column_v[0];
			if (column_v[0]!=diff){
				throw std::invalid_argument("The grid is not a rectangle or square.");
				}
			else{
				for (int i=1;i<column_v.size()-1;i++){
					if ((column_v[i+1]-column_v[i])!=diff){
						throw std::invalid_argument("The grid is not a rectangle or square.");
					}
				}

			}
		}
			for (int i=0;i<file_data.size();i++){
				for (int j=0;j<file_data[i].size();j++){
					if (file_data[i][j]!="o" and file_data[i][j]!="-"){
						throw std::invalid_argument("file content should only contains two of characters: 'o' '-' .");
					}
				}
			}

	}

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

	grid::grid(int row, int col) :rows(row), cols(col) {
		validate_row_col(row, col);
		vector<string> t;
		for (int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++){
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
		validate_num_alive(row, col, alives);
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
		string temp;
        vector<string> temp_row, temp_row_num, temp_col_num;
		vector<int> column_vector;
		vector<vector<string>> file_data;
		
		int row_num = 0;
		int col_num = 0;
		while (getline(ifs, temp))
		{			
			row_num = row_num + 1;
			stringstream input(temp);
			string out;
			while (input >> out) {
				col_num = col_num + 1;
				temp_row.push_back(out);
			}
			file_data.push_back(temp_row);
			column_vector.push_back(col_num);
			temp_row.clear();
		}
			//temp_row_num.push_back(std::to_string(row_num));
			cols=(col_num / row_num);
			//celldata.push_back(temp_row_num);
			//celldata.push_back(temp_col_num);
			//std::vector<std::string> row_num1;
			//std::vector<std::string> col_num1;
			//col_num1 = celldata.back();
			//temp.pop_back();
			//row_num1 = celldata.back();
			//temp.pop_back();
			//cols = std::stoi(col_num1[0]);

			rows = row_num;
			
			position_data = file_data;

		}
		

	int grid::alives_neighbour(int row, int col) {
		
		int count = 0;
		if (row > rows || col > cols) {
			throw invalid_argument("the number of rows and columns should not be out of grid.");
		}
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
#ifndef golGrid_h
#define golGrid_h
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using std::vector;

namespace gol {
	class grid {

	public:
		grid(int rows, int cols);
		grid(int rows, int cols, int alives);
		grid(string file_name);
		grid(const grid &v);

		void print();
		void set_cell_content(int row, int col, string content);
		int alives_neighbour(int row, int col);
		vector<vector<string>> get_position_data();
		int get_rows();
		int get_columns();

	private:
		int rows;
		int cols;
		vector<vector<string>> position_data;

	};
	void validate_row_col(int row,int col);
	void validate_num_alive(int row,int col,int alive);
	void validate_file(string file);
}
#endif

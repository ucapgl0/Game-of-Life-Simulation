# include<iostream>
#include <vector>
#include <string>

using namespace std;
using std::vector;

namespace gol {
	class grid {

	public:
		grid(int rows, int cols);
		grid(int rows, int cols, int alives);
		grid(std::string file_name);
		grid(const grid &v);

		


	private:
		int rows;
		int cols;
		vector<string> position_data;

	};
}

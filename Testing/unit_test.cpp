#include "catch.hpp"
#include "../Code/Lib/golGrid.h"
#include "../Code/Lib/Game.h"
#include <iostream>
#include <vector>

using namespace std;
TEST_CASE( "Invalid number" , "[Invalid number]") 
{
  // Unit tests for invalid numbers
  REQUIRE_THROWS(gol::validate_row_col(0,3));
  REQUIRE_THROWS(gol::validate_row_col(2,0));
  REQUIRE_THROWS(gol::validate_row_col(-1,-1));
  REQUIRE_THROWS(gol::validate_num_alive(3,3,11));
  REQUIRE_THROWS(gol::validate_iteration(-1));

}

TEST_CASE( "Invalid file" , "[File]")
{
  // Unit tests for Invalid file input
  REQUIRE_THROWS(gol::validate_file("file_not_exist.txt"));
  REQUIRE_THROWS(gol::validate_file("../../Testing/Data/unittest_empty.txt"));
  REQUIRE_THROWS(gol::validate_file("../../Testing/Data/unittest_not_rectangle.txt"));
  REQUIRE_THROWS(gol::validate_file("../../Testing/Data/unittest_invalid_content.txt"));
}

TEST_CASE( "Valid file" , "[File]")
{
  // Unit tests for valid file input
  REQUIRE_NOTHROW(gol::validate_file("../../Testing/Data/glider.txt"));
  REQUIRE_NOTHROW(gol::validate_file("../../Testing/Data/input.txt"));  
}

TEST_CASE( "Invalid position" , "[Invalid position]") 
{
  // Unit tests for out of grid range 
  gol::grid grid1("../../Testing/Data/glider.txt");
  REQUIRE_THROWS(grid1.alives_neighbour(15,15));

  gol::grid grid2(4,4,3);
  REQUIRE_THROWS(grid2.alives_neighbour(5,5));
}

int count_alive_cell(vector<vector<string>> position_data){
  // Count the number of alive cells in a grid
  int alives = 0;
  for (int i=0;i<position_data.size();i++){
    for (int j=0;j<position_data[i].size();j++){
      if (position_data[i][j]=="o"){
        alives=alives+1;
      }
    }
  }
  return alives;
}

TEST_CASE("Total number of placed cells","[placed cells]"){
  // Units tests with a specified number of alive cells
  gol::grid Cell1(3,3,5);
  vector<vector<string>> celldata1 = Cell1.get_position_data();
  REQUIRE(count_alive_cell(celldata1)==5);

  gol::grid Cell2(6,6,7);
  vector<vector<std::string>> celldata2 = Cell2.get_position_data();
  REQUIRE(count_alive_cell(celldata2)==7);
}

string Compare_patterns(vector<vector<string>>data1,vector<vector<string>>data2){
  //  Compare two patterns
  if (data1==data2){
    return "Two patterns are same.";
  }
  else{
    return "Two patterns are different.";
  }
}

TEST_CASE("Different instances with different patterns","[different patterns]"){
  // Unit tests if the different instances have different patterns
  gol::grid grid1(5,5,5);
  vector<vector<string>> celldata1 = grid1.get_position_data();

  gol::grid grid2(5,5,5);
  vector<vector<string>> celldata2 = grid2.get_position_data();
  REQUIRE(Compare_patterns(celldata1,celldata2)=="Two patterns are different.");
}

TEST_CASE("Number of alive neighbours","[alive neighbours]"){
  // Unit tests to see whether the calculation of the function num_of_alive_neigh is correct
  gol::grid g("../../Testing/Data/glider.txt");
  REQUIRE(g.alives_neighbour(6,2)==0);
  REQUIRE(g.alives_neighbour(3,2)==5);
  REQUIRE(g.alives_neighbour(3,3)==3);
}

TEST_CASE("Take step","[Take step]"){
  // Unit tests to check whether TakeStep() works as expected
  gol::grid grid("../../Testing/Data/input.txt");
  gol::Game gol(grid);
  gol.TakeStep();
  vector<vector<string>> cellgrid = gol.get_grid_data();
  vector<vector<string>> step1 = {{"-","o","o"},{ "-", "-", "o" }, { "-", "-", "-" }};
  REQUIRE(cellgrid==step1);

  gol.TakeStep();
  cellgrid = gol.get_grid_data();
  vector<vector<string>> step2 = {{"-","o","o"},{ "-", "o", "o" }, { "-", "-", "-" }};
  REQUIRE(cellgrid==step2);
}
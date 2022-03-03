#include "catch.hpp"
#include "../Code/Lib/golGrid.h"
#include "../Code/Lib/Game.h"
#include <iostream>
#include <vector>

using namespace std;
TEST_CASE( "Invalid number" , "[Invalid number]") 
{
  // Unit tests for invalid input numbers
  REQUIRE_THROWS(gol::validate_row_col(0,3));
  REQUIRE_THROWS(gol::validate_row_col(2,0));
  REQUIRE_THROWS(gol::validate_row_col(-1,-1));
  REQUIRE_THROWS(gol::validate_num_alive(3,3,11));
  REQUIRE_THROWS(gol::validate_iteration(-1));

}

TEST_CASE( "Invalid position" , "[Invalid position]") 
{
  // Unit tests for out-of-range position
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
  // Units tests for the constructor with a specified number of alive cells
  gol::grid Cell1(3,3,5);
  std::vector<std::vector<std::string>> celldata1 = Cell1.get_position_data();
  REQUIRE(count_alive_cell(celldata1)==5);

  gol::grid Cell2(6,6,7);
  std::vector<std::vector<std::string>> celldata2 = Cell2.get_position_data();
  REQUIRE(count_alive_cell(celldata2)==7);
}

std::string Compare_patterns(std::vector<std::vector<std::string>>data1,std::vector<std::vector<std::string>>data2){
  // Compare two patterns to see whether they are different or not
  if (data1==data2){
    return "Two patterns are the same.";
  }
  else{
    return "Two patterns are different.";
  }
}

TEST_CASE("Different instances with different patterns","[different patterns]"){
  // Unit tests to see if the different instances have different patterns
  gol::grid grid1(5,5,5);
  std::vector<std::vector<std::string>> celldata1 = grid1.get_position_data();

  gol::grid grid2(5,5,5);
  std::vector<std::vector<std::string>> celldata2 = grid2.get_position_data();
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
  // Unit tests to check whether the function TakeStep works as expected
  gol::grid grid("../../Testing/Data/input.txt");
  gol::Game gol(grid);
  gol.TakeStep();
  std::vector<std::vector<std::string>> cellgrid = gol.get_grid_data();
  std::vector<std::vector<std::string>> step1 = {{"-","-","-"},{ "-", "o", "-" }, { "-", "o", "-" }};
  REQUIRE(cellgrid==step1);

  gol.TakeStep();
  cellgrid = gol.get_grid_data();
  std::vector<std::vector<std::string>> step2 = {{"-","-","-"},{ "-", "-", "-" }, { "-", "-", "-" }};
  REQUIRE(cellgrid==step2);
}
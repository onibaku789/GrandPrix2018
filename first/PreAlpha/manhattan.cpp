#include <vector>
#include <iostream>
#include <math.h>
int manhattanDist (int p_Row,int p_Col, int n_Row, int n_Col, int p_Val, int n_Val){
    int Val = 0;
    if ((p_Val + n_Val) == 0){
       Val = p_Val;
    }
    else if((p_Val + n_Val) < 0){
      Val = p_Val;
    }
    else if((p_Val + n_Val) > 0){
      Val = abs(n_Val);
    }
    int dist = (abs(p_Row - n_Row) + abs(p_Col - n_Col )) * Val;
  return dist;
  }

int main(int argc, char const *argv[]) {
  std::cout << manhattanDist(1,1,1,2,3,-3) << std::endl;
  std::cout << manhattanDist(4,26,1,1,3,-5) << std::endl;
  std::cout << manhattanDist(1,1,2,4,6,-5) << std::endl;
  return 0;
}

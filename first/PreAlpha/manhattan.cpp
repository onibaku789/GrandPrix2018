#include <vector>
#include <iostream>
#include <math.h>
#include <climits>
class SpareMatrix {
public:
  SpareMatrix(){
    val = -1;
    col = -1;
    row = -1;
  }
  int  getVal(){
    return this->val;
  }
  int  getCol(){
    return this->col;
  }
  int  getRow(){
    return this->row;
  }
  void setVal(int k){
    this->val = k;
  }
  void setRow(int k) {
    this->row = k;
  }

  void setCol(int k) {
    this->col = k;
  }


  void addValue(int row, int column, int value ) {
    this->row = row;
    this->col = column;
    this->val = value;
  }
  void displaySpareMatrix(){
    std::cout << "Row: " << this->getRow() << " " << "Col: " << this->getCol() << " "<<"Val: " << this->getVal();
  }
private:
  int val;
  int col;
  int row;
};
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

  int manhattanDist (SpareMatrix   & pos , SpareMatrix  & neg ){
      int Val = 0;
      if ((pos.getVal() + neg.getVal()) <= 0){
         Val = pos.getVal();
      }
      else if((pos.getVal() + neg.getVal()) > 0){
        Val = abs(neg.getVal());
      }
      int dist = (abs(pos.getRow() - neg.getRow()) + abs(pos.getCol() - neg.getCol() )) * Val;
    return dist;
    }
  int blackMagic(std::vector<SpareMatrix> & pos, std::vector<SpareMatrix> & neg ){
    bool isNull = true;
    int count = -1, min = INT_MAX,sum = 0;

    for(int i; i < pos.size();i++){
      if(!isNull){
      --i;
      }
      for (int j = 0; j < neg.size(); j++) {
        int temp = manhattanDist(pos[i],neg[j]);
        if( temp < min){
          min = temp;
          count = j;
      }

    sum += min;
    int posVal = pos[i].getVal();
    int negVal =  neg[count].getVal();
    int pos_negVal = posVal + negVal;


    if(pos_negVal > 0 ){
      isNull = false;
      neg.erase(neg.begin()+count);
      pos[i].setVal(pos_negVal);
    }
    else if (pos_negVal < 0){
          pos.erase(pos.begin() + i);
        neg[count].setVal(pos_negVal);
    }
    else if (pos_negVal == 0){
      pos.erase(pos.begin() + i);
      neg.erase(neg.begin()+count);
    }
    else{
      std::cout << "GIGA HÜLYE VAGY" << std::endl;
    }
    }
}
return sum;
  }


  int main()
  {
      // Assume 4x5 sparse matrix
      int sparseMatrix[2][3] =
      {
          {1 , -2 , 0  },
          {0 , -2 , 3 },

      };
      int row_size = 0, col_size = 0;
      std::cin >> row_size >> col_size;

      // number of columns in compactMatrix (size) must be
      // equal to number of non - zero elements in
      // sparseMatrix
      int compactMatrix[3][col_size];
      std::vector<SpareMatrix> posVector;
      std::vector<SpareMatrix> negVector;

      // Making of new matrix
      SpareMatrix temp;
      int k = 0;
      for (int i = 0; i < row_size; i++)
          for (int j = 0; j < col_size; j++){
              if (sparseMatrix[i][j] > 0)  {
                temp.addValue(i+1,j+1,sparseMatrix[i][j]);
                posVector.push_back(temp);

              }
              if (sparseMatrix[i][j] < 0)  {
                temp.addValue(i+1,j+1,sparseMatrix[i][j]);
                negVector.push_back(temp);

              }
}


          for(auto i : posVector){
              i.displaySpareMatrix();
          std::cout << std::endl;
        }
          std::cout << "negatív" << std::endl;
        for (auto i: negVector) {
        i.displaySpareMatrix();
        std::cout << std::endl;
      }
        std::cout << blackMagic(posVector,negVector) << std::endl;

      return 0;
  }

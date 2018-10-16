#include <vector>
#include <iostream>
#include <cmath>
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
    std::cout << "Row: " << this->getRow() << " " << "Col: " << this->getCol() << " "<<"Val: " << this->getVal() << std::endl;;
  }
private:
  int val;
  int col;
  int row;
};

  int manhattanDist (SpareMatrix   & pos , SpareMatrix  & neg ){
      int Val = 0;
      int valdif = pos.getVal() + neg.getVal();
      if (valdif == 0){
         Val = pos.getVal();
      }else  if (valdif < 0){
         Val = pos.getVal();
      }
      else if(valdif > 0){
        Val = abs(neg.getVal());
      }
      int dist = (abs(pos.getRow() - neg.getRow()) + abs(pos.getCol() - neg.getCol() )) * Val;
    return dist;
    }
  int blackMagic(std::vector<SpareMatrix> & pos, std::vector<SpareMatrix> & neg ){
    bool isNull = true;
    int count = -1,sum = 0;

    for(int i = 0; i < pos.size();){


       int min = INT_MAX;
      for (int j = 0; j < neg.size(); j++) {
        int temp = manhattanDist(pos[i],neg[j]);
        if( temp < min && temp !=0){
          min = temp;
          count = j;
        }
      }

    sum += min;
    int posVal = pos[i].getVal();
    int negVal =  neg[count].getVal();
    int pos_negVal = posVal + negVal;


    if(pos_negVal > 0 ){
      isNull = false;
     neg.erase(neg.begin() + count);
      pos[i].setVal(pos_negVal);
    }
    else if (pos_negVal < 0){
            isNull= true;
        //pos.erase(pos.begin() + i);
        neg[count].setVal(pos_negVal);
    }
    else if (pos_negVal == 0){
        isNull = true;
     // pos.erase(pos.begin() + i);
      neg.erase(neg.begin() + count);
    }
    else{
      std::cout << "GIGA HÜLYE VAGY" << std::endl;
    }


     if(isNull){
        ++i;
      }
}
return sum;
  }


  int main()
  {

      int sparseMatrix[2][3] =
      {
          {0 , -2, 0  },
          {0 , -2 , 4 }
      };
      int row_size = 0, col_size = 0;
      std::cin >> row_size >> col_size;



      std::vector<SpareMatrix> posVector;
      std::vector<SpareMatrix> negVector;


      SpareMatrix temp;
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

        std::cout << blackMagic(posVector,negVector);

      return 0;
  }

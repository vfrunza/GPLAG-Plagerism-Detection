#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <limits>

/* typedefs of arrays and matrices */
using DubArr = std::vector<double>;
using Mat = std::vector<DubArr>;

/* define structure of metaSubMatrix */
struct plMatrix {
     int midX, midY;
     int dimension;   
};

/* return greatest possible size of matrix */
int MaxDefaultSize(int a, int b) {
     int max{(a < b) ? a : b};
     
     if(max == 0) return 0;
     if(max % 2 == 0) return max-1;
     return max;
}

/* elements sum of submatrix */
double SubMatrixSum(const Mat &matrix, const plMatrix &submatrix) {
     double _sum {0.};
     
     for(int i {submatrix.midX - submatrix.dimension}; i <= submatrix.midX + submatrix.dimension; ++i)
          for(int j {submatrix.midY - submatrix.dimension}; j <= submatrix.midY + submatrix.dimension; ++j)
               _sum = _sum + matrix.at(i).at(j);
     
     return _sum;
}

/* check the validity of matrix | ReturnValues = (-1 if 0xM or Mx0, 0 if non-matrix, 1 if valid matrix) */
int ValidMatrix(const Mat &matrix) {
     if(matrix.empty()) return -1; 
     
     /* check validty of nonzero matrix */
     int _rowSize = static_cast<int>(matrix.at(0).size());
     if(_rowSize == 0) return -1;
     
     for(int i = 1; i < matrix.size(); ++i)
          if(_rowSize != static_cast<int>(matrix.at(i).size())) return 0;
          
     return 1;
}

/* function to check if submatrix is mountain */
bool isMatrixMountain(const Mat &matrix, const plMatrix &submatrix) {
     double _previousSquare = SubMatrixSum(matrix, plMatrix {submatrix.midX, submatrix.midY, 0});
     double _nextSquare;
     double _shift{.0};
  
     /* check if submatrix is mountain */
     for(int i {1}; i <= submatrix.dimension; ++i) {
          _nextSquare = SubMatrixSum(matrix, plMatrix {submatrix.midX, submatrix.midY, i});
          /* iff condition for mountain matrix */
          if((_nextSquare-_previousSquare) >= (_previousSquare-_shift)) 
               return false;
               
          _shift = _previousSquare;
          _previousSquare = _nextSquare;
     }
     /* return default value */
     return true;
}

/* function to create matrix using passed struct object */
Mat CreateMatrixUsingStructure(const Mat &matrix, const plMatrix &submatrix) {
     /* instance for 0 dimension */
     if(submatrix.dimension == 0) return {{matrix.at(submatrix.midX).at(submatrix.midY)}};
     
     Mat output;
     DubArr temp;
     
     /* generate a matrix by the given structure */
     for(int i {submatrix.midX - submatrix.dimension}; i <= submatrix.midX + submatrix.dimension; ++i) {
          for(int j {submatrix.midY - submatrix.dimension}; j <= submatrix.midY + submatrix.dimension; ++j)
               temp.push_back(matrix.at(i).at(j));
          output.push_back(temp);
          temp.clear();
     }
     
     return output;
}

/* find the biggest mountain within a matrix */
Mat NajvecaPlaninaMatrice(const Mat &matrix) {
     int _check {ValidMatrix(matrix)};
     plMatrix outputSubMatrix;
          
     /* check validity of matrix first */
     if(_check == -1) return (Mat {});
     else if(_check == 0) throw std::domain_error("Matrica nije korektna");
     else {
          /* create subMatrix to save info about */
          plMatrix tempSub;
          bool _subSet {false}; // paramater for the return value
     
          /* initiate the size parameters for submatrix search */
          int sizeX {static_cast<int>(matrix.size())};
          int sizeY {static_cast<int>(matrix.at(0).size())};
          
          /* start searching for the submatrices */
          for(int dimension {MaxDefaultSize(sizeX, sizeY)}; dimension >= 0; --dimension) 
          {
               for(int i {dimension}; i < (sizeX-dimension); ++i) {
                    for(int j {dimension}; j < (sizeY-dimension); ++j) {
                         /* start searching for submatrices */
                         tempSub = {i, j, dimension};
                         if(isMatrixMountain(matrix, tempSub)) {
                              /* insert default value */
                              if(!_subSet) {
                                   outputSubMatrix = tempSub;
                                   _subSet = true;
                              }
                              else {
                                   if(tempSub.dimension > outputSubMatrix.dimension)      outputSubMatrix = tempSub;
                                   else if(tempSub.dimension == outputSubMatrix.dimension) 
                                   {
                                        if(matrix.at(outputSubMatrix.midX).at(outputSubMatrix.midY) < matrix.at(i).at(j))
                                             outputSubMatrix = tempSub;
                                        else if(outputSubMatrix.midX > i)
                                             outputSubMatrix = tempSub;
                                        else if(outputSubMatrix.midX == i && outputSubMatrix.midY > j)
                                             outputSubMatrix = tempSub;
                                   }
                              }
                         }
                    }
               }
          }
     }
     /* output value */
     return (CreateMatrixUsingStructure(matrix, outputSubMatrix));
}

/* function to print matrix */
void PrintMatrix(const Mat &matrix) {
     for(auto row: matrix) {
          for(auto element: row) 
               std::cout << std::right << std::setw(6) << element;
          std::cout << '\n';
     }
}

/* implementing main function here */
int main () {
     /* input */
     int m, n;
     std::cout << "Unesite dimenzije matrice (m i n): ";
     std::cin >> m >> n;
     if(m < 0 || n < 0) {
          std::cout << "Dimenzije matrice moraju biti nenegativne!";
          return 0;
     }
     
     std::cout << "Unesite elemente matrice:";
     Mat matrica;
     DubArr red;
     double num;
     for(int i{0}; i < m; i++) {
          
          for(int j{0}; j < n; j++) {
               std::cin >> num;
               red.push_back(num);
          }
          matrica.push_back(red);
          red.clear();
     }
     try {
          std::cout << std::endl << "Najveca planina unesene matrice je:" << std::endl;
          Mat output {NajvecaPlaninaMatrice(matrica)};
          PrintMatrix(output);
     }
     catch(std::domain_error &e) {
          std::cout << e.what();
     }
	return 0;
}
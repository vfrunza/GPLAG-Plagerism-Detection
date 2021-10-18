#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <new>

#define BIGGERTYPE_MM(m1, m2)      decltype(**m1.elementi + **m2.elementi) 

/*   Matrix definition   */
template <typename TipElemenata>
struct Matrica {
     int br_redova = 0, br_kolona = 0; // zbog petlje
     TipElemenata **elementi = nullptr;
};

/*   destroy matrix      */
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> &mat) {
     if(!mat.elementi) return;
     for(int i = 0; i < mat.br_redova; i++) 
          delete[] mat.elementi[i];
     delete[] mat.elementi;
     mat.elementi = nullptr;
}

// for a larger number to delete // CON!!! works only for same-type matrices
template <typename ArgType>
void cleanMess(std::vector<std::reference_wrapper<Matrica<ArgType>>> _toClean) {
     std::for_each(_toClean.begin(), _toClean.end(), [](Matrica<ArgType>& mat) { UnistiMatricu(mat); });
}

/*   create matrix      */
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
     Matrica<TipElemenata> mat;
     mat.br_redova = br_redova; mat.br_kolona = br_kolona;
     mat.elementi = new TipElemenata*[br_redova];
     for(int i (0); i < br_redova; ++i) mat.elementi[i] = nullptr;
     try {
          for(int i = 0; i < br_redova; i++)
          mat.elementi[i] = new TipElemenata[br_kolona]{};
     }
     catch(...) {
          UnistiMatricu(mat);
          throw;
     }
     return mat;
}

/*   input matrix      */
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
     for(int i = 0; i < mat.br_redova; i++)
          for(int j = 0; j < mat.br_kolona; j++) {
               std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
               std::cin >> mat.elementi[i][j];
          }
}

/*   print matrix      */
template <typename TipElemenata>
void IspisiMatricu(Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
     for(int i = 0; i < mat.br_redova; i++) {
          for(int j = 0; j < mat.br_kolona; j++)
               std::cout << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
          std::cout << std::endl;
     }
     if(treba_brisati) UnistiMatricu(mat);
}

/*   matrix sum      */
template <typename TipElemenata1, typename TipElemenata2>
auto ZbirMatrica(const Matrica<TipElemenata1> &m1, const Matrica<TipElemenata2> &m2) -> Matrica<BIGGERTYPE_MM(m1, m2)> {
     if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
          throw std::domain_error("Matrice nemaju jednake dimenzije!");

     auto m3(StvoriMatricu<BIGGERTYPE_MM(m1, m2)>(m1.br_redova, m1.br_kolona));
     for(int i = 0; i < m1.br_redova; i++)
          for(int j = 0; j < m1.br_kolona; j++)
               m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
     return m3;
}

/*   product of matrix and scalar    */
template <typename TipElemenata, typename TipSkalara>
auto ScalarProduct(const Matrica<TipElemenata>& A, const TipSkalara& p) -> Matrica<decltype(**A.elementi * p)> {
     Matrica<decltype(**A.elementi * p)> R (StvoriMatricu<decltype(**A.elementi * p)>(A.br_kolona, A.br_redova));
     for(int i (0); i < A.br_redova; ++i) 
          for(int j (0); j < A.br_kolona; ++j) 
               R.elementi[i][j] = p * A.elementi[i][j];
               
     return R;
}

/*                                      */
/*   added functions to implement       */
/*                                      */
template <typename TipElemenata1, typename TipElemenata2>
auto ProduktMatrica(const Matrica<TipElemenata1>& A, const Matrica<TipElemenata2>& B) -> Matrica<BIGGERTYPE_MM(A, B)> {
     if(A.br_kolona != B.br_redova)
          throw std::domain_error("Matrice nisu saglasne za mnozenje");
          
     using BiggerType = BIGGERTYPE_MM(A, B);
     Matrica<BiggerType> C (StvoriMatricu<BiggerType>(int(A.br_kolona), int(B.br_redova)));
     BiggerType _sum (0);
     
     for(int i (0); i < A.br_redova; ++i) {
          for(int j (0); j < B.br_kolona; ++j) {
               _sum = 0;
               for(int k (0); k < A.br_kolona; ++k) 
                    _sum += A.elementi[i][k] * B.elementi[k][j];
               C.elementi[i][j] = _sum;
          }
     }
     return C;
}

/*   matrix polinomial   */
template <typename TipElemenata, typename IterType>
auto MatricniPolinom(const Matrica<TipElemenata>& A, int n, IterType p) -> Matrica<decltype(**A.elementi * *p)> {
     if(n < 0) throw std::domain_error("Neispravan stepen polinoma");
     if(A.br_kolona < 0 || A.br_redova < 0 || A.br_kolona != A.br_redova)
          throw std::domain_error("Matrica mora biti kvadratna");

     using BiggerType = decltype(**A.elementi * *p);  // for example: TipElementa = int, *p = double, return matrix must be double
     int _size (A.br_kolona);
     Matrica<BiggerType> _clean[3], SP,
          _A (StvoriMatricu<BiggerType>(_size, _size)), 
          P  (StvoriMatricu<BiggerType>(_size, _size)), 
          M  (StvoriMatricu<BiggerType>(_size, _size));
               
     // convert matrix A from TipElemenata to BiggerType matrix _A
     for(int i (0); i < _size; ++i) 
          for(int j (0); j < _size; ++j)
               _A.elementi[i][j] = static_cast<BiggerType>(A.elementi[i][j]);
     
     // M = p[0] * I, A^0 = I = P
     for(int i (0); i < _size; ++i) {
          M.elementi[i][i] = static_cast<BiggerType>(*p);
          P.elementi[i][i] = static_cast<BiggerType>(1);
     }
     
     // calculate matrix
     ++p;
     for(int i (1); i <= n; ++i) {
          _clean[0] = M;
          _clean[1] = P;
          _clean[2] = SP;
          try {
               P  = ProduktMatrica(P, _A);
               SP = ScalarProduct(P, *p);
               M  = ZbirMatrica(M, SP);
               
               cleanMess<BiggerType>({_clean[0], _clean[1], _clean[2]});
               ++p;
          }
          catch (...) {
               cleanMess<BiggerType>({_clean[0], _clean[1], _clean[2], P, SP, M, _A});
               throw;
          }
     }
     cleanMess<BiggerType>({P, SP, _A});
     return M;
}

/*   main program logic    */
int main() {
     Matrica<double> A, M; 
     int dim, n;
     std::cout << "Unesite dimenziju kvadratne matrice: "; std::cin >> dim;
     try {
          A = StvoriMatricu<double>(dim, dim);
          std::cout << "Unesite elemente matrice A:" << std::endl; UnesiMatricu('A', A);
     
          std::cout << "Unesite red polinoma: ";  std::cin >> n;
          std::vector<double> p(n + 1, 0);
          
          std::cout << "Unesite koeficijente polinoma: ";
          for(int i(0); i <= n; ++i) 
               std::cin >> p.at(i);
          
          M = MatricniPolinom(A, n, std::begin(p));
          IspisiMatricu(M, 10, 6, true);
     }
     catch(std::bad_alloc) {
          std::cout << "Nema dovoljno memorije!\n";
     }
     UnistiMatricu(A);
     return 0;
}
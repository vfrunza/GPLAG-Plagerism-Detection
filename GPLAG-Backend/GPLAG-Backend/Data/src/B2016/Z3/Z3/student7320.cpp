#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

#define pb push_back

template <typename TipElemenata>
struct Matrica {
  int br_redova, br_kolona;
  TipElemenata **elementi = nullptr; 
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
  if(!mat.elementi) return;
  for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
  delete[] mat.elementi;
  mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
  Matrica<TipElemenata> mat;
  mat.br_redova = br_redova; mat.br_kolona = br_kolona;
  mat.elementi = new TipElemenata*[br_redova]{};
  for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
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
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
  for(int i = 0; i < mat.br_redova; i++)
  for(int j = 0; j < mat.br_kolona; j++) {
    std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
    std::cin >> mat.elementi[i][j];
  }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 0, bool brisi = false) {
  //std::cout << mat.br_kolona << " " << mat.br_redova << "\n";
  for(int i = 0; i < mat.br_redova; i++) {
  for(int j = 0; j < mat.br_kolona; j++) {
    std::cout << std::setw(sirina_ispisa);
    if (preciznost) std::cout << std::setprecision(preciznost);
    std::cout << mat.elementi[i][j];
  }
  std::cout << std::endl;
  }
  if (brisi) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
  if (m2.br_redova != m1.br_kolona) throw std::domain_error("Matrice nisu saglasne za mnozenje");
  Matrica<TipElemenata> m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
  TipElemenata suma = 0;
  
  for (int i = 0; i < m1.br_redova; i++) {
    for (int j = 0; j < m2.br_kolona; j++) {
      for (int k = 0; k < m1.br_kolona; k++) {
        suma += m1.elementi[i][k] * m2.elementi[k][j];
      }
      m3.elementi[i][j] = suma;
      suma = 0;
    }
  }
  return m3; 
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> m, std::vector<TipElemenata> v) {
  if (m.br_kolona != m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
  auto m2 = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
  auto m3 = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
  //auto tempo = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
  for (int i = 0; i < m.br_redova; i++) 
    for (int j = 0; j < m.br_kolona; j++) 
      m2.elementi[i][i] = 1, 
      m3.elementi[i][j] = 0;
  for (int i = 1; i < v.size(); i++) {
    auto tempo = ProduktMatrica(m2, m);
    for (int ii = 0; ii < tempo.br_redova; ii++)
      for (int jj = 0; jj < tempo.br_kolona; jj++)
        m2.elementi[ii][jj] = tempo.elementi[ii][jj];
    for (int ii = 0; ii < m3.br_redova; ii++)
      for (int jj = 0; jj < m3.br_kolona; jj++)
        m3.elementi[ii][jj] += m2.elementi[ii][jj] * v[i];
    
    UnistiMatricu(tempo);
  }
  for (int i = 0; i < m3.br_redova; i++) {
    m3.elementi[i][i] += v[0];
  }
  UnistiMatricu(m2);
  //UnistiMatricu(tempo);
  return m3;
}

int main() {
  Matrica<double> a, c;
  int n;
  std::cout << "Unesite dimenziju kvadratne matrice: ";
  std::cin >> n;
  try {
    a = StvoriMatricu<double>(n, n);
    std::cout << "Unesite elemente matrice A:\n";
    UnesiMatricu('A', a); 
    //IspisiMatricu(a,10,6);
    std::cout << "Unesite red polinoma: "; 
    int RedPolinoma; std::cin >> RedPolinoma;
    std::cout << "Unesite koeficijente polinoma: ";
    std::vector<double> koef;
    for (int i = 0; i <= RedPolinoma; i++) {
      double tmp; std::cin >> tmp;
      koef.pb(tmp);
    }
    try {
      //c = MatricniPolinom(a, koef);
      IspisiMatricu(c = MatricniPolinom(a,koef), 10, 6);
      //MatricniPolinom(a, koef);
      
    } 
    catch (std::domain_error cc) {
      std::cout << cc.what();
    }
      
  }
  catch(std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
  }
  UnistiMatricu(a); UnistiMatricu(c);
  return 0;
}
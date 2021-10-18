#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata> 
struct Matrica {
  int br_redova, br_kolona;
  TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
  if (!mat.elementi) return;
  for (int i = 0; i < mat.br_redova; i++)
    delete[] mat.elementi[i];
  delete[] mat.elementi;
  mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
  Matrica<TipElemenata> mat;
  mat.br_redova = br_redova;
  mat.br_kolona = br_kolona;
  mat.elementi = new TipElemenata*[br_redova];
  for (int i = 0; i < br_redova; i++)
    mat.elementi[i] = nullptr;
  try {
    for (int i = 0; i < br_redova; i++)
      mat.elementi[i] = new TipElemenata[br_kolona];
  } catch (...) {
    UnistiMatricu(mat);
    throw;
  }
  return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
  for (int i = 0; i < mat.br_redova; i++){
    for (int j = 0; j < mat.br_kolona; j++) {
    std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
    std::cin >> mat.elementi[i][j];
    }
  }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
  for (int i = 0; i < mat.br_redova; i++) {
    for (int j = 0; j < mat.br_kolona; j++)
      std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
    std::cout << std::endl;
  }
  if(treba_brisati) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
  if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije !");
  auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
  for (int i = 0; i < m1.br_redova; i++)
    for (int j = 0; j < m1.br_kolona; j++)
      m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
  return m3;
}

//MINE
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto vrati(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++){
      for(int j=0; j<m2.br_kolona; j++){
        vrati.elementi[i][j]=0;
        for(int k=0; k<m2.br_redova; k++){
          vrati.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
        }
      }
    }
    return vrati;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatPutaKoef(const Matrica<TipElemenata> &m, double koef){
  auto vrati(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
  for(int i=0; i<m.br_redova; i++)
    for(int j=0; j<m.br_kolona; j++)
      vrati.elementi[i][j]=m.elementi[i][j]*koef;
  return vrati;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> A, std::vector<double> v){
  if(A.br_kolona!=A.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
  auto Pa(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
  for(int i=0; i<Pa.br_redova; i++)
    for(int j=0; j<Pa.br_kolona; j++)
      Pa.elementi[i][j]=0;
      
  for(int k=0; k<v.size(); k++){
    if(!k){
      auto I(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
      for(int i=0; i<I.br_redova; i++)
        for(int j=0; j<I.br_kolona; j++)
          if(i!=j) I.elementi[i][j]=0;
          else I.elementi[i][j]=1;
      auto matpk(MatPutaKoef<TipElemenata>(I, v[k]));
      auto zbir(ZbirMatrica<TipElemenata>(Pa, matpk)); UnistiMatricu(Pa); Pa=zbir;
      UnistiMatricu(matpk);
      UnistiMatricu(I);
    }else if(k==1){
      auto matpk(MatPutaKoef<TipElemenata>(A, v[k]));
      auto zbir(ZbirMatrica<TipElemenata>(Pa, matpk)); UnistiMatricu(Pa); Pa=zbir;
      UnistiMatricu(matpk);
    }else{
      auto tempA(A);
      for(int m=1; m<k; m++){
        auto prodMat(ProduktMatrica<TipElemenata>(tempA, A));
        if(m>1) UnistiMatricu(tempA); 
        tempA=prodMat;
      }
      auto matpk(MatPutaKoef<TipElemenata>(tempA, v[k]));
      auto zbir(ZbirMatrica(Pa, matpk)); UnistiMatricu(Pa); Pa=zbir;
      UnistiMatricu(matpk);
      UnistiMatricu(tempA);
    }
  }
  return Pa;
}

int main (){
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int dim; std::cin>>dim;
    std::cout<<"Unesite elemente matrice A: "<<std::endl;
    auto A(StvoriMatricu<double>(dim, dim));
    UnesiMatricu('A', A);
    std::cout<<"Unesite red polinoma: ";
    int red; std::cin>>red;
    std::cout<<"Unesite koeficijente polinoma: ";
    std::vector<double> k; double unos;
    for(int i=0; i<=red; i++){
      std::cin>>unos;
      k.push_back(unos);
    }
    auto matPol(MatricniPolinom<double>(A,k));
    IspisiMatricu(matPol, 10);
    UnistiMatricu(matPol);
    UnistiMatricu(A);
	return 0;
}
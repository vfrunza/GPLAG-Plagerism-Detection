/B2016/2017: Zadaća 3, Zadatak 3

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
     if(!mat.elementi) return;
     for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
     delete[] mat.elementi;
     mat.elementi = nullptr;
 }
template <typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
     Matrica<TipElemenata> mat;
     mat.br_redova = br_redova; mat.br_kolona = br_kolona;
     mat.elementi = new TipElemenata*[br_redova];
     for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
     try {
     for(int i = 0; i < br_redova; i++)
     mat.elementi[i] = new TipElemenata[br_kolona];
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
     std::cout << ime_matrice
     << "(" << i + 1 << "," << j + 1 << ") = ";
     std::cin >> mat.elementi[i][j];
     }
 }
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat,
 int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
     for(int i = 0; i < mat.br_redova; i++) {
     for(int j = 0; j < mat.br_kolona; j++)
     std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
     std::cout << std::endl;
     }
     if(treba_brisati) 
     UnistiMatricu(mat);
 }
 
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
     const Matrica<TipElemenata> &m2) {
     if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
     throw std::domain_error("Matrice nemaju jednake dimenzije!");
     auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
     for(int i = 0; i < m1.br_redova; i++)
     for(int j = 0; j < m1.br_kolona; j++)
     m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
     return m3;
 }
 
template <typename TipElemenata>
 Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,
    const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona != m2.br_redova) 
    throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
    for(int j = 0; j < m2.br_kolona; j++){
        int brojac(0);
        double proizvod(0);
        m3.elementi[i][j] = 0;
        while(brojac < m1.br_kolona){
           proizvod = m1.elementi[i][brojac]*m2.elementi[brojac][j];
           m3.elementi[i][j] += proizvod; 
           brojac++;
        }
    }
    return m3;
 }

template <typename TipElemenata>
 void PopuniMatricuM1KaoM2(const Matrica<TipElemenata> &m1, 
      const Matrica<TipElemenata> &m2){
      for(int i=0; i<m1.br_redova; i++)
      for(int j=0; j<m2.br_kolona; j++)
       m1.elementi[i][j] = m2.elementi[i][j];
       
 }
template <typename TipElemenata>
 void MnozenjeBrojem(const Matrica<TipElemenata> &m1,
      const double &x){
      for(int i=0; i<m1.br_redova; i++)
      for(int j=0; j<m1.br_kolona; j++)
      m1.elementi[i][j]*=x;
 }
template <typename TipElemenata>
 Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1,
    const std::vector<double> &v){
    if(m1.br_kolona != m1.br_redova) 
    throw std::domain_error("Matrica mora biti kvadratna");
    auto m(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    auto m2(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i<m1.br_kolona; i++)
    for(int j=0; j<m1.br_kolona; j++){
       m.elementi[i][j]=0;
       m2.elementi[i][j]=0;
    }
    Matrica<TipElemenata> pomocna;
    for(int i=0; i<v.size(); i++){
        
       if(i==0){
         for(int j=0; j<m1.br_kolona; j++)
         for(int k=0; k<m1.br_kolona; k++){
           if(j!=k)m.elementi[j][k] = 0;
           else m.elementi[j][k] = 1;
         }
       }
       else {
         pomocna = ProduktMatrica(m1,m);
         UnistiMatricu(m);
         m = StvoriMatricu<TipElemenata>(m1.br_kolona,m1.br_kolona);
         PopuniMatricuM1KaoM2(m,pomocna);
         UnistiMatricu(pomocna);
       }
       
       pomocna = StvoriMatricu<TipElemenata>(m1.br_kolona,m1.br_kolona) ;
       PopuniMatricuM1KaoM2(pomocna,m);
       MnozenjeBrojem(pomocna,v[i]);
       auto m3 = ZbirMatrica(m2,pomocna);
       UnistiMatricu(m2);
       m2 = StvoriMatricu<TipElemenata>(m1.br_kolona,m1.br_kolona);
       PopuniMatricuM1KaoM2(m2,m3);
       UnistiMatricu(m3);
       UnistiMatricu(pomocna);
       
       
       
    }
    UnistiMatricu(m);
    return m2;
    
 }

int main() {
 try{
  std::cout<< "Unesite dimenziju kvadratne matrice: ";
  int dimenzija; 
  std::cin>>dimenzija;
  std::cout<< "Unesite elemente matrice A: " << std::endl;
  Matrica<double> mat (StvoriMatricu<double>(dimenzija,dimenzija));
  UnesiMatricu('A',mat);
  std::cout<<"Unesite red polinoma: ";
  int red;
  std::cin>>red;
  std::cout<<"Unesite koeficijente polinoma: ";
  std::vector<double> koeficijenti;
  while (red>=0) {
    double n;
    std::cin>>n;
    koeficijenti.push_back(n);
    red--;
  }
  auto matricni_polinom (MatricniPolinom<double>(mat, koeficijenti));
  IspisiMatricu(matricni_polinom,10);
  UnistiMatricu(mat);
  UnistiMatricu(matricni_polinom);
 }
 catch(std::domain_error e){
  std::cout<<e.what();
 }

 return 0;
}

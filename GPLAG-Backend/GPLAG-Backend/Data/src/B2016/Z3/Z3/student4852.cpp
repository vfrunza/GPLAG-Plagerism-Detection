#include <iostream>
#include <iomanip>
#include <stdexcept>
#include<vector>
#include <new>
template <typename TipElemenata>
 struct Matrica {
 int br_redova, br_kolona;
 TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
 };
template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) {
 if(!mat.elementi) return;
 for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
 delete [] mat.elementi;
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
 void Kopiraj(Matrica<TipElemenata> mat1, Matrica<TipElemenata>mat2) {
  for(int i = 0; i < mat2.br_redova; i++)
 for(int j = 0; j < mat2.br_kolona; j++) {
 mat2.elementi[i][j]=mat1.elementi[i][j];
 }
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> StvoriJedinicnu(int br_redova) {
 Matrica<TipElemenata> mat;
 mat.br_redova = br_redova; mat.br_kolona = br_redova;
 mat.elementi = new TipElemenata*[br_redova];
 for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
 try {
 for(int i = 0; i < br_redova; i++)
 mat.elementi[i] = new TipElemenata[br_redova];
 }
 catch(...) {
 UnistiMatricu(mat);
 throw;
 }
  for(int i = 0; i < mat.br_redova; i++)
  for(int j = 0; j < mat.br_redova; j++)
  if(i==j)
 mat.elementi[i][i]=1;
 else
 mat.elementi[i][j]=0;
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
 void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=8,bool treba_brisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa)<<std::setprecision(preciznost)<< mat.elementi[i][j];
 std::cout << std::endl;
 }
 if(treba_brisati)
 UnistiMatricu(mat);
 }
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }
 template <typename TipElemenata>
 void PomnoziMatricuRealnimBrojem(const Matrica<TipElemenata> &m1,
 double r) {
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m1.elementi[i][j] =r*m1.elementi[i][j];
 }
  template <typename TipElemenata>
 void PodijeliMatricuRealnimBrojem(const Matrica<TipElemenata> &m1,
 double r) {
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m1.elementi[i][j] =m1.elementi[i][j]/r;
 }
 template <typename TipElemenata>
bool MoguSeMnoziti(Matrica<TipElemenata> m1, Matrica<TipElemenata> m2) {
 return m1.br_kolona == m2.br_redova;
}
 template <typename TipElemenata>
bool DaLiJeKvadratna(Matrica<TipElemenata> m1) {
 return m1.br_redova == m1.br_kolona;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> m1, Matrica<TipElemenata> m2) {
    if(!MoguSeMnoziti(m1,m2))throw std::domain_error("Matrice nisu saglasne za mnozenje");
 Matrica<TipElemenata> m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m2.br_kolona; j++) {
 double suma(0);
 for(int k = 0; k < m2.br_redova; k++) suma += m1.elementi[i][k] * m2.elementi[k][j];
 m3.elementi[i][j] = suma;
 }
 return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> A,std::vector<double>koeficijenti){
    if(!DaLiJeKvadratna(A))throw std::domain_error("Matrica mora biti kvadratna");
    if(koeficijenti.size()==0){ PomnoziMatricuRealnimBrojem(A,0);return A;}
    Matrica<TipElemenata> A2(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    Matrica<TipElemenata> A1(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    Kopiraj(A,A1);
    Matrica<TipElemenata> pomocna;
    Matrica<TipElemenata>MPolinom;
    MPolinom=StvoriJedinicnu<TipElemenata>(A.br_redova);
    for(int i=0;i<koeficijenti.size();i++){
        if(i==0||i==1){
            if(i==0){
           pomocna=MPolinom;
            PomnoziMatricuRealnimBrojem(MPolinom,koeficijenti[i]);
            }
            if(i==1){
            pomocna=MPolinom;
                PomnoziMatricuRealnimBrojem(A1,koeficijenti[i]);
                if(koeficijenti[i]==0)
                 Kopiraj(A1,A2);
            MPolinom=ZbirMatrica(A1,MPolinom);
           UnistiMatricu(pomocna);
            }
            }
        else{
            if(koeficijenti[i-1]!=0){
            PodijeliMatricuRealnimBrojem(A1,koeficijenti[i-1]);
            if(koeficijenti[i]==0){
            pomocna=A1;
            A1=ProduktMatrica(A1,A);
          UnistiMatricu(pomocna);
            Kopiraj(A1,A2);
            }
            }
            else {
            Kopiraj(A2,A1);
            }
            pomocna=A1;
            A1=ProduktMatrica(A1,A);
           UnistiMatricu(pomocna);
            pomocna=MPolinom;
            PomnoziMatricuRealnimBrojem(A1,koeficijenti[i]);
            MPolinom=ZbirMatrica(MPolinom,A1);
         UnistiMatricu(pomocna);
        }
    }
  UnistiMatricu(A1);
  UnistiMatricu(A2);
    return MPolinom;
}

int main() {
 Matrica<double> a,b; // AUTOMATSKA INICIJALIZACIJA!!!
 int m, n;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m;
 try {
 a = StvoriMatricu<double>(m, m);
 std::cout << "Unesite elemente matrice A: "<<std::endl;
 UnesiMatricu('A', a);
 std::cout<<"Unesite red polinoma: ";
 std::cin>>n;
  std::vector<double>v(n+1);
  std::cout<<"Unesite koeficijente polinoma: ";
 for(int i=0;i<=n;i++){
     std::cin>>v[i];
 }
 b=MatricniPolinom(a,v);
 IspisiMatricu(b,10,6);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!";
 }
 UnistiMatricu(a); UnistiMatricu(b);
 return 0;
}

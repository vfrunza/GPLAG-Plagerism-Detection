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
 for(int i = 0; i < mat.br_redova; i++)
  delete[] mat.elementi[i];
 delete[] mat.elementi;
 mat.elementi = nullptr;
 mat.br_kolona=0;
 mat.br_redova=0;
 }
template <typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
 Matrica<TipElemenata> mat;
 mat.br_redova = br_redova; mat.br_kolona = br_kolona;
 try {
 mat.elementi = new TipElemenata*[br_redova];
 for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;

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
 void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,
 int preciznost=6,bool treba_se_brisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) <<std::setprecision(preciznost)<< mat.elementi[i][j];
 std::cout << std::endl;
 }
 if(treba_se_brisati) {
  UnistiMatricu(mat);
 }
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> operator *(TipElemenata n,Matrica<TipElemenata> mat) {
  auto proizvod(StvoriMatricu<double>(mat.br_redova,mat.br_kolona));
  if(proizvod.elementi) {
  for(int i=0;i<proizvod.br_redova;i++) {
   for(int j=0;j<proizvod.br_kolona;j++) {
    proizvod.elementi[i][j]=n*mat.elementi[i][j];
   }
  }
  }
  return proizvod;
 }
 template <typename TipElemenata>
 Matrica<TipElemenata>  ProduktMatrica(Matrica<TipElemenata> &m1,Matrica<TipElemenata> &m2) {
     try {
     if(m1.br_kolona!=m2.br_redova) {
         throw std::domain_error("Matrice nisu saglasne za mnozenje");
     }
auto matrica(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
if(matrica.elementi) {
    for(int i=0;i<m1.br_redova;i++) {
        double suma(0);
        for(int j=0;j<m2.br_kolona;j++) {
         suma=0;
         for(int k=0;k<m1.br_kolona;k++) {
            suma+=m1.elementi[i][k]*m2.elementi[k][j];
        }
        matrica.elementi[i][j]=suma;
        }
    }
}
        return matrica;
 }
 catch(std::domain_error e) {
  std::cout<<e.what()<<std::endl;
 }
 catch(...) {
  std::cout<<"Problemi sa memorijom!"<<std::endl;
 }
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
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> &mat,std::vector<double> &v) {
 try {
 if(mat.br_kolona!=mat.br_redova) {
  throw std::domain_error("Matrica mora biti kvadratna");
 }
 if(v.size()==0) {
  auto rez(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
  if(rez.elementi) {
  for(int i=0;i<mat.br_redova;i++) {
   for(int j=0;j<mat.br_kolona;j++) {
    rez.elementi[i][j]=0;
   }
  }
  }
  return rez;
 }
 auto jedinicna(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
 if(jedinicna.elementi) {
 for(int t=0;t<jedinicna.br_redova;t++) {
  for(int z=0;z<jedinicna.br_kolona;z++) {
   if(t==z) {
    jedinicna.elementi[t][z]=1;
   }
   else jedinicna.elementi[t][z]=0;
  }
 }
 }
 Matrica<TipElemenata> obrisano(jedinicna);
Matrica<TipElemenata> vraceno;
 auto p(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
 if(p.elementi) {
 for(int u=0;u<p.br_redova;u++) {
  for(int v=0;v<p.br_kolona;v++) {
   p.elementi[u][v]=mat.elementi[u][v];
  }
 }
 }
 for(int k=0;k<v.size();k++) {
  if(k==0) {
  vraceno=v[k]*jedinicna;
 }
 else {
  Matrica<TipElemenata> usputni(vraceno);
  Matrica<TipElemenata> pomocni(p);
 vraceno=ZbirMatrica(vraceno,v[k]*p);
 p=ProduktMatrica(p,mat);
 UnistiMatricu(pomocni);
 UnistiMatricu(usputni);
}
}
UnistiMatricu(obrisano);
return vraceno;
}
catch(std::domain_error e) {
 std::cout<<e.what()<<std::endl;
 }
}

int main() {
 Matrica<double> a , polinom;
 int m(0);
 std::cout << "Unesite dimenziju kvadratne matrice:";
 std::cin >> m;
 try {
 a = StvoriMatricu<double>(m, m);
 std::cout << " Unesite elemente matrice A:\n";
 UnesiMatricu('A', a);
 std::cout << "Unesite red polinoma: ";
 int n;
 std::cin>>n;
 std::vector<double> v;
 std::cout<<"Unesite koeficijente polinoma: ";
 for(int i=0;i<=n;i++) {
  double x;
  std::cin>>x;
  v.push_back(x);
 }
 IspisiMatricu(polinom = MatricniPolinom(a,v),10,5);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 UnistiMatricu(a); UnistiMatricu(polinom);
 return 0;
}
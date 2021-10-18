/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template <typename TipElemenata>
 struct Matrica {
 int br_redova, br_kolona;
 TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
 };
template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) {
 if(!mat.elementi) return;
 for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
 delete[] mat.elementi;
 mat.elementi = nullptr;
 }
 template<typename TipElemenata>
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
 void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisat=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout <<std::setprecision(preciznost)<< std::setw(sirina_ispisa) << mat.elementi[i][j];
 std::cout << std::endl;
 }
 if(treba_brisat==true)
 {
  UnistiMatricu(mat);
 }
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> mat1,Matrica<TipElemenata> mat2)
{
 if(mat1.br_kolona!=mat2.br_redova){throw std::domain_error("Matrice nisu saglasne za mnozenje");}
 auto m3(StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona));
 for(auto i=0;i<m3.br_redova;i++)
 {
  for(auto j=0;j<m3.br_kolona;j++)
  {
   TipElemenata suma(0);
   int k(0);
   while(k!=mat1.br_kolona)
   {
    suma+=(mat1.elementi[i][k]*mat2.elementi[k][j]);
    k++;
   }
   m3.elementi[i][j]=suma;
  }
 }
 return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> mat,std::vector<double> polinom)
{
 if(mat.br_kolona!=mat.br_redova)throw std::domain_error("Matrica mora biti kvadratna");
 auto m3(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
 if(polinom.size()==0)
 {
  for(auto i=0;i<mat.br_redova;i++)
   for(auto j=0;j<mat.br_kolona;j++)m3.elementi[i][j]=0;
   return m3;
 }
 auto jedinicna(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
 auto pomoc(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
 auto vratiti(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
 for(auto i=0;i<mat.br_redova;i++)
 {
  for(auto j=0;j<mat.br_kolona;j++)
  {
   if(i==j)jedinicna.elementi[i][j]=1;
   else jedinicna.elementi[i][j]=0;
   m3.elementi[i][j]=mat.elementi[i][j];
  }
 }
 for(auto i=0;i<polinom.size();i++)
 {
  if(i==0)
  {
   for(auto k=0;k<mat.br_redova;k++)
   {
    for(auto f=0;f<mat.br_kolona;f++)
    {
     vratiti.elementi[k][f]=polinom[0]*jedinicna.elementi[k][f];
    }
   }
  }
  else if (i==1)
  {
    for(auto k=0;k<mat.br_redova;k++)
   {
    for(auto f=0;f<mat.br_kolona;f++)
    {
     pomoc.elementi[k][f]=polinom[1]*mat.elementi[k][f];
    }
   }
   auto a(vratiti);
   vratiti=ZbirMatrica(vratiti,pomoc);
   UnistiMatricu(a);
  }
  else
  {
   auto p(m3);
   m3=ProduktMatrica(m3,mat);
   UnistiMatricu(p);
    for(auto k=0;k<mat.br_redova;k++)
   {
    for(auto f=0;f<mat.br_kolona;f++)
    {
     pomoc.elementi[k][f]=polinom[i]*m3.elementi[k][f];
    }
   }
   auto g(vratiti);
   vratiti=ZbirMatrica(vratiti,pomoc);
   UnistiMatricu(g);
  }
 }
 UnistiMatricu(m3);UnistiMatricu(pomoc);UnistiMatricu(jedinicna);
 return vratiti;
}
int main() {
 Matrica<double> a, b;// AUTOMATSKA INICIJALIZACIJA!!!
 std::vector<double> poslati;
 int m,n;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m ;
 try {
 a = StvoriMatricu<double>(m,m);
 //b=StvoriMatricu<double>(m,m);
 std::cout << "Unesite elemente matrice A:\n";
 UnesiMatricu('A', a);
 std::cout<<"Unesite red polinoma: ";
 std::cin>>n;
 std::cout<<"Unesite koeficijente polinoma: ";  
 for(auto i=0;i<=n;i++)
 {
  double broj;
  std::cin>>broj;
  poslati.push_back(broj);
 }
 try
 {
  IspisiMatricu(b=MatricniPolinom(a,poslati),10,6,false);
 }
 catch(std::domain_error)
 {
  std::cout<<"Matrica mora biti kvadratna";
 }
 UnistiMatricu(a);
 UnistiMatricu(b);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 catch(std::domain_error)
 {
  std::cout<<"Matrice nisu saglasne za mnozenje";
 }
 
 return 0;
}

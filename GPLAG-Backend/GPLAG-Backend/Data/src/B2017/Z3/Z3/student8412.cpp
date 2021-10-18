#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include<list>
#include<exception>
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
 int sirina_ispisa,int preciznost=6,bool treba_obrisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) <<std::setprecision(preciznost)<< mat.elementi[i][j];
 std::cout << std::endl;
 }
 if(treba_obrisati) UnistiMatricu(mat);
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
 Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &a,const Matrica<TipElemenata> &b)
 {
  if(a.br_kolona!=b.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
  int m=a.br_redova,n=b.br_kolona;
  auto c(StvoriMatricu<TipElemenata>(m,n));
   for(int i=0;i<m;i++)
  {
   for(int j=0;j<n;j++)
   c.elementi[i][j]=0;
  }
  for(int i=0;i<a.br_redova;i++)
  {
   for(int j=0;j<b.br_kolona;j++)
   {
    
    for(int l=0;l<a.br_kolona;l++)
    {
     c.elementi[i][j]+=a.elementi[i][l]*b.elementi[l][j];
    }
    
   }
  }
  return c;
 }
template <typename TipElemenata,typename Itertip>
 Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> a,int n,Itertip pok)
 {
  if(n<0) throw std::domain_error("Neispravan stepen polinoma");
  if(a.br_kolona!=a.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
  int m=a.br_kolona;
  auto c(StvoriMatricu<TipElemenata>(m,m));
  for(int i=0;i<m;i++)
  {
   for(int j=0;j<m;j++)
   c.elementi[i][j]=0;
  }
  auto d(StvoriMatricu<TipElemenata>(m,m));
   for(int i=0;i<m;i++)
  {
   for(int j=0;j<m;j++){
    d.elementi[i][j]=a.elementi[i][j];
   }
  }
  
  for(int k=0;k<=n;k++)
  {
   
   if(k>1){
   
   auto r=ProduktMatrica(d,a);
   /*if(k==3) {std::cout << "OVO JE" << std::endl;
    IspisiMatricu(r);
    std::cout << "et" << std::endl;
   }*/
   for(int i=0;i<m;i++)
  {
   for(int j=0;j<m;j++){
    d.elementi[i][j]=r.elementi[i][j];
   }
  }
   for(int i=0;i<m;i++)
  {
   for(int j=0;j<m;j++)
   r.elementi[i][j]=r.elementi[i][j]*(*pok);
  }
   auto p=ZbirMatrica(c,r);
   //c=p; ne moze ovo jer kad izbrisemo p,nece c postojat
     for(int i=0;i<m;i++)
  {
   for(int j=0;j<m;j++){
   c.elementi[i][j]=p.elementi[i][j];}
  }
   UnistiMatricu(p);
   /*std::cout <<"Matrica" << std::endl;
   IspisiMatricu(r);*/
   UnistiMatricu(r);
   }
   else{
    if(k==0) {
     
     auto r=StvoriMatricu<TipElemenata>(m,m);
     for(int i=0;i<m;i++)
  {
   for(int j=0;j<m;j++)
  {
   if(i==j) r.elementi[i][j]=1;
   else r.elementi[i][j]=0;
   r.elementi[i][j]=r.elementi[i][j]*(*pok);
  }
  }
   auto p=ZbirMatrica(c,r);
   //c=p; ne moze ovo jer kad izbrisemo p,nece c postojat
     for(int i=0;i<m;i++)
  {
   for(int j=0;j<m;j++){
   c.elementi[i][j]=p.elementi[i][j];}
  }
   UnistiMatricu(p);
   /*std::cout <<"Matrica" << std::endl;
   IspisiMatricu(r);*/
   UnistiMatricu(r);
    }
    if(k==1)
    {
     auto r(StvoriMatricu<TipElemenata>(m,m));
      for(int i=0;i<m;i++)
  {
   for(int j=0;j<m;j++)
  {
   r.elementi[i][j]=a.elementi[i][j];
   r.elementi[i][j]=r.elementi[i][j]*(*pok);
  }
  }
    
     auto p=ZbirMatrica(c,r);
   //c=p; ne moze ovo jer kad izbrisemo p,nece c postojat
     for(int i=0;i<m;i++)
  {
   for(int j=0;j<m;j++){
   c.elementi[i][j]=p.elementi[i][j];}
  }
   UnistiMatricu(p);
  /* std::cout <<"Matrica" << std::endl;
   IspisiMatricu(r);*/
   UnistiMatricu(r);
   }
   }
  
   pok++;
  }
  UnistiMatricu(d);
  return c;
 }

int main() {
 Matrica<double> a; 
 int n;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> n;
 try {
 a = StvoriMatricu<double>(n, n);

 std::cout << "Unesite elemente matrice A:\n";
 UnesiMatricu('A', a);
 std::cout<<"Unesite red polinoma: ";
 int k;
 std::cin>>k;
 std::cout << "Unesite koeficijente polinoma: " ;
 std::list<int> koef(k+1) ;
 auto pok=koef.begin();
 auto pok2=pok;
 for(int i=0;i<=k;i++)
 {
  std::cin>>*(pok2);
  pok2++;
  
 } 
 Matrica<double> m=MatricniPolinom(a,k,pok);
 
 IspisiMatricu(m,10,6);
 UnistiMatricu(m); 

 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 UnistiMatricu(a); 
 return 0;
}
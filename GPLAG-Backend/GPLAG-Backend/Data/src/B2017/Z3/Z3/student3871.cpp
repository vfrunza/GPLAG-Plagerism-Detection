/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <new>

template<typename TipElemenata>
struct Matrica
{
 int br_redova, br_kolona;
 TipElemenata **elementi=nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
 if(!mat.elementi) return;
 for(int i(0);i<mat.br_redova;i++) delete[] mat.elementi[i];
 delete[] mat.elementi;
 mat.elementi=nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona)
{
 Matrica<TipElemenata> mat;
 mat.br_redova=br_redova;
 mat.br_kolona=br_kolona;
 mat.elementi=new TipElemenata*[br_redova];
 for(int i(0);i<br_redova;i++) mat.elementi[i]=nullptr;
 try
 {
  for(int i(0);i<br_redova;i++)
   mat.elementi[i]=new TipElemenata[br_redova];
 }
 catch(...)
 {
  UnistiMatricu(mat);
  throw;
 }
 return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
 for(int i(0);i<mat.br_redova;i++)
 {
  for(int j(0);j<mat.br_kolona;j++)
  {
   std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
   std::cin >> mat.elementi[i][j];
  }
 }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina, int preciznost=6, bool treba_brisati=false)
{
 for(int i(0);i<mat.br_redova;i++)
 {
  for(int j(0);j<mat.br_kolona;j++)
  {
   std::cout << std::setw(sirina) << std::setprecision(preciznost) << mat.elementi[i][j];
  }
  std::cout << std::endl;
 }
 if(treba_brisati==true) UnistiMatricu(mat);
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
 if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
  throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
 for(int i(0);i<m1.br_redova;i++)
 {
  for(int j(0);j<m1.br_redova;j++)
  {
   m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
  }
 }
 return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2)
{
 if(mat1.br_kolona!=mat2.br_redova)
 {
  UnistiMatricu(mat1); UnistiMatricu(mat2);
  throw std::domain_error("Matrice nisu saglasne za mnozenje");
 }
 auto mat3(StvoriMatricu<TipElemenata>(mat1.br_redova,mat1.br_kolona));
 for(int i(0);i<mat3.br_redova;i++)
 {
  for(int j(0);j<mat3.br_kolona;j++)
  {
   mat3.elementi[i][j]=0;
  }
 }
 for(int i(0);i<mat1.br_redova;i++)
 {
  for(int j(0);j<mat2.br_kolona;j++)
  {
   TipElemenata suma(0);
   for(int k(0);k<mat2.br_redova;k++) suma+=mat1.elementi[i][k]*mat2.elementi[k][j];
   mat3.elementi[i][j]=suma;
  }
 }
 return mat3;
}

template<typename TipElemenata>
Matrica<TipElemenata> Jedinicna(Matrica<TipElemenata> mat)
{
 auto jedinicna(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
 for(int i(0);i<mat.br_redova;i++)
 {
  for(int j(0);j<mat.br_redova;j++)
  {
   if(i==j) jedinicna.elementi[i][j]=1;
   else jedinicna.elementi[i][j]=0;
  }
 }
 return jedinicna;
}

template<typename TipElemenata,typename Pok>
Matrica<TipElemenata> ProizvodBrojem(const Matrica<TipElemenata> &mat, Pok broj)
{
 auto pomocna(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
 for(int i(0);i<mat.br_redova;i++)
 {
  for(int j(0);j<mat.br_redova;j++)
  {
   pomocna.elementi[i][j]=mat.elementi[i][j]*broj;
  }
 }
 return pomocna;
}

template<typename TipElemenata>
Matrica<TipElemenata> Stepen(const Matrica<TipElemenata> &mat, int k)
{
 auto temp_matrica(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
 if(k==0) 
 {
  UnistiMatricu(temp_matrica);
  return Jedinicna(mat);
 }
 else if(k==1)
 {
  for(int i(0);i<mat.br_redova;i++)
  {
   for(int j(0);j<mat.br_kolona;j++)
   {
    temp_matrica.elementi[i][j]=mat.elementi[i][j];
   }
  }
  return temp_matrica;
 }
 else
 {
  for(int i(0);i<mat.br_redova;i++)
  {
   for(int j(0);j<mat.br_kolona;j++)
   {
    temp_matrica.elementi[i][j]=mat.elementi[i][j];
   }
  }
  for(int i(0);i<k-1;i++)
  {
   auto sadasnjaTemp = temp_matrica;
   temp_matrica=ProduktMatrica(sadasnjaTemp,mat);
   UnistiMatricu(sadasnjaTemp);
  }
 }
 return temp_matrica;
}

template<typename TipElemenata, typename Pok>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, int n, Pok pocetak)
{
  if(n<0) 
  {
   UnistiMatricu(mat);
   throw std::domain_error("Neispravan stepen polinoma");
  }
  if(mat.br_redova!=mat.br_kolona)
  {
   UnistiMatricu(mat);
   throw std::domain_error("Matrica mora biti kvadratna");
  }
  auto zbir(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
  for(int i(0);i<mat.br_redova;i++)
  {
   for(int j(0);j<mat.br_redova;j++)
   {
    zbir.elementi[i][j]=0;
   }
  }
  for(int i(0);i<=n;i++)
  {
   auto stepena=Stepen(mat,i);
   auto proizvod=ProizvodBrojem(stepena,*pocetak);
   pocetak++;
   auto sadasnjiZbir = zbir;
   zbir=ZbirMatrica(sadasnjiZbir,proizvod); 
   UnistiMatricu(sadasnjiZbir);
   UnistiMatricu(stepena);
   UnistiMatricu(proizvod);
  }
  return zbir;
}

int main ()
{
 try
 {
  int m,n,unos;
  Matrica<double> a;
  std::vector<int> v;
  std::cout << "Unesite dimenziju kvadratne matrice: ";
  std::cin >> m;
  a=StvoriMatricu<double>(m,m);
  std::cout << "Unesite elemente matrice A:" << std::endl;
  UnesiMatricu('A',a);
  std::cout << "Unesite red polinoma: ";
  std::cin >> n;
  std::cout << "Unesite koeficijente polinoma: ";
  for(int i(0);i<=n;i++)
  {
   std::cin >> unos;
   v.push_back(unos);
  }
  IspisiMatricu(MatricniPolinom(a,n,v.begin()),10,5,true);
  UnistiMatricu(a);
 }
 catch(std::bad_alloc)
 {
  std::cout << "Nema dovoljno memorije!" << std::endl;
 }
 catch(std::domain_error izuzetak)
 {
  std::cout << izuzetak.what() << std::endl;;
 }
 return 0;
}

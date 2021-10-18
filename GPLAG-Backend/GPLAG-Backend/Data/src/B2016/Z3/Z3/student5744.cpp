#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template <typename TipElemenata>
 struct Matrica 
 {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
 };
template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) 
 {
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
 }
template <typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) 
 {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try 
    {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...) 
    {
         UnistiMatricu(mat);
         throw;
    }
    return mat;
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &a,const Matrica<TipElemenata> &b)
 {
     if(b.br_redova!=a.br_kolona) throw std::domain_error("Matrice nisu saglasne za mnozenje");
     Matrica<TipElemenata> c=StvoriMatricu<TipElemenata>(a.br_redova,b.br_kolona);
     for(int i=0;i<a.br_redova;i++)
        for(int j=0;j<b.br_kolona;j++)
        {
            TipElemenata suma{};
            for(int k=0;k<a.br_kolona;k++)
                suma+=a.elementi[i][k]*b.elementi[k][j];
            c.elementi[i][j]=suma;
        }
     return c;
 }
template <typename TipElemenata,typename t2>
 Matrica<TipElemenata> Skalar(const Matrica<TipElemenata> &mat,t2 skal) 
 {
     for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) mat.elementi[i][j]*=skal;
    return mat;
 }
 
template <typename TipElemenata>
 void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
 {
     for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) 
        {
             std::cout << ime_matrice
             << "(" << i + 1 << "," << j + 1 << ") = ";
             std::cin >> mat.elementi[i][j];
        }
 }
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false) 
 {
     for(int i = 0; i < mat.br_redova; i++) 
     {
         for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)<< mat.elementi[i][j];
         std::cout << std::endl;
     }
     if(treba_brisati) UnistiMatricu(mat);
 }
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) 
 {
     if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
     auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
     for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
     return m3;
 }
 
 template <typename TipElemenata>
  Matrica<TipElemenata> kopiraj(const Matrica<TipElemenata> &m)
  {
      Matrica<TipElemenata> nova=StvoriMatricu<TipElemenata>(m.br_kolona,m.br_redova);
      for(int i=0;i<m.br_kolona;i++)
            for(int j=0;j<m.br_kolona;j++)
                nova.elementi[i][j]=m.elementi[i][j];
    return nova;
  }
 
template <typename TipElemenata>
 Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m,std::vector<double> vek)
 {
     if(m.br_kolona!=m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
     if(vek.size()==0) return Skalar(kopiraj(m),TipElemenata{});
     Matrica<TipElemenata> p=kopiraj(m),s=Skalar(kopiraj(m),TipElemenata{}),pom1,pom2;
     for(int i=0;i<m.br_kolona;i++) s.elementi[i][i]=1;
     s=Skalar(s,vek[0]);
     for(int i=1;i<vek.size();i++)
     {
         pom1=kopiraj(p);
         pom2=ZbirMatrica(s,Skalar(pom1,vek[i]));
         UnistiMatricu(s);
         s=pom2;
         pom2=ProduktMatrica(p,m);
         UnistiMatricu(p);
         p=pom2;
         UnistiMatricu(pom1);
     }
     UnistiMatricu(p);
     return s;
 }

int main() 
{
     Matrica<double> a, c; // AUTOMATSKA INICIJALIZACIJA!!!
     int m;
     std::cout << "Unesite dimenziju kvadratne matrice: ";
     std::cin >> m;
     try 
     {
         a = StvoriMatricu<double>(m,m);
         std::cout << "Unesite elemente matrice A:\n";
         UnesiMatricu('A', a);
         std::cout << "Unesite red polinoma: ";
         std::cin >> m;
         std::vector<double> v(m+1);
         std::cout << "Unesite koeficijente polinoma: ";
         for(double &x:v) std::cin >> x;
         IspisiMatricu(c=MatricniPolinom<double>(a,v),10);
     }
     catch(std::bad_alloc) 
     {
        std::cout << "Nema dovoljno memorije!\n";
     }
     UnistiMatricu(a);UnistiMatricu(c);
     return 0;
}

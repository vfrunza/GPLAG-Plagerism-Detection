/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElementa>
struct Matrica {
      int br_redova, br_kolona;
      TipElementa **elementi=nullptr;
}; 

template <typename TipElementa>
void UnistiMatricu(Matrica<TipElementa> mat) {
  //    std::cout << "UNISTIO SAM " << std::endl;
      if(!mat.elementi) return; 
      for(int i=0; i<mat.br_redova; i++) { delete[] mat.elementi[i]; }
      delete[] mat.elementi;
      mat.elementi=nullptr;
}

template <typename TipElementa>
Matrica<TipElementa> StvoriMatricu(int br_redova, int br_kolona) {
      Matrica<TipElementa> mat;
      mat.br_redova=br_redova;
      mat.br_kolona=br_kolona;
      mat.elementi=new TipElementa*[br_redova];
  //    std::cout << "alociraooo sam" << std::endl; 
      for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr; 
      try {
            for(int i=0; i<br_redova; i++)
            mat.elementi[i]=new TipElementa[br_kolona]; 
      }
      catch(...) {
            UnistiMatricu(mat);
            throw;
      }
      return mat;
}

template <typename TipElementa>
void UnesiMatricu(char ime_matrice, Matrica<TipElementa> &mat) {
      for(int i=0; i<mat.br_redova; i++)
      for(int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";  
            std::cin >> mat.elementi[i][j];
      }
      
}

template <typename TipElementa>
void IspisiMatricu(Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
      for(int i=0; i<mat.br_redova; i++) {
      for(int j=0; j<mat.br_kolona; j++)
      std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) <<mat.elementi[i][j];
      std::cout << std::endl; }
      if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElementa>
Matrica<TipElementa> ZbirMatrica(const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2) {
      if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!"); 
      auto m3(StvoriMatricu<TipElementa>(m1.br_redova, m1.br_kolona));
      for(int i=0; i<m1.br_redova; i++)
      for(int j=0; j<m2.br_kolona; j++)
      m3.elementi[i][j]=m2.elementi[i][j]+m1.elementi[i][j];
      return m3; 
}

template <typename TipElementa>
Matrica<TipElementa> ProduktMatrica(const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2) {
      if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
     auto m3(StvoriMatricu<TipElementa>(m1.br_redova, m2.br_kolona));  
     for(int i=0; i<m1.br_redova; i++)
     for(int j=0; j<m2.br_kolona; j++) {
           TipElementa suma=0; 
           for(int k=0; k<m2.br_redova; k++)
           suma=suma+m1.elementi[i][k]*m2.elementi[k][j];
           m3.elementi[i][j]=suma;
           suma=0;
          
     }
     
     return m3;
      
}

template <typename TipElementa>
Matrica<TipElementa> MatricaPomnozenaSkalarom(const Matrica<TipElementa> &mat, TipElementa skalar) {
      auto rezultat(StvoriMatricu<TipElementa>(mat.br_redova, mat.br_kolona)); 
      for(int i=0; i<mat.br_redova; i++)
      for(int j=0; j<mat.br_kolona; j++)
      rezultat.elementi[i][j]=mat.elementi[i][j]*skalar; 
      return rezultat; 
}

template <typename TipElementa, typename IterTip>
Matrica<TipElementa> MatricniPolinom(const Matrica<TipElementa> &mat, int n, IterTip it) {
      if(n<0) throw std::domain_error("Neispravan stepen polinoma");
      if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
      auto P(StvoriMatricu<TipElementa>(mat.br_kolona, mat.br_kolona)); 
      for(int i=0; i<mat.br_kolona; i++)
      for(int j=0; j<mat.br_kolona; j++) {
      if(i==j) P.elementi[i][j]=1;
      else P.elementi[i][j]=0; 
      }
      auto P_n(MatricaPomnozenaSkalarom(P, *it++)); //ovdje dodajit++;
      UnistiMatricu(P);
    //  auto prethodni(StvoriMatricu<TipElementa>(mat.br_kolona, mat.br_kolona));
      auto prethodni=P_n;
      auto A(StvoriMatricu<TipElementa>(mat.br_kolona, mat.br_kolona)); 
   //   A=mat; //think about it
      for(int i=0; i<mat.br_kolona; i++)
      for(int j=0; j<mat.br_kolona; j++)
      A.elementi[i][j]=mat.elementi[i][j];
   //   IspisiMatricu(A, 5);

     // auto prethodnoA(StvoriMatricu<TipElementa>(mat.br_kolona, mat.br_kolona)); 
      auto prethodnoA=A;
      for(int i=1; i<=n; i++) {
         //   std::cout << "mnozim sa  " << *it; 
            auto ovapomozena(MatricaPomnozenaSkalarom(A,*it));
            it++;
//           IspisiMatricu(ovapomozena, 5);
            P_n=ZbirMatrica(P_n, ovapomozena);
      //      IspisiMatricu(P_n, 5); 
            UnistiMatricu(ovapomozena);
            A=ProduktMatrica(A,mat);
          //  IspisiMatricu(A, 5);     
            UnistiMatricu(prethodnoA);
            prethodnoA=A;
            UnistiMatricu(prethodni);
            prethodni=P_n;
      }
 // UnistiMatricu(prethodni);
      UnistiMatricu(prethodnoA);
      

      return P_n;
      
      
      
}

int main ()
{
      std::cout << "Unesite dimenziju kvadratne matrice: "; 
      int n; 
      std::cin >> n; 
      auto A(StvoriMatricu<int>(n,n));
      std::cout << "Unesite elemente matrice A: " << std::endl; 
      UnesiMatricu<int>('A', A); 
      std::cout << "Unesite red polinoma: ";
      int k; 
      std::cin >> k; 
      std::vector<int> onaj_polinom(k+1);
      std::cout << "Unesite koeficijente polinoma: ";
      int kopija_k(k); 
      for(int i=0; i<=k; i++) {
            int unos;
      std::cin >> unos; 
      onaj_polinom[i]=unos; }
      
      auto REZULTAT(MatricniPolinom(A,kopija_k,onaj_polinom.begin()));
      IspisiMatricu(REZULTAT, 10, 6);
      UnistiMatricu(REZULTAT);
      UnistiMatricu(A); 
      
	return 0;
}

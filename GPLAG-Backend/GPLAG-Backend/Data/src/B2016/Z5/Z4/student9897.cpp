/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <initializer_list>

template <typename TipEl> 
class GMatrica {
   
   TipEl mat[4][4]; 
   int broj_redova, broj_kolona; 
   
   public: 
   GMatrica(); 
   GMatrica(int broj_redova, int broj_kolona, TipEl vrijednost={});  
   GMatrica(const GMatrica &matr);
   GMatrica(TipEl matr[4][4]);
   GMatrica(std::vector<std::vector<TipEl>> matr); 
   GMatrica(std::initializer_list<std::initializer_list<TipEl>> lista); 
   int DajBrojRedova() const { return broj_redova; } 
   int DajBrojKolona() const { return broj_kolona; }
   GMatrica<TipEl> &operator()(int i, int j) const {
      if (i<1 || i>broj_redova || j<1 || j>broj_kolona) 
      throw std::range_error ("Nedozvoljen indeks"); 
      return mat[i][j];
   }
   
   template <typename TipEl1, typename TipEl2> 
   friend GMatrica<TipEl1> operator +(const GMatrica<TipEl2> &m1, const GMatrica<TipEl1> &m2); 
   template <typename TipEl1, typename TipEl2>
   friend GMatrica<TipEl1> operator -(const GMatrica<TipEl2> &m1, const GMatrica<TipEl1> &m2);  
   template <typename TipEl1, typename TipEl2> 
   friend GMatrica<TipEl1> operator *(const GMatrica<TipEl2> &m1, const GMatrica<TipEl1> &m2); 
   template <typename TipEl1, typename TipEl2> 
   friend GMatrica<TipEl1> operator *(const GMatrica<TipEl1> &m1, TipEl2 a); 
   template <typename TipEl1, typename TipEl2> 
   friend GMatrica<TipEl1> operator *(TipEl2 a, const GMatrica<TipEl1> &m1); 
   
   template <typename TipEl1, typename TipEl2> 
   friend GMatrica<TipEl1> &operator += (GMatrica<TipEl1> &m1, const GMatrica<TipEl2> &m2); 
   template <typename TipEl1, typename TipEl2> 
   friend GMatrica<TipEl1> &operator -= (GMatrica<TipEl1> &m1, const GMatrica<TipEl2> &m2); 
   template <typename TipEl1, typename TipEl2> 
   friend GMatrica<TipEl1> &operator *= (GMatrica<TipEl1> &m1, TipEl2 a); 
   
   template <typename TipEl1>
   friend bool operator ==(const GMatrica<TipEl1> &m1, const GMatrica<TipEl1> &m2);  
   template <typename TipEl1> 
   friend bool operator !=(const GMatrica<TipEl1> &m1, const GMatrica<TipEl1> &m2); 
   
   template <typename TipEl1> 
   friend std::ostream &operator <<(std::ostream &tok, const GMatrica<TipEl1> &m1); 
   template <typename TipEl1> 
   friend std::istream &operator >>(std::istream &tok, GMatrica<TipEl1> &m1); 
}; 

template <typename TipEl1> 
std::istream &operator >> (std::istream &tok, GMatrica<TipEl1> &m1) {
   char znak; 
   tok >> znak; 
   if (znak != '[') tok.setstate(std::ios::failbit); 
   for (int i=0; i<m1.broj_redova; i++) {
      for (int j=0; j<m1.broj_kolona; j++) {
         tok >> m1.mat[i][j]; 
      }
      tok >> znak; 
      if (znak != ';') tok.setstate(std::ios::failbit); 
   }
   
   tok >> znak; 
   if (znak != ']') tok.setstate(std::ios::failbit); 
   
   return tok; 
}

template <typename TipEl1> 
std::ostream &operator <<(std::ostream &tok, const GMatrica<TipEl1> &m1) {
   for (int i=0; i<m1.broj_redova; i++) {
      for (int j=0; j<m1.broj_kolona; j++) {
      tok << std::setw(6);
      tok << m1.mat[i][j];
      }
      tok << std::endl;
   }
   return tok; 
}

template <typename TipEl1>
bool operator ==(const GMatrica<TipEl1> &m1, const GMatrica<TipEl1> &m2) {
   bool iste=false; 
   for (int i=0; i<m1.broj_redova; i++) {
      for (int j=0; j<m1.broj_kolona; j++) {
      if (m1.mat[i][j]==m2.mat[i][j]) {
         iste=true; 
      }
     }
   }
   if (iste==true) return true; 
   else return false; 
}

template <typename TipEl1> 
bool operator !=(const GMatrica<TipEl1> &m1, const GMatrica<TipEl1> &m2) {
   bool razlicite=false; 
   for (int i=0; i<m1.broj_redova; i++) {
      for (int j=0; j<m1.broj_kolona; j++) {
      if (m1.mat[i][j]!=m2.mat[i][j]) {
         razlicite=true; 
      }
     }
   }
   if (razlicite==true) return true; 
   else return false; 
}

template<typename Tip1> 
GMatrica<Tip1>::GMatrica() { broj_kolona=0; broj_redova=0; }

template <typename Tip1> 
GMatrica<Tip1>::GMatrica(int broj_redova, int broj_kolona, Tip1 vrijednost) : broj_redova(broj_redova), broj_kolona(broj_kolona) {
   if (broj_redova<0 || broj_redova>4 || broj_kolona<0 || broj_kolona>4) 
   throw std::logic_error ("Ilegalan format matrice"); 
   
   for (int i=0; i<broj_redova; i++) {
      for (int j=0; j<broj_kolona; j++) 
      mat[i][j]=vrijednost; 
   }
}

template <typename Tip1> 
GMatrica<Tip1>::GMatrica(const GMatrica &matr) : broj_redova(matr.broj_redova), broj_kolona(matr.broj_kolona) {
   
   for (int i=0; i<broj_redova; i++) {
      for (int j=0; j<broj_kolona; j++) 
      mat[i][j]=matr[i][j];
   }
}

template <typename Tip1> 
GMatrica<Tip1>::GMatrica(Tip1 matr[4][4]) {
   for (int i=0; i<4; i++) {
      for (int j=0; j<4; j++) 
      mat[i][j]=matr[i][j];
   }
}

template <typename Tip1> 
GMatrica<Tip1>::GMatrica(std::vector<std::vector<Tip1>> matr) {
   if (matr.size()>4) throw std::logic_error ("Ilegalan format matrice"); 
   for (int i=0; i<matr.size(); i++) {
      if (matr[i].size()>4 || matr[i].size()<0) throw std::logic_error("Ilegalan format matrice"); 
   }
   
   for (int i=0; i<matr.size(); i++) {
      for (int j=0; j<matr[i].size(); j++) 
      mat[i][j]=matr[i][j];
   }
}

template <typename Tip1> 
GMatrica<Tip1>::GMatrica(std::initializer_list<std::initializer_list<Tip1>> lista) : broj_redova(lista.size()), broj_kolona(lista.size()) {
   if (lista.size()<0 || lista.size()>4) throw std::logic_error ("Ilegalan format matrice");
   
   auto it=lista.begin(); 
   auto it1=((*it).begin());
   
   for (auto i=0; i<broj_redova; i++) {
      for (auto j=0; j<broj_kolona; j++) {
      mat[i][j]=*it1; 
      it1++;
      }
      it++;
   }
}

template <typename TipEl1, typename TipEl2> 
GMatrica<TipEl1> operator +(const GMatrica<TipEl2> &m1, const GMatrica<TipEl1> &m2) {
   if (m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) 
   throw std::domain_error ("Nedozvoljena operacija"); 
   
   GMatrica<TipEl1> m3(m1.broj_redova, m1.broj_kolona);
   
   for (int i=0; i<m1.broj_redova; i++) {
      for (int j=0; j<m1.broj_kolona; j++)
         m3.mat[i][j]=m1.mat[i][j]+m2.mat[i][j]; 
   }
   return m3; 
}

template <typename TipEl1, typename TipEl2> 
GMatrica<TipEl1> operator -(const GMatrica<TipEl2> &m1, const GMatrica<TipEl1> &m2) {
   if (m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) 
   throw std::domain_error ("Nedozvoljena operator"); 
   
   GMatrica<TipEl1> m3(m1.broj_redova, m1.broj_kolona); 
   
   for (int i=0; i<m1.broj_redova; i++) {
      for (int j=0; j<m1.broj_kolona; j++) 
      m3.mat[i][j]=m1.mat[i][j]-m2.mat[i][j]; 
   }
   return m3; 
}

template <typename TipEl1, typename TipEl2> 
GMatrica<TipEl1> operator *(const GMatrica<TipEl2> &m1, const GMatrica<TipEl1> &m2) {
   if (m1.DajBrojRedova() != m2.DajBrojKolona()) throw std::domain_error ("Nedozvoljena operacija"); 
   
   GMatrica<TipEl1> m3; 
   
   for (int i=0; i<m1.broj_redova; i++) 
   for (int j=0; j<m2.broj_kolona; j++) {
   
      m3.mat[i][j]=0;
      for (int k=0; k<m1.broj_kolona; k++) 
      m3.mat[i][j]+=m1.mat[i][k]*m2.mat[k][j];
   }
   return m3; 
}

template <typename TipEl1, typename TipEl2> 
GMatrica<TipEl1> operator *(const GMatrica<TipEl1> &m1, TipEl2 a) {
   GMatrica<TipEl1> m3; 
   for (int i=0; i<m1.broj_redova; i++) {
      for (int j=0; j<m1.broj_kolona; j++)
      m3.mat[i][j]=m1.mat[i][j]*a; 
   }
}

template <typename TipEl1, typename TipEl2> 
GMatrica<TipEl1> operator *(TipEl2 a, const GMatrica<TipEl1> &m1) {
   GMatrica<TipEl1> m3; 
   for (int i=0; i<m1.broj_redova; i++) {
      for (int j=0; j<m1.broj_kolona; j++) 
      m3.mat[i][j]=a*m1.mat[i][j]; 
   }
}

template <typename TipEl1, typename TipEl2> 
GMatrica<TipEl1> &operator +=(GMatrica<TipEl1> &m1, const GMatrica<TipEl2> &m2) {
   
   if (m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) 
   throw std::domain_error ("Nedozvoljena operacija"); 
   
   for (int i=0; i<m1.broj_redova; i++) {
      for (int j=0; j<m1.broj_kolona; j++) {
         m1.mat[i][j]=m1.mat[i][j]+m2.mat[i][j]; 
      }
   }
   return m1; 
}

template <typename TipEl1, typename TipEl2> 
GMatrica<TipEl1> &operator -= (GMatrica<TipEl1> &m1, const GMatrica<TipEl2> &m2) {
   if (m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) 
   throw std::domain_error ("Nedozvoljena operacija"); 
   
   for (int i=0; i<m1.broj_redova; i++) {
      for (int j=0; j<m2.broj_kolona; j++) {
         m1.mat[i][j]=m1.mat[i][j]-m2.mat[i][j];
      }
   }
   return m1; 
}

template <typename TipEl1, typename TipEl2> 
GMatrica<TipEl1> &operator *= (GMatrica<TipEl1> &m1, TipEl2 a) {
   
   for (int i=0; i<m1.broj_redova; i++) {
      for (int j=0; j<m1.broj_kolona; j++) {
         m1.mat[i][j]=m1.mat[i][j]*a; 
      }
   }
      return m1; 
}

int main () {
   
   GMatrica<int> m1 ({{1,2}, {3,4}});
   GMatrica<int> m2 ({{1,2}, {3,4}}); 
   
   m1+=m2; 
   std::cout << m1 << std::endl; 
   
   m1-=m2; 
   std::cout << m1 << std::endl; 
   
   m1*=2; 
   std::cout << m1 << std::endl; 
   
   if (m1==m2) std::cout << std::endl << "OK"; 
   else std::cout << std::endl << "NOT OK"; 
   
	return 0;
}
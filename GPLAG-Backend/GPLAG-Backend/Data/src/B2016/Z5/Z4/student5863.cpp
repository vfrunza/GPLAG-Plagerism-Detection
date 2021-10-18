/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>
#include <string>
#include <type_traits>


template <typename TIP>
class GMatrica {
    TIP matrica[4][4];
    int br_redova = 0;
    int br_kolona = 0;
    
    public:
    
    GMatrica() = default;
    
    
    GMatrica(int br_redova, int br_kolona, TIP elementi = {});
      
    
  
    GMatrica(const GMatrica<TIP> &nova);
    
    
    GMatrica(TIP niz[4][4]);
   
    GMatrica(std::vector<std::vector<TIP>> dmat);
    
   
    GMatrica(std::initializer_list<std::initializer_list<TIP>> lista);
       
    
    int DajBrojRedova() const { return br_redova; }
    int DajBrojKolona() const { return br_kolona; } 
   
   template <typename tip, typename tip1>
   friend auto operator +(const GMatrica<tip> &mat, const GMatrica<tip1> &m) -> GMatrica<decltype( mat.matrica[0][0] + m.matrica[0][0] )>;
    
    template <typename tip1, typename tip2>
    friend auto operator *(const GMatrica<tip1> &mat, const GMatrica<tip2> &m) -> GMatrica<decltype( mat.matrica[0][0] + m.matrica[0][0] )>;
    
    template <typename tip1, typename tip2>
    friend auto operator *(const GMatrica<tip1> &m, tip2 mnozac) -> GMatrica<decltype( m.matrica[0][0] + mnozac)>;
   
    template <typename tip1, typename tip2>
    friend auto operator *(tip1 mnozac, GMatrica<tip2> &m) -> GMatrica<decltype( m.matrica[0][0] + mnozac)>;
    
    
    GMatrica<TIP> &operator +=( const GMatrica<TIP> &mat); 
    
   
    GMatrica<TIP> &operator *=(const GMatrica<TIP> &mat);
    
    
    GMatrica<TIP> &operator *=(TIP mnozac);
    
  
    GMatrica<TIP> &operator -=( const GMatrica<TIP> &m); 
    
    template <typename tip1, typename tip2>
    friend auto operator -(const GMatrica<tip1> &mat, const GMatrica<tip2> &m) -> GMatrica<decltype( m.matrica[0][0] + mat.matrica[0][0] )>;
    
    TIP &operator ()(int x_ind, int y_ind); 
    TIP operator ()(int x_ind, int y_ind) const; 
    
    TIP *operator [](int br);  
    TIP operator [](int br) const;  
    
    template <typename tip>
    friend std::ostream &operator <<(std::ostream &tok, const GMatrica<tip> &m);
    
    template <typename tip1, typename tip2>
    friend bool operator ==(const GMatrica<tip1> &m, const GMatrica<tip2> &mat);
    
    template <typename tip1, typename tip2>
    friend inline bool operator !=(const GMatrica<tip1> &m, const GMatrica<tip2> &mat);
    
    template <typename tip>
    friend std::istream &operator >>(std::istream &cin, GMatrica<tip> &m);
};

 template<typename tip>
 GMatrica<tip>::GMatrica(int br_redova, int br_kolona, tip elementi) : br_redova(br_redova), br_kolona(br_kolona) {
     if(br_redova < 0 || br_redova > 4 || br_kolona < 0 || br_kolona > 4) throw std::logic_error("Ilegalan format");
     for(int i = 0; i < br_redova; i++)
     for(int j = 0; j < br_kolona; j++)
     matrica[i][j] = elementi;
 }
 
 template <typename tip>
 GMatrica<tip>::GMatrica(const GMatrica<tip> &nova) : br_redova(nova.br_redova) , br_kolona(nova.br_kolona) {
      if( br_redova < 0 || br_redova > 4 || br_kolona < 0 || br_kolona > 4) throw std::logic_error("Ilegalan format matrice");
     for(int i = 0; i < br_redova; i++)
     for(int j = 0; j < br_kolona; j++)
     matrica[i][j] = nova.matrica[i][j];
 }
 
 template <typename tip>
 GMatrica<tip>::GMatrica(tip niz[4][4]) : br_redova(4), br_kolona(4) {
     for(int i = 0; i < 4; i++)
     for(int j = 0; j < 4; j++)
     matrica[i][j] = niz[i][j];
 }
 
 template <typename tip>
 GMatrica<tip>::GMatrica(std::vector<std::vector<tip>> dmat) : br_redova(dmat.size()), br_kolona(dmat[0].size()) {
      if( br_redova < 0 || br_redova > 4 || br_kolona < 0 || br_kolona > 4) throw std::logic_error("Ilegalan format matrice");
     for(int i = 0; i < br_redova; i++)
     for(int j = 0; j < br_kolona; j++)
     matrica[i][j] = dmat[i][j];
 }
 
 template <typename tipy>
 GMatrica<tipy>::GMatrica(std::initializer_list<std::initializer_list<tipy>> lista) : br_redova(lista.size()), br_kolona((*lista.begin()).size()) {
      if( br_redova < 0 || br_redova > 4 || br_kolona < 0 || br_kolona > 4) throw std::logic_error("Ilegalan format matrice");
     int k = 0, r = 0;
     for(const std::initializer_list<tipy> &v : lista) {
         k = 0;
         for(const tipy &el : v)
         matrica[r][k++] = el;
         ++r;
     }
 }


  template <typename tip>
  std::istream &operator >>(std::istream &tok, GMatrica<tip> &m) {
      std::vector<tip> brojevi;
      tip broj = {};
      int red = 0, kolona = 0;
      char unos[100];
      bool neg = false;
      tok.get(unos,100);
             int i = 0;
          while( i < 100) {
             
              if( unos[0] != '[') tok.setstate(std::ios::failbit);
              i++;
              if( unos[i] == '-' || (unos[i] >= '0' && unos[i] <= '9') ) {
                  broj = 0;
                  if(unos[i] == '-') { neg = true; i++; }
                  if(!(unos[i] >= '0' && unos[i] <= '9') ) tok.setstate(std::ios::failbit);
                  while  (unos[i] >= '0' && unos[i] <= '9') {
                      broj *= 10;
                      broj += unos[i] -'0';
                      i++;
                  } 
                  if(neg) { broj *= -1; neg = false; }
                  brojevi.push_back(broj);
              }
              if( unos[i] == ']' || unos[i] == '\0') break;
             if(unos[i] != ',' && unos[i] != ';') tok.setstate(std::ios::failbit);
              if(unos[i] == ',') kolona++;
              if(unos[i] == ';') red++;
              
          }
          
          if(tok) {
               red++;
          kolona += red;
          
          if( double(kolona)/red - kolona/red != 0) tok.setstate(std::ios::failbit);
          kolona /= red;
         
         
          if( m.br_kolona == 0 && m.br_redova == 0) {
          m.br_kolona = kolona;
          m.br_redova = red;
          }
          else if( m.br_kolona != kolona || m.br_redova != red) tok.setstate(std::ios::failbit);
          if(tok) {
          int br = 0;
          
          for(int i = 0; i < red; i++)
          for(int j = 0; j < kolona; j++) {
             m.matrica[i][j] = brojevi[br];
             br++;
          }
          }
  }
          
          return tok;
  }
  
     
  
  template <typename tip>
  tip &GMatrica<tip>::operator ()(int x_ind, int y_ind) {
      if( x_ind < 1 || x_ind > 5 || y_ind < 1 || y_ind > 5) throw std::range_error("Nedozvoljen indeks");
      return matrica[x_ind-1][y_ind-1];
  }
  
  template <typename tip>
  tip GMatrica<tip>::operator ()(int x_ind, int y_ind) const {
      if( x_ind < 1 || x_ind > 5 || y_ind < 1 || y_ind > 5) throw std::range_error("Nedozvoljen indeks");
      GMatrica<tip> nova(*this);
      return nova[x_ind-1][y_ind-1];
  }
  
  template <typename tip>
  tip *GMatrica<tip>::operator [](int br) {
      return matrica[br];
  }
  
  template <typename tip>
  tip GMatrica<tip>::operator [](int br) const {
      GMatrica<tip> nova(*this);
      return nova[br];
  }

  template <typename tip1, typename tip2>
  bool operator ==(const GMatrica<tip1> &m, const GMatrica<tip2> &mat) {
      if( m.DajBrojKolona() != mat.DajBrojKolona() || mat.DajBrojRedova() != m.DajBrojRedova()) return false;
      
      for(int i = 0; i < m.DajBrojRedova(); i++)
      for(int j = 0; j < m.DajBrojKolona(); j++)
      if(m.matrica[i][j] != mat.matrica[i][j]) return false;
      
      return true;
  }
  
  template <typename tip1, typename tip2>
  inline bool operator != (const GMatrica<tip1> &m, const GMatrica<tip2> &mat) {
      return !(m == mat);
  }

   template <typename tip1>
   GMatrica<tip1> &GMatrica<tip1>::operator +=(const GMatrica<tip1> &mat)  {
       if( mat.DajBrojRedova() != (*this).br_redova || (*this).br_kolona != mat.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija");
       for(int i = 0; i < mat.DajBrojRedova(); i++)
       for(int j = 0; j < mat.DajBrojKolona(); j++)
       (*this).matrica[i][j] += mat.matrica[i][j];
       
       return *this;
   }
   
   template <typename tip1>
    GMatrica<tip1> &GMatrica<tip1>::operator *=(const GMatrica<tip1> &m) {
        if(br_redova != m.br_kolona) throw std::domain_error("Nedozvoljena operacija");
        GMatrica<tip1> mat(*this);
        GMatrica<tip1> to(mat.br_redova,m.br_kolona);
         for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++) {
            double suma = 0;
            for(int k = 0; k < m.br_redova; k++ ) suma += (mat.matrica[i][k]*m.matrica[k][j]);
            to.matrica[i][j] = suma;
        }
        *this = to;
        
        return *this;
    }
    
   
    template <typename tip1>
    GMatrica<tip1>  &GMatrica<tip1>::operator *=(tip1 mnozac) {
        for(int i = 0; i < (*this).DajBrojRedova(); i++)
        for(int j = 0; j < (*this).DajBrojKolona(); j++)
        (*this).matrica[i][j] *= mnozac;
        
        return *this;
    }
    
    template <typename tip1>
    GMatrica<tip1> &GMatrica<tip1>::operator -=(const GMatrica<tip1> &m)  {
        if( (*this).DajBrojRedova() != m.DajBrojRedova() || m.DajBrojKolona() != (*this).DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija");
        for(int i = 0; i < (*this).DajBrojRedova(); i++)
        for(int j = 0; j < (*this).DajBrojKolona(); j++)
        (*this).matrica[i][j] -= m.matrica[i][j];
        
        return *this;
    }

  template <typename tip>
  std::ostream &operator <<(std::ostream &tok, const GMatrica<tip> &m) {
      int w = tok.width();
      if( w < 6) w = 6;
      
      for(int i = 0; i < m.DajBrojRedova(); i++) {
      for(int j = 0; j < m.DajBrojKolona(); j++)
       tok << std::setw(w) << m.matrica[i][j];
       tok << "\n";
      }
      
      return tok;
  }

  template <typename tip, typename tip1>
   auto operator +(const GMatrica<tip> &mat, const GMatrica<tip1> &m) -> GMatrica<decltype( mat.matrica[0][0] + m.matrica[0][0] )>{  //trebal bit prijateljska il s jednim parametrom?
         if(m.br_redova != mat.br_redova || m.br_kolona != mat.br_kolona) throw std::domain_error("Nedozvoljena operacija");
        GMatrica<decltype(mat.matrica[0][0] + m.matrica[0][0])> nova(m.br_redova,m.br_kolona);
        for(int i = 0; i < m.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++)
        nova.matrica[i][j] = m.matrica[i][j] + mat.matrica[i][j];
        
        return nova;
    }
    
    template <typename tip1, typename tip2>
    auto operator *(const GMatrica<tip1> &mat, const GMatrica<tip2> &m) -> GMatrica<decltype( mat.matrica[0][0] + m.matrica[0][0] )> {
        if(mat.br_redova != m.br_kolona) throw std::domain_error("Nedozvoljena operacija");
        GMatrica<decltype(mat.matrica[0][0] + m.matrica[0][0])> nova(mat.br_redova,m.br_kolona);
        for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++) {
            double suma = 0;
            for(int k = 0; k < m.br_redova; k++ ) suma += mat.matrica[i][k]*m.matrica[k][j];
            nova.matrica[i][j] = suma;
        }
        
        return nova;
    }
    
    template <typename tip1, typename tip2>
    auto operator *(const GMatrica<tip1> &m, tip2 mnozac) -> GMatrica<decltype( m.matrica[0][0] + mnozac)> {
        GMatrica<decltype(m.matrica[0][0] + mnozac)> nova(m.br_redova, m.br_kolona);
        for(int i = 0; i < m.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++)
        nova.matrica[i][j] = m.matrica[i][j]*mnozac;
        
        return nova;
        
    }
    
    template <typename tip1, typename tip2>
    auto operator *(tip1 mnozac, GMatrica<tip2> &m) -> GMatrica<decltype( m.matrica[0][0] + mnozac)> {
        GMatrica<decltype(m.matrica[0][0] + mnozac)> nova(m.br_redova, m.br_kolona);
        for(int i = 0; i < m.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++)
        nova.matrica[i][j] = m.matrica[i][j]*mnozac;
        
        return nova;
    }
    
    template <typename tip1, typename tip2>
    auto operator -(const GMatrica<tip1> &mat, const GMatrica<tip2> &m) -> GMatrica<decltype( m.matrica[0][0] + mat.matrica[0][0] )> {
        if( mat.br_redova != m.br_redova || mat.br_kolona != m.br_kolona) throw std::domain_error("Nedozvoljena operacija");
        GMatrica<decltype(m.matrica[0][0] + mat.matrica[0][0])> nova(mat.br_redova, mat.br_kolona);
        for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++)
         nova.matrica[i][j] = mat.matrica[i][j] - m.matrica[i][j];
         
         return nova;
    }



int main ()
{
    try{
   int niz[4][4] = {{1,2,3,4},{2,3,4,5},{3,4,5,6},{3,4,4,4}};
   GMatrica<int> m1({{1, 2, 7}, {3, 4, 5}});
   GMatrica<int> m12(niz);
   GMatrica<double> m;
   GMatrica<int> miii{{2,3},{1,2},{1,3}};
       GMatrica<int> m2{{1, 2, 1}, {3, 4, 5}};
      auto m3 = m1 + m2;
       std::cout << m3 << std::endl;
       GMatrica<int> m4({{1, 2, 8}, {3, 4, 8}});
       auto m5 = m2-m4;
       std::cout << m5 << std::endl;
       auto mu = miii*m4;
       std::cout << mu << std::endl;
       mu = mu *4;
       std::cout << mu << std::endl;
       mu = 4*mu;
       std::cout << mu << std::endl;
      
       m1 += m2;
       std::cout << m1 << std::endl;
       m2 -= m4;
       std::cout << m2 << std::endl;
       miii *= m4;
       std::cout << miii << std::endl;
        miii *= 4;
       std::cout << miii << std::endl;
       int br = miii(1,1);
       std::cout << br << std::endl;
       br = miii[1][1];
       std::cout << br << std::endl;
        miii[1][1] = 2;
        miii(1,1) = 0;
        std::cout << miii << std::endl;
        if(miii == m4) std::cout << "jes" << std::endl;
        else std::cout << "nije" << std::endl;
        if(miii != m4) std::cout << "jes" << std::endl;
        else std::cout << "nije" << std::endl;
    }catch(std::domain_error d) {
        std::cout << d.what() << std::endl;
    }
    catch(std::range_error r) {
        std::cout << r.what() << std::endl;
    }
   return 0;
}

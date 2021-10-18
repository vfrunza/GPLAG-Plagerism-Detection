#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector> 
#include <type_traits>

template <typename TipEl>
class GMatrica{
    int br_redova;
    int br_kolona;
    int matrica[4][4];
    public:
    GMatrica();
    GMatrica(int br_redova, int br_kolona, TipEl element);
    
    template<typename TipEl2>
    GMatrica(GMatrica<TipEl2> nova);
    
    template<typename TipEl2>
    GMatrica(TipEl2 nova[4][4]);
    
    GMatrica(std::vector<std::vector<TipEl>> vek);
    
    int DajBrojRedova()const;
    
    int DajBrojKolona()const;
    
    template<typename TipEl2, typename TipEl3>
    friend auto  operator +( GMatrica<TipEl2>m1 , GMatrica<TipEl3> m2)-> GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>;
    template<typename TipEl2, typename TipEl3>
    friend auto operator -( GMatrica<TipEl2>m1,  GMatrica<TipEl3>m2)-> GMatrica< decltype(m1.matrica[0][0]-m2.matrica[0][0])>;
   template<typename TipEl2, typename TipEl3>
    friend auto operator *( GMatrica<TipEl3>m1,  GMatrica<TipEl2>m2)-> decltype(m1.matrica[0][0]*m2.matrica[0][0]);
    template <typename TipEl2>
  friend GMatrica<TipEl2> operator *(int n, GMatrica<TipEl2> m);
  template <typename TipEl2>
  friend GMatrica<TipEl2> operator *( GMatrica<TipEl2> m, int n);
  
  template<typename TipEl2, typename TipEl3>
  friend bool operator==(GMatrica<TipEl2> m1, GMatrica<TipEl3> m2);
  
  template<typename TipEl2, typename TipEl3>
  friend bool operator!=(GMatrica<TipEl2> m1, GMatrica<TipEl3> m2);
  
  template<typename TipEl2>
  GMatrica<TipEl> &operator+=(GMatrica<TipEl2> m2);
  
  template<typename TipEl2>
  GMatrica<TipEl> &operator-=(GMatrica<TipEl2> m2);
  

  GMatrica<TipEl> &operator*=(int n);
  
  
  TipEl &operator()(int indeks1,int indeks2);
  
  TipEl *operator[](int n);
  
  template<typename TipEl2>
    friend std::ostream &operator<<(std::ostream &tok,  GMatrica<TipEl2> m);
    
};

template <typename TipEl>
GMatrica<TipEl>::GMatrica(){
    br_redova=0;
    br_kolona=0;
    matrica[br_redova][br_kolona]=0;
}

template<typename TipEl>
GMatrica<TipEl>::GMatrica(int br_redova, int br_kolona, TipEl element):br_redova(br_redova), br_kolona(br_kolona){
   if(br_redova<0 || br_redova>4 || br_kolona<0 || br_kolona>4) throw std::logic_error("Ilegalan format matrice");
   
    for(int i=0; i<br_redova; i++)
    for(int j=0; j<br_kolona; j++)
    matrica[i][j]=element;
}

template<typename TipEl> template< typename TipEl2>
GMatrica<TipEl>::GMatrica(GMatrica<TipEl2>nova){
    for(int i=0; i<nova.size(); i++)
    for(int j=0; j<nova[i].size(); j++)
    matrica[i][j]=nova[i][j];
}

template<typename TipEl> template< typename TipEl2>
GMatrica<TipEl>::GMatrica(TipEl2 nova[4][4]){
    for(int i=0; i<4; i++)
    for(int j=0; j<4; j++)
    matrica[i][j]=nova[i][j];
}

template<typename TipEl>
GMatrica<TipEl>::GMatrica(std::vector<std::vector<TipEl>> vek){
       br_redova=vek.size();
    if(vek.size()<0 || vek.size()>4)throw std::logic_error("Ilegalan format matrice");
    else {
        for(int i=0; i<vek.size(); i++){{
            br_kolona=vek[i].size();
    
        if(vek[i].size()<0 || vek[i].size()>4)throw std::logic_error("Ilegalan format matrice");
    }}}
    
    for(int i=0; i<vek.size(); i++)
    for(int j=0; j<vek[i].size(); j++)
    matrica[i][j]=vek[i][j];
}

template<typename TipEl>
 int GMatrica<TipEl>:: DajBrojRedova()const{
    return br_redova;
}

template<typename TipEl>
int GMatrica<TipEl>::DajBrojKolona()const{
    return br_kolona;
}

template<typename TipEl2,typename TipEl3>
auto operator+( GMatrica<TipEl2> m1 ,  GMatrica<TipEl3> m2)->GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>{
       GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])> ret;
       ret.br_kolona=m1.br_kolona; ret.br_redova=m1.br_redova;
    if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova) throw std::domain_error("Nedozvoljena operacija");
    for(int i=0; i<m1.br_redova; i++)
    for(int j=0; j<m1.br_kolona; j++)
    ret.matrica[i][j]=m1.matrica[i][j]+m2.matrica[i][j];
    return ret;
}

template<typename TipEl2, typename TipEl3>
auto operator-(GMatrica<TipEl2> m1,  GMatrica<TipEl3> m2)-> GMatrica<decltype(m1.matrica[0][0]-m2.matrica[0][0])>{
     GMatrica<decltype (m1.matrica[0][0]-m2.matrica[0][0])>ret;
     ret.br_kolona=m1.br_kolona; ret.br_redova=m1.br_redova;
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Nedozvoljena operacija");
    for(int i=0; i<m1.br_redova; i++)
    for(int j=0; j<m1.br_kolona; j++)
    ret.matrica[i][j]=m1.matrica[i][j]-m2.matrica[i][j];
    return ret;
}




template<typename TipEl2>
GMatrica<TipEl2> operator *(int n, GMatrica<TipEl2> m){
    GMatrica<TipEl2> ret;
    ret.br_kolona=m.br_kolona; ret.br_redova=m.br_redova;
    for(int i=0; i<m.br_redova; i++)
    for(int j=0; j<m.br_kolona; j++)
    ret.matrica[i][j]=m.matrica[i][j]*n;
    return ret;
}

template <typename TipEl2>
  GMatrica<TipEl2> operator *( GMatrica<TipEl2> m, int n){
       GMatrica<TipEl2> ret;
    ret.br_kolona=m.br_kolona; ret.br_redova=m.br_redova;
    for(int i=0; i<m.br_redova; i++)
    for(int j=0; j<m.br_kolona; j++)
    ret.matrica[i][j]=m.matrica[i][j]*n;
    return ret;
  }
  
 template<typename TipEl2, typename TipEl3>
 bool operator ==(GMatrica<TipEl2> m1, GMatrica<TipEl3> m2){
     if(m1.br_kolona != m2.br_kolona || m1.br_redova!=m2.br_redova) return false;
         for(int i=0; i<m1.br_redova; i++){
         for(int j=0; j<m1.br_kolona; j++)
         if(m1.matrica[i][j]!=m2.matrica[i][j])return false;
         }
         return true;
 }
 
 template<typename TipEl2 , typename TipEl3>
 bool operator!=(GMatrica<TipEl2> m1, GMatrica<TipEl3>m2){
     if(m1.br_kolona!=m2.br_kolona || m1.br_redova!= m2.br_redova) return true;
     for(int i=0; i<m1.br_redova; i++)
     for(int j=0; j<m1.br_kolona; j++)
     if(m1.matrica[i][j]!=m2.matrica[i][j])return true;
     return false;
     
 }


template<typename TipEl> template< typename TipEl2>
GMatrica<TipEl>&GMatrica<TipEl>::operator +=(GMatrica<TipEl2> m2){
    if(br_kolona!=m2.br_kolona || br_redova!=m2.br_redova) throw std::domain_error("Nedozvoljena operacija");
    for(int i=0; i<m2.br_redova; i++)
    for(int j=0; j<m2.br_kolona; j++)
    matrica[i][j]+=m2.matrica[i][j];
    return *this;
}

template<typename TipEl> template<typename TipEl2>
GMatrica<TipEl>&GMatrica<TipEl>::operator -=(GMatrica<TipEl2>m2){
    if(br_kolona!=m2.br_kolona || br_redova!=m2.br_redova)throw std::domain_error("Nedozvoljena operacija");
    for(int i=0; i<m2.br_redova; i++)
    for(int j=0; j<m2.br_kolona; j++)
    matrica[i][j]-=m2.matrica[i][j];
    return *this;
}

template<typename TipEl> 
GMatrica<TipEl>&GMatrica<TipEl>::operator *=(int n){
    for(int i=0; i<br_redova; i++)
    for(int j=0; j<br_kolona; j++)
    matrica[i][j]*=n;
    return *this;
}


template<typename TipEl>
TipEl &GMatrica<TipEl>::operator()(int indeks1, int indeks2){
    if (indeks1<1 || indeks2<1 || indeks1>4 || indeks2>4) throw std::range_error("Nedozvoljen indeks");
    return matrica[indeks1-1][indeks2-1];
}

template<typename TipEl>
TipEl *GMatrica<TipEl>::operator[](int n){
    return (matrica[n]);
}




template<typename TipEl2>
std::ostream &operator<<(std::ostream &tok,  GMatrica<TipEl2> m){
    for(int i=0; i<m.br_redova; i++){
    for(int j=0; j<m.br_kolona; j++)
    tok<<std::setw(6)<<m.matrica[i][j];
    tok<<std::endl;
    }
    return tok;
}



int main ()
{
   
    GMatrica<int> m1({{1, 2}, {3, 4}});
   GMatrica<int> m2({{1, 2}, {3, 4}});
   std::cout <<  m1 << std::endl;
   m1 += m2;
   std::cout <<  m1 << std::endl;
   m1 -= m2;
   std::cout <<  m1 << std::endl;
   m1 *= 2;
   std::cout <<  m1 << std::endl;
	return 0;
}
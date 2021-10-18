/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include<vector>
#include<stdexcept>
#include<initializer_list>
#include<iomanip>
#include<utility>
template<typename tip>
class GMatrica{
    
    int broj_redova;
    int broj_kolona;
    tip mat[4][4];
    
    
    public:
    
    GMatrica():broj_redova(0),broj_kolona(0){};
    GMatrica(int broj_redova,int broj_kolona,tip t=tip());
    
    template<typename tip2>
    GMatrica(GMatrica<tip2> mat2);
    
    GMatrica(tip m[4][4]);
    GMatrica(std::vector<std::vector<tip>> v);
    GMatrica(std::initializer_list<std::initializer_list<tip>> lista);
    int DajBrojRedova() const{return broj_redova;};
    int DajBrojKolona() const {return broj_kolona;}
    
   template<typename tip1,typename tip2>
    friend auto operator +(const GMatrica<tip1> &mat1,const GMatrica<tip2> &mat2)->GMatrica<decltype(mat1.mat[0][0]+mat2.mat[0][0])>;
    
    template<typename tip1,typename tip2>
    friend auto operator -(const GMatrica<tip1> &mat1,const GMatrica<tip2> &mat2)->GMatrica<decltype(mat1.mat[0][0]-mat2.mat[0][0])>;
    
    template<typename tip1,typename tip2>
  friend auto operator *(const GMatrica<tip1> &mat1,const GMatrica<tip2> &mat2)->GMatrica<decltype(mat1.mat[0][0]*mat2.mat[0][0])>;
  
  
  template<typename tip1>
  GMatrica &operator +=(const GMatrica<tip1> &m);
  template<typename tip1>
  GMatrica &operator -=(const GMatrica<tip1> &m);
  template<typename tip1>
  GMatrica &operator *=(const GMatrica<tip1> &m);
  template<typename tip1>
  GMatrica &operator *=(tip1 t);
  
 
   template<typename tip1,typename tip2>
   friend auto operator *(tip1 t,const GMatrica<tip2> &m)->GMatrica<decltype(t*m.mat[0][0])>;
    
    template<typename tip1,typename tip2>
 friend auto operator *(const GMatrica<tip1> &m,tip2 t)->GMatrica<decltype(t*m.mat[0][0])>;
 
  template<typename tip1,typename tip2>
  friend bool operator ==(const GMatrica<tip1> &mat1,const GMatrica<tip2> &mat2);
  
  template<typename tip1,typename tip2>
  friend bool operator !=(const GMatrica<tip1> &mat1,const GMatrica<tip2> &mat2);
 

 auto operator [](int indeks)->decltype(mat[indeks]);

 
  
  tip operator ()(int x,int y);

 
    
    template<typename tip1>
    friend std::ostream &operator<<(std::ostream &tok,const GMatrica<tip1> &m);
    template<typename tip1>
    friend std::istream &operator>>(std::istream &tok,GMatrica<tip1> &m);
    
    
    
};

template<typename tip>
tip GMatrica<tip>:: operator ()(int x, int y){
    if(x<1 || x>4 || y<1 || y>4) throw std::range_error("Nedozvoljen indeks");
    return mat[x-1][y-1];
}

template<typename tip>


 auto GMatrica<tip>::operator [](int indeks)->decltype(mat[indeks]) {
     return mat[indeks];
 }
 

template<typename tip>
GMatrica<tip>::GMatrica(int broj_redova,int broj_kolona,tip t ){
    
    if(broj_redova<0 || broj_redova>4 || broj_kolona<0 || broj_kolona>4) throw std::logic_error("Ilegalan format matrice");
    
    GMatrica::broj_redova=broj_redova; GMatrica::broj_kolona=broj_kolona;
    
    for(int i=0;i<broj_redova;i++){
        for(int j=0;j<broj_redova;j++){
            mat[i][j]=t;
        }
    }
}
template<typename tip>
template<typename tip2>
GMatrica<tip>::GMatrica(GMatrica<tip2> mat2){
    
    broj_redova=mat2.broj_redova;
    broj_kolona=mat2.broj_kolona;
    for(int i=0;i<broj_redova;i++){
        for(int j=0;j<broj_kolona;j++){
            mat[i][j]=mat2[i][j];
        }
    }
    
}
template<typename tip>
GMatrica<tip>::GMatrica(tip m[4][4]):broj_redova(4),broj_kolona(4){
    for(int i=0;i<broj_redova;i++){
        for(int j=0;j<broj_kolona;j++){
            mat[i][j]=m[i][j];
        }
    }
}

template<typename tip>
GMatrica<tip>::GMatrica(std::vector<std::vector<tip>> v){
    int red(v.size());
    
    if(red>4) throw std::logic_error("Ilegalan format matrice");
    int kolona;
    if(red==0) kolona=0;
    else kolona=v[0].size();
    for(int i=0;i<red;i++){
        if(v[i].size()!=kolona) throw std::logic_error("Ilegalan format matrice");
    }
    broj_redova=red; broj_kolona=kolona;
    for(int i=0;i<broj_redova;i++){
        for(int j=0;j<broj_kolona;j++){
            mat[i][j]=v[i][j];
        }
    }
  
}
template<typename tip>
GMatrica<tip>::GMatrica(std::initializer_list<std::initializer_list<tip>> lista){
    auto red(lista.size());
    if(red>4) throw std::logic_error("Ilegalan format matrice");
    auto kolona(lista.begin()->size());
   for(auto it=lista.begin();it!=lista.end();it++){
        
            if(it->size()!=kolona)  throw std::logic_error("Ilegalan format matrice");
    
    }
    
    broj_redova=red; broj_kolona=kolona;
   
    int i(0);
    for(auto it=lista.begin();it!=lista.end();it++){
        int j(0);
        for(auto it2=it->begin();it2!=it->end();it2++){
            mat[i][j]=*it2;
            
            j++;
        }
        i++;
    }
    
   
    
}

template<typename tip1,typename tip2>

auto operator +(const  GMatrica<tip1> &mat1, const GMatrica<tip2> &mat2)->GMatrica<decltype(mat1.mat[0][0]+mat2.mat[0][0])>
{
    
   if(mat1.broj_redova!=mat2.broj_redova || mat1.broj_kolona!=mat2.broj_kolona) throw std::domain_error("Nedozvoljena operacija");
    
    GMatrica<decltype(mat1.mat[0][0]+mat2.mat[0][0])> gmat(mat1.broj_redova,mat1.broj_kolona,0);
    
   
    for(int i=0;i<mat1.broj_redova;i++){
        for(int j=0;j<mat1.broj_kolona;j++){
            
       
         gmat.mat[i][j]=mat1.mat[i][j]+mat2.mat[i][j];
        }
    }
    
    return gmat;
}

template<typename tip>
template<typename tip1>
GMatrica<tip> &GMatrica<tip>::operator +=(const GMatrica<tip1> &m){
     
   if(broj_redova!=m.broj_redova || broj_kolona!=m.broj_kolona) throw std::domain_error("Nedozvoljena operacija");
 
    for(int i=0;i<m.broj_redova;i++){
        for(int j=0;j<m.broj_kolona;j++){
     
         mat[i][j]=mat[i][j]+m.mat[i][j];
        }
    }
    
    return *this;
}
template<typename tip>
template<typename tip1>
GMatrica<tip> &GMatrica<tip>::operator -=(const GMatrica<tip1> &m){
     
   if(broj_redova!=m.broj_redova || broj_kolona!=m.broj_kolona) throw std::domain_error("Nedozvoljena operacija");
  
    for(int i=0;i<m.broj_redova;i++){
        for(int j=0;j<m.broj_kolona;j++){
     
         mat[i][j]=mat[i][j]-m.mat[i][j];
        }
    }
    
    return *this;
}
template<typename tip>
 template<typename tip1>
   GMatrica<tip> &GMatrica<tip>::operator *=(const GMatrica<tip1> &m){
        if(broj_kolona!=m.broj_redova) throw std::domain_error("Nedozvoljena operacija");
          
          for(int i=0;i<broj_redova;i++){
              for(int j=0;j<m.broj_kolona;j++){
                  tip1 pomocna(0);
                  for(int k=0;k<broj_kolona;k++){
                      pomocna+=mat[i][k]*m.mat[k][j];
                  }
                  mat[i][j]=pomocna;
                
              }
          }
          return *this;
        
        
    }
    template<typename tip>
    template<typename tip1>
 GMatrica<tip> &GMatrica<tip>::operator *=(tip1 t){
    
       
        for(int i=0;i<broj_redova;i++){
            for(int j=0;j<broj_kolona;j++){
               mat[i][j]=t*mat[i][j];
            }
        }
        return *this;
    }
template<typename tip1,typename tip2>
auto operator -(const  GMatrica<tip1> &mat1, const GMatrica<tip2> &mat2)->GMatrica<decltype(mat1.mat[0][0]-mat2.mat[0][0])>
{
    
   if(mat1.broj_redova!=mat2.broj_redova || mat1.broj_kolona!=mat2.broj_kolona) throw std::domain_error("Nedozvoljena operacija");
    
    GMatrica<decltype(mat1.mat[0][0]-mat2.mat[0][0])> gmat(mat1.broj_redova,mat1.broj_kolona,0);
    for(int i=0;i<mat1.broj_redova;i++){
        for(int j=0;j<mat1.broj_kolona;j++){
            gmat.mat[i][j]=mat1.mat[i][j]-mat2.mat[i][j];
        }
    }
    
    return gmat;
}

 template<typename tip1,typename tip2>
 auto operator *(tip1 t,const GMatrica<tip2> &m)->GMatrica<decltype(t*m.mat[0][0])>{
    
     
        GMatrica<decltype(t*m.mat[0][0])> gmat(m.broj_redova,m.broj_kolona,1);
        for(int i=0;i<m.broj_redova;i++){
            for(int j=0;j<m.broj_kolona;j++){
                gmat.mat[i][j]=t*m.mat[i][j];
            }
        }
        return gmat;
    }
    
template<typename tip1, typename tip2>
    auto operator *(const GMatrica<tip1> &m,tip2 t)->GMatrica<decltype(t*m.mat[0][0])>{
        return t*m;
    }
  
     template<typename tip1,typename tip2>
   auto operator *(const GMatrica<tip1> &mat1,const GMatrica<tip2> &mat2)->GMatrica<decltype(mat1.mat[0][0]*mat2.mat[0][0])>{
        if(mat1.broj_kolona!=mat2.broj_redova) throw std::domain_error("Nedozvoljena operacija");
          GMatrica<decltype(mat1.mat[0][0]*mat2.mat[0][0])> gmat(mat1.broj_redova,mat2.broj_kolona,1);
          for(int i=0;i<mat1.broj_redova;i++){
              for(int j=0;j<mat2.broj_kolona;j++){
                  tip1 pomocna(0);
                  for(int k=0;k<mat1.broj_kolona;k++){
                      pomocna+=mat1.mat[i][k]*mat2.mat[k][j];
                  }
                  gmat.mat[i][j]=pomocna;
                  
                  
                  
              }
          }
          return gmat;
        
        
    }

template <typename tip1>
std::ostream &operator<<(std::ostream &tok,const GMatrica<tip1> &m){
    
    for(int i=0;i<m.broj_redova;i++){
        for(int j=0;j<m.broj_kolona;j++){
            tok<<std::setw(6)<<m.mat[i][j];
        }
        tok<<std::endl;
    }
    return tok;
}
template<typename tip1>
    std::istream &operator>>(std::istream &tok,GMatrica<tip1> &m){
        
        
        char znak;
        tok>>std::ws;
        if(tok.peek()!='[') tok.setstate(std::ios::failbit);
        tok>>znak;
        int i(0);
        bool prvi(true);
        int provjera(0);
        int j(0);
       
        p:
     
        tok>>m.mat[i][j];
        j++;
       
        
        if(tok.peek()==',') {
            tok>>znak;
            goto p;
        }
        if(tok.peek()==';'&& prvi) {
            tok>>znak;
            prvi=false;
            provjera=j;
            if(j>3) tok.setstate(std::ios::failbit);
            
           
            
            i++; j=0; goto p;
        }
        if(tok.peek()==';' && !prvi){
            tok>>znak;
            if(provjera!=j || j>3) tok.setstate(std::ios::failbit);
         
            i++; j=0;goto p;
        }
    if(tok.peek()==']'){
        if(provjera!=j || j>3) tok.setstate(std::ios::failbit);
        tok>>znak;
        if(tok.peek()!='\n' || tok.peek()!='\r' || tok.peek()!='\f' || tok.peek()!='\v' || tok.peek()!='\t' || tok.peek()!=' ') tok.setstate(std::ios::failbit);
        
       i++;
        }
        
       m.broj_redova=i;
        m.broj_kolona=provjera;
    
    return tok;
  }
    

template<typename tip1,typename tip2>
bool operator ==(const GMatrica<tip1> &mat1,const GMatrica<tip2> &mat2){
    
    if(mat1.broj_redova!=mat2.broj_redova || mat1.broj_kolona!=mat2.broj_kolona) return false;
    for(int i=0;i<mat1.broj_redova;i++){
        for(int j=0;j<mat1.broj_kolona;j++){
            if(mat1.mat[i][j]!=mat2.mat[i][j]) return false;
        }
    }
    
    return true;
}
template <typename tip1,typename tip2>
bool operator !=(const GMatrica<tip1> &mat1,const GMatrica<tip2> &mat2){
    return !(mat1==mat2);
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
	return 0;
}
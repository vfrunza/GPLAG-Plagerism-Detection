/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <cstring>


 //template<typename Tip>

 class GMatrica{
   template<typename Tip>
     Tip niz[4][4];
     int br_redova;
     int br_kolona;
     
     public:
    
     GMatrica(){
         br_kolona=0;
         br_redova=0;
     }
     template<typename Tip>
     GMatrica(int br_redova,int br_kolona,Tip vrijednost);
     template<typename Tip>
     GMatrica(Tip novi[4][4]);
     template<typename Tip>
     GMatrica(std::vector<std::vector<Tip>>v);
     template<typename Tip>
     GMatrica(std::initializer_list<Tip>lista);
     
     int DajBrojRedova()const{return br_redova;}
     int DajBrojKolona()const{return br_kolona;}
     
     template<typename Tip>
    friend GMatrica<Tip>operator+(const GMatrica<Tip> &a,const GMatrica<Tip> &b);
     template<typename Tip>
   friend  GMatrica<Tip>operator-(const GMatrica<Tip>&a,const GMatrica<Tip>&b);
     template<typename Tip,typename Tip2>
    friend GMatrica<Tip>operator*(const GMatrica<Tip>&a,Tip2 n);
     template<typename Tip,typename Tip2>
     inline GMatrica<Tip>operator *(Tip2 n,const GMatrica<Tip>&a){
      return a*n;
     }
     template<typename Tip>
    friend GMatrica<Tip>&operator +=(const GMatrica<Tip>&a);
    
     template<typename Tip>
    friend GMatrica<Tip>operator -=(const GMatrica<Tip>&a);
     template<typename Tip>
    friend bool &operator==(const GMatrica<Tip>&a,const GMatrica<Tip>&b);
     
     template<typename Tip>
     inline GMatrica<Tip>&operator !=(const GMatrica<Tip>&a,const GMatrica<Tip>&b){
      return !(a==b);
     }
     template<typename Tip>
     Tip &operator()(int i,int j){
      if(i<0 || j<0 || i>br_redova || j>br_kolona) throw std::range_error("Nedozvoljen indeks");
      return niz[i-1][j-1];
     }
     template<typename Tip>
     Tip operator ()(int i,int j)const{
       if(i<0 || j<0 || i>br_redova || j>br_kolona) throw std::range_error("Nedozvoljen indeks");
       return niz[i-1][j-1];
     }
    template<typename Tip>
   friend std::ostream &operator<<(std::ostream &tok,const GMatrica<Tip>a);
    
    template<typename Tip>
   friend std::istream &operator >>(std::istream &tok,const GMatrica<Tip>&a);
    
 };
 
  template<typename Tip>
    GMatrica<Tip>:: GMatrica(int br_redova,int br_kolona,Tip vrijednost){
         if(br_redova<0 || br_redova>4 || br_kolona<0 || br_kolona>4) throw std::logic_error("Ilegalan format matrice");
         for(int i=0;i<br_redova;i++){
             for(int j=0;j<br_kolona;j++){
                 niz[i][j]=vrijednost;
             }
         }
     }
 
 template<typename Tip>
    GMatrica<Tip>:: GMatrica(Tip novi[4][4]){
         for(int i=0;i<4;i++){
             for(int j=0;j<4;j++){
                 niz[i][j]=novi[i][j];
             }
         }
     }
  template<typename Tip>
    GMatrica<Tip>:: GMatrica(std::vector<std::vector<Tip>>v){
         int br_ele_prvog_reda=v[0].size();
         if(br_ele_prvog_reda<0 || br_ele_prvog_reda>4) throw std::logic_error("Ilegalan format matrice");
         for(int i=0;i<v.size();i++){
             if(v[i]size()!=br_ele_prvog_reda) throw std::logic_error("Ilegalan format matrice");
         }
         for(int i=0;i<v.size();i++){
             for(int j=0;j<v[i].size();j++){
                 niz[i][j]=v[i][j];
             }
         }
     }
      template<typename Tip>
    GMatrica<Tip>:: GMatrica(std::initializer_list<Tip>lista){
         if(lista.size()<0 || lista.size()>4) throw std::logic_error("Ilegalan format matrice");
         int i=0,j=0;
         auto x=lista.begin();
         while(x!=lista.end()){
             niz[i][j]=x;
             i++;j++;x++;
         }
     }
     
      template<typename Tip>
     GMatrica<Tip> operator+(const GMatrica<Tip> &a,const GMatrica<Tip> &b){
      if(a.br_redova!=b.br_redova || a.br_kolona!=b.br_kolona) throw std::domain_error("Nedozvoljena operacija");
      GMatrica<Tip>c(m1.br_redova,m2.br_kolona);
      for(int i=0;i<m1.br_redova;i++){
       for(int j=0;j<m1.br_kolona;j++){
        c.niz[i][j]=a.niz[i][j]+b.niz[i][j];
       }
      }
      return c;
     }
     
      template<typename Tip>
     GMatrica<Tip>operator-(const GMatrica<Tip>&a,const GMatrica<Tip>&b){
      if(a.br_redova!=b.br_redova || a.br_kolona!=b.br_kolona) throw std::domain_error("Nedozvoljena operacija");
      GMatrica<Tip>c(m1.br_redova,m2.br_kolona);
      for(int i=0;i<m1.br_redova;i++){
       for(int j=0;j<m2.br_kolona;j++){
        c.niz[i][j]=a.niz[i][j]-b.niz[i][j];
       }
      }
      return c;
     }
     
      template<typename Tip,typename Tip2>
     GMatrica<Tip>operator*(const GMatrica<Tip>&a,Tip2 n){
      GMatrica<Tip>c(a);
      for(int i=0;i<c.br_redova;i++)
      for(int j=0;j<c.br_kolona;j++)
      c.niz[i][j]*=n;
      return c;
     }
     
      template<typename Tip>
     GMatrica<Tip>&operator +=(const GMatrica<Tip>&a){
      if(br_redova!=a.br_redova || br_kolona!=a.br_kolona) throw std::domain_error("Nedozvoljena operacija");
      for(int i=0;i<br_redova;i++){
       for(int j=0;j<br_kolona;j++){
        niz[i][j]+=a.niz[i][j];       
        
       }
      }
      return *this;
     }
     
      template<typename Tip>
     GMatrica<Tip>operator -=(const GMatrica<Tip>&a){
      if(br_redova!=a.br_redova || br_kolona!=a.br_kolona) throw std::domain_error("Nedozvoljena operacija");
      for(int i=0,i<br_redova;i++){
       for(int j=0;j<br_kolona;j++){
        niz[i][j]-=a.niz[i][j];
       }
      }
      return *this;
     }
     
      template<typename Tip>
    std:: bool &operator==(const GMatrica<Tip>&a,const GMatrica<Tip>&b){
      if(a.size()!=b.size()) return false;
      for(int i=0;i<a.br_redova;i++){
       for(int j=0;j<a.br_kolona;j++){
        if(a.niz[i][j]!=b.niz[i][j])
        return false;
       }
      }
      return true;
     }
     
      template<typename Tip>
   std:: ostream &operator<<(std::ostream &tok,const GMatrica<Tip>a){
     int x=tok.width();
     for(int i=0;<a.br_redova;i++){
      for(int j=0;j<a.br_kolona;j++){
       tok<<setw(x)<<a.niz[i][j];
      }
      tok<<endl;
     }
     return tok;
    }
    
     template<typename Tip>
    std::istream &operator >>(std::istream &tok,const GMatrica<Tip>&a){
     for(int i=0;i<a.br_redova,i++){
      for(int j=0;j<b.br_kolona;j++){
       
       tok>>a.niz[i][j];
       
       
      }
     }
     return tok;
    }
 
 int main(){
  return 0;
  
 }
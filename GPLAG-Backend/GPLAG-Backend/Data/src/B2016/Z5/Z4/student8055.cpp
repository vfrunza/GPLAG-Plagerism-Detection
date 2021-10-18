/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>
template<typename Tip>
class GMatrica{
    Tip matrica[4][4];
    int brredova;
    int brkolona;
    public:
    GMatrica();
    GMatrica(int x, int y, Tip el=Tip());
    template<typename DrugiTip>
    GMatrica(GMatrica<DrugiTip> mat);
    template<typename DrugiTip>
    GMatrica(DrugiTip** niz);
    GMatrica(std::vector<std::vector<Tip>> vek);
    GMatrica(std::initializer_list<std::initializer_list<Tip>> l);
    int DajBrojRedova() const{
        return brredova;
    }
    int DajBrojKolona() const{
        return brkolona;
    }
    template<typename Tip1, typename Tip2>
    friend auto operator +(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<decltype(Tip1()+Tip2())>;
    template<typename Tip1, typename Tip2>
    friend auto operator -(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<decltype(Tip1()-Tip2())>;
    template<typename Tip1, typename Tip2>
    friend auto operator *(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<decltype(Tip1()*Tip2())>;
    template<typename Tip1, typename Tip2>
    friend auto operator *(const GMatrica<Tip1> &m, const Tip2 a) -> GMatrica<decltype(a*Tip1())>;
    
    
    
};
    template<typename Tip>
    GMatrica<Tip>::GMatrica(){
        brredova=0;
        brkolona=0;
    }
    template<typename Tip>
    GMatrica<Tip>::GMatrica(int x, int y, Tip el){
        if(x<0 || x>4 || y<0 || y>4) throw std::logic_error("Ilegalan format matrice");
        for(int i(0); i<x; i++){
            for(int j(0); j<y; j++){
                matrica[i][j]=el;
            }
        }
        
    }
    template<typename Tip>
    template<typename DrugiTip>
    GMatrica<Tip>:: GMatrica(GMatrica<DrugiTip> mat){
        for(int i(0); i<mat.brredova; i++){
            for(int j(0); j<mat.brkolona; j++){
                matrica[i][j]=mat.matrica[i][j];
            }
        }
        brredova=mat.brredova;
        brkolona=mat.brkolona;
        
    }
    template<typename Tip>
    template<typename DrugiTip>
     GMatrica<Tip>::GMatrica(DrugiTip** niz){
          for(int i(0); i<4; i++){
              for(int j(0); j<4; j++){
                  matrica[i][j]=niz[i][j];
              }
          }
          brredova=4;
          brkolona=4;
      }
    template<typename Tip>
      GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip>> vek){
          if(vek.size()<0 || vek.size>4 || vek[0].size()<0 || vek[0].size()>4) throw std::logic_error("Ilegalan format matrice");
          for(int i(1); i<vek.size(); i++){
              if(vek[i].size()!=vek[0].size())  throw std::logic_error("Ilegalan format matrice");
          }
          for(int i(0); i<vek.size(); i++ ){
              for(int j(0); j<vek[i].size(); j++){
                  matrica[i][j]=vek[i][j];
              }
          }
          brredova=vek.size();
          brkolona=vek[0].size();
      }
    template<typename Tip>
      GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Tip>> l){
          if(l.size()<0 || l.size>4) throw std::logic_error("Ilegalan format matrice");
          if((*l.begin()).size()<0 || (*l.begin()).size()>4) throw std::logic_error("Ilegalan format matrice");
          for(auto it=l.begin(); it!=l.end(); it++){
              if((*it).size()!=(*l.begin()).size())  throw std::logic_error("Ilegalan format matrice");
          }
          int redovi(0);
          int kolone(0);
          for(auto it=l.begin(); it!=l.end(); it++){
              for( auto it1=(*it).begin(); it1!=(*it).end(); it1++){
                  matrica[redovi++][kolone++]=*it1;
              }
      }
      
      }
        
    template<typename Tip1, typename Tip2>
      auto operator +(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<decltype(Tip1()+Tip2())>{
          if(m1.brredova!=m2.brredova || m1.brkolona!=m2.brkolona) throw std::domain_error("Nedozvoljena operacija");
          GMatrica<decltype(Tip1()+Tip2())> rezultat;
          for(int i(0); i<m1.brredova; i++){
              for(int j(0); j<m1.brkolona; j++){
                  rezultat.matrica[i][j]=m1.matrica[i][j]+m2.matrica[i][j];
              }
          }
          rezultat.brredova=m1.brredova;
          rezultat.brkolona=m1.brkolona;
          return rezultat;
          
      }
    template<typename Tip1, typename Tip2>
      auto operator -(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<decltype(Tip1()-Tip2())>{
          if(m1.brredova!=m2.brredova || m1.brkolona!=m2.brkolona) throw std::domain_error("Nedozvoljena operacija");
          GMatrica<decltype(Tip1()-Tip2())> rezultat;
          for(int i(0); i<m1.brredova; i++){
              for(int j(0); j<m1.brkolona; j++){
                  rezultat.matrica[i][j]=m1.matrica[i][j]-m2.matrica[i][j];
              }
          }
          rezultat.brredova=m1.brredova;
          rezultat.brkolona=m1.brkolona;
          return rezultat;
          
      }
    template<typename Tip1, typename Tip2>
    auto operator *(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<decltype(Tip1()*Tip2())>{
        if(m1.brkolona!=m2.brredova) throw std::domain_error("Nedozvoljena operacija");
          GMatrica<decltype(Tip1()*Tip2())> rezultat(m1.brredova, m2.brkolona);
          for(int i(0); i<m1.brredova; i++){
              for(int j(0); j<m2.brkolona; j++){
                  decltype(Tip1()*Tip2()) suma(0);
                  for(int k(0); k<m1.brkolona; k++){
                      suma+=m1.matrica[i][j]*m2.matrica[j][i];
                  }
                  
                  rezultat.matrica[i][j]=suma;
              }
          }
          
          return rezultat;
        
    }
    template<typename Tip1, typename Tip2>
    auto operator *(const GMatrica<Tip1> &m, const Tip2 a) -> GMatrica<decltype(a*Tip1())>{
         GMatrica<decltype(a*Tip1())> rezultat(m.brredova, m.brkolona);
          for(int i(0); i<m.brredova; i++){
              for(int j(0); j<m.brkolona; j++){
              
                      rezultat=a*m.matrica[i][j];
                  }
          }
          
          return rezultat;
        
    }
        
    
    
      

int main ()
{
	return 0;
}
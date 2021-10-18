/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <iomanip>
#include <algorithm>
template <typename NekiTip>
class GMatrica{
 NekiTip matrica[4][4];
 int red, kolona;
  public:
  GMatrica(){red=0; kolona=0;}
  GMatrica(int m, int n, NekiTip p);
  template<typename NekiTip1>
  GMatrica(GMatrica<NekiTip1> &m);
  template <typename NekiTip1>
  GMatrica(NekiTip1 niz[][4]);
  GMatrica(std::vector<std::vector<NekiTip>>v);
  GMatrica(std::initializer_list<std::initializer_list<NekiTip>> m);
  int DajBrojRedova() const{return red;}
  int DajBrojKolona() const{return kolona;}
  template<typename NekiTip1, typename NekiTip2>
  friend auto operator +(const GMatrica<NekiTip1> &m1, const GMatrica<NekiTip2> &m2)->GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>const;
  template<typename NekiTip1, typename NekiTip2>
  friend auto operator -(const GMatrica<NekiTip1> &m1, const GMatrica<NekiTip2> &m2)->GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>const;
  template<typename NekiTip1, typename NekiTip2>
  friend auto operator *(const GMatrica<NekiTip1> &m1, const GMatrica<NekiTip2> &m2)->GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>const;
  GMatrica<NekiTip> &operator +=(const GMatrica<NekiTip> &m1);
  GMatrica<NekiTip> &operator -=(const GMatrica<NekiTip> &m1);
  GMatrica<NekiTip> &operator *=(const GMatrica<NekiTip> &m1);
  template<typename NekiTip1, typename NekiTip2>
  friend GMatrica<NekiTip1> operator *(NekiTip2 k, const GMatrica<NekiTip1> &m);
  template<typename NekiTip1, typename NekiTip2>
  friend GMatrica<NekiTip1> operator *(const GMatrica<NekiTip1> &m, NekiTip2 k);
  template <typename NekiTip1>
  friend std::ostream &operator <<(std::ostream &tok, const GMatrica<NekiTip1> &m);
};
template <typename NekiTip>
GMatrica<NekiTip>::GMatrica(int m, int n, NekiTip p){
    if(m<0 || m>4 || n<0 || n>4) throw std::logic_error("Ilegalan format matrice");
    red=m;
    kolona=n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            matrica[i][j]=p;
        }
    }
}
template <typename NekiTip>
template <typename NekiTip1>
GMatrica<NekiTip>::GMatrica(NekiTip1 niz[][4]){
    red=4;
    kolona=4;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            matrica[i][j]=niz[i][j];
        }
    }
}
template <typename NekiTip>
GMatrica<NekiTip>::GMatrica(std::vector<std::vector<NekiTip>>v){
    if(v.size()<0 || v.size()>4) throw std::logic_error("Ilegalan format matrice");
    red=v.size();
    kolona=v[0].size();
    for(int i=0; i<v.size(); i++){
        if(v[0].size()!=v[i].size() || v[i].size()<0 || v[i].size()>4) throw std::logic_error("Ilegalan format matrice");
        for(int j=0; j<v[i].size(); j++){
            matrica[i][j]=v[i][j];
        }
    }
}
template <typename NekiTip>
GMatrica<NekiTip>::GMatrica(std::initializer_list<std::initializer_list<NekiTip>> m){
    if(m.size()<0 || m.size()>4) throw std::logic_error("Ilegalan format matrice");
    typename std::initializer_list<std::initializer_list<NekiTip>>::iterator it1{m.begin()}, it2{m.begin()};
    for(it2=m.begin(); it2!=m.end(); it2++){
        if(it1->size()!=it2->size()) throw std::logic_error("Ilegalan format matrice");
    }
    red=m.size();
    it2=m.begin();
    for(int i=0; i<m.size(); i++){kolona=it2->size(); it2++;}
    for(int i=0; i<m.size(); i++){
        auto it3=it1->begin();
        for(int j=0; j<kolona; j++){
            matrica[i][j]=*it3;
            it3++;
        }
        it1++;
    }
}
template <typename NekiTip>
template <typename NekiTip1>
GMatrica <NekiTip>::GMatrica(GMatrica <NekiTip1> &m){
    NekiTip1 mat[4][4];
   int red1{m.DajBrojRedova()}, kolona1{m.DajBrojKolona()};
   red=red1; kolona=kolona1;
    for(int i=0; i<red; i++){
        for(int j=0; j<kolona; j++){
           matrica[i][j]=mat[i][j];
        }
    }
}
template <typename NekiTip1, typename NekiTip2>
auto operator +(const GMatrica<NekiTip1> &m1, const GMatrica<NekiTip2> &m2)->GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])> const{
    int j{0};
    if(m1.red!=m2.red || m1.kolona!=m2.kolona) throw std::domain_error("Nedozvoljena operacija");
    int red{m1.DajBrojRedova()}, kolona{m1.DajBrojKolona()};
    decltype(m1.matrica[0][0]+m2.matrica[0][0]) mat[4][4]{};
    for(int i=0; i<red; i++){
        for(j=0; j<kolona; j++){
            mat[i][j]=m1.matrica[i][j]+m2.matrica[i][j];
        }
    }
    return mat;
}
template<typename NekiTip1, typename NekiTip2>
auto operator -(const GMatrica<NekiTip1> &m1, const GMatrica<NekiTip2> &m2)->GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])> const{
    int j{0};
    if(m1.red!=m2.red || m1.kolona!=m2.kolona) throw std::domain_error("Nedozvoljena operacija");
    int red{m1.DajBrojRedova()}, kolona{m1.DajBrojKolona()};
    decltype(m1.matrica[0][0]+m2.matrica[0][0]) mat[4][4]{};
    for(int i=0; i<red; i++){
        for(j=0; j<kolona; j++){
            mat[i][j]=m1.matrica[i][j]-m2.matrica[i][j];
        }
    }
    return mat;
}
template<typename NekiTip1, typename NekiTip2>
auto operator *(const GMatrica<NekiTip1> &m1, const GMatrica<NekiTip2> &m2)->GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])> const{
    int j{0};
    if(m1.kolona!=m2.red) throw std::domain_error("Nedozvoljena operacija");
    int red{m1.DajBrojRedova()}, kolona{m1.DajBrojKolona()}, red1{m2.DajBrojRedova()};
    decltype(m1.matrica[0][0]+m2.matrica[0][0]) mat[4][4]{};
    for(int i=0; i<red; i++){
        for(j=0; j<kolona; j++){
            double suma{0};
            for(int k=0; k<red1; k++){
                suma=suma+m1.matrica[i][k]*m2.matrica[k][j];
            }
                mat[i][j]=suma;
        }
    }
    return mat;
}
template<typename NekiTip1, typename NekiTip2>
GMatrica<NekiTip1> operator *(NekiTip2 k, const GMatrica<NekiTip1> &m){
    decltype(m.matrica[0][0]*k) mat[4][4]{};
    int red{m.DajBrojRedova()}, kolona{m.DajBrojKolona()};
    for(int i=0; i<red; i++){
        for(int j=0; j<kolona; j++){
            mat[i][j]=k*m.matrica[i][j];
        }
    }
  return mat;
}
template<typename NekiTip1, typename NekiTip2>
GMatrica<NekiTip1> operator *(const GMatrica<NekiTip1> &m, NekiTip2 k){
    decltype(m.matrica[0][0]*k) mat[4][4]{};
    int red{m.DajBrojRedova()}, kolona{m.DajBrojKolona()};
    for(int i=0; i<red; i++){
        for(int j=0; j<kolona; j++){
            mat[i][j]=m.matrica[i][j]*k;
        }
    }
    return mat;
}
template <typename NekiTip>
GMatrica<NekiTip> &GMatrica<NekiTip>::operator +=(const GMatrica<NekiTip> &m1){
  int red{m1.DajBrojRedova()}, kolona{m1.DajBrojKolona()}; 
 //if(this->red!=m1.red || this->kolona!=m1.kolona) throw std::domain_error("Nedozvoljena operacija");
 for(int i=0; i<red; i++){
    for(int j=0; j<kolona; j++){
        this->matrica[i][j]+=m1.matrica[i][j];
     }
 }
 return *this;
}
template <typename NekiTip>
GMatrica<NekiTip> &GMatrica<NekiTip>::operator -=(const GMatrica<NekiTip> &m1){
    int red{m1.DajBrojRedova()}, kolona{m1.DajBrojKolona()};
    for(int i=0; i<red; i++){
        for(int j=0; j<kolona; j++){
            this->matrica[i][j]-=m1.matrica[i][j];
        }
    }
    return *this;
}
/*GMatrica<NekiTip> &GMatrica<NekiTip>::operator *=(const GMatrica<NekiTip> &m1){
    int red{m1.DajBrojRedova()}, kolona{m1.DajBrojKolona()};
    for(int i=0; i<red; i++){
        for(int j=0; j<kolona; j++)
    }
}*/
template <typename NekiTip1>
std::ostream &operator <<(std::ostream &tok, const GMatrica<NekiTip1> &m){
    int x(tok.width());
    int red{m.DajBrojRedova()}, kolona{m.DajBrojKolona()};
    for(int i=0; i<red; i++){
        for(int j=0; j<kolona; j++){
         //   std::cout <<m.matrica[i][j];
          //  if(m.matrica[i][j]=='A'){ }
          /* else*/ tok <<std::setw(x)<<m.matrica[i][j];
        }
        tok <<std::endl;
    }
    tok <<std::endl;
    return tok;
}
int main (){
    try{
  //  double niz[4][4]{{1,2,5,2},{3,1,2,1},{2,5,1,2},{1,2,3,4}};
  // GMatrica<int> matrica(niz);
 //  std::cout<<matrica.DajBrojRedova()<<" "<<matrica.DajBrojKolona();
 //  std::vector<std::vector<int>> v{{1,2,5,2},{2,5,1,2},{1,2,3,4}};
  //  GMatrica<int> matrica(v);
 //   std::cout <<matrica.DajBrojRedova()<<" "<<matrica.DajBrojKolona();
  //    GMatrica<int> matrica{{1,2,5,2},{3,1,2,1},{2,5,1,2},{1,2,3,4}};
 //     std::cout <<matrica.DajBrojRedova()<<" "<<matrica.DajBrojKolona();
    GMatrica<int> matrica1({{1,2,5},{3,1,2},{2,5,1}});   
    GMatrica<double> matrica2({{1,2,5},{3,1,2},{2,5,1}});
  // std::cout <<std::setw(10)<<matrica1+matrica2<<std::setw(10)<<matrica1-matrica2<<std::setw(10)<<matrica1*matrica2;
   // std::cout <<std::setw(10)<<3*matrica1;
    //std::cout<<std::setw(10)<<matrica2*3;
    matrica1+=matrica2;
    std::cout <<std::setw(10)<<matrica1;
    matrica1-=matrica2;
    std::cout <<std::setw(10)<<matrica1;
   //  GMatrica<int> matrica(2,2,2);
  //  GMatrica<int> matrica1(2,2,2);
  // GMatrica<double> matrica(matrica1);
 //   std::cout <<matrica1.DajBrojKolona()<<" "<<matrica1.DajBrojRedova();
   // matrica=static_cast<double>(matrica1);
//    GMatrica<double> matrica{{1,2,5},{3,1,2},{2,5,1}};
    }
    catch(std::logic_error izuzetak1){
        std::cout <<izuzetak1.what()<<std::endl;
    }
    catch(std::domain_error izuzetak2){
        std::cout <<izuzetak2.what()<<std::endl;
    }
	return 0;
}
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <utility>

template <typename Tip>

class GMatrica{
    int br_redova;
    int br_kolona;
    Tip matrica[4][4];
public:
    GMatrica();
    GMatrica(int br_redova, int br_kolona, Tip element={});
    template <typename Tip2> GMatrica(Tip2 mat);
    template <typename Tip2> GMatrica(Tip2 niz[4][4]);
    template <typename Tip2> GMatrica(std::vector<std::vector<Tip2>> vektor);
    GMatrica(std::initializer_list<Tip> lista);
    int DajBrojRedova() const {return br_redova;}
    int DajBrojKolona() const {return br_kolona;}
    template <typename Tip2>
    friend GMatrica<int> operator +(GMatrica<Tip> &a,GMatrica<Tip2> &b);
   /* template <typename Tip2>
    friend auto operator -(const GMatrica<Tip> &a, const GMatrica<Tip2> &b)->GMatrica<decltype (a.matrica[0][0]-b.matrica[0][0])>;
    template <typename Tip2>
    friend auto operator *(const GMatrica<Tip> &a, const GMatrica<Tip2> &b)->GMatrica<decltype (a.matrica[0][0]*b.matrica[0][0])>;
    template <typename Tip2>
    friend auto operator *(const GMatrica<Tip> &a, const Tip2 broj)-> GMatrica<decltype (a.matrica[0][0]*broj)>;
    template <typename Tip2>
    friend auto operator *(const Tip2 broj, const GMatrica<Tip> &a)->GMatrica<decltype (a.matrica[0][0]*broj)>;
    template <typename Tip2>
    friend GMatrica &operator +=(GMatrica<Tip> &a, const GMatrica<Tip2> &b);
    template <typename Tip2>
    friend GMatrica &operator -=(GMatrica<Tip> &a, const GMatrica<Tip2> &b);
    template <typename Tip2>
    friend GMatrica &operator *=(GMatrica<Tip> &a, const GMatrica<Tip2> &b);
    template <typename Tip2>
    friend GMatrica &operator *=(GMatrica<Tip> &a, const Tip2 broj);
    template <typename Tip2>
    friend GMatrica &operator *=(const Tip2 broj, GMatrica<Tip> &a);*/
    friend bool operator ==(const GMatrica &a, const GMatrica &b);
    friend bool operator !=(const GMatrica &a, const GMatrica &b);
    
};
template <typename Tip>
GMatrica<Tip>::GMatrica(){
    GMatrica::br_redova=0;
    GMatrica::br_kolona=0;
    }
    
template<typename Tip>
GMatrica<Tip>::GMatrica(int br_redova, int br_kolona, Tip element): br_redova(br_redova), br_kolona(br_kolona){
    if(GMatrica::br_redova<0 || GMatrica::br_redova>4 || GMatrica::br_kolona<0 || GMatrica::br_kolona>4) throw std::logic_error("Ilegalan format matrice");
    GMatrica::br_redova=br_redova;
    GMatrica::br_kolona=br_kolona;
    for(int i(0);i<GMatrica::br_redova;i++){
        for(int j(0);j<GMatrica::br_kolona;j++){
            GMatrica::matrica[i][j]=element;
        }
    }
}

template <typename Tip>
template <typename Tip2>
GMatrica<Tip>::GMatrica(Tip2 mat){
    if(mat.br_redova<0 || mat.br_redova>4 || mat.br_kolona<0 || mat.br_kolona>4) throw std::logic_error("Ilegalan format matrice");
    GMatrica::br_redova=mat.br_redova;
    GMatrica::br_kolona=mat.br_kolona;
    for(int i(0);i<mat.br_redova;i++){
        for(int j(0);j<mat.br_kolona;j++){
            matrica[i][j]=(Tip)mat.matrica[i][j];
        }
    }
}
template<typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<Tip> lista){
    std::copy(lista.begin(),lista.end(), matrica);
}

template<typename Tip>
template<typename Tip2>
GMatrica<Tip>::GMatrica(Tip2 niz[4][4]){
    for(int i(0);i<4;i++){
        for(int j(0);j<4;j++){
            matrica[i][j]=(Tip)niz[i][j];
        }
    }
}

template<typename Tip>
template<typename Tip2>
GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip2>> vektor){
    if(vektor.size()<0 || vektor.size()>4) throw std::logic_error("Ilegalan format matrice");
    br_redova=vektor.size();
    br_kolona=vektor.size();
    for(int i(0);i<vektor.size();i++){
        for(int j(0);j<vektor.size();j++){
            matrica[i][j]=(Tip)vektor[i][j];
        }
    }
}

template <typename Tip,typename Tip2>
//template <typename Tip2>
GMatrica<Tip> operator +(const GMatrica<Tip> &a, const GMatrica<Tip2> &b){
    GMatrica<Tip> matrica;
    if(a.DajBrojRedova() != b.DajBrojRedova() || a.DajBrojKolona() != b.DajBrojKolona()) throw std::domain_error ("Nedozvoljena operacija");
    for(int i(0);i<a.DajBrojRedova();i++){
        for(int j(0);j<a.DajBrojKolona();j++){
            matrica.matrica[i][j]=a.matrica[i][j]+b.matrica[i][j];
        }
    }
    return matrica;
}
template <typename Tip, typename Tip2>
GMatrica<Tip> operator -(const GMatrica<Tip> &a, const GMatrica<Tip2> &b){
    GMatrica<Tip> matrica;
    if(a.br_redova!=b.br_redova || a.br_kolona!=b.br_kolona) throw std::domain_error ("Nedozvoljena operacija");
    for(int i(0);a.br_redova;i++){
        for(int j(0);a.br_kolona;j++){
            matrica.matrica[i][j]=a.matrica[i][j]-b.matrica[i][j];
        }
    }
    return matrica;
}
template <typename Tip, typename Tip2>
bool operator==(const GMatrica<Tip> &a, const GMatrica<Tip2> &b){
    bool jednaki(true);
    for(int i(0);i<a.br_redova;i++){
        for(int j(0);j<a.br_kolona;j++){
            if(a.matrica[i][j]==b.matrica[i][j]) jednaki=true;
            else{
                jednaki=false;
                break;
            }
        }
    }
    return jednaki;
}
template <typename Tip, typename Tip2>
bool operator !=(const GMatrica<Tip> &a, const GMatrica<Tip2> &b){
    return !(a==b);
}

int main ()
{
    int mat[4][4]{{1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}};
    GMatrica<int> m1(mat);
    int mat2[4][4]{{1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}};
    GMatrica<int> m2(mat2);
    GMatrica<int> m3 = m1+m2;
   // std::cout << m3 << std::endl;
   // GMatrica<double> m4({{1, 2}, {3, 4}});
  //  auto m5 = m3-m4;
 //  std::cout << m5 << std::endl;
	return 0;
}
/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename tip>
class GMatrica{
    tip mat[4][4];
    int brred,brkol;
    public:
    GMatrica () {};
    GMatrica(int red,int kol, tip x());
    // oni podrazumijevani konstruktori ....template <typename tip>
    //template <typename tip1>
    GMatrica(std::vector<std::vector<tip>> matrica);
    template <typename tip1>
    GMatrica<tip>(GMatrica<tip1> &matrica);
    int DajBrojRedova() {return brred;}
    int DajBrojKolona() {return brkol;}
   // template<typename tip1,typename tip2>
   // friend GMatrica operator +(GMatrica m1, GMatrica m2)
};

template <typename tip>
GMatrica<tip>::GMatrica(int red, int kol, tip x()){
    if(red<0 || red>4 || kol<0 || kol>4) throw std::logic_error("Ilegalan format matrice");
    brred=kol;
    brkol=kol;
    for(int i=0;i<brred;i++){
        for(int j=0;j<brkol;j++){
            mat[i][j]=x;
        }
    }
}

template <typename tip>
template <typename tip1>
GMatrica<tip1>::GMatrica(GMatrica<tip1> &matrica){
    if (matrica.DajBrojRedova()<0 || matrica.DajBrojKolona()>4 || matrica.DajBrojRedova()>4 || matrica.DajBrojKolona()<0) throw std::logic_error("Ilegalan format matrice");
    brred=matrica.DajBrojRedova; brkol=matrica.DajBrojKolona();
    for(int i=0;i<matrica.DajBrojRedova();i++){
        for(int j=0;j<matrica.DajBrojKolona();j++){
            mat[i][j]=matrica[i][j];
        }
    }
}

template <typename tip>
GMatrica<tip>::GMatrica(std::vector<std::vector<tip>> matrica){
        for(int i=1;i<matrica.size();i++){
            if(matrica[i].size()!=matrica[0].size()) throw std::logic_error("Ilegalan format matrice");
        }
        if(matrica.size()<0 || matrica.size()>4 || matrica[0].size()<0 || matrica[0].size()>4) throw std::logic_error("Ilegalan format matrice");
        for(int i=0;i<matrica.size();i++){
            for(int j=0;j<matrica[0].size();j++){
                mat[i][j]=matrica[i][j];
            }
        }
}


int main ()
{
	return 0;
}
/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept> 

template <typename TipEl> 
class GMatrica{
    TipEl el[4][4];
    int br_red, br_kol;
    public:
    GMatrica();
    GMatrica(int broj_k, int broj_r, TipEl vr);
    
};

template <typename TipEl>
GMatrica<TipEl>::GMatrica() : br_red(0), br_kol(0){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            el[i][j]=0;
        }
    }
}

template <typename TipEl>
GMatrica<TipEl>::GMatrica(int broj_k, int broj_r, TipEl vr ) : {
    if (broj_k>4 || broj_k<0 || broj_r>4 || broj_r<0)
        throw std::logic_error ("Ilegalan format matrice")
    br_red (broj_r), br_kol(broj_k)
     for (int i=0; i<broj_r; i++)
        for (int j=0; j<broj_k; j++)
            el[i][j] = vr;
 }
int main ()
{
	return 0;
}
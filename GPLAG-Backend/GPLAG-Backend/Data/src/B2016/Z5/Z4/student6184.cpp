/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <initializer_list>
#include <stdexcept>

template <typename tip>
class GMatrica
{ 
    tip mat[4][4];
    int br_redova;
    int br_kolona;
public:
    GMatrica();
    GMatrica(int br_redova,int br_kolona,tip vrijednost=tip());
    GMatrica(GMatrica &m);
    GMatrica(tip **m);
    GMatrica(std::vector<std::vector<tip>> &veca);
    GMatrica(std::initializer_list<tip> lista);
    int DajBrojRedova() const;
    int DajBrojKolona() const;
    friend GMatrica operator +(const GMatrica &m1,const GMatrica &m2);
    friend GMatrica operator -(const GMatrica &m1,const GMatrica &m2);
    friend GMatrica operator *(const GMatrica &m1,const GMatrica &m2);
    friend GMatrica operator *(const GMatrica &m1,tip broj);
    friend GMatrica operator *(tip broj,const GMatrica &m);
    GMatrica operator +=(const GMatrica &m);
    GMatrica operator -=(const GMatrica &m);
    GMatrica operator *=(const GMatrica &m);


};

GMatrica::GMatrica()
{
    br_kolona=0;
    br_redova=0;
}

template<typename tip>
GMatrica::GMatrica(int br_redova,int br_kolona,tip vrijednost=tip())
{
    if(br_redova<0 || br_redova>4 || br_kolona<0 || br_kolona>4) throw std::logic_error("Ilegalan format matrice");
    GMatrica::br_redova=br_redova;
    GMatrica::br_kolona=br_kolona;
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<br_kolona; j++) mat[i][j]=vrijednost;
    }
}

template<typename tip>
GMatrica::GMatrica(GMatrica<tip> &m)
{
    br_redova=m.DajBrojRedova();
    br_kolona=m.DajBrojKolona();
    for(int i=0; i<m.DajBrojRedova(); i++) {
        for(int j=0; j<m.DajBrojKolona(); j++) mat[i][j]=m[i][j];
    }
}

template<typename tip>
GMatrica::GMatrica(tip **poki)
{
    br_redova=4;
    br_kolona=4;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            mat[i][j]=poki[i][j];
        }
    }
}

template<typename tip>
GMatrica::GMatrica(std::vector<std::vector<tip>> &veca)
{
    if(veca.size()<0 || veca.size()>4 || veca[0].size()<0 || veca[0]>4) throw std::logic_error("Ilegalan format matrice");
    for(int i=0; i<veca.size(); i++) {
        if(veca[i].size()!=veca[0].size) throw std::logic_error("Ilegalan format matrice");
    }
    br_redova=veca.size();
    br_kolona=veca[0].size();
    for(int i=0; i<veca.size(); i++) {
        for(int j=0; j<veca[i].size(); j++) {
            mat[i][j]=veca[i][j];
        }
    }
}
template<typename tip>
GMatrica::GMatrica(std::intializer_list<std::intializer_list<tip>> lista)
{
    br_redova=lista.size();
    auto it(lista.begin());
    br_kolona=(*it).size();
    for(int i=0; i<lista.size(); i++) {
        auto it(lista.begin());
        for(int j=0; j<(*it).size(); j++) {
            auto it1((*it).begin());
            mat[i][j]=*it1;
            it1++;
        }
        it++;
    }
}

int GMatrica::DajBrojRedova()
{
    return br_redova;
}
int GMatrica::DajBrojKolona()
{
    return br_kolona;
}

GMatrica GMatrica::operator +(const GMatrica &m1,const GMatrica &m2)
{
    if(m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m1.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija");

    GMatrica m(m1.DajBrojRedova(),m1.DajBrojKolona())
}

int main ()
{
    return 0;
}
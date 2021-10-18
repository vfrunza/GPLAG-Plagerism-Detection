/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <stdexcept>
#include <type_traits>
#include <initializer_list>
#include <algorithm>
template <typename t>
class GMatrica{
    t matr[4][4];
    int br_red;
    int br_kol;
    static void Test(int red, int kol){if(red<0 || red>4 || kol<0 || kol>4) throw std::logic_error("Ilegalan format matrice");}
    template<typename t1, typename t2>
    static bool ImajuLiIstiFormat(const GMatrica<t1> &m1, const GMatrica<t2> &m2){
        if(m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona())
        throw std::domain_error("Nedozvoljena operacija"); return true;}
public:
    int DajBrojRedova()const{return br_red;}
    int DajBrojKolona()const{return br_kol;}
    template <typename t1, typename t2>
    friend GMatrica &operator +(const GMatrica<t1> &m1,const GMatrica<t2> &m2);
    template<typename t1, typename t2>
    friend GMatrica &operator -(const GMatrica<t1> &m1, const GMatrica<t2> &m2);
    template<typename t1, typename t2>
    friend GMatrica &operator *(const GMatrica<t1> &m1, const GMatrica<t2> &m2);
    template<typename t1,typename t2>
    friend GMatrica &operator *(GMatrica<t1> &m1, t2 broj);
    template<typename t1,typename t2>
    friend GMatrica &operator *(t2 broj, GMatrica<t1> &m1);
    template<typename t1>
    GMatrica &operator +=(const GMatrica<t1> &m1);
    template<typename t1>
    GMatrica &operator -=(const GMatrica<t1> &m1);
    template<typename t1>
    GMatrica &operator *=(const GMatrica<t1> &m1);
    template<typename t1, typename t2>
    friend bool operator ==(const GMatrica<t1> &m1, const GMatrica<t2> &m2);
    template<typename t1, typename t2>
    friend bool operator !=(const GMatrica<t1> &m1, const GMatrica<t2> &m2);
    t &operator ()(int i, int j);
    t operator ()(int i, int j)const;
    GMatrica* &operator [](int i);
    GMatrica* operator [](int i)const;
    template<typename t1>
    friend std::istream &operator >>(std::istream &ulaz, const GMatrica<t1> &m1);
    template<typename t1>
    friend std::ostream &operator <<(std::ostream &izlaz, const GMatrica<t1> &m1);
    GMatrica();
    GMatrica(int red, int kol, t vr=0);
    template <typename t1>
    GMatrica(const GMatrica<t1> &a);
    GMatrica(const t matrica[4][4]);
    GMatrica(const std::vector<std::vector<t>> v);
    GMatrica(std::initializer_list<t> a);
};
template<typename t>
t GMatrica<t>::operator ()(int i, int j)const{}
template<typename t>
t GMatrica<t>::&operator ()(int i, int j){}
template<typename t1, typename t2>
bool operator !=(const GMatrica<t1> &m1, const GMatrica<t2> &m2){}
template<typename t1, typename t2>
bool operator ==(const GMatrica<t1> &m1, const GMatrica<t2> &m2){}
template<typename t>
auto GMatrica<t>::&operator +=(const GMatrica<t> &m)->GMatrica<decltype(m[0][0])>{}
template<typename t>
auto GMatrica<t>::&operator -=(const GMatrica<t> &m)->GMatrica<decltype(m[0][0])>{}
template<typename t>
auto GMatrica<t>::&operator *=(const GMatrica<t> &m)->GMatrica<decltype(m[0][0])>{}
template<typename t1, typename t2>
auto operator +(const GMatrica<t1> &m1, const GMatrica<t2> &m2)->GMatrica<decltype(m1[0][0]+m2[0][0])>{
    ImajuLiIstiFormat(m1,m2);
    decltype(m1[0][0]+m2[0][0]) zbir(m1.DajBrojRedova(),m1.DajBrojKolona(),0);  //more bit' problem zbog 0
    //svedi ovo na operator +=
}
template<typename t1, typename t2>
auto operator -(const GMatrica<t1> &m1, const GMatrica<t2> &m2)->GMatrica<decltype(m1[0][0]-m2[0][0])>{}
template<typename t1, typename t2>
auto operator *(const GMatrica<t1> &m1, const GMatrica<t2> &m2)->GMatrica<decltype(m1[0][0]*m2[0][0])>{}
template<typename t1, typename t2>
auto operator *(GMatrica<t1> &m, t2 broj)->GMatrica<decltype(m[0][0]*broj)>{}
template<typename t1, typename t2>
auto operator *(t1 broj, GMatrica<t2> &m)->GMatrica<decltype(m[0][0]*broj)>{}

template<typename t>
GMatrica<t>::GMatrica(std::initializer_list<t> a){
    for(auto i=a.begin(); i!=a.end(); i++) Test(a.size(), i->size());
    auto it=a.begin();
    for(int i=0; i<br_red; i++){
        std::copy(matr[i], matr[i]+br_kol, it);
        it++;
    }
}
template <typename t>
GMatrica<t>::GMatrica(const std::vector<std::vector<t>> v){
    int i;
    for(i=0; i<v.size(); i++){
        Test(v.size(), v[i].size());
        if(v.size()!=v[i].size()) throw std::logic_error("Ilegalan format matrice");
    }
    br_red=v.size();
    if(i==1) br_kol=0;
    else br_kol=v[0].size();
    for(int j=0; i<v.size(); i++)
        for(int k=0; k<v[i].size(); k++)
            matr[j][k]=v[j][k];
}

/*template <typename t1, typename t2>  //sto neces
GMatrica<t1>::GMatrica(const GMatrica<t2> &a){
    Test(a.br_red,a.br_kol);
    br_red=a.br_red; br_kol=a.br_kol;
    for(int i=0; i<br_red; i++)
        for(int j=0; j<br_kol; j++)
            matr[i][j]=a.matr[i][j];
}*/
template <typename t>
GMatrica<t>::GMatrica():br_red(0),br_kol(0){}
template <typename t>
GMatrica<t>::GMatrica(int red, int kol, t vr){
    Test(red,kol);
    br_red=red; br_kol=kol;
    for(int i=0; i<br_red; i++)
        for(int j=0; j<br_kol; j++)
            matr[i][j]=vr;
}

int main ()
{
	return 0;
}
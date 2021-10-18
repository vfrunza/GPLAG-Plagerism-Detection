/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>    
#include <type_traits>
#include <iomanip>

using namespace std;

template <typename T>
class GMatrica {
    int br_red=0, br_kol=0;
    T mat[4][4];                                                   
    public:
    GMatrica() {br_red=0; br_kol=0; };
    GMatrica(int BrojRedova, int BrojKolona, T vrijednost=0);
    GMatrica(GMatrica &mat1);                                           
    GMatrica(T niz[4][4]);                                           
    GMatrica(vector<vector<T> > mat);                               
    GMatrica(initializer_list<initializer_list<T> > i_lista);                           
    int DajBrojRedova() const  { return br_red; };
    int DajBrojKolona() const  { return br_kol; };
    template <typename T1,typename T2,typename T3>
    friend GMatrica<T1> operator +(const GMatrica<T2> &mat1, const GMatrica<T3> &mat2);
    template <typename T1,typename T2,typename T3>
    friend GMatrica<T1> operator -(const GMatrica<T1> &mat1, const GMatrica<T1> &mat2);
    template <typename T1,typename T2,typename T3>
    friend GMatrica<T1> operator *(const GMatrica<T1> &mat1, const GMatrica<T1> &mat2);
    template <typename T1,typename T2,typename T3>
    friend GMatrica<T1> operator *(const GMatrica<T2> &mat1, T3 n);
    template <typename T1,typename T2,typename T3>
    friend GMatrica<T1> operator *(T2 n, const GMatrica<T3> &mat1);
    GMatrica &operator +=(const GMatrica &mat);
    GMatrica &operator -=(const GMatrica &mat);
    GMatrica &operator *=(const GMatrica &mat);
    GMatrica &operator *=(T broj);
    bool operator ==(const GMatrica &mat);
    bool operator !=(const GMatrica &mat);
    T& operator ()(int i, int j);
    T* operator [](int i) { return mat[i]; };
    template<typename T1>
    friend ostream &operator <<(ostream &tok, const GMatrica<T1> &m);
    template<typename T1>
    friend istream &operator >>(istream &tok, const GMatrica<T1> &m);
};
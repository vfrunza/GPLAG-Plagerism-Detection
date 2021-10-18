/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <type_traits>
template<typename T>
class GMatrica {
 //!!!
    T elementi[4][4];
    int redovi, kolone;
public:
    GMatrica() : redovi(0), kolone(0) {}
    GMatrica(int r, int k, T el = 0);
    template <typename T2> GMatrica<T>(const GMatrica<T2> &m);
    template <typename T2> GMatrica<T>(T2 niz[4][4]);
    GMatrica(const std::vector<T> &v);
    template <typename T2> GMatrica<T>(const std::initializer_list<std::initializer_list<T2>> &lista);
    int DajBrojRedova() const {return redovi;}
    int DajBrojKolona() const {return kolone;}
    template <typename T2> friend GMatrica<decltype(T() + T2())> operator +(const GMatrica<T> &m1, const GMatrica<T2> &m2);// -> decltype(T() + T2());
    
    
};
template <typename T>
    auto operator + (const GMatrica<T> &m1, const GMatrica<T> &m2) -> decltype(m1.elementi[0][0] + m2.elementi[0][0]) {
        
    }
template <typename T>
GMatrica<T>::GMatrica(int r, int k, T el) : redovi(r), kolone(k) {
    if(r < 0 || k < 0 || r > 4 || k > 4) throw std::logic_error("Ilegalan format matrice");
    for(int i = 0; i < r; i++)
        std::fill(elementi[i], elementi[i]+k, el);
}
template <typename T>
template <typename T2>
GMatrica<T>::GMatrica(const GMatrica<T2> &m) {
    redovi = m.redovi;
    kolone = m.kolone;
    for(int i = 0; i < redovi; i++)
        std::copy(m.elementi[i], m.elementi[i]+kolone, elementi[i]);
}
template <typename T>
template <typename T2>
GMatrica<T>::GMatrica(T2 niz[4][4]) {
    redovi = 4;
    kolone = 4;
    for(int i = 0; i < 4; i++)
        std::copy(niz[i], niz[i]+4, elementi[i]);
}
template <typename T>
GMatrica<T>::GMatrica(const std::vector<T> &v) {
    if(v.size() > 4) throw std::logic_error("Ilegalan format matrice");
    if(v.size() && v[0].size() > 4) throw std::logic_error("Ilegalan format matrice");
    for(int i = 0; i < v.size(); i++)
        if(v[i].size() != v[0].size())
            throw std::logic_error("Ilegalan format matrice");
    redovi = v.size();
    kolone = v[0].size();
    for(int i = 0; i < redovi; i++)
        std::copy(v[i].begin(), v.end(), elementi[i]);
    
}
template <typename T>
template <typename T2>
GMatrica<T>::GMatrica(const std::initializer_list<std::initializer_list<T2>> &lista) {
    if(lista.size() > 4) throw std::logic_error("Ilegalan format matrice");
    for(auto it = lista.begin(); it != lista.end(); it++)
        if(it->size() != lista.begin()->size() || it->size() > 4) throw std::logic_error("Ilegala format matrice");
    redovi = lista.size();
    kolone = lista.begin()->size();
    int i(0);
    for(auto it = lista.begin(); it != lista.end(); it++) {
        std::copy(it->begin(), it->end(), elementi[i]);
        i++;
    }
}
int main ()
{
    GMatrica<int> m;
    
	return 0;
}
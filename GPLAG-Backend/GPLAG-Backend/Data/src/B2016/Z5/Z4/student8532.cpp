/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <cmath>
#include <functional>
#include <iomanip>
#include <utility>
#include <complex>
#include <string>

using namespace std;

template <typename T1, typename T2>
bool poredi(T1 a, T2 b){
    return fabs(a - b) < 0.001;
}

template <typename T>
class GMatrica {
    T mat[4][4];
    int redovi, kolone;
    
public:
    GMatrica<T> () : mat{{0}}, redovi(0), kolone(0) {}
    GMatrica<T> (int, int, T n = T());
    template <typename T2>
    GMatrica<T> (const GMatrica<T2>&);
    template <typename T2>
    GMatrica<T> (T2**);
    GMatrica<T> (vector<vector<T>>);
    GMatrica<T> (initializer_list<initializer_list<T>>);
    //
    int DajBrojRedova() const { return redovi; }
    int DajBrojKolona() const { return kolone; }
    template <typename T1, typename T2>
    friend auto operator+ (const GMatrica<T1>& m1, const GMatrica<T2>& m2) 
        -> decltype(GMatrica<decltype(m1(1, 1) + m2(1, 1))>());
    template <typename T1, typename T2>
    friend auto operator- (const GMatrica<T1>& m1, const GMatrica<T2>& m2) 
        -> decltype(GMatrica<decltype(m1(1, 1) - m2(1, 1))>());
    template <typename T1, typename T2>
    friend auto operator* (const GMatrica<T1>& m1, const GMatrica<T2>& m2) 
        -> decltype(GMatrica<decltype(m1(1, 1) * m2(1, 1))>());
    template <typename T1, typename T2>
    friend auto operator* (const GMatrica<T1>& m, const T2 n) 
        -> decltype(GMatrica<decltype(m(1, 1) * n)>());
    //template <typename T1, typename T2>
    //friend auto operator* (const T1 n, const GMatrica<T2>& m) -> decltype(GMatrica<decltype(m(1, 1) * n)>()) { return m * n; }
    template <typename T2>
    GMatrica<T> operator+= (const GMatrica<T2>&);
    template <typename T2>
    GMatrica<T> operator-= (const GMatrica<T2>&);
    template <typename T2>
    GMatrica<T> operator*= (const GMatrica<T2>&);
    template <typename T2>
    GMatrica<T> operator*= (const T2&);
    //template <typename T2>
    //friend GMatrica<T> operator*= (const T2& n, GMatrica<T>& m) { return m *= n; }
    template <typename T1, typename T2>
    friend bool operator==(const GMatrica<T1>&, const GMatrica<T2>&);
    //template <typename T1, typename T2>
    //friend bool operator!=(const GMatrica<T1>& m1, const GMatrica<T2>& m2) { return !(m1 == m2); }
    
    T& operator() (int, int);
    const T operator() (int, int) const;
    T* operator[] (int);
    const T* operator[] (int) const;
    
    template <typename T2>
    friend ostream& operator<< (ostream&, const GMatrica<T2>&);
    template <typename T2>
    friend istream& operator>> (istream&, GMatrica<T2>&);
};

template <typename T1, typename T2>
bool operator!=(const GMatrica<T1>& m1, const GMatrica<T2>& m2) { return !(m1 == m2); }

template <typename T1, typename T2>
auto operator* (const T1 n, const GMatrica<T2>& m) -> decltype(GMatrica<decltype(m(1, 1) * n)>()) { return m * n; }

template <typename T>
GMatrica<T>::GMatrica(int redovi, int kolone, T n){
    if(redovi < 0 || redovi > 4 || kolone < 0 || kolone > 4)
        throw logic_error("Ilegalan format matrice");
    this->redovi = redovi;
    this->kolone = kolone;
    for(int i(0); i < redovi; i++)
        for(int j(0); j < kolone; j++) mat[i][j] = n;
}

template <typename T>
template <typename T2>
GMatrica<T>::GMatrica (const GMatrica<T2>& g){
    this->redovi = g.DajBrojRedova();
    this->kolone = g.DajBrojKolona();
    for(int i(0); i < this->redovi; i++)
        for(int j(0); j < this->kolone; j++)
            mat[i][j] = g[i][j];
}

template <typename T>
template <typename T2>
GMatrica<T>::GMatrica (T2** mat){
    redovi = 4;
    kolone = 4;
    for(int i(0); i < this->redovi; i++)
        for(int j(0); j < this->kolone; j++)
            this->mat[i][j] = mat[i][j];
}

template <typename T>
GMatrica<T>::GMatrica (vector<vector<T>> v){
    int vel = (int)v.size();
    int brojKolona = 0;
    if(vel > 4) throw logic_error("Ilegalan format matrice");
    if(vel != 0){
        brojKolona = (int)v.at(0).size();
        for(vector<T> x : v)
            if(x.size() > 4 || (int)x.size() != brojKolona) throw logic_error("Ilegalan format matrice");
    }
    this->redovi = vel;
    this->kolone = brojKolona;
    for(int i(0); i < vel; i++)
        for(int j(0); j < brojKolona; j++)
            mat[i][j] = v.at(i).at(j);
}

template <typename T>
GMatrica<T>::GMatrica (initializer_list<initializer_list<T>> lista){
    int vel = (int)lista.size();
    int brojKolona = 0;
    if(vel > 4) throw logic_error("Ilegalan format matrice");
    if(vel != 0){
        brojKolona = (int)lista.begin()->size();
        for(initializer_list<T> x : lista)
            if(x.size() > 4 || (int)x.size() != brojKolona) throw logic_error("Ilegalan format matrice");
    }
    this->redovi = vel;
    this->kolone = brojKolona;
    auto it = lista.begin();
    for(int i(0); i < vel; i++, it++){
        auto element = it->begin();
        for(int j(0); j < brojKolona; j++, element++)
            mat[i][j] = *element;
    }
}

template <typename T1, typename T2>
auto operator+ (const GMatrica<T1>& m1, const GMatrica<T2>& m2) -> decltype(GMatrica<decltype(m1(1, 1) + m2(1, 1))>()){
    typedef decltype(GMatrica<decltype(m1(1, 1) + m2(1, 1))>()) tip;
    if(m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona())
        throw domain_error("Nedozvoljena operacija");
    tip rez(m1.DajBrojRedova(), m1.DajBrojKolona());
    for(int i(0); i < m1.DajBrojRedova(); i++)
        for(int j(0); j < m1.DajBrojKolona(); j++)
            rez[i][j] = m1[i][j] + m2[i][j];
    return rez;
}

template <typename T1, typename T2>
auto operator- (const GMatrica<T1>& m1, const GMatrica<T2>& m2) -> decltype(GMatrica<decltype(m1(1, 1) - m2(1, 1))>()){
    typedef decltype(GMatrica<decltype(m1(1, 1) - m2(1, 1))>()) tip;
    if(m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona())
        throw domain_error("Nedozvoljena operacija");
    tip rez(m1.DajBrojRedova(), m1.DajBrojKolona());
    for(int i(0); i < m1.DajBrojRedova(); i++)
        for(int j(0); j < m1.DajBrojKolona(); j++)
            rez[i][j] = m1[i][j] - m2[i][j];
    return rez;
}

template <typename T1, typename T2>
auto operator* (const GMatrica<T1>& m1, const GMatrica<T2>& m2) -> decltype(GMatrica<decltype(m1(1, 1) * m2(1, 1))>()){
    typedef decltype(GMatrica<decltype(m1(1, 1) * m2(1, 1))>()) tip;
    if(m1.DajBrojKolona() != m2.DajBrojRedova())
        throw domain_error("Nedozvoljena operacija");
    tip rez(m1.DajBrojRedova(), m2.DajBrojKolona());
    for(int i(0); i < rez.DajBrojRedova(); i++)
        for(int j(0); j < rez.DajBrojKolona(); j++)
            for(int k(0); k < rez.DajBrojKolona(); k++)
                rez[i][j] += m1[i][k] * m2[k][j];
    return rez;
}

template <typename T1, typename T2>
auto operator* (const GMatrica<T1>& m, const T2 n) -> decltype(GMatrica<decltype(m(1, 1) * n)>()){
    typedef decltype(GMatrica<decltype(m(1, 1) * n)>()) tip;
    tip rez(m);
    for(int i(0); i < rez.DajBrojRedova(); i++)
        for(int j(0); j < rez.DajBrojKolona(); j++)
            rez[i][j] *= n;
    return rez;
}

template <typename T>
template <typename T2>
GMatrica<T> GMatrica<T>::operator+= (const GMatrica<T2>& m){
    if(DajBrojRedova() != m.DajBrojRedova() || DajBrojKolona() != m.DajBrojKolona())
        throw domain_error("Nedozvoljena operacija");
    for(int i(0); i < DajBrojRedova(); i++)
        for(int j(0); j < DajBrojKolona(); j++)
            mat[i][j] += m[i][j];
    return *this;
}

template <typename T>
template <typename T2>
GMatrica<T> GMatrica<T>::operator-= (const GMatrica<T2>& m){
    if(DajBrojRedova() != m.DajBrojRedova() || DajBrojKolona() != m.DajBrojKolona())
        throw domain_error("Nedozvoljena operacija");
    for(int i(0); i < DajBrojRedova(); i++)
        for(int j(0); j < DajBrojKolona(); j++)
            mat[i][j] -= m[i][j];
    return *this;
}

template <typename T>
template <typename T2>
GMatrica<T> GMatrica<T>::operator*= (const GMatrica<T2>& m){
    if(DajBrojKolona() != m.DajBrojRedova())
        throw domain_error("Nedozvoljena operacija");
    GMatrica<T> rez(DajBrojRedova(), m.DajBrojKolona());
    for(int i(0); i < rez.DajBrojRedova(); i++)
        for(int j(0); j < rez.DajBrojKolona(); j++)
            for(int k(0); k < rez.DajBrojKolona(); k++)
                rez[i][j] += mat[i][k] * m[k][j];
    return *this = rez;
}

template <typename T>
template <typename T2>
GMatrica<T> GMatrica<T>::operator*= (const T2& n){
    for(int i(0); i < DajBrojRedova(); i++)
        for(int j(0); j < DajBrojKolona(); j++)
            mat[i][j] *= n;
    return *this;
}

template <typename T1, typename T2>
bool operator==(const GMatrica<T1>& m1, const GMatrica<T2>& m2){
    if(m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona())
        return false;
    for(int i(0); i < m1.DajBrojRedova(); i++)
        for(int j(0); j < m1.DajBrojKolona(); j++)
            if(!poredi(m1[i][j], m2[i][j])) return false;
    return true;
}

template <typename T>
T& GMatrica<T>::operator() (int red, int kolona){
    if(red < 1 || red >= redovi || kolona < 1 || kolona >= kolone)
        throw range_error("Nedozvoljen indeks");
    return mat[red-1][kolona-1];
}

template <typename T>
const T GMatrica<T>::operator() (int red, int kolona) const{
    if(red < 1 || red >= redovi || kolona < 1 || kolona >= kolone)
        throw range_error("Nedozvoljen indeks");
    return mat[red-1][kolona-1];
}

template <typename T>
T* GMatrica<T>::operator[] (int indeks){
    return mat[indeks];
}

template <typename T>
const T* GMatrica<T>::operator[] (int indeks) const {
    return mat[indeks];
}

template <typename T>
ostream& operator<< (ostream& tok, const GMatrica<T>& g){
    int sirina = tok.width();
    if(sirina < 6) sirina = 6;
    for(int i(0); i < g.redovi; i++){
        for(int j(0); j < g.kolone; j++){
            int brojCifri = poredi(g[i][j], 0) ? 1 : 0;
            int temp = g[i][j];
            while(temp != 0){
                brojCifri++;
                temp /= 10;
            }
            for(int k(0); k < sirina - brojCifri; k++)
                tok << " ";
            tok << g.mat[i][j];
        }
        tok << endl;
    }
    return tok;
}

template <typename T>
istream& operator>> (istream& tok, GMatrica<T>& m){
    //tok.setstate(ios_base::failbit)
    vector<vector<T>> temp(1);
    int brojKolona(0);
    int red(0), kolona(0);
    bool prvired = true;
    while(1){
        if(tok.peek() == char_traits<char>::to_int_type('[')) {
            char c;
            tok >> c;
            continue;
        }
        else if(tok.peek() == char_traits<char>::to_int_type(']')) break;
        else if(tok.peek() == char_traits<char>::to_int_type(';')){
            if(prvired){
                brojKolona = kolona;
                prvired = false;
            }
            else if(kolona != brojKolona){
                tok.setstate(ios_base::failbit);
                return tok;
            }
            else kolona = 0;
            char c;
            tok >> c;
            red++;
            if(red == 4){
                tok.setstate(ios_base::failbit);
                return tok;
            }
            temp.push_back(vector<T>());
        }
        else if(tok.peek() == char_traits<char>::to_int_type(',')){
            char c;
            tok >> c;
            kolona++;
            if(kolona == 4){
                tok.setstate(ios_base::failbit);
                return tok;
            }
        }
        else{
            T broj;
            tok >> broj;
            if(!tok){
                tok.setstate(ios_base::failbit);
                return tok;
            }
            temp[red].push_back(broj);
            //cout << broj;
        }
    }
    //cout << kolona << " " << brojKolona;
    if(kolona - 1 != brojKolona){ // DORADITI DORADITI DORADTII DORADITI
        tok.setstate(ios_base::failbit);
        return tok;
    }
    m = temp;
    return tok;
}

int main ()
{
    try{
   GMatrica<int> m1;
   std::cin >> m1;
   std::cout << m1 << std::endl;  
    }catch(exception &e){
        cout << e.what();
    }
	return 0;
}
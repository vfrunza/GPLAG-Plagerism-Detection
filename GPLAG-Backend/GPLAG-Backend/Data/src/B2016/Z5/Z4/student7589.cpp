/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>


template <typename Tip>
class GMatrica {
    Tip matrica[4][4];
    int redovi, kolone;
public:
    GMatrica();
    GMatrica(int r, int k, Tip vrijednost = 0);
    template<typename T>
    GMatrica(const GMatrica<T> &m);
    template<typename T>
    GMatrica(T m[4][4]);
    GMatrica(std::vector<std::vector<Tip>> v);
    GMatrica(std::initializer_list<std::initializer_list<Tip>> lista);
    int DajBrojRedova() const { return redovi; }
    int DajBrojKolona() const { return kolone; }
    template<typename T1, typename T2>
    friend auto operator+(const GMatrica<T1> &m1, const GMatrica<T2> &m2) -> GMatrica<decltype(m1.matrica[0][0] + m2.matrica[0][0])>;
    template<typename T1, typename T2>
    friend auto operator-(const GMatrica<T1> &m1, const GMatrica<T2> &m2) -> GMatrica<decltype(m1.matrica[0][0] - m2.matrica[0][0])>;
    
    template<typename T1, typename T2>
    friend auto operator*(const GMatrica<T1> &m1, const GMatrica<T2> &m2) -> GMatrica<decltype(m1.matrica[0][0] * m2.matrica[0][0])>;
    
    template<typename T1>
    friend auto operator*(const GMatrica<T1> &m1, double broj) -> GMatrica<decltype(m1.matrica[0][0] * broj)>;
    
    template<typename T2>
    friend auto operator*(double broj, const GMatrica<T2> &m1) -> GMatrica<decltype(broj*m1.matrica[0][0])>;
    
    template<typename T>
    GMatrica<Tip> &operator+=(const GMatrica<T> &m2);
    template<typename T>
    GMatrica<Tip> &operator-=(const GMatrica<T> &m2);
    template<typename T>
    GMatrica<Tip> &operator*=(const GMatrica<T> &m2);
    template<typename T>
    GMatrica<Tip> &operator*=(T broj);
    template<typename T1, typename T2>
    friend bool operator==(const GMatrica<T1> &m1, const GMatrica<T2> &m2);
    template<typename T1, typename T2>
    friend inline bool operator!=(const GMatrica<T1> &m1, const GMatrica<T2> &m2);
    Tip* operator[](int i);
    const Tip* operator[](int i) const;
    Tip &operator()(int i, int j);
    Tip operator()(int i, int j) const;
    template<typename T>
    friend std::ostream &operator<<(std::ostream &tok, const GMatrica<T> &m);
    template<typename T>
    friend std::istream &operator>>(std::istream &tok, GMatrica<T> &m);
};

template<typename Tip>
GMatrica<Tip>::GMatrica() : redovi(0), kolone(0) {}
template<typename Tip>
GMatrica<Tip>::GMatrica(int r, int k, Tip vrijednost) {
    if(r < 0 || r > 4 || k < 0 || k > 4) throw std::logic_error("Ilegalan format matrice");
    redovi = r;
    kolone = k;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < k; j++)
            matrica[i][j] = vrijednost;
    }
}

template<typename Tip>
template <typename T>
GMatrica<Tip>::GMatrica(const GMatrica<T> &m) {
    redovi = m.DajBrojRedova();
    kolone = m.DajBrojKolona();
    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < kolone; j++) {
            matrica[i][j] = m[i][j];
        }
    }
}

template <typename Tip>
template <typename T>
GMatrica<Tip>::GMatrica(T m[4][4]) {
    redovi = 4;
    kolone = 4;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++)
            matrica[i][j] = m[i][j];
    }
}
template<typename Tip>
GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip>> v) {
    if(v.size() > 4) throw std::logic_error("Ilegalan format matrice");
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(i == j) continue;
            if(v[i].size() != v[j].size() || v[i].size() > 4) throw std::logic_error("Ilegalan format zadavanja matrice");
        }
    }
    
    redovi = v.size();
    kolone = v[0].size();
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++)
            matrica[i][j] = v[i][j];
    }
}
template<typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Tip>> lista) {
    if(lista.size() > 4) throw std::logic_error("Ilegalan format matrice");
    for(auto i = lista.begin(); i != lista.end(); i++) {
        if(std::distance(i -> begin(), i -> end()) > 4) throw std::logic_error("Ilegalan format matrice");
    }
    
    redovi = lista.size();
    auto it = lista.begin();
    kolone = std::distance(it -> begin(), it -> end());
    int i = 0, j = 0;
    while(it != lista.end()) {
        auto k = it -> begin();
        while(k != it -> end()) {
            matrica[i][j] = *k;
            k++;
            j++;
        }
        i++;
        j = 0;
        it++;
    }
}

template<typename T1, typename T2>
auto operator+(const GMatrica<T1> &m1, const GMatrica<T2> &m2) -> GMatrica<decltype(m1.matrica[0][0] + m2.matrica[0][0])> {
    if(m1.DajBrojKolona() != m2.DajBrojKolona() || m1.DajBrojRedova() != m2.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.matrica[0][0] + m2.matrica[0][0])> nova(m1.DajBrojRedova(),m2.DajBrojKolona(),0);
    for(int i = 0; i < m1.DajBrojRedova(); i++) {
        for(int j = 0; j < m1.DajBrojKolona(); j++) 
            nova.matrica[i][j] = m1.matrica[i][j] + m2.matrica[i][j];
    }
    return nova;
}

template<typename T1, typename T2>
auto operator-(const GMatrica<T1> &m1, const GMatrica<T2> &m2) -> GMatrica<decltype(m1.matrica[0][0] - m2.matrica[0][0])> {
    if(m1.DajBrojKolona() != m2.DajBrojKolona() || m1.DajBrojRedova() != m2.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.matrica[0][0] - m2.matrica[0][0])> nova(m1.DajBrojRedova(), m1.DajBrojKolona(), 0);
    for(int i = 0; i < m1.DajBrojRedova(); i++) {
        for(int j = 0; j < m1.DajBrojKolona(); j++) 
            nova.matrica[i][j] = m1.matrica[i][j] - m2.matrica[i][j];
    }
    return nova;
}

template<typename T1, typename T2>
auto operator*(const GMatrica<T1> &m1, const GMatrica<T2> &m2) -> GMatrica<decltype(m1.matrica[0][0] * m2.matrica[0][0])> {
    if(m1.DajBrojKolona() != m2.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.matrica[0][0] * m2.matrica[0][0])> nova(m1.DajBrojRedova(), m2.DajBrojKolona(), 0);
    decltype(m1.matrica[0][0] * m2.matrica[0][0]) p = 0, q = 0;
    for(int i = 0; i < m1.DajBrojRedova(); i++) {
        for(int j = 0; j < m2.DajBrojKolona(); j++) {
            for(int k = 0; k < m1.DajBrojKolona(); k++) {
                p = m1.matrica[i][k];
                q = m2.matrica[k][j];
                nova.matrica[i][j] += p*q;
            }
        }
    }
    return nova;
}

template<typename T1>
auto operator*(const GMatrica<T1> &m1, double broj) -> GMatrica<decltype(m1.matrica[0][0] * broj)> {
    GMatrica<decltype(m1.matrica[0][0] * broj)> nova(m1.DajBrojRedova(), m1.DajBrojKolona(), 0);
    for(int i = 0; i < m1.DajBrojRedova(); i++) {
        for(int j = 0; j < m1.DajBrojKolona(); j++)
            nova.matrica[i][j] = m1.matrica[i][j] * broj;
    }
    return nova;
}

template<typename T2>
auto operator*(double broj, const GMatrica<T2> &m1) -> GMatrica<decltype(broj * m1.matrica[0][0])> {
    GMatrica<decltype(m1.matrica[0][0] * broj)> nova(m1.DajBrojRedova(), m1.DajBrojKolona(), 0);
    for(int i = 0; i < m1.DajBrojRedova(); i++) {
        for(int j = 0; j < m1.DajBrojKolona(); j++)
            nova.matrica[i][j] = m1.matrica[i][j] * broj;
    }
    return nova;
}

template<typename Tip>
template<typename T>
GMatrica<Tip> &GMatrica<Tip>::operator+=(const GMatrica<T> &m2) {
    if(redovi != m2.redovi || kolone != m2.kolone) throw std::domain_error("Nedozvoljena operacija");
    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < kolone; j++) 
            matrica[i][j] += m2.matrica[i][j];
    }
    return *this;
}

template<typename Tip>
template<typename T>
GMatrica<Tip> &GMatrica<Tip>::operator-=(const GMatrica<T> &m2) {
    if(redovi != m2.redovi || kolone != m2.kolone) throw std::domain_error("Nedozvoljena operacija");
    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < kolone; j++)
            matrica[i][j] -= m2.matrica[i][j];
    }
    return *this;
}

template<typename Tip>
template<typename T>
GMatrica<Tip> &GMatrica<Tip>::operator*=(const GMatrica<T> &m2) {
    if(kolone != m2.redovi) throw std::domain_error("Nedozvoljena operacija");
    Tip p = 0, q = 0;
    GMatrica<Tip> nova(*this);
    for(int i = 0; i < redovi; i++)
        for(int j = 0; j < kolone; j++) matrica[i][j] = 0;
    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < m2.kolone; j++) {
            for(int k = 0; k < kolone; k++) {
                p = nova.matrica[i][k];
                q = m2.matrica[k][j];
                matrica[i][j] += p*q;
            }
        }
    }
    return *this;
}

template<typename Tip>
template<typename T>
GMatrica<Tip> &GMatrica<Tip>::operator*=(T broj) {
    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < kolone; j++)
            matrica[i][j] *= broj;
    }
    return *this;
}

template<typename T1, typename T2>
bool operator==(const GMatrica<T1> &m1, const GMatrica<T2> &m2) {
    if(m1.DajBrojKolona() != m2.DajBrojKolona() || m1.DajBrojRedova() != m2.DajBrojRedova()) return false;
    for(int i = 0; i < m1.DajBrojRedova(); i++) {
        for(int j = 0; j < m1.DajBrojKolona(); j++) {
            if(m1.matrica[i][j] != m2.matrica[i][j]) return false;
        }
    }
    return true;
}
template<typename T1, typename T2>
bool operator!=(const GMatrica<T1> &m1, const GMatrica<T2> &m2) {
    return !(m1 == m2);
}

template<typename Tip>
Tip* GMatrica<Tip>::operator[](int i) {
    return matrica[i];
}

template<typename Tip>
const Tip * GMatrica<Tip>::operator[](int i) const{
    return matrica[i];
}

template<typename Tip>
Tip &GMatrica<Tip>::operator()(int i, int j) {
    if(i > redovi || j > kolone || i <= 0 || j <= 0) throw std::range_error("Nedozvoljen indeks");
    return matrica[i-1][j-1];
}

template<typename Tip>
Tip GMatrica<Tip>::operator()(int i, int j) const {
    if(i > redovi || j > kolone || i <= 0 || j <= 0) throw std::range_error("Nedozvoljen indeks");
    return matrica[i-1][j-1];
}

template<typename T>
std::ostream &operator<<(std::ostream &tok, const GMatrica<T> &m) {
    int sirina = tok.width();
    if(sirina < 6) sirina = 6;
    for(int i = 0; i < m.DajBrojRedova(); i++) {
        for(int j = 0; j < m.DajBrojKolona(); j++) {
            tok << std::setw(sirina) << m[i][j];
        }
        tok << std::endl;
    }
    return tok;
}

template<typename T>
std::istream &operator>>(std::istream &tok, GMatrica<T> &m) {
    std::vector<std::vector<T>> nova;
    char znak;
   // int c;
    //T broj;
    bool minus = false;
    tok >> znak;
    if(znak != '[') tok.setstate(std::ios::failbit);
   // int prethodni;
    for(int i = 0; i < 4; i++) {
        std::vector<T> pomocni;
        for(int j = 0; j < 4; j++)  { 
            T broj;
            int c = tok.peek(); 
            if(c == '-') { minus = true; tok >> znak; }
            else if(!std::isdigit(c)) tok.setstate(std::ios::failbit);
            tok >> broj;
            if(minus) { broj *= -1; minus = false; }
            pomocni.push_back(broj);
            tok >> znak;
            /*
            if( (znak == ';' && j < m.kolone-1) || 
                (znak == ',' && j == m.kolone-1) ||
                (znak != ']' && i == m.redovi - 1 && j == m.kolone-1)) tok.setstate(std::ios::failbit);*/
            if(znak == ';' || znak == ']') break;
            if(znak != ',') tok.setstate(std::ios::failbit);
        }
        nova.push_back(pomocni);
        if(znak == ']') break;
    }
    for(int i = 0; i < nova.size(); i++) {
        for(int j = 0; j < nova.size(); j++) {
            if(i == j) continue;
            if(nova[i].size() != nova[j].size()) {
                tok.setstate(std::ios::failbit);
                return tok;
            }
        }
    }
    if(m.redovi != 0 && m.redovi != nova.size()) tok.setstate(std::ios::failbit);
    if(m.kolone != 0 && m.kolone != nova[0].size()) tok.setstate(std::ios::failbit);
    else {
        m.redovi = nova.size();
        m.kolone = nova[0].size();
        for(int i = 0; i < nova.size(); i++) {
            for(int j = 0; j < nova[i].size(); j++) {
                m.matrica[i][j] = nova[i][j];
            }
        }
    }
   /* int r = 0, k = 0;
    int prethodni = k;
    while(1) {
        c = tok.peek();
        if(c == '-') { minus = true; tok >> znak; }
        if(!std::isdigit(c)) tok.setstate(std::ios::failbit);
        tok >> broj;
        if(minus) { broj *= -1; minus = false; }
        m.matrica[r][k] = broj;
        k++;
        c = tok.peek();
        if(c )
        if(c != ',')
    }*/
    return tok;
} 

int main ()
{
    GMatrica<int> m1({{1,2}, {3,4}});
    std::cout << m1(1,1) << std::endl;
    std::cout << m1[1][1] << std::endl;
    
    //GMatrica<int> a({{1,2}, {3,4}});
   // GMatrica<int> b(3,3,1);
    /*GMatrica<int> c({{1,2}, {3,5}});*/
    //std::cout  << "sta.. " << std::endl;
 //   GMatrica<int> a({{1,2}, {3,4}});
   // std::cout << "Unesi: ";
    //std::cin >> a;
  //  std::cout << a.DajBrojRedova() << ", " << a.DajBrojKolona();
    //GMatrica<double> c;
   // a += b;
 //   GMatrica<int> nova = a*2;
    //nova = a*2;
   // std::cout << a;
  //  std::cout << nova;
    //auto nova(a+b);
    /*
    if(a == b && a != c && !(a != b) && !(a != b)) std::cout << "ok";
    else std::cout << "nije ok";
    *//*
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }*/
	return 0;
}
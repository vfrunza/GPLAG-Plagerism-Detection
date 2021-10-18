#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <type_traits>

template<typename Tip> 
class GMatrica {
    Tip mat[4][4];
    int br_redova, br_kolona;
public:
    GMatrica() : br_redova(0), br_kolona(0) {}
    GMatrica(int br_redova, int br_kolona, Tip vrijednost = Tip());
    
    template<typename T> 
    GMatrica(const GMatrica<T> &GM);
    
    template <typename T>
    GMatrica(T mat[4][4]);

    GMatrica(std::vector<std::vector<Tip>> v);
    GMatrica(std::initializer_list<std::initializer_list<Tip>> l);
    
    int DajBrojRedova() const { return br_redova; }
    int DajBrojKolona() const { return br_kolona; }
    
    // Operatori sabiranja
    template<typename T1, typename T2>
    friend auto operator +(const GMatrica<T1> &m1, const GMatrica<T2> &m2)
        -> GMatrica<decltype(m1.mat[0][0] + m2.mat[0][0])>;
        
    template<typename T>
    auto operator +=(const GMatrica<T> &mat2)
        -> GMatrica<decltype(mat[0][0] + mat2.mat[0][0])>&;
    
    // Operatori oduzimanja
        
    template<typename T1, typename T2>
    friend auto operator -(const GMatrica<T1> &m1, const GMatrica<T2> &m2) 
        -> GMatrica<decltype(m1.mat[0][0] + m2.mat[0][0])>;
        
    template<typename T>
    auto operator -=(const GMatrica<T> &m)
        -> GMatrica<decltype(mat[0][0] + m.mat[0][0])>&;
        
    // Operatori mnozenja
    
    template<typename T1, typename T2>
    friend auto operator *(const GMatrica<T1> &m1, const GMatrica<T2> &m2) 
        -> GMatrica<decltype(m1.mat[0][0] + m2.mat[0][0])>;
        
    template<typename T1, typename T2>
    friend auto operator *(const GMatrica<T1> &m, T2 broj)
        -> GMatrica<decltype(m.mat[0][0] + broj)>;
        
    template<typename T1, typename T2>
    friend auto operator *(T1 broj, const GMatrica<T2> &m)
        -> GMatrica<decltype(m.mat[0][0] + broj)>;
        
    template<typename T>
    auto operator *=(const GMatrica<T> &mat2)
        -> GMatrica<decltype(mat[0][0] + mat2.mat[0][0])>&;
        
    template<typename T>
    auto operator *=(T broj)
        -> GMatrica<decltype(mat[0][0] + broj)>&;
        
    // Logicki operatori 
    
    template<typename T1, typename T2>
    friend bool operator ==(const GMatrica<T1> &m1, const GMatrica<T2> &m2);
        
    template<typename T1, typename T2>
    friend bool operator !=(const GMatrica<T1> &m1, const GMatrica<T2> &m2);
    
    // ulazni i izlazni operatori
    
    template<typename T>
    friend std::ostream& operator <<(std::ostream& tok, const GMatrica<T> &m);
    
    template<typename T>
    friend std::istream& operator >>(std::istream& tok, GMatrica<T> &m);
    
    // ostali operatori
    
    Tip& operator ()(int a, int b);
    Tip operator ()(int a, int b) const;
    Tip* operator [](int a); 
};

// KONSTRUKTORI

template<typename Tip> 
GMatrica<Tip>::GMatrica(int br_redova, int br_kolona, Tip vrijednost) {
    if(br_redova < 0 || br_redova > 4 || br_kolona < 0 || br_kolona > 4)
        throw std::logic_error("Ilegalan format matrice");
    GMatrica::br_redova = br_redova;
    GMatrica::br_kolona = br_kolona;
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++) 
            mat[i][j] = vrijednost;
}

template<typename Tip>
template<typename T>
GMatrica<Tip>::GMatrica(const GMatrica<T> &GM) {
    br_redova = GM.br_redova;
    br_kolona = GM.br_kolona;
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++) 
            mat[i][j] = GM.mat[i][j];
}

template<typename Tip>
template<typename T>
GMatrica<Tip>::GMatrica(T mat[4][4]) : br_redova(4), br_kolona(4) {
    for(int i = 0; i < br_redova; i++) 
        for(int j = 0; j < br_kolona; j++) 
            GMatrica::mat[i][j] = mat[i][j];
}

template<typename Tip>
GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip>> v) {
    if(v.size() > 4 || v[0].size() > 4) throw std::logic_error("Ilegalan format matrice");
    
    for(int i = 0; i < v.size(); i++) 
        if(v[0].size() != v[i].size()) 
            throw std::logic_error("Ilegalan format matrice");     

    br_redova = v.size(); br_kolona = v[0].size();
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++) 
            mat[i][j] = v[i][j];
}

template<typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Tip>> l) {
    if(l.size() > 4) throw std::logic_error("Ilegalan format matrice");
    
    for(auto x = l.begin(); x != l.end(); x++)
        if(l.begin()->size() != x->size())
            throw std::logic_error("Ilegalan format matrice");

    br_redova = l.size(); br_kolona = l.begin()->size();
    int i = 0, j = 0;
    for(auto x = l.begin(); x != l.end(); x++, i++) {
        j = 0;
        for(auto y = x->begin(); y != x->end(); y++, j++) {
            mat[i][j] = *y;
        }
    }
}

// Operatori sabiranja

template<typename T1, typename T2>
auto operator +(const GMatrica<T1> &m1, const GMatrica<T2> &m2)
    -> GMatrica<decltype(m1.mat[0][0] + m2.mat[0][0])> {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Nedozvoljena operacija");
    
    GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])> m3(m1.br_redova, m2.br_kolona);
        
    for(int i = 0; i < m1.br_redova; i++) 
        for(int j = 0; j < m2.br_kolona; j++) 
            m3.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
    return m3;
}

template<typename Tip>
template<typename T2>
auto GMatrica<Tip>::operator +=(const GMatrica<T2> &mat2)
    -> GMatrica<decltype(mat[0][0] + mat2.mat[0][0])>& {
    if(br_redova != mat2.br_redova || br_kolona != mat2.br_kolona)
        throw std::domain_error("Nedozvoljena operacija");
        
    for(int i = 0; i < br_redova; i++) 
        for(int j = 0; j < mat2.br_kolona; j++) 
            mat[i][j] += mat2.mat[i][j];
    return *this;
}

// Operatori oduzimanja

template<typename T1, typename T2>
auto operator -(const GMatrica<T1> &m1, const GMatrica<T2> &m2)
    -> GMatrica<decltype(m1.mat[0][0] + m2.mat[0][0])> {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Nedozvoljena operacija");
    
    GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])> m3(m1.br_redova, m2.br_kolona);
        
    for(int i = 0; i < m1.br_redova; i++) 
        for(int j = 0; j < m2.br_kolona; j++) 
            m3.mat[i][j] = m1.mat[i][j] - m2.mat[i][j];
    return m3;
}

template<typename Tip>
template<typename T>
auto GMatrica<Tip>::operator -=(const GMatrica<T> &m)
    -> GMatrica<decltype(mat[0][0] + m.mat[0][0])>& {
    if(br_redova != m.br_redova || br_kolona != m.br_kolona)
        throw std::domain_error("Nedozvoljena operacija");
        
    for(int i = 0; i < br_redova; i++) 
        for(int j = 0; j < m.br_kolona; j++) 
            mat[i][j] -= m.mat[i][j];
    return *this;
            
}

// Operatori mnozenja

template<typename T1, typename T2>
auto operator *(const GMatrica<T1> &m1, const GMatrica<T2> &m2) 
    -> GMatrica<decltype(m1.mat[0][0] + m2.mat[0][0])> {
    if(m1.br_kolona != m2.br_redova)    
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])> mat3(m1.br_redova, m2.br_kolona);
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m2.br_kolona; j++) {
            mat3.mat[i][j] = 0;
            for(int k = 0; k < m1.br_kolona; k++) {
                mat3.mat[i][j] += m1.mat[i][k] * m2.mat[k][j];
            }
        }
    }
    return mat3;
}

template<typename T1, typename T2>
auto operator *(const GMatrica<T1> &m, T2 broj)
    -> GMatrica<decltype(m.mat[0][0] + broj)> {
    GMatrica<decltype(m.mat[0][0]+broj)> mat3(m.br_redova, m.br_kolona);
    for(int i = 0; i < m.br_redova; i++) {
        for(int j = 0; j < m.br_kolona; j++) {
            mat3.mat[i][j] += m.mat[i][j] * broj;
        }
    }
    return mat3;  
}

template<typename T1, typename T2>
auto operator *(T1 broj, const GMatrica<T2> &m)
    -> GMatrica<decltype(m.mat[0][0] + broj)> {
    GMatrica<decltype(m.mat[0][0]+broj)> mat3(m.br_redova, m.br_kolona);
    for(int i = 0; i < m.br_redova; i++) {
        for(int j = 0; j < m.br_kolona; j++) {
            mat3.mat[i][j] += m.mat[i][j] * broj;
        }
    }
    return mat3;  
}

template<typename Tip>
template<typename T>
auto GMatrica<Tip>::operator *=(const GMatrica<T> &mat2)
    -> GMatrica<decltype(mat[0][0] + mat2.mat[0][0])>& {
    if(br_kolona != mat2.br_redova)    
        throw std::domain_error("Nedozvoljena operacija");
    
    GMatrica<decltype(mat[0][0]+mat2.mat[0][0])> mat3(br_redova, mat2.br_kolona, 0);
    
    for(int i = 0; i < br_redova; i++) {
        for(int j = 0; j < mat2.br_kolona; j++) {
            mat3.mat[i][j] = 0;
            for(int k = 0; k < br_kolona; k++) {
                mat3.mat[i][j] += mat[i][k] * mat2.mat[k][j];
            }
        }
    }
    *this = mat3;
    return *this;
}

template<typename Tip>
template<typename T>
auto GMatrica<Tip>::operator *=(T broj) 
    -> GMatrica<decltype(mat[0][0] + broj)>& {
    for(int i = 0; i < br_redova; i++) {
        for(int j = 0; j < br_kolona; j++) {
            mat[i][j] *= broj;
        }
    }
    return *this;  
}

// Logicki operatori

template<typename T1, typename T2>
bool operator ==(const GMatrica<T1> &m1, const GMatrica<T2> &m2) {
    if(m1.br_redova != m2.br_redova || m2.br_kolona != m2.br_kolona)
        return false;
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m1.br_kolona; j++) {
            if(m1.mat[i][j] != m2.mat[i][j]) return false;
        }
    }
    return true;
}

template<typename T1, typename T2>
bool operator !=(const GMatrica<T1> &m1, const GMatrica<T2> &m2) {
    if(m1.br_redova != m2.br_redova || m2.br_kolona != m2.br_kolona)
        return true;
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m1.br_kolona; j++) {
            if(m1.mat[i][j] != m2.mat[i][j]) 
                return true;
        }
    }
    return false;
}

// Ulazni/izlazni operatori

template<typename T>
std::ostream& operator <<(std::ostream &tok, const GMatrica<T> &m) {
    int sirina = tok.width();
    if(sirina < 6) {
        for(int i = 0; i < m.br_redova; i++) {
            for(int j = 0; j < m.br_kolona; j++) {
                tok << std::setw(6) << m.mat[i][j];
            }
            tok << std::endl;
        }
    }
    else {
        for(int i = 0; i < m.br_redova; i++) {
            for(int j = 0; j < m.br_kolona; j++) {
                tok << std::setw(sirina) << m.mat[i][j];
            }
            tok << std::endl;
        }  
    }
    return tok;
}

template<typename T>
std::istream& operator >>(std::istream& tok, GMatrica<T> &m) {
    std::vector<std::vector<T>> mtr;
    std::vector<T> pomocni, prazan;
    char znak;
    tok >> znak;
    if(znak != '[') {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    while(true) {
        T temp;
        tok >> temp >> znak;
        pomocni.push_back(temp);
        if(znak == ',') continue; 
        else if(znak == ';') {
            mtr.push_back(pomocni);
            pomocni = prazan;
        }
        else if(znak == ']') {
            mtr.push_back(pomocni);
            break;
        }
        else {
            tok.setstate(std::ios::failbit);
            return tok;
        }
    }
    // provjera ispravnosti redova i kolona
    if(mtr[0].size() > 4 || mtr.size() > 4) {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    int vel = mtr[0].size();
    for(auto &x : mtr) {
        if(x.size() != vel) {
            tok.setstate(std::ios::failbit);
            return tok;
        }
    }
    // kopiranje vectora mtr u glavni 2D niz
    m.br_redova = mtr.size(); m.br_kolona = mtr[0].size();
    for(int i = 0; i < m.br_redova; i++) {
        for(int j = 0; j < m.br_kolona; j++) {
            m.mat[i][j] = mtr[i][j];
        }
    }
    return tok;
}

// Ostali operatori

template<typename Tip>
Tip& GMatrica<Tip>::operator ()(int i, int j) {
    if(i > br_redova  || j > br_kolona || i < 1 || j < 1)
        throw std::range_error("Nedozvoljen indeks");
    return mat[i-1][j-1];
}

template<typename Tip>
Tip GMatrica<Tip>::operator ()(int i, int j) const {
    if(i > br_redova  || j > br_kolona || i < 1 || j < 1)
        throw std::range_error("Nedozvoljen indeks");
    return mat[i-1][j-1];
}

template<typename Tip>
Tip* GMatrica<Tip>::operator [](int i) {
    return mat[i];
}

int main() {
    GMatrica<int> m1, m2;
    std::cout << "Unesite 1. matricu: "; std::cin >> m1;
    std::cout << "Unesite 2. matricu: "; std::cin >> m2;
    
    std::cout << "operator + \n" << m1 + m2;
    std::cout << "operator - \n" << m1 - m2;
    std::cout << "operator * \n" << m1 * m2;
    
    std::cout << "Matrice pomnozene sa 2\n";
    std::cout << "mat1 * 2\n" << m1 * 2;
    std::cout << "2 * mat2\n" << 2 * m2;
    
    std::cout << "operator += \n";
    m1 += m2;
    std::cout << m1;
    std::cout << "operator -= \n";
    m1 -= m2;
    std::cout << m1;
    std::cout << "operator *= \n";
    m1 *= m2;
    std::cout << m1;
    
    std::cout << "operator == : " << std::boolalpha << (m1 == m2) << std::endl;
    std::cout << "operator != : " << std::boolalpha << (m1 != m2) << std::endl;
    
    std::cout << "operator () (1,1)(mat1): " << m1(1,1) << std::endl;
    std::cout << "operator [] [0][0](mat2): " << m2[0][0] << std::endl;
    return 0;
}
/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <iomanip>
using namespace std;

template <typename Tip>
class GMatrica {
    int redovi, kolone;
    Tip matrica[4][4];  
    public:
    GMatrica();
    GMatrica(int redovi, int kolone, Tip element = Tip());
    template <typename Tip2>
    GMatrica(const GMatrica<Tip2> &mat);
    template <typename Tip2>
    GMatrica(Tip2 mat[4][4]);
    GMatrica(const vector<vector<Tip>> &vektor);
    GMatrica(const initializer_list<initializer_list<Tip>> &mat);
    int DajBrojRedova() const {
        return redovi;
    }
    int DajBrojKolona() const {
        return kolone;
    }
    
    template <typename Tip2>
    GMatrica<Tip> &operator +=(const GMatrica<Tip2> &mat);
    
    template <typename Tip2>
    GMatrica<Tip> &operator -=(const GMatrica<Tip2> &mat);
    
    template <typename Tip2>
    GMatrica<Tip> &operator *=(const GMatrica<Tip2> &mat);
    
    template<typename Tip2>
    GMatrica<Tip> &operator *=(Tip2 broj);
    
    Tip &operator ()(int i, int j);
    Tip operator ()(int i, int j) const;
    
    Tip *operator [](int i);
    
    template<typename Tip1, typename Tip2>
    friend auto operator +(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<typename remove_reference<decltype(Tip1() + Tip2())>::type>;
    
    template<typename Tip1, typename Tip2>
    friend auto operator -(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<typename remove_reference<decltype(Tip1() - Tip2())>::type>;
    
    template<typename Tip1, typename Tip2>
    friend auto operator *(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<typename remove_reference<decltype(Tip1() * Tip2())>::type>;

    template<typename Tip1>
    friend bool operator ==(const GMatrica<Tip1> &m1, const GMatrica<Tip1> &m2);
    
    template<typename Tip1>
    friend bool operator !=(const GMatrica<Tip1> &m1, const GMatrica<Tip1> &m2);
    
    template<typename Tip1, typename Tip2>
    friend auto operator *(const GMatrica<Tip1> &m1, Tip2 broj) -> GMatrica<typename remove_reference<decltype(Tip1() * Tip2())>::type>;
    
    template<typename Tip1, typename Tip2>
    friend auto operator *(Tip1 broj, const GMatrica<Tip2> &m1) -> GMatrica<typename remove_reference<decltype(Tip1() * Tip2())>::type>;
    
    template<typename Tip1>
    friend ostream &operator <<(ostream &tok, const GMatrica<Tip1> &m);
    
    template<typename Tip1>
    friend istream &operator >>(istream &tok, GMatrica<Tip1> &m);
    
};

template <typename Tip>
GMatrica<Tip>::GMatrica() : redovi(0), kolone(0) {
    
}

template <typename Tip>
GMatrica<Tip>::GMatrica(int redovi, int kolone, Tip element) : redovi(redovi), kolone(kolone) {
    if(redovi < 0 || redovi > 4 || kolone < 0 || kolone > 4) {
        throw logic_error("Ilegalan format matrice");
    }
    for(int i=0; i < redovi; i++) {
        for(int j=0; j<kolone; j++) {
            matrica[i][j] = element;
        }
    }
}

template <typename Tip>
template <typename Tip2>
GMatrica<Tip>::GMatrica(const GMatrica<Tip2> &mat) : redovi(mat.DajBrojRedova()), kolone(mat.DajBrojKolona()) {
    for(int i=0; i < redovi; i++) {
        for(int j=0; j<kolone; j++) {
            matrica[i][j] = mat(i+1,j+1);
        }
    }
}

template <typename Tip>
template <typename Tip2>
GMatrica<Tip>::GMatrica(Tip2 mat[4][4]) : redovi(4), kolone(4) {
    for(int i=0; i<redovi; i++) {
        for(int j=0; j<kolone; j++) {
            matrica[i][j] = mat[i][j];
        }
    }
}

template <typename Tip>
GMatrica<Tip>::GMatrica(const vector<vector<Tip>> &vektor) : redovi(vektor.size()) {
    if(redovi > 0) {
        kolone = vektor[0].size();
    }
    if(redovi < 0 || redovi > 4 || kolone < 0 || kolone > 4) {
        throw logic_error("Ilegalan format matrice");
    }
    for(int i=1; i < vektor.size(); i++) {
        if(vektor[0].size() != vektor[i].size()) {
            throw logic_error("Ilegalan format matrice");
        }
    }
    for(int i=0; i < vektor.size(); i++) {
        for(int j=0; j<vektor[i].size(); j++) {
            matrica[i][j] = vektor[i][j];
        }
    }
}

template <typename Tip>
GMatrica<Tip>::GMatrica(const initializer_list<initializer_list<Tip>> &lista) {
    vector<vector<Tip>> mat;
    for(initializer_list<Tip> red : lista) {
        vector<Tip> temp;
        for(Tip e : red) {
            temp.push_back(e);
        }
        mat.push_back(temp);
    }
    redovi = mat.size();
    if(redovi > 0) {
        kolone = mat[0].size();
    }
    if(redovi < 0 || redovi > 4 || kolone < 0 || kolone > 4) {
        throw logic_error("Ilegalan format matrice");
    }
    for(int i=1; i < mat.size(); i++) {
        if(mat[0].size() != mat[i].size()) {
            throw logic_error("Ilegalan format matrice");
        }
    }
    for(int i=0; i < mat.size(); i++) {
        for(int j=0; j < mat[i].size(); j++) {
            matrica[i][j] = mat[i][j];
        }
    }
}

template<typename Tip>
Tip* GMatrica<Tip>::operator [](int i) {
    return matrica[i];
}

template<typename Tip1, typename Tip2>
auto operator +(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<typename remove_reference<decltype(Tip1() + Tip2())>::type> {
    if(m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona()) {
        throw domain_error("Nedozvoljena operacija");
    }
    GMatrica<typename remove_reference<decltype(Tip1() + Tip2())>::type> temp(m1);
    for(int i=0; i < m2.DajBrojRedova(); i++) {
        for(int j=0; j < m2.DajBrojKolona(); j++) {
            temp.matrica[i][j] += m2.matrica[i][j];
        }
    }
    return temp;
}

template<typename Tip1, typename Tip2>
auto operator -(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<typename remove_reference<decltype(Tip1() - Tip2())>::type> {
    if(m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona()) {
        throw domain_error("Nedozvoljena operacija");
    }
    GMatrica<typename remove_reference<decltype(Tip1() - Tip2())>::type> temp(m1);
    for(int i=0; i < m2.DajBrojRedova(); i++) {
        for(int j=0; j < m2.DajBrojKolona(); j++) {
            temp.matrica[i][j] -= m2.matrica[i][j];
        }
    }
    return temp;
}

template<typename Tip1, typename Tip2>
auto operator *(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2) -> GMatrica<typename remove_reference<decltype(Tip1() * Tip2())>::type> {
    if(m1.DajBrojKolona() != m2.DajBrojRedova()) {
        throw domain_error("Nedozvoljena operacija");
    }
    GMatrica<typename remove_reference<decltype(Tip1() * Tip2())>::type> temp(m1.DajBrojRedova(), m2.DajBrojKolona());
    for(int i=0; i < m1.DajBrojRedova(); i++) {
        for(int j=0; j < m2.DajBrojKolona(); j++) {
            for(int k=0; k < m1.DajBrojKolona(); k++) {
                temp.matrica[i][j] += m1.matrica[i][k] * m2.matrica[k][j];
            }
        }
    }
    return temp;
}

template<typename Tip1, typename Tip2>
auto operator *(const GMatrica<Tip1> &m1, Tip2 broj) -> GMatrica<typename remove_reference<decltype(Tip1() * Tip2())>::type> {
    GMatrica<typename remove_reference<decltype(Tip1() * Tip2())>::type> temp(m1);
    for(int i=0; i < m1.DajBrojRedova(); i++) {
        for(int j=0; j < m1.DajBrojKolona(); j++) {
            temp.matrica[i][j] *= broj;
        }
    }
    return temp;
}

template<typename Tip1, typename Tip2>
auto operator *(Tip1 broj, const GMatrica<Tip2> &m1) -> GMatrica<typename remove_reference<decltype(Tip1() * Tip2())>::type> {
    GMatrica<typename remove_reference<decltype(Tip1() * Tip2())>::type> temp(m1);
    for(int i=0; i < m1.DajBrojRedova(); i++) {
        for(int j=0; j < m1.DajBrojKolona(); j++) {
            temp.matrica[i][j] *= broj;
        }
    }
    return temp;
}

template<typename Tip>
template<typename Tip2>
GMatrica<Tip>& GMatrica<Tip>::operator +=(const GMatrica<Tip2> &mat) {
    if(DajBrojRedova() != mat.DajBrojRedova() || DajBrojKolona() != mat.DajBrojKolona()) {
        throw domain_error("Nedozvoljena operacija");
    }
    for(int i=0; i < mat.DajBrojRedova(); i++) {
        for(int j=0; j < mat.DajBrojKolona(); j++) {
            matrica[i][j] += mat(i+1,j+1);
        }
    }
    return *this;
}

template<typename Tip>
template<typename Tip2>
GMatrica<Tip>& GMatrica<Tip>::operator -=(const GMatrica<Tip2> &mat) {
    if(DajBrojRedova() != mat.DajBrojRedova() || DajBrojKolona() != mat.DajBrojKolona()) {
        throw domain_error("Nedozvoljena operacija");
    }
    for(int i=0; i < mat.DajBrojRedova(); i++) {
        for(int j=0; j < mat.DajBrojKolona(); j++) {
            matrica[i][j] -= mat(i+1,j+1);
        }
    }
    return *this;
}

template<typename Tip>
template<typename Tip2>
GMatrica<Tip>& GMatrica<Tip>::operator *=(const GMatrica<Tip2> &mat) {
    if(DajBrojKolona() != mat.DajBrojRedova() || DajBrojKolona() != mat.DajBrojKolona()) {
        throw domain_error("Nedozvoljena operacija");
    }
    for(int i=0; i < DajBrojRedova(); i++) {
        for(int j=0; j < DajBrojKolona(); j++) {
            for(int k=0; k < DajBrojKolona(); k++) {
                matrica[i][j] += matrica[i][k] * mat(i+1,k+1);
            }
        }
    }
    return *this;
}

template<typename Tip>
template<typename Tip2>
GMatrica<Tip>& GMatrica<Tip>::operator *=(Tip2 broj) {
    for(int i=0; i < DajBrojRedova(); i++) {
        for(int j=0; j < DajBrojKolona(); j++) {
            matrica[i][j] *= broj;
        }
    }
    return *this;
}

template<typename Tip1>
bool operator ==(const GMatrica<Tip1> &m1, const GMatrica<Tip1> &m2) {
    if(m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona()) {
        return false;
    }
    for(int i=0; i < m1.DajBrojRedova(); i++) {
        for(int j=0; j < m1.DajBrojKolona(); j++) {
            if(m1.matrica[i][j] != m2.matrica[i][j]) {
                return false;
            }
        }
    }
    return true;
}

template <typename Tip1>
bool operator !=(const GMatrica<Tip1> &m1, const GMatrica<Tip1> &m2) {
    if(m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona()) {
        return true;
    }
    for(int i=0; i < m1.DajBrojRedova(); i++) {
        for(int j=0; j < m1.DajBrojKolona(); j++) {
            if(m1.matrica[i][j] != m2.matrica[i][j]) {
                return true;
            }
        }
    }
    return false;
}

template<typename Tip>
Tip& GMatrica<Tip>::operator ()(int i, int j) {
    if(i < 1 || i > redovi || j < 1 || j > kolone) {
        throw range_error("Nedozvoljen indeks");
    }
    return matrica[i-1][j-1];
}

template<typename Tip>
Tip GMatrica<Tip>::operator ()(int i, int j) const {
    if(i < 1 || i > redovi || j < 1 || j > kolone) {
        throw range_error("Nedozvoljen indeks");
    }
    return matrica[i-1][j-1];
}

template<typename Tip1>
ostream &operator <<(ostream &tok, const GMatrica<Tip1> &m) {
    int sirina(tok.width());
    if(sirina < 6) {
        sirina = 6;
    }
    for(int i=0; i < m.DajBrojRedova(); i++) {
        for(int j=0; j < m.DajBrojKolona(); j++) {
            tok << setw(sirina) << m.matrica[i][j];
        }
        tok << endl;
    }
    return tok;
}

template<typename Tip1>
istream &operator >>(istream &tok, GMatrica<Tip1> &m) {
    char znak;
    tok >> znak;
    vector<vector<Tip1>> vektor(1,vector<Tip1>());
    if(znak == '[') {
        Tip1 element;
        int i(0);
        do {
            tok >> element >> znak;
            vektor[i].push_back(element);
            if(znak == ';') {
                i++;
                vektor.push_back(vector<Tip1>());
            } else if(znak == ',') {
                continue;
            } else if(znak == ']') {
                break;
            } else {
                tok.setstate(ios::failbit);
                return tok;
            }
        }while(znak != ']');
    } else {
        tok.setstate(ios::failbit);
        return tok;
    }
    m = GMatrica<Tip1>(vektor);
    return tok;
}

int main() {
    //orbob
    GMatrica<int> m1({{1, 2}, {3, 4}});
    GMatrica<double> m2{{2,3},{3,3}};
    cout << m1 + m2 << endl;
    cout << m1 - m2 << endl;
    cout << m1 * m2 << endl;
    GMatrica<int> m3(m1 *= 3);
    cout << m1(1,1) << endl;
    cout << m1[1][1] << endl;
    cout << m3 << endl;
    GMatrica<double> m4(m3);
    m4 *= m3;
    m3 += m2;
    m1 -= m3;
    m1 = m3;
    if(m1 != m3) {
        cout << "Nisu jednaki" << endl;
    } else if(m1 == m3) {
        cout << "Jednaki su" << endl;
    }
    m4 *= 3;
    cout << m4 << endl;
    return 0;
}
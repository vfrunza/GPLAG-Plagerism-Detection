#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <iomanip>
#include <initializer_list>

template<typename Tip>
class GMatrica {
    int br_redova, br_kolona;
    Tip pok[4][4];
public:
    GMatrica();
    GMatrica(int br_redova, int br_kolona, Tip n = Tip());
    template<typename Tip2>
    GMatrica(const GMatrica<Tip2> &m1);
    template<typename Tip2>
    GMatrica(Tip2 mat[4][4]);
    GMatrica(const std::vector<std::vector<Tip>> &v);
    GMatrica(std::initializer_list<std::initializer_list<Tip>> l);
    int DajBrojRedova() const { return br_redova; }
    int DajBrojKolona() const { return br_kolona; }
    //operatori funkcije clanice
    template<typename Tip2>
    GMatrica &operator +=(const GMatrica<Tip2> &m1); 
    template<typename Tip2>
    GMatrica &operator -=(const GMatrica<Tip2> &m1); 
    template<typename Tip2>
    GMatrica &operator *=(Tip2 n); 
    template<typename Tip2>
    GMatrica<Tip> &operator *=(const GMatrica<Tip2> &m1);
    Tip &operator ()(int red, int kol);
    Tip operator ()(int red, int kol) const;
    Tip operator [](int n) const;
    Tip *operator [](int n);
    //friend operatori
    template<typename Tip2, typename Tip3>
    friend auto operator +(const GMatrica<Tip2> &m1, const GMatrica<Tip3> &m2) -> GMatrica<decltype(m1.pok[0][0] + m2.pok[0][0])>;
    template<typename Tip2, typename Tip3>
    friend auto operator -(const GMatrica<Tip2> &m1, const GMatrica<Tip3> &m2) -> GMatrica<decltype(m1.pok[0][0] - m2.pok[0][0])>;
    template<typename Tip2, typename Tip3>
    friend auto operator *(const GMatrica<Tip2> &m1, const GMatrica<Tip3> &m2) -> GMatrica<decltype(m1.pok[0][0] * m2.pok[0][0])>;
    template<typename Tip2, typename Tip3>
    friend auto operator *(const GMatrica<Tip2> &m1, Tip3 n) -> GMatrica<decltype(m1.pok[0][0] * n)>;
    template<typename Tip2, typename Tip3>
    friend auto operator *(Tip3 n, const GMatrica<Tip2> &m1) -> GMatrica<decltype(n * m1.pok[0][0])>;
    template<typename Tip2>
    friend std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip2> &m);
    template<typename Tip2>
    friend std::istream &operator >>(std::istream &tok, GMatrica<Tip2> &m);
    template<typename Tip2>
    friend bool operator ==(const GMatrica<Tip2> &m1, const GMatrica<Tip2> &m2);
    template<typename Tip2>
    friend bool operator !=(const GMatrica<Tip2> &m1, const GMatrica<Tip2> &m2);
};
template<typename Tip>
GMatrica<Tip>::GMatrica() : br_redova(0), br_kolona(0) {}
template<typename Tip>
GMatrica<Tip>::GMatrica(int br_r, int br_k, Tip n) {
    if(br_r > 4 || br_r < 0 || br_k > 4 || br_k < 0)
        throw std::logic_error("Ilegalan format matrice");
    br_redova = br_r; br_kolona = br_k; 
        for(int i=0; i<br_redova; i++)
            for(int j=0; j<br_kolona; j++)
                pok[i][j] = n;
}
template<typename Tip>
template<typename Tip2>
GMatrica<Tip>::GMatrica(const GMatrica<Tip2> &m1) {
    if(m1.DajBrojRedova() > 4 || m1.DajBrojRedova() < 0 || m1.DajBrojKolona() > 4 || m1.DajBrojKolona() < 0)
        throw std::logic_error("Ilegalan format matrice");
    br_redova = m1.DajBrojRedova(); br_kolona = m1.DajBrojKolona(); 
        for(int i=0; i<br_redova; i++)
            for(int j=0; j<br_kolona; j++) 
                pok[i][j] = m1(i+1, j+1);
}
template<typename Tip>
template<typename Tip2>
GMatrica<Tip>::GMatrica(Tip2 mat[4][4]) {
    br_redova = 4; br_kolona = 4;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            pok[i][j] = mat[i][j];
}
template<typename Tip>
GMatrica<Tip>::GMatrica(const std::vector<std::vector<Tip>> &v) {
    if(v.size() == 0) return;
    if(v.size() != 0 && v.size() > 4)
        throw std::logic_error("Ilegalan format matrice");
    for(int i=0; i<v.size(); i++)
        for(int j=0; j<v.size(); j++)
            if(v[i].size() != v[j].size()) throw std::logic_error("Ilegalan format matrice");
    br_redova = v.size(); br_kolona = v[0].size();
    for(int i=0; i<v.size(); i++)
        for(int j=0; j<v.size(); j++)
            pok[i][j] = v[i][j];
}
template<typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Tip>> l) {
    if(l.size() == 0) return;
    if(l.size() != 0 && l.size() > 4)
        throw std::logic_error("Ilegalan format matrice");
    for(auto red: l)
        for(auto red2 : l)
            if(red.size() != red2.size()) throw std::logic_error("Ilegalan format matrice");
    br_redova = l.size(); br_kolona = l.begin()->size();
    int i(0), j(0);
    for(auto red : l) {
        for(auto el: red) {
            pok[i][j] = el;
            j++;
        }
        j = 0; i++;
    }
}
template<typename Tip, typename Tip2>
auto operator +(const GMatrica<Tip> &m1, const GMatrica<Tip2> &m2) -> GMatrica<decltype(m1.pok[0][0] + m2.pok[0][0])> {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) 
        throw std::domain_error("Nedozvoljena operacija");
    try {
        GMatrica<decltype(m1.pok[0][0] + m2.pok[0][0])> m(m1.br_redova, m1.br_kolona);
        for(int i=0; i<m1.br_redova; i++)
            for(int j=0; j<m1.br_kolona; j++)
                m.pok[i][j] = m1.pok[i][j] + m2.pok[i][j];
        return m;
    }
    catch(...) {
        throw std::domain_error("Nedozvoljena operacija");
    }
}
template<typename Tip, typename Tip2>
auto operator -(const GMatrica<Tip> &m1, const GMatrica<Tip2> &m2) -> GMatrica<decltype(m1.pok[0][0] - m2.pok[0][0])> {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) 
        throw std::domain_error("Nedozvoljena operacija");
    try {
        GMatrica<decltype(m1.pok[0][0] - m2.pok[0][0])> m(m1.br_redova, m1.br_kolona);
        for(int i=0; i<m1.br_redova; i++)
            for(int j=0; j<m1.br_kolona; j++)
                m.pok[i][j] = m1.pok[i][j] - m2.pok[i][j];
        return m;
    }
    catch(...) {
        throw std::domain_error("Nedozvoljena operacija");
    }
}
template<typename Tip, typename Tip2>
auto operator *(const GMatrica<Tip> &m1, const GMatrica<Tip2> &m2) -> GMatrica<decltype(m1.pok[0][0] * m2.pok[0][0])> {
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Nedozvoljena operacija");
    try {
        GMatrica<decltype(m1.pok[0][0] * m2.pok[0][0])> m(m1.br_redova, m2.br_kolona);
        for(int i=0; i<m1.br_redova; i++)
            for(int j=0; j<m2.br_kolona; j++)
                for(int k=0; k<m1.br_kolona; k++)
                    m.pok[i][j] += m1.pok[i][k] * m2.pok[k][j];
        return m;
    }
    catch(...) {
        throw std::domain_error("Nedozvoljena operacija");
    }
}
template<typename Tip, typename Tip2>
auto operator *(const GMatrica<Tip> &m1, Tip2 n) -> GMatrica<decltype(m1.pok[0][0] * n)> {
    try {
        GMatrica<decltype(m1.pok[0][0] * n)> m(m1.br_redova, m1.br_kolona);
        for(int i=0; i<m1.br_redova; i++)
            for(int j=0; j<m1.br_kolona; j++)
                m.pok[i][j] = m1.pok[i][j] * n;
        return m;
    }
    catch(...) {
        throw std::domain_error("Nedozvoljena operacija");
    }
}
template<typename Tip, typename Tip2>
auto operator *(Tip2 n, const GMatrica<Tip> &m1) -> GMatrica<decltype(n * m1.pok[0][0])> {
    try {
        GMatrica<decltype(m1.pok[0][0] * n)> m(m1.br_redova, m1.br_kolona);
        m = m1 * n;
        return m;
    }
    catch(...) {
        throw std::domain_error("Nedozvoljena operacija");
    }
} 
template<typename Tip>
Tip &GMatrica<Tip>::operator ()(int red, int kol) {
    if(red < 1 || red > 4 || kol < 1 || kol > 4)
        throw std::range_error("Nedozvoljen indeks");
    return pok[red-1][kol-1];
}
template<typename Tip>
Tip GMatrica<Tip>::operator ()(int red, int kol) const {
    if(red < 1 || red > 4 || kol < 1 || kol > 4)
        throw std::range_error("Nedozvoljen indeks");
    return pok[red-1][kol-1];
}
template<typename Tip>
Tip *GMatrica<Tip>::operator [](int n) {
    return &pok[n][0];
}
template<typename Tip>
Tip GMatrica<Tip>::operator [](int n) const {
    return pok[n];
}
template<typename Tip>
std::istream &operator >>(std::istream &tok, GMatrica<Tip> &m1) {
    GMatrica<Tip> m;
    m.br_kolona++; m.br_redova++;
    char zagrada;
    tok >> zagrada;
    if(zagrada != '[') {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    for(int i=0; i<m.br_redova; i++) {
        bool novi_red(false);
        if(m.br_redova > 4) {
            tok.setstate(std::ios::failbit);
        return tok;
        }
        for(int j=0; j<m.br_kolona; j++) {
            if(m.br_kolona > 4) {
                tok.setstate(std::ios::failbit);
                return tok;
            }
            char znak;
            tok >> m.pok[i][j] >> znak;
            if(znak == ';') { novi_red = true; break;}
            else if(znak == ',') {
                if(i == 0) m.br_kolona++;
                else continue;
            }
            else if(znak == ']') break;
            else {
                tok.setstate(std::ios::failbit);
                return tok;
            }
        }
        if(novi_red) m.br_redova++;
    }
    if(m1.br_redova != 0 && m1.br_kolona != 0 && (m1.br_redova != m.br_redova || m1.br_kolona != m.br_kolona)) {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    else m1 = m;
    return tok;
}
template<typename Tip>
std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip> &m) {
    int sirina(std::cout.width());
    if(sirina < 6) sirina = 6;
    for(int i=0; i<m.br_redova; i++) {
        for(int j=0; j<m.br_kolona; j++)
            tok << std::setw(sirina) << m.pok[i][j];
        tok << std::endl;
    }
    return tok;
}
template<typename Tip>
template<typename Tip2>
GMatrica<Tip> &GMatrica<Tip>::operator +=(const GMatrica<Tip2> &m1) {
    if(m1.DajBrojRedova() != br_redova || m1.DajBrojKolona() != br_kolona) 
        throw std::domain_error("Nedozvoljena operacija");
    try {
        for(int i=0; i<m1.DajBrojRedova(); i++)
            for(int j=0; j<m1.DajBrojKolona(); j++)
                pok[i][j] += m1(i+1,j+1);
        return *this;
    }
    catch(...) {
        throw std::domain_error("Nedozvoljena operacija");
    }
}
template<typename Tip>
template<typename Tip2>
GMatrica<Tip> &GMatrica<Tip>::operator -=(const GMatrica<Tip2> &m1) {
    if(m1.DajBrojRedova() != br_redova || m1.DajBrojKolona()!= br_kolona) 
        throw std::domain_error("Nedozvoljena operacija");
    try {
        for(int i=0; i<m1.br_redova; i++)
            for(int j=0; j<m1.br_kolona; j++)
                pok[i][j] -= m1(i+1,j+1);
        return *this;
    }
    catch(...) {
        throw std::domain_error("Nedozvoljena operacija");
    }
}
template<typename Tip>
template<typename Tip2>
GMatrica<Tip> &GMatrica<Tip>::operator *=(Tip2 n) {
    try {
        for(int i=0; i<br_redova; i++)
            for(int j=0; j<br_kolona; j++)
                    pok[i][j] *= n;
        return *this;
    }
    catch(...) {
        throw std::domain_error("Nedozvoljena operacija");
    }
}
template<typename Tip>
template<typename Tip2>
GMatrica<Tip> &GMatrica<Tip>::operator *=(const GMatrica<Tip2> &m1) {
    if(br_kolona != m1.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    try {
        GMatrica<Tip> m(br_redova, m1.DajBrojKolona());
        for(int i=0; i<br_redova; i++)
            for(int j=0; j<m1.DajBrojKolona(); j++)
                for(int k=0; k<br_kolona; k++)
                    m.pok[i][j] += pok[i][k] * m1(k+1, j+1);
        *this = m;
        return *this;
    }
    catch(...) {
        throw std::domain_error("Nedozvoljena operacija");
    }
}
template<typename Tip>
bool operator ==(const GMatrica<Tip> &m1, const GMatrica<Tip> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) return false;
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            if(m1.pok[i][j] != m2.pok[i][j]) return false;
    return true;
}
template<typename Tip>
bool operator !=(const GMatrica<Tip> &m1, const GMatrica<Tip> &m2) {
    return !(m1 == m2);
}
int main () {
    //Testiranje konstruktora sa 3 parametra
    int br_r, br_k;
    std::cout << "Unesite broj redova i kolona matrice: " << std::endl;
    try {
       std::cin >> br_r >> br_k;
    //Testiranje unosa matrice
        GMatrica<double> m1(br_r, br_k);
        std::cout << "Unesite elemente matrice: " << std::endl;
        std::cin >> m1;
        std::cout << m1;
        if(!std::cin) throw "Neispravan unos"; 
    //Testiranje unosa 0x0 i konstruktora bez parametara
        GMatrica<int> m2;
        std::cout << "Unesite elemente matrice: " << std::endl;
        std::cin >> m2;
        if(!std::cin) throw "Neispravan unos";
        std::cout << m2; 
    //Testiranje konstruktora kopije i dodjele (razliciti tipovi)
        GMatrica<int> mint{{1,2,3},{4,5,6}};
        GMatrica<double> mdoub(mint);
        std::cout << "Original: \n" << mint << "Kopija: \n" << mdoub << std::endl;
    //Covski konstruktor
    int niz[4][4] = {{1,2,3,4},{3,4,5,6},{5,6,8,8},{7,8,8,8}};
    GMatrica<double> Cmat(niz);
    std::cout << Cmat << std::endl;
    //vector vector u gmatricu i da moze primiti inic listu
    std::vector<std::vector<double>> vint{{1,2},{3,3},{4,4}};
    Cmat = vint;
    std::cout << Cmat << std::endl;
    GMatrica<double> mk({{1,2}, {3,5}});
    std::cout << mk << std::endl;
    //sekvencijski
    GMatrica<std::string> s{{"A"}, {"B"}, {"C"}}, s1{{"A"}, {"B"}, {"C"}};
    std::cout << s;
    GMatrica<double> m4{{1,2},{3,5}}, m5{{1,1},{0,1}};
    //operator == i !=
    if(mk == m4 && s == s1) std::cout << "jednaki" << std::endl;
    if(mk != m5) std::cout << "razliciti" << std::endl;
    //operator +, -, *
    Cmat = m4 + m5; m5 = m4 - mk;
    m4 = m4 * m5;
    std::cout << Cmat << std::endl << m4 << std::endl << m5 << std::endl << mk << std::endl;
    //operator +=, -=, *=
    int x(2); mk *= x; m4 += mk; m5 -= m4;
    GMatrica<double> mat1{{1,1},{1,1}};
    GMatrica<int> mat2{{1,1},{0,0}};
    mat2 *= mat1;
    std::cout << mk << std::endl << m4 << std::endl << m5 << std::endl << std::endl << mat2 << std::endl;
    std::cout << mat2[0][1] << " " << mat2(1,2);
    }
    catch(std::logic_error e) {
        std::cout << e.what() << std::endl;
    }
    catch(std::domain_error e) {
        std::cout << e.what() << std::endl;
    }
    catch(std::range_error e) {
        std::cout << e.what() << std::endl;
    }
    catch(const char e[]) {
        std::cout << e << std::endl;
    }
    catch(...) {}
	return 0;
}
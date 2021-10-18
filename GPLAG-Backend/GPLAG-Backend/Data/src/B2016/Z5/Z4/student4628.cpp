/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

template <typename Tip>
class GMatrica {
    Tip mat[4][4];
    int br_redova, br_kolona;
public:
    GMatrica();
    GMatrica(int redovi, int kolone, Tip vrijednost = 0);
    template <typename Tip2>
    GMatrica(GMatrica<Tip2> m) {
        for(int i = 0; i < br_redova; i++)
            for(int j = 0; j < br_kolona; j++)
                mat[i][j] = m[i][j];
    }
    GMatrica(Tip m[4][4]);
    GMatrica(std::vector<std::vector<Tip>> v);
    GMatrica(std::initializer_list<std::initializer_list<Tip>> lista);
    
    int DajBrojRedova() { return br_redova; }
    int DajBrojKolona() { return br_kolona; }
    GMatrica<Tip> &operator +=(const GMatrica<Tip> &m2);
    GMatrica<Tip> &operator -=(const GMatrica<Tip> &m2);
    GMatrica<Tip> &operator *=(Tip br);
    Tip *operator [](int index) const{
        return mat[index];
    }
    Tip *&operator [](int index) {
        return mat[index];
    }
    Tip &operator()(int i, int j) const{
        if(i <= 0 || i > br_redova || j <= 0 || j > br_kolona) throw std::range_error("Nedozvoljen indeks");
        return mat[i - 1][j - 1];
    }
    Tip operator()(int i, int j) {
        if(i <= 0 || i > br_redova || j <= 0 || j > br_kolona) throw std::range_error("Nedozvoljen indeks");
        return mat[i - 1][j - 1];
    }
    
    template<typename Tip2>
    friend GMatrica<Tip2> operator +(const GMatrica<Tip2> &m1, const GMatrica<Tip2> &m2);//-> GMatrica<decltype(m1[0][0] + m2[0][0])>;
    template<typename Tip2>
    friend GMatrica<Tip2> operator -(const GMatrica<Tip2> &m1, const GMatrica<Tip2> &m2);//-> GMatrica<decltype(m1[0][0] - m2[0][0])>;
    template<typename Tip2>
    friend GMatrica<Tip2> operator *(const GMatrica<Tip2> &m1, const GMatrica<Tip2> &m2);//-> GMatrica<decltype(m1[0][0] * m2[0][0])>;
    template<typename Tip2>
    friend GMatrica<Tip2> operator *(const GMatrica<Tip2> &m1, Tip2 br);
    template<typename Tip2>
    friend GMatrica<Tip2> operator *(Tip2 br, const GMatrica<Tip2> &m1);
    template<typename Tip2>
    friend bool operator ==(const GMatrica<Tip2> &m1, const GMatrica<Tip2> &m2);
    template<typename Tip2>
    friend bool operator !=(const GMatrica<Tip2> &m1, const GMatrica<Tip2> &m2);
    template<typename Tip2>
    friend std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip2> &m);
    template<typename Tip2>
    friend std::istream &operator >>(std::istream &tok, GMatrica<Tip2> &m);
};

template<typename Tip>
GMatrica<Tip>::GMatrica() {
    br_kolona = 0; br_redova = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            mat[i][j] = 0;
} 
template <typename Tip>
GMatrica<Tip>::GMatrica(int redovi, int kolone, Tip vrijednost) {
    if(redovi < 0 || redovi > 4 || kolone < 0 || redovi > 4) throw std::logic_error("Ilegalan format matrice");
    br_redova = redovi;
    br_kolona = kolone;
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
            mat[i][j] = vrijednost;
} 
template<typename Tip>
GMatrica<Tip>::GMatrica(Tip m[4][4]) {
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
            mat[i][j] = m[i][j];
}
template<typename Tip>
GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip>> v) {
    if(v[0].size() < 0 || v[0].size() > 4 || v.size() < 0 || v.size() > 4) std::logic_error("Ilegalan format matrice");
    for(int i = 0; i < v.size(); i++)
        for(int j = i + 1; j < v.size(); j++)
            if(v[i].size() != v[j].size) throw std::logic_error("Ilegalan format matrice");
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++)
            mat.mat[i][j] = v.mat[i][j];
    }
}
template<typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Tip>> lista) {
    if(lista.size() < 0 || lista.size() > 4 || (*lista.begin()).size() < 0 || (*lista.begin()).size() > 4) throw std::logic_error ("Ilegalan format matrice");
    br_redova = lista.size();
    br_kolona = (*lista.begin()).size();
    int i(0);
    for(auto it1 = lista.begin(); it1 != lista.end(); it1++,i++) {
        int j(0);
        for(auto it2 = it1 -> begin(); it2 != it1 -> end(); it2++, j++)
            mat[i][j] = *it2;
    }
}
template<typename Tip2>//, typename Tip3>
GMatrica<Tip2> operator +(const GMatrica<Tip2> &m1, const GMatrica<Tip2> &m2) {//-> GMatrica<decltype(m1[0][0] + m2[0][0])> {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<Tip2> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
    return m3;
}
template<typename Tip2>
GMatrica<Tip2> operator -(const GMatrica<Tip2> &m1, const GMatrica<Tip2> &m2) {//-> GMatrica<decltype(m1[0][0] - m2[0][0])> {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<Tip2> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.mat[i][j] = m1.mat[i][j] - m2.mat[i][j];

    return m3;
}
template<typename Tip2>
GMatrica<Tip2> operator *(const GMatrica<Tip2> &m1, const GMatrica<Tip2> &m2) {//-> GMatrica<decltype(m1[0][0] * m2[0][0])> {
    if(m1.br_redova != m2.br_kolona || m1.br_kolona != m2.br_redova) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<Tip2> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.mat[i][j] = m1.mat[i][j] * m2.mat[i][j];
    return m3;
}
template<typename Tip2>
GMatrica<Tip2> operator *(const GMatrica<Tip2> &m1, Tip2 br) {//-> GMatrica<decltype(m1[0][0] * br)> {
    GMatrica<Tip2> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.mat[i][j] = m1.mat[i][j] * br;
    return m3;
}
template<typename Tip2>
GMatrica<Tip2> operator *(Tip2 br, const GMatrica<Tip2> &m1) {//-> GMatrica<decltype(m1[0][0] * br)> {
    GMatrica<Tip2> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.mat[i][j] = m1.mat[i][j] * br;
    return m3;
}
template<typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator +=(const GMatrica<Tip> &m2) {
    if(br_redova != m2.br_redova || br_kolona != m2.br_kolona) throw std::domain_error("Nedozvoljena operacija");
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
            mat[i][j] += m2.mat[i][j];
    return *this;
}
template<typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator -=(const GMatrica<Tip> &m2) {
    if(br_redova != m2.br_redova || br_kolona != m2.br_kolona) throw std::domain_error("Nedozvoljena operacija");
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
            mat[i][j] -= m2.mat[i][j];
    return *this;
}  
template<typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator *=(Tip br) {
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
            mat[i][j] *= br;
    return *this;
}
template<typename Tip2>
bool operator ==(const GMatrica<Tip2> &m1, const GMatrica<Tip2> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) return false;
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            if(m1.mat[i][j] != m2.mat[i][j]) return false;
    return true;
}
template<typename Tip2>
bool operator !=(const GMatrica<Tip2> &m1, const GMatrica<Tip2> &m2) {
    return !(m1 == m2);
}
template<typename Tip2>
std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip2> &m) {
    int sirina = tok.width();
    if(sirina < 6) sirina = 6;
    for(int i = 0; i < m.br_redova; i++){
        for(int j = 0; j < m.br_kolona; j++)
            tok << std::setw(sirina) << m.mat[i][j];
        tok << std::endl;
    }
    return tok;
}
template<typename Tip2>
std::istream &operator >>(std::istream &tok, GMatrica<Tip2> &m) {
    char znak;
    tok >> znak;
    if(znak != '[') tok.setstate(std::ios::failbit);
    int br(0);
    for(int i = 0; i < m.br_redova; i++){
        int br1(0);
        for(int j = 0; j < m.br_kolona; j++) {
            tok >> m.mat[i][j] >> znak;
            if(znak != ',') tok.setstate(std::ios::failbit);
            br++;
        }
        if(br1 != m.br_kolona) tok.setstate(std::ios::failbit);
        //tok >> znak;
        if(br < m.br_redova - 1) if(znak != ';') tok.setstate(std::ios::failbit);
        br++;
    }
//    tok >> znak;
    if(znak != ']') tok.setstate(std::ios::failbit);
    return tok;
}

int main ()
{
    GMatrica<int> m1({{1, 2}, {3, 4}});
    GMatrica<int> m2({{5, 6}, {1, 4}});
    auto m3 = m1 + m2;
    auto m6 = m1 - m2;
    auto m5 = m1 * m2;
    GMatrica<int> m4 = m1 * 2; 
    std::cout << "Oduzimanje: \n";
    std::cout <<  m6 << std::endl;
    std::cout << "Sabiranje: \n";
    std::cout << m3 << std::endl;
    std::cout << "Mnozenje skalarom: \n";
    std::cout <<  m4 << std::endl;
    std::cout << "Mnozenje matrice: \n";
    std::cout <<  m5 << std::endl;
    bool iste(m1 == m2);
    std::cout << "Jesu li iste: \n" << iste;


	return 0;
}
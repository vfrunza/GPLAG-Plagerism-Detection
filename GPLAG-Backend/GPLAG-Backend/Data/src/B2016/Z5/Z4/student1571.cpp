/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>
#include <type_traits>

template <typename Tip>
class GMatrica {
    Tip matrica[4][4] ;
    int br_redova = 0 , br_kolona = 0 ;
    public:
    int DajBrojKolona() const { return br_kolona; }
    int DajBrojRedova() const { return br_redova; }
    GMatrica() = default;
    template <typename Tip1>
    GMatrica (const GMatrica<Tip1> &mat);
    GMatrica (int redovi, int kolone, Tip vrijednost = {});
    GMatrica (const Tip niz[4][4]);
    GMatrica (const std::vector<std::vector<Tip>> &vek);
    GMatrica (const std::initializer_list<std::initializer_list<Tip>> &mat);
    template <typename Tip2, typename Tip3>
    friend auto operator+ (const GMatrica<Tip2> &mat, const GMatrica<Tip3> &mat1) -> GMatrica <decltype (mat.matrica[0][0] + mat1.matrica[0][0])>;
    template <typename Tip2, typename Tip3>
    friend auto operator- (const GMatrica<Tip2> &mat, const GMatrica<Tip3> &mat1) -> GMatrica <decltype (mat.matrica[0][0] - mat1.matrica[0][0])>;
    template <typename Tip2, typename Tip3>
    friend auto operator* (const GMatrica<Tip2> &mat, const GMatrica<Tip3> &mat1) -> GMatrica <decltype (mat.matrica[0][0] * mat1.matrica[0][0])>;
    template <typename Tip2, typename Tip3>
    friend auto operator* (const GMatrica<Tip2> &mat, Tip3 n) -> GMatrica <decltype (mat.matrica[0][0] * n)>;
    template <typename Tip2, typename Tip3>
    friend auto operator* (Tip2 n, const GMatrica<Tip3> &mat) -> GMatrica <decltype (n * mat.matrica[0][0])>;
    template <typename Nesto>
    friend std::ostream &operator<< (std::ostream &tok, GMatrica<Nesto> &mat);
    template <typename Tip1>
    friend std::istream &operator>> (std::istream &tok, GMatrica<Tip1> &mat);
    GMatrica<Tip> &operator+= (const GMatrica<Tip> &mat); 
    
    GMatrica<Tip> &operator-= (const GMatrica<Tip> &mat1);
    GMatrica<Tip> &operator*= (const GMatrica<Tip> &mat1);
    GMatrica<Tip> &operator*= (Tip n);
    template <typename Tip2, typename Tip3>
    friend bool operator== (const GMatrica<Tip2> &mat, const GMatrica<Tip3> &mat1);
    template <typename Tip2, typename Tip3>
    friend bool operator!= (const GMatrica<Tip2> &mat, const GMatrica<Tip3> &mat1);
    Tip *operator[] (int i);
    Tip &operator() (int i, int j);
    const Tip *operator[] (int i) const { return matrica[i]; }
    Tip operator() (int i, int j) const { return matrica[i-1][j-1]; }
};
template <typename Tip>
GMatrica<Tip>::GMatrica (int redovi, int kolone, Tip vrijednost) {
    if (redovi < 0 || kolone < 0 || redovi > 4 || redovi > 4) throw std::logic_error ("Ilegalan format matrice");
    br_redova = redovi;
    br_kolona = kolone;
    for (int i=0; i<redovi; i++) {
        for (int j=0; j<kolone; j++) 
            matrica[i][j] = vrijednost;
    }
}
template <typename Tip>
template <typename Tip1>
GMatrica<Tip>::GMatrica (const GMatrica<Tip1> &mat) {
    if (mat.br_redova < 0 || mat.br_kolona < 0 || mat.br_redova > 4 || mat.br_redova > 4) throw std::logic_error ("Ilegalan format matrice");
    br_kolona = mat.br_kolona;
    br_redova = mat.br_redova;
    for (int i=0; i<br_redova; i++) {
        for (int j=0; j<br_kolona; j++)
            matrica[i][j] = mat[i][j];
    }
}
template <typename Tip>
GMatrica<Tip>::GMatrica (const Tip niz[4][4]) {
    this->br_kolona = 4;
    this->br_redova = 4;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++)
            matrica[i][j] = niz[i][j];
    }
}
template <typename Tip>
GMatrica<Tip>::GMatrica (const std::vector<std::vector<Tip>> &vek) {
    if (vek.size() < 0 || vek.size() > 4) throw std::logic_error ("Ilegalan format matrice");
    for (int i=0; i<vek.size() - 1 ; i++) 
        if (vek[i].size() != vek[i+1].size()) throw std::logic_error ("Ilegalan format matrice");
        
    br_kolona = vek[0].size();
    br_redova = vek.size();
    for (int i=0; i<vek.size(); i++) {
        for (int j=0; j<vek[i].size(); j++)
            matrica[i][j] = vek[i][j];
    }
}
template <typename Tip>
GMatrica<Tip>::GMatrica (const std::initializer_list<std::initializer_list<Tip>> &mat) {
    if (mat.size() < 0 || mat.size() > 4) throw std::logic_error ("Ilegalan format matrice");
    for (auto it(mat.begin()), it1(mat.begin()); it1 != mat.end(); it1++) {
        if (it->size() != it1->size()) throw std::logic_error ("Ilegalan format matrice");
    }
    br_redova = mat.size();
    br_kolona = (*mat.begin()).size();
    auto a = mat.begin();
    for (int i=0; i<br_redova; i++, a++) {
        auto b (a->begin());
        for (int j=0; j<br_kolona; j++, b++) 
            matrica[i][j] = *b;
    }
}
template <typename Tip2, typename Tip3>
auto operator+ (const GMatrica<Tip2> &mat, const GMatrica<Tip3> &mat1) -> GMatrica <decltype (mat.matrica[0][0] + mat1.matrica[0][0]) > {
    if (mat.DajBrojKolona() != mat1.DajBrojKolona() || mat.DajBrojRedova() != mat1.DajBrojRedova())
        throw std::domain_error ("Nedozvoljena operacija");
    GMatrica<decltype (mat1[0][0] + mat[0][0])> temp (mat1.DajBrojRedova(), mat1.DajBrojKolona());
    for (int i=0; i<mat.DajBrojRedova(); i++) {
        for (int j=0; j<mat.DajBrojKolona(); j++) {
            temp.matrica[i][j] = mat.matrica[i][j] + mat1.matrica[i][j];
        }
    }
    return temp;
}
template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator+= (const GMatrica<Tip> &mat) {
    if ((*this).DajBrojRedova() != mat.DajBrojRedova() || (*this).DajBrojKolona() != mat.DajBrojKolona())
        throw std::domain_error ("Nedozvoljena operacija");
    GMatrica <decltype ((*this)[0][0] + mat[0][0])> temp (mat.DajBrojRedova(), mat.DajBrojKolona());
    for (int i=0; i<temp.DajBrojRedova(); i++) {
        for (int j=0; j<temp.DajBrojKolona(); j++)
            (*this).matrica[i][j] = (*this).matrica[i][j] + mat.matrica[i][j];
    }
    
    return *this;
}
template <typename Tip2, typename Tip3>
auto operator- (const GMatrica<Tip2> &mat, const GMatrica<Tip3> &mat1) -> GMatrica <decltype (mat.matrica[0][0] - mat1.matrica[0][0])> {
    if (mat.DajBrojKolona() != mat1.DajBrojKolona() || mat.DajBrojRedova() != mat1.DajBrojRedova())
        throw std::domain_error ("Nedozvoljena operacija");
    GMatrica<decltype (mat[0][0] - mat1[0][0])> temp(mat.DajBrojRedova(), mat.DajBrojKolona());
    for (int i=0; i<temp.DajBrojRedova(); i++) {
        for (int j=0; j<temp.DajBrojKolona(); j++)
            temp.matrica[i][j] = mat.matrica[i][j] - mat1.matrica[i][j];
    }
    return temp;
}
template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator-= (const GMatrica<Tip> &mat1) {
    if ((*this).DajBrojRedova() != mat1.DajBrojRedova() || (*this).DajBrojKolona() != mat1.DajBrojKolona())
        throw std::domain_error ("Nedozvoljena operacija");
    for (int i=0; i<mat1.DajBrojRedova(); i++) {
        for (int j=0; j<mat1.DajBrojKolona(); j++)
            (*this).matrica[i][j] = (*this).matrica[i][j] - mat1.matrica[i][j];
    }
    return *this;
}
template <typename Tip2, typename Tip3>
auto operator* (const GMatrica<Tip2> &mat, const GMatrica<Tip3> &mat1) -> GMatrica <decltype (mat.matrica[0][0] * mat1.matrica[0][0])> {
    if (mat.DajBrojKolona() != mat1.DajBrojRedova())
        throw std::domain_error ("Nedozvoljena operacija");
    GMatrica <decltype (mat.matrica[0][0] * mat1.matrica[0][0])> temp (mat.DajBrojRedova(), mat1.DajBrojKolona());
    for (int i=0; i<mat.DajBrojKolona(); i++) {
        for (int j=0; j<mat1.DajBrojKolona(); j++) {
            for (int k=0; k<mat1.DajBrojRedova(); k++)
                temp.matrica[i][j] += mat.matrica[i][k] * mat1.matrica[k][j];
        }
    }
    return temp;
}
template <typename Tip2, typename Tip3>
auto operator* (const GMatrica<Tip2> &mat, Tip3 n) -> GMatrica <decltype (mat.matrica[0][0] * n)> {
    GMatrica<decltype (mat.matrica[0][0] * n)> temp (mat.DajBrojRedova(), mat.DajBrojKolona());
    for (int i=0; i<temp.DajBrojRedova(); i++) {
        for (int j=0; j<temp.DajBrojKolona(); j++)
            temp.matrica[i][j] = mat.matrica[i][j] * n;
    }
    return temp;
}
template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator*= (const GMatrica<Tip> &mat1) {
    if ((*this).DajBrojKolona() != mat1.DajBrojRedova())
        throw std::domain_error ("Nedozvoljena operacija");
    GMatrica<decltype (mat1.matrica[0][0] * (*this).matrica[0][0])> temp ((*this).DajBrojRedova(), mat1.DajBrojKolona());
    for (int i=0; i<(*this).DajBrojRedova(); i++) {
        for (int j=0; j<mat1.DajBrojKolona(); j++) {
            for (int k=0; k<mat1.DajBrojKolona(); k++)
                temp.matrica[i][j] += (*this).matrica[i][k] * mat1.matrica[k][j];
        }
    }
    *this = temp;
    return *this;
}
template <typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator*= (Tip n) {
    for (int i=0; i<(*this).DajBrojRedova(); i++) {
        for (int j=0; j<(*this).DajBrojKolona(); j++)
            (*this).matrica[i][j] = (*this).matrica[i][j] * n;
    }
    return *this;
}
template <typename Tip2, typename Tip3>
auto operator* (Tip2 n, const GMatrica<Tip3> &mat) -> GMatrica <decltype (n * mat.matrica[0][0])>{
    return mat * n;
}
template <typename Tip>
std::ostream &operator << (std::ostream &tok, GMatrica<Tip> &mat) {
    int sirina = tok.width();
    if (sirina < 6) sirina = 6;
    for (int i=0; i<mat.DajBrojRedova(); i++) {
        for (int j=0; j<mat.DajBrojKolona(); j++)
            tok << std::setw(sirina) << mat[i][j];
        tok << std::endl;
    }
    return tok;
}
template <typename Tip1>
std::istream &operator>> (std::istream &tok, GMatrica<Tip1> &mat) {
    char niz [100];
    int redovi = 0, kolone = 0;
    std::vector<Tip1> brojevi;
    tok.get(niz,100);
    if (niz[0] != '[') tok.setstate (std::ios::failbit);
    bool negativan(false);
    for (int i=0; i<100; i++) {
        if (niz[i] == '-') 
            negativan = true;
        if (niz[i] == ']' || niz[i] == '\0') break;
        if (niz[i] >= '0' && niz[i] <= '9') {
            Tip1 a = Tip1(niz[i]) - 48;
            if (negativan) a *= -1;
            negativan = false;
            brojevi.push_back(a);
            kolone++;
            if (niz[i+1] != ']') {
                if (niz[i+1] != ',' && niz[i+1] != ';') 
                tok.setstate (std::ios::failbit);
            }
        }
        if (niz[i] == ';') {
            kolone = 0;
            redovi++;
        }
    }
    redovi +=1;
    int k=0;
    if (!tok) return tok;
    mat.br_redova = redovi;
    mat.br_kolona = kolone;
    for (int i=0; i<redovi; i++) {
        for (int j=0; j<kolone; j++) {
            mat.matrica[i][j] = brojevi[k];
            k++;
        }
    }
    return tok;
}
template <typename Tip2, typename Tip3>
bool operator== (const GMatrica<Tip2> &mat, const GMatrica<Tip3> &mat1) {
    if (mat.DajBrojRedova() != mat1.DajBrojRedova() || mat.DajBrojKolona() != mat.DajBrojKolona()) return false;
    for (int i=0; i<mat.DajBrojRedova(); i++) {
        for (int j=0; j<mat.DajBrojKolona(); j++) {
            if (mat[i][j] != mat1[i][j]) return false;
        }
    }
    return true;
}
template <typename Tip2, typename Tip3>
bool operator!= (const GMatrica<Tip2> &mat, const GMatrica<Tip3> &mat1) {
    return !(mat == mat1);
}
template <typename Tip>
Tip *GMatrica<Tip>::operator[] (int i) {
    return matrica[i];
}
template <typename Tip>
Tip &GMatrica<Tip>::operator() (int i, int j) {
    return matrica[i-1][j-1];
}
int main ()
{ 
    try {
       GMatrica<int> m1({{1, 0, 2}, {-1, 3, 1}});
       GMatrica<int> m2({{3, 1},{2, 1}, {1,0}});
       auto m3 = m1 + m2;
       std::cout << m3 << std::endl;
       GMatrica<int> m4({{1, 2, 8}, {3, 4, 8}});
       auto m5 = m3-m4;
       m1*=m2;
       std::cout << m1 << std::endl;
       auto neka = m1 * m2;
       std::cout << neka << std::endl;
       m1-=m2;
       std::cout << m1;
       std::cout << m1[0][0];
       if (m1 == m2) std::cout << "Iste su!";
       else std::cout << "Nisu iste!";
     }
    catch (domain_error end) {
        std::cout << end.what();
    }
    catch (std::logic_error ne) {
        std::cout << ne.what();
    }
    return 0;
}
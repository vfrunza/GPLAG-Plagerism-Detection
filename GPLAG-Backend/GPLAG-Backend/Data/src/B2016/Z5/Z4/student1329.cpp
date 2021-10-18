#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <initializer_list>

template <typename TipElementa>
class GMatrica {
    int broj_redova, broj_kolona;
    TipElementa matrica[4][4];
public:
    GMatrica(int broj_redova = 0, int broj_kolona = 0, TipElementa element = TipElementa());
    template <typename DrugiTip>
    GMatrica(const GMatrica<DrugiTip> &g);
    template <typename DrugiTip>
    GMatrica &operator = (const GMatrica<DrugiTip> &g);
    GMatrica(const TipElementa niz[4][4]);
    GMatrica(const std::vector<std::vector<TipElementa>> &m);
    GMatrica(const std::initializer_list<std::initializer_list<TipElementa>> &l1);
    int DajBrojRedova() const { return broj_redova; }
    int DajBrojKolona() const { return broj_kolona; }
    
    //friend operator + (const GMatrica<Tip1> &g1, const GMatrica<Tip2> &g2);
    //friend operator - (const GMatrica<Tip1> &g1, const GMatrica<Tip2> &g2);
    //friend operator * (const GMatrica<Tip1> &g1, const GMatrica<Tip2> &g2);
    
    template <typename Tip>
    friend bool operator == (const GMatrica<Tip> &g1, const GMatrica<Tip> &g2);
    template <typename Tip>
    friend bool operator != (const GMatrica<Tip> &g1, const GMatrica<Tip> &g2);
    
    TipElementa &operator () (int x, int y);
    TipElementa operator () (int x, int y) const;
    //TipElementa* &operator [] (int x) { return matrica[x]; }
    //TipElementa operator [] (int x) const { return matrica[x]; }
    
    template <typename Tip>
    friend std::ostream &operator << (std::ostream &tok, const GMatrica<Tip> &g1);
    //template <typename Tip>
    //friend std::istream &operator >> (std::istream &tok, GMatrica<Tip> &g1);
};

template <typename TipElementa>
GMatrica<TipElementa>::GMatrica(int broj_redova, int broj_kolona, TipElementa element) {
    if(broj_redova < 0 || broj_kolona < 0 || broj_kolona > 4 || broj_redova > 4)
        throw std::logic_error("Ilegalan format matrice");
    GMatrica<TipElementa>::broj_redova = broj_redova; GMatrica<TipElementa>::broj_kolona = broj_kolona;
    for(int i = 0; i < broj_redova; i++) {
        for(int j = 0; j < broj_kolona; j++)
            matrica[i][j] = element;
    }
}

template <typename TipElementa>
template <typename DrugiTip>
GMatrica<TipElementa>::GMatrica(const GMatrica<DrugiTip> &g) : broj_redova(g.broj_redova), broj_kolona(g.broj_kolona) {
    for(int i = 0; i < broj_redova; i++) {
        for(int j = 0; j < broj_kolona; j++) {
            matrica[i][j] = static_cast<TipElementa>(g[i][j]);
        }
    }
}

template <typename TipElementa>
template <typename DrugiTip>
GMatrica<TipElementa> &GMatrica<TipElementa>::operator = (const GMatrica<DrugiTip> &g) {
    for(int i = 0; i < broj_redova; i++) {
        for(int j = 0; j < broj_kolona; j++) {
            matrica[i][j] = static_cast<TipElementa>(g[i][j]);
        }
    }
}

template <typename TipElementa>
GMatrica<TipElementa>::GMatrica(const TipElementa niz[4][4]) : broj_redova(4), broj_kolona(4) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            matrica[i][j] = niz[i][j];
        }
    }
}

template <typename TipElementa>
GMatrica<TipElementa>::GMatrica(const std::vector<std::vector<TipElementa>> &m) {
    if(m.size() < 0 || m.size() > 4)
        throw std::logic_error("Ilegalan format matrice");
    for(int i = 0; i < m.size(); i++)
        if(m[i].size() > 4) throw std::logic_error("Ilegalan format matrice");
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++)
            matrica[i][j] = m[i][j];
    }
    broj_redova = m.size(); broj_kolona = m[0].size();
}

template <typename TipElementa>
GMatrica<TipElementa>::GMatrica(const std::initializer_list<std::initializer_list<TipElementa>> &l1) {
    if(l1.size() < 0 || l1.size() > 4)
        throw std::logic_error("Ilegalan format matrice");
    for(int i = 0; i < l1.size(); i++)
        if((*(l1.begin() + i)).size() > 4) throw std::logic_error("Ilegalan format matrice");
    broj_redova = l1.size(); broj_kolona = (*l1.begin()).size();
    int i(0), j(0);
    for(auto x : l1) {
        for(auto y : x) {
            matrica[i][j] = y;
            j++;
            if(j == broj_kolona) j = 0;
        }
        i++;
        if(i == broj_redova) i = 0;
    }    
}

template <typename Tip>
bool operator == (const GMatrica<Tip> &g1, const GMatrica<Tip> &g2) {
    for(int i = 0; i < g1.broj_redova; i++) {
        for(int j = 0; j < g1.broj_kolona; j++) {
            if(g1.matrica[i][j] != g2.matrica[i][j]) return false;
        }
    }
    return true;
}

template <typename Tip>
bool operator != (const GMatrica<Tip> &g1, const GMatrica<Tip> &g2) {
    return !(g1 == g2);
}

template <typename TipElementa>
TipElementa &GMatrica<TipElementa>::operator () (int x, int y) {
    if(x < 1 || x > broj_redova || y < 1 || y > broj_kolona) throw std::range_error("Nedozvoljen indeks");
    return matrica[x - 1][y - 1];
}

template <typename TipElementa>
TipElementa GMatrica<TipElementa>::operator () (int x, int y) const {
    if(x < 1 || x > broj_redova || y < 1 || y > broj_kolona) throw std::range_error("Nedozvoljen indeks");
    return matrica[x - 1][y - 1];
}

template <typename Tip>
std::ostream &operator << (std::ostream &tok, const GMatrica<Tip> &g1) {
    int sirina(tok.width());
    if(sirina < 6) sirina = 6;
    for(int i = 0; i < g1.broj_redova; i++) {
        for(int j = 0; j < g1.broj_kolona; j++)
            tok << std::setw(sirina) << g1.matrica[i][j];
        tok << std::endl;
    }
    return tok;
}

/*template <typename Tip>
std::istream &operator >> (std::istream &tok, GMatrica<Tip> &g1) {
    
}*/

int main() {
    
    GMatrica<int> g1 {{1,2,3}, {2,3,4}};
    std::cout << std::setw(3) << g1;
    
    return 0;
}
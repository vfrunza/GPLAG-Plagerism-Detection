#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>

template <typename tip_pok>
class Pokazivac {
    const tip_pok *p;
public:
    Pokazivac(const tip_pok *novi) : p(novi) {}
    tip_pok operator [](int a) const { return p[a]; }
    operator Pokazivac() { return p; }
};

template <typename tip>
class GMatrica {
    tip matrica[4][4];
    int broj_redova, broj_kolona;
public:
    GMatrica() : broj_redova(0), broj_kolona(0) {}
    GMatrica(int broj_redova, int broj_kolona, tip a={});
    template <typename tip2>
    GMatrica(const GMatrica<tip2>&druga);
    GMatrica(tip **druga);
    GMatrica(const std::vector<std::vector<tip>>&v);
    GMatrica(const std::initializer_list<std::initializer_list<tip>>&L);
    
    int DajBrojRedova() const { return broj_redova; }
    int DajBrojKolona() const { return broj_kolona; }
    
    template <typename tip1, typename tip2>
    friend auto operator +(const GMatrica<tip1>&prva, const GMatrica<tip2>&druga) -> GMatrica<decltype(prva.matrica[0][0]+druga.matrica[0][0])>;
    template <typename tip1, typename tip2>
    friend auto operator -(const GMatrica<tip1>&prva, const GMatrica<tip2>&druga) -> GMatrica<decltype(prva.matrica[0][0]-druga.matrica[0][0])>;
    template <typename tip1, typename tip2>
    friend auto operator *(const GMatrica<tip1>&prva, const GMatrica<tip2>&druga) -> GMatrica<decltype(prva.matrica[0][0]*druga.matrica[0][0])>;
    template <typename tip1, typename tip2>
    friend auto operator *(const GMatrica<tip1>&prva, tip2 faktor) -> GMatrica<decltype(prva.matrica[0][0]*faktor)>;
    template <typename tip1, typename tip2>
    friend auto operator *(tip2 faktor, const GMatrica<tip1>&prva) -> GMatrica<decltype(prva.matrica[0][0]*faktor)>;
    
    template <typename tip2>
    GMatrica& operator +=(const GMatrica<tip2>&druga);
    template <typename tip2>
    GMatrica& operator -=(const GMatrica<tip2>&druga);
    template <typename tip2>
    GMatrica& operator *=(const GMatrica<tip2>&druga);
    template <typename tip2>
    GMatrica& operator *=(tip2 faktor);
    
    template <typename tip1, typename tip2>
    friend bool operator ==(const GMatrica<tip1>&prva, const GMatrica<tip2>&druga);
    template <typename tip1, typename tip2>
    friend bool operator !=(const GMatrica<tip1>&prva, const GMatrica<tip2>&druga);
    
    tip& operator ()(int a, int b);
    tip operator ()(int a, int b) const;
    tip* operator [](int a) { return matrica[a]; }
    Pokazivac<tip> operator [](int a) const { return Pokazivac<tip>(matrica[a]+0); }
    
    template <typename tip1>
    friend std::ostream& operator <<(std::ostream& tok, const GMatrica<tip1>&m);
    template <typename tip1>
    friend std::istream& operator >>(std::istream& tok, GMatrica<tip1>&m);
};

template <typename tip>
GMatrica<tip>::GMatrica(int broj_redova, int broj_kolona, tip a) : broj_redova(broj_redova), broj_kolona(broj_kolona) {
    if(broj_redova<0 || broj_redova>4 || broj_kolona<0 || broj_kolona>4) throw std::logic_error("Ilegalan format matrice");
    for(int i=0; i<broj_redova; i++) for(int j=0; j<broj_kolona; j++) matrica[i][j]=a;
}

template <typename tip>
template <typename tip2>
GMatrica<tip>::GMatrica(const GMatrica<tip2>&druga) : broj_kolona(druga.broj_kolona), broj_redova(druga.broj_redova) {
    for(int i=0; i<broj_redova; i++) for(int j=0; j<broj_kolona; j++) matrica[i][j]=druga.matrica[i][j];
}

template <typename tip>
GMatrica<tip>::GMatrica(tip **druga) : broj_kolona(4), broj_redova(4) {
    for(int i=0; i<broj_redova; i++) for(int j=0; j<broj_kolona; j++) matrica[i][j]=druga[i][j];
}

template <typename tip>
GMatrica<tip>::GMatrica(const std::vector<std::vector<tip>>&v) {
    if(v.size()>4) throw std::logic_error("Ilegalan format matrice");
    if(v.size()) { 
        for(int i=0; i<v.size(); i++) if(v[i].size()!=v[0].size()) throw std::logic_error("Ilegalan format matrice"); 
        broj_kolona=v[0].size();
    }
    else broj_kolona=0;
    broj_redova=v.size();
    for(int i=0; i<broj_redova; i++) for(int j=0; j<broj_kolona; j++) matrica[i][j]=v[i][j];
}

template <typename tip>
GMatrica<tip>::GMatrica(const std::initializer_list<std::initializer_list<tip>>&L) {
    if(L.size()>4) throw std::logic_error("Ilegalan format matrice");
    if(L.size()) {
        for(auto i=L.begin(); i!=L.end(); i++) if(i->size()!=L.begin()->size()) throw std::logic_error("Ilegalan format matrice");
        broj_kolona=L.begin()->size();
    }
    else broj_kolona=0;
    broj_redova=L.size(); auto it1=L.begin();
    for(int i=0; i<broj_redova; i++, it1++) {
        auto it2=it1->begin();
        for(int j=0; j<broj_kolona; j++, it2++) {
            matrica[i][j]=*it2;
        }
    }
}

template <typename tip, typename tip2>
auto operator +(const GMatrica<tip>&prva, const GMatrica<tip2>&druga) -> GMatrica<decltype(prva.matrica[0][0]+druga.matrica[0][0])> {
    if(prva.broj_kolona!=druga.broj_kolona || prva.broj_redova!=druga.broj_redova) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(prva.matrica[0][0]+druga.matrica[0][0])>nova(prva.broj_redova, prva.broj_kolona);
    for(int i=0; i<nova.broj_redova; i++) for(int j=0; j<nova.broj_kolona; j++) nova.matrica[i][j]=prva.matrica[i][j]+druga.matrica[i][j];
    return nova;
}

template <typename tip, typename tip2>
auto operator -(const GMatrica<tip>&prva, const GMatrica<tip2>&druga) -> GMatrica<decltype(prva.matrica[0][0]-druga.matrica[0][0])> {
    if(prva.broj_kolona!=druga.broj_kolona || prva.broj_redova!=druga.broj_redova) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(prva.matrica[0][0]-druga.matrica[0][0])>nova(prva.broj_redova, prva.broj_kolona);
    for(int i=0; i<nova.broj_redova; i++) for(int j=0; j<nova.broj_kolona; j++) nova.matrica[i][j]=prva.matrica[i][j]-druga.matrica[i][j];
    return nova;
}

template <typename tip, typename tip2>
auto operator *(const GMatrica<tip>&prva, const GMatrica<tip2>&druga) -> GMatrica<decltype(prva.matrica[0][0]*druga.matrica[0][0])> {
    if(prva.broj_kolona!=druga.broj_redova) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(prva.matrica[0][0]*druga.matrica[0][0])>nova(prva.broj_redova, druga.broj_kolona);
    for(int i=0; i<nova.broj_redova; i++) {
        for(int j=0; j<nova.broj_kolona; j++) {
            for(int k=0; k<prva.broj_kolona; k++) {
                nova.matrica[i][j]+=prva.matrica[i][k]*druga.matrica[k][j];
            }
        }
    }
    return nova;
}

template <typename tip, typename tip2>
auto operator *(const GMatrica<tip>&prva, tip2 faktor) -> GMatrica<decltype(prva.matrica[0][0]*faktor)> {
    GMatrica<decltype(prva.matrica[0][0]*faktor)>nova(prva.broj_redova, prva.broj_kolona);
    for(int i=0; i<nova.broj_redova; i++) for(int j=0; j<nova.broj_kolona; j++) nova[i][j]=prva.matrica[i][j]*faktor;
    return nova;
}

template <typename tip, typename tip2>
auto operator *(tip2 faktor, const GMatrica<tip>&prva) -> GMatrica<decltype(prva.matrica[0][0]*faktor)> {
    return prva*faktor;
}

template <typename tip>
template <typename tip2>
GMatrica<tip>& GMatrica<tip>::operator +=(const GMatrica<tip2>&druga) {
    if(broj_kolona!=druga.broj_kolona || broj_redova!=druga.broj_redova) throw std::domain_error("Nedozvoljena operacija");
    for(int i=0; i<broj_redova; i++) for(int j=0; j<broj_kolona; j++) matrica[i][j]+=druga.matrica[i][j];
    return *this;
}

template <typename tip>
template <typename tip2>
GMatrica<tip>& GMatrica<tip>::operator -=(const GMatrica<tip2>&druga) {
    if(broj_kolona!=druga.broj_kolona || broj_redova!=druga.broj_redova) throw std::domain_error("Nedozvoljena operacija");
    for(int i=0; i<broj_redova; i++) for(int j=0; j<broj_kolona; j++) matrica[i][j]-=druga.matrica[i][j];
    return *this;
}

template <typename tip>
template <typename tip2>
GMatrica<tip>& GMatrica<tip>::operator *=(const GMatrica<tip2>&druga) {
    return *this=*this*druga;
}

template <typename tip>
template <typename tip2>
GMatrica<tip>& GMatrica<tip>::operator *=(tip2 faktor) {
    for(int i=0; i<broj_redova; i++) for(int j=0; j<broj_kolona; j++) matrica[i][j]*=faktor;
    return *this;
}

template <typename tip, typename tip2>
bool operator ==(const GMatrica<tip>&prva, const GMatrica<tip2>&druga) {
    if(prva.broj_redova!=druga.broj_redova || prva.broj_kolona!=druga.broj_kolona) return false;
    for(int i=0; i<prva.broj_redova; i++) for(int j=0; j<prva.broj_kolona; j++) if(prva.matrica[i][j]!=druga.matrica[i][j]) return false;
    return true;
}

template <typename tip, typename tip2>
bool operator !=(const GMatrica<tip>&prva, const GMatrica<tip2>&druga) {
    return !(prva==druga);
}

template <typename tip>
tip& GMatrica<tip>::operator ()(int a, int b) {
    if(a<1 || a>broj_redova || b<1 || b>broj_kolona) throw std::range_error("Nedozvoljen indeks");
    return matrica[a-1][b-1];
}

template <typename tip>
tip GMatrica<tip>::operator ()(int a, int b) const {
    if(a<1 || a>broj_redova || b<1 || b>broj_kolona) throw std::range_error("Nedozvoljen indeks");
    return matrica[a-1][b-1];
}

template <typename tip>
std::ostream& operator <<(std::ostream& tok, const GMatrica<tip>&m) {
    int sirina=tok.width(); if(sirina<6) sirina=6;
    for(int i=0; i<m.broj_redova; i++) {
        for(int j=0; j<m.broj_kolona; j++) {
            tok << std::setw(sirina) << m.matrica[i][j];
        }
        std::cout << "\n";
    }
    return tok;
}

template <typename tip>
std::istream& operator >>(std::istream& tok, GMatrica<tip>&m) {
    char c; int kolone=-1; m.broj_redova=0;
    tok >> c; if(c!='[') tok.setstate(std::ios::failbit);
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            tok >> m.matrica[i][j] >> c;
            if(c==';' || c==']') {
                if(kolone!=-1 && kolone!=j+1) tok.setstate(std::ios::failbit);
                kolone=j+1;
                break;
            }
            else if(c!=',') { tok.setstate(std::ios::failbit); break; }
        }
        m.broj_redova++;
        if(c==',') tok.setstate(std::ios::failbit);
        if(c==']') break;
    }
    m.broj_kolona=kolone;
    return tok;
}

int main() {
    GMatrica<double> m1({{1, 2}, {3, 4}});
   GMatrica<double> m2({{1, 2}, {3, 4}});
   auto m3 = m1 + m2;
   std::cout << m3 << std::endl;
}
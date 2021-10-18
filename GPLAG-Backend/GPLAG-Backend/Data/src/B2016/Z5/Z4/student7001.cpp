/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>

template <typename TipEl>
class GMatrica {
    TipEl niz2D[4][4];
    int stvarni_br_redova, stvarni_br_kolona;
public:
    GMatrica() : stvarni_br_redova(0),stvarni_br_kolona(0) {}
    GMatrica(int br_redova, int br_kolona, TipEl vrijednost=TipEl());
    GMatrica<TipEl>(const GMatrica<TipEl> &matrica);
    GMatrica(TipEl matrica[4][4]);
    GMatrica(std::vector<std::vector<TipEl>> matrica);
    GMatrica(std::initializer_list<std::initializer_list<TipEl>> matrica);
    int DajBrojRedova() const { return stvarni_br_redova; }
    int DajBrojKolona() const { return stvarni_br_kolona; }
    template <typename Tip1, typename Tip2>
        friend GMatrica operator +(GMatrica &m1,GMatrica &m2);
    template <typename Tip1, typename Tip2>
        friend GMatrica operator -(GMatrica &m1,GMatrica &m2);
    template <typename Tip1, typename Tip2> 
        friend GMatrica operator *(GMatrica &m1,GMatrica &m2);
    template <typename Tip1, typename Tip2>
        friend GMatrica operator *(GMatrica &m,Tip2 vrijednost);
    template <typename Tip1, typename Tip2>
        friend GMatrica operator *(Tip2 vrijednost,GMatrica &m);
    GMatrica &operator +=(GMatrica &m);
    GMatrica &operator -=(GMatrica &m);
    GMatrica &operator *=(GMatrica &m);
    GMatrica &operator *=(TipEl vrijednost);
    template <typename Tip1> 
        friend bool operator ==(GMatrica m1,GMatrica m2);
    template <typename Tip1>
        friend bool operator !=(GMatrica m1,GMatrica m2);
    TipEl* operator[] (int indeks) {
        return niz2D[indeks];
    }
    TipEl &operator() (int indeks1,int indeks2) {
        if (indeks1<=0 || indeks1>stvarni_br_redova || indeks2<=0 || indeks2>stvarni_br_kolona)
            throw std::range_error("Nedozvoljen indeks");
        return niz2D[indeks1-1][indeks2-1];
    }
    template <typename Tip1>
        friend std::ostream &operator <<(std::ostream &tok,GMatrica<TipEl> &m);
    template <typename Tip1>
        friend std::istream &operator >>(std::istream &tok,GMatrica<TipEl> &m);
};

template <typename TipEl>
GMatrica<TipEl>::GMatrica(int br_redova, int br_kolona, TipEl vrijednost) {
    if (br_redova<0 || br_redova>4 || br_kolona<0 || br_kolona>4)
        throw std::logic_error("Ilegalan format matrice");
    stvarni_br_redova=br_redova; stvarni_br_kolona=br_kolona;
    for (int i=0; i<br_redova; i++)
        for (int j=0; j<br_kolona; j++)
            niz2D[i][j]=vrijednost;
}

template <typename TipEl>
GMatrica<TipEl>::GMatrica(const GMatrica<TipEl> &matrica) {
    stvarni_br_redova=matrica.DajBrojRedova();
    stvarni_br_kolona=matrica.DajBrojKolona();
    for (int i=0; i<matrica.DajBrojRedova(); i++)
        for (int j=0; j<matrica.DajBrojKolona(); j++)
            niz2D[i][j]=matrica.niz2D[i][j];
}

template <typename TipEl>
GMatrica<TipEl>::GMatrica(TipEl matrica[4][4]) {
    stvarni_br_redova=4;
    stvarni_br_kolona=4;
    for (int i=0; i<stvarni_br_redova; i++)
        for (int j=0; j<stvarni_br_kolona; j++)
            niz2D[i][j]=matrica[i][j];
}

template <typename TipEl>
GMatrica<TipEl>::GMatrica(std::vector<std::vector<TipEl>> matrica) {
    if (matrica.size()<0 || matrica.size()>4)
        throw std::logic_error("Ilegalan format matrice");
    int tmp=matrica[0].size();
    for (int i=0; i<matrica.size(); i++)
        if (matrica[i].size()<0 || matrica[i].size()>4 || matrica[i].size()!=tmp)
            throw std::logic_error("Ilegalan format matrice");
    stvarni_br_redova=matrica.size();
    stvarni_br_kolona=matrica[0].size();
    for (int i=0; i<matrica.size(); i++)
        for (int j=0; j<matrica[0].size(); j++)
            niz2D[i][j]=matrica[i][j];
}

template <typename TipEl>
GMatrica<TipEl>::GMatrica(std::initializer_list<std::initializer_list<TipEl>> matrica) {
    if (matrica.size()<0 || matrica.size()>4)
        throw std::logic_error("Ilegalan format matrice");
    auto it=matrica.begin();
    int tmp=it->size();
    for (auto it=matrica.begin(); it!=matrica.end(); it++)
        if (it->size()<0 || it->size()>4 || it->size()!=tmp)
            throw std::logic_error("Ilegalan format matrice");
    stvarni_br_redova=matrica.size();
    stvarni_br_kolona=tmp;
    int indeks1=0;
    for (auto it1=matrica.begin(); it1!=matrica.end(); it1++) {
        int indeks2=0;
        for (auto it2=it1->begin(); it2!=it1->end(); it2++) {
            niz2D[indeks1][indeks2]=*it2;
            indeks2++;
        }
        indeks1++;
    }
}

template <typename TipEl1, typename TipEl2>
auto operator +(GMatrica<TipEl1> &m1,GMatrica<TipEl2> &m2) -> GMatrica<decltype(m1[0][0]+m2[0][0])> {
    if (m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona())
        throw std::domain_error("Matrice nemaju jednake dimenzije");
    GMatrica<decltype(m1[0][0]+m2[0][0])> m3(m1.DajBrojRedova(),m1.DajBrojKolona());
    for (int i=0; i<m1.DajBrojRedova(); i++)
        for (int j=0; j<m1.DajBrojKolona(); j++)
            m3[i][j]=m1[i][j]+m2[i][j];
    return m3;
}

template <typename TipEl1, typename TipEl2>
auto operator -(GMatrica<TipEl1> &m1,GMatrica<TipEl2> &m2) -> GMatrica<decltype(m1[0][0]-m2[0][0])> {
    if (m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona())
        throw std::domain_error("Matrice nemaju jednake dimenzije");
    GMatrica<decltype(m1[0][0]-m2[0][0])> m3(m1.DajBrojRedova(),m1.DajBrojKolona());
    for (int i=0; i<m1.DajBrojRedova(); i++)
        for (int j=0; j<m1.DajBrojKolona(); j++)
            m3[i][j]=m1[i][j]-m2[i][j];
    return m3;
}

template <typename TipEl1, typename TipEl2>
auto operator *(GMatrica<TipEl1> &m1,GMatrica<TipEl2> &m2) -> GMatrica<decltype(m1[0][0]*m2[0][0])> {
    if (m1.DajBrojKolona()!=m2.DajBrojRedova())
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    GMatrica<decltype(m1[0][0]*m2[0][0])> m3(m1.DajBrojRedova(),m2.DajBrojKolona());
    for (int i=0; i<m1.DajBrojRedova(); i++) {
        for (int j=0; j<m2.DajBrojKolona(); j++) {
            decltype(m1[0][0]*m2[0][0]) suma=0;
            for (int k=0; k<m2.DajBrojRedova(); k++)
                suma+=m1[i][k]*m2[k][j];
            m3[i][j]=suma;
        }
    }
    return m3;
}

template <typename TipEl1, typename TipEl2>
auto operator *(GMatrica<TipEl1> &m1, TipEl2 vrijednost) -> GMatrica<decltype(m1[0][0]*vrijednost)> {
    GMatrica<decltype(m1[0][0]*vrijednost)> m2(m1.DajBrojRedova(),m1.DajBrojKolona());
    for (int i=0; i<m1.DajBrojRedova(); i++)
        for (int j=0; j<m1.DajBrojKolona(); j++)
            m2[i][j]=m1[i][j]*vrijednost;
    return m2;
}

template <typename TipEl1, typename TipEl2>
auto operator *(TipEl2 vrijednost, GMatrica<TipEl1> &m1) -> GMatrica<decltype(m1[0][0]*vrijednost)> {
    GMatrica<decltype(m1[0][0]*vrijednost)> m2(m1.DajBrojRedova(),m1.DajBrojKolona());
    for (int i=0; i<m1.DajBrojRedova(); i++)
        for (int j=0; j<m1.DajBrojKolona(); j++)
            m2[i][j]=m1[i][j]*2;
    return m2;
}

template <typename TipEl>
GMatrica<TipEl> &GMatrica<TipEl>::operator +=(GMatrica<TipEl> &m2) {
    if (stvarni_br_redova!=m2.DajBrojRedova() || stvarni_br_kolona!=m2.DajBrojKolona())
        throw std::domain_error("Matrice nemaju jednake dimenzije");
    for (int i=0; i<stvarni_br_redova; i++)
        for (int j=0; j<stvarni_br_kolona; j++)
            niz2D[i][j]+=m2[i][j];
    return *this;
}

template <typename TipEl>
GMatrica<TipEl> &GMatrica<TipEl>::operator -=(GMatrica<TipEl> &m2) {
    if (stvarni_br_redova!=m2.DajBrojRedova() || stvarni_br_kolona!=m2.DajBrojKolona())
        throw std::domain_error("Matrice nemaju jednake dimenzije");
    for (int i=0; i<stvarni_br_redova; i++)
        for (int j=0; j<stvarni_br_kolona; j++)
            niz2D[i][j]-=m2[i][j];
    return *this;
}

template <typename TipEl>
GMatrica<TipEl> &GMatrica<TipEl>::operator *=(GMatrica<TipEl> &m2) {
    if (stvarni_br_kolona!=m2.DajBrojRedova())
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    GMatrica<TipEl> m3(stvarni_br_redova,m2.DajBrojKolona());
    for (int i=0; i<stvarni_br_redova; i++) {
        for (int j=0; j<m2.DajBrojKolona(); j++) {
            TipEl suma=0;
            for (int k=0; k<m2.DajBrojRedova(); k++)
                suma+=niz2D[i][k]*m2[k][j];
            m3[i][j]=suma;
        }
    }
    stvarni_br_redova=m3.DajBrojRedova();
    stvarni_br_kolona=m3.DajBrojKolona();
    for (int i=0; i<m3.DajBrojRedova(); i++)
        for (int j=0; j<m3.DajBrojKolona(); j++)
            niz2D[i][j]=m3[i][j];
    return *this;
}

template <typename TipEl>
GMatrica<TipEl> &GMatrica<TipEl>::operator *=(TipEl vrijednost) {
    for (int i=0; i<stvarni_br_redova; i++)
        for (int j=0; j<stvarni_br_kolona; j++)
            niz2D[i][j]*=vrijednost;
    return *this;
}

template <typename TipEl> 
bool operator ==(GMatrica<TipEl> m1, GMatrica<TipEl> m2) {
    if (m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona()) return false;
    for (int i=0; i<m1.DajBrojRedova(); i++)
        for (int j=0; j<m1.DajBrojKolona(); j++)
            if (m1[i][j]!=m2[i][j]) return false;
    return true;
}

template <typename TipEl>
bool operator !=(GMatrica<TipEl> m1, GMatrica<TipEl> m2) { return !(m1==m2); }

template <typename TipEl>
std::ostream &operator <<(std::ostream &tok, GMatrica<TipEl> &m) {
    int sirina_ispisa=tok.width();
    if (sirina_ispisa<6) sirina_ispisa=6;
    for (int i=0; i<m.DajBrojRedova(); i++) {
        for (int j=0; j<m.DajBrojKolona(); j++)
            tok << std::setw(sirina_ispisa) << m[i][j];
        tok << std::endl;
    }
    return tok;
}

template <typename TipEl>
std::istream &operator >>(std::istream &tok, GMatrica<TipEl> &m) {
    char znak;
    GMatrica<TipEl> pomocna(4,4);
    int indeks1=1, indeks2=1, prethodna_duzina_reda=0;
    if (tok.peek()!='[') tok.setstate(std::ios::failbit);
    else tok >> znak;
    do {
        if (tok.peek()==']' && indeks2==prethodna_duzina_reda) break;
        else if (tok.peek()>='0' && tok.peek()<='9') tok >> pomocna(indeks1,indeks2);
        else if (tok.peek()==',') {
            tok >> znak;
            indeks2++;
            if (indeks2>4) {
                tok.setstate(std::ios::failbit);
                break;
            }
        }
        else if (tok.peek()==';') {
            tok >> znak;
            indeks1++;
            if (indeks1>4 || (prethodna_duzina_reda!=0 && indeks2!=prethodna_duzina_reda)) {
                tok.setstate(std::ios::failbit);
                break;
            }
            prethodna_duzina_reda=indeks2;
            indeks2=1;
        }
        else {
            tok.setstate(std::ios::failbit);
            break;
        }
    } while(1);
    if (!tok) return tok;
    GMatrica<int> pomocna1(indeks1,indeks2);
    for (int i=0; i<indeks1; i++)
        for (int j=0; j<indeks2; j++)
            pomocna1[i][j]=pomocna[i][j];
    m=std::move(pomocna1);
    return tok;
}

int main () {
    GMatrica<int> m1{{1,2,3},{1,2,3},{1,2,3}};
    GMatrica<double> m2({{1.5,2.5,3.5},{1.5,2.5,3.5},{1.5,2.5,3.5}});
    auto m3=m1+m2;
    std::cout << m3 << std::endl;
    auto m4=m1-m2;
    std::cout << m4 << std::endl;
    auto m5=m1*m2;
    std::cout << m5 << std::endl;
    auto m6=m1*2.5;
    std::cout << m6 << std::endl;
	return 0;
}
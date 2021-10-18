/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <iomanip>
#include <type_traits>
#include <algorithm>
using namespace std;
template <typename TipEl>
class GMatrica {
    int br_redova, br_kolona;
    TipEl niz[4][4];
    public:
    GMatrica():br_redova(0),br_kolona(0) {};
    GMatrica(int br_re, int br_ko, TipEl vrij=0);
    GMatrica(const GMatrica &m);
    GMatrica(TipEl niz1[4][4]);
    GMatrica(const vector<vector<TipEl>> &v);
    GMatrica(initializer_list<initializer_list<TipEl>> v);
    int DajBrojRedova() const { return br_redova; }
    int DajBrojKolona() const { return br_kolona; }
    GMatrica &operator +=(const GMatrica &m2);
    GMatrica &operator -=(const GMatrica &m2);
    GMatrica &operator *=(const GMatrica &m2);
    GMatrica &operator *=(TipEl d);
    template<typename TipEl2>
    friend bool operator ==(const GMatrica<TipEl2> &m1, const GMatrica<TipEl2> &m2);
    template<typename TipEl2>
    friend bool operator !=(const GMatrica<TipEl2> &m1, const GMatrica<TipEl2> &m2);
    TipEl &operator ()(int a, int b);
    TipEl operator() (int a, int b) const;
    TipEl const*  operator [](int const a) const {return niz[a]; }
    TipEl* operator [](int const a) { return niz[a];}
    template<typename TipEl2>
    friend ostream &operator <<(ostream &tok, const GMatrica<TipEl2> &m);
    template<typename TipEl2>
    friend istream &operator >>(istream &izlaz, GMatrica<TipEl2> &m);
    template<typename TipEl2, typename TipEl3>
    friend auto operator+(const GMatrica<TipEl2> &m1, const GMatrica<TipEl3> &m2)-> GMatrica<decltype(m1.niz[0][0]+m2.niz[0][0])>;
    template<typename TipEl3, typename TipEl2>
    friend auto operator-(const GMatrica<TipEl3> &m1, const GMatrica<TipEl2> &m2)-> GMatrica<decltype(m1.niz[0][0]-m2.niz[0][0])>;
    template<typename TipEl3, typename TipEl2>
    friend auto operator *(TipEl2 d, const GMatrica<TipEl3> &m) -> GMatrica<decltype(d*m.niz[0][0])>;
    template<typename TipEl3,typename TipEl2>
    friend auto operator *(const GMatrica<TipEl3> &m, TipEl2 d) -> GMatrica<decltype(m.niz[0][0]*d)>;
    void Ispisi() const {
         for(int i=0;i<br_redova;i++) {
            for(int j=0;j<br_kolona;j++)
                cout<<setw(10)<<niz[i][j];
         cout<<endl;}       
    }
    
};
template <typename TipEl>
GMatrica<TipEl>::GMatrica(int br_re,int br_ko, TipEl vrij) {
    if(br_re<0 || br_re>4 || br_ko<0 || br_ko>4) throw logic_error("Ilegalan format matrice");
    br_redova=br_re; br_kolona=br_ko; 
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
            niz[i][j]=vrij;
}
template <typename TipEl>
GMatrica<TipEl>::GMatrica(const GMatrica<TipEl> &m) {
    br_redova=m.br_redova; br_kolona=m.br_kolona; 
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
            niz[i][j]=m.niz[i][j];
}
template<typename TipEl>
GMatrica<TipEl>::GMatrica(TipEl niz1[4][4]) {
    br_redova=4; br_kolona=4;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            niz[i][j]=niz1[i][j];
}
template<typename TipEl>
GMatrica<TipEl>::GMatrica(const vector<vector<TipEl>> &v) {
    if(v.size()<0 || v.size()>4) throw logic_error("Ilegalan format matrice");
    for(int i=0;i<v.size();i++) if(v[i].size()<0 || v[i].size()>4) throw logic_error("Ilegalan format matrice");
    br_redova=v.size(); br_kolona=v[0].size();
    for(int i=0;i<v.size();i++) {
        for(int j=0;j<v[i].size();j++)
            niz[i][j]=v[i][j]; }
}
template<typename TipEl>
GMatrica<TipEl>::GMatrica(initializer_list<initializer_list<TipEl>> v)  {
    if(v.size()<0 || v.size()>4) throw logic_error("Ilegalan format matrice");
    for(int i=0;i<v.size();i++) if(v.begin()->size()<0 || v.begin()->size()>4) throw logic_error("Ilegalan format matrice");
    br_redova=v.size(); br_kolona=v.begin()->size();
    auto in=begin(v);
    for(int i=0;i<br_redova;++i,++in)
    copy(begin(*in),end(*in),&niz[i][0]);
}
template<typename TipEl, typename TipEl2>
auto operator +(const GMatrica<TipEl> &m1, const GMatrica<TipEl2> &m2)  -> GMatrica <decltype(m1.niz[0][0]+m2.niz[0][0])> {
    if(m1.br_kolona<0 || m1.br_kolona>4 || m1.br_redova<0 || m1.br_redova>4 || m2.br_kolona<0 || m2.br_kolona>4 || m2.br_redova<0 ||m2.br_redova>4) throw domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.niz[0][0]+m2.niz[0][0])>  m;
    m.br_kolona=m1.br_kolona; m.br_redova=m1.br_redova;
    for(int i=0;i<m.br_redova;i++)
        for(int j=0;j<m.br_kolona;j++) {
            m.niz[i][j]=m1.niz[i][j]+m2.niz[i][j];}
    return m;
} 
template<typename TipEl3, typename TipEl2>
auto operator -(const GMatrica<TipEl3> &m1, const GMatrica<TipEl2> &m2) -> GMatrica<decltype(m1.niz[0][0]-m2.niz[0][0])> {
    if(m1.br_kolona<0 || m1.br_kolona>4 || m1.br_redova<0 || m1.br_redova>4 || m2.br_kolona<0 || m2.br_kolona>4 || m2.br_redova<0 ||m2.br_redova>4) throw domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.niz[0][0]-m2.niz[0][0])> m;
    m.br_kolona=m1.br_kolona; m.br_redova=m1.br_redova;
    for(int i=0;i<m.br_redova;i++)
        for(int j=0;j<m.br_kolona;j++)
            m.niz[i][j]= (m1.niz[i][j]-m2.niz[i][j]);
    return m;
}
template<typename TipEl3,typename TipEl2>
auto operator *(TipEl2 d, const GMatrica<TipEl3> &m) -> GMatrica<decltype(d*m.niz[0][0])> {
    if(m.br_kolona<0 || m.br_kolona>4 || m.br_redova<0 || m.br_redova>4) throw domain_error("Nedozvoljena operacija");
    GMatrica<decltype(d*m.niz[0][0])> m1;
    m1.br_kolona=m.br_kolona; m1.br_redova=m.br_redova;
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
            m1.niz[i][j]=d*m.niz[i][j];
    return m1;
}
template<typename TipEl3,typename TipEl2>
auto operator *(const GMatrica<TipEl3> &m, TipEl2 d) -> GMatrica<decltype(m.niz[0][0]*d)> {
    if(m.br_kolona<0 || m.br_kolona>4 || m.br_redova<0 || m.br_redova>4) throw domain_error("Nedozvoljena operacija");
    GMatrica<decltype(d*m.niz[0][0])> m1;
    m1.br_kolona=m.br_kolona; m1.br_redova=m.br_redova;
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
            m1.niz[i][j]=d*m.niz[i][j];
    return m1;
}
template<typename TipEl>
GMatrica<TipEl> &GMatrica<TipEl>::operator +=(const GMatrica<TipEl> &m2) {
    for(int i=0;i<m2.br_redova;i++)
        for(int j=0;j<m2.br_kolona;j++)
            niz[i][j] += m2.niz[i][j];
    return *this;
}
template<typename TipEl>
GMatrica<TipEl> &GMatrica<TipEl>::operator -=(const GMatrica<TipEl> &m2) {
    for(int i=0;i<m2.br_redova;i++)
        for(int j=0;j<m2.br_kolona;j++)
            niz[i][j] -= m2.niz[i][j];
    return *this;
}
template<typename TipEl>
GMatrica<TipEl> &GMatrica<TipEl>::operator *=(const GMatrica<TipEl> &m2) {
    for(int i=0;i<br_redova;i++) 
        for(int j=0;j<m2.br_kolona;j++)
            for(int k=0;k<m2.br_redova;k++)
                niz[i][j] +=niz[i][k]*m2.niz[k][j];
    return *this;
}
template<typename TipEl>
GMatrica<TipEl> &GMatrica<TipEl>::operator *=(TipEl d) {
    for(int i=0;i<br_redova;i++) 
        for(int j=0;j<br_kolona;j++)
            niz[i][j]=niz[i][j]*d;
    return *this;
}
template<typename TipEl>
bool operator ==(const GMatrica<TipEl> &m1, const GMatrica<TipEl> &m2) {
    if(m1.br_redova!=m2.br_redova) return false;
    if(m1.br_kolona!=m2.br_kolona) return false;
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
            if(m1.niz[i][j]!=m2.niz[i][j]) return false;
    return true;
}
template<typename TipEl>
bool operator !=(const GMatrica<TipEl> &m1, const GMatrica<TipEl> &m2) {
    if(m1.br_redova!=m2.br_redova) return true;
    if(m1.br_kolona!=m2.br_kolona) return true;    
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
            if(m1.niz[i][j]!=m2.niz[i][j]) return true;
    return false;
}
template<typename TipEl>
TipEl &GMatrica<TipEl>::operator ()(int a, int b) {
    if(a<1 || a>4 || b<1 || b>4) throw range_error("Nedozvoljen indeks");
    return niz[a-1][b-1];
}
template<typename TipEl>
TipEl GMatrica<TipEl>::operator ()(int a, int b) const {
    if(a<1 || a>4 || b<1 || b>4) throw range_error("Nedozvoljen indeks");
    return niz[a-1][b-1];
} 

template<typename TipEl>
ostream& operator<<(ostream &tok, const GMatrica<TipEl> &m) {
    for(int i=0;i<m.br_redova;i++)  {
        for(int j=0;j<m.br_kolona;j++)
            tok << setw(6) << m.niz[i][j]; 
        tok<<endl; }
    return tok;
}
template<typename TipEl>
istream &operator >>(istream &izlaz, GMatrica<TipEl> &m) {
    char znak;
    izlaz>> ws;
    if(izlaz.peek()!='[') {
        for(int i=0;i<m.br_redova;i++) 
            for(int j=0;j<m.br_kolona;j++)
               izlaz>> m.niz[i][j];
    }
    else { 
        for(int i=0;i<m.br_redova;i++) {
            for(int j=0;j<m.br_kolona;j++){
                izlaz>> m.niz[i][j] >>znak;
                if(znak!=',') izlaz.setstate(std::ios::failbit); }
                if(znak!=';') izlaz.setstate(std::ios::failbit); }
        if(znak!=']') izlaz.setstate(std::ios::failbit);
    }
    return izlaz; 
}

int main ()
{
   GMatrica<int> m1;
   std::cin >> m1;
   std::cout << m1 << std::endl;
	return 0;
}
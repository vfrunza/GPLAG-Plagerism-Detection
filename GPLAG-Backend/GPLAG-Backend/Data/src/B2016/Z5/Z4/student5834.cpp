/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include<stdexcept>
#include<vector>
#include<initializer_list>
#include<iomanip>
#include<string>
template<typename tip>
class GMatrica
{
    int red,kolona;
    tip mat[4][4];
public:
    GMatrica () {
        red=0;
        kolona=0;
    }

    GMatrica(int x,int y,tip n=tip()):red(x),kolona(y) {
        if(x<0 || x>4 || y<0 || y>4) throw std::logic_error("Ilegalan format matrice");
        for(int i=0; i<x; i++)
            for(int j=0; j<y; j++)
                mat[i][j]=n;
    }
    template<typename tip2>
    GMatrica(const GMatrica<tip2> &m) {
        for(int i=0; i<m.red; i++)
            for(int j=0; j<m.kolona; j++)
                mat[i][j]=m[i][j];
        red=m.red;
        kolona=m.kolona;
    }
    template<typename tip1>
    GMatrica(tip1 m[4][4]) {
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                mat[i][j]=m[i][j];
        kolona=4;
        red=4;
    }
    GMatrica(std::vector<std::vector<tip>> m) {
        if(m.size()<0 || m.size()>4 || m[0].size()<0 || m[0].size()>4) throw std::logic_error("Ilegalan format matrice");
        for(int i=0; i<m.size()-1; i++)
            if(m[i].size()!=m[i+1].size())
                throw std::logic_error("Ilegalan format matrice");
        red=m.size();
        kolona=m[0].size();
        for(int i=0; i<red; i++)
            for(int j=0; j<kolona; j++)
                mat[i][j]=m[i][j];
    }
    GMatrica(std::initializer_list<std::initializer_list<tip>> m) {
        auto it(m.begin()),it1(m.begin());
        if(m.size()<0 || m.size()>4 || it->size()<0 || it->size()>4) throw std::logic_error("Ilegalan format matrice");
        for(auto i(m.begin()); i!=m.end(); i++)
            if(i->size()!=(i)->size())
                throw std::logic_error("Ilegalan format matrice");
        red=m.size();
        kolona=it1->size();
        for(int i=0; i<red; i++) {
            auto it2=it1->begin();
            for(int j=0; j<kolona; j++)
                mat[i][j]=*it2++;
            it1++;
        }
    }
    int DajBrojRedova() {
        return red;
    }
    int DajBrojKolona() {
        return kolona;
    }
    template <typename Tip6>
    friend std::ostream& operator <<(std::ostream &tok,const GMatrica<Tip6> &m);
    template <typename Tip3>
    friend std::istream& operator >>(std::istream &tok, GMatrica<Tip3> &m) ;

    template <typename Tip3>
    friend GMatrica<Tip3> operator +(const GMatrica<Tip3> &m1,const GMatrica<Tip3> &m2);
    template <typename Tip8>
    friend GMatrica<Tip8> operator +(const GMatrica<Tip8> &m1,const Tip8 n);
    template <typename Tip7>
    friend GMatrica<Tip7> operator +(const Tip7 n,const GMatrica<Tip7> &m2);

    template <typename Tip4>
    friend GMatrica<Tip4> operator -(const GMatrica<Tip4> &m1,const GMatrica<Tip4> &m2);
    template <typename Tip8>
    friend GMatrica<Tip8> operator -(const GMatrica<Tip8> &m1,const Tip8 n);
    template <typename Tip7>
    friend GMatrica<Tip7> operator -(const Tip7 n,const GMatrica<Tip7> &m2);

    template <typename Tip5>
    friend GMatrica<Tip5> operator *(const GMatrica<Tip5> &m1,const GMatrica<Tip5> &m2);
    template <typename Tip8>
    friend GMatrica<Tip8> operator *(const GMatrica<Tip8> &m1,const Tip8 n);
    template <typename Tip7>
    friend GMatrica<Tip7> operator *(const Tip7 n,const GMatrica<Tip7> &m2);

    template <typename Tip9>
    friend GMatrica<Tip9> &operator +=(GMatrica<Tip9> &m1, GMatrica<Tip9> &m2);
    template <typename Tip10>
    friend GMatrica<Tip10> &operator -=(GMatrica<Tip10> &m1, GMatrica<Tip10> &m2);
    template <typename Tip11>
    friend GMatrica<Tip11> &operator *=(GMatrica<Tip11> &m1, GMatrica<Tip11> &m2);
    template <typename Tip9>
    friend GMatrica<Tip9> &operator +=( GMatrica<Tip9> &m1,const Tip9 n);
    template <typename Tip10>
    friend GMatrica<Tip10> &operator -=( GMatrica<Tip10> &m1,const Tip10 n);
    template <typename Tip11>
    friend GMatrica<Tip11> &operator *=( GMatrica<Tip11> &m1,const Tip11 n);

    template <typename Tip11>
    friend bool operator ==(const GMatrica<Tip11> &m1,const GMatrica<Tip11> &m2);
    template <typename Tip11>
    friend bool operator !=(const GMatrica<Tip11> &m1,const GMatrica<Tip11> &m2);
    
    tip *operator[](int x) {
        return mat[x];
    }
    auto operator ()(int x,int y)-> decltype(mat[0][0]);
    auto operator ()(int x,int y)const-> decltype(mat[0][0]+mat[0][0]);
    
};
template <typename Tip11>
auto GMatrica<Tip11>::operator ()(int x,int y)->decltype(mat[0][0]){
    if(x<0 || x>4 || y<0 || y>4) throw std::logic_error("Ilegalan format matrice");
    return mat[x-1][y-1];
}
template <typename Tip11>
auto GMatrica<Tip11>::operator ()(int x,int y)const ->decltype(mat[0][0]+mat[0][0]){
    if(x<0 || x>4 || y<0 || y>4) throw std::logic_error("Ilegalan format matrice");
    return mat[x-1][y-1];
}
//********************************
template <typename Tip11>
bool operator ==(const GMatrica<Tip11> &m1,const GMatrica<Tip11> &m2)
{

    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m1.kolona; j++)
            if(m1.mat[i][j] != m2.mat[i][j]) return false;
    return true;
}
template <typename Tip11>
bool operator !=(const GMatrica<Tip11> &m1,const GMatrica<Tip11> &m2)
{

    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m1.kolona; j++)
            if(m1.mat[i][j] != m2.mat[i][j]) return true;
    return false;
}
//***********************
template <typename Tip9>
GMatrica<Tip9> &operator +=( GMatrica<Tip9> &m1,const Tip9 n)
{
    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m1.kolona; j++)
            m1.mat[i][j] = m1.mat[i][j] + n;
    return m1;
}
template <typename Tip10>
GMatrica<Tip10> &operator -=( GMatrica<Tip10> &m1,const Tip10 n)
{
    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m1.kolona; j++)
            m1.mat[i][j] = m1.mat[i][j] -n;
    return m1;
}
template <typename Tip11>
GMatrica<Tip11> &operator *=( GMatrica<Tip11> &m1,const Tip11 n)
{
    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m1.kolona; j++)
            m1.mat[i][j] = m1.mat[i][j] * n;
    return m1;
}
//*********************
template <typename Tip9>
GMatrica<Tip9> &operator +=(GMatrica<Tip9> &m1, GMatrica<Tip9> &m2)
{
    if(m1.red != m2.red || m1.kolona != m2.kolona)
        throw std::domain_error("Nedozvoljena operacija");
    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m1.kolona; j++)
            m1.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
    return m1;
}
template <typename Tip9>
GMatrica<Tip9> &operator -=(GMatrica<Tip9> &m1, GMatrica<Tip9> &m2)
{
    if(m1.red != m2.red || m1.kolona != m2.kolona)
        throw std::domain_error("Nedozvoljena operacija");
    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m1.kolona; j++)
            m1.mat[i][j] = m1.mat[i][j] - m2.mat[i][j];
    return m1;
}
template <typename Tip9>
GMatrica<Tip9> &operator *=(GMatrica<Tip9> &m1, GMatrica<Tip9> &m2)
{
    if(m1.kolona!=m2.red)
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<Tip9> m3;
    m3.red=m1.red;
    m3.kolona=m2.kolona;
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++)
            m3.elementi[i][j]=0;

    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m2.kolona; j++)
            for(int k=0; k<m1.kolona; k++) {
                m3.mat[i][j]+=m1.mat[i][k]*m2.mat[k][j];
            }
    for(int i = 0; i < m3.red; i++)
        for(int j = 0; j < m3.kolona; j++)
            m1.mat[i][j]=m3.mat[i][j];
    return m1;
}
//****************************
template<typename tip>
GMatrica<tip> operator +(const GMatrica<tip> &m1,const GMatrica<tip> &m2)
{
    if(m1.red != m2.red || m1.kolona != m2.kolona)
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<tip> m3;
    m3.red=m1.red;
    m3.kolona=m1.kolona;
    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m1.kolona; j++)
            m3.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
    return m3;
}
template <typename Tip8>
GMatrica<Tip8> operator +(const GMatrica<Tip8> &m1,const Tip8 n)
{
    GMatrica<Tip8> m3;
    m3.red=m1.red;
    m3.kolona=m1.kolona;
    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m1.kolona; j++)
            m3.mat[i][j] = m1.mat[i][j] + n;
    return m3;
}
template <typename Tip7>
GMatrica<Tip7> operator +(const Tip7 n,const GMatrica<Tip7> &m2)
{
    GMatrica<Tip7> m3;
    m3.red=m2.red;
    m3.kolona=m2.kolona;
    for(int i = 0; i < m2.red; i++)
        for(int j = 0; j < m2.kolona; j++)
            m3.mat[i][j] = m2.mat[i][j] + n;
    return m3;
}
//*******************************
template <typename Tip8>
GMatrica<Tip8> operator -(const GMatrica<Tip8> &m1,const Tip8 n)
{
    GMatrica<Tip8> m3;
    m3.red=m1.red;
    m3.kolona=m1.kolona;
    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m1.kolona; j++)
            m3.mat[i][j] = m1.mat[i][j] - n;
    return m3;
}
template <typename Tip7>
GMatrica<Tip7> operator -(const Tip7 n,const GMatrica<Tip7> &m2)
{
    GMatrica<Tip7> m3;
    m3.red=m2.red;
    m3.kolona=m2.kolona;
    for(int i = 0; i < m2.red; i++)
        for(int j = 0; j < m2.kolona; j++)
            m3.mat[i][j] = m2.mat[i][j] -n;
    return m3;
}
template<typename tip>
GMatrica<tip> operator -(const GMatrica<tip> &m1,const GMatrica<tip> &m2)
{
    if(m1.red != m2.red || m1.kolona != m2.kolona)
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<tip> m3;
    m3.red=m1.red;
    m3.kolona=m1.kolona;
    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m1.kolona; j++)
            m3.mat[i][j] = m1.mat[i][j] - m2.mat[i][j];
    return m3;
}

template <typename tip>
GMatrica<tip> operator *(const GMatrica<tip> &m1, const GMatrica<tip> &m2)
{
    if(m1.kolona!=m2.red)
        throw std::domain_error("“Matrice nisu saglasne za množenje");
    GMatrica<tip> m3;
    m3.red=m1.red;
    m3.kolona=m1.kolona;
    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m2.kolona; j++)
            m3.mat[i][j]=0;
    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m2.kolona; j++)
            for(int k=0; k<m1.kolona; k++)
                m3.mat[i][j]+=m1.mat[i][k]*m2.mat[k][j];
    return m3;
}
template <typename TipEl>
GMatrica<TipEl> operator *(const GMatrica<TipEl> &m1,const TipEl n)
{
    GMatrica<TipEl> m3;
    m3.red=m1.red;
    m3.kolona=m1.kolona;
    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m1.kolona; j++)
            m3.mat[i][j] = m1.mat[i][j] *n;
    return m3;
}

template <typename TipEl>
GMatrica<TipEl> operator *(const TipEl n,const GMatrica<TipEl> &m1)
{
    GMatrica<TipEl> m3;
    m3.red=m1.red;
    m3.kolona=m1.kolona;
    for(int i = 0; i < m1.red; i++)
        for(int j = 0; j < m1.kolona; j++)
            m3.mat[i][j] = m1.mat[i][j] *n;
    return m3;
}
//************************
template <typename tip>
std::ostream &operator <<(std::ostream &tok,const GMatrica<tip> &m)
{
    int sirina=tok.width();
    if(sirina<6) sirina=6;
    for(int i = 0; i < m.red; i++) {
        for(int j = 0; j < m.kolona; j++) {
            tok<<std::setw(sirina)<<m.mat[i][j];
        }
        tok<<std::endl;
    }
    return tok;
}
template <typename Tip3>
std::istream& operator >>(std::istream &tok, GMatrica<Tip3> &m)
{
    std::string s;
    tok>>s;
    int r=0,k=0,kol;
    for(int i=0;i<s.length();i++){
       if(s[i]=='['){
          g: i++;
           if(s[i]<'0' || s[i]>'9'); //neispravan;
           if(s[i]>='0' && s[i]<='9') m.mat[r][k++]=s[i]-'0';
           
           i++;
           if(s[i]==',') goto g;
           if(s[i]==';') {kol=k; k=0; r++;  goto g;}
           if(s[i]==']') { break;}
       }
    }
    m.red=r+1;
    m.kolona=kol;

    return tok;
}
//*************************************

int main ()
{
   GMatrica<int> m1({{1, 2}, {3, 4}});
   std::cout << m1(1,1) << std::endl;
   std::cout << m1[1][1] << std::endl;
    return 0;
}
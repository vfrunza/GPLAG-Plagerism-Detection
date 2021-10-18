/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <memory>
#include <climits>
using namespace std;
template <typename tip>
class GMatrica{
    int br_redova;
    int br_kolona;
    tip niz[4][4];
    public:
    GMatrica(){
        br_kolona=0;
        br_redova=0;
    }
    GMatrica(int br_k,int br_r,tip vrijednost){
        if(br_k<0 || br_k>4 || br_r<0 || br_r>4)throw logic_error("Ilegalan format matrice");
        br_kolona=br_k;
        br_redova=br_r;
        for(int i=0;i<br_kolona;i++){
            fill(niz[i].begin(),niz[i].end,vrijednost);
        }
    }
    template <typename tip1>
    GMatrica(GMatrica &matrica){
        for(int i=0;i<matrica.br_kolona;i++){
            for(int j=0;j<matrica.br_redova;j++){
                niz[i][j]=matrica[i][j];
            }
        }
        br_kolona=matrica.br_kolona;
        br_redova=matrica.br_redova;
    }
    template <typename tip2>
    GMatrica(tip2 niz1[4][4]){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                niz[i][j]=niz1[i][j];
            }
        }
        br_kolona=4;
        br_redova=4;
    }
    GMatrica(vector<vector<tip> > &v){
        if(v.size()>4 || v.size()<0)throw logic_error("Ilegalan formal matrice");
        for(int i=0;i<v.size();i++)if(v[i].size()<0 || v[i].size()>4)throw logic_error("Ilegalan format matrice");
        GMatrica pomocna;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                pomocna.niz[i][j]=v[i][j];
            }
        }
        br_kolona=v.size();
        br_redova=v[0].size();
    }
    GMatrica(initializer_list<initializer_list<tip> > v){
        if(v.size()>4 || v.size()<0)throw logic_error("Ilegalan formal matrice");
        for(auto i=v.begin();i!=v.end();i++)if(i->size()<0 || i->size()>4)throw logic_error("Ilegalan formal matrice");
        int br(0),br_r;
        for(auto i=v.begin();i!=v.end();i++){
            int br1(0);
            for(auto j=i->begin();j!=i->end();j++){
                niz[br][br1]=*j;
                br1++;
            }
            br++;
            br_r=br1;
        }
        br_kolona=br;
        br_redova=br_r;
    }
    tip& operator ()(tip a,tip b){
    if(a<0 || a>4 || b<0 || b>4)throw range_error("Nedozvoljen indeks");
    return niz[a-1][b-1];
    }
    tip operator ()(tip a,tip b)const{
    if(a<0 || a>4 || b<0 || b>4)throw range_error("Nedozvoljen indeks");
    return niz[a-1][b-1];
    }
    tip* operator [](int a){
        tip* pok(niz[a]);
    return pok;
    }
    tip operator [](int a)const{
    return niz[a];
    }
    template <typename tip1>
    friend GMatrica<tip1>& operator +=(GMatrica<tip1>& m,GMatrica<tip1> m1);
    template <typename tip1>
    friend GMatrica<tip1>& operator -=(GMatrica<tip1>& m,GMatrica<tip1> m1);
    template <typename tip1>
    friend GMatrica<tip1>& operator *=(GMatrica<tip1>& m,GMatrica<tip1> m1);
    template <typename tip1>
    friend GMatrica<tip1>& operator *=(GMatrica<tip1>& m,tip1 n);
    template <typename tip1>
    friend bool operator ==(GMatrica<tip1>& m,GMatrica<tip1>& m1);
    template <typename tip1>
    friend bool operator !=(GMatrica<tip1>& m,GMatrica<tip1>& m1);
    template <typename tip1>
    friend inline GMatrica<tip1> operator +(GMatrica<tip1> &m1,GMatrica<tip1> m2);
    template <typename tip1>
    friend inline GMatrica<tip1> operator -(GMatrica<tip1>& m1,GMatrica<tip1> m2);
    template <typename tip1>
    friend inline GMatrica<tip1> operator *(GMatrica<tip1> m1,GMatrica<tip1> m2);
    template <typename tip1>
    friend inline GMatrica<tip1> operator *(GMatrica<tip1> m1,tip1 n);
    tip DajBrojRedova()const{return br_redova;}
    tip DajBrojKolona()const{return br_kolona;}
    template <typename tip1>
    friend ostream &operator <<(ostream &tok,const GMatrica<tip1>& m);
    template <typename tip1>
    friend istream &operator >>(istream &tok,GMatrica<tip1>& m);
};
template <typename tip>
    inline GMatrica<tip> operator +(GMatrica<tip> &m1,GMatrica<tip> m2){
    if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova)throw domain_error("Nedozvoljena operacija");
    return (m1+=m2);
}
template <typename tip>
    inline GMatrica<tip> operator *(GMatrica<tip> &m1,GMatrica<tip> m2){
        if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova)throw domain_error("Nedozvoljena operacija");
        return (m1*=m2);
}
template <typename tip>
    inline GMatrica<tip> operator *(GMatrica<tip> m,tip n){
        return m*=n;
}
template <typename tip>
    inline GMatrica<tip> operator *(tip n,GMatrica<tip> m){
        return m*=n;
}
template <typename tip>
    inline GMatrica<tip> operator -(GMatrica<tip>& m1,GMatrica<tip> m2){
        if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova)throw domain_error("Nedozvoljena operacija");
        return (m1-=m2);
}
template <typename tip>
GMatrica<tip>& operator +=(GMatrica<tip>& m,GMatrica<tip> m1){
    if(m1.br_kolona!=m.br_kolona || m1.br_redova!=m.br_redova)throw domain_error("Nedozvoljena operacija");
    for(int i=0;i<m1.br_kolona;i++){
        for(int j=0;j<m1.br_redova;j++){
            m.niz[i][j]=m.niz[i][j]+m1.niz[i][j];
        }
    }
    return m;
}
template <typename tip>
GMatrica<tip>& operator -=(GMatrica<tip> &m,GMatrica<tip> m1){
    if(m1.br_kolona!=m.br_kolona || m1.br_redova!=m.br_redova)throw domain_error("Nedozvoljena operacija");
    for(int i=0;i<m1.br_kolona;i++){
        for(int j=0;j<m1.br_redova;j++){
            m.niz[i][j]=m.niz[i][j]-m1.niz[i][j];
        }
    }
    return m;
}
template <typename tip>
GMatrica<tip>& operator *=(GMatrica<tip> &m,GMatrica<tip> m1){
    if(m1.br_kolona!=m.br_kolona || m1.br_redova!=m.br_redova)throw domain_error("Nedozvoljena operacija");
    for(int i=0;i<m1.br_kolona;i++){
        for(int j=0;j<m1.br_redova;j++){
            tip clan;
            for(int k=0;k<m1.br_redova;k++)clan+=m.niz[i][k]*m1.niz[k][j];
        m.niz[i][j]=clan;
        }
        
    }
    return m;
}
template <typename tip>
inline GMatrica<tip>& operator *=(GMatrica<tip> &m,tip n){
    for(int i=0;i<m.br_kolona;i++){
        for(int j=0;j<m.br_redova;j++){
            m.niz[i][j]*=n;
        }
    }
    return m;
}
template <typename tip>
inline bool operator ==(GMatrica<tip> &m,GMatrica<tip> &m1){
    if(m1.br_kolona!=m.br_kolona || m1.br_redova!=m.br_redova)throw domain_error("Nedozvoljena operacija");
    for(int i=0;i<m1.br_kolona;i++){
        for(int j=0;j<m1.br_redova;j++){
            if(m.niz[i][j]!=m1.niz[i][j])return false;
        }
    }
    return true;
}
template <typename tip>
inline bool operator !=(GMatrica<tip> &m,GMatrica<tip> &m1){
    if(m1.br_kolona!=m.br_kolona || m1.br_redova!=m.br_redova)throw domain_error("Nedozvoljena operacija");
    for(int i=0;i<m1.br_kolona;i++){
        for(int j=0;j<m1.br_redova;j++){
            if(m.niz[i][j]!=m1.niz[i][j])return true;
        }
    }
    return false;
}
template <typename tip1>
    ostream &operator <<(ostream &tok,const GMatrica<tip1>& m){
        for(int i=0;i<m.br_kolona;i++){
            for(int j=0;j<m.br_redova;j++){
                tok<<setw(6)<<m.niz[i][j];
            }
            tok<<'\n';
        }
        return tok;
    }
template <typename tip1>
    istream &operator >>(istream &tok,GMatrica<tip1>& m){
        string unos;
        int br(0),br1(0);
        tok>>unos;
        if(unos[0]!='[')tok.setstate(ios::failbit);
        for(int i=0;i<unos.length();i++){
            if(i%2!=0)br++;
            if(unos[i]==';' || unos[i]==']'){
            m.br_redova=br;
            br=0;
            br1++;
        }
        }
        m.br_kolona=br1;
        int k(0),r(0);
        for(int i=0;i<unos.length();i++){
            if(i%2!=0){
                m.niz[k][r]=unos[i]-48;
                r++;
            }
            if(i%2==0 && i>0  && unos[i]!=';' && unos[i]!=',')tok.setstate(ios::failbit);
            if(unos[i]==';'){
                k++;
                r=0;
            }
        }
        return tok;
    }

int main (){   
   GMatrica<int> m1,m2{{1}};
   cout<<m2;
   std::cin >> m1;
   std::cout << m1 << std::endl;
	return 0;
}
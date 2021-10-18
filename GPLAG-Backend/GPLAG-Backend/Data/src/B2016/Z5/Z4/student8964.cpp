/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <vector>
#include <initializer_list>

using namespace std;

template <typename Tip>
class GMatrica
{
    Tip podaci[4][4];
    int br_redova,br_kolona;

public:
    GMatrica() {};
    GMatrica(int br_redova,int br_kolona,Tip vrijednost=0);
    GMatrica(const GMatrica<Tip>&m);
    GMatrica(Tip vrijednost):
        br_redova(4),br_kolona(4) {
        fill(&(podaci[0][0]),&(podaci[3][3])+1,vrijednost);
    }
    GMatrica(vector<vector<Tip>>m);
    GMatrica(initializer_list<GMatrica<Tip>>lista);

    int DajBrojRedova() const {
        return br_redova;
    }
    int DajBrojKolona() const {
        return br_kolona;
    }
    template<typename Tip2,typename Tip3>
    friend GMatrica<decltype(Tip3()+Tip2())>operator+(const GMatrica<Tip2>&m1,const GMatrica<Tip3>&m2);
    template<typename Tip2,typename Tip3>
    friend GMatrica<decltype(Tip3()-Tip2())>operator-(const GMatrica<Tip2>&m1,const GMatrica<Tip3>&m2);
    template<typename Tip2,typename Tip3>
    friend GMatrica<decltype(Tip3()*Tip2())>operator*(const GMatrica<Tip2>&m1,const GMatrica<Tip3>&m2);
    template<typename Tip2,typename Tip3>
    friend GMatrica<decltype(Tip3()*Tip2())>operator*(const GMatrica<Tip2>&m,Tip3 k);
    template<typename Tip2,typename Tip3>
    friend GMatrica<decltype(Tip3()*Tip2())>operator*(Tip3 k,const GMatrica &m);

    GMatrica &operator+=(const GMatrica<Tip>&m);
    GMatrica &operator-=(const GMatrica<Tip>&m);
    GMatrica &operator*=(const GMatrica<Tip>&m);

    template<typename Tip2,typename Tip3>
    friend bool operator==(const GMatrica<Tip2>&m1,const GMatrica<Tip3>&m2);
    template<typename Tip2,typename Tip3>
    friend bool operator!=(const GMatrica<Tip2>&m,const GMatrica<Tip>&m2);

    Tip operator()(int i,int j) const {
        if(i<1 || i>br_redova || j<1 || j>br_kolona)
            throw range_error("Nedozvoljen indeks");
        return podaci[i-1][j-1];
    }
    Tip& operator()(int i,int j) {
        if(i<1 || i>br_redova || j<1 || j>br_kolona)
            throw range_error("Nedozvoljen indeks");
        return podaci[i-1][j-1];
    }

    vector<Tip>operator [](int i)const {
        return podaci[i];
    }
    vector<Tip>&operator [](int i) {
        return podaci[i];
    }

    template<typename Tip1>
    friend ostream& operator<<(ostream &tok,const GMatrica<Tip>&m)
    {
    auto x=tok.width();
    for(int i=0; i<m.DajBrojRedova(); i++) {
        for(int j=0; j<m.DajBrojKolona(); j++) {
            tok<<setw(6)<<m.podaci[i][j];
            tok<<"\n";
        }
    }
    return tok;
}
    template<typename Tip1>
    friend istream& operator>>(istream &tok,const GMatrica<Tip1>&m);


};


template<typename Tip>
GMatrica<Tip>::GMatrica(int br_redova,int br_kolona,Tip vrijednost):
    br_redova(br_redova),br_kolona(br_kolona)
{
    if(br_redova<0 || br_redova>4 || br_kolona<0 || br_kolona>4) throw logic_error("Ilegalan format matrice");
    fill(&(podaci[0][0]),&(podaci[3][3])+1,vrijednost);
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<br_kolona; j++) {
            podaci[i][j]=vrijednost;
        }
    }
}

template<typename Tip>
GMatrica<Tip>::GMatrica(vector<vector<Tip>>m)
{
    for(int i=0; i<m.size(); i++) {
        for(int j=0; j<m[0].size()-1; j++) {
            if(m.size()<0 || m.size()>4 || m[j].size()!=m[j+1].size()) throw logic_error("Ilegalan format matrice");
            break;
        }
    }
br_redova=m.size(); br_kolona=m[0].size();
    for(int i=0; i<DajBrojRedova(); i++) {
        for(int j=i; j<DajBrojKolona(); j++) {
            podaci[i][j]=m[i][j];
        }
    }
}

/*
template<typename Tip>
GMatrica<Tip>::GMatrica(initializer_list<GMatrica<Tip>>lista)
{
    for(auto it=lista.begin(); it!=lista.end(); it++) {
        auto it1=it;
        it1++;
        for(; it1!=lista.end(); it1++) {
            if(it<0 || it>4 || (it->size()!=it1->size()))
            }
    }
    for(int it=lista.begin(); it!=lista.end(); it++) {
        podaci=*(it);
    }
}

*/

template<typename Tip2,typename Tip3>
GMatrica<decltype(Tip3()+Tip2())>operator+(const GMatrica<Tip2>&m1,const GMatrica<Tip3>&m2)
{
    if(m1.DajBrojKolona()!=m2.DajBrojKolona() || m1.DajBrojRedova()!=m2.DajBrojRedova()) throw domain_error("Nedozvoljena operacija");

    auto x=m1.podaci[0][0]+m2.podaci[0][0];
    vector<vector<decltype(x)>>mat;
    mat.resize(m1.DajBrojKolona());

    for(int i=0; i<m1.DajBrojRedova(); i++) {
        for(int j=0; j<m1.DajBrojKolona(); j++) {
            mat[i].push_back(m1.podaci[i][j]+m2.podaci[i][j]);
        }
    }
    GMatrica<decltype(x)>m(mat);
    return m;
}

template<typename Tip2,typename Tip3>
GMatrica<decltype(Tip3()-Tip2())>operator-(const GMatrica<Tip2>&m1,const GMatrica<Tip3>&m2)
{
    if(m1.DajBrojKolona()!=m2.DajBrojKolona() || m1.DajBrojRedova()!=m2.DajBrojRedova()) throw domain_error("Nedozvoljena operacija");

    auto x=m1.podaci[0][0]+m2.podaci[0][0];
    vector<vector<decltype(x)>>mat;
    mat.resize(m1.DajBrojRedova());
    for(int i=0; i<m1.DajBrojRedova(); i++) {
        for(int j=0; j<m1.DajBrojKolona(); j++) {
            mat[i].push_back(m1.podaci[i][j]-m2.podaci[i][j]);
        }
    }
    GMatrica<decltype(x)>m(mat);

    return m;
}

template<typename Tip2,typename Tip3>
GMatrica<decltype(Tip3()*Tip2())>operator*(const GMatrica<Tip2>&m1,const GMatrica<Tip3>&m2)
{
    if(m1.DajBrojKolona()!=m2.DajBrojRedova()) throw domain_error("Nedozvoljena operacija");

    auto x=m1.podaci[0][0]*m2.podaci[0][0];
    vector<vector<decltype(x)>>mat;
    mat.resize(m1.DajBrojRedova());

    for(int i=0; i<m1.DajBrojRedova(); i++) {
        mat[i].resize(m2.DajBrojKolona());
        for(int j=0; j<m2.DajBrojKolona(); j++) {
            for(int k=0; k<m1.DajBrojKolona(); k++) {
                mat.podaci[i][j]+=m1.podaci[i][k]*m2.podaci[k][j];
            }
        }
    }
    GMatrica<decltype(x)>m(mat);
    return m;
}

template<typename Tip2,typename Tip3>
GMatrica<decltype(Tip3()*Tip2())>operator*(const GMatrica<Tip2>&m1,Tip3 m2)
{

    auto x=m1.podaci[0][0]*m2;
    vector<vector<decltype(x)>>mat;
    mat.resize(m1.DajBrojRedova());
    for(int i=0; i<m1.DajBrojRedova(); i++) {
        for(int j=0; j<m1.DajBrojKolona(); j++) {
            mat.podaci[i][j]=m1.podaci[i][j]*m2;
        }
    }
    GMatrica<decltype(x)>m(mat);
    return m;
}

template<typename Tip2,typename Tip3>
GMatrica<decltype(Tip3()*Tip2())>operator*(Tip3 m2,const GMatrica<Tip2>&m1)
{
    auto x=m1.podaci[0][0]*m2;
    vector<vector<decltype(x)>>mat;
    mat.resize(m1.DajBrojRedova());
    for(int i=0; i<m1.DajBrojRedova(); i++) {
        for(int j=0; j<m1.DajBrojKolona(); j++) {
            mat.podaci[i][j]=m1.podaci[i][j]*m2;
        }
    }
    GMatrica<decltype(x)>m(mat);
    return m;

}

template<typename Tip>
GMatrica<Tip>&GMatrica<Tip>::operator+=(const GMatrica<Tip>&m)
{
    if(DajBrojKolona()!=m.DajBrojKolona() || DajBrojRedova()!=m.DajBrojRedova()) throw domain_error("Nedozvoljena operacija");
    for(int i=0; i<DajBrojRedova(); i++) {
        for(int j=0; j<DajBrojKolona(); j++) {
            podaci[i][j]+=m.podaci[i][j];
        }
    }
    return *this;
}

template<typename Tip>
GMatrica<Tip>&GMatrica<Tip>::operator-=(const GMatrica<Tip>&m)
{
    if(DajBrojKolona()!=m.DajBrojKolona() || DajBrojRedova()!=m.DajBrojRedova()) throw domain_error("Nedozvoljena operacija");
    for(int i=0; i<DajBrojRedova(); i++) {
        for(int j=0; j<DajBrojKolona(); j++) {
            podaci[i][j]-=m.podaci[i][j];
        }
    }
    return *this;
}

template<typename Tip>
GMatrica<Tip>&GMatrica<Tip>::operator*=(const GMatrica<Tip>&m)
{
    if(DajBrojKolona()!=m.DajBrojRedova()) throw domain_error("Nedozvoljena operacija");
    for(int i=0; i<DajBrojRedova(); i++) {
        for(int j=0; j<m.DajBrojKolona(); j++) {
            podaci[i][j]=0;
            for(int k=0; k<DajBrojKolona(); k++) {
                podaci[i][j]+=podaci[i][k]*m.podaci[k][j];
            }
        }
    }
    return *this;
}

template<typename Tip2,typename Tip3>
bool operator==(const GMatrica<Tip2>&m1,const GMatrica<Tip3>&m2)
{
    if(m1.DajBrojKolona()!=m2.DajBrojKolona() || m1.DajBrojRedova()!=m2.DajBrojRedova()) return false;

    for(int i=0; i<m1.DajBrojRedova(); i++) {
        for(int j=0; j<m2.DajBrojKolona(); j++) {
            if(m1.podaci[i][j]!=m2.podaci[i][j])
                return false;
        }
    }
    return true;
}

template<typename Tip>
bool operator!=(const GMatrica<Tip>&m1,const GMatrica<Tip>&m2)
{
    return!(m1==m2);
}




template<typename Tip1>
istream &operator >>(istream &tok, GMatrica<Tip1>&m)
{

    for(int i=0; i<m.DajBrojRedova(); i++) {
        tok>>ws;
        for(int j=0; j<m.DajBrojKolona(); j++) {
            tok>>m.podaci[i][j];
        }
    }
}


int main ()
{
   GMatrica<double> m1({{1, 2}, {3, 4}});
   GMatrica<double> m2({{1, 2}, {3, 4}});
   auto m3 = m1 + m2;
   std::cout << m3 << std::endl;
   GMatrica<double> m4({{1, 2}, {3, 4}});
   auto m5 = m3-m4;
   std::cout << m5 << std::endl;
    return 0;
}
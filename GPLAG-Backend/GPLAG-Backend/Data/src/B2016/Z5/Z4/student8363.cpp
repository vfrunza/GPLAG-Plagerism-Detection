/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <initializer_list>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void throwerr(int i=0) {
    if(!i)throw std::logic_error("Ilegalan format matrice");
    else if(i==1)throw std::domain_error("Nedozvoljena operacija");
}
template <typename T>
    class GMatrica{
        T m[4][4]{};
        int br_r=0, br_k=0;
        void checkBound(int a, int b){if(a<0 || b<0 || a>4 || b>4)throwerr();}
        void checkRange(int a, int b){if(a>br_r || a<1 || b>br_k || b<1)throw std::range_error("Neispravan indeks");}
    public: 
        int DajBrojKolona() const { return br_k;}
        int DajBrojRedova() const { return br_r;}
        GMatrica();
        GMatrica(int r, int k, T e = T());
        GMatrica(vector<vector<T>>);
        GMatrica(std::initializer_list<std::initializer_list<T>>);
        GMatrica(T pm[4][4]);
        T *operator [](int a) {return m[a];}
        T *operator [](int a) const {return m[a];}
        T &operator ()(int a, int b){checkRange(a,b); return m[a-1][b-1];}
        T operator ()(int a, int b) const {checkRange(a,b);return m[a-1][b-1];}
        template <typename T2>
        GMatrica &operator += (const GMatrica<T2> &b);
        template <typename T2>
        GMatrica &operator -= (const GMatrica<T2> &b);
        template <typename T2>
        GMatrica &operator *= (T2 k);
        template <typename T2>
        GMatrica &operator *=(const GMatrica<T2>&);
        template <typename T2>
        friend std::ostream &operator << (std::ostream &out,const GMatrica<T2>&);
        template <typename T2>
        friend std::istream &operator >> (std::istream &in, GMatrica<T2> &);
        template <typename T1, typename T2>
            friend auto operator + (const GMatrica<T1> &a, const GMatrica<T2> &b)->GMatrica<decltype (a.m[0][0] + b.m[0][0])>;
        template <typename T1, typename T2>
            friend auto operator - (const GMatrica<T1> &a, const GMatrica<T2> &b)->GMatrica<decltype (a.m[0][0] + b.m[0][0])>;
        template <typename T1, typename T2>
            friend auto operator * (const GMatrica<T1> &a, const GMatrica<T2> &b)->GMatrica<decltype (a.m[0][0] + b.m[0][0])>;
        template <typename T1, typename T2>
            friend auto operator * (const GMatrica<T1> &a,T2 k)->GMatrica<decltype (a.m[0][0]*k)>{
                GMatrica<decltype (a.m[0][0]*k)> izlaz(a.br_r,a.br_k);
                for(int i=0; i<a.br_r; i++)
                    for(int j=0; j<a.br_k; j++)
                        izlaz.m[i][j]=a.m[i][j]*k;
                return izlaz;
            }
     };
template <typename T>
    template <typename T2>
        GMatrica<T>& GMatrica<T>::operator += (const GMatrica<T2> &b){
            if(br_k != b.br_k || br_r != b.br_r)
                throwerr(1);
            for (int i = 0; i < br_r; i++) {
                for(int j=0;j<br_k;j++)
                    m[i][j]+=b.m[i][j];
            }
            return *this;
            }
template <typename T> 
    template <typename T2>
        GMatrica<T>& GMatrica<T>::operator -= (const GMatrica<T2> &b){
            if(br_k!=b.br_k || br_r!=b.br_r)throwerr(1);
            for(int i=0;i<br_r;i++)
                for(int j=0;j<br_k;j++)
                    this->m[i][j]-=b.m[i][j];
            return *this;
        }
template <typename T>
    template <typename T2>
        GMatrica<T>& GMatrica<T>::operator *=(T2 k){
            for (int i = 0; i < br_r; i++) {
                for(int j=0; j < br_k; j++)
                    m[i][j]*=k;
            }  
            return *this;
        }
template <typename T>
    template <typename T2>
        GMatrica<T>& GMatrica<T>::operator *=(const GMatrica<T2> &b){
            if(br_k != b.br_r)throwerr(1);
            for (int i = 0; i < br_r; i++) {
                for(int j=0;j<br_k;j++){
                    T2 e = 0;
                    for(int k=0; k<br_r;k++)
                        e+=m[i][k]*b.m[k][j];
                    m[i][j]=e;
                }
            }
            return *this;
        }
template <typename T>
    std::ostream &operator << (std::ostream &out, const GMatrica<T> &a){
        int w = out.width();
        if(w<6)w=6;
        for (int i = 0; i < a.br_r; i++) {
            for(int j = 0; j < a.br_k; j++)
                out<<std::setw(6)<<a.m[i][j];
            out<<'\n';
        }
        return out;
    }
template <typename T>
    std::istream &operator >> (std::istream &in, GMatrica<T> &a){
        in>>std::ws;
        if(in.get()!='['){in.setstate(std::ios::failbit);return in;}
        int kol = -1;
        GMatrica<T> tmp(a.br_k,a.br_r);
        for (int i = 0; i < 4; i++) {
            for(int j=0; j< 4; j++){
                in>>tmp.m[i][j];
                if(in.peek()==';'){
                    in.get();
                    if(kol==-1)kol = j;
                    else if(j!=kol){in.setstate(std::ios::failbit);return in;}
                    break;
                }
                else if(in.peek()==']'){
                    in.get();
                    if(kol != j && kol !=-1){in.setstate(std::ios::failbit);return in;}
                    a=tmp;
                    a.br_k=j+1;
                    a.br_r=i+1;
                    return in;
                }
                else if(in.peek()!=','){in.setstate(std::ios::failbit); return in;}
                in.get();
            }
        }
    }
template <typename T>
    GMatrica<T>::GMatrica(){}
template <typename T>
    GMatrica<T>::GMatrica(int r, int k, T e){
        checkBound(r,k);
        br_k = k; br_r = r;
        for (int i = 0; i < br_r; i++) {
            for(int j=0; j< br_k; j++)
                m[i][j]=e;
        }
    }
template <typename T>
    GMatrica<T>::GMatrica(vector<vector<T>> v){
        if(!v.size())throwerr();
        else if(v.size() > 4 || v[0].size() > 4 || !v[0].size())throwerr();
        br_r = v.size();
        br_k = v[0].size();
        for (int i = 0; i < br_r; i++) {
            if(v[i].size()!=br_k)throwerr();
            for( int j = 0; j < br_k; j++){
                m[i][j]=v[i][j];
            }
        }
    }
template <typename T>
    GMatrica<T>::GMatrica(std::initializer_list<std::initializer_list<T>> ini){
        br_r = ini.size();
        br_k = ini.begin()->size();
        checkBound(br_r,br_k);
        int i=0;
        auto it = ini.begin();
        for(;it!=ini.end();it++,i++){
            if(it->size()!=br_k)throwerr();
            auto e = it->begin();
            for(int j = 0; e!=it->end();j++,e++){
                m[i][j]=*e;
            }
        }
    }
template <typename T1, typename T2>
     auto operator + (const GMatrica<T1> &a, const GMatrica<T2> &b)->GMatrica<decltype (a.m[0][0] + b.m[0][0])>{
        if(a.br_r != b.br_r || a.br_k != b.br_k)throwerr(1);
        GMatrica<decltype(a.m[0][0] + b.m[0][0])> izlaz(a.br_r,a.br_k);
        for (int i = 0; i < a.br_r; i++) {
            for(int j = 0; j < a.br_k; j++){
                izlaz.m[i][j] = a.m[i][j] + b.m[i][j];
            }
        }
        return izlaz;
    }
template <typename T1, typename T2>
     auto operator - (const GMatrica<T1> &a, const GMatrica<T2> &b)->GMatrica<decltype (a.m[0][0] + b.m[0][0])>{
         if(a.br_r != b.br_r || a.br_k != b.br_k)throwerr(1);
        GMatrica<decltype(a.m[0][0] + b.m[0][0])> izlaz(a.br_r,a.br_k);
        for (int i = 0; i < a.br_r; i++) {
            for(int j = 0; j < a.br_k; j++){
                izlaz.m[i][j] = a.m[i][j] - b.m[i][j];
            }
        }
        return izlaz;
     }
template <typename T1, typename T2>
    auto operator * (const GMatrica<T1> &a, const GMatrica<T2> &b)->GMatrica<decltype (a.m[0][0] + b.m[0][0])>{
        if(a.br_k != b.br_r)throwerr(1);
        GMatrica<decltype (a.m[0][0] + b.m[0][0])> izlaz(a.br_r,b.br_k);
        for(int i=0; i< a.br_r ; i++)
            for(int j=0; j<b.br_r; j++)
                for(int k=0;k<a.br_k;k++)
                    izlaz.m[i][j]+=a.m[i][k] * b.m[k][j];
        return izlaz;
    }
int main ()
{
    GMatrica<int> a({{1,1,1},{2,2,2},{5,5,5}}),b({{1,1,0},{2,2,0},{0,0,0}});
    std::cout<<(a+(a+b)*5);
	return 0;
}
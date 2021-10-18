/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <string>
#include <initializer_list>

using std::cin;
using std::cout;
using std::vector;
using std::string;




template<typename Tip>
class GMatrica
{
    Tip niz[4][4];
    int redovi,kolone;
    public:
    GMatrica():redovi(0),kolone(0){}
    GMatrica(int red,int kol,Tip a=Tip());
    template<typename Tip1>
    GMatrica(const GMatrica<Tip1> &m);
    template<typename Tip1>
    GMatrica(Tip1 niz1[4][4]);
    GMatrica(vector<vector<Tip>> v);
    template<typename Tip1>
    GMatrica(std::initializer_list<std::initializer_list<Tip1>> a);
    int DajBrojRedova()const{return redovi;}
    int DajBrojKolona()const{return kolone;}
    template<typename Tip1,typename Tip2>
    friend auto operator+(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<typename std::remove_reference<decltype(m1.niz[0][0]+m2.niz[0][0])>::type>;
    template<typename Tip1,typename Tip2>
    friend auto operator-(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<typename std::remove_reference<decltype(m1.niz[0][0]-m2.niz[0][0])>::type>;
    template<typename Tip1,typename Tip2>
    friend auto operator*(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<typename std::remove_reference<decltype(m1.niz[0][0]*m2.niz[0][0])>::type>;
    template<typename Tip1>
    friend GMatrica<Tip1> operator*(const GMatrica<Tip1> &m1,double elem);
    template<typename Tip1>
    friend GMatrica<Tip1> operator*(double elem,const GMatrica<Tip1> &m1);
    template<typename Tip1>
    GMatrica<Tip> &operator+=(const GMatrica<Tip1> &m1);
    template<typename Tip1>
    GMatrica<Tip> &operator-=(const GMatrica<Tip1> &m1);
    template<typename Tip1>
    GMatrica<Tip> &operator*=(const GMatrica<Tip1> &m1);
    GMatrica<Tip> &operator*=(double elem);
    template<typename Tip1>
    friend bool operator==(const GMatrica<Tip1> &m1,const GMatrica<Tip1> &m2);
    template<typename Tip1>
    friend bool operator!=(const GMatrica<Tip1> &m1,const GMatrica<Tip1> &m2);
    Tip *operator [](int x){return niz[x];}
    const Tip *operator [](int x)const{return niz[x];}
    Tip &operator()(int x,int y);
    Tip operator()(int x,int y)const;
    template<typename Tip1>
    friend std::ostream &operator<<(std::ostream &tok,const GMatrica<Tip1> &m);
    template<typename Tip1>
    friend std::istream &operator>>(std::istream &tok,GMatrica<Tip1> &m);
};
template<typename Tip1>
std::istream &operator>>(std::istream &tok,GMatrica<Tip1> &m)
{
    char znak;
    tok >> znak;
    if(znak!='[')
    {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    if(m.redovi == 0 and m.kolone == 0)
    {
        int i=0,j=0;
        int pamti;
        bool promijeni=true;
        for(;;)
        {
            j=0;
            for(;;)
            {
                if(j>=4)
                {
                    tok.setstate(std::ios::failbit);
                    return tok;
                }
                Tip1 pomoc;
                tok >> pomoc;
                if(!tok or (tok.peek()!=',' and tok.peek()!=';' and tok.peek()!=']'))
                {
                    tok.setstate(std::ios::failbit);
                    return tok;
                }
                m[i][j]=pomoc;
                if(tok.peek() == ';')
                {
                    tok.get();
                    break;
                }
                if(tok.peek() == ']')
                    break;
                if(tok.peek() == ',')
                {
                    j++;
                    tok.get();
                    if(promijeni)
                        pamti=j;
                    continue;
                }
            }
            if(pamti!=j)
            {
                tok.setstate(std::ios::failbit);
                return tok;
            }
            else
                promijeni=false;
            if(tok.peek() == ']')
                break;
            i++;
        }
    m.redovi=i+1;
    m.kolone=j+1;
    }
    else
    {
        for(int i=0;i<m.redovi;i++)
        {
            for(int j=0;j<m.kolone;j++)
            {
                if(tok.peek()<'0' or tok.peek()>'9')
                {
                    tok.setstate(std::ios::failbit);
                    return tok;
                }
                tok >> m[i][j];
                if(tok.peek()==';' and j!=m.kolone-1)
                {
                    tok.setstate(std::ios::failbit);
                    return tok;
                }
                if(tok.peek() == ']')
                    break;
                if(tok.peek()!=',' and tok.peek()!=';')
                {
                    tok.setstate(std::ios::failbit);
                    return tok;
                }
                tok.get();
            }
            if(tok.peek()!=';' and tok.peek()!=']')
            {
                tok.setstate(std::ios::failbit);
                return tok;
            }
            char znak1;
            if(tok.peek() == ';')
                tok >> znak1;
            if(tok.peek()==']' and i!=m.redovi-1)
            {
                tok.setstate(std::ios::failbit);
                return tok;
            }
        }
    }
    return tok;
}
template<typename Tip1>
std::ostream &operator<<(std::ostream &tok,const GMatrica<Tip1> &m)
{
    int a=tok.width();
    if(a<6)
        a=6;
    for(int i=0;i<m.redovi;i++)
    {
        for(int j=0;j<m.kolone;j++)
            tok << std::setw(a) << m[i][j];
        tok << "\n";
    }
    return tok;
}
template<typename Tip>
Tip &GMatrica<Tip>::operator ()(int x,int y)
{
    if(x<1 or y<1 or x>this->redovi or y>this->kolone)
        throw std::range_error("Nedozvoljen indeks");
    return (*this)[x-1][y-1];
}
template<typename Tip>
Tip GMatrica<Tip>::operator ()(int x,int y)const
{
    if(x<1 or y<1 or x>this->redovi or y>this->kolone)
        throw std::range_error("Nedozvoljen indeks");
    return (*this)[x-1][y-1];
}
template<typename Tip1>
bool operator!=(const GMatrica<Tip1> &m1,const GMatrica<Tip1> &m2)
{
    return !(m1==m2);
}
template<typename Tip1>
bool operator==(const GMatrica<Tip1> &m1,const GMatrica<Tip1> &m2)
{
    if(m1.redovi!=m2.redovi or m1.kolone!=m2.kolone)
        return false;
    for(int i=0;i<m1.redovi;i++)
        for(int j=0;j<m1.kolone;j++)
            if(m1[i][j]!=m2[i][j])
                return false;
    return true;
}
template<typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator*=(double elem)
{
    for(int i=0;i<redovi;i++)
        for(int j=0;j<kolone;j++)
            niz[i][j]*=elem;
    return *this;
}
template<typename Tip>
template<typename Tip1>
GMatrica<Tip> &GMatrica<Tip>::operator*=(const GMatrica<Tip1> &m1)
{
    if(kolone!=m1.redovi)    
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<Tip> mat;
    mat.redovi=this->redovi;
    mat.kolone=m1.kolone;
    for(int i=0;i<mat.redovi;i++)
        for(int j=0;j<mat.kolone;j++)
            mat[i][j]=0;
    for(int i=0;i<this->redovi;i++)
        for(int j=0;j<m1.kolone;j++)
            for(int k=0;k<this->kolone;k++)
                mat[i][j]+=((*this)[i][k])*(m1[k][j]);
    *this=mat;
    return *this;
}
template<typename Tip>
template<typename Tip1>
GMatrica<Tip> &GMatrica<Tip>::operator-=(const GMatrica<Tip1> &m1)
{
    if(this->redovi!=m1.redovi or this->kolone!=m1.kolone)
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<Tip> mat(m1.redovi,m1.kolone);
    mat=*this;
    for(int i=0;i<mat.redovi;i++)
        for(int j=0;j<mat.kolone;j++)
            mat[i][j]-=m1[i][j];
    *this=mat;
    return *this;
}
template<typename Tip>
template<typename Tip1>
GMatrica<Tip> &GMatrica<Tip>::operator+=(const GMatrica<Tip1> &m1)
{
    if(this->redovi!=m1.redovi or this->kolone!=m1.kolone)
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<Tip> mat(m1.redovi,m1.kolone);
    mat=*this;
    for(int i=0;i<mat.redovi;i++)
        for(int j=0;j<mat.kolone;j++)
            mat[i][j]+=m1[i][j];
    *this=mat;
    return *this;
}
template<typename Tip1>
GMatrica<Tip1> operator*(double elem,const GMatrica<Tip1> &m1)
{
    GMatrica<Tip1> nova(m1.redovi,m1.kolone);
    for(int i=0;i<m1.redovi;i++)
        for(int j=0;j<m1.kolone;j++)
            nova[i][j]=m1[i][j]*elem;
    return nova;
}
template<typename Tip1>
GMatrica<Tip1> operator*(const GMatrica<Tip1> &m1,double elem)
{
    GMatrica<Tip1> nova(m1.DajBrojRedova(),m1.DajBrojKolona());
    for(int i=0;i<m1.DajBrojRedova();i++)
        for(int j=0;j<m1.DajBrojKolona();j++)
            nova[i][j]=m1[i][j]*elem;
    return nova;
}
template<typename Tip1,typename Tip2>
auto operator*(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<typename std::remove_reference<decltype(m1.niz[0][0]*m2.niz[0][0])>::type>
{
    if(m1.kolone!=m2.redovi)    
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<typename std::remove_reference<decltype(m1.niz[0][0]*m2.niz[0][0])>::type> mat;
    mat.redovi=m1.redovi;
    mat.kolone=m2.kolone;
    for(int i=0;i<mat.redovi;i++)
        for(int j=0;j<mat.kolone;j++)
            mat[i][j]=0;
    for(int i=0;i<m1.redovi;i++)
        for(int j=0;j<m2.kolone;j++)
            for(int k=0;k<m1.kolone;k++)
                mat[i][j]+=m1[i][k]*m2[k][j];
    return mat;
}
template<typename Tip1,typename Tip2>
auto operator-(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<typename std::remove_reference<decltype(m1.niz[0][0]-m2.niz[0][0])>::type>
{
    if(m1.redovi!=m2.redovi or m1.kolone!=m2.kolone)
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<typename std::remove_reference<decltype(m1.niz[0][0]-m2.niz[0][0])>::type> mat;
    mat.redovi=m1.redovi;
    mat.kolone=m1.kolone;
    for(int i=0;i<mat.redovi;i++)
        for(int j=0;j<mat.kolone;j++)
            mat.niz[i][j]=m1.niz[i][j]-m2.niz[i][j];
    return mat;
}
template<typename Tip1,typename Tip2>
auto operator+(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<typename std::remove_reference<decltype(m1.niz[0][0]+m2.niz[0][0])>::type>
{
    if(m1.redovi!=m2.redovi or m1.kolone!=m2.kolone)
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<typename std::remove_reference<decltype(m1.niz[0][0]+m2.niz[0][0])>::type> mat;
    mat.redovi=m1.redovi;
    mat.kolone=m1.kolone;
    for(int i=0;i<mat.redovi;i++)
        for(int j=0;j<mat.kolone;j++)
            mat.niz[i][j]=m1.niz[i][j]+m2.niz[i][j];
    return mat;
}
template<typename Tip>
template<typename Tip1>
GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Tip1>> a)
{
    vector<vector<Tip1>> v;
    for(auto it=a.begin();it!=a.end();it++)
        v.push_back(*it);
    redovi=v.size();
    kolone=v[0].size();
    auto b=GMatrica<Tip1>(v);
    *this=b;
}
template<typename Tip>
GMatrica<Tip>::GMatrica(vector<vector<Tip>> v)
{
    if(v.size()>4)
        throw std::logic_error("Ilegalan format matrice");
    for(int i=0;i<v.size()-1;i++)
        if(v[i].size()!=v[i+1].size() or v[i].size()>4)
            throw std::logic_error("Ilegalan format matrice");
    redovi=v.size();
    kolone=v[0].size();
    for(int i=0;i<redovi;i++)
        for(int j=0;j<kolone;j++)
            niz[i][j]=v[i][j];
}
template<typename Tip>
template<typename Tip1>
GMatrica<Tip>::GMatrica(Tip1 niz1[4][4])
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            niz[i][j]=niz1[i][j];
    redovi=4;
    kolone=4;
}
template<typename Tip>
template<typename Tip1>
GMatrica<Tip>::GMatrica(const GMatrica<Tip1> &m)
{
    for(int i=0;i<m.DajBrojRedova();i++)
        for(int j=0;j<m.DajBrojKolona();j++)
            niz[i][j]=m[i][j];
    kolone=m.DajBrojKolona();
    redovi=m.DajBrojRedova();
}
template<typename Tip>
GMatrica<Tip>::GMatrica(int red,int kol,Tip a)
{
    if(kol>4 or kol<0 or red>4 or red<0)
        throw std::logic_error("Ilegalan format matrice");
    kolone=kol;
    redovi=red;
    for(int i=0;i<redovi;i++)
        for(int j=0;j<kolone;j++)
            niz[i][j]=a;
}
int main ()
{
   
   //operator+ i operator- i <<
   
   GMatrica<double> m1({{1, 2}, {3, 4}});
   GMatrica<double> m2({{1, 2}, {3, 4}});
   m1[0][0]=5;
   cout<<m1;
	return 0;
}
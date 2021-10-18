/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
using namespace std;

template<typename t>
class GMatrica
{
    int r,k;
    t mat[4][4];
public:
    GMatrica(int r=0,int k=0,t n=0);
    GMatrica(GMatrica &m);
    GMatrica(GMatrica &&m);
    GMatrica(const vector<vector<t>>&v);
    GMatrica(const initializer_list<initializer_list<t>>&l);
    int DajBrojRedova()const{return r;}
    int DajBrojKolona()const{return k;}
    GMatrica(t &n)
    {
        r=4;k=4;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                mat[i][j]=n;
    }
    template<typename t1,typename t2>
    friend GMatrica<decltype(t1()+t2())>operator+(GMatrica<t1>&m1,GMatrica<t2>&m2);
    GMatrica &operator+=(GMatrica<t> &m);
    template<typename t1,typename t2>
    friend GMatrica<decltype(t1()+t2())>operator-(GMatrica<t1>&m1,GMatrica<t2>&m2);
    GMatrica &operator-=(GMatrica<t> &m);
    template<typename t1,typename t2>
    friend GMatrica<decltype(t1()+t2())>operator*(GMatrica<t1>&m1,GMatrica<t2>&m2);
    GMatrica &operator*=(GMatrica<t> &m);
    template<typename t1,typename t2>
    friend GMatrica<decltype(t1()+t2())>operator*(GMatrica<t1>&m1,const t2 &n);
    template<typename t1,typename t2>
    friend GMatrica<decltype(t1()+t2())>operator*(const t1 &n,GMatrica<t2>&m1);
    GMatrica &operator*=(const t &n);
    t operator()(int i,int j) const
    {
        if(i<=0 || j<=0) throw range_error("Nedozvoljen indeks");
        return mat[i-1][j-1];
    }
    t &operator()(int i,int j)
    {
        return mat[i-1][j-1];
    }
    
    t *operator[](const int &i) const
    {
        return mat[i];
    }
    t *operator[](const int &i)
    {
        return mat[i];
    }
    
    friend ostream &operator<<(ostream &cout,GMatrica<t> m)
    {   
        streamsize n;        
        if(cout.width()==0) n=6;
        else  n=cout.width();
        for(int i=0;i<m.r;i++)
        {
            for(int j=0;j<m.k;j++)
                cout<<setw(n)<<m.mat[i][j];
            cout<<endl;
        }        
        return cout;
    }
    friend istream &operator>>(istream &cin,GMatrica<t> &m)
    {
        int a=0;int n=0;
        char c;
        cin>>c;
        if(c=='[')
            while(c!=']')
            {   
                cin>>m.mat[a][n]>>c;
                if(c==',')n++;
                else if(c==';'){a++;n=0;}
                else break;
            }
        m.r=a+2-1;m.k=n+2-1;
        return cin;
    }
    template<typename t1,typename t2>
    friend bool operator==(GMatrica<t1>&m1,GMatrica<t2>&m2);
    template<typename t1,typename t2>
    friend bool operator!=(GMatrica<t1>&m1,GMatrica<t2>&m2);
};


template<typename t1>
GMatrica<t1>::GMatrica(int red,int kol,t1 n)
    {
       if(red<0 || red>4 || kol<0 || kol>4) throw logic_error("Ilegalan format matrice");
        r=red;k=kol;
        for(int i=0;i<r;i++)
            for(int j=0;j<k;j++)
                mat[i][j]=n;
    
    }
template<typename t1>
GMatrica<t1>::GMatrica(GMatrica<t1> &m)
    {
        r=m.r;
        k=m.k;
        for(int i=0;i<r;i++)
            for(int j=0;j<k;j++)
                GMatrica::mat[i][j]=m.mat[i][j];
    }
    

template<typename t1>
GMatrica<t1>::GMatrica(GMatrica<t1> &&m)
    {
        r=m.r;
        k=m.k;
        for(int i=0;i<r;i++)
            for(int j=0;j<k;j++)
                GMatrica::mat[i][j]=m.mat[i][j];
    }
template<typename t1>
GMatrica<t1>::GMatrica(const vector<vector<t1>> &v)
{       
    
    if(v.size()>4) throw logic_error("Ilegalan format matrice");
    for(int i=0; i<v.size(); i++) if(v[i].size()!=v[0].size() || v[i].size()>4) throw logic_error("Ilegalan format matrice");
    r=v.size();
    k=v[0].size();
    for(int i=0;i<r;i++)
        for(int j=0;j<k;j++)
            GMatrica::mat[i][j]=v[i][j];
} 
template<typename t1>
GMatrica<t1>::GMatrica(const initializer_list<initializer_list<t1>> &l)
{       
    int br=0;
    for(auto x:l) br++;
    if(br>4)throw logic_error("Ilegalan format matrice");
    for(auto x:l)
    {
        br=0;
        for(auto y:x) br++;
        if(br>4) throw logic_error("Ilegalan format matrice");
    }
    auto it=l.begin();
    r=l.begin()->size();
    k=it->size();
    int x=0;
    for(auto i=l.begin();i!=l.end();i++)
    {   
        int y=0;
        for(auto j=i->begin();j!=i->end();j++)
             {mat[x][y]=*j; y++; }
        x++;
    }
        
}

template<typename t1,typename t2>
GMatrica<decltype(t1()+t2())>operator+(GMatrica<t1>&m1,GMatrica<t2>&m2)
{   
    if(m1.k!=m2.k || m1.r!=m2.r) throw domain_error("Nedozvoljena operacija");
    GMatrica<decltype(t1()+t2())> m(m1.r,m1.k);
    for(int i=0;i<m.r;i++)
        for(int j=0;j<m.k;j++)
            m.mat[i][j]=m1.mat[i][j]+m2.mat[i][j];
    return m;
}    

template<typename t1>
GMatrica<t1> &GMatrica<t1>::operator+=(GMatrica<t1> &m)
{
    if(k!=m.k || r!=m.r) throw domain_error("Nedozvoljena operacija");
    for(int i=0;i<m.r;i++)
        for(int j=0;j<m.k;j++)
            mat[i][j]=mat[i][j]+m.mat[i][j];
    return *this;
} 

template<typename t1,typename t2>
GMatrica<decltype(t1()+t2())>operator-(GMatrica<t1>&m1,GMatrica<t2>&m2)
{
    if(m1.k!=m2.k || m1.r!=m2.r) throw domain_error("Nedozvoljena operacija");
    GMatrica<decltype(t1()+t2())> m(m1.r,m1.k);
    for(int i=0;i<m.r;i++)
        for(int j=0;j<m.k;j++)
            m.mat[i][j]=m1.mat[i][j]-m2.mat[i][j];
    return m;
}    

template<typename t1>
GMatrica<t1> &GMatrica<t1>::operator-=(GMatrica<t1> &m)
{
    if(k!=m.k || m.r!=r) throw domain_error("Nedozvoljena operacija");
    for(int i=0;i<m.r;i++)
        for(int j=0;j<m.k;j++)
            mat[i][j]=mat[i][j]-m.mat[i][j];
    return *this;
}
 
template<typename t1,typename t2>
GMatrica<decltype(t1()+t2())>operator*(GMatrica<t1>&m1,GMatrica<t2>&m2)
{

    if(m1.k!=m2.r || m1.r!=m2.k) throw domain_error("Nedozvoljena operacija");
    GMatrica<decltype(t1()+t2())> m(m1.r,m1.k);
    for(int i=0;i<m.r;i++)
        for(int j=0;j<m.k;j++)
        {   m.mat[i][j]=0;
            for(int k=0;k<m.k;k++)
              m.mat[i][j]+=m1.mat[i][k]*m2.mat[k][j];
        }
    return m;
}    

template<typename t1,typename t2>
GMatrica<decltype(t1()+t2())>operator*(GMatrica<t1>&m1,const t2 &n)
{
   GMatrica<decltype(t1()+t2())> m(m1.DajBrojRedova(),m1.DajBrojKolona());
    for(int i=0;i<m.DajBrojRedova();i++)
        for(int j=0;j<m.DajBrojKolona();j++)
            m.mat[i][j]=m1.mat[i][j]*n;
    return m;
}
template<typename t1,typename t2>
GMatrica<decltype(t1()+t2())>operator*(const t1 &n,GMatrica<t2>&m1)
{
    GMatrica<decltype(t1()+t2())> m(m1.DajBrojRedova(),m1.DajBrojKolona());
    for(int i=0;i<m.DajBrojRedova();i++)
        for(int j=0;j<m.DajBrojKolona();j++)
            m.mat[i][j]=m1.mat[i][j]*n;
    return m;
}

 template<typename t1,typename t2>
 bool operator==(GMatrica<t1>&m1,GMatrica<t2>&m2)
 {
     if(m1.r!=m2.r || m1.k!=m2.k) return false;
     for(int i=0;i<m1.r;i++)
        for(int j=0;j<m1.k;j++)
            if(m1.mat[i][j]!=m2.mat[i][j]) return false;
        return true;
 }
template<typename t1,typename t2>
bool operator!=(GMatrica<t1>&m1,GMatrica<t2>&m2)
{
    return !(m1==m2);
}

template<typename t1>
GMatrica<t1> &GMatrica<t1>::operator*=(GMatrica<t1> &m)
{
    for(int i=0;i<m.r;i++)
        for(int j=0;j<m.k;j++)
        {   mat[i][j]=0;
            for(int k=0;k<m.k;k++)
                mat[i][j]+=mat[i][k]*m.mat[k][j];
        }
    return *this;
}
template<typename t1>
GMatrica<t1> &GMatrica<t1>::operator*=(const t1 &n)
{
  for(int i=0;i<r;i++)
    for(int j=0;j<k;j++)
        mat[i][j]=mat[i][j]*n;
    return *this;
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
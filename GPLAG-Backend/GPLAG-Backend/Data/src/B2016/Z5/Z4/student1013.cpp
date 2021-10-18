/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>

using namespace std;

template<typename Tip>
class GMatrica
{
    Tip Mat[4][4];
    int brR,brK;
    
    public:
    GMatrica(int r=0,int k=0,Tip n=0);//
    GMatrica(GMatrica &g);//
    GMatrica(GMatrica &&g);//
    GMatrica(const vector<vector<Tip>>&v);//
    GMatrica(const initializer_list<initializer_list<Tip>>&l);//
    GMatrica(Tip &n)
    {
        brR=4;brK=4;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                Mat[i][j]=n;
    }
   
    int DajBrojRedova()const{return brR;}
    int DajBrojKolona()const{return brK;}
    
    template<typename Tip1,typename Tip2>
    friend GMatrica<decltype(Tip1()+Tip2())>operator+(GMatrica<Tip1>&g1,GMatrica<Tip2>&g2);//
    template<typename Tip1,typename Tip2>
    friend GMatrica<decltype(Tip1()+Tip2())>operator-(GMatrica<Tip1>&g1,GMatrica<Tip2>&g2);//
    template<typename Tip1,typename Tip2>
    friend GMatrica<decltype(Tip1()+Tip2())>operator*(GMatrica<Tip1>&g1,GMatrica<Tip2>&g2);//
    template<typename Tip1,typename Tip2>
    friend GMatrica<decltype(Tip1()+Tip2())>operator*(GMatrica<Tip1>&g1,const Tip2 &n);//
    template<typename Tip1,typename Tip2>
    friend GMatrica<decltype(Tip1()+Tip2())>operator*(const Tip1 &n,GMatrica<Tip2>&g1);//
   
    GMatrica &operator+=(GMatrica<Tip> &g);
    GMatrica &operator-=(GMatrica<Tip> &g);
    GMatrica &operator*=(GMatrica<Tip> &g);
    GMatrica &operator*=(const Tip &n);
    
    
    template<typename Tip1,typename Tip2>
    friend bool operator==(GMatrica<Tip1>&g1,GMatrica<Tip2>&g2);//
    template<typename Tip1,typename Tip2>
    friend bool operator!=(GMatrica<Tip1>&g1,GMatrica<Tip2>&g2);//
   
    Tip operator()(int i,int j) const
    {
        if(i<=0 || j<=0) throw range_error("Nedozvoljen indeks");
        return Mat[i-1][j-1];
    }
    Tip &operator()(int i,int j)
    {
        if(i<=0 || j<=0) throw range_error("Nedozvoljen indeks");
        return Mat[i-1][j-1];
    }
    
    Tip *operator[](const int &i) const
    {
        return Mat[i];
    }
    Tip *operator[](const int &i)
    {
        return Mat[i];
    }
    
    friend ostream &operator<<(ostream &izso,GMatrica<Tip> g)
    {   
        streamsize n;        
        if(cout.width()==0) n=6;
        else  n=cout.width();
        
        for(int i=0;i<g.DajBrojRedova();i++)
        {
            for(int j=0;j<g.DajBrojKolona();j++)
                izso<<setw(n)<<g.Mat[i][j];
            izso<<endl;
        }        
        return izso;
    }
    friend istream &operator>>(istream &uso,GMatrica<Tip> &g)
    {
        int m=0;int n=0;
        char c;
        uso>>c;
        if(c=='[')
            while(c!=']')
            {   
                uso>>g.Mat[m][n]>>c;
                if(c==',')n++;
                else if(c==';'){m++;n=0;}
                else break;
            }
        g.brR=m+1;g.brK=n+1;
        
        return uso;
    }
    
};


template<typename Tip1>
GMatrica<Tip1>::GMatrica(int r,int k,Tip1 n)
    {
        if(r<0 || r>4 || k<0 || k>4) throw logic_error("Ilegalan format matrice");
        brR=r;brK=k;
        for(int i=0;i<r;i++)
            for(int j=0;j<k;j++)
                Mat[i][j]=n;
    
    }
template<typename Tip1>
GMatrica<Tip1>::GMatrica(GMatrica<Tip1> &g)
    {
        GMatrica::brR=g.brR;
        GMatrica::brK=g.brK;
        
        for(int i=0;i<brR;i++)
            for(int j=0;j<brK;j++)
                GMatrica::Mat[i][j]=g.Mat[i][j];
    }
    

template<typename Tip1>
GMatrica<Tip1>::GMatrica(GMatrica<Tip1> &&g)
    {
        GMatrica::brR=g.brR;
        GMatrica::brK=g.brK;
        
        for(int i=0;i<brR;i++)
            for(int j=0;j<brK;j++)
                GMatrica::Mat[i][j]=g.Mat[i][j];
    }
template<typename Tip1>
GMatrica<Tip1>::GMatrica(const vector<vector<Tip1>> &v)
{       
        if(v.size()>4) throw logic_error("Ilegalan format matrice");
    for(int i=0; i<v.size(); i++) if(v[i].size()!=v[0].size()) throw logic_error("Ilegalan format matrice");
    for(auto i:v) if(i.size()>4) throw logic_error("Ilegalan format matrice");
        GMatrica::brR=v.size();
        GMatrica::brK=v[0].size();
    
        for(int i=0;i<brR;i++)
            for(int j=0;j<brK;j++)
                GMatrica::Mat[i][j]=v[i][j];
}
template<typename Tip1>
GMatrica<Tip1>::GMatrica(const initializer_list<initializer_list<Tip1>> &l)
{       
        
        int br=0, br1=0;
    for(auto x=l.begin(); x!=l.end(); x++)
    {
        br++; br1=0;
        for(auto y=x->begin();y!=x->end();y++) br1++;
        if(br>4) throw logic_error("Ilegalan format matrice");
    }
    
    if(br>4)throw logic_error("Ilegalan format matrice");
        auto it=l.begin();
        GMatrica::brR=l.begin()->size();
        GMatrica::brK=it->size();
        
        int p=0;
        for(auto i=l.begin();i!=l.end();i++,p++)
        {   
            int q=0;
            for(auto j=i->begin();j!=i->end();j++,q++)
            {
                 Mat[p][q]=*j;
            }
        }
        
}

template<typename Tip1,typename Tip2>
GMatrica<decltype(Tip1()+Tip2())>operator+(GMatrica<Tip1>&g1,GMatrica<Tip2>&g2)
{   
    if(g1.DajBrojKolona()!=g2.DajBrojKolona() || g1.DajBrojRedova()!=g2.DajBrojRedova()) throw domain_error("Nedozvoljena operacija");
    GMatrica<decltype(Tip1()+Tip2())> g(g1.DajBrojRedova(),g1.DajBrojKolona());
    for(int i=0;i<g.DajBrojRedova();i++)
        for(int j=0;j<g.DajBrojKolona();j++)
            g.Mat[i][j]=g1.Mat[i][j]+g2.Mat[i][j];
  
    return g;
}    


template<typename Tip1,typename Tip2>
GMatrica<decltype(Tip1()+Tip2())>operator-(GMatrica<Tip1>&g1,GMatrica<Tip2>&g2)
{
   if(g1.DajBrojKolona()!=g2.DajBrojKolona() || g1.DajBrojRedova()!=g2.DajBrojRedova()) throw domain_error("Nedozvoljena operacija");
    GMatrica<decltype(Tip1()+Tip2())> g(g1.DajBrojRedova(),g1.DajBrojKolona());
    for(int i=0;i<g.DajBrojRedova();i++)
        for(int j=0;j<g.DajBrojKolona();j++)
            g.Mat[i][j]=g1.Mat[i][j]-g2.Mat[i][j];
            
    return g;
}    


template<typename Tip1,typename Tip2>
GMatrica<decltype(Tip1()+Tip2())>operator*(GMatrica<Tip1>&g1,GMatrica<Tip2>&g2)
{
    if(g1.DajBrojKolona()!=g2.DajBrojRedova() || g1.DajBrojRedova()!=g2.DajBrojKolona()) throw domain_error("Nedozvoljena operacija");
    GMatrica<decltype(Tip1()+Tip2())> g(g1.DajBrojRedova(),g1.DajBrojKolona());
    for(int i=0;i<g.DajBrojRedova();i++)
        for(int j=0;j<g.DajBrojKolona();j++)
        {   g.Mat[i][j]=0;
            for(int k=0;k<g.DajBrojKolona();k++)
              g.Mat[i][j]+=g1.Mat[i][k]*g2.Mat[k][j];
        }
    return g;
}    

template<typename Tip1,typename Tip2>
GMatrica<decltype(Tip1()+Tip2())>operator*(GMatrica<Tip1>&g1,const Tip2 &n)
{
   GMatrica<decltype(Tip1()+Tip2())> g(g1.DajBrojRedova(),g1.DajBrojKolona());
    for(int i=0;i<g.DajBrojRedova();i++)
        for(int j=0;j<g.DajBrojKolona();j++)
            g.Mat[i][j]=g1.Mat[i][j]*n;
    return g;
}
template<typename Tip1,typename Tip2>
GMatrica<decltype(Tip1()+Tip2())>operator*(const Tip1 &n,GMatrica<Tip2>&g1)
{
    GMatrica<decltype(Tip1()+Tip2())> g(g1.DajBrojRedova(),g1.DajBrojKolona());
    for(int i=0;i<g.DajBrojRedova();i++)
        for(int j=0;j<g.DajBrojKolona();j++)
            g.Mat[i][j]=g1.Mat[i][j]*n;
    return g;
}

 template<typename Tip1,typename Tip2>
 bool operator==(GMatrica<Tip1>&g1,GMatrica<Tip2>&g2)
 {
     for(int i=0;i<g1.DajBrojRedova();i++)
        for(int j=0;j<g1.DajBrojKolona();j++)
            if(g1.Mat[i][j]!=g2.Mat[i][j]) return false;
        return true;
 }
template<typename Tip1,typename Tip2>
bool operator!=(GMatrica<Tip1>&g1,GMatrica<Tip2>&g2)
{
    for(int i=0;i<g1.DajBrojRedova();i++)
        for(int j=0;j<g1.DajBrojKolona();j++)
            if(g1.Mat[i][j]!=g2.Mat[i][j]) return true;
        return false;
}

template<typename Tip1>
GMatrica<Tip1> &GMatrica<Tip1>::operator+=(GMatrica<Tip1> &g)
{
    if(g.DajBrojKolona()!=DajBrojKolona() || g.DajBrojRedova()!=DajBrojRedova()) throw domain_error("Nedozvoljena operacija");
    for(int i=0;i<g.DajBrojRedova();i++)
        for(int j=0;j<g.DajBrojKolona();j++)
            Mat[i][j]=Mat[i][j]+g.Mat[i][j];
    
    return *this;
}
template<typename Tip1>
GMatrica<Tip1> &GMatrica<Tip1>::operator-=(GMatrica<Tip1> &g)
{
    
    if(g.DajBrojKolona()!=DajBrojKolona() || g.DajBrojRedova()!=DajBrojRedova()) throw domain_error("Nedozvoljena operacija");for(int i=0;i<g.DajBrojRedova();i++)
        for(int j=0;j<g.DajBrojKolona();j++)
            Mat[i][j]=Mat[i][j]-g.Mat[i][j];
        
    return *this;
}
template<typename Tip1>
GMatrica<Tip1> &GMatrica<Tip1>::operator*=(GMatrica<Tip1> &g)
{
    
    if(DajBrojKolona()!=g.DajBrojRedova() || DajBrojRedova()!=g.DajBrojKolona()) throw domain_error("Nedozvoljena operacija");for(int i=0;i<g.DajBrojRedova();i++)
        for(int j=0;j<g.DajBrojKolona();j++)
        {   Mat[i][j]=0;
            for(int k=0;k<g.DajBrojKolona();k++)
                Mat[i][j]+=Mat[i][k]*g.Mat[k][j];
        }
    return *this;
}
template<typename Tip1>
GMatrica<Tip1> &GMatrica<Tip1>::operator*=(const Tip1 &n)
{
  for(int i=0;i<DajBrojRedova();i++)
    for(int j=0;j<DajBrojKolona();j++)
        Mat[i][j]=Mat[i][j]*n;
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
/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <cmath>

template <typename Tip>
class GMatrica
{
    int n,m;
    Tip mat[4][4];
public:
    GMatrica();
    GMatrica(int sir,int duz,Tip el=Tip{});
    template<typename Tip1>
    GMatrica(const GMatrica<Tip1> &g):n(g.DajBrojRedova()), m(g.DajBrojKolona())
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) mat[i][j]=g(i+1,j+1);
    }
    template<typename Tip2>
        GMatrica(Tip2 niz[]);
    template<typename Tip2>
        GMatrica(std::vector<std::vector<Tip2>> vek);
    template<typename Tip2>
        GMatrica(std::initializer_list<std::initializer_list<Tip2>> t);
    int DajBrojRedova()const{return n;}
    int DajBrojKolona()const{return m;}
    template<typename Tip1,typename Tip2>
        friend auto operator+(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])>;
    template<typename Tip1,typename Tip2>
        friend auto operator-(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])>;
    template<typename Tip1,typename Tip2>
        friend auto operator*(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])>;
    Tip* operator[](int i){return mat[i];}
    Tip* operator[](int i)const{static Tip t[4];for(int j=0;j<m;j++) t[j] = mat[i][j];return t;}
    template <typename Tip1>
        friend std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip1> &r);
    Tip operator()(int i,int j)const {if(i>n || j>m || j<1 || i<1) throw std::range_error("Nedozvoljen indeks");return mat[i-1][j-1];}
    Tip &operator()(int i,int j){if(i>n || j>m || j<1 || i<1) throw std::range_error("Nedozvoljen indeks");return mat[i-1][j-1];}
    template<typename Tip1,typename Tip2>
        friend auto operator*(const GMatrica<Tip1> &m1,Tip2 s)->GMatrica<decltype(m1.mat[0][0]+s)>;
    template<typename Tip1,typename Tip2>
        friend bool operator==(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2);
    template<typename Tip1,typename Tip2>
        friend bool operator!=(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2);
    template<typename Tip1,typename Tip2>
        friend auto operator*(Tip2 s,const GMatrica<Tip1> &m1)->GMatrica<decltype(m1.mat[0][0]+s)>;
    template<typename Tip2>
        GMatrica<Tip> operator+=(const GMatrica<Tip2> &m2);
    template<typename Tip2>
        GMatrica<Tip> operator-=(const GMatrica<Tip2> &m2);
    template<typename Tip2>
        GMatrica<Tip> operator*=(const GMatrica<Tip2> &m2);
     template<typename Tip2>
        GMatrica<Tip> operator*=(Tip2 s);
    template <typename Tip1>
        friend std::istream &operator >>(std::istream &tok, GMatrica<Tip1> &r);
};

int main()
{  
    int niz[4][4];
    GMatrica<int> a(2,3,4),b8({{1,2},{2,1}}),c(3,2,10);
    const GMatrica<double> s(2,3,1);
    GMatrica<double> p;
    a(2,2)=s[1][1];
    std::cout << a;
    std::cin >> a;
    if(!std::cin) std::cout << "lblal";
    std::cout << "sve u redu\n";
    GMatrica<double> b(b8);
    std::cout <<std::setw(5) <<  a;
	return 0;
}
template<typename Tip>
    GMatrica<Tip>::GMatrica()
    {
        n=0,m=0;
    }
template<typename Tip>   
    GMatrica<Tip>::GMatrica(int sir,int duz,Tip el)
    {
        if(sir<0 || duz<0 || duz>4 || sir>4) throw  std::logic_error("Ilegalan format matrice");
        n=sir;
        m=duz;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) mat[i][j]=el;
    }
template<typename Tip>
    template<typename Tip2>
        GMatrica<Tip>::GMatrica(Tip2 niz[])
        {
            n=4,m=4;
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++) mat[i][j]=niz[i][j];
        }
        
template<typename Tip>
    template<typename Tip2>
        GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip2>> vek)
        {
            if(vek.size()>4) throw  std::logic_error("Ilegalan format matrice");
            for(int i=0;i<vek.size();i++) if(vek[i].size()>4 || vek[i].size()!=vek[0].size()) throw  std::logic_error("Ilegalan format matrice");
            n=vek.size();
            if(n) m=vek[0].size();
            else m=0;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++) mat[i][j]=vek[i][j];
        }
template<typename Tip>
    template<typename Tip2>
        GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Tip2>> t)
        {
            
            int i=0,j;
            for(auto x:t)
            {
                j=0;
                for(auto y:x) mat[i][j++]=y;
                i++;
            }
            n=i;
            m=j;
        }
template<typename Tip1,typename Tip2>
        auto operator+(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])>
        {
            if(m1.m!=m2.m || m1.n!=m2.n) throw std::domain_error("Nedozvoljena operacija");
            GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])> m(m1.n,m1.m);
            for(int i=0;i<m1.n;i++)
                for(int j=0;j<m2.m;j++)  m.mat[i][j]=m1.mat[i][j]+m2.mat[i][j];
            return m;
        }
template <typename Tip1>
    std::ostream &operator <<(std::ostream &tok, const GMatrica<Tip1> &r)
    {
        int a=tok.width();
        for(int i=0;i<r.n;i++)
        {
            for(int j=0;j<r.m;j++)
                tok << std::setw(std::max(a,6)) << r.mat[i][j];
            tok << "\n";
        }
        return tok;
    }
template<typename Tip1,typename Tip2>
        auto operator-(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])>
        {
            if(m1.m!=m2.m || m1.n!=m2.n) throw std::domain_error("Nedozvoljena operacija");
            GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])> m(m1.n,m2.m);
            for(int i=0;i<m1.n;i++)
                for(int j=0;j<m2.m;j++)  m.mat[i][j]=m1.mat[i][j]-m2.mat[i][j];
            return m;
        }
template<typename Tip1,typename Tip2>
        auto operator*(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])>
        {
            if(m1.m!=m2.n) throw std::domain_error("Nedozvoljena operacija");
            GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])> m(m1.n,m2.m);
            decltype(m1.mat[0][0]+m2.mat[0][0]) suma{};
            for(int i=0;i<m1.n;i++)
                for(int j=0;j<m2.m;j++)
                {
                    for(int k=0;k<m1.m;k++)
                        suma+=m1.mat[i][k]*m2.mat[k][j];
                    m.mat[i][j]=suma;
                }
            return m;
        }
template<typename Tip1,typename Tip2>
        auto operator*(const GMatrica<Tip1> &m1,Tip2 s)->GMatrica<decltype(m1.mat[0][0]+s)>
        {
            GMatrica<decltype(m1.mat[0][0]+s)> m(m1.n,m1.m);
            for(int i=0;i<m1.n;i++)
                for(int j=0;j<m1.m;j++)  m.mat[i][j]=m1.mat[i][j]*s;
            return m;
        }
template<typename Tip1, typename Tip2> 
    bool operator==(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)
    {
        if(m1.n!=m2.n || m1.m!=m2.m) return false;
        for(int i=0;i<m1.n;i++)
            for(int j=0;j<m1.m;j++) if(m1.mat[i][j]!=m2.mat[i][j]) return false;
        return true;
    }
template<typename Tip1, typename Tip2> 
    bool operator!=(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)
    {
        if(m1.n!=m2.n || m1.m!=m2.m) return true;
        for(int i=0;i<m1.n;i++)
            for(int j=0;j<m1.m;j++) if(m1.mat[i][j]!=m2.mat[i][j]) return true;
        return false;
    }
template<typename Tip1,typename Tip2>
        auto operator*(Tip2 s,const GMatrica<Tip1> &m1)->GMatrica<decltype(m1.mat[0][0]+s)>
        {
            GMatrica<decltype(m1.mat[0][0]+s)> m(m1.n,m1.m);
            for(int i=0;i<m1.n;i++)
                for(int j=0;j<m1.m;j++)  m.mat[i][j]=m1.mat[i][j]*s;
            return m;
        }
template<typename Tip1>
    template<typename Tip2>
        GMatrica<Tip1> GMatrica<Tip1>::operator-=(const GMatrica<Tip2> &m2)
        {
            if(m!=m2.DajBrojKolona()|| n!=m2.DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija");
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)  mat[i][j]-=m2(i+1,j+1);
            return *this;
        }
template<typename Tip1>
    template<typename Tip2>
        GMatrica<Tip1> GMatrica<Tip1>::operator+=(const GMatrica<Tip2> &m2)
        {
            if(m!=m2.DajBrojKolona()|| n!=m2.DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija");
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)  mat[i][j]+=m2(i+1,j+1);
            return *this;
        }
template<typename Tip1>
    template<typename Tip2>
        GMatrica<Tip1> GMatrica<Tip1>::operator*=(const GMatrica<Tip2> &m2)
        {
            if(m!=m2.DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija");
            GMatrica<Tip1> m(*this);
            Tip1 suma{};
            this->m=m2.m;
            for(int i=0;i<m.n;i++)
                for(int j=0;j<m2.DajBrojKolona();j++)
                {
                    for(int k=0;k<m.m;k++)
                        suma+=m.mat[i][k]*m2(k+1,j+1);
                    mat[i][j]=suma;
                }
            return *this;
        }
template<typename Tip1>
    template<typename Tip2>
        GMatrica<Tip1> GMatrica<Tip1>::operator*=(Tip2 s)
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++) mat[i][j]*=s;
            return *this;
        }
template <typename Tip1>
    std::istream &operator >>(std::istream &tok, GMatrica<Tip1> &r)
    {
        std::vector<std::vector<Tip1>> v;
        char p;
        tok >> p;
        if(p!='[') 
        {
            tok.setstate(std::basic_ios<char>::failbit);
            return tok;
        }
        Tip1 pom;
        for(int i=0;i<4;i++)
        {
            std::vector<Tip1> pv;
            for(int j=0;j<4;j++)
            {
                tok >> pom;
                pv.push_back(pom);
                while(tok.peek()==' ' || tok.peek()=='\t' || tok.peek()=='\r' || tok.peek()=='\f' || tok.peek()=='\v') tok.get(p);
                if(tok.peek()==';' || tok.peek()==']'){ tok >> p;break;}
                if(tok.peek()!=','){ std::cout << (char)tok.peek();tok.setstate(std::basic_ios<char>::failbit);}
                else tok >> p;
            }
            v.push_back(pv);
            if(p==']') break;
        }
        if(p!=']') tok.setstate(std::basic_ios<char>::failbit);
        try
        {
            r=GMatrica<Tip1>(v);
        }
        catch(...)
        {
            tok.setstate(std::basic_ios<char>::failbit);
        }
        return tok;
    }
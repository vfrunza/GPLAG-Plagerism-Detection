/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <vector>
#include <iomanip>

template<typename tip>
    class GMatrica{
    int m, n;
    tip matrica[4][4];
public:
    GMatrica();
  template<typename tip2>
    GMatrica(const GMatrica<tip2> &mat);
    GMatrica(int n, int m, tip t=tip{});
  template<typename tip2>
    GMatrica(tip2 ma[][4]);
    GMatrica(std::vector<std::vector<tip>> v);
    GMatrica(std::initializer_list<std::initializer_list<tip>> v);
    int DajBrojRedova() const{return n;}
    int DajBrojKolona() const{return m;}
  template<typename tip1>
    friend GMatrica<double> operator*(const GMatrica<tip1> &, double);
  template<typename tip1>
    friend GMatrica<double> operator*(double, const GMatrica<tip1> &);
  template<typename tip1, typename tip2>
    friend auto operator+(const GMatrica<tip1> &m1, const GMatrica<tip2> &m2)->GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>;
  template<typename tip1, typename tip2>
    friend auto operator-(const GMatrica<tip1> &m1, const GMatrica<tip2> &m2)->GMatrica<decltype(m1.matrica[0][0]-m2.matrica[0][0])>;
  template<typename tip1, typename tip2>
    friend auto operator*(const GMatrica<tip1> &m1, const GMatrica<tip2> &m2)->GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0])>;
  template<typename tip2>
    GMatrica& operator+=(const GMatrica<tip2> &m1);
  template<typename tip2>
    GMatrica& operator-=(const GMatrica<tip2> &m1);
  template<typename tip2>
    GMatrica& operator*=(const GMatrica<tip2> &m1);
    GMatrica& operator*=(double x);
  template<typename tip2>
    bool operator ==(const GMatrica<tip2> &m1) const;
  template<typename tip2>
    bool operator !=(const GMatrica<tip2> &m1) const;
    tip& operator ()(int x, int y);
    tip operator ()(int x, int y) const;
    tip* operator [](int x);
    const tip* operator [](int x) const;
  template<typename tip1>
    friend std::ostream& operator <<(std::ostream &fout, const GMatrica<tip1> &m1);
  template<typename tip1>
    friend std::istream& operator >>(std::istream &fin, GMatrica<tip1> &m1);
};

template<typename tip1>
    std::ostream& operator <<(std::ostream &fout, const GMatrica<tip1> &m1){
        int sirina=fout.width();
        if(sirina<6)sirina=6;
        for(int i=0;i<m1.n;i++){
            for(int j=0;j<m1.m;j++){
                fout<<std::setw(sirina)<<m1.matrica[i][j];
            }
            fout<<"\n";
        }
        return fout;
    }
template<typename tip1>
    std::istream& operator >>(std::istream &fin, GMatrica<tip1> &m1){
        char c;
        tip1 a;
        fin>>c;
        std::vector<std::vector<tip1>> v{{}};
        if(c!='[')fin.setstate(std::ios::failbit);
        do{
            if(!fin)break;
            fin>>a>>c;
            if(!fin)break;
            v[v.size()-1].push_back(a);
            if(c==',')continue;
            if(c==';'){
                v.push_back({});
                continue;
            }
            if(c==']')break;
            fin.setstate(std::ios::failbit);
            break;
        }while(true);
        if(fin){
            try{
                m1=GMatrica<tip1>(v);
            }
            catch(...){
                fin.setstate(std::ios::failbit);
            }
        }
        return fin;
    }
template<typename tip>
    template<typename tip2>
    bool GMatrica<tip>::operator ==(const GMatrica<tip2> &m1) const{
        if(n!=m1.DajBrojRedova() || m!=m1.DajBrojKolona())return false;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(matrica[i][j]!=m1(i+1, j+1))return false;
        return true;
    }
template<typename tip>
    template<typename tip2>
    bool GMatrica<tip>::operator !=(const GMatrica<tip2> &m1) const{
        return !((*this)==m1);
    }
template<typename tip>
    tip& GMatrica<tip>::operator ()(int x, int y){
        if(x<1 || y<1 || x>n || y>m)throw std::range_error("Nedozvoljen indeks");
        return matrica[x-1][y-1];
    }
template<typename tip>
    tip GMatrica<tip>::operator ()(int x, int y) const{
        if(x<1 || y<1 || x>n || y>m)throw std::range_error("Nedozvoljen indeks");
        return matrica[x-1][y-1];
    }
template<typename tip>
    tip* GMatrica<tip>::operator [](int x){
        if(x<0 || x>=n)throw std::range_error("Nedozvoljen indeks");
        return matrica[x];
    }
template<typename tip>
    const tip* GMatrica<tip>::operator [](int x) const{
        if(x<0 || x>=n)throw std::range_error("Nedozvoljen indeks");
        return matrica[x];
    }
template<typename tip>
    GMatrica<tip>::GMatrica():m(0), n(0){}
template<typename tip>
    GMatrica<tip>::GMatrica(int n, int m, tip t):m(m),n(n){
        if(n>4 || m>4 || m<0 || n<0)throw std::logic_error("Ilegalan format matrice");
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                matrica[i][j]=t;
    }
template<typename tip> 
    template<typename tip2>
    GMatrica<tip>::GMatrica(const GMatrica<tip2> &mat){
        n=mat.DajBrojRedova();
        m=mat.DajBrojKolona();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                matrica[i][j]=mat(i+1, j+1);
    }
template<typename tip> 
    template<typename tip2>
    GMatrica<tip>::GMatrica(tip2 ma[][4]){
        n=4;
        m=4;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                matrica[i][j]=ma[i][j];
    }
template<typename tip>
    GMatrica<tip>::GMatrica(std::vector<std::vector<tip>> v){
        n=v.size();
        if(n>4)throw std::logic_error("Ilegalan format matrice");
        for(int i=0;i<n;i++){
            m=v[i].size();
            if(n!=m || m>4)throw std::logic_error("Ilegalan format matrice");
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                matrica[i][j]=v[i][j];
    }
template<typename tip>
    GMatrica<tip>::GMatrica(std::initializer_list<std::initializer_list<tip>> v){
        n=v.size();
        if(n>4)throw std::logic_error("Ilegalan format matrice");
        for(auto i:v){
            m=i.size();
            if(n!=m || m>4)throw std::logic_error("Ilegalan format matrice");
        }
        int x=0, y;
        for(auto i:v){
            y=0;
            for(auto j:i){
                matrica[x][y]=j;
                y++;
            }
            x++;
        }
    }
template<typename tip1, typename tip2>
    auto operator+(const GMatrica<tip1> &m1, const GMatrica<tip2> &m2)->GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])>{
        if(m1.n!=m2.n || m1.m!=m2.m)throw std::domain_error("Nedozvoljena operacija");
        GMatrica<decltype(m1.matrica[0][0]+m2.matrica[0][0])> nova(m1.n, m1.m);
        for(int i=0;i<m1.n;i++)
            for(int j=0;j<m1.m;j++)
                nova.matrica[i][j]=m1.matrica[i][j]+m2.matrica[i][j];
        return nova;
    }
template<typename tip>
    template<typename tip2>
    GMatrica<tip>& GMatrica<tip>::operator +=(const GMatrica<tip2> &m1){
        if(n!=m1.DajBrojRedova() || m!=m1.DajBrojKolona())throw std::domain_error("Nedozvoljena operacija");
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                matrica[i][j]+=m1(i+1, j+1);
        return *this;
    }
template<typename tip1, typename tip2>
    auto operator-(const GMatrica<tip1> &m1, const GMatrica<tip2> &m2)->GMatrica<decltype(m1.matrica[0][0]-m2.matrica[0][0])>{
        if(m1.n!=m2.n || m1.m!=m2.m)throw std::domain_error("Nedozvoljena operacija");
        GMatrica<decltype(m1.matrica[0][0]-m2.matrica[0][0])> nova(m1.n, m1.m);
        for(int i=0;i<m1.n;i++)
            for(int j=0;j<m1.m;j++)
                nova.matrica[i][j]=m1.matrica[i][j]-m2.matrica[i][j];
        return nova;
    }
template<typename tip>
    template<typename tip2>
    GMatrica<tip>& GMatrica<tip>::operator -=(const GMatrica<tip2> &m1){
        if(n!=m1.DajBrojRedova() || m!=m1.DajBrojKolona())throw std::domain_error("Nedozvoljena operacija");
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                matrica[i][j]-=m1(i+1, j+1);
        return *this;
    }
template<typename tip1, typename tip2>
    auto operator*(const GMatrica<tip1> &m1, const GMatrica<tip2> &m2)->GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0])>{
        if(m1.m!=m2.n)throw std::domain_error("Nedozvoljena operacija");
        GMatrica<decltype(m1.matrica[0][0]*m2.matrica[0][0])> nova(m1.n, m2.m);
        for(int i=0;i<m1.n;i++)
            for(int j=0;j<m2.m;j++){
                decltype(m1.matrica[0][0]*m2.matrica[0][0]) a{};
                for(int k=0;k<m1.m;k++)
                    a+=m1.matrica[i][k]*m2.matrica[k][j];
                nova.matrica[i][j]=a;
            }
        return nova;
    }
template<typename tip>
    template<typename tip2>
    GMatrica<tip>& GMatrica<tip>::operator *=(const GMatrica<tip2> &m1){
        if(m!=m1.DajBrojRedova())throw std::domain_error("Nedozvoljena operacija");
        GMatrica<decltype(matrica[0][0]*m1(1, 1))> nova(n, m1.DajBrojKolona());
        for(int i=0;i<n;i++)
            for(int j=0;j<m1.DajBrojKolona();j++){
                decltype(matrica[0][0]*m1(1, 1)) a{};
                for(int k=0;k<m;k++)
                    a+=matrica[i][k]*m1(k+1, j+1);
                nova[i][j]=a;
            }
        m=m1.DajBrojKolona();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                matrica[i][j]=nova[i][j];
        return *this;
    }
template<typename tip>
    GMatrica<tip>& GMatrica<tip>::operator *=(double x){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                matrica[i][j]*=x;
        return *this;
    }
template<typename tip1>
    GMatrica<double> operator*(const GMatrica<tip1> &m1, double x){
        GMatrica<decltype(m1.matrica[0][0]*x)> nova(m1.n, m1.m);
        for(int i=0;i<m1.n;i++)
            for(int j=0;j<m1.m;j++)
                    nova.matrica[i][j]=m1.matrica[i][j]*x;
        return nova;
    }
template<typename tip1>
    GMatrica<double> operator*(double x, const GMatrica<tip1> &m1){
        return m1*x;
    }


int main ()
{
    GMatrica<int> a;
    GMatrica<double> b(a);
    GMatrica<int> c{{1,1},{1,1}};
    std::vector<std::vector<double>> v{{1,1},{1,1}};
    GMatrica<double> d(v);
    double gg[4][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    GMatrica<int> e(gg);
    std::cout<<a<<"g\n"<<b<<"g\n"<<c<<"g\n"<<d;
    std::cout<<e.DajBrojRedova()<<"x"<<e.DajBrojKolona()<<"\n"<<e;
    std::cout<<c+d<<c-d<<d*c<<3*d<<d*3;
    c+=d;
    d-=c;
    d*=c;
    try{
        e+=d;
    }
    catch(std::domain_error gg){
        std::cout<<gg.what()<<"\n";
    }
    std::cout<<d;
    d*=4;
    std::cout<<d;
    std::cout<<(d==c);
    d=c;
    std::cout<<" "<<(d==c)<<"\n";
    std::cout<<c(1,1);
    std::cin>>b;
    if(!std::cin)std::cout<<"nije fino unijeto"; else std::cout<<b;
	return 0;
}
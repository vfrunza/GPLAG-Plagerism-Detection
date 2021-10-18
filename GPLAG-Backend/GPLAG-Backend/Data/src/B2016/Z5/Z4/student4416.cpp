/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <iterator>
template <typename tip>
class GMatrica{
    tip matrica[4][4];
    int br_redova,br_kolona;
  public:
    GMatrica();
    GMatrica(int red,int kolona,tip vrijednost={});
    template <typename tip2>
    GMatrica(const GMatrica<tip2>&m);
    template <typename tip2>
    GMatrica(tip2** niz);
    GMatrica(std::vector<std::vector<tip>> vektor);
    template <typename tip2>
    GMatrica(std::initializer_list<std::initializer_list<tip2>> a);
    int DajBrojRedova()const{return br_redova;}
    int DajBrojKolona()const{return br_kolona;}
    tip&operator()(int a,int b){
        if(a<1 || b<1 || a>br_kolona || b>br_redova)throw std::range_error("Nedozvoljen indeks");
        return matrica[a-1][b-1];
    }
    tip operator()(int a,int b)const{
        if(a<1 || b<1 || a>br_kolona || b>br_redova)throw std::range_error("Nedozvoljen indeks");
        return matrica[a-1][b-1];
    }
    template <typename tip1,typename tip2>
    friend auto operator+(const GMatrica<tip1>&a,const GMatrica<tip2>&b)->GMatrica<decltype(a[0][0]+b[0][0])>;
    template <typename tip1,typename tip2>
    friend auto operator-(const GMatrica<tip1>&a,const GMatrica<tip2>&b)->GMatrica<decltype(a[0][0]-b[0][0])>;
    template <typename tip1,typename tip2>
    friend auto operator*(const GMatrica<tip1>&a,const GMatrica<tip2>&b)->GMatrica<decltype(a[0][0]*b[0][0])>;
    template <typename tip1>
    friend std::ostream&operator<<(std::ostream&tok,const GMatrica<tip1>&m);
    template <typename tip1>
    friend std::istream&operator>>(std::istream&tok,GMatrica<tip1>&m);
    tip* operator[](int indeks){return matrica[indeks];}
    tip* operator[](int indeks)const{return matrica[indeks];}
    template <typename tip1>
    friend auto operator*(const GMatrica<tip1>&a,double koef)->GMatrica<decltype(a[0][0]*koef)>{
        GMatrica<tip1>b(a);
        for(int i=0;i<b.br_redova;i++)
            for(int j=0;j<b.br_kolona;j++)
                b.matrica[i][j]*=koef;
        return b;        
    }
    template <typename tip1>
    friend auto operator*(double koef,GMatrica<tip1>a)->GMatrica<decltype(a[0][0]*koef)>{
        return a*koef;
    }
    template <typename tip1,typename tip2>
    friend bool operator==(const GMatrica<tip1>&a,const GMatrica<tip2>&b);
    template <typename tip1,typename tip2>
    friend bool operator!=(const GMatrica<tip1>&a,const GMatrica<tip2>&b);
    template <typename tip1,typename tip2>
    friend GMatrica<tip1>&operator+=(GMatrica<tip1>&a,const GMatrica<tip2>&b);
    template <typename tip1,typename tip2>
    friend GMatrica<tip1>&operator*=(GMatrica<tip1>&a,const GMatrica<tip2>&b);
    template <typename tip1,typename tip2>
    friend GMatrica<tip1>&operator-=(GMatrica<tip1>&a,const GMatrica<tip2>&b);
    template <typename tip1>
    friend GMatrica<tip1> &operator*=(GMatrica<tip1>&a,double koef){
        for(int i=0;i<a.br_redova;i++)
            for(int j=0;j<a.br_kolona;j++)
                a.matrica[i][j]*=koef;
        return a;        
    }
};
template <typename tip1>
GMatrica<tip1>::GMatrica(){
    br_redova=0;br_kolona=0;
}
template <typename tip1>
GMatrica<tip1>::GMatrica(int red,int kolona,tip1 vrijednost){
    if(red<0 || red>4 || kolona<0 || kolona>4)throw std::logic_error("Ilegalan format matrice"); 
    br_redova=red; br_kolona=kolona;
    for(int i=0;i<red;i++)
        for(int j=0;j<kolona;j++)
            matrica[i][j]=vrijednost;
}
template <typename tip1>
template <typename tip2>
GMatrica<tip1>::GMatrica(const GMatrica<tip2>&m){
    br_redova=m.br_redova;
    br_kolona=m.br_kolona;
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
            matrica[i][j]=m.matrica[i][j];
}
template <typename tip1>
template <typename tip2>
GMatrica<tip1>::GMatrica(tip2** niz){
    br_kolona=4;br_redova=4;
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
            matrica[i][j]=niz[i][j];
}
template <typename tip1>
GMatrica<tip1>::GMatrica(std::vector<std::vector<tip1>> vektor){
    if(vektor.size()>4)throw std::logic_error("Ilegalan format matrice");
    for(int i=0;i<vektor.size()-1;i++)if(vektor[i].size()!=vektor[i+1].size())throw std::logic_error("Ilegalan format matrice");
    br_redova=vektor.size();
    if(br_redova>0)br_kolona=vektor[0].size();
    else br_kolona=0;
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
            matrica[i][j]=vektor[i][j];
}
template <typename tip1>
template <typename tip2>
GMatrica<tip1>::GMatrica(std::initializer_list<std::initializer_list<tip2>> a){
    br_redova=a.size();
    int i=0,j;
    auto it(a.begin());
    br_kolona=it->size();
    while(it!=a.end()){
        if(br_kolona!=it->size())throw std::logic_error("Ilegalan format matrice");
        j=0;
        auto it2(it->begin());
        auto it3(it->end());
        while(it2!=it3){
            matrica[i][j]=tip1(*it2++);
            j++;
        }
        it++;
        i++;
    }
}
template <typename tip1,typename tip2>
auto operator+(const GMatrica<tip1>&a,const GMatrica<tip2>&b)->GMatrica<decltype(a[0][0]+b[0][0])>{
    if(a.br_kolona!=b.br_kolona || a.br_redova!=b.br_redova)throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(a[0][0]+b[0][0])> c(a.br_redova,a.br_kolona);
    for(int i=0;i<a.br_redova;i++)
        for(int j=0;j<a.br_kolona;j++)
            c.matrica[i][j]=a.matrica[i][j]+b.matrica[i][j];
    return c;        
}
template <typename tip1,typename tip2>
auto operator*(const GMatrica<tip1>&a,const GMatrica<tip1>&b)->GMatrica<decltype(a[0][0]-b[0][0])>{
    if(a.br_kolona!=b.br_redova)throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(a[0][0]*b[0][0])> c(a.br_redova,b.br_kolona);
    for(int i=0;i<a.br_redova;i++)
        for(int j=0;j<b.br_kolona;j++)
            for(int k=0;k<a.br_kolona;k++)
                c.matrica[i][j]=a.matrica[i][k]+b.matrica[k][j];
    return c;            
}
template <typename tip1,typename tip2>
auto operator-(const GMatrica<tip1>&a,const GMatrica<tip2>&b)->GMatrica<decltype(a[0][0]-b[0][0])>{
    if(a.br_kolona!=b.br_kolona || a.br_redova!=b.br_redova)throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(a[0][0]-b[0][0])> c(a.br_redova,a.br_kolona);
    for(int i=0;i<a.br_redova;i++)
        for(int j=0;j<a.br_kolona;j++)
            c.matrica[i][j]=a.matrica[i][j]-b.matrica[i][j];
    return c;        
}
template <typename tip1>
std::ostream&operator<<(std::ostream&tok,const GMatrica<tip1>&m){
    int x(std::cout.width());
    if(x<6)x=6;
    for(int i=0;i<m.br_redova;i++){
        for(int j=0;j<m.br_kolona;j++){
            tok<<std::setw(x)<<m.matrica[i][j];
        }
        tok<<std::endl;
    }
    return tok;
}
template <typename tip1>
std::istream&operator>>(std::istream&tok,GMatrica<tip1>&m){
    char znak;
    int i(0),j(0);
    tok>>znak; 
    if(znak!='[') tok.setstate(std::ios::failbit);
    while(znak!=']'&& znak!=0){
        znak='x';
        j=0;
        if(znak==0)tok.setstate(std::ios::failbit);
        while(znak!=';'&&znak!=0&&znak!=']'){
            if(znak==0)tok.setstate(std::ios::failbit);
            if(j>3)tok.setstate(std::ios::failbit);
            tok>>m.matrica[i][j];
            j++;
            tok>>znak;
        }
        if(i>3)tok.setstate(std::ios::failbit);
        i++;
    }
    m.br_redova=i;
    m.br_kolona=j;
    return tok;
}
/*template <typename tip1>
auto operator*(GMatrica<tip1>a,double koef)->GMatrica<decltype(a[0][0]*koef)>{
        for(int i=0;i<a.br_redova;i++)
            for(int j=0;j<a.br_kolona;j++)
                a[i][j]*=koef;
        return a;
}
template <typename tip1>
auto operator*(double koef,GMatrica<tip1>a)->GMatrica<decltype(a[0][0]*koef)>{
    return a*koef;
}*/
template <typename tip1,typename tip2>
bool operator==(const GMatrica<tip1>&a,const GMatrica<tip2>&b){
    if(a.br_kolona!=b.br_kolona||a.br_redova!=b.br_redova)return false;
    for(int i=0;i<a.br_redova;i++)
        for(int j=0;j<a.br_kolona;j++)
            if(a.matrica[i][j]!=b.matrica[i][j])return false;
    return true;        
}
template <typename tip1,typename tip2>
bool operator!=(const GMatrica<tip1>&a,const GMatrica<tip2>&b){
    return !(a==b);
}
template <typename tip1,typename tip2>
GMatrica<tip1>&operator+=(GMatrica<tip1>&a,const GMatrica<tip2>&b){
    if(a.br_kolona!=b.br_kolona || a.br_redova!=b.br_redova)throw std::domain_error("Nedozvoljena operacija");
    for(int i=0;i<a.br_redova;i++)
        for(int j=0;j<a.br_kolona;j++)
            a.matrica[i][j]+=b.matrica[i][j];
    return a;        
}
template <typename tip1,typename tip2>
GMatrica<tip1>&operator-=(GMatrica<tip1>&a,const GMatrica<tip2>&b){
    if(a.br_kolona!=b.br_kolona || a.br_redova!=b.br_redova)throw std::domain_error("Nedozvoljena operacija");
    for(int i=0;i<a.br_redova;i++)
        for(int j=0;j<a.br_kolona;j++)
            a.matrica[i][j]-=b.matrica[i][j];
    return a;
}
template <typename tip1,typename tip2>
GMatrica<tip1>&operator*=(GMatrica<tip1>&a,const GMatrica<tip2>&b){
    if(a.br_kolona!=a.br_redova || b.br_kolona!=b.br_redova || a.br_kolona!=b.br_kolona)throw std::domain_error("Nedozvoljena operacija");
    GMatrica<tip1>c(a.br_redova,a.br_kolona);
    for(int i=0;i<a.br_redova;i++)
        for(int j=0;j<a.br_redova;j++)
            for(int k=0;k<a.br_redova;k++)
                c.matrica[i][j]=a.matrica[i][k]+b.matrica[k][j];
    a=c;
    return a;
}



int main (){
    std::cout<<"blabla\n";
    GMatrica<int> m({{1,2},{3,4}});
    GMatrica<int>m2(m);
    std::cout<<m2;
    //    m*2;
    m[0][0];
    /*//std::cout<<2*m<<std::endl;
    GMatrica<double> b({{1,2},{3,4}});
    std::cout<<m+b<<std::endl;*/
    //auto a(m);
    //std::cout<<a.DajBrojRedova()<<" "<<a.DajBrojKolona()<<" ";
	return 0;
}
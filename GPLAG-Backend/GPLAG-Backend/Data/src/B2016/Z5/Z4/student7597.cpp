/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <vector> 
#include <initializer_list>
#include <iomanip>
#include <stdexcept>

template<typename tip>
class GMatrica{
    int brr;
    int brk;
    tip mat[4][4];
    public:
    GMatrica():brr(0),brk(0){}
    GMatrica(int brr,int brk,tip vrijednost=tip());
    template<typename tip1>
    GMatrica(const GMatrica<tip1> &m); 
    template<typename tip1>
    GMatrica(tip1 **m);
    GMatrica(std::vector<std::vector<tip>> v);
    GMatrica(std::initializer_list<std::initializer_list<tip>> l);
    int DajBrojRedova() const{return brr;}
    int DajBrojKolona() const{return brk;}
    template<typename tip1,typename tip2>
    friend auto operator +(const GMatrica<tip1>& m1,const GMatrica<tip2> &m2)->GMatrica<decltype(m1[0][0]+m2[0][0])>;
    template<typename tip1,typename tip2>
    friend auto operator -(const GMatrica<tip1>& m1,const GMatrica<tip2> &m2)->GMatrica<decltype(m1[0][0]+m2[0][0])>;
    template<typename tip1,typename tip2>
    friend auto operator *(const GMatrica<tip1>& m1,const GMatrica<tip2> &m2)->GMatrica<decltype(m1[0][0]+m2[0][0])>;
    template<typename tip1,typename tip2>
    friend auto operator *(const GMatrica<tip1>& m1,tip2 n)->GMatrica<decltype(m1[0][0]+n)>;
    template<typename tip1,typename tip2>
    friend auto operator *(tip2 n,const GMatrica<tip1>& m1)->GMatrica<decltype(m1[0][0]+n)>;
    tip* operator[](int j){ return mat[j];}
    const tip* const operator [] (int j)const { return mat[j];}
    template<typename tip1>
    GMatrica &operator -=(const GMatrica<tip1>&m2);
    template<typename tip1>
    GMatrica &operator +=(const GMatrica<tip1>&m2);
    template<typename tip1>
    GMatrica &operator *=(const GMatrica<tip1>&m2);
    template<typename tip1,typename tip2>
    friend bool operator !=(const GMatrica<tip1> &m1,const GMatrica<tip2> &m2);
    template<typename tip1,typename tip2>
    friend bool operator ==(const GMatrica<tip1> &m1,const GMatrica<tip2> &m2);
    tip& operator ()(int i,int j);
    tip operator ()(int i,int j)const;
    template<typename tip1>
    friend std::istream &operator>>(std::istream &tok, GMatrica<tip1> &m);
    template<typename tip1>
    friend std::ostream &operator<<(std::ostream &tok,const GMatrica<tip1> &m);
    template<typename tip1>
    GMatrica &operator -=(tip1 n);
    template<typename tip1>
    GMatrica &operator +=(tip1 n);
    template<typename tip1>
    GMatrica &operator *=(tip1 n);
    
};
template<typename tip1>
std::istream &operator>>(std::istream &tok, GMatrica<tip1> &m){
    tok>>std::ws;
    if(tok.peek()!='['){ tok.setstate(std::ios::failbit); return tok;}
    int i=0,j=0; char znak;
    tok>>znak; int kolone[4];
    while(true){
        if(j>4||i>4){ tok.setstate(std::ios::failbit); return tok;}
        if(!(tok>>m[i][j])){ tok.setstate(std::ios::failbit); return tok;}
        if(tok.peek()!=','&&tok.peek()!=';'&&tok.peek()!=']'){ tok.setstate(std::ios::failbit); return tok;}
        tok>>znak;
        j++;
        if(znak==';'){kolone[i]=j;i++; j=0;}
        if(znak==']') break;
    }
    for(int z=0;z<i;z++) if(kolone[0]!=kolone[z]){ tok.setstate(std::ios::failbit); return tok;}
    m.brr=i+1;
    m.brk=kolone[0];
    if(tok.peek()!=' '&&tok.peek()!='\n'&&tok.peek()!='\t'&&tok.peek()!='\v'&&tok.peek()!='\f'&&tok.peek()!=EOF)  tok.setstate(std::ios::failbit);
    return tok;
}
template<typename tip1>
std::ostream &operator <<(std::ostream &tok,const GMatrica<tip1> &m){
    auto sirina(tok.width()); if(sirina<6) sirina=6;
    for(int i=0;i<m.brr;i++){
        for(int j=0;j<m.brk;j++) tok<<std::setw(sirina)<<m[i][j];
        std::cout<<std::endl;
    }
    return tok;
}
template<typename tip>
tip& GMatrica<tip>::operator ()(int i,int j){ 
    if(i>brr||i<1||j>brk||j<1) throw std::range_error("Nedozvoljen indeks");
    return mat[i-1][j-1];
}
template<typename tip>
tip GMatrica<tip>::operator ()(int i,int j)const { 
    if(i>brr||i<1||j>brk||j<1) throw std::range_error("Nedozvoljen indeks");
    return mat[i-1][j-1];
}
template<typename tip>
GMatrica<tip>::GMatrica(int brr,int brk,tip vrijednost):brr(brr),brk(brk){
    if(brr<0||brr>4||brk<0||brk>4) throw std::logic_error("Ilegalan format matrice");
    for(int i=0;i<brr;i++) for(int j=0;j<brk;j++) mat[i][j]=vrijednost;
}
template<typename tip>
template<typename tip1>
GMatrica<tip>::GMatrica(const GMatrica<tip1> &m):brr(m.DajBrojRedova()),brk(m.DajBrojKolona()){
    for(int i=0;i<brr;i++) for(int j=0;j<brk;j++) mat[i][j]=m[i][j];
}
template<typename tip>
template<typename tip1>
GMatrica<tip>::GMatrica(tip1 **m):brr(4),brk(4){
    for(int i=0;i<4;i++)for(int j=0;j<4;j++) mat[i][j]=m[i][j];
}
template<typename tip>
GMatrica<tip>::GMatrica(std::vector<std::vector<tip>> v){
        for(int i=0;i<v.size();i++) if(v[0].size()!=v[i].size()||v[i].size()>4||v.size()>4) throw std::logic_error("Ilegalan format matrice");
        for(int i=0;i<v.size();i++) for(int j=0;j<v[i].size();j++) mat[i][j]=v[i][j];
        brr=v.size(); 
        if(v.size()!=0) brk=v[0].size();
        else brk=0;
}
template <typename tip>
GMatrica<tip>::GMatrica(std::initializer_list<std::initializer_list<tip>> l){
    for(auto it=l.begin();it!=l.end();it++){
        auto it2=l.begin();
        if((*it2).size()!=(*it).size()||(*it).size()>4||l.size()>4)throw std::logic_error("Ilegalan format matrice");
    }
    int i(0),j(0);
    for(auto it=l.begin();it!=l.end();it++){
        for(auto it2=(*it).begin();it2!=(*it).end();it2++){ mat[i][j]=*it2; j++;}
        i++; j=0;
    }
    brr=l.size(); 
    if(l.size()!=0)brk=(*(l.begin())).size();
    else brk=0;
}
template<typename tip1,typename tip2>
auto operator +(const GMatrica<tip1>& m1,const GMatrica<tip2> &m2)->GMatrica<decltype(m1[0][0]+m2[0][0])>{
    if(m1.brr!=m2.brr||m1.brk!=m2.brk) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1[0][0]+m2[0][0])> m(m1.brr,m2.brk);
    for(int i=0;i<m1.brr;i++) for(int j=0;j<m1.brk;j++) m[i][j]=m1[i][j]+m2[i][j];
    return m;
}
template<typename tip,typename tip1>
auto operator -(const GMatrica<tip>& m1,const GMatrica<tip1> &m2)->GMatrica<decltype(m1[0][0]+m2[0][0])>{
    if(m1.brr!=m2.brr||m1.brk!=m2.brk) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1[0][0]+m2[0][0])> m(m1.brr,m2.brk);
    for(int i=0;i<m1.brr;i++) for(int j=0;j<m1.brk;j++) m[i][j]=m1[i][j]-m2[i][j];
    return m;
}
template<typename tip1,typename tip2>
auto operator *(const GMatrica<tip1>& m1,const GMatrica<tip2> &m2)->GMatrica<decltype(m1[0][0]+m2[0][0])>{
    if(m1.brk!=m2.brr)throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1[0][0]+m2[0][0])> m(m1.brr,m2.brk);
    for(int i=0;i<m1.brr;i++){
        for(int j=0;j<m2.brk;i++){
            for(int z=0;z<m2.brr;z++) m[i][j]+=m1[i][z]*m2[z][j];
        }
    }
}
template<typename tip1,typename tip2>
auto operator *(const GMatrica<tip1>& m1,tip2 n)->GMatrica<decltype(m1[0][0]+n)>{
    GMatrica<decltype(m1[0][0]+n)> m(m1);
    for(int i=0;i<m.brr;i++)for(int j=0;j<m.brk;j++) m[i][j]*=n;
    return m;
}
template<typename tip1,typename tip2>
auto operator *(tip2 n,const GMatrica<tip1>& m1)->GMatrica<decltype(m1[0][0]+n)>{
    GMatrica<decltype(m1[0][0]+n)> m(m1);
    for(int i=0;i<m.brr;i++)for(int j=0;j<m.brk;j++) m[i][j]*=n;
    return m;
}
template<typename tip>
template<typename tip1>
GMatrica<tip>& GMatrica<tip>::operator *=(tip1 n){
    for(int i=0;i<brr;i++) for(int j=0;j<brk;j++) mat[i][j]*=n;
    return *this;
}
template<typename tip>
template<typename tip1>
GMatrica<tip>& GMatrica<tip>::operator +=(tip1 n){
    for(int i=0;i<brr;i++) for(int j=0;j<brk;j++) mat[i][j]+=n;
    return *this;
}
template<typename tip>
template<typename tip1>
GMatrica<tip>& GMatrica<tip>::operator -=(tip1 n){
    for(int i=0;i<brr;i++) for(int j=0;j<brk;j++) mat[i][j]-=n;
    return *this;
}
  template<typename tip>
  template<typename tip1>
GMatrica<tip>& GMatrica<tip>::operator*= (const GMatrica<tip1> &m2){
    if((*this).brk!=m2.brr)throw std::domain_error("Nedozvoljena operacija");
    auto m1(*this);
    for(int i=0;i<m1.brr;i++){
        for(int j=0;j<m2.brk;i++){
            mat[i][j]=0;
            for(int z=0;z<m2.brr;z++) mat[i][j]+=m1[i][z]*m2[z][j];
        }
    }
    brr=m1.brr; brk=m2.brk;
    return *this;
}
template<typename tip>
template<typename tip1>
GMatrica<tip>& GMatrica<tip>::operator +=(const GMatrica<tip1>&m2){
    if(brr!=m2.brr||brk!=m2.brk) throw std::domain_error("Nedozvoljena operacija");
    for(int i=0;i<m2.brr;i++) for(int j=0;j<m2.brk;j++) mat[i][j]+=m2[i][j];
    return *this;
}
template <typename tip>
template<typename tip1>
GMatrica<tip>& GMatrica<tip>::operator -=(const GMatrica<tip1>&m2){
    if(brr!=m2.brr||brk!=m2.brk) throw std::domain_error("Nedozvoljena operacija");
    for(int i=0;i<m2.brr;i++) for(int j=0;j<m2.brk;j++) mat[i][j]-=m2[i][j];
    return *this;
}
template<typename tip1, typename tip2>
bool operator ==(const GMatrica<tip1> &m1,const GMatrica<tip2> &m2){
    if(m1.brr!=m2.brr||m1.brk!=m2.brk) return false;
    for(int i=0;i<m1.brr;i++) for(int j=0;j<m1.brk;j++) if(m1[i][j]!=m2[i][j]) return false;
    return true;
}
template<typename tip1,typename tip2>
bool operator !=(const GMatrica<tip1> &m1,const GMatrica<tip2> &m2){
    if(m1.brr!=m2.brr||m1.brk!=m2.brk) return true;
    for(int i=0;i<m1.brr;i++) for(int j=0;j<m1.brk;j++) if(m1[i][j]!=m2[i][j]) return true;
    return false;
}
int main ()
{ 
GMatrica<int> m1({{1, 2}, {3, 4}});
   GMatrica<int> m2({{1, 2}, {3, 4}});
   GMatrica<double> m3({{1, 2}, {3, 5}});
  GMatrica<int> m(m3);
}
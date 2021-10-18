/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>

template <typename Tip>
class GMatrica{
    
    private:
        Tip mat[4][4];
        int redovi,kolone;
    public:
        int DajBrojRedova() const {return redovi;}
        int DajBrojKolona() const {return kolone;}
        GMatrica():redovi(0),kolone(0){}
        GMatrica(int redovi, int kolone, Tip inc_vrijednost=Tip{});
        GMatrica(const GMatrica<Tip> &m);
        GMatrica(Tip niz[4][4]);
        GMatrica(std::vector<std::vector<Tip>> v);
        GMatrica(std::initializer_list<std::initializer_list<Tip>> l);
        
        template <typename Tip1, typename Tip2>
        friend GMatrica operator +(GMatrica m1, GMatrica m2);
        template <typename Tip1, typename Tip2>
        friend GMatrica operator -(GMatrica m1, GMatrica m2);
        template <typename Tip1, typename Tip2>
        friend GMatrica operator *(GMatrica m1, GMatrica m2);
        template <typename Tip1, typename Tip2>
        friend GMatrica operator *(GMatrica m, Tip2 koef);
        template <typename Tip1, typename Tip2>
        friend GMatrica operator *(Tip2 koef, GMatrica m);
        template<typename Tip1>
        friend bool operator ==(GMatrica m1, GMatrica m2);
        template<typename Tip1>
        friend bool operator !=(GMatrica m1, GMatrica m2);
        template<typename Tip2>
        friend std::ostream& operator<<(std::ostream &tok, const GMatrica<Tip2> &m);
        template<typename Tip1>
        friend std::istream& operator>>(std::istream &tok,GMatrica<Tip1> &m);
        GMatrica &operator +=(const GMatrica &m);
        GMatrica &operator -=(const GMatrica &m);
        GMatrica &operator *=(Tip koef);
        GMatrica &operator *=(const GMatrica &m);
        Tip* operator[] (int i){
            return mat[i];
        }
        Tip &operator()(int i, int j){
            if(i<1 || j<1 || i>redovi || i>kolone)
                throw std::range_error("Nedozvoljen indeks");
            return mat[i-1][j-1];
        }
        
        
};

template<typename Tip1>
std::ostream& operator<<(std::ostream &tok, const GMatrica<Tip1> &m){
    int s=tok.width();
    if(s<6) s=6;
    for(int i=0;i<m.redovi;i++){
        for(int j=0;j<m.kolone;j++){
            tok<<std::setw(s)<<m.mat[i][j];
        }
        tok<<std::endl;
    }
    return tok;
}
template<typename Tip1>
std::istream& operator>>(std::istream &tok, GMatrica<Tip1> &m){
    char znak;
    tok>>znak;
    GMatrica<Tip1> p(4,4);
    if(znak!='['){
        tok.setstate(std::ios::failbit);
        return tok;
    }
    for(int i=0;i<p.redovi;i++){
        for(int j=0;j<p.kolone;j++){
            
        
        if(i==0){
            tok>>p(i+1,j+1);
            tok>>znak;
            if(znak==';')
            p.kolone=j+1;
        }
        else{
        tok>>p(i+1,j+1);
        tok>>znak;
        if((znak==';' && j<p.kolone-1)){
            tok.setstate(std::ios::failbit);
        }
        if(j==p.kolone-1 && znak==',')
            tok.setstate(std::ios::failbit);
        
        else if(znak==']'&&j==p.kolone-1){
            p.redovi=i+1;
            m=p;
            return tok;
        }
        }
        }
    }
    return tok;
}
template<typename Tip1>
GMatrica<Tip1>::GMatrica(int redovi, int kolone, Tip1 inc_vrijednost){
    if(redovi<0 || redovi>4 || kolone<0 || kolone>4)
        throw std::logic_error("Ilegalan format matrice");
    GMatrica::redovi=redovi;
    GMatrica::kolone=kolone;
    for(int i=0;i<redovi;i++){
        for(int j=0;j<kolone;j++){
            mat[i][j]=inc_vrijednost;
        }
    }
}
template<typename Tip1>
GMatrica<Tip1>::GMatrica(const GMatrica<Tip1> &m){
    redovi=m.redovi;
    kolone=m.kolone;
    for(int i=0;i<m.redovi;i++){
        for(int j=0;j<m.kolone;j++){
            mat[i][j]=m.mat[i][j];
        }
    }
}
template<typename Tip1>
GMatrica<Tip1>::GMatrica(Tip1 niz[4][4]){
    redovi=4;
    kolone=4;
    for(int i=0; i<4; i++){
        for(int j=0;j<4;j++){
            mat[i][j]=niz[i][j];
        }
    }
}
template<typename Tip1>
GMatrica<Tip1>::GMatrica(std::vector<std::vector<Tip1>> v){
    if(v.size()>4)
        throw std::logic_error("Ilegalan format matrice");
    if(v.size==0)
        redovi=0,kolone=0;
    else{
        redovi=v.size();
        int br=v[0].size();
        if(br>4)
            throw std::logic_error("Ilegalan format matrice");
        for(int i=0;i<redovi;i++){
            if(v[i].size()!=br)
                throw std::logic_error("Ilegalan format matrice");
        }
        kolone=br;
        for(int i=0;i<redovi;i++){
            for(int j=0;j<kolone;j++){
                mat[i][j]=v[i][j];
            }
        }
    }
}
template<typename Tip1>
GMatrica<Tip1>::GMatrica(std::initializer_list<std::initializer_list<Tip1>> l){
    if(l.size()>4)
        throw std::logic_error("Ilegalan format matrice");
    if(l.size()==0){
        redovi=0; kolone=0;
    }
    else{
        auto it=l.begin();
        int br=it->size();
        while(it!=l.end()){
            if(it->size()!=br){
                throw std::logic_error("Ilegalan format matrice");
            }
            it++;
        }
        int a=0;
        auto it1=l.begin();
        while(it1!=l.end()){
            auto it2=it1->begin();
            int b=0;
            while(it2!=it1->end()){
                mat[a][b]=*it2;
                it2++;
                b++;
            }
            a++;
            it1++;
        }
        redovi=l.size();
        kolone=l.begin()->size();
    }
}
template<typename Tip1>
GMatrica<Tip1> &GMatrica<Tip1>::operator +=(const GMatrica<Tip1> &m){
    if(m.redovi!=redovi || m.kolone!=kolone)
        throw std::domain_error("Nedozvoljena operacija");
    
    for(int i=0;i<redovi;i++){
        for(int j=0;j<kolone;j++){
            mat[i][j]+=m.mat[i][j];
        }
    }
    return *this;
}
template<typename Tip1>
GMatrica<Tip1> &GMatrica<Tip1>::operator -=(const GMatrica<Tip1> &m){
    if(m.redovi!=redovi || m.kolone!=kolone)
        throw std::domain_error("Nedozvoljena operacija");
        
    for(int i=0;i<redovi;i++){
          for(int j=0;j<kolone;j++){
            mat[i][j]-=m.mat[i][j];
        }
    }
    return *this;
}
template<typename Tip1>
GMatrica<Tip1> &GMatrica<Tip1>::operator *=(Tip1 koef){
    for(int i=0;i<redovi;i++)
        for(int j=0;j<kolone;j++)
            mat[i][j]*=koef;
    return *this;
}
template<typename Tip1>
GMatrica<Tip1> &GMatrica<Tip1>::operator *=(const GMatrica<Tip1> &m){
    if(kolone!=m.redovi)
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<Tip1> pom(redovi,m.kolone);
    for(int i=0;i<pom.redovi;i++){
        for(int j=0;j<pom.kolone;j++){
            Tip1 suma{};
            for(int k=0;k<m.redovi;k++){
                suma+=mat[i][k]*m.mat[k][j];
            }
            pom.mat[i][j]=suma;
        }
    }
    *this=pom;
    return *this;
}
template <typename Tip1>
bool operator ==(GMatrica<Tip1> m1, GMatrica<Tip1> m2){
    if(m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona())
    return false;
    
    for(int i=0;i<m1.DajBrojRedova();i++){
        for(int j=0;j<m1.DajBrojKolona();j++){
            if(m1[i][j]!=m2[i][j])
                return false;
        }
    }
    
    return true;
}
template <typename Tip1>
bool operator !=(GMatrica<Tip1> m1, GMatrica<Tip1> m2){
    return !(m1==m2);
}

template<typename Tip1, typename Tip2>
auto operator+ (GMatrica<Tip1> m1,GMatrica<Tip2> m2) -> GMatrica<decltype(m1[0][0]+m2[0][0])> {
    if(m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona())
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1[0][0]+m2[0][0])> m3(m1.DajBrojRedova(),m1.DajBrojKolona());
    
    for(int i=0;i<m3.DajBrojRedova();i++){
        for(int j=0;j<m3.DajBrojKolona();j++){
            m3[i][j]=m1[i][j]+m2[i][j];
        }
    }
    return m3;
}
template<typename Tip1, typename Tip2>
auto operator- (GMatrica<Tip1> m1,GMatrica<Tip2> m2) -> GMatrica<decltype(m1[0][0]-m2[0][0])> {
    if(m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojRedova()!=m2.DajBrojKolona())
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1[0][0]-m2[0][0])> m3(m1.DajBrojRedova(),m2.DajBrojKolona());
    for(int i=0;i<m3.DajBrojRedova();i++){
        for(int j=0;j<m3.DajBrojKolona();j++){
            m3[i][j]=m1[i][j]-m2[i][j];
        }
    }
    return m3;
}
template<typename Tip1, typename Tip2>
auto operator* (GMatrica<Tip1> m1,GMatrica<Tip2> m2) -> GMatrica<decltype(m1[0][0]*m2[2][0])> {
    if(m1.kolone!=m2.redovi)
        throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1[0][0]*m2[0][0])> m3(m1.redovi,m2.kolone);
    for(int i=0; i<m3.redovi;i++){
        for(int j=0;j<m3.kolone;j++){
            decltype(m1[0][0]*m2[0][0]) suma(0);
            for(int k=0;k<m2.redovi;k++){
                suma+=m1.mat[i][k]*m2.mat[k][j];
            }
            m3.mat[i][j]=suma;
        }
    }
    return m3;
}
template <typename Tip1, typename Tip2>
auto operator* (GMatrica<Tip1> m, Tip2 koef) ->GMatrica<decltype(m[0][0]*koef)>{
    for(int i=0;i<m.DajBrojRedova();i++){
        for(int j=0;j<m.DajBrojKolona();j++){
            m(i+1,j+1)*=koef;
        }
    }
    return m;
}
template<typename Tip1, typename Tip2>
auto operator* (Tip2 koef, GMatrica<Tip1> m) -> GMatrica<decltype(m[0][0]*koef)>{
    for(int i=0;i<m.DajBrojRedova();i++){
        for(int j=0;j<m.DajBrojKolona();j++){
            m(i+1,j+1)*=koef;
        }
    }
    return m;
}

int main ()
{
    GMatrica<int> m1(2,2,4),m2(2,2,6);
    GMatrica<int>m3= m1+m2;
    m2*=4;
    m3*=m1;
    m1+=m2;
    std::cout<<m1;
    m1*=8;
    m2-=m1;
    std::cout<<m2;
    
	return 0;
}
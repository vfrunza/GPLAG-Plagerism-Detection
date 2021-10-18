/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iomanip>

template <typename Tip>
class GMatrica{
    Tip niz[4][4];
    int br_redova,br_kolona;
    void ProvjeriFormat(int a,int b) const {
        if(a>4 || a<0 || b>4 || b<0)throw std::logic_error("Ilegalan format matrice");
    }
    void ProvjeriVektor(std::vector<std::vector<Tip>>v){
        for(int i=0;i<v.size()-1;i++){
            if(v[i].size()!=v[i+1].size())throw std::logic_error("Ilegalan format matrice");
        }
        try{
            ProvjeriFormat(v.size(),v[0].size());
        }
        catch(...){
            throw;
        }
    }
    void ProvjeriListu(std::initializer_list<std::initializer_list<Tip>> l){
        int br;
        for(auto i : l){br=i.size(); break; }
        for(auto i: l){
            if(i.size()!=br)throw std::logic_error("Ilegalan format matrice");
        }
        try{
            ProvjeriFormat(l.size(),br);
        }
        catch(...){
            throw;
        }
    }
    public:
        //KONSTRUKTOR SA I BEZ PARAMETARA
        GMatrica(int br_red=0,int br_kol=0,Tip broj=Tip());
        
        //PRISTUPNE METODE
        int DajBrojRedova() const { return br_redova ;}
        int DajBrojKolona() const { return br_kolona ;}
        
        //GENERICKI KOPIRAJUCI KONSTRUKTOR
        template <typename Tip1>
        GMatrica(const GMatrica<Tip1> &g);
        
        //GENERICKI KONSTRUKTOR (C-ovski 2D niz)
        template <typename Tip1>
        GMatrica(Tip1 n [4][4]);
        
        //KOSTRUKTOR KOJI PRIMA VEKTOR VEKTORA
        GMatrica(std::vector<std::vector<Tip>> v);
        
        //SEKVENCIJSKI KONSTRUKTOR
        GMatrica(std::initializer_list<std::initializer_list<Tip>>lista);
        
        //OPERATORI + , - , *
        template <typename Tip1,typename Tip2>
        friend auto operator +(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.niz[0][0]+m2.niz[0][0])>;
        
        template <typename Tip1,typename Tip2>
        friend auto operator -(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.niz[0][0]-m2.niz[0][0])>;
        
        template <typename Tip1,typename Tip2>
        friend auto operator *(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.niz[0][0]*m2.niz[0][0])>;
        
        template <typename Tip1,typename Tip2>
        friend auto operator *(Tip1 broj,const GMatrica<Tip2> &m2)->GMatrica<decltype(broj+m2.niz[0][0])>;
        
        template <typename Tip1,typename Tip2>
        friend auto operator *(const GMatrica<Tip1> &m2,Tip2 broj)->GMatrica<decltype(m2.niz[0][0]+broj)>;
        
        //PREKLOPLJENI OPERATORI
        GMatrica &operator +=(const GMatrica &m2);
        GMatrica &operator -=(const GMatrica &m2);
        GMatrica &operator *=(Tip broj);
        
        //OPERATORI JEDNAKOSTI/NEJEDNAKOSTI
        template<typename Tip2>
        friend bool operator ==(const GMatrica<Tip2> &m1,const GMatrica<Tip2> &m2);
        
        template<typename Tip2>
        friend bool operator !=(const GMatrica<Tip2> &m1,const GMatrica<Tip2> &m2);
        
        //OPERATORI () I [][]
        Tip &operator ()(int i,int j);
        Tip operator ()(int i,int j)const;
        Tip* operator [](int i);
        const Tip* operator [](int i)const;
        
        //OPERATORI ISPISA I UNOSA << >>
        template<typename Tip2>
        friend std::ostream &operator <<(std::ostream &tok,const GMatrica<Tip2> &m);
        
        template<typename Tip1>
        friend std::istream &operator >>(std::istream &tok,GMatrica<Tip1> &m);
        
};

template<typename Tip>
GMatrica<Tip>::GMatrica(int br_red,int br_kol,Tip broj){
    ProvjeriFormat(br_red,br_kol);
    br_redova=br_red; br_kolona=br_kol;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            niz[i][j]=broj;
        }
    }
}

template<typename Tip>
template<typename Tip1>
GMatrica<Tip>::GMatrica(const GMatrica<Tip1> &g):br_redova(g.DajBrojRedova()),br_kolona(g.DajBrojKolona()){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i<br_redova && j<br_kolona){
                niz[i][j]=g.niz[i][j];
            }
            else niz[i][j]=Tip();
        }
    }
}
template<typename Tip>
template<typename Tip1>
GMatrica<Tip>::GMatrica(Tip1 n [4][4]):br_redova(4),br_kolona(4){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            niz[i][j]=n[i][j];               
        }
    }
}

template<typename Tip>
GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip>> v){
    ProvjeriVektor(v);
    br_redova=v.size(); br_kolona=v[0].size();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i<br_redova && j<br_kolona){
                niz[i][j]=v[i][j];
            }
            else niz[i][j]=Tip();
        }
    }
}

template<typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Tip>>lista){
    ProvjeriListu(lista);
    br_redova=lista.size();
        for(auto i:lista){ br_kolona=i.size(); break; }
        int br(0);
        for(auto i:lista){
            std::copy(i.begin(),i.end(),niz[br]);
            br++;
        }
}

template <typename Tip1,typename Tip2>
auto operator +(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.niz[0][0]+m2.niz[0][0])>{
    if(m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.niz[0][0]+m2.niz[0][0])> m(m1.DajBrojRedova(),m1.DajBrojKolona(),decltype(m1.niz[0][0]+m2.niz[0][0])());
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i<m1.DajBrojRedova() && j< m2.DajBrojKolona())m.niz[i][j]=m1.niz[i][j]+m2.niz[i][j];
            else m.niz[i][j]=decltype(m1.niz[0][0]+m2.niz[0][0])();
        }
    }
    return m;
}

template <typename Tip1,typename Tip2>
auto operator -(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.niz[0][0]-m2.niz[0][0])>{
    if(m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.niz[0][0]-m2.niz[0][0])> m(m1.DajBrojRedova(),m1.DajBrojKolona(),decltype(m1.niz[0][0]-m2.niz[0][0])());
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i<m1.DajBrojRedova() && j< m2.DajBrojKolona())m.niz[i][j]=m1.niz[i][j]-m2.niz[i][j];
            else m.niz[i][j]=decltype(m1.niz[0][0]-m2.niz[0][0])();
        }
    }
    return m;
}

template <typename Tip1,typename Tip2>
auto operator *(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.niz[0][0]*m2.niz[0][0])>{
    if(m1.DajBrojKolona()!=m2.DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(m1.niz[0][0]*m2.niz[0][0])> m(m1.DajBrojRedova(),m2.DajBrojKolona(),decltype(m1.niz[0][0]*m2.niz[0][0])());
    for(int i=0;i<m1.DajBrojRedova();i++){
        decltype(m1.niz[0][0]*m2.niz[0][0]) sum;
        for(int j=0;j<m2.DajBrojKolona();j++){
            sum=decltype(m1.niz[0][0]*m2.niz[0][0])();
            for(int k=0;k<m1.DajBrojKolona();k++){
                sum=sum+m1.niz[i][k]*m2.niz[k][j];
            }
            m.niz[i][j]=sum;
        }
    }
    return m;
}

template <typename Tip1,typename Tip2>
auto operator *(Tip1 broj,const GMatrica<Tip2> &m2)->GMatrica<decltype(broj+m2.niz[0][0])>{
    GMatrica<decltype(broj*m2.niz[0][0])> m(m2.DajBrojRedova(),m2.DajBrojKolona(),decltype(broj*m2.niz[0][0])());
    for(int i=0;i<m2.DajBrojRedova();i++){
        for(int j=0;j<m2.DajBrojKolona();j++){
            m.niz[i][j]=broj*m2.niz[i][j];
        }
    }
    return m;
}

template <typename Tip3,typename Tip4>
auto operator *(const GMatrica<Tip3> &m2,Tip4 broj)->GMatrica<decltype(m2.niz[0][0]+broj)>{
    return broj*m2;
}

template<typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator +=(const GMatrica<Tip> &m2){
    if(DajBrojRedova()!=m2.DajBrojRedova() || DajBrojKolona()!=m2.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija");
    for(int i=0;i<DajBrojRedova();i++){
        for(int j=0;j<DajBrojKolona();j++){
            niz[i][j]+=m2.niz[i][j];
        }
    }
    return *this;
}

template<typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator -=(const GMatrica<Tip> &m2){
    if(DajBrojRedova()!=m2.DajBrojRedova() || DajBrojKolona()!=m2.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija");
    for(int i=0;i<DajBrojRedova();i++){
        for(int j=0;j<DajBrojKolona();j++){
            niz[i][j]-=m2.niz[i][j];
        }
    }
    return *this;
}

template<typename Tip>
GMatrica<Tip> &GMatrica<Tip>::operator *=(Tip broj){
    for(int i=0;i<DajBrojRedova();i++){
        for(int j=0;j<DajBrojKolona();j++){
                niz[i][j]*=broj;
        }
    }
    return *this;
}
template<typename Tip>
bool operator ==(const GMatrica<Tip> &m1,const GMatrica<Tip> &m2){
    if(m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona()) return false;
    for(int i=0;i<m1.DajBrojRedova();i++){
        for(int j=0;j<m1.DajBrojKolona();j++){
            if(m1.niz[i][j]!=m2.niz[i][j])return false;
        }
    }
    return true;
}

template<typename Tip>
bool operator !=(const GMatrica<Tip> &m1,const GMatrica<Tip> &m2){
    return !(m1==m2);
}

template<typename Tip>
Tip &GMatrica<Tip>::operator ()(int i,int j){
    if(i-1<0 || j-1<0 || i-1>4 || j-1>4 )std::range_error("Nedozvoljen indeks");
    return niz[i-1][j-1];
}

template<typename Tip>
Tip GMatrica<Tip>::operator ()(int i,int j)const{
    if(i-1<0 || j-1<0 || i-1>4 || j-1>4 )std::range_error("Nedozvoljen indeks");
    return niz[i-1][j-1];
}

template<typename Tip>
Tip* GMatrica<Tip>::operator [](int i){
    return niz[i];
}

template<typename Tip>
const Tip* GMatrica<Tip>::operator [](int i)const {
    return niz[i];
}

template<typename Tip>
std::ostream &operator <<(std::ostream &tok,const GMatrica<Tip> &m){    
    int a(tok.width());
    for(int i=0;i<m.DajBrojRedova();i++){
        for(int j=0;j<m.DajBrojKolona();j++){
            if(a<6) tok << std::setw(6) << m.niz[i][j];
            else tok << std::setw(a) << m.niz[i][j];
        }
        tok<< std::endl;
    }
    return tok;
}

template<typename Tip>
std::istream &operator >>(std::istream &tok,GMatrica<Tip> &m){
    char znak;
    tok >> std::ws;
    tok >> znak;
    if(znak!='[')tok.setstate(std::ios::failbit);
    else {
        for(int i=0;i<4;i++){
            m.br_redova=i+1;
            for(int j=0;j<4;j++){
                int br;
                tok >> std::ws;
                tok>> br;
                if(!tok)tok.setstate(std::ios::failbit);
                m.br_kolona=j+1;
                m.niz[i][j]=br;
                    char znak1;
                    tok >> std::ws;
                    tok >> znak1;
                    if(znak1==',')continue;
                    else if(znak1==';')break;
                    else if(znak1==']'){ i=5; break; }
                    else tok.setstate(std::ios::failbit);
            }
        }
    }
    return tok;
}

int main ()
{
   
	return 0;
}
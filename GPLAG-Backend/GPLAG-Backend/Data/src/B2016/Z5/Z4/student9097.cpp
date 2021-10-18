/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>
template <typename TipElemenata>
class GMatrica{
    TipElemenata Elementi[4][4];
    int BrojRedova,BrojKolona;
    public:
        GMatrica():BrojKolona(0),BrojRedova(0){}
        GMatrica(int BrojRedova,int BrojKolona, TipElemenata PodrazumijevanaVrijednost=TipElemenata());
        GMatrica(const GMatrica &M);
        //template<typename TipElemenata2>
        GMatrica(TipElemenata** Matrica);
        //template<typename TipElemenata2>
        GMatrica(std::vector<std::vector<TipElemenata>> Matrica);
        //template<typename TipElemenata2>
        GMatrica(std::initializer_list<TipElemenata> lista);
        TipElemenata* operator[](int i)const {return Elementi[i];}
        TipElemenata &operator ()(int i, int j){
            if(i>DajBrojRedova() || i<=0 || j>DajBrojKolona() || j<=0) throw std::range_error("Nedozvoljen indeks");
            return Elementi[i-1][j-1];
        }
        int DajBrojRedova() const{return BrojRedova;}
        int DajBrojKolona() const{return BrojKolona;}
        template<typename TipElemenata2>
        friend GMatrica &operator+(const GMatrica<TipElemenata2> &, const GMatrica<TipElemenata2> &); 
        template<typename TipElemenata2>
        friend GMatrica<TipElemenata2> operator-(const GMatrica<TipElemenata2> &,const GMatrica<TipElemenata2> &);
        GMatrica<TipElemenata> &operator*();
        GMatrica<TipElemenata> &operator+=(const GMatrica<TipElemenata> &);
        GMatrica<TipElemenata> &operator-=(const GMatrica<TipElemenata> &);
 //       GMatrica<TipElemenata> &operator*=();
        template<typename TipElemenata2>
        friend bool operator==(const GMatrica<TipElemenata2> &,const GMatrica<TipElemenata2> &);
        template<typename TipElemenata2>
        friend bool operator!=(const GMatrica<TipElemenata2> &,const GMatrica<TipElemenata2> &);
        template<typename TipElemenata2>
        friend std::ostream &operator<<(std::ostream &,const GMatrica<TipElemenata2> &);
        template<typename TipElemenata2>
        friend std::istream &operator>>(std::istream &,const GMatrica<TipElemenata2> &);
};
template<typename TipElemenata>
GMatrica<TipElemenata>::GMatrica(std::vector<std::vector<TipElemenata>> Matrica){
    if(Matrica.size()<0 || Matrica.size()>4) throw std::logic_error("Ilegalan format matrice");
    for(auto x:Matrica){
        if(x.size()>4 || x.size()!=Matrica[0].size()) throw std::logic_error("Ilegalan format matrice");
    }
    BrojRedova=Matrica.size();
    if(BrojRedova!=0) BrojKolona=Matrica[0].size(); else BrojKolona=0;
    for(int i=0;i<BrojRedova;i++)
        for(int j=0;j<BrojKolona;j++) Elementi[i][j]=Matrica[i][j];
}
//template<typename TipElemenata,typename TipElemenata2>
template<typename TipElemenata>
GMatrica<TipElemenata>::GMatrica(TipElemenata** Matrica):BrojRedova(4),BrojKolona(4){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)    Elementi[i][j]=Matrica[i][j];
}
template<typename TipElemenata>
GMatrica<TipElemenata>::GMatrica(const GMatrica<TipElemenata> &M): BrojKolona(M.BrojKolona),BrojRedova(M.BrojRedova){
    for(int i=0;i<BrojRedova;i++)
        for(int j=0;j<BrojKolona;j++)
            Elementi[i][j]=M.Elementi[i][j];
}
template<typename TipElemenata>
GMatrica<TipElemenata>::GMatrica(int BrojRedova, int BrojKolona, TipElemenata PodrazumijevanaVrijednost){
    if(BrojRedova<0 || BrojRedova>4 || BrojKolona<0 || BrojKolona>4) throw std::logic_error("Ilegalan format matrice");
    GMatrica::BrojRedova=BrojRedova; GMatrica::BrojKolona=BrojKolona;
    for(int i=0;i<BrojRedova;i++)
        for(int j=0;j<BrojKolona;j++)   Elementi[i][j]=PodrazumijevanaVrijednost;
}
template<typename TipElemenata>
std::ostream &operator <<(std::ostream &tok,const GMatrica<TipElemenata> &m){
    int sirina(tok.width());
    if(sirina<6) sirina=6;
    for(int i=0;i<m.DajBrojRedova();i++){
        for(int j=0;j<m.DajBrojKolona();j++)
            tok<<std::setw(sirina)<<m.Elementi[i][j];
        tok<<std::endl;
    }
    return tok;
}
template<typename TipElemenata>
bool operator!=(const GMatrica<TipElemenata> &m1, const GMatrica<TipElemenata> &m2){
    if(m1.DajBrojKolona()!=m2.DajBrojKolona() || m1.DajBrojRedova()!=m2.DajBrojRedova()) return true;
    for(int i=0;i<m1.DajBrojRedova();i++)
        for(int j=0;j<m2.DajBrojKolona();j++)
            if(m1.Elementi[i][j]!=m2.Elementi[i][j]) return true;
    return false;
}
template<typename TipElemenata>
bool operator==(const GMatrica<TipElemenata> &m1,const GMatrica<TipElemenata> &m2){
    if(m1.DajBrojKolona()!=m2.DajBrojKolona() || m1.DajBrojRedova()!=m2.DajBrojRedova()) return false;
    for(int i=0;i<m1.DajBrojRedova();i++)
        for(int j=0;j<m2.DajBrojKolona();j++)
            if(m1.Elementi[i][j]!=m2.Elementi[i][j]) return false;
    return true;
}
template <typename TipElemenata>
GMatrica<TipElemenata> &GMatrica<TipElemenata>::operator+=(const GMatrica<TipElemenata> &m){
    if(DajBrojKolona()!=m.DajBrojKolona() || DajBrojRedova()!=m.DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija");
    for(int i=0;i<DajBrojRedova();i++)
        for(int j=0;j<DajBrojKolona();j++)
            Elementi[i][j]+=m.Elementi[i][j];
    return *this;
}
template<typename TipElemenata>
GMatrica<TipElemenata> &GMatrica<TipElemenata>::operator-=(const GMatrica<TipElemenata> &m){
    if(DajBrojKolona()!=m.DajBrojKolona() || DajBrojRedova()!=m.DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija");
    for(int i=0;i<DajBrojRedova();i++)
        for(int j=0;j<DajBrojKolona();j++)
            Elementi[i][j]-=m.Elementi[i][j];
    return *this;
}
template<typename TipElemenata, typename TipElemenata2>
auto operator +(const GMatrica<TipElemenata> &m1, const GMatrica<TipElemenata2> &m2) -> GMatrica<decltype(m1.Elementi[0][0]+m2.Elementi[0][0])>{ 
    if(m1.BrojRedova!=m2.BrojRedova || m1.BrojKolona!=m2.BrojKolona) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<TipElemenata2> m(m1.BrojRedova,m1.BrojKolona);
    
}
//template<typename TipElemenata,typename TipElemenata2>
template<typename TipElemenata>
GMatrica<TipElemenata>::GMatrica(std::initializer_list<TipElemenata> lista){
    if(lista.size()<0 || lista.size()>4) throw std::logic_error("Ilegalan format matrice");
    bool Prva(true);
    int Kolone;
    for(auto x: lista){
        if(!Prva){if (Kolone!=x.size()) throw std::logic_error("Ilegalan format matrice");}
        if(Prva){Kolone=x.size();Prva=false;}
    }
    BrojKolona=Kolone;
    BrojRedova=lista.size();
    int i(0),j(0);
    for(auto x: lista){
        for(auto y:x){
            Elementi[i][j]=*y;
            j++;
        }
        i++;
    }        
}
int main2 (){
    
	return 0;
}
int main1(){
    //operator+ i operator- i <<
   
   GMatrica<double> m1({{1, 2}, {3, 4}});
   GMatrica<double> m2({{1, 2}, {3, 4}});
   auto m3 = m1 + m2;
   std::cout << m3 << std::endl;
   GMatrica<double> m4({{1, 2}, {3, 4}});
   auto m5 = m3-m4;
   std::cout << m5 << std::endl;
    return 0;
}
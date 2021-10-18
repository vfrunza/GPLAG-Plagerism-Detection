/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
template <typename Tip>
class GMatrica{
    Tip elementi[4][4];
    int broj_redova,broj_kolona;
    
    public:
    GMatrica();
    GMatrica(int redovi,int kolone, int vrijednost=0);
    //GMatrica(int redovi,int kolone, Tip vrijednost);
    GMatrica(int niz[4][4]);
    GMatrica(std::initializer_list<std::initializer_list<Tip>> lista);
    GMatrica(std::vector<std::vector<Tip>> vektor);
    int DajBrojRedova() const { return broj_redova; }
    int DajBrojKolona() const { return broj_kolona; }
    template <typename Tip2>
  friend   GMatrica<Tip2> operator+(const GMatrica<Tip2> &m, const GMatrica<Tip2> &n);
  template <typename Tip2>
  friend  GMatrica<Tip2> operator-(const GMatrica<Tip2> &m, const GMatrica<Tip2> &n);
  template <typename Tip2>
  friend GMatrica<Tip2> operator*(const GMatrica<Tip2> &m, int n);
  template <typename Tip2>
  friend GMatrica<Tip2> operator*(int n, const GMatrica<Tip2> &m);
  template<typename Tip2>
  friend GMatrica<Tip2> operator*(const GMatrica<Tip2> &m, const GMatrica<Tip2> &n);
  template <typename Tip2>
  friend GMatrica<Tip2> &operator+=(GMatrica<Tip2> &m, const GMatrica<Tip2> &n);
  template <typename Tip2>
  friend GMatrica<Tip2> &operator-=(GMatrica<Tip2> &m, const GMatrica<Tip2> &n);
  template <typename Tip2>
  friend GMatrica<Tip2> &operator*=(GMatrica<Tip2> &m, const GMatrica<Tip2> &n);
  template <typename Tip2>
  friend std::ostream &operator<<(std::ostream &tok,const GMatrica<Tip2> &m);
  template <typename Tip2>
  friend bool operator==(const GMatrica<Tip2> &m, const GMatrica<Tip2> &n);
  template <typename Tip2>
  friend bool operator!=(const GMatrica<Tip2> &m, const GMatrica<Tip2> &n);
  template <typename Tip2>
  friend std::istream &operator>>(std::istream &tok,GMatrica<Tip2> &m);
  template <typename Tip2>
  friend GMatrica<Tip2> &operator*=(GMatrica<Tip2> &m, int n);
};
template <typename Tip>
GMatrica<Tip>::GMatrica(){
    broj_redova=0;
    broj_kolona=0;
}
template <typename Tip>
GMatrica<Tip>::GMatrica(int redovi,int kolone,int vrijednost){
    if(redovi<0 || redovi>4 || kolone<0 || kolone > 4)
    throw std::logic_error("Ilegalan format matrice");
    for(int i=0;i<redovi;i++){
        for(int j=0;j<kolone;j++)
        elementi[i][j]=vrijednost;
    }
    broj_redova=redovi;
    broj_kolona=kolone;
}
/*template <typename Tip>
GMatrica<Tip>::GMatrica(int redovi,int kolone,Tip vrijednost){
    if(redovi<0 || redovi>4 || kolone<0 || kolone>4)
    throw std::logic_error("Ilegalan format matrice");
    for(int i=0;i<redovi;i++){
        for(int j=0;j<kolone;j++)
        elementi[i][j]=vrijednost;
        
    }
    broj_redova=redovi;
    broj_kolona=kolone;
    
}*/
template <typename Tip>
GMatrica<Tip>::GMatrica(int niz[4][4]){
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        elementi[i][j]=niz[i][j];
    }
    broj_redova=4;
    broj_kolona=4;
}

template <typename Tip>

GMatrica<Tip>::GMatrica(std::vector<std::vector<Tip>> vektor){
    if(vektor.size()<0 || vektor.size()>4 || vektor[0].size()<0 || vektor[0].size()>4)
    throw std::logic_error("Ilegalan format matrice");
    broj_redova=vektor.size();
    broj_kolona=vektor[0].size();
    for(int i=0;i<broj_redova;i++ )
    for(int j=0;j<broj_kolona;j++)
    std::copy(vektor,vektor+j,elementi);
}


template <typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Tip>> lista)
{
    int i(0),j,a;
    if(lista.size()<0 || lista.size()>4) throw std::logic_error("Ilegalan format matrice");
    for(auto x:lista)
    {if(x.size()<0 || x.size()>4) throw std::logic_error("Ilegalan format matrice");
    j=0;
    for(auto y:x)

    {elementi[i][j]=y;
        j++;
    }
        i++;
       a=x.size();
    }
    broj_redova=lista.size();
    broj_kolona=a;
}
template <typename Tip>
GMatrica<Tip> operator+(const GMatrica<Tip> &m, const GMatrica<Tip> &n){
    if(m.broj_redova!=n.broj_redova && m.broj_kolona!=n.broj_kolona)
    throw std::domain_error("Neodzovljena operacija");
    GMatrica<Tip> p(m.broj_redova,m.broj_kolona);
    for(int i=0;i<m.broj_redova;i++)
    for(int j=0;j<m.broj_kolona;j++)
        p.elementi[i][j]=m.elementi[i][j]+n.elementi[i][j];
    
    return p;
}
 
 template <typename Tip>
 GMatrica<Tip> operator-(const GMatrica<Tip> &m, const GMatrica<Tip> &n){
     if(m.broj_redova!=n.broj_redova && m.broj_kolona!=n.broj_kolona)
     throw std::domain_error("Nedozovoljena operacija");
     GMatrica<Tip> p(m.broj_redova,m.broj_kolona);
     for(int i=0;i<m.broj_redova;i++)
     for(int j=0;j<m.broj_kolona;j++)
         p.elementi[i][j]=m.elementi[i][j]-n.elementi[i][j];
     
     return p;
 }
 template <typename Tip>
 GMatrica<Tip> operator*(const GMatrica<Tip> &m, int n){
     GMatrica<Tip> k(m.broj_redova,m.broj_kolona);
     for(int i=0;i<m.broj_redova;i++){
         for(int j=0;j<m.broj_kolona;j++)
         k.elementi[i][j]=m.elementi[i][j]*n;
     }
     return k;
 }
 
 template <typename Tip>
 GMatrica<Tip> operator*(int n, const GMatrica<Tip> &m){
     GMatrica<Tip> k(m.broj_redova,m.broj_kolona);
     for(int i=0;i<m.broj_redova;i++){
         for(int j=0;j<m.broj_kolona;j++)
         k.elementi[i][j]=n*m.elementi[i][j];
     }
     return k;
 }
 
 template <typename Tip>
 GMatrica<Tip> operator*(const GMatrica<Tip> &m, const GMatrica<Tip> &n){
     if(m.broj_kolona!=n.broj_redova)
     throw std::domain_error("Nedozvoljena operacija");
     GMatrica<Tip> p(m.broj_redova,m.broj_kolona);
     for(int i=0;i<m.size();i++){
         for(int j=0;j<n[0].size();j++)
         p.elementi[i][j]+=m.elementi[i][j]*n.elementi[i][j];
     }
     return p;
 }
 
 template <typename Tip>
 GMatrica<Tip> &operator+=(GMatrica<Tip> &m, const GMatrica<Tip> &n){
     if(m.broj_redova!=n.broj_redova || m.broj_kolona!=n.broj_kolona) throw std::domain_error("Nedozvoljena operacija");
     for(int i=0;i<m.broj_redova;i++){
         for(int j=0;j<m.broj_kolona;j++)
         m.elementi[i][j]=m.elementi[i][j]+n.elementi[i][j];
     }
     return m;
 }
 
 template <typename Tip>
 GMatrica<Tip> &operator-=(GMatrica<Tip> &m, const GMatrica<Tip> &n){
     if(m.broj_redova!=n.broj_redova || m.broj_kolona!=n.broj_kolona)
     throw std::domain_error("Nedozvoljena operacija");
     for(int i=0;i<m.broj_redova;i++){
         for(int j=0;j<m.broj_kolona;j++)
         m.elementi[i][j]=m.elementi[i][j]-n.elementi[i][j];
     }
     return m;
 }
 template <typename Tip>
 GMatrica<Tip> &operator*=(GMatrica<Tip> &m, const GMatrica<Tip> &n){
     if(m.broj_kolona!=n.broj_redova)
     throw std::domain_error("Nedozvoljena operacija");
     for(int i=0;i<m.broj_redova;i++){
         for(int j=0;j<n.broj_kolona;j++)
         m.elementi[i][j]=m.elementi[i][j]+n.elementi[i][j];
     }
     return m;
 }
 
 template <typename Tip>
 std::ostream &operator<<(std::ostream &tok, const GMatrica<Tip> &m){
     for(int i=0;i<m.broj_redova;i++){
         for(int j=0;j<m.broj_kolona;j++)
         {
             tok.width(6);
             tok<<m.elementi[i][j];}
         tok<<"\n";
     }
     return tok;
 }
 
 template <typename Tip>
 bool operator ==(const GMatrica <Tip> &m, const GMatrica <Tip> &n){
     for(int i=0;i<m.broj_redova;i++){
         for(int j=0;j<m.broj_kolona;j++)
         {
             if(m.elementi[i][j]!=n.elementi[i][j]) return false;
         }
     }
     return true;
 }
 template <typename Tip>
 bool operator !=(const GMatrica<Tip> &m, const GMatrica<Tip> &n){
     for(int i=0;i<m.broj_redova;i++){
         for(int j=0;j<m.broj_kolona;j++){
             if(m.elementi[i][j]!=n.elementi[i][j]) return true;
         }
     }
     return false;
 }
 
 template <typename Tip>
 std::istream &operator>>(std::istream &tok, GMatrica<Tip> &m){
     char znak;
     tok>>znak;
     if(znak!='[') tok.setstate(std::ios::failbit);
     tok>>std::ws;
     int i(0),j(0);
     while(znak!=']')
     {
         while(znak==','){
             tok>>m.elementi[i][j];
             tok>>std::ws;
             j++;
             tok>>znak;
             tok>>std::ws;
             if(znak!=',') tok.setstate(std::ios::failbit);
             if(znak==';') break;
         }
         i++;
         tok>>znak;
         if(znak!=';') tok.setstate(std::ios::failbit);
     }
     tok>>znak;
     if(znak!=']') tok.setstate(std::ios::failbit);
     return tok;
 }
 
 template <typename Tip>
 GMatrica<Tip> &operator*=(GMatrica<Tip> &m, int n){
     for(int i=0;i<m.broj_redova;i++){
         for(int j=0;j<m.broj_kolona;j++)
         m.elementi[i][j]=m.elementi[i][j]*n;
     }
     return m;
 }
int main ()
{
    GMatrica<int> m1{{1, 2}, {3, 4}, {5, 6}};
    GMatrica<int> m2({{1,2},{3,4}});
    GMatrica<int> m4(2,2,0);
    
    
    std::cout<<m1<<std::endl;
    std::cout<<m2<<std::endl;
    auto m5=m1*2;
    std::cout<<m5<<std::endl;
	return 0;
}
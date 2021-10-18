
#include <iostream>
#include<stdexcept>
#include<vector>
#include<iomanip>
#include<initializer_list>
template <typename Tip>
class GMatrica{
    Tip mat[4][4]; 
    int brojkolona; 
    int brojredova; 
    public: 
    GMatrica(){
        brojkolona=0; 
        brojredova=0; 
    }
    GMatrica(int brojkol, int brojred, Tip element=Tip());
    template< typename Tip1>
    GMatrica(const GMatrica <Tip1>&a );
    template< typename Tip1>
    GMatrica(Tip1 niz[4][4]);
    GMatrica(const std::vector<std::vector<Tip>> &a);
    GMatrica( std::initializer_list<std::vector<Tip>> lista);
    int DajBrojRedova() const{
        return brojredova; 
    }
    int DajBrojKolona() const{
        return brojkolona; 
    }
    template<typename Tip1, typename Tip2>
    friend auto operator+(const GMatrica<Tip1> &a, const GMatrica<Tip2> &b)->GMatrica <decltype(a.mat[0][0]+b.mat[0][0])>; 
    template<typename Tip1, typename Tip2>
    friend auto operator-(const GMatrica<Tip1> &a, const GMatrica<Tip2> &b)->GMatrica<decltype(a.mat[0][0]-b.mat[0][0])>; 
    template<typename Tip1, typename Tip2>
    friend auto operator*(const GMatrica<Tip1> &a, const GMatrica<Tip2> &b)->GMatrica<decltype(a.mat[0][0]*b.mat[0][0])>; 
    template<typename Tip1, typename Tip2>
    friend auto operator*(const GMatrica<Tip1> &a, Tip2 x)->GMatrica<decltype(a.mat[0][0]*x)>; 
    template <typename Tip1, typename Tip2>
    friend auto operator*( Tip1 x, const GMatrica<Tip2> &a)->GMatrica<decltype(x*a.mat[0][0])>;
    template <typename Tip1>
    GMatrica <Tip> &operator+=(const GMatrica<Tip1> &a); 
    template <typename Tip1>
    GMatrica <Tip> &operator-=(const GMatrica<Tip1> &a);
    template <typename Tip1>
    GMatrica <Tip> &operator*=(Tip1 x);
    template <typename Tip1>
    GMatrica <Tip> &operator*=(const GMatrica<Tip1> &a); 
    template< typename Tip2>
    bool operator ==( const GMatrica<Tip2> &b);
    template< typename Tip2>
    bool operator !=( const GMatrica<Tip2> &b);
    Tip* &operator [](int broj_redova)const;
    Tip* operator [](int broj_redova);
    Tip  operator () (int a, int b) const;
    Tip  &operator () (int a, int b);
    template< typename Tip1>
    friend std::ostream &operator<<(std::ostream &tok,  GMatrica<Tip1> &a);
    template< typename Tip1>
    friend std::istream &operator>>(std::istream &tok,  GMatrica<Tip1> &a);
};
template <typename Tip>
GMatrica<Tip>::GMatrica(int brojkol, int brojred, Tip element){
        if(brojkol>4 || brojkol<0 || brojred>4 || brojkol<0) throw std::logic_error("Ilegalan format matrice");
        GMatrica::brojkolona=brojkol, GMatrica::brojredova=brojred; 
        for(int i=0; i<DajBrojRedova(); i++){
            for(int j=0; j<DajBrojKolona(); j++){
                mat[i][j]=element; 
            }
        }
    }
/*
template <typename Tip>
template< typename Tip1>
  GMatrica<Tip>::GMatrica(const GMatrica <Tip1>&a ){
        GMatrica::brojkolona=a.DajBrojKolona(); 
       GMatrica::brojredova=a.DajBrojRedova();
        for(int i=0; i<DajBrojRedova(); i++){
            for(int j=0; j<DajBrojKolona(); j++){
                mat[i][j]=a.mat[i][j]; 
            }
        }
    }
*/
template<typename Tip>
template<typename Tip1>
GMatrica<Tip>::GMatrica(const GMatrica<Tip1>&m)
{
    if(m.brojredova<0 || m.brojkolona<0 || m.brojredova>4 || m.brojkolona>4) throw std::logic_error("Ilegalan format matrica");
    GMatrica::brojkolona=m.brojkolona;
    GMatrica::broj_redova=m.brojredova;
    for(int i=0; i<brojredova; i++) {
        for(int j=0; j<brojkolona; j++) {
            mat[i][j]=m.mat[i][j];
        }
    }
}
template <typename Tip>
template< typename Tip1>
 GMatrica<Tip>::GMatrica(Tip1 niz[4][4]){
        GMatrica::brojkolona=4; GMatrica::brojredova=4; 
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                mat[i][j]=niz[i][j]; 
            }
        }
    }
    template <typename Tip>
template <typename Tip1>
    GMatrica <Tip> & GMatrica <Tip>::operator*=(Tip1 x){
        for(int i=0; i<DajBrojRedova(); i++){
            for(int j=0; j<DajBrojKolona(); j++){
                mat[i][j]*=x; 
            }
        }
        return *this; 
    }
    

template <typename Tip>

 GMatrica<Tip>::GMatrica(const std::vector<std::vector<Tip>> &a){
        if(a.size()>4 || a.size(a[0])>4) throw std::logic_error("Ilegalan format matrice"); 
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<a[i].size(); j++){
                if(a[0].size()!=a[i].size())  throw std::logic_error("Ilegalan format matrice"); 
            }
        }
        brojredova=a.size(); 
        brojkolona=a.size(a[0]); 
        for(int i=0; i<brojredova; i++){
            for(int j=0; j<brojkolona; j++){
                mat[i][j]=a[i][j]; 
            }
        }
    }

template <typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<std::vector<Tip>> lista ){
        GMatrica::brojkolona=lista.begin()->size();
    GMatrica::brojredova=lista.size();
    auto it=lista.begin();
    for(int i=0; i<lista.size(); i++) {
        int k(0);
        for(int j=0; j<lista.begin()->size(); j++) {
            mat[i][j]=(*it)[k];
            k++;
        }
        it++;
    }
    }
template <typename Tip1, typename Tip2>
auto operator + (const GMatrica<Tip1> &a, const GMatrica<Tip2> &b)->GMatrica <decltype(a.mat[0][0]+b.mat[0][0])>{
    if(a.DajBrojRedova()!=b.DajBrojRedova() || a.DajBrojKolona()!=b.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija"); 
       GMatrica<decltype(a.mat[0][0]+b.mat[0][0])>s(a.DajBrojRedova(), a.DajBrojKolona(), a.mat[0][0]+b.mat[0][0]);
        for(int i=0; i<a.DajBrojRedova(); i++){
            for(int j=0; j<a.DajBrojKolona(); j++){
                s.mat[i][j]=a.mat[i][j]+b.mat[i][j]; 
            }
        }
        return s; 
     
}
template <typename Tip1, typename Tip2>
auto operator - (const GMatrica<Tip1> &a, const GMatrica<Tip2> &b)->GMatrica <decltype(a.mat[0][0]-b.mat[0][0])>{
 if(a.DajBrojRedova()!=b.DajBrojRedova() || a.DajBrojKolona()!=b.DajBrojKolona()) throw std::domain_error("Nedozvoljena operacija"); 
       GMatrica<decltype(a.mat[0][0]-b.mat[0][0])>s(a.DajBrojRedova(), a.DajBrojKolona(), a.mat[0][0]-b.mat[0][0]);
        for(int i=0; i<a.DajBrojRedova(); i++){
            for(int j=0; j<a.DajBrojKolona(); j++){
                s.mat[i][j]=a.mat[i][j]-b.mat[i][j]; 
            }
        }
        return s; 
   
}
template <typename Tip1, typename Tip2>
auto operator * (const GMatrica<Tip1> &a, const GMatrica<Tip2> &b)->GMatrica <decltype(a.mat[0][0]*b.mat[0][0])>{
    if( a.DajBrojKolona()!=b.DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija"); 
       GMatrica<decltype(a.mat[0][0]*b.mat[0][0])>s(a.DajBrojRedova(), a.DajBrojKolona(), a.mat[0][0]*b.mat[0][0]);
        for(int i=0; i<a.DajBrojRedova(); i++){
            for(int j=0; j<b.DajBrojKolona(); j++){
                for(int k=0; k<a.DajBrojKolona(); k++)
                s.mat[i][j]=a.mat[i][k]+b.mat[k][j]; 
            }
        }
        return s; 
    
}
template <typename Tip1, typename Tip2>
auto operator*(const GMatrica<Tip1> &a, Tip2 x)->GMatrica<decltype(a.mat[0][0]*x)>{
    GMatrica<decltype(a.mat[0][0]*x)>s((a.DajBrojRedova(), a.DajBrojKolona()));
    for(int i=0; i<a.DajBrojRedova(); i++){
        for(int j=0; j<a.DajBrojKolona(); j++){
            s[i][j]=x*a[i][j]; 
        }
    }
    return s; 
}
template <typename Tip1, typename Tip2>
auto operator*( Tip1 x, const GMatrica<Tip2> &a)->GMatrica<decltype(a.mat[0][0]*x)>{
    GMatrica<decltype(a.mat[0][0]*x)>s((a.DajBrojRedova(), a.DajBrojKolona() ));
    for(int i=0; i<a.DajBrojRedova(); i++){
        for(int j=0; j<a.DajBrojKolona(); j++){
            s[i][j]=x*a[i][j]; 
        }
    }
    return s; 
}
template <typename Tip> 
template <typename Tip1>
GMatrica <Tip>& GMatrica<Tip>:: operator+=(const GMatrica<Tip1> &b){
        if(DajBrojRedova()==b.DajBrojRedova() && DajBrojKolona()==b.DajBrojKolona()){
        for(int i=0; i<DajBrojRedova(); i++){
            for(int j=0; j<DajBrojKolona(); j++){
                mat[i][j]+=b.mat[i][j]; 
            }
        }
        return *this; 
    }
    else throw std::domain_error("Nedozvoljena operacija"); 
    } 
template <typename Tip> 
template <typename Tip1>
GMatrica <Tip>& GMatrica<Tip>:: operator-=(const GMatrica<Tip1> &b){
        if(DajBrojRedova()==b.DajBrojRedova() && DajBrojKolona()==b.DajBrojKolona()){
        for(int i=0; i<DajBrojRedova(); i++){
            for(int j=0; j<DajBrojKolona(); j++){
                mat[i][j]-=b.mat[i][j]; 
            }
        }
        return *this; 
    }
    else throw std::domain_error("Nedozvoljena operacija"); 
    } 
    
template <typename Tip> 
template <typename Tip1>
GMatrica <Tip>& GMatrica<Tip>:: operator*=(const GMatrica<Tip1> &b){
    if( DajBrojKolona()==b.DajBrojRedova()){
        for(int i=0; i<DajBrojRedova(); i++){
            for(int j=0; j<b.DajBrojKolona(); j++){
                for(int k=0; k<DajBrojKolona(); k++)
                mat[i][j]*=b.mat[k][j]; 
            }
        }
        return *this; 
    }
    else throw std::domain_error("Nedozvoljena operacija"); 
}
template <typename Tip> 
 template<typename Tip2>
    bool GMatrica<Tip>:: operator ==( const GMatrica<Tip2> &b){
        if(DajBrojKolona()!=b.DajBrojKolona() || b.DajBrojRedova()!=DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija"); 
        for(int i=0; i<DajBrojRedova(); i++){
            for(int j=0; j<DajBrojKolona(); j++){
                if(mat[i][j]==b.mat[i][j]) return true; 
            }
        }
        return false; 
    }
    template <typename Tip > 
     template< typename Tip2>
    bool GMatrica<Tip>:: operator !=( const GMatrica<Tip2> &b){
        if(DajBrojKolona()!=b.DajBrojKolona() || b.DajBrojRedova()!=DajBrojRedova()) throw std::domain_error("Nedozvoljena operacija"); 
        for(int i=0; i<DajBrojRedova(); i++){
            for(int j=0; j<DajBrojKolona(); j++){
                if(mat[i][j]!=b.mat[i][j]) return true; 
            }
        }
        return false; 
    }
    template <typename Tip>
Tip*&GMatrica<Tip>::operator [](int broj_redova) const
{
    return mat[broj_redova];
}

template <typename Tip>
Tip* GMatrica<Tip>::operator [](int broj_redova)
{
    return mat[broj_redova];
}
    template<typename Tip>
    Tip GMatrica<Tip>::operator () (int a, int b)const  {
        if(a<=0 || b<=0 || (a>DajBrojRedova())|| b>DajBrojKolona()) throw std::range_error("Nedozvoljen indeks");
        return mat[a-1][b-1]; 
    }
    template<typename Tip>
    Tip &GMatrica<Tip>::operator () (int a, int b)  {
        if(a<=0 || b<=0 || (a>DajBrojRedova())|| b>DajBrojKolona()) throw std::range_error("Nedozvoljen indeks");
        return mat[a-1][b-1]; 
    }
     template< typename Tip1>
     std::ostream &operator<<(std::ostream &tok,  GMatrica<Tip1> &a){
         std::streamsize n; 
         if(tok.width()<6) n=6; 
         else n=tok.width();
         for(int i=0; i<a.DajBrojRedova(); i++){
             for(int j=0; j<a.DajBrojKolona(); j++){
                 tok<<std::setw(n)<<a.mat[i][j]; 
             }
             tok<<std::endl; 
         }
         return tok; 
     }
     template<typename Tip1>
std::istream &operator >>(std::istream &tok,  GMatrica<Tip1> &m)
{
    char znak;
    tok >> std::ws;
    tok>>znak;
    if(znak!='[') tok.setstate(std::ios::failbit);
    Tip1 x;
    int i(0), j(0);
    if(m.brojredova==0 && m.brojkolona==0) {
        for(;;) {
            tok>>x>>znak;
            m[i][j]=x;
            if(znak!=',') {
                m.brojredova++;
                i++;
                j=0;
            }
            if(znak==',') {
                j++;
                m.brojkolona++;
            }
            if(znak==']') break;
            if(znak!=',' && znak!=';' && znak!=']') tok.setstate(std::ios::failbit);

        }
    } else {
        int br(0), br2(0);
        for(;;) {
            Tip1 x;
            tok>>x>>znak;
            m.mat[i][j]=x;
            if(znak!=',') {
                br++;
                i++;
                j=0;
            }
            if(znak==',') {
                j++;
                br2++;
            }
            if(znak==']') break;
            if(br!=m.brojredova-1 && br2!=m.brojkolona-1) tok.setstate(std::ios::failbit);
            if(znak!=',' && znak!=';' && znak!=']') tok.setstate(std::ios::failbit);

        }
    }
    return tok;
}
    
    
    
    

    

int main ()
{
     GMatrica<int> m1;
   std::cin >> m1;
   std::cout << m1 << std::endl;
}
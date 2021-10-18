/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <initializer_list>

template <typename TipEl>
class GMatrica{
    TipEl mat[4][4];
    int br_kolona,br_redova;
    void Test(int br_red,int br_kol){
        
        if(br_red<0 || br_red>4 || br_kol<0 || br_kol>4)throw std::logic_error("Ilegalan format matrice");
    }
    
    public:
    GMatrica(); //konst bez parametara
    GMatrica(int br_red,int br_kol, TipEl pocv=TipEl());
     
    template <typename Tip2>
    GMatrica(const GMatrica<Tip2> &m);
   
    template <typename Tip2>
    GMatrica(Tip2 m[4][4]);
      
    GMatrica(const std::vector<std::vector<TipEl>> &v);

    GMatrica(const std::initializer_list<std::initializer_list<TipEl>> &v);
   
    int DajBrojRedova()const {return br_redova;}
    int DajBrojKolona()const {return br_kolona;}
   
    template <typename TipEl1,typename TipEl2>         //BINARNI PLUS
        friend auto operator+(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2) ->GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])>;
    
    template <typename TipEl1,typename TipEl2>         //BINARNI MINUS
        friend auto operator-(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2) ->GMatrica<decltype(m1.mat[0][0]-m2.mat[0][0])>;
        
    template <typename TipEl1,typename TipEl2>         //BINARNO MNOZENJE
        friend auto operator*(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2) ->GMatrica<decltype(m1.mat[0][0]*m2.mat[0][0])>;
        
        //+=    -=   *=   kao fje clanice 
    template <typename TipEl2>         //   +=
        GMatrica<TipEl> &operator+=(const GMatrica<TipEl2> &m2);
     
    template <typename TipEl2>         //   -=
        GMatrica<TipEl> &operator-=(const GMatrica<TipEl2> &m2);
        
    template <typename TipEl2>         //   *=
        GMatrica<TipEl> &operator*=(const GMatrica<TipEl2> &m2);
    
    //OPERATORI ==   !=
    template <typename TipEl1,typename TipEl2>         //==
        friend bool operator ==(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2); 
    
    template <typename TipEl1,typename TipEl2>         //!=
        friend bool operator !=(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2);    
    
    //OPERATORI ()  []  izvedeni kao fje clanice (POVRATNI TIP MORA BITI JEDNAK TIPU KLASE !!!!!!!!!!!!!!!!)
    TipEl &operator ()(int indeks1, int indeks2){Test(indeks1-1,indeks2-1); return mat[indeks1-1][indeks2-1];}          //ne konstantna verzija operatora ()
    TipEl operator ()(int indeks1, int indeks2)const{Test(indeks1-1,indeks2-1); return mat[indeks1-1][indeks2-1];} ;
    
    TipEl *operator [](int indeks1){return mat[indeks1];};           //ne konstantna verzija operatora []
    const TipEl *operator [](int indeks1)const {return mat[indeks1];}; //konstatna verzija!!!
    
    //operator *za mnozenje matrice skalarom
    template <typename Tip1,typename Tip2>
        friend auto operator *(GMatrica<Tip2> m,Tip1 broj)->GMatrica<decltype(broj*m.mat[0][0])>;
    
    template <typename Tip1,typename Tip2>
        friend auto operator *(Tip1 broj,GMatrica<Tip2> m)->GMatrica<decltype(broj*m.mat[0][0])>;
     
    //da li treba ovo implementirati !!!
    //operatori *= za mnozenje skalara i matrice izvedeni kao fje clanice 
    //kada mnozimo matrica * skalar tada mozemo koristit fju clanicicuž
    //kada mnozimo sklara* matrica ne moze fja clanica jer je prvi operator skalar a treba matrica
    
    template <typename TipEl2>         //   *=
    GMatrica<TipEl> &operator*=(TipEl2 broj);
    
    template <typename Tip1,typename Tip2>
    friend GMatrica<Tip1> &operator *=(Tip1 broj,GMatrica<Tip2> &m);       //DA LI TREBA OVO IMPLEMENTIRATI !!!
    
 
    
    //fja za ispis i upis
    template <typename Tip2>
    friend std::ostream &operator<< (std::ostream &tok,const GMatrica<Tip2> &v);
    
    template <typename Tip2>
    friend std::istream &operator>> (std::istream &tok, GMatrica<Tip2> &v);
    
};

template <typename TipEl>
GMatrica<TipEl>::GMatrica():br_kolona(0),br_redova(0){              //prvi konstr
    for(auto &red: mat){
        for (auto &i : red) {
            i=TipEl();
        }
    }
}

template <typename TipEl>
GMatrica<TipEl>::GMatrica(int br_red,int br_kol, TipEl pocv){   //drugi konstr

    Test(br_red,br_kol);
    for(auto &red: mat){
        for (auto &i : red) {
            i=pocv;
        }
    }
    
    br_kolona=br_kol;
    br_redova=br_red;
}

template <typename TipEl>
template <typename Tip2>                                         //treci konstr
GMatrica<TipEl>::GMatrica(Tip2 m[4][4]){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; i++) {
            mat[i][j] = m[i][j];
        }
    }
    br_kolona=4;
    br_redova=4;
}

template <typename TipEl>
GMatrica<TipEl>::GMatrica(const std::vector<std::vector<TipEl>> &v){                         //cetvrti konstruktor
    if(v.size() < 0 || v.size() >4)throw std::logic_error("Ilegalan format matrice");
    int br_kol(v.at(0).size());
    for(auto &red: v){
        if(red.size() != br_kol)throw std::logic_error("Ilegalan format matrice");
    }
    
    for(int i=0;i< v.size(); i++){
        for(int j=0;j<br_kol;j++){
            mat[i][j]=v[i][j];
        }
    }
    br_redova=v.size();
    br_kolona=br_kol;
}



template <typename TipEl>
template <typename Tip2>
GMatrica<TipEl>::GMatrica(const GMatrica<Tip2> &m){       //peti konstruktor
    br_kolona=m.br_kolona;
    br_redova=m.br_redova;
    //std::swap(mat,m); //swap ce imati nezeljeni efekat dobit cemo npr matricu double i ako je trebala biti int
    for (int i = 0; i < m.br_redova; i++) {
        for (int j = 0; j < m.br_kolona ; j++) {
            mat[i][j] = m.mat[i][j]; 
        }
    }
}

template <typename TipEl>                                                              //sesti konsturkotr
GMatrica<TipEl>::GMatrica(const std::initializer_list<std::initializer_list<TipEl>> &v){
    if(v.size() < 0 || v.size() >4)throw std::logic_error("Ilegalan format matrice");
    int br_kol(v.begin()->size());
   
    for(auto &red: v){
        if(red.size() != br_kol)throw std::logic_error("Ilegalan format matrice");
    }
    
    int i=0,j=0;
    for(auto it=v.begin(); it != v.end(); it++){
        j=0;
        for(auto it2=it->begin(); it2 != it->end(); it2++){
            mat[i][j]=*it2;
            j++;
        }
        i++;
    }
  
    br_redova=v.size();
    br_kolona=br_kol;
}

    
    

 //fja za mnozenje
template <typename TipEl1,typename TipEl2>         //BINARNO MNOZENJE
auto operator*(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2) ->GMatrica<decltype(m1.mat[0][0]*m2.mat[0][0])>{
    
    
    if(m1.br_kolona != m2.br_redova)throw std::domain_error("Nedozvoljena operacija");
    
    GMatrica<decltype(m1.mat[0][0]*m2.mat[0][0])> m3(m1.br_redova,m1.br_kolona)  ;                                      
    decltype(m1.mat[0][0]*m2.mat[0][0]) sum;
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            sum = decltype(m1.mat[0][0]*m2.mat[0][0])();
            for(int k=0;k<m1.br_kolona;k++)sum+=(m1.mat[i][k]*m2.mat[k][j]);
            m3.mat[i][j] = sum;
        }
    }
    return m3;
}


//fja za oduzimanje
template <typename TipEl1,typename TipEl2>         //BINARNO oduzimanje
auto operator-(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2) ->GMatrica<decltype(m1.mat[0][0]-m2.mat[0][0])>{
   if((m1.br_redova != m2.br_redova )||( m1.br_kolona != m2.br_kolona))throw std::domain_error("Nedozvoljena operacija");
     GMatrica<decltype(m1.mat[0][0]-m2.mat[0][0])> m3(m1.br_redova,m1.br_kolona)  ;                                          //da li hvatat izuzetak
    
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
          
            m3.mat[i][j] =m1.mat[i][j]-m2.mat[i][j] ;
        }
    }
    return m3;
 
}


//fja za sabiranje
template <typename TipEl1,typename TipEl2>         //BINARNO sabiranje
auto operator+(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2) ->GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])>{
   if((m1.br_redova != m2.br_redova )||( m1.br_kolona != m2.br_kolona))throw std::domain_error("Nedozvoljena operacija");
   
     GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])> m3(m1.br_redova,m1.br_kolona,decltype(m1.mat[0][0]+m2.mat[0][0])())  ;                                          //da li hvatat izuzetak
    
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
          
            m3.mat[i][j] =m1.mat[i][j]+m2.mat[i][j] ;
        }
    }
    
    return m3;
 
}
 
template <typename TipEl>
template <typename TipEl2>         //   +=
GMatrica<TipEl> &GMatrica<TipEl>::operator+=(const GMatrica<TipEl2> &m2){
    if((br_redova != m2.br_redova )||( br_kolona != m2.br_kolona))throw std::domain_error("Nedozvoljena operacija");
    
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++){
          
            mat[i][j] +=m2.mat[i][j] ;
        }
    }
    return *this;
}

template <typename TipEl>
template <typename TipEl2>         //   -=
GMatrica<TipEl> &GMatrica<TipEl>::operator-=(const GMatrica<TipEl2> &m2){
    if((br_redova != m2.br_redova )||( br_kolona != m2.br_kolona))throw std::domain_error("Nedozvoljena operacija");
    
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++){
          
            mat[i][j] -=m2.mat[i][j] ;
        }
    }
    return *this;
}
 
template <typename TipEl>  
template <typename TipEl2>         //   *=
GMatrica<TipEl> &GMatrica<TipEl>::operator*=(const GMatrica<TipEl2> &m2){
    if(br_kolona != m2.br_redova)throw std::domain_error("Nedozvoljena operacija");
    
    TipEl sum;
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            sum = decltype(mat[0][0]*m2.mat[0][0])();
            for(int k=0;k<br_kolona;k++)sum+=(mat[i][k]*m2.mat[k][j]);
            mat[i][j] = sum;
        }
    }
    return *this;
}


//OPERATORI ==   !=
template <typename TipEl1,typename TipEl2>         //==
bool operator ==(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2){
    if((m1.br_redova != m2.br_redova) || (m1.br_kolona != m2.br_kolona))return false;

    for (int i = 0; i < m1.br_redova; i++) {
        for (int j = 0; j < m1.br_kolona; j++) {
            if(m1.mat[i][j] != m2.mat[i][j])return false;
        }
    }
    
    return true;
}

template <typename TipEl1,typename TipEl2>         //!=
bool operator !=(const GMatrica<TipEl1> &m1,const GMatrica<TipEl2> &m2){
    return !(m1==m2);
}
        

//fja za Ispis
template <typename Tip2>
std::ostream &operator<< (std::ostream &tok, const GMatrica<Tip2> &v) {
     int sirina_ispisa=tok.width();
     if(sirina_ispisa<6)sirina_ispisa=6;
      for(int i = 0; i <v. br_redova; i++) {
         for(int j = 0; j < v.br_kolona; j++)
         std::cout << std::setw(sirina_ispisa) << v.mat[i][j];
         std::cout << std::endl;
    }
return tok;
}

template <typename Tip1,typename Tip2>
auto operator *(GMatrica<Tip2> m,Tip1 broj)->GMatrica<decltype(broj*m.mat[0][0])>{
    GMatrica<decltype(m.mat[0][0]*m.mat[0][0])> m3(m)  ;                                          //da li hvatat izuzetak
    
    for(int i=0;i<m.br_redova;i++){
        for(int j=0;j<m.br_kolona;j++){
          
            m3.mat[i][j] *=broj ;
        }
    }
    
    return m3;
}
    
template <typename Tip1,typename Tip2>
auto operator *(Tip1 broj,GMatrica<Tip2> m)->GMatrica<decltype(broj*m.mat[0][0])>{
    return m*broj;
}

template <typename TipEl>
template <typename TipEl2>         //   *=
GMatrica<TipEl> &GMatrica<TipEl>::operator*=(TipEl2 broj){
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++){
          
            mat[i][j] *=broj ;
        }
    }
    
    return *this;
}

template <typename Tip1,typename Tip2>
GMatrica<Tip2> &operator *=(Tip1 broj,GMatrica<Tip2> &m){
    
    return m*broj;
}


//fja za upis
template <typename Tip2>
std::istream &operator>> (std::istream &tok, GMatrica<Tip2> &v){
    
    tok>>std::ws;
    char znak;
    tok>>znak;
    Tip2 broj;
    bool flag(false);
    if(znak != '['){tok.setstate(std::ios::failbit); return tok;}
    
    for (int i = 0; ; i++) {
        if(flag)break;
        
        v.br_redova = i+1;
        for (int j = 0;  ;j++) {
            if(j>3){tok.setstate(std::ios::failbit);flag=true;break;}
            tok>>std::ws;
            znak = tok.peek();
            if(znak<='0' || znak>='9'){tok.setstate(std::ios::failbit);flag=true;break;}
            tok>>broj;
            if(!tok){tok.setstate(std::ios::failbit);flag=true;break;}
            v.mat[i][j] = broj;
            v.br_kolona =  j+1;
            tok>>std::ws;
            
            znak = tok.peek();
            if(znak == ','){tok.get();continue;}
            else if(znak == ';'){
                if(j<1){tok.setstate(std::ios::failbit);flag=true;break;}
                tok.get();
                break;
            }else if(znak == ']'){
                flag = true;
                break;
            }else {tok.setstate(std::ios::failbit);flag=true;break;}
        }
    }
    
    return tok;
}








int main ()
{
    GMatrica<int> v;
    std::cin>>v;
    if(!std::cin)std::cout<<"NE VALJA UNOS";
    else std::cout<<v;
    
	return 0;
}
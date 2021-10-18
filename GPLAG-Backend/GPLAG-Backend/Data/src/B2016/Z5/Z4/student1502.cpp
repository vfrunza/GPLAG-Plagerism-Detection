#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;

template <typename TipEl>
class GMatrica{
    template<typename>
    friend class GMatrica;
    int br_redova,br_kolona;
    TipEl mat[4][4];
   public:
      
    GMatrica(): br_redova(0), br_kolona(0){};
    GMatrica(int,int,TipEl el=TipEl{});
    template<typename Tip2>
     GMatrica(const GMatrica<Tip2> &mat);
    GMatrica(TipEl[4][4]);
    GMatrica(vector<vector<TipEl>>);
    GMatrica(std::initializer_list<std::initializer_list<TipEl>>);
    int DajBrojRedova() const{ return br_redova; }
    int DajBrojKolona() const{ return br_kolona; }
    //Aritmetick operatori
    template<typename Tip2>
     auto operator +=(const GMatrica<Tip2> &m2)->GMatrica<decltype(this->mat[0][0]+m2.mat[0][0])>&;
    template<typename Tip1,typename Tip2>
     friend auto operator +(const GMatrica<Tip1> &mat1, const GMatrica<Tip2> &mat2)->GMatrica<decltype(mat1.mat[0][0]+mat2.mat[0][0])>;
     
    template<typename Tip2>
     auto operator -=(const GMatrica<Tip2> &m2)->GMatrica<decltype(this->mat[0][0]-m2.mat[0][0])>&;
    template<typename Tip1,typename Tip2>
     friend auto operator -(const GMatrica<Tip1> &m1, const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.mat[0][0]-m2.mat[0][0])>;
    
    template<typename Tip2>
     GMatrica<TipEl>& operator *=(const GMatrica<Tip2> &m2);
    template<typename Tip1,typename Tip2>
     friend auto operator *(const GMatrica<Tip1> &m1,const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.mat[0][0]*m2.mat[0][0])>;
    
    template<typename Tip2>
     GMatrica<TipEl>& operator *=(Tip2 broj);
    template<typename Tip1,typename Tip2>
     friend auto operator *(Tip1 broj,const GMatrica<Tip2> &m)->GMatrica<decltype(m.mat[0][0]*broj)>;
    template<typename Tip1,typename Tip2>
     friend auto operator *(const GMatrica<Tip1> &m, Tip2 broj)->GMatrica<decltype(m.mat[0][0]*broj)>;

    //Logicki operatori
    template<typename Tip2>
     friend bool operator ==(const GMatrica<Tip2> &mat1, const GMatrica<Tip2> &mat2);
    template<typename Tip2>
     friend bool operator !=(const GMatrica<Tip2> &mat1, const GMatrica<Tip2> &mat2);
    //Operatori pristupa
    TipEl& operator ()(int prvi, int drugi);
    TipEl operator ()(int prvi, int drugi) const;
    TipEl* operator [](int indeks) { return mat[indeks]; };
    TipEl const* operator [](int indeks) const { return mat[indeks]; };
    //Operatori toka
    template<typename Tip1>
     friend std::ostream& operator <<(std::ostream& tok, const GMatrica<Tip1> &matrica);
    template<typename Tip1>
     friend std::istream& operator >>(std::istream& tok, GMatrica<Tip1> &matrica);
};

//KONSTRUKTOR SA 3 PARAMETRA
template <typename TipEl>
GMatrica<TipEl>::GMatrica (int br_redova, int br_kolona, TipEl element){
    if(br_redova<0 or br_redova>4 or br_kolona <0 or br_kolona>4) throw std::logic_error("Ilegalan format matrice");
    this->br_redova=br_redova; this->br_kolona=br_kolona;
    for(int i=0; i<br_redova; i++){
        for(int j=0; j<br_kolona; j++) mat[i][j]=element;
    }
}

//KONSTRUKTOR SA OBICNIM NIZOM
template <typename TipEl>
GMatrica<TipEl>::GMatrica(TipEl niz[4][4]): br_redova(4), br_kolona(4){
    for(int i=0; i<br_redova; i++){
        for(int j=0; j<br_kolona; j++) mat[i][j]=niz[i][j];
    }
}

//KONSTRUTOR SA MATRICOM DRUGOG TIPA
template <typename TipEl> // Default template same klase
    template <typename Tip2> //Sad unutar klase imamo template samog konstruktora
        GMatrica<TipEl>::GMatrica(const GMatrica<Tip2> &matrica): br_redova(matrica.br_redova), br_kolona(matrica.br_kolona){
            for(int i=0; i<br_redova; i++){
                for(int j=0; j<br_kolona; j++) mat[i][j]=matrica.mat[i][j];
            }
        }
//KONSTRUKTOR SA INICIJALIZACIONOM LISTOM
template<typename TipEl>
GMatrica<TipEl>::GMatrica(std::initializer_list<std::initializer_list<TipEl>> lista){
    if(lista.size()>4) throw std::logic_error("Ilegalan format matrice");
    int vel(0);
    if(lista.size()) vel=lista.begin()->size(); //broj kolona
    for(auto it=lista.begin(); it!=lista.end(); it++){
        if(it->size()!=vel) throw std::logic_error("Ilegalan format matrice");
    }
    if(lista.size() and lista.begin()->size()>4) throw std::logic_error("Ilegalan format matrice");
    br_redova=lista.size(); br_kolona=0;
    if(br_redova!=0) br_kolona=lista.begin()->size();
    int i(0);
    for(auto it=lista.begin(); it!=lista.end(); it++,i++){
        int j=0;
        for(auto it2=it->begin(); it2!=it->end(); it2++,j++) mat[i][j]=*it2;
    }
}


//KONSTRUKTOR S VEKTOROM KAO PARAMETROM
template<typename TipEl>
GMatrica<TipEl>::GMatrica(vector<vector<TipEl>> vektor){
    if(vektor.size()>4) throw std::logic_error("Ilegalan format matrice");
    for(int i=0; i<int(vektor.size()-1); i++){
        if(vektor.at(i).size() != vektor.at(i+1).size()) throw std::logic_error("Ilegalan format matrice");
    }
    if(vektor.size() and vektor.at(0).size()>4) throw std::logic_error("Ilegalan format matrice");
    br_redova=vektor.size();
    br_kolona=0;
    if(br_redova!=0) br_kolona=vektor.at(0).size();
    for(int i=0; i<br_redova; i++){
        for(int j=0; j<br_kolona; j++) mat[i][j]=vektor.at(i).at(j);
    }
}

//OPERATOR +=  SABIRANJE-DODJELA
template <typename TipEl>
    template<typename Tip2>
        auto GMatrica<TipEl>::operator +=(const GMatrica<Tip2> &m2)->GMatrica<decltype(this->mat[0][0]+m2.mat[0][0])>&{
            if(this->br_redova != m2.br_redova || this->br_kolona != m2.br_kolona)
        		throw std::domain_error("Nedozvoljena operacija");
        	for(int i = 0; i < this->br_redova; i++){
        		for(int j = 0; j < this->br_kolona; j++)
        			 this->mat[i][j]+=m2.mat[i][j];
        	}
        	return *this;
        }
  
//OPERATOR + SABIRANJE      
template<typename TipEl,typename Tip2>
    auto operator +(const GMatrica<TipEl> &m1, const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])>{
      GMatrica<decltype(m1.mat[0][0]+m2.mat[0][0])> rez(m1);
      rez+=m2;
      return rez;
    }

//OPERATOR -= ODUZIMANJE DODJELA    
template <typename TipEl>
    template<typename Tip2>
        auto GMatrica<TipEl>::operator -=(const GMatrica<Tip2> &m2)->GMatrica<decltype(this->mat[0][0]-m2.mat[0][0])>&{
            if(this->br_redova != m2.br_redova || this->br_kolona != m2.br_kolona)
        		throw std::domain_error("Nedozvoljena operacija");
        	for(int i = 0; i < this->br_redova; i++){
        		for(int j = 0; j < this->br_kolona; j++)
        			 this->mat[i][j]-=m2.mat[i][j];
        	}
        	return *this;
        }

//OPERATOR - ODUZIMANJE
template <typename TipEl, typename Tip2>
    auto operator -(const GMatrica<TipEl> &m1, const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.mat[0][0]-m2.mat[0][0])>{
      GMatrica<decltype(m1.mat[0][0]-m2.mat[0][0])> rez(m1);
      rez-=m2;
      return rez;
    }

//OPERATOR *= MATRICOM - MNOZENJE DODJELA MATRICOM
template <typename TipEl>
    template<typename Tip2>
        GMatrica<TipEl>& GMatrica<TipEl>::operator *=(const GMatrica<Tip2> &m2){
            if(this->br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
            vector<decltype(this->mat[0][0]*m2.mat[0][0])> red;// sve cemo smjestit u ovaj red
            for(int i=0; i<this->br_redova; i++){ 
                for(int j=0; j<m2.br_kolona; j++){
                    decltype(this->mat[0][0]*m2.mat[0][0]) suma{};
                    for(int k=0; k<this->br_kolona; k++)
                        suma+=this->mat[i][k]*m2.mat[k][j];
                    red.push_back(suma);
                }
                for(int k=0; k<red.size(); k++)
                    this->mat[i][k]=red.at(k);
                red.resize(0);
            }
            return *this;
        }

//OPERATOR * MNOZENJE MATRICOM 
template <typename TipEl, typename Tip2>
    auto operator *(const GMatrica<TipEl> &m1,const GMatrica<Tip2> &m2)->GMatrica<decltype(m1.mat[0][0]*m2.mat[0][0])>{
      GMatrica<decltype(m1.mat[0][0]*m2.mat[0][0])> rez(m1);
      rez*=m2;
      return rez;
    }
    
//OPERATOR *= MNOZENJE BROJEM
template <typename TipEl>
    template<typename Tip2>
        GMatrica<TipEl>& GMatrica<TipEl>::operator *=(Tip2 broj){
            for(int i = 0; i < this->br_redova; i++){
        		for(int j = 0; j < this->br_kolona; j++)
        			 this->mat[i][j]*=broj;
            }
            return *this;
        }

//OPERATOR * MNOZENJE BROJA I MATRICE
template<typename Tip1,typename Tip2>
    auto operator *(Tip1 broj,const GMatrica<Tip2> &m)->GMatrica<decltype(m.mat[0][0]*broj)>{
        GMatrica<decltype(m.mat[0][0]*broj)> rez(m);
        rez*=broj;
        return rez;
     };

//OPERATOR * MNOZENJE MATRICE I BROJA
template<typename Tip1,typename Tip2>
inline auto operator *(const GMatrica<Tip1> &m, Tip2 broj)->GMatrica<decltype(m.mat[0][0]*broj)>{
    return broj*m;
}


//OPERATOR JEDNAKOSTI ==
template <typename TipEl>
bool operator ==(const GMatrica<TipEl> &mat1, const GMatrica<TipEl> &mat2){
    if(mat1.br_redova!=mat2.br_redova or mat1.br_kolona != mat2.br_kolona) return false;
    for(int i=0; i<mat1.br_redova; i++){
        for(int j=0; j<mat1.br_kolona; j++){
            if(mat1[i][j] != mat2[i][j]) return false;
        }
    }
    return true;
}

//OPERATOR RAZLICITOSTI !=
template <typename TipEl>
bool operator !=(const GMatrica<TipEl> &mat1, const GMatrica<TipEl> &mat2){
    if(mat1.br_redova!=mat2.br_redova or mat1.br_kolona != mat2.br_kolona) return true;
    for(int i=0; i<mat1.br_redova; i++){
        for(int j=0; j<mat1.br_kolona; j++){
            if(mat1[i][j] != mat2[i][j]) return true;
        }
    }
    return false;
}


//OPERATOR INDEKSACIJE MATEMATSKE NAD NEKONSTANTNIM OBJEKTOM
template <typename TipEl>
TipEl& GMatrica<TipEl>::operator ()(int prvi, int drugi){
    if(prvi<1 or prvi>4 or drugi<1 or drugi>4) throw std::range_error("Nedozvoljen indeks");
    return mat[prvi-1][drugi-1];
}

//OPERATOR INDEKSACIJE MATEMATSKE NAD KONSTANTNIM OBJEKTOM
template <typename TipEl>
TipEl GMatrica<TipEl>::operator ()(int prvi, int drugi) const{
    if(prvi<1 or prvi>4 or drugi<1 or drugi>4) throw std::range_error("Nedozvoljen indeks");
    return mat[prvi-1][drugi-1];
}

//OPERATOR IZLAZNOG TOKA
template<typename Tip1>
std::ostream& operator <<(std::ostream& tok, const GMatrica<Tip1> &matrica){
    int sirina(cout.width());
    if(sirina<6) sirina=6;
    for(int i=0; i<matrica.br_redova; i++){
        for(int j=0; j<matrica.br_kolona; j++)
            tok<<setw(sirina)<<matrica.mat[i][j];
        tok<<endl;
    }
    return tok;
 }

//OPERATOR ULAZNOG TOKA
template<typename Tip1>
std::istream& operator >>(std::istream& tok, GMatrica<Tip1> &matricarez){
     GMatrica<Tip1> matrica;
     char znak=0;
     int kolone=0,i(0),j(0);
     bool postavljen(false);
     tok>>std::ws;
     tok>>znak;
     if(znak!='[') tok.setstate(std::ios::failbit);
     vector<Tip1> red(4);
     while(true){
         if(j>3 or i>3){
             tok.setstate(std::ios::failbit);
             break;
         }
         tok>>matrica.mat[i][j];
         tok>>znak;
         if(znak==',') {
            j++;
            continue;
         }
         else if(znak==';'){
             if(!postavljen){
                postavljen=true;
                kolone=j+1;
             }
             else if(j+1!=kolone) {
                 tok.setstate(std::ios::failbit);
                 break;
             }
             j=0;
             i++;
         }
         else if(znak==']'){
             if(postavljen and j+1!=kolone) tok.setstate(std::ios::failbit);
             matrica.br_redova=i+1;
             matrica.br_kolona=j+1;
             break;
         }
         else tok.setstate(std::ios::failbit);
     }
     if(tok) matricarez=matrica;
     return tok;
 }
   

int main ()
{
   try{
       GMatrica<int> m1;
       std::cin >> m1;
       std::cout << m1 << std::endl;
       GMatrica<double> m2(m1);
       cout<<m2.DajBrojKolona()<<" "<<m2.DajBrojRedova()<<endl;
       m2+=m1;
       m1*=2;
       GMatrica<int> m3= m2*4;
       GMatrica<int> m5 = 4*m2;
       cout<<setw(7)<<m2<<endl;
       cout<<setw(1)<<m3<<endl;
       GMatrica<double> nova{{7.1,2.1},{2.1,5.6}};
       GMatrica<double> najnovija= nova*m2;
       cout<<najnovija(2,1)<<endl;
   }
   catch(...){
       cout<<"Greska"<<endl;
   }
   return 0;
}
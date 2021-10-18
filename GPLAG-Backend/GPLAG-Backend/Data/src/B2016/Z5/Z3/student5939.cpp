/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <iomanip>

const long long int M = std::numeric_limits<long long int>::max();
const long long int m = std::numeric_limits<long long int>::min();

//provjeriti da li nzd radi za negativne brojeve
class Razlomak{
    long long int br,naz;
    static long long int NZD(long long int br1,long long int br2){
        if(br2==0)return br1;
        else{
            return NZD(br2,br1%br2);
        }
    }
    static long long int PR(long long int br1, long long int br2,char znak); //prekoracenje
    static void Izuzetak(){ throw std::overflow_error("Nemoguce dobiti tacan rezultat");};
    
    public:
    Razlomak(long long int br1,long long int br2);
    Razlomak(long long int br1){
        naz=1;
        br=br1;
    }
    Razlomak(){br=0;naz=1;}
    long long int DajBrojnik()const {return br;}
    long long int DajNazivnik()const {return naz;}
    friend Razlomak operator+(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator-(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator*(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator/(const Razlomak &r1, const Razlomak &r2);
    
    //unarni operatori
    friend Razlomak operator+(const Razlomak &r1){ return r1; }
    friend Razlomak operator-(const Razlomak &r1){
        if(r1.br/r1.naz==m)throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(r1.br==m)throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else return Razlomak(-r1.br,r1.naz); 
        
    } //STA AKO JE MIN 
    
    //binarni operatori koji vracaju referencu
    //+= -= *= /=
    friend Razlomak &operator+=(Razlomak &r1,const Razlomak &r2);
    friend Razlomak &operator-=(Razlomak &r1,const Razlomak &r2);
    friend Razlomak &operator*=(Razlomak &r1,const Razlomak &r2);
    friend Razlomak &operator/=(Razlomak &r1,const Razlomak &r2);
    
    //unarni operatori koji vracaju referencu
    friend Razlomak &operator++(Razlomak &r1);
    friend Razlomak &operator--(Razlomak &r1);
    
    //unarni operatori koji ne vracaju referencu
    friend Razlomak operator++(Razlomak &r1, int);
    friend Razlomak operator--(Razlomak &r1, int);
    
    //poredbeni operatori
    friend bool operator==(Razlomak &r1,const Razlomak &r2);
    friend bool operator!=(Razlomak &r1,const Razlomak &r2);
    friend bool operator>(Razlomak &r1,const Razlomak &r2);
    friend bool operator<(Razlomak &r1,const Razlomak &r2);
    friend bool operator>=(Razlomak &r1,const Razlomak &r2);
    friend bool operator<=(Razlomak &r1,const Razlomak &r2);
    
    //operatori za upis i ispis(UVIJEK KAO PRIJATELJESKE FJE ZBOG PRVOG PARAMETRA)
    friend std::ostream &operator <<(std::ostream &tok,const Razlomak &r1){
       tok<<r1.br; r1.naz==1 ? tok<<"" : tok<<"/"<<r1.naz;
       return tok;
    }
    friend std::istream &operator >>(std::istream &tok, Razlomak &r1);
    
    //zadnja fja za pretvorbu u long double
    operator long double () const{
        long double r((long double)br/naz);
        return r;
    }
   
};



Razlomak::Razlomak(long long int br1,long long int br2){
    if(br1==m && br2<0 || br2==m && br1<0)throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int br3(std::abs(br1));long long int br4(std::abs(br2)); //paziti ovdje sa int min !!!!!!!
    if(br4==0)throw std::logic_error("Nekorektan razlomak");   
    long long int nzd=NZD(br3,br4);   
    br3/=nzd;                                    //NZD NEGATIVAN 
    br4/=nzd;                                       //ako je u nazivniku MIN ne moze onda da se dole stavi -Min jer ne moze stati u LInt
  
    if(br1<=0 && br2<0){
        br=br3;naz=br4;
    }else if(br1<=0 && br2>0){
        br=-br3; naz=br4;
    }else if(br1>=0 && br2<0){
        br=-br3;
        naz=br4;
    }else
    br=br3;naz=br4;
}

long long int Razlomak::PR(long long int x, long long int y,char znak){
    long long int rez(0);
    bool izuzetak(false);
    
    if(znak == '+'){
        
        if(x>=0 && y>=0 && x > M -y){
            izuzetak = true;
        }else if(x<=0 && y<=0 && x<m-y){ //druge slucajeve (X<0 && y>0)ne treba jer oni ne mogu prekoraciti zbog parametara fje
            izuzetak = true;
        }else
        rez= x+y;
        
    }else if(znak == '-'){
        
        if(x>=0 && y<=0 && x >M +y){
            izuzetak = true;
        }else if(x<=0 && y>=0 && x<m+y){ //druge slucajeve (X<0 && y<0)ne treba jer oni ne mogu prekoraciti zbog parametara fje
            izuzetak = true;
        }else
        rez= x-y;
        
    }else if(znak == '*'){
        if(y>0){
            if(x < m/y || x > M/y){
                izuzetak=true;
            }else
            rez = x*y;
        }else if(y<0){
            if(x==m || -x>M/(-y) || -x<m/(-y)){
                izuzetak = true;
            }else
            rez = x*y;
        }
    }
    
    if(izuzetak)throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    else return rez;
}

Razlomak operator+(const Razlomak &r1, const Razlomak &r2){
    
    long long int r(Razlomak::NZD(r1.naz,r2.naz)) ,  s(Razlomak::NZD(r1.br,r2.naz));
    long long int brojnik,nazivnik;
    
    try{
        brojnik = Razlomak::PR(Razlomak::PR(r1.br ,r2.naz/r,'*') , Razlomak::PR(r2.br, (r1.naz/r),'*'),'+' );
        nazivnik = Razlomak::PR(r1.naz,r2.naz/r,'*');
        
    }catch(std::overflow_error e){
        throw e;
    }
    
    return Razlomak(brojnik,nazivnik);      
}

Razlomak operator-(const Razlomak &r1, const Razlomak &r2){
    try{
        return r1 + (-r2);
    }catch(std::overflow_error e){
        throw e;
    }    
}

Razlomak operator*(const Razlomak &r1, const Razlomak &r2){
    long long int s(Razlomak::NZD(r1.br,r2.naz)) ,  t(Razlomak::NZD(r2.br,r2.naz));
    long long int brojnik,nazivnik;
    
    try{
        brojnik = Razlomak::PR(r1.br/s,r2.br/t,'*');
        nazivnik = Razlomak::PR(r1.naz/t,r2.naz/s,'*');
        
    }catch(std::overflow_error e){
        throw e;
    }
    
    return Razlomak(brojnik,nazivnik); 
}

Razlomak operator/(const Razlomak &r1, const Razlomak &r2){
     
     Razlomak r3(r2.naz,r2.br);
     try{
        return r1 * (r3);
    }catch(std::overflow_error e){
        throw e;
    }  
}

inline Razlomak &operator+=(Razlomak &r1,const Razlomak &r2){
    
     try{
        return r1 = r1 + r2;
    }catch(std::overflow_error e){
        throw e;
    } 
}

inline Razlomak &operator-=(Razlomak &r1,const Razlomak &r2){
     try{
        return r1= r1-r2;
    }catch(std::overflow_error e){
        throw e;
    } 
}

inline Razlomak &operator*=(Razlomak &r1,const Razlomak &r2){
     try{
        return r1 = r1 * r2;
    }catch(std::overflow_error e){
        throw e;
    } 
}

inline Razlomak &operator/=(Razlomak &r1,const Razlomak &r2){
     try{
        return r1 = r1 / r2;
    }catch(std::overflow_error e){
        throw e;
    } 
}


Razlomak &operator++(Razlomak &r1){
    Razlomak r3(1,1);
    try{
        return r1 = r1 + r3;
    }catch(std::overflow_error e){
        throw e;
    } 
}

Razlomak &operator--(Razlomak &r1){
    Razlomak r3(1,1);
    try{
        return r1 = r1 - r3;
    }catch(std::overflow_error e){
        throw e;
    }
}

Razlomak operator++(Razlomak &r1, int){
    Razlomak pomocni(r1);
    Razlomak r3(1,1);
    try{
        r1 = r1 + r3;
        return pomocni;
    }catch(std::overflow_error e){
        throw e;
    }
}

Razlomak operator--(Razlomak &r1, int){
    Razlomak pomocni(r1);
    Razlomak r3(1,1);
    try{
        r1 = r1 - r3;
        return pomocni;
    }catch(std::overflow_error e){
        throw e;
    } 
}

bool operator==(Razlomak &r1,const Razlomak &r2){
    long double x((long double)r1.br/r1.naz) , y((long double)r2.br/r2.naz);
    return x==y;
}
bool operator!=(Razlomak &r1,const Razlomak &r2){
    return !(r1==r2);
}
bool operator>(Razlomak &r1,const Razlomak &r2){
    long double x((long double)r1.br/r1.naz) , y((long double)r2.br/r2.naz);
    return x>y;
}
bool operator<(Razlomak &r1,const Razlomak &r2){
   long double x((long double)r1.br/r1.naz) , y((long double)r2.br/r2.naz);
    return x<y;
}
bool operator>=(Razlomak &r1,const Razlomak &r2){
    long double x((long double)r1.br/r1.naz) , y((long double)r2.br/r2.naz);
    return x>=y;
}
bool operator<=(Razlomak &r1,const Razlomak &r2){
    long double x((long double)r1.br/r1.naz) , y((long double)r2.br/r2.naz);
    return x<=y;
}

std::istream &operator >>(std::istream &tok, Razlomak &r1){
    
    char znak;
    r1.naz = 1;
    tok>>std::ws;
    znak = tok.peek();
    if(znak<='0' || znak>='9')tok.setstate(std::ios::failbit);
    else{
        tok>>r1.br;
        znak = tok.peek();
        
        if(znak == ' ' || znak == tok.eof() || znak == '\n'){
            return tok;
        }
        else if(znak == '/'){
            tok.get();
            tok>>r1.naz;
            znak = tok.peek();
            if(znak != ' ' && znak != '\n' && znak != tok.eof())tok.setstate(std::ios::failbit);
            
        }else{
            tok.setstate(std::ios::failbit);
        }
    
    }
    r1 = Razlomak(r1.br,r1.naz);
    return tok;

}


int main ()
{
    try{
    Razlomak r(m,-1);
    //auto t= -r;
    std::cout<<r;
    }catch(std::exception &e){
        std::cout<<e.what();
    }
    
	return 0;
}



































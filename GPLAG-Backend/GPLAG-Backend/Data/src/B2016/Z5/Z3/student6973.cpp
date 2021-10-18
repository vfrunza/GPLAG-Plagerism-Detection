/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <limits>
#include <stdexcept>

const long long int M = std::numeric_limits<long long int>::max();
const long long int m = std::numeric_limits<long long int>::min();

class Razlomak{
    long long int _brojnik;
    long long int _nazivnik;
    
    static long long int nzd(long long int p,long long int q){
        if(q==0)
            return p;
        else 
            return nzd(q,p%q);
    }

    void PostaviRazlomak(long long int brojnik,long long int nazivnik);
    static long long int saberi(long long int x,long long int y);
    static long long int oduzmi(long long int x,long long int y);
    static long long int mnozi(long long int x,long long int y);
    
    public:
        Razlomak() : _brojnik(0), _nazivnik(1) {}
        Razlomak(long long int brojnik,long long int nazivnik);
        Razlomak(long long int brojnik) : _brojnik(brojnik), _nazivnik(1) {}
        
        Razlomak(std::initializer_list<long long int> lista);
        long long DajBrojnik() const;
        long long DajNazivnik() const;
        void PostaviBrojnik(long long int brojnik);
        void PostaviNazivnik(long long int nazivnik);
        
        operator long double() const;
        
        friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r);
        friend std::istream &operator >>(std::istream &tok, Razlomak &r);
        friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
       
        friend Razlomak operator +=(Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator -=(Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator *=(Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator /=(Razlomak &r1, const Razlomak &r2);
       
        friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
        friend bool operator !=(const Razlomak &r1, const Razlomak &r2);
        friend bool operator <(const Razlomak &r1, const Razlomak &r2);
        friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
        friend bool operator >(const Razlomak &r1, const Razlomak &r2);
        friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
        
};

long long Razlomak::DajBrojnik() const{
    return _brojnik;
}

long long Razlomak::DajNazivnik() const{
    return _nazivnik;
}

void Razlomak::PostaviBrojnik(long long int brojnik){
    _brojnik=brojnik;
}

void Razlomak::PostaviNazivnik(long long int nazivnik){
    _nazivnik=nazivnik;
}

Razlomak::operator long double() const {
    return (long double) this->DajBrojnik()/this->DajNazivnik();
}

void Razlomak::PostaviRazlomak(long long brojnik,long long nazivnik){
    _brojnik=brojnik;
    _nazivnik=nazivnik;
    auto r=nzd(_brojnik,_nazivnik);
    _brojnik /=r;
    _nazivnik /=r;
    
    if(nazivnik<0 && brojnik>0){
        _brojnik=-brojnik;
        _nazivnik=-nazivnik;
    }
    else if(nazivnik<0 && brojnik<0){
        _brojnik=-brojnik;
        _nazivnik=-nazivnik;
    }
    else if(nazivnik>0 && brojnik<0){
        _brojnik=brojnik;
        _nazivnik=nazivnik;
    }
    else if(nazivnik==0) 
    throw std::domain_error("Nazivnik jednak 0.");
}

long long Razlomak::saberi(long long x, long long y){
    if ((y>0 && x>M-y) || (y<0 && x<m-y))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return x+y;
}

long long Razlomak::oduzmi(long long x, long long y){
    return saberi(x,-y);
}

long long Razlomak::mnozi(long long x, long long y){
    if(y>0 && (x<m/y || x>M/y))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    else if(y<0 &&(x<M/y || x>m/y))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return x*y;
}

Razlomak::Razlomak(long long int brojnik, long long int nazivnik){
    PostaviRazlomak(brojnik,nazivnik);
}

Razlomak::Razlomak(std::initializer_list<long long int> lista){
    
    if(lista.size() == 1){
        long long int brojnik = *lista.begin();
        PostaviRazlomak(brojnik,1);
    }
    else if(lista.size() == 2){
        long long int brojnik = *lista.begin();
        long long int nazivnik = *(lista.begin()+1);
        PostaviRazlomak(brojnik,nazivnik);
    }
    else throw std::logic_error("Nepravilno formatirana inicijalizacijska lista.");
}

std::ostream &operator <<(std::ostream &tok, const Razlomak &r){
    if(r.DajNazivnik()==1)
        tok<<r.DajBrojnik();
    else 
    tok<<r.DajBrojnik()<<"/"<<r.DajNazivnik();
    return tok;
}

std::istream &operator >>(std::istream &tok, Razlomak &r){
    char znak(0);
    long long int brojnik(0), nazivnik(0), r1(0);
    
    tok>>std::ws;
        
        tok>>brojnik;
        
        if (tok.peek()!='\n' && tok.peek()!=-1 && tok.peek()!=' ') {
            tok>>znak;

            if (znak!='/') 
                tok.setstate(std::ios::failbit);
                
            tok>>nazivnik;
            if (tok.peek() > '9') {
                tok.setstate(std::ios::failbit);
            }
            r1 = Razlomak::nzd(brojnik, nazivnik);
            r.PostaviBrojnik(brojnik/r1);
            r.PostaviNazivnik(nazivnik/r1);
        }
        else {
            r.PostaviBrojnik(brojnik);
            r.PostaviNazivnik(1);
        
        }
    return tok;
}


Razlomak operator +(const Razlomak &r1, const Razlomak &r2){
    
    long long int r = Razlomak::nzd(r1.DajNazivnik(),r2.DajNazivnik());
    long long int brojnik(Razlomak::saberi(Razlomak::mnozi(r1.DajBrojnik(),r2.DajNazivnik()/r),
                         Razlomak::mnozi(r2.DajBrojnik(),r1.DajNazivnik()/r)));
    long long int nazivnik(Razlomak::mnozi(r1.DajNazivnik(),r2.DajNazivnik()/r));
    
    return Razlomak(brojnik,nazivnik);
}
Razlomak operator -(const Razlomak &r1, const Razlomak &r2){
    long long int r = Razlomak::nzd(r1.DajNazivnik(),r2.DajNazivnik());
    long long int brojnik(Razlomak::oduzmi(Razlomak::mnozi(r1.DajBrojnik(),r2.DajNazivnik()/r),
                         Razlomak::mnozi(r2.DajBrojnik(),r1.DajNazivnik()/r)));
    long long int nazivnik(Razlomak::mnozi(r1.DajNazivnik(),r2.DajNazivnik()/r));
    
    return Razlomak(brojnik,nazivnik);
}

Razlomak operator *(const Razlomak &r1, const Razlomak &r2){
    long long int s = Razlomak::nzd(r1.DajBrojnik(),r2.DajNazivnik());
    long long int t = Razlomak::nzd(r2.DajNazivnik(),r1.DajNazivnik());
    
    long long int brojnik(Razlomak::mnozi(r2.DajBrojnik()/s,r2.DajBrojnik()/t));
    long long int nazivnik(Razlomak::mnozi(r1.DajNazivnik()/t,r2.DajNazivnik()/s));
    
    return Razlomak(brojnik,nazivnik);
}
        
Razlomak operator /(const Razlomak &r1, const Razlomak &r2){    
    long long int r = Razlomak::nzd(r1.DajNazivnik(),r2.DajNazivnik());
    long long int u = Razlomak::nzd(r1.DajBrojnik(),r2.DajBrojnik());
    
    long long int brojnik(Razlomak::mnozi(r1.DajBrojnik()/u,r2.DajNazivnik()/r));
    long long int nazivnik(Razlomak::mnozi(r1.DajNazivnik()/r,r2.DajBrojnik()/u));
    
    return Razlomak(brojnik,nazivnik);
}
       
Razlomak operator +=(Razlomak &r1, const Razlomak &r2){
            Razlomak pomocni(r1+r2);
            r1.PostaviBrojnik(pomocni.DajBrojnik());
            r1.PostaviNazivnik(pomocni.DajNazivnik());
            return r1;
        }
        Razlomak operator -=(Razlomak &r1, const Razlomak &r2){
            Razlomak pomocni(r1-r2);
            r1.PostaviBrojnik(pomocni.DajBrojnik());
            r1.PostaviNazivnik(pomocni.DajNazivnik());
            return r1;
        }
        Razlomak operator *=(Razlomak &r1, const Razlomak &r2){
            Razlomak pomocni(r1*r2);
            r1.PostaviBrojnik(pomocni.DajBrojnik());
            r1.PostaviNazivnik(pomocni.DajNazivnik());
            return r1;
        }
        Razlomak operator /=(Razlomak &r1, const Razlomak &r2){
            Razlomak pomocni(r1/r2);
            r1.PostaviBrojnik(pomocni.DajBrojnik());
            r1.PostaviNazivnik(pomocni.DajNazivnik());
            return r1;
        }
       
    bool operator ==(const Razlomak &r1, const Razlomak &r2){
        if(r1.DajBrojnik()==r2.DajBrojnik() && r1.DajNazivnik()==r2.DajNazivnik())
            return true;
        return false;
        }
        bool operator !=(const Razlomak &r1, const Razlomak &r2){
            return !(r1 == r2);
        }
    bool operator <(const Razlomak &r1, const Razlomak &r2){
        return (long double) r1 < (long double) r2;
        }
        
    bool operator <=(const Razlomak &r1, const Razlomak &r2){
        return r1==r2 || ((long double ) r1 <(long double) r2);
        }
    
    bool operator >(const Razlomak &r1, const Razlomak &r2){
        return (long double) r1> (long double) r2;
        }
    
    bool operator >=(const Razlomak &r1, const Razlomak &r2){
        return r1==r2 || ((long double ) r1 > (long double) r2);
        }


int main ()
{
    Razlomak r, q, t;
    std::cout<<"Unesite razlomke: \n";
    std::cin >> r >> q;
    std::cout << r*q << std::endl;
    std::cout << r+q << std::endl;
    std::cout << r/q << std::endl;
    std::cout << r-q << std::endl;
    std::cout<< (r<q)<< std::endl;
    std::cout<< (r>=q)<< std::endl;
    std::cout<< (r==q)<< std::endl;
    std::cout<< (r!=q)<< std::endl;
    std::cout<< (r/=q)<< std::endl;
    
     
    
	return 0;
}
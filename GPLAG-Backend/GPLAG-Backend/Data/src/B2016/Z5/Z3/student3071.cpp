/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <iomanip>
class Razlomak{
    long long int b, n;
    static int NZD(long long int p, long long int q){
        if(q==0) return p;
        return NZD(q,p%q);
    }
    public:
    Razlomak(){
        b=0; n=1;
    }
    Razlomak(long long int brojnik, long long int nazivnik){
        if(nazivnik==0) throw std::logic_error("Nekorektan razlomak");
        if(nazivnik<0){
            brojnik=-brojnik;
            nazivnik=-nazivnik;
        }
            b=brojnik/NZD(brojnik,nazivnik);
            n=nazivnik/NZD(brojnik,nazivnik);
        
    }
    Razlomak(long long int brojnik){
        b=brojnik;
        n=1;
    }
    Razlomak(std::initializer_list<long long int> l){
        b=*l.begin();
        n=*(l.end()-1);
    }
    long long int DajNazivnik()const{return n;}
    long long int DajBrojnik()const{return b;}
    friend Razlomak operator+(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator-(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator*(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator/(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator+(const Razlomak &r){
        return r;
    }
    friend Razlomak operator-(const Razlomak &r){
        return Razlomak(-r.b,-r.n);
    }
    friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2){
        r1=r1+r2;
        return r1;
    }
    friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2){
        r1=r1-r2;
        return r1;
    }
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2){
        r1=r1*r2;
        return r1;
    }
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2){
        r1=r1/r2;
        return r1;
    }
    friend Razlomak &operator ++(Razlomak &r);
    friend Razlomak operator ++(Razlomak &r, int);
    friend Razlomak &operator --(Razlomak &r);
    friend Razlomak operator --(Razlomak &r, int);
    friend bool operator<(const Razlomak &r1, const Razlomak &r2);
    friend bool operator>(const Razlomak &r1, const Razlomak &r2);
    friend bool operator<=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator>=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator==(const Razlomak &r1, const Razlomak &r2);
    friend bool operator!=(const Razlomak &r1, const Razlomak &r2);
    friend std::ostream &operator<<(std::ostream &tok, const Razlomak &r);
    friend std::istream &operator>>(std::istream &tok, Razlomak &r);
    operator long double()const{
        long double a,b;
        a=this->b; b=this->n;
        return a/b;
    }
};
Razlomak operator +(const Razlomak &r1, const Razlomak &r2){
    Razlomak s;
    s.b=(r1.b*(r2.n/Razlomak::NZD(r1.n,r2.n))+r2.b*(r1.n/Razlomak::NZD(r1.n,r2.n)));
    s.n=(r1.n*(r2.n/Razlomak::NZD(r1.n,r2.n)));    
    return Razlomak(s.b,s.n);
}
Razlomak operator -(const Razlomak &r1, const Razlomak &r2){
    Razlomak s;
    s.b=(r1.b*(r2.n/Razlomak::NZD(r1.n,r2.n))-r2.b*(r1.n/Razlomak::NZD(r1.n,r2.n)));
    s.n=(r1.n*(r2.n/Razlomak::NZD(r1.n,r2.n)));
     return Razlomak(s.b,s.n);
}
Razlomak operator *(const Razlomak &r1, const Razlomak &r2){
    Razlomak s;
    s.b=((r1.b/Razlomak::NZD(r1.b,r2.n))*(r2.b/Razlomak::NZD(r2.b,r1.n)));
    s.n=((r1.n/Razlomak::NZD(r2.b,r1.n))*(r2.n/Razlomak::NZD(r1.b,r2.n)));
    return Razlomak(s.b,s.n);
}
Razlomak operator /(const Razlomak &r1, const Razlomak &r2){
    Razlomak s;
    s.b=((r1.b/Razlomak::NZD(r1.b,r2.b))*(r2.n/Razlomak::NZD(r1.n,r2.n)));
    s.n=((r1.n/Razlomak::NZD(r1.n,r2.n))*(r2.b/Razlomak::NZD(r1.b,r2.b)));
    return Razlomak(s.b,s.n);
}
Razlomak &operator ++(Razlomak &r){
    r+=1;
    return r;
}
Razlomak operator ++(Razlomak &r,int){
    Razlomak pom(r);
    r++;
    return pom;
}
Razlomak &operator --(Razlomak &r){
    r-=1;
    return r;
}
Razlomak operator --(Razlomak &r,int){
    Razlomak pom(r);
    r--;
    return pom;
}
std::ostream &operator<<(std::ostream &tok, const Razlomak &r){
    if(r.n==1){
        tok<<r.b; return tok;
    }else{
        Razlomak novi(r.b,r.n);
        if(novi.n==1){
            tok<<novi.b; return tok;
        }else{
        tok<<novi.b<<"/"<<novi.n;
    }}
    return tok;
}
std::istream &operator>>(std::istream &tok,Razlomak &r){
    char znak;
    tok>>std::ws;
    tok>>r.b;
    if(tok.peek()!='/'){
        r.n=1;
        return tok;
    }else{
        tok>>znak>>r.n;
    if(tok.peek()!=' ' && tok.peek()!='\n' && tok.peek()!='\t' && tok.peek()!='\r' && tok.peek()!='\v' && tok.peek()!='\f') tok.setstate(std::ios::failbit);
    auto pom=r.b;
    r.b/=Razlomak::NZD(r.b,r.n);
    r.n/=Razlomak::NZD(pom,r.n);
    return tok;
    }
}
bool operator<(const Razlomak &r1, const Razlomak &r2){
    long double a,b;
    a=r1.b/r1.n; b=r2.b/r2.n;
    return a<b;
}
bool operator>(const Razlomak &r1, const Razlomak &r2){
    long double a,b;
    a=r1.b/r1.n; b=r2.b/r2.n;
    return a>b;
}
bool operator<=(const Razlomak &r1, const Razlomak &r2){
    long double a,b;
    a=r1.b/r1.n; b=r2.b/r2.n;
    return a<=b;
}
bool operator>=(const Razlomak &r1, const Razlomak &r2){
    long double a,b;
    a=r1.b/r1.n; b=r2.b/r2.n;
    return a>=b;
}
bool operator==(const Razlomak &r1, const Razlomak &r2){
    long double a,b;
    a=r1.b/r1.n; b=r2.b/r2.n;
    return a==b;
}
bool operator!=(const Razlomak &r1, const Razlomak &r2){
    return !(r1==r2);
}

int main ()
{

	return 0;
}
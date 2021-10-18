#include <iostream>
#include <stdexcept>
class Razlomak {
    long long int brojnik,nazivnik;
    static int najmanji_zaj(long long int broj,long long int naz) {
        if(broj<0) broj=-broj;
        if(naz==0) return broj;
        broj=broj%naz;
        return najmanji_zaj(naz,broj);
    }
public:
    Razlomak(long long int brojnik,long long int nazivnik) {
        if(nazivnik==0) throw std::logic_error("Nekorektan razlomak");
        if(nazivnik<0) {
            brojnik=-brojnik;
            nazivnik=abs(nazivnik);
        }
        else if(brojnik<0 && nazivnik<0) {
            brojnik=abs(brojnik);
            nazivnik=abs(nazivnik);
        }
        int rez(najmanji_zaj(brojnik,nazivnik));
        Razlomak::brojnik=brojnik/rez;
        Razlomak::nazivnik=nazivnik/rez;
    }
    Razlomak (int n) {
        brojnik=n;
        nazivnik=1;
    }
    Razlomak() {
        brojnik=0;
        nazivnik=1;
    }
    friend Razlomak operator+ (const  Razlomak &v1, const Razlomak &v2);
    friend Razlomak operator- (const  Razlomak &v1, const Razlomak &v2);
    friend Razlomak operator* (const  Razlomak &v1, const Razlomak &v2);
    friend Razlomak operator/ (const  Razlomak &v1, const Razlomak &v2);
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &v);
    friend std::istream &operator >>(std::istream &tok,Razlomak &v);
    friend Razlomak &operator +( Razlomak &v);
    friend Razlomak &operator -( Razlomak &v);
    friend Razlomak &operator++( Razlomak &v);
    friend Razlomak &operator--( Razlomak &v);
    friend Razlomak & operator +=(Razlomak &v1, const Razlomak &v2);
    friend Razlomak & operator -=(Razlomak &v1, const Razlomak &v2);
    friend Razlomak & operator *=(Razlomak &v1, const Razlomak &v2);
    friend Razlomak & operator /=(Razlomak &v1, const Razlomak &v2);
    friend bool operator <(const Razlomak  &v1, const Razlomak &v2);
    friend bool operator >(const Razlomak  &v1, const Razlomak &v2);
    friend bool operator <=(const Razlomak  &v1, const Razlomak &v2);
    friend bool operator >=(const Razlomak  &v1, const Razlomak &v2);
    friend Razlomak operator++(Razlomak &v,int);
    friend Razlomak operator--(Razlomak &v,int);
    friend bool operator ==(const Razlomak &v1, const Razlomak &v2);
    friend bool operator !=(const Razlomak &v1, const Razlomak &v2);
    int DajBrojnik() const { return brojnik; }
    int DajNazivnik() const { return nazivnik; }
    operator long double () const;
};
Razlomak::operator long double() const {
        return (long double)brojnik/nazivnik;
    }
Razlomak operator+ (const  Razlomak &v1, const Razlomak &v2) {
    int r=Razlomak::najmanji_zaj(v1.nazivnik,v2.nazivnik);
    Razlomak a (v1.brojnik*(v2.nazivnik/r)+v2.brojnik*(v1.nazivnik/r),v1.nazivnik*(v2.nazivnik/r));
    return a;
}
Razlomak operator- (const  Razlomak &v1, const Razlomak &v2) {
    int r(Razlomak::najmanji_zaj(v1.nazivnik,v2.nazivnik));
    Razlomak a (v1.brojnik*(v2.nazivnik/r)-v2.brojnik*(v1.nazivnik/r),v1.nazivnik*(v2.nazivnik/r));
    return a;
    
}
Razlomak operator*( const Razlomak &v1, const Razlomak &v2) {
        int s=Razlomak::najmanji_zaj(v1.brojnik,v2.nazivnik);
        int t=Razlomak::najmanji_zaj(v2.brojnik,v1.nazivnik);
        Razlomak a ((v1.brojnik/s)*(v2.brojnik/t),(v1.nazivnik/t)*(v2.nazivnik/s));
        return a;
    }
Razlomak operator / ( const Razlomak &v1, const Razlomak &v2) {
        int u=Razlomak::najmanji_zaj(v1.brojnik,v2.brojnik);
        int r=Razlomak::najmanji_zaj(v1.nazivnik,v2.nazivnik);
        Razlomak a((v1.brojnik/u)*(v2.nazivnik/r),(v1.nazivnik/r)*(v2.brojnik/u));
        return a;
}
Razlomak &operator +( Razlomak &v) {
    return v;
}
Razlomak &operator -(Razlomak &v) {
    v.brojnik=-v.brojnik;
    return v;
}
std::ostream &operator <<(std::ostream &tok, const Razlomak &v) {
    if(v.nazivnik==1) return tok<<v.brojnik;
    return (tok<<v.brojnik<<"/"<<v.nazivnik);
}
std::istream &operator >>(std::istream &tok,Razlomak &v) {
    char znak;
    tok>>std::ws;
    tok>>v.brojnik;
    if(tok.peek()!='/') {
        v.nazivnik=1;
    }
    else {
        tok>>znak>>v.nazivnik;
        if(tok.peek()!=' ') tok.setstate(std::ios::failbit);
        v=Razlomak(v.brojnik,v.nazivnik);
    }
    return tok;
}
Razlomak &operator++( Razlomak &v) {
    return v+=1;
}
Razlomak operator++(Razlomak &v,int) {
    Razlomak neki(v);
    v+=1;
    return neki;
}
Razlomak &operator--(Razlomak &v) {
    return v-=1;
}
Razlomak operator--(Razlomak &v,int) {
    Razlomak neki(v);
    v-=1;
    return neki;
}
inline Razlomak &operator +=(Razlomak &v1, const Razlomak &v2) {
    v1=v1+v2;
}
inline Razlomak &operator -=(Razlomak &v1, const Razlomak &v2) {
    v1=v1-v2;
}
inline Razlomak &operator *=(Razlomak &v1, const Razlomak &v2) {
    v1=v1*v2;
}
inline Razlomak & operator /=(Razlomak &v1, const Razlomak &v2){
    v1=v1/v2;
}
bool operator <(const Razlomak  &v1, const Razlomak &v2) {
    long double jedan, drugi;
    jedan =(long double)v1.brojnik/v1.nazivnik;
    drugi=(long double)v2.brojnik/v2.nazivnik;
    if(jedan<drugi) return true;
    return false;
}
bool operator >(const Razlomak  &v1, const Razlomak &v2) {
    long double jedan, drugi;
    jedan =(long double)v1.brojnik/v1.nazivnik;
    drugi=(long double)v2.brojnik/v2.nazivnik;
    if(jedan>drugi) return true;
    return false;
}
bool operator <=(const Razlomak  &v1, const Razlomak &v2) {
    long double jedan, drugi;
    jedan =(long double)v1.brojnik/v1.nazivnik;
    drugi=(long double)v2.brojnik/v2.nazivnik;
    if(jedan<=drugi) return true;
    return false;
}
bool operator >=(const Razlomak  &v1, const Razlomak &v2) {
    long double jedan, drugi;
    jedan =(long double)v1.brojnik/v1.nazivnik;
    drugi=(long double)v2.brojnik/v2.nazivnik;
    if(jedan>=drugi) return true;
    return false;
}
bool operator ==(const Razlomak &v1, const Razlomak &v2) {
    return v1.brojnik==v2.brojnik && v1.nazivnik==v2.nazivnik;
}
bool operator !=(const Razlomak &v1, const Razlomak &v2) {
    return v1.brojnik!=v2.brojnik || v1.nazivnik==v2.nazivnik;
}
int main ()
{
    Razlomak a(5,2);
    Razlomak b(5,1);
    Razlomak d=a/b;
    std::cout<<d.DajBrojnik()<<std::endl<<d.DajNazivnik()<<std::endl;
    std::cout<<"Zbir, razlika, proizvod i kolicnik razlomaka respektivno su: "<<a+b<<", "<<a-b<<", "<<a*b<<", "<<a/b;
	return 0;
}
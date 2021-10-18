/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <climits>
#define EPS 0.00000000000000001

class Razlomak {
    long long int brojnik,nazivnik;
  //  static long long int NZD(long long int a, long long int b);
    public:
    Razlomak(long long int a, long long int b);
    Razlomak(long long int a) { brojnik=a; nazivnik=1; }
    Razlomak() { brojnik=0; nazivnik=1; }
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    friend Razlomak operator + (const Razlomak &x, const Razlomak &y);
    friend Razlomak operator - (const Razlomak &x, const Razlomak &y);
    friend Razlomak operator * (const Razlomak &x, const Razlomak &y);
    friend Razlomak operator / (const Razlomak &x, const Razlomak &y);
    friend Razlomak operator +(Razlomak x);
    friend Razlomak operator -(Razlomak x);
    friend Razlomak operator +=(Razlomak &x, const Razlomak &y);
    friend Razlomak operator -=(Razlomak &x, const Razlomak &y);
    friend Razlomak operator *=(Razlomak &x, const Razlomak &y);
    friend Razlomak operator /=(Razlomak &x, const Razlomak &y);
    friend Razlomak operator ++(Razlomak &x);
    friend Razlomak operator ++(Razlomak &x, int);
    friend Razlomak operator --(Razlomak &x);
    friend Razlomak operator --(Razlomak &x, int);
    friend bool operator <(const Razlomak &x, const Razlomak &y);
    friend bool operator >(const Razlomak &x, const Razlomak &y);
    friend bool operator <=(const Razlomak &x, const Razlomak &y);
    friend bool operator >=(const Razlomak &x, const Razlomak &y);
    friend bool operator ==(const Razlomak &x, const Razlomak &y);
    friend bool operator !=(const Razlomak &x, const Razlomak &y);
    friend std::ostream &operator <<(std::ostream &ispisi,const Razlomak &x);
    friend std::istream &operator >>(std::istream &upisi, Razlomak &x);
    operator long double() {
        long double pom=(static_cast<long double>(brojnik))/nazivnik;
        return pom;
    }
};
//NZD ZA DVA BROJA
long long int NZD (long long int a, long long int b) {
    while (b!=0) {
        long long int pom=b;
        b=a%b;
        a=pom;
    }
    return a;
}
//KONSTRUKTOR
Razlomak::Razlomak(long long int a, long long int b) {
    if (a>LONG_MAX || a<LONG_MIN || b>LONG_MAX || b<LONG_MIN) throw std::overflow_error("Nemoguce dobiti tacan rezultat");//mozda moze ovako, mada sumnjam
    if (b==0) throw std::logic_error ("Nekorektan nazivnik");
    long long int dijelj(NZD(a,b));
    if ((a<0 && b<0) || (a>0 && b<0)) {
        brojnik=(a/dijelj)*(-1);
        nazivnik=(b/dijelj)*(-1);
    }
    else {
        brojnik=a/dijelj;
        nazivnik=b/dijelj;
    }
}
//OPERATOR SABIRANJA BINARNO +
Razlomak operator + (const Razlomak &x, const Razlomak &y) {
    long long int r=NZD(x.DajNazivnik(),y.DajNazivnik());
    Razlomak zbir((x.DajBrojnik()*(y.DajNazivnik()/r)+y.DajBrojnik()*(x.DajNazivnik()/r)) , (x.DajNazivnik()*(y.DajNazivnik()/r)));
    return zbir;
}
//OPERATOR BINARNO ODUZIMANJE -
Razlomak operator - (const Razlomak &x, const Razlomak &y) {
    long long int r=NZD(x.DajNazivnik(),y.DajNazivnik());
    Razlomak razlika((x.DajBrojnik()*(y.DajNazivnik()/r)-y.DajBrojnik()*(x.DajNazivnik()/r)) , (x.DajNazivnik()*(y.DajNazivnik()/r)));
    return razlika;
}
//OPERATOR BINARNO MNOZENJE *
Razlomak operator * (const Razlomak &x,const Razlomak &y) {
    long long int s=NZD(x.DajBrojnik(),y.DajNazivnik()),t=NZD(x.DajNazivnik(),y.DajBrojnik());
    Razlomak mnozenje(((x.DajBrojnik()/s)*(y.DajBrojnik()/t)),((x.DajNazivnik()/t)*(y.DajNazivnik()/s)));
    return mnozenje;
}
//OPERATOR BINARNO DIJELJENJE /
Razlomak operator / (const Razlomak &x,const Razlomak &y) {
    long long int u=NZD(x.DajBrojnik(),y.DajBrojnik()),r=NZD(x.DajNazivnik(),y.DajNazivnik());
    Razlomak dijeljenje(((x.DajBrojnik()/u)*(y.DajNazivnik()/r)),((x.DajNazivnik()/r)*(y.DajBrojnik()/u)));
    return dijeljenje;
}
//OPERATOR UNARNI, VRACA ISTI RAZLOMAK
Razlomak operator +(Razlomak x) {
    return x;
}
//OPARATOR UNARNI, VRACA SUPROTAN PREDZNAK
Razlomak operator -(Razlomak x) {
    return {x.DajBrojnik()*(-1),x.DajNazivnik()};
}
//OPERATOR SABIRANJA, ALI +=
Razlomak operator +=(Razlomak &x, const Razlomak &y) {
    if ((y.DajBrojnik()>0 && x.DajBrojnik()>LONG_MAX-y.DajBrojnik()) || (y.DajNazivnik()>0 && x.DajNazivnik()>LONG_MAX-y.DajNazivnik()) || 
    (y.DajBrojnik()<0 && x.DajBrojnik()<LONG_MIN-y.DajBrojnik()) || (y.DajNazivnik()<0 && x.DajNazivnik()<LONG_MIN-y.DajNazivnik())) 
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
//std::cout<<"x="<<x;
    x=x+y;
//std::cout<<" Nakon x="<<x;
    return x;
}
//OPERATOR ODUZIMANJA, ALI -=
Razlomak operator -=(Razlomak &x, const Razlomak &y) {
    if ((y.DajBrojnik()>0 && x.DajBrojnik()>LONG_MAX+(-y.DajBrojnik())) || (y.DajNazivnik()>0 && x.DajNazivnik()>LONG_MAX+(-y.DajNazivnik())) || (y.DajBrojnik()<0 && x.DajBrojnik()<LONG_MIN+(-y.DajBrojnik())) || (y.DajNazivnik()<0 && x.DajNazivnik()<LONG_MIN+(-y.DajNazivnik()))) 
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    x=x-y;
    return x;
}
//OPERATOR MNOZENJA, ALI *=
Razlomak operator *=(Razlomak &x, const Razlomak &y) {
    if ((y.DajBrojnik()>0 && x.DajBrojnik()<LONG_MIN-y.DajBrojnik()) || (y.DajNazivnik()>0 && x.DajNazivnik()<LONG_MIN-y.DajNazivnik()) || (y.DajBrojnik()<0 && ( (-x.DajBrojnik()>(LONG_MAX/(-y.DajBrojnik()))) || (-x.DajBrojnik()<(LONG_MIN/(-y.DajBrojnik()))) || x.DajBrojnik()==LONG_MIN) ) || (y.DajNazivnik()<0 && ( (-x.DajNazivnik()>(LONG_MAX/(-y.DajNazivnik()))) || (-x.DajNazivnik()<(LONG_MIN/(-y.DajNazivnik()))) || x.DajNazivnik()==LONG_MIN) ) )
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    x=x*y;
    return x;
}
//OPERATOR DIJELJENJA, ALI /=
Razlomak operator /=(Razlomak &x, const Razlomak &y) {
    if ((y.DajBrojnik()>0 && (x.DajBrojnik()/y.DajBrojnik())>LONG_MAX) || (y.DajNazivnik()>0 && (x.DajNazivnik()/y.DajNazivnik())>LONG_MAX) || (y.DajBrojnik()<0 && (x.DajBrojnik()/y.DajBrojnik())<LONG_MIN) || (y.DajNazivnik()<0 && (x.DajNazivnik()/y.DajNazivnik())<LONG_MIN))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    x=x/y;
    return x;
}
//OPERATOR UNARNI ++, UVECAVA ZA 1, prefiksni
Razlomak operator ++(Razlomak &x) {
    Razlomak a(1);
    x+=a;
    return x;
}
//OPERATOR UNARNI ++, postfiksni
Razlomak operator ++(Razlomak &x, int) {
    Razlomak a(1),pom(x);
    x+=a;
    return pom;
}

//OPERATOR UNARNI --, UMANJUJE ZA 1, prefiksni
Razlomak operator --(Razlomak &x) {
    Razlomak a(1);
    x-=a;
    return x;
}
//OPERAROT UNARNI --, postfiksni
Razlomak operator --(Razlomak &x, int) {
    Razlomak a(1),pom(x);
    x-=a;
    return pom;
}

//OPERATOR POREDJENJA, NA <
bool operator <(const Razlomak &x, const Razlomak &y) {
 //   long long int r=NZD(x.DajNazivnik(),y.DajNazivnik()) ,s=NZD(x.DajBrojnik(),y.DajNazivnik());
    Razlomak a(x.DajBrojnik()),b(x.DajNazivnik()),c(y.DajBrojnik()),d(y.DajNazivnik());
    if (static_cast<long double> (a*d) < static_cast<long double> (b*c)) return true;
    return false;
}
//OPERATOR POREDJENJA, NA >
bool operator >(const Razlomak &x, const Razlomak &y) {
    Razlomak a(x.DajBrojnik()),b(x.DajNazivnik()),c(y.DajBrojnik()),d(y.DajNazivnik());
    if (static_cast<long double>(a*d) > static_cast<long double>(b*c)) return true;
    return false;
}
//OPERATOR POREDJENJA, NA <=
bool operator <=(const Razlomak &x, const Razlomak &y) {
    if (x<y || x==y) return true;
    return false;
}
//OPERATOR POREDJENJA, NA >=
bool operator >=(const Razlomak &x, const Razlomak &y) {
    if (x>y || x==y) return true;
    return false;
}
//OPERATOR POREDJENJA, NA JEDNAKOST ==
bool operator ==(const Razlomak &x, const Razlomak &y) {
    Razlomak a(x.DajBrojnik()),b(x.DajNazivnik()),c(y.DajBrojnik()),d(y.DajNazivnik());
    if (abs(static_cast<long double>(a*d)-static_cast<long double>(b*c))<EPS) return true;
    return false;
}
//OPERATOR POREDJENJA, NA RAZLICITOST !=
bool operator !=(const Razlomak &x, const Razlomak &y) {
    Razlomak a(x.DajBrojnik()),b(x.DajNazivnik()),c(y.DajBrojnik()),d(y.DajNazivnik());
    if (abs(static_cast<long double> (a*d)-static_cast<long double> (b*c))>EPS) return true;
    return false;
}
//OPERATOR ISPISI
std::ostream &operator <<(std::ostream &ispisi,const Razlomak &x) {
    if (x.DajNazivnik()==1) return ispisi<<x.DajBrojnik();
    return ispisi<<x.DajBrojnik()<<"/"<<x.DajNazivnik();
}
//OPERATOR UPISI
std::istream &operator >>(std::istream &upisi, Razlomak &x) {
    long long int a,b;
    upisi>>std::ws;
    upisi>>a;
    if (upisi.peek()!='/'){
        Razlomak pom(a);
        x=pom;
        return upisi;
    }
    char znak;
    upisi>>znak;
    if(znak!='/') {
        upisi.setstate(std::ios::failbit);
    }
    upisi>>b;
    if(upisi.peek()!='\n' && upisi.peek()!='\t' && upisi.peek()!=' ' && upisi.peek()!='r' && upisi.peek()!='v' && upisi.peek()!='f') {
        upisi.setstate(std::ios::failbit);
    }
    Razlomak pom(a,b);
    x=pom;
    return upisi;
}

int main ()
{
    Razlomak a{10,50}, b(1);
    std::cout<<a<<"+"<<b<<"="<<a+b<<std::endl;
    std::cout<<a<<"-"<<b<<"="<<a-b<<std::endl;
    std::cout<<a<<"*"<<b<<"="<<a*b<<std::endl;
    std::cout<<a<<"/"<<b<<"="<<a/b<<std::endl;
    b=a--;//<<std::endl;
    std::cout<<"a="<<a<<"b="<<b<<std::endl;
    std::cout<<"a!=b je "<<(a!=b);

}
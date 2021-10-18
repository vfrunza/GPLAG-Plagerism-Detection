#include <iostream>
#include <memory>
#include <cmath>
#include <locale>
#include <sstream>
#include <limits>
#define eps 0.0000000000000001
const long long int m=std::numeric_limits<long long int>::lowest();
const long long int M=std::numeric_limits<long long int>::max();
long long int NZD(long long int p,long long int q)
{
    long long int p1(p);
    while(q!=0) {
        p=q;
        q=fabs(p1%q);
        p1=p;
    }
    return p;
}
bool Sabiranje(long long int x,long long int y)
{
    if((y>=0 && x>M-y) || (y<0 && x<m-y)) return false;
    else return true;
}
bool Mnozenje(long long int x,long long int y)
{
    if((y<0 && (x==m || (x*-1)>M/(y*-1) || (x*-1)<m/(y*-1)))) return false;
    else return true;
}
class Razlomak
{
    long long int brojnik, nazivnik;
public:
    Razlomak(long long int b, long long int n) {
        if(n==0) throw std::logic_error ("Nekorektan razlomak");
        if(n<0) {
            b*=-1;
            n*=-1;
        }
        long long int p;
        p=NZD(b,n);
        brojnik = b/p;
        nazivnik = n/p;
    }
    Razlomak(long long int b): brojnik(b),nazivnik(1) {}
    Razlomak(): brojnik(0),nazivnik(1) {}

    operator long double() const;

    long long int DajBrojnik() const{
        return brojnik;
    }
    long long int DajNazivnik() const{
        return nazivnik;
    }
    Razlomak operator +=(const Razlomak &R2);
    Razlomak operator -=(const Razlomak &R2);
    Razlomak operator *=(const Razlomak &R2);
    Razlomak operator /=(const Razlomak &R2);
    Razlomak &operator ++();
    Razlomak operator ++(int);
    Razlomak &operator --();
    Razlomak operator --(int);
    Razlomak &operator -() {
        if(!Mnozenje(brojnik,-1))  throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        brojnik*=-1;
        return *this;
    }
    Razlomak &operator +() {
        return *this;
    }
    friend Razlomak operator +(const Razlomak &R1,const Razlomak &R2);
    friend Razlomak operator -(const Razlomak &R1,const Razlomak &R2);
    friend Razlomak operator *(const Razlomak &R1,const Razlomak &R2);
    friend Razlomak operator /(const Razlomak &R1,const Razlomak &R2);
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &R);
    friend bool operator ==(const Razlomak &R1, const Razlomak &R2);
    friend bool operator !=(const Razlomak &R1, const Razlomak &R2);
    friend bool operator >(const Razlomak &R1, const Razlomak &R2);
    friend bool operator <(const Razlomak &R1, const Razlomak &R2);
    friend bool operator >=(const Razlomak &R1, const Razlomak &R2);
    friend bool operator <=(const Razlomak &R1, const Razlomak &R2);
    friend std::istream &operator >>(std::istream &tok, const Razlomak &R);

};
Razlomak::operator long double() const
{
    long double k;
    k=double(brojnik)/nazivnik;
    return k;
}
bool operator <(const Razlomak &R1, const Razlomak &R2)
{
    long double kolicnik[2];
    kolicnik[0]=R1.brojnik/R1.nazivnik;
    kolicnik[1]=R2.brojnik/R2.nazivnik;
    if(kolicnik[0]<kolicnik[1])
        return true;
    else return false;
}
bool operator <=(const Razlomak &R1, const Razlomak &R2)
{
    long double kolicnik[2];
    kolicnik[0]=R1.brojnik/R1.nazivnik;
    kolicnik[1]=R2.brojnik/R2.nazivnik;
    if(kolicnik[0]<kolicnik[1] || fabs(kolicnik[0]-kolicnik[1])<eps)
        return true;
    else return false;
}
bool operator >(const Razlomak &R1, const Razlomak &R2)
{
    long double kolicnik[2];
    kolicnik[0]=R1.brojnik/R1.nazivnik;
    kolicnik[1]=R2.brojnik/R2.nazivnik;
    if(kolicnik[0]>kolicnik[1])
        return true;
    else return false;
}
bool operator >=(const Razlomak &R1, const Razlomak &R2)
{
    long double kolicnik[2];
    kolicnik[0]=R1.brojnik/R1.nazivnik;
    kolicnik[1]=R2.brojnik/R2.nazivnik;
    if(kolicnik[0]>kolicnik[1] || fabs(kolicnik[0]-kolicnik[1])<eps)
        return true;
    else return false;
}
bool operator ==(const Razlomak &R1, const Razlomak &R2)
{
    long double kolicnik[2];
    kolicnik[0]=R1.brojnik/R1.nazivnik;
    kolicnik[1]=R2.brojnik/R2.nazivnik;
    if(fabs(kolicnik[0]-kolicnik[1])<eps)
        return true;
    else return false;
}
bool operator !=(const Razlomak &R1, const Razlomak &R2)
{
    return !(R1==R2);
}
Razlomak &Razlomak::operator ++()
{
    *this+=1;
    *this=Razlomak(*this);
    return *this;
}
Razlomak Razlomak::operator ++(int)
{
    Razlomak pomocni(*this);
    ++(*this);
    return pomocni;
}
Razlomak &Razlomak::operator --()
{
    *this-=1;
    *this=Razlomak(*this);
    return *this;
}
Razlomak Razlomak::operator --(int)
{
    Razlomak pomocni(*this);
    --(*this);
    return pomocni;
}

Razlomak operator +(const Razlomak &R1,const Razlomak &R2)
{
    long long int broj, naz;
    long long int r=NZD(R1.nazivnik, R2.nazivnik);
    if(!Mnozenje(R1.brojnik,(R2.nazivnik/r)) || !Mnozenje(R2.brojnik,(R1.nazivnik/r)) || !Sabiranje(R1.brojnik*(R2.nazivnik/r),R2.brojnik*(R1.nazivnik/r))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    broj=R1.brojnik*(R2.nazivnik/r)+R2.brojnik*(R1.nazivnik/r);
    naz=R1.nazivnik*(R2.nazivnik/r);
    return Razlomak(broj,naz);
}
Razlomak operator -(const Razlomak &R1,const Razlomak &R2)
{
    Razlomak R3(R2.brojnik,R2.nazivnik);
    return R1+(-R3);

}
Razlomak operator *(const Razlomak &R1,const Razlomak &R2)
{
    long long int broj, naz;
    long long int s=NZD(R1.brojnik, R2.nazivnik),t=NZD(R2.brojnik,R1.nazivnik);
    if(!Mnozenje((R1.brojnik/s),(R2.brojnik/t)) || !Mnozenje(R1.nazivnik/t,(R2.nazivnik/s))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    broj=(R1.brojnik/s)*(R2.brojnik/t);
    naz=(R1.nazivnik/t)*(R2.nazivnik/s);
    return Razlomak(broj,naz);

}
Razlomak operator /(const Razlomak &R1,const Razlomak &R2)
{
    long long int broj, naz;
    long long int r=NZD(R1.nazivnik, R2.nazivnik),u=NZD(R1.brojnik,R2.brojnik);
    if(!Mnozenje((R1.brojnik/u),(R2.nazivnik/r)) || !Mnozenje((R1.nazivnik/r),(R2.brojnik/u))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    broj=(R1.brojnik/u)*(R2.nazivnik/r);
    naz=(R1.nazivnik/r)*(R2.brojnik/u);
    return Razlomak(broj,naz);
}
Razlomak Razlomak::operator +=(const Razlomak &R2)
{
    long long int broj, naz;
    long long int r=NZD(nazivnik, R2.nazivnik);
    if(!Mnozenje(brojnik,(R2.nazivnik/r)) || !Mnozenje(R2.brojnik,(nazivnik/r)) || !Sabiranje(brojnik*(R2.nazivnik/r),R2.brojnik*(nazivnik/r))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    broj=brojnik*(R2.nazivnik/r)+R2.brojnik*(nazivnik/r);
    naz=nazivnik*(R2.nazivnik/r);
    brojnik=broj;
    nazivnik=naz;
    *this=Razlomak(*this);
    return *this;
}
Razlomak Razlomak::operator -=(const Razlomak &R2)
{
        Razlomak R3(R2.brojnik,R2.nazivnik);

    *this=*this+(-R3);
    return *this;
}
Razlomak Razlomak::operator *=(const Razlomak &R2)
{
    long long int broj, naz;
    long long int s=NZD(brojnik, R2.nazivnik),t=NZD(R2.brojnik,nazivnik);
    if(!Mnozenje((brojnik/s),(R2.brojnik/t)) || !Mnozenje(nazivnik/t,(R2.nazivnik/s))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    broj=(brojnik/s)*(R2.brojnik/t);
    naz=(nazivnik/t)*(R2.nazivnik/s);
    brojnik=broj;
    nazivnik=naz;
    *this=Razlomak(*this);
    return *this;
}
Razlomak Razlomak::operator /=(const Razlomak &R2)
{
    long long int broj, naz;
    long long int r=NZD(nazivnik, R2.nazivnik),u=NZD(brojnik,R2.brojnik);
        if(!Mnozenje((brojnik/u),(R2.nazivnik/r)) || !Mnozenje((nazivnik/r),(R2.brojnik/u))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    broj=(brojnik/u)*(R2.nazivnik/r);
    naz=(nazivnik/r)*(R2.brojnik/u);
    brojnik=broj;
    nazivnik=naz;
    *this=Razlomak(*this);
    return *this;
}
std::ostream &operator <<(std::ostream &tok, const Razlomak &R)
{
    if(R.nazivnik==1) tok<<R.brojnik;
    else tok<<R.brojnik<<"/"<<R.nazivnik;
    return tok;
}
std::istream &operator >>(std::istream &tok, Razlomak &R)
{
    char razmak;
    bool ocisti(true);
    long long int broj(1),naz(1);
    tok >> std::ws;
    tok >> broj;

    if(tok.eof() || std::isspace(static_cast<unsigned char>(tok.peek()))) {
        R=Razlomak(broj);
        tok.clear();
        return tok;
    }
    tok >> razmak;
    tok >> naz;

    if(!std::isspace(static_cast<unsigned char>(tok.peek())) || razmak != '/') {
        tok.setstate(std::ios::failbit);
        ocisti = false;
    }
    //tok >> std::ws;

    R=Razlomak(broj,naz);
    if(ocisti) std::cin.clear();
    return tok;
}

int main ()
{
    Razlomak a(100, 200), b(10, 20), c(5, 50), d; 
    std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl;
    std::cout << "Zbir razlomaka a i b: " << a + b << std::endl;
    std::cout << "Razlika razlomaka a i c: " << a - c << std::endl;
    std::cout << "Proizvod razlomaka b i c: " << b * c << std::endl;
    std::cout << "Kolicnik razlomaka a i b: " << a / b << std::endl;
    std::cout << "Inkrement razlomka a: " << ++a << std::endl;
    std::cout << "Dekrement razlomka b: " << --b << std::endl;
    if(a == b) std::cout << "Razlomci a i b su jednaki." << std::endl;
    if(a != b) std::cout << "Razlomci a i b nisu jednaki." << std::endl;
    std::cout << "Unesi razlomak d = " << std::endl;
    std::cin >> d;
    std::cout << d << std::endl;
    if(d < a) std::cout << "Razlomak d je manji od razlomka a." << std::endl;
    if(d > b) std::cout << "Razlomak d je veci od razlomka b." << std::endl;
    return 0;
}

#include <iostream>
#include <stdexcept>
#include <limits>

class Razlomak {
 
    long long int brojnik, nazivnik;
    
    static long long int NZD(long long int a, long long int b) {
        if(b==0) return a;
        a=a%b;
        return NZD(b,a);
    }
    static bool Prekoracenje(long long int x, long long int y, char operacija) {
        long long int m(std::numeric_limits<long long int>::min()), M(std::numeric_limits<long long int>::max());
        if(operacija=='+') {
            if(y>0) {
                if(x>M-y) return true;
            }
            else if(x<m-y) return true;
        }
        else if(operacija=='-') {
          if(y<0) {
                if(x>M-y) return true;
            }
            else if(x<m-y) return true;  
        }
        else if(operacija=='*') {
            if(y>0) {
                if(x<m/y) return true;
            else if(x==m) return true;
            }
        }
        return false;
    }
    
    public:
    
    Razlomak(long long int b, long long int n);
    Razlomak(long long int b) { brojnik=b; nazivnik=1; }
    Razlomak() { brojnik=0; nazivnik=1; }
    
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    
    friend Razlomak operator+(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator-(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator*(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator/(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator +(const Razlomak &a) { return a; }
    friend Razlomak operator-(const Razlomak &a) {
        //Uz pretpostavnu da nazivnik nikad nece biti <0 jer konstruktor to ne dozvoljava
        if((a.brojnik<0 && a.brojnik==std::numeric_limits<long long int>::min())) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        return Razlomak(-a.brojnik, -a.nazivnik);
    }
    //Znam da je neefikasno i treba svugdje try catch blok
    friend Razlomak &operator+=(Razlomak &a, const Razlomak &b) { return a=a+b; }
    friend Razlomak &operator-=(Razlomak &a, const Razlomak &b) { return a=a-b; }
    friend Razlomak &operator*=(Razlomak &a, const Razlomak &b) { return a=a*b; }
    friend Razlomak &operator/=(Razlomak &a, const Razlomak &b) { return a=a/b; }
    friend Razlomak &operator++(Razlomak &a) { a-=1; return a; }
    friend Razlomak  operator++(Razlomak &a, int) { Razlomak pom(a); a-=1; return pom; }
    friend Razlomak &operator--(Razlomak &a) { a-=1; return a; }
    friend Razlomak  operator--(Razlomak &a, int) { Razlomak pom(a); a-=1; return pom; }
    friend bool operator==(const Razlomak &a, const Razlomak &b);
    friend bool operator!=(const Razlomak &a, const Razlomak &b) { return !(a==b); }
    friend bool operator <(const Razlomak &a, const Razlomak &b);
    friend bool operator<=(const Razlomak &a, const Razlomak &b) { if(a<b || a==b) return true; return false; }
    friend bool operator >(const Razlomak &a, const Razlomak &b) { return !(a<b); }
    friend bool operator>=(const Razlomak &a, const Razlomak &b) { if(!(a<b) || a==b) return true; return false; }
    friend std::ostream &operator<<(std::ostream &tok, const Razlomak &a);
    friend std::istream &operator>>(std::istream &tok, Razlomak &a);
    
    operator long double() const {
        long double b(DajBrojnik()), n(DajNazivnik());
        return b/n;
    }
    
};

Razlomak::Razlomak(long long int b, long long int n) {
    if(n==0) throw std::logic_error ("Nekorektan razlomak");
    long long int nzd(NZD(n,b));
    n/=nzd; b/=nzd;
    if((n<0 && b<0) || (n<0 && b>0)) {
        if((b<0 && n<0 && b==std::numeric_limits<long long int>::min()) || (n<0 && n==std::numeric_limits<long long int>::min()))
            throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        nazivnik=-n; brojnik=-b;
    }
    else {
        nazivnik=n; brojnik=b;
    }
}

std::ostream &operator<<(std::ostream &tok, const Razlomak &a) {
    if(a.nazivnik==1) tok<<a.brojnik;
    else tok<<a.brojnik<<"/"<<a.nazivnik;
    return tok;
}
std::istream &operator>>(std::istream &tok, Razlomak &a) {
    char znak;
    long long int b,n;
    tok>>std::ws;
    tok>>b;
    if(std::cin.peek()!='/') { a.brojnik=b; a.nazivnik=1; }
    else {
        tok>>znak>>n;
        a.brojnik=b; a.nazivnik=n;
        if(znak!='/' ) tok.setstate(std::ios::failbit);
    }
    return tok;
}

Razlomak operator+(const Razlomak &a, const Razlomak &b) {
    long long int n,br, r(Razlomak::NZD(a.nazivnik, b.nazivnik));
    if(Razlomak::Prekoracenje(a.brojnik,b.nazivnik/r,'*')) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    if(Razlomak::Prekoracenje(b.brojnik,a.nazivnik/r,'*')) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    if(Razlomak::Prekoracenje(a.brojnik*(b.nazivnik/r),b.brojnik*(a.nazivnik/r),'+')) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    if(Razlomak::Prekoracenje(a.nazivnik,b.nazivnik/r,'*')) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    br=a.brojnik*(b.nazivnik/r)+b.brojnik*(a.nazivnik/r);
    n=a.nazivnik*(b.nazivnik/r);
    return Razlomak(br,n);
}
Razlomak operator-(const Razlomak &a, const Razlomak &b) {
    long long int n,br, r(Razlomak::NZD(a.nazivnik, b.nazivnik));
    if(Razlomak::Prekoracenje(a.brojnik,b.nazivnik/r,'*')) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    if(Razlomak::Prekoracenje(b.brojnik,a.nazivnik/r,'*')) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    if(Razlomak::Prekoracenje(a.brojnik*(b.nazivnik/r),b.brojnik*(a.nazivnik/r),'+')) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    if(Razlomak::Prekoracenje(a.nazivnik,b.nazivnik/r,'*')) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    br=a.brojnik*(b.nazivnik/r)-b.brojnik*(a.nazivnik/r);
    n=a.nazivnik*(b.nazivnik/r);
    return Razlomak(br,n);
}
Razlomak operator *(const Razlomak &a, const Razlomak &b) {
    long long int n, br, s(Razlomak::NZD(a.brojnik, b.nazivnik)), t(Razlomak::NZD(a.nazivnik, b.brojnik));
    if(Razlomak::Prekoracenje(a.brojnik/s,b.brojnik/t,'*')) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    if(Razlomak::Prekoracenje(a.nazivnik/t,b.nazivnik/s,'*')) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    br=(a.brojnik/s)*(b.brojnik/t);
    n=(a.nazivnik/t)*(b.nazivnik/s);
    return Razlomak(br,n);
}
Razlomak operator/(const Razlomak &a, const Razlomak &b) {
    long long int n,br, u(Razlomak::NZD(a.brojnik, b.brojnik)), r(Razlomak::NZD(a.nazivnik, b.nazivnik));
    if(Razlomak::Prekoracenje(a.brojnik/u,b.nazivnik/r,'*')) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    if(Razlomak::Prekoracenje(a.nazivnik/r,b.brojnik/u,'*')) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    br=(a.brojnik/u)*(b.nazivnik/r);
    n=(a.nazivnik/r)*(b.brojnik/u);
    return Razlomak(br,n);
}

bool operator==(const Razlomak &a, const Razlomak &b) {
    long double prvi(a.brojnik/a.nazivnik), drugi(b.brojnik/b.nazivnik);
    if(prvi==drugi) return true;
    return false;
}
bool operator<(const Razlomak &a, const Razlomak &b) {
    long double prvi(a.brojnik/a.nazivnik), drugi(b.brojnik/b.nazivnik);
    if(prvi<drugi) return true;
    return false;
}

int main () {

	return 0;
}
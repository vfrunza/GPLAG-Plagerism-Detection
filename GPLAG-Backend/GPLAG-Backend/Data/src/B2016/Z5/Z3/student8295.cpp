/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <initializer_list>
#include <limits>
#include <sstream>

class Razlomak {
    long long int brojnik;
    long long int nazivnik;
    static long long int NZD(long long int a, long long int b); 
    public:
    Razlomak(long long int b, long long int n) {
        if(n==0) throw std::logic_error("Nekorektan razlomak");
        long long int najmanji = NZD(b,n);
        if(n<0) {
            b*=(-1);
            n*=(-1);
        }
        if(n<0 && b<0) {
            b*=(-1);
            n*=(-1);
        }
        brojnik = b/najmanji;
        nazivnik = n/najmanji;
    }
    Razlomak() {
        brojnik=0;
        nazivnik=1;
    }
    Razlomak(long long int b) {
        nazivnik=1;
        brojnik = b;
    }
    
    Razlomak(std::initializer_list<long long int> l) {
        if(l.size() == 2) {
        long long int b, n;
        auto i(l.begin());
        b=*i;
        i++;
        n=*i;
        if(n==0) throw std::logic_error("Nekorektan razlomak");
        long long int najmanji = NZD(b,n);
        if(n<0) {
            b*=(-1);
            n*=(-1);
        }
        if(n<0 && b<0) {
            b*=(-1);
            n*=(-1);
        }
        brojnik = b/najmanji;
        nazivnik = n/najmanji;
        }
        else if(l.size() == 1) {
            auto i(l.begin());
            nazivnik=1;
            brojnik = *i;
        }
    }
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    
    friend Razlomak operator +(const Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak operator -(const Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak operator *(const Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak operator /(const Razlomak &prvi, const Razlomak &drugi);
    
    friend Razlomak operator +(const Razlomak &prvi) { return prvi;}
    friend Razlomak operator -(Razlomak &prvi) { prvi.brojnik*=(-1); return prvi; }
    
    friend Razlomak &operator +=(Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak &operator -=(Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak &operator *=(Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak &operator /=(Razlomak &prvi, const Razlomak &drugi);
    
    friend bool operator <(const Razlomak &prvi, const Razlomak &drugi);
    friend bool operator >(const Razlomak &prvi, const Razlomak &drugi);
    friend bool operator <=(const Razlomak &prvi, const Razlomak &drugi);
    friend bool operator >=(const Razlomak &prvi, const Razlomak &drugi);
    friend bool operator ==(const Razlomak &prvi, const Razlomak &drugi);
    friend bool operator !=(const Razlomak &prvi, const Razlomak &drugi);
    
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r);
    friend std::istream &operator >>(std::istream &tok, Razlomak &r);
    
    friend Razlomak &operator ++(Razlomak &r);
    friend Razlomak &operator --(Razlomak &r);
    friend Razlomak operator ++(Razlomak &r, int);
    friend Razlomak operator --(Razlomak &r, int);
    
};
long long int Razlomak::NZD(long long int a, long long int b) {
    long long int p, q;
    if(a>b) {
        p=std::abs(a); q=std::abs(b);
    }
    if(b>a) {
        p=std::abs(b); q=std::abs(a);
    }
    while (q!=0) {
        while (p>=q) {
            p-=q;
            if(p==0) return q;
        }
        long long int temp = p;
        p=q;
        q=temp;
    }
    return 1;
}
Razlomak &operator ++(Razlomak &r) {
    Razlomak r2(1);
    r+=r2;
    return r;
}
Razlomak &operator --(Razlomak &r) {
    Razlomak r2(1);
    r-=r2;
    return r;
}
Razlomak operator ++(Razlomak &r, int) {
    Razlomak pom(r);
    Razlomak r2(1);
    r+=r2;
    return pom;
}

Razlomak operator --(Razlomak &r, int) {
    Razlomak pom(r);
    Razlomak r2(1);
    r-=r2;
    return pom;
}
std::ostream &operator <<(std::ostream &tok, const Razlomak &r) {
    if(r.nazivnik == 1) tok << r.brojnik;
    else tok << r.brojnik << "/" << r.nazivnik;
    return tok;
}

std::istream &operator >>(std::istream &tok, Razlomak &r) {
    std::string s;
    tok>>s;
    long long int nazivn=0,brojn=0; 
    for(int i(0); i<s.length(); i++) {
        while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\r' || s[i] == '\f' || s[i] == '\v') {
            i++;
        }
        if(s[i]<'0' && s[i]>'9') tok.setstate(std::ios::failbit);
        if(s[i]>='0' && s[i]<='9') {
            int brojcifara = 0;
            int k=i;
            while (s[k]>='0' && s[k]<='9') {
                brojcifara++; 
                k++;
            }
            int multiplikator = std::pow(10,brojcifara-1);
            while(s[i]>='0' && s[i]<='9') {
                brojn += multiplikator*(s[i] - '0');
                multiplikator/=10;
                i++;
            }
            if(s[i]=='/') {
                i++;
                if(s[i]>='0' && s[i]<='9') {
                
                    int brojcifara1 = 0;
                    int d=i;
                    while (s[d]>='0' && s[d]<='9') {
                            brojcifara1++; 
                            d++;
                    }
                    //std::cout << brojcifara1<<"=";
                    int multiplikator1 = std::pow(10,brojcifara1-1);
                    //std::cout << multiplikator1<<"*";
                    while(s[i]>='0' && s[i]<='9') {
                    nazivn += multiplikator1*(s[i] - '0');
                    multiplikator1/=10;
                    i++;
                    //std::cout <<nazivn;
                    }
                    long long int skr=Razlomak::NZD(brojn,nazivn);
                    brojn/=skr;
                    nazivn/=skr;
                    //std::cout <<brojn;
                    //std::cout <<nazivn;
                    
                    r.brojnik=brojn;
                    r.nazivnik=nazivn;
                    
                    if(!(s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\r' || s[i] == '\f' || s[i] == '\v')) tok.setstate(std::ios::failbit);
                }
                if(s[i]<'0' && s[i]>'9') tok.setstate(std::ios::failbit);
            }
            if(s[i]!='/') {
                if(i==s.length() || s[i+1] == ' ' || s[i+1] == '\n' || s[i+1] == '\t' || s[i+1] == '\r' || s[i+1] == '\f' || s[i+1] == '\v') {
                    long long int n=1;
                    r.brojnik=brojn;
                    r.nazivnik=n;
                }
                else tok.setstate(std::ios::failbit);
            }
        }
        
    }
    return tok;
}

Razlomak operator +(const Razlomak &prvi, const Razlomak &drugi) {
    long long int m = std::numeric_limits<long long int>::min();
    long long int M = std::numeric_limits<long long int>::max();
    Razlomak rez;
    long long int x,y;
    x=prvi.brojnik*(drugi.nazivnik / Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    y=drugi.brojnik*(prvi.nazivnik/Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    if(y>=0) {
        if(x>M-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(y<0) {
        if(x<m-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    rez.brojnik = prvi.brojnik*(drugi.nazivnik / Razlomak::NZD(prvi.nazivnik, drugi.nazivnik)) + drugi.brojnik*(prvi.nazivnik/Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    rez.nazivnik = prvi.nazivnik * (drugi.nazivnik /Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    long long int skratiti = Razlomak::NZD(rez.brojnik, rez.nazivnik);
    rez.brojnik /=skratiti;
    rez.nazivnik/=skratiti;
    return rez;
}

Razlomak &operator +=(Razlomak &prvi, const Razlomak &drugi) {
    long long int m = std::numeric_limits<long long int>::min();
    long long int M = std::numeric_limits<long long int>::max();
    Razlomak rez;
    long long int x,y;
    x=prvi.brojnik*(drugi.nazivnik / Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    y=drugi.brojnik*(prvi.nazivnik/Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    if(y>=0) {
        if(x>M-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(y<0) {
        if(x<m-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    rez.brojnik = prvi.brojnik*(drugi.nazivnik / Razlomak::NZD(prvi.nazivnik, drugi.nazivnik)) + drugi.brojnik*(prvi.nazivnik/Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    rez.nazivnik = prvi.nazivnik * (drugi.nazivnik /Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    long long int skratiti = Razlomak::NZD(rez.brojnik, rez.nazivnik);
    rez.brojnik /=skratiti;
    rez.nazivnik/=skratiti;
    prvi.brojnik=rez.brojnik; prvi.nazivnik=rez.nazivnik;
    return prvi;
}

Razlomak operator -(const Razlomak &prvi, const Razlomak &drugi) {
    long long int m = std::numeric_limits<long long int>::min();
    long long int M = std::numeric_limits<long long int>::max();
    Razlomak rez;
    long long int x,y;
    x=prvi.brojnik*(drugi.nazivnik / Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    y=drugi.brojnik*(prvi.nazivnik/Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    if(y>=0) {
        if(x<m-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(y<0) {
        if(x>M-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    rez.brojnik = prvi.brojnik*(drugi.nazivnik / Razlomak::NZD(prvi.nazivnik, drugi.nazivnik)) - drugi.brojnik*(prvi.nazivnik/Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    rez.nazivnik = prvi.nazivnik * (drugi.nazivnik /Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    long long int skratiti = Razlomak::NZD(rez.brojnik, rez.nazivnik);
    rez.brojnik /=skratiti;
    rez.nazivnik/=skratiti;
    return rez;
}

Razlomak &operator -=(Razlomak &prvi, const Razlomak &drugi) {
    long long int m = std::numeric_limits<long long int>::min();
    long long int M = std::numeric_limits<long long int>::max();
    Razlomak rez;
    long long int x,y;
    x=prvi.brojnik*(drugi.nazivnik / Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    y=drugi.brojnik*(prvi.nazivnik/Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    if(y>=0) {
        if(x<m-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(y<0) {
        if(x>M-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    rez.brojnik = prvi.brojnik*(drugi.nazivnik / Razlomak::NZD(prvi.nazivnik, drugi.nazivnik)) - drugi.brojnik*(prvi.nazivnik/Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    rez.nazivnik = prvi.nazivnik * (drugi.nazivnik /Razlomak::NZD(prvi.nazivnik, drugi.nazivnik));
    long long int skratiti = Razlomak::NZD(rez.brojnik, rez.nazivnik);
    rez.brojnik /=skratiti;
    rez.nazivnik/=skratiti;
    prvi.brojnik=rez.brojnik; prvi.nazivnik=rez.nazivnik;
    return prvi;
}

Razlomak operator *(const Razlomak &prvi, const Razlomak &drugi) {
    long long int m = std::numeric_limits<long long int>::min();
    long long int M = std::numeric_limits<long long int>::max();
    Razlomak rez;
    long long int x,y;
    x=(prvi.brojnik/Razlomak::NZD(prvi.brojnik, drugi.nazivnik));
    y=(drugi.brojnik/Razlomak::NZD(drugi.brojnik,prvi.nazivnik));
    if(y>=0) {
        if(x<m/y || x>M/y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(y<0) {
        if(x==m || x*(-1)>M/(y*(-1)) || x*(-1)<m/(y*(-1))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    rez.brojnik = (prvi.brojnik/Razlomak::NZD(prvi.brojnik, drugi.nazivnik))*(drugi.brojnik/Razlomak::NZD(drugi.brojnik,prvi.nazivnik));
    rez.nazivnik = (prvi.nazivnik/Razlomak::NZD(drugi.brojnik,prvi.nazivnik))*(drugi.nazivnik/Razlomak::NZD(prvi.brojnik, drugi.nazivnik));
    long long int skratiti = Razlomak::NZD(rez.brojnik, rez.nazivnik);
    rez.brojnik /=skratiti;
    rez.nazivnik/=skratiti;
    return rez;
}

Razlomak &operator *=(Razlomak &prvi, const Razlomak &drugi) {
    long long int m = std::numeric_limits<long long int>::min();
    long long int M = std::numeric_limits<long long int>::max();
    Razlomak rez;
    long long int x,y;
    x=(prvi.brojnik/Razlomak::NZD(prvi.brojnik, drugi.nazivnik));
    y=(drugi.brojnik/Razlomak::NZD(drugi.brojnik,prvi.nazivnik));
    if(y>=0) {
        if(x<m/y || x>M/y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(y<0) {
        if(x==m || x*(-1)>M/(y*(-1)) || x*(-1)<m/(y*(-1))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    rez.brojnik = (prvi.brojnik/Razlomak::NZD(prvi.brojnik, drugi.nazivnik))*(drugi.brojnik/Razlomak::NZD(drugi.brojnik,prvi.nazivnik));
    rez.nazivnik = (prvi.nazivnik/Razlomak::NZD(drugi.brojnik,prvi.nazivnik))*(drugi.nazivnik/Razlomak::NZD(prvi.brojnik, drugi.nazivnik));
    long long int skratiti = Razlomak::NZD(rez.brojnik, rez.nazivnik);
    rez.brojnik /=skratiti;
    rez.nazivnik/=skratiti;
    prvi.brojnik=rez.brojnik; prvi.nazivnik=rez.nazivnik;
    return prvi;
}

Razlomak operator /(const Razlomak &prvi, const Razlomak &drugi) {
    Razlomak rez;
    rez.brojnik = (prvi.brojnik/Razlomak::NZD(prvi.brojnik, drugi.brojnik))*(drugi.nazivnik/Razlomak::NZD(drugi.nazivnik,prvi.nazivnik));
    rez.nazivnik = (prvi.nazivnik/Razlomak::NZD(drugi.nazivnik,prvi.nazivnik))*(drugi.brojnik/Razlomak::NZD(prvi.brojnik, drugi.brojnik));
    long long int skratiti = Razlomak::NZD(rez.brojnik, rez.nazivnik);
    rez.brojnik /=skratiti;
    rez.nazivnik/=skratiti;
    return rez;
}

Razlomak &operator /=(Razlomak &prvi, const Razlomak &drugi) {
    Razlomak rez;
    rez.brojnik = (prvi.brojnik/Razlomak::NZD(prvi.brojnik, drugi.brojnik))*(drugi.nazivnik/Razlomak::NZD(drugi.nazivnik,prvi.nazivnik));
    rez.nazivnik = (prvi.nazivnik/Razlomak::NZD(drugi.nazivnik,prvi.nazivnik))*(drugi.brojnik/Razlomak::NZD(prvi.brojnik, drugi.brojnik));
    long long int skratiti = Razlomak::NZD(rez.brojnik, rez.nazivnik);
    rez.brojnik /=skratiti;
    rez.nazivnik/=skratiti;
    prvi.brojnik=rez.brojnik; prvi.nazivnik=rez.nazivnik;
    return prvi;
}

bool operator <(const Razlomak &prvi, const Razlomak &drugi) {
    long double a,b;
    a = prvi.brojnik/prvi.nazivnik;
    b = drugi.brojnik/drugi.nazivnik;
    if(a<b) return true;
    return false;
}

bool operator >(const Razlomak &prvi, const Razlomak &drugi) {
    long double a,b;
    a = prvi.brojnik/prvi.nazivnik;
    b = drugi.brojnik/drugi.nazivnik;
    if(a>b) return true;
    return false;
}
bool operator <=(const Razlomak &prvi, const Razlomak &drugi) {
    long double a,b;
    a = prvi.brojnik/prvi.nazivnik;
    b = drugi.brojnik/drugi.nazivnik;
    if(a<=b) return true;
    return false;
}

bool operator >=(const Razlomak &prvi, const Razlomak &drugi) {
    long double a,b;
    a = prvi.brojnik/prvi.nazivnik;
    b = drugi.brojnik/drugi.nazivnik;
    if(a>=b) return true;
    return false;
}
bool operator ==(const Razlomak &prvi, const Razlomak &drugi) {
    long double a,b;
    a = prvi.brojnik/prvi.nazivnik;
    b = drugi.brojnik/drugi.nazivnik;
    if(a==b) return true;
    return false;
}

bool operator !=(const Razlomak &prvi, const Razlomak &drugi) {
    long double a,b;
    a = prvi.brojnik/prvi.nazivnik;
    b = drugi.brojnik/drugi.nazivnik;
    if(a!=b) return true;
    return false;
}

int main ()
{
	return 0;
}
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;


//maksimalni I MIN ZA LONG DOUBLE
long long int constexpr maksimalni (std::numeric_limits<long long int>::max());
long long int constexpr minimalni (std::numeric_limits<long long int>::min());
long double constexpr EPS = 0.000000000000000001;

class Razlomak{
    long long int brojnik,nazivnik;
    static long long int NZD(long long int p, long long int q);
   public:
    //KONSTRUKTORI 
    Razlomak(long long int brojnik=0, long long int nazivnik=1);
    
    //PRISTUPNE METODE
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    
    //ARITMETICKE OPERACIJE  - BINARNE
    Razlomak operator +=(const Razlomak &r2);
    Razlomak operator -=(const Razlomak &r2);
    Razlomak operator *=(const Razlomak &r2);
    Razlomak operator /=(const Razlomak &r2);
    friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2); 
    friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
    
    //ARITMETICKE OPERACIJE  - UNARNE
    friend Razlomak operator +(Razlomak &r1) { return r1; }
    friend Razlomak operator -(Razlomak &r1);
    
    //INKREMENTACIJE 
    friend Razlomak& operator ++(Razlomak &r1); //prefiksni
    friend Razlomak operator ++(Razlomak &r1, int); //postfiksni
    friend Razlomak& operator --(Razlomak &r1); //prefiksni
    friend Razlomak operator --(Razlomak &r1, int); //postfiksni
    
    //LOGICKE OPERACIJE
    friend bool operator <(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
    
    //OPERACIJE SA TOKOVIMA
    friend std::ostream& operator <<(std::ostream& tok, const Razlomak &r1);
    friend std::istream& operator >>(std::istream& tok,Razlomak &r1);
    
    //KONVERZIJA U LONG DOUBLE
    operator long double() const;
    
     
};

//NAJMANJI ZAJEDNICKI DJELILAC
long long Razlomak::NZD(long long int p, long long int q){
    q=abs(q);  
    p=abs(p);
    if(p==q) return p;
    auto p1(p),q1(q);
    while(q!=0){
        auto temp = q;
        q=p%q;
        p=temp;
    }
    if(p<p1 or p<q1) // mora biti manji barem od jednog, ako nije, onda nema zajednickog sadrzaoca
        return p;
    return 1;
}
//KONSTRUKTOR
Razlomak::Razlomak(long long int brojnik, long long int nazivnik){
    if(nazivnik<0){
        nazivnik*=-1;
        brojnik*=-1;
    }
    int nzd = NZD(brojnik,nazivnik);
    brojnik/=nzd;
    nazivnik/=nzd;
    Razlomak::brojnik=brojnik;
    Razlomak::nazivnik=nazivnik;
}

//PROVJERE PREKORACENJA
bool PrekoracenjeMnozenja(long long int x, long long int y){
    if(y>0 and (x<minimalni/y or x>maksimalni/y)) return true;
    if(y<0 and (x==minimalni or -x>maksimalni/-y or -x<minimalni/-y)) return true;
    return false;
}

bool PrekoracenjeSabiranja(long long int x, long long int y){
    if(y>0 and x>maksimalni-y) return true;
    if(y<0 and x<minimalni+y) return true;
    return false;
}

bool PrekoracenjeOduzimanja(long long int x, long long int y){
    if(y>0 and x<minimalni+y) return true;
    if(y<0 and x>maksimalni+y) return true;
    return false;
}

//SABIRANJE RAZLOMAKA += DODJELA
Razlomak Razlomak::operator +=(const Razlomak &r2){
    long long int p1(this->brojnik),p2(r2.DajBrojnik()),q1(this->nazivnik),q2(r2.DajNazivnik()); //operandi
    long long int r(NZD(q1,q2)),x1(q2/r),x2(q1/r);
    if(PrekoracenjeMnozenja(p1,x1) or PrekoracenjeMnozenja(p2,q2) or PrekoracenjeMnozenja(q1,x1) or PrekoracenjeSabiranja(p1*x1,p2*x2))
        throw std::overflow_error("Nemoguće dobiti tacan rezultat");
    *this=Razlomak(p1*x1 + p2*x2,q1*x1);
    return *this;
}

//SABIRANJE RAZLOMAKA +
Razlomak operator +(const Razlomak &r1, const Razlomak &r2){
    Razlomak rez(r1);
    rez+=r2;
    return rez;
}

//ODUZIMANJE RAZLOMAKA -= DODJELA
Razlomak Razlomak::operator -=(const Razlomak &r2){
    long long int p1(this->brojnik),p2(r2.DajBrojnik()),q1(this->nazivnik),q2(r2.DajNazivnik()); //operandi
    long long int r(NZD(q1,q2)),x1(q2/r),x2(q1/r);
    if(PrekoracenjeMnozenja(p1,x1) or PrekoracenjeMnozenja(p2,q2) or PrekoracenjeMnozenja(q1,x1) or PrekoracenjeOduzimanja(p1*x1,p2*x2))
        throw std::overflow_error("Nemoguće dobiti tacan rezultat");
    *this=Razlomak(p1*x1 - p2*x2,q1*x1);
    return *this;
}

//ODUZIMANJE RAZLOMAKA - 
Razlomak operator -(const Razlomak &r1, const Razlomak &r2){
    Razlomak rez(r1);
    rez-=r2;
    return rez;
}

//MNOZENJE RAZLOMAKA *= DODJELA
Razlomak Razlomak::operator *=(const Razlomak &r2){
    long long int p1(this->brojnik),p2(r2.DajBrojnik()),q1(this->nazivnik),q2(r2.DajNazivnik()); //operandi
    long long int s(NZD(this->brojnik,r2.DajNazivnik())),t(NZD(r2.DajBrojnik(),this->nazivnik));
    if(PrekoracenjeMnozenja(p1/s,p2/t) or PrekoracenjeMnozenja(q1/t,q2/s))
        throw std::overflow_error("Nemoguće dobiti tacan rezultat");
    *this=Razlomak(p1/s*p2/t,q1/t*q2/s);
    return *this;
}

//MNOZENJE RAZLOMAKA *
Razlomak operator *(const Razlomak &r1, const Razlomak &r2){
    Razlomak rez(r1);
    rez*=r2;
    return rez;
}

//DIJELJENJE RAZLOMAKA /= DODJELA
Razlomak Razlomak::operator /=(const Razlomak &r2){
    long long int p1(this->brojnik),p2(r2.DajBrojnik()),q1(this->nazivnik),q2(r2.DajNazivnik()); //operandi
    long long int u(NZD(p1,p2)),r(NZD(q1,q2));
    if(PrekoracenjeMnozenja(p1/u,q2/r) or PrekoracenjeMnozenja(q1/r,p2/u))
        throw std::overflow_error("Nemoguće dobiti tacan rezultat");
    *this=Razlomak(p1/u*q2/r,q1/r*p2/u);
    return *this;
}

//DIJELJENJE RAZLOMAKA /
Razlomak operator /(const Razlomak &r1, const Razlomak &r2){
    Razlomak rez(r1);
    rez/=r2;
    return rez;
}

//MIJENJANJE PREDZNAKA NA -
Razlomak operator -(Razlomak &r1){
    if(PrekoracenjeMnozenja(r1.DajBrojnik(),-1))
        throw std::overflow_error("Nemoguće dobiti tacan rezultat");
    return Razlomak(r1.DajBrojnik()*-1,r1.DajNazivnik());
}

//INKREMENTACIJA
//++ PREFIKSNI
Razlomak& operator ++(Razlomak &r1){
    if(PrekoracenjeSabiranja(r1.DajBrojnik(),r1.DajNazivnik()))
        throw std::overflow_error("Nemoguće dobiti tacan rezultat");
    r1=Razlomak(r1.DajBrojnik()+r1.DajNazivnik(),r1.DajNazivnik());
    return r1;
}

//++ POSTIFKSNI
Razlomak operator ++(Razlomak &r1, int){
    auto pomocna(r1);
    if(PrekoracenjeSabiranja(r1.DajBrojnik(),r1.DajNazivnik()))
        throw std::overflow_error("Nemoguće dobiti tacan rezultat");
    r1=Razlomak(r1.DajBrojnik()+r1.DajNazivnik(),r1.DajNazivnik());
    return pomocna;
}

//-- PREFIKSNI
Razlomak& operator --(Razlomak &r1){
    if(PrekoracenjeOduzimanja(r1.DajBrojnik(),r1.DajNazivnik()))
        throw std::overflow_error("Nemoguće dobiti tacan rezultat");
    r1=Razlomak(r1.DajBrojnik()-r1.DajNazivnik(),r1.DajNazivnik());
    return r1;
}

//-- POSTIFKSNI
Razlomak operator --(Razlomak &r1, int){
    auto pomocna(r1);
    if(PrekoracenjeOduzimanja(r1.DajBrojnik(),r1.DajNazivnik()))
        throw std::overflow_error("Nemoguće dobiti tacan rezultat");
    r1=Razlomak(r1.DajBrojnik()-r1.DajNazivnik(),r1.DajNazivnik());
    return pomocna;
}

//LOGICKE OPERACIJE POREDJENJA
bool operator <(const Razlomak &r1, const Razlomak &r2){
    return static_cast<long double>(r1) < static_cast<long double> (r2);
}
bool operator >(const Razlomak &r1, const Razlomak &r2){
    return static_cast<long double>(r1) > static_cast<long double> (r2);
}
bool operator <=(const Razlomak &r1, const Razlomak &r2){
    long double p1 = r1, p2 = r2;
    return p1<p2 or fabs(p1-p2)<EPS;
}
bool operator >=(const Razlomak &r1, const Razlomak &r2){
    long double p1 = r1, p2 = r2;
    return p1>p2 or fabs(p1-p2)<EPS;
}
bool operator ==(const Razlomak &r1, const Razlomak &r2){
    long double p1 = r1, p2 = r2;
    return fabs(p1-p2)<EPS;
}
inline bool operator !=(const Razlomak &r1, const Razlomak &r2){
    return !(r1==r2);
}

//OPERACIJE SA TOKOVIMA
std::ostream& operator <<(std::ostream& tok, const Razlomak &r1){
    tok<<r1.DajBrojnik();
    if(r1.DajNazivnik()!=1) tok<<"/"<<r1.DajNazivnik();
    return tok;
}
std::istream& operator >>(std::istream& tok, Razlomak &r1){
    long long int brojnik,nazivnik;
    tok>>std::ws;
    tok>>brojnik;
    if((tok.peek()<='9' and tok.peek()>='0') or tok.peek()==EOF or tok.peek()=='\n' or tok.peek()==' '){ //moze doci novi razlomak ili kraj ili newline
        r1=Razlomak(brojnik,1);
        return tok;
    }
    else if(tok.peek()!='/') tok.setstate(std::ios::failbit);
    else tok.get();
    tok>>nazivnik;
    if((tok.peek()>'0' or tok.peek()>'9') and tok.peek()!='\n' and tok.peek()!=EOF) tok.setstate(std::ios::failbit);
    r1=Razlomak(brojnik,nazivnik);
    return tok;
}

//KONVERZIJA U LONG DOUBLE
Razlomak::operator long double() const{
    return brojnik*1./nazivnik;
}

int main ()
{
       
        return 0;
}
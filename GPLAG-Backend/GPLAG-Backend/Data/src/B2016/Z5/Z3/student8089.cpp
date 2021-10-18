#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>



class Razlomak{
        long long int brojnik, nazivnik;
        static long long int NZD (long long int p, long long int q){
            if (q == 0) return p;
            else if (q != 0) return NZD(q, p%q);
            return 0;
        }
    public:
        Razlomak (long long int brojnik=0, long long int nazivnik=1); //Fali provjera za overflow
        operator long double() const{
            return static_cast<long double>(brojnik) / nazivnik;
        }
        long long int DajBrojnik () const {
            return brojnik;
        }
        long long int DajNazivnik () const {
            return nazivnik;
        }
        
        friend Razlomak operator+ (Razlomak r1, Razlomak r2); //Fali provjera za overflow
        friend Razlomak operator- (Razlomak r1, Razlomak r2); //Fali provjera za overflow
        friend Razlomak operator* (Razlomak r1, Razlomak r2); //Fali provjera za overflow
        friend Razlomak operator/ (Razlomak r1, Razlomak r2); //Fali provjera za overflow
        friend std::ostream &operator <<(std::ostream &tok, Razlomak r1);
        friend std::istream &operator >>(std::istream &tok, Razlomak &r1);
        
        Razlomak operator+ () const{ return *this;}
        Razlomak operator- (){ 
            brojnik *= -1; nazivnik *= -1;
            return *this;
        } //Fali provjera za overflow
        Razlomak &operator+= (Razlomak r2){
            *this = *this + r2;
            return *this;
        }
        Razlomak &operator-= (Razlomak r2){
            *this = *this - r2;
            return *this;
        }
        Razlomak &operator*= (Razlomak r2){
            *this = *this * r2;
            return *this;
        }
        Razlomak &operator/= (Razlomak r2){
            *this = *this / r2;
            return *this;
        }
        Razlomak &operator++ (){
            *this += 1;
            return * this;
        }
        Razlomak operator++ (int){
            Razlomak temp(*this);
            *this += 1;
            return temp;
        }
        Razlomak &operator-- (){
            *this -= 1;
            return *this;
        }
        Razlomak operator-- (int){
            Razlomak temp(*this);
            *this -= 1;
            return temp;
        }
        friend bool operator <(Razlomak r1, Razlomak r2) ;
        friend bool operator >(Razlomak r1, Razlomak r2) ;
        friend bool operator <=(Razlomak r1, Razlomak r2) ;
        friend bool operator >=(Razlomak r1, Razlomak r2) ;
        friend bool operator ==(Razlomak r1, Razlomak r2) ;
        friend bool operator !=(Razlomak r1, Razlomak r2) ;
        
};

Razlomak::Razlomak (long long int brojnik, long long int nazivnik){
    if (nazivnik == 0) throw std::logic_error ("Nekorektan razlomak");
    if (nazivnik < 0){ brojnik *= -1; nazivnik *= -1;}
            
    long long int a (NZD(brojnik, nazivnik));
    brojnik = brojnik /  a;
    nazivnik = nazivnik / a;
            
    Razlomak::brojnik = brojnik; Razlomak::nazivnik = nazivnik;
}

Razlomak operator+ (Razlomak r1, Razlomak r2) {
    long long int M(std::numeric_limits<long long int>::max()), m(std::numeric_limits<long long int>::min());
    if ((r2.brojnik > 0 && r1.brojnik > M-r2.brojnik) || (r2.brojnik < 0 && r1.brojnik < m-r2.brojnik))  throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if ((r2.nazivnik > 0 && r1.nazivnik > M-r2.nazivnik) || (r2.nazivnik < 0 && r1.nazivnik < m-r2.nazivnik))  throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    
    long long int r (Razlomak::NZD(r1.nazivnik, r2.nazivnik));
    long long int nazivnik(r1.nazivnik * (r2.nazivnik / r));
    long long int brojnik (r1.brojnik * (r2.nazivnik / r) + r2.brojnik * (r1.nazivnik / r));
    Razlomak r3(brojnik, nazivnik);
    return r3;
}

Razlomak operator- (Razlomak r1, Razlomak r2) {
    long long int M(std::numeric_limits<long long int>::max()), m(std::numeric_limits<long long int>::min());
    if ((r2.brojnik < 0 && r1.brojnik > M+r2.brojnik) || (r2.brojnik > 0 && r1.brojnik < m+r2.brojnik))  throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if ((r2.nazivnik < 0 && r1.nazivnik > M+r2.nazivnik) || (r2.nazivnik > 0 && r1.nazivnik < m+r2.nazivnik))  throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    
    long long int r (Razlomak::NZD(r1.nazivnik, r2.nazivnik));
    long long int nazivnik(r1.nazivnik * (r2.nazivnik / r));
    long long int brojnik (r1.brojnik * (r2.nazivnik / r) - r2.brojnik * (r1.nazivnik / r));
    Razlomak r3(brojnik, nazivnik);
    return r3;
}

Razlomak operator* (Razlomak r1, Razlomak r2) {
    long long int M(std::numeric_limits<long long int>::max()), m(std::numeric_limits<long long int>::min());
    if ((r2.brojnik > 0 && (r1.brojnik < m/r2.brojnik || r1.brojnik> M / r2.brojnik)) || (r2.brojnik < 0 && (r1.brojnik == m || (-1*r1.brojnik) > M / (-1*r2.brojnik) 
    || (-1*r1.brojnik) < m / (-1*r2.brojnik))))  throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if ((r2.nazivnik > 0 && (r1.nazivnik < m/r2.nazivnik || r1.nazivnik> M / r2.nazivnik)) || (r2.nazivnik < 0 && (r1.nazivnik == m || (-1*r1.nazivnik) > M / (-1*r2.nazivnik) 
    || (-1*r1.nazivnik) < m / (-1*r2.nazivnik))))  throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    
    long long int s (Razlomak::NZD(r1.brojnik, r2.nazivnik)), t(Razlomak::NZD(r2.brojnik, r1.nazivnik));
    long long int brojnik ((r1.brojnik/s)*(r2.brojnik / t));
    long long int nazivnik ((r1.nazivnik/t)*(r2.nazivnik / s));
    Razlomak r3(brojnik, nazivnik);
    return r3;
}

Razlomak operator/ (Razlomak r1, Razlomak r2)  {
    long long int r (Razlomak::NZD(r1.nazivnik, r2.nazivnik)), u(Razlomak::NZD(r1.brojnik, r2.brojnik));
    long long int brojnik ((r1.brojnik/u)*(r2.nazivnik / r));
    long long int nazivnik ((r1.nazivnik/r)*(r2.brojnik / u));
    Razlomak r3(brojnik, nazivnik);
    return r3;
}

std::ostream &operator <<(std::ostream &tok, Razlomak r1){
    tok << r1.DajBrojnik(); if (r1.DajNazivnik() != 1) tok  << "/" << r1.DajNazivnik();
    return tok;
}

std::istream &operator >>(std::istream &tok, Razlomak &r1){
    
    tok >> r1.brojnik;
    
    
    if (tok.peek() == '/') {
        char znak;
        tok >> znak;
        tok >> r1.nazivnik;
        long long int nzd(Razlomak::NZD(r1.brojnik, r1.nazivnik));
        r1.brojnik /= nzd;
        r1.nazivnik /= nzd;
        
        if (!(tok.peek() == ' ' || tok.peek() == '\n' || tok.peek() == '\r' || tok.peek() == '\f' || tok.peek() == '\t' || tok.peek() == '\v')) tok.setstate(std::ios::failbit);
    }
    else if (tok.peek() == EOF || tok.peek() == ' ' || tok.peek() == '\n'  || tok.peek() == '\r' || tok.peek() == '\f' || tok.peek() == '\t' || tok.peek() == '\v'){
        
        r1.nazivnik = 1;
    }
    else tok.setstate(std::ios::failbit);
    
    
    return tok;
    
} //NE RADI KAKO TREBA

bool operator <(Razlomak r1, Razlomak r2) {
    long double e1(r1.brojnik/r1.nazivnik), e2(r2.brojnik/r2.nazivnik);
    if (e1 < e2) return true;
    return false;
}

bool operator >(Razlomak r1, Razlomak r2) {
    long double e1(r1.brojnik/r1.nazivnik), e2(r2.brojnik/r2.nazivnik);
    if (e1 > e2) return true;
    return false;
}

bool operator <=(Razlomak r1, Razlomak r2) {
    long double e1(r1.brojnik/r1.nazivnik), e2(r2.brojnik/r2.nazivnik);
    if (e1 <= e2) return true;
    return false;
    }
      
bool operator >=(Razlomak r1, Razlomak r2) {
    long double e1(r1.brojnik/r1.nazivnik), e2(r2.brojnik/r2.nazivnik);
    if (e1 >= e2) return true;
    return false;
}

bool operator ==(Razlomak r1, Razlomak r2) {
    long double e1(r1.brojnik/r1.nazivnik), e2(r2.brojnik/r2.nazivnik);
    if (e1 == e2) return true;
    return false;
}

bool operator !=(Razlomak r1, Razlomak r2) {
    long double e1(r1.brojnik/r1.nazivnik), e2(r2.brojnik/r2.nazivnik);
    if (e1 != e2) return true;
    return false;
}

int main (){
  
}
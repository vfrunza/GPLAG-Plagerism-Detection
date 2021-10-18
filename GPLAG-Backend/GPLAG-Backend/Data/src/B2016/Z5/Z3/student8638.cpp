/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>


class Razlomak{
  long long int brojnik;
  long long int nazivnik;
  static long long int NZD(long long int x, long long int y);
  static bool Uporedi_double(long double a, long double b);

  public:
  Razlomak(long long int brojnik=0, long long int nazivnik=1);
  long long int DajBrojnik() const { return brojnik;}
  long long int DajNazivnik() const { return nazivnik;}
  friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r);
  friend std::istream &operator >>(std::istream &tok, Razlomak &r); //DORADITI
  friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
  Razlomak operator +() const { return Razlomak(brojnik,nazivnik); }
  Razlomak operator -() { return Razlomak(-brojnik, nazivnik); }
  Razlomak operator *=(const Razlomak &r2){ *this = *this * r2; return *this;}
  Razlomak operator /=(const Razlomak &r2){ *this = *this / r2; return *this;}
  Razlomak operator +=(const Razlomak &r2){ *this = *this + r2; return *this;}
  Razlomak operator -=(const Razlomak &r2){ *this = *this - r2; return *this;}
  Razlomak operator ++() {  *this = *this + Razlomak(1); return *this;}  //prefiksni
  Razlomak operator --() {  *this = *this - Razlomak(1); return *this; }  //prefiksni
  Razlomak operator ++(int) { Razlomak temp(brojnik,nazivnik); temp = Razlomak(1) + temp; return temp; }
  Razlomak operator --(int) { Razlomak temp(brojnik,nazivnik); temp = temp - Razlomak(1); return temp; } 
  operator long double ();
  friend bool operator < (Razlomak r1, Razlomak r2){ long double a = r1; long double b = r2; return a < b; }
  friend bool operator > (Razlomak r1, Razlomak r2){ long double a = r1; long double b = r2; return a > b; }
  friend bool operator <=(Razlomak r1, Razlomak r2){ long double a = r1; long double b = r2; return a <= b; }
  friend bool operator >=(Razlomak r1, Razlomak r2){ long double a = r1; long double b = r2; return a >= b; }
  friend bool operator ==(Razlomak r1, Razlomak r2){ long double a = r1; long double b = r2; return Uporedi_double(a,b); }
  friend bool operator !=(Razlomak r1, Razlomak r2){ long double a = r1; long double b = r2; return !(Uporedi_double(a,b)); }
  
};

long long int Razlomak::NZD(long long int x, long long int y){
    long long int temp;
    while(y!=0){
        temp = x%y;
        x = y; 
        y = temp;
    }
    return x;
}

bool Razlomak::Uporedi_double(long double a, long double b){
      long double razlika = a-b;
      long double EPSILON = std::numeric_limits<long double>::epsilon();
      return (razlika < EPSILON) && (-razlika < EPSILON);
  }

  
Razlomak::Razlomak(long long int brojnik, long long int nazivnik){
    if(nazivnik == 0) throw std::logic_error("Nekorektan razlomak");
    long long int nzd = Razlomak::NZD(brojnik, nazivnik);
    long long int temp1, temp2;
    
    if(nzd == 1 || nzd == -1){
        if(brojnik < 0 && nazivnik < 0){
            temp1 = brojnik * -1;
            temp2 = nazivnik *-1;
        }
        if(brojnik > 0 && nazivnik < 0){
            temp1 = brojnik * -1;
            temp2 = nazivnik *-1;
        }
    temp1 = brojnik;
    temp2 = nazivnik;
    }
    
    while(nzd != 1){
        temp1 = brojnik/nzd;
        temp2= nazivnik/nzd;
        nzd = Razlomak::NZD(temp1, temp2);
    }
    
    if(temp1 > 0 && temp2 < 0){
        temp1 *=-1; temp2 *=-1;
    }
    
    if(temp1 < 0 && temp2 < 0){
        temp1 *=-1; temp2 *=-1;
    }
    
    Razlomak::brojnik = temp1;
    Razlomak::nazivnik = temp2;
}

std::ostream &operator <<(std::ostream &tok, const Razlomak &r){
    if(r.nazivnik == 1) tok << r.brojnik ;
    else tok << r.brojnik << "/" << r.nazivnik;
    return tok;
}

std::istream &operator >>(std::istream &tok, Razlomak &r){
    char znak;
    tok >> std::ws;
    tok >> r.brojnik;
    if(tok.peek() == '/'){
        tok >> znak;
        tok >> r.nazivnik;
        r = Razlomak(r.brojnik, r.nazivnik);
    }
    else if(tok.peek() == '\n' || tok.peek() == ' '){
        r.nazivnik = 1;
        r = Razlomak(r.brojnik, r.nazivnik);
    }
    else {
        tok.setstate(std::ios::failbit);
    }
    return tok;
}

Razlomak operator +(const Razlomak &r1, const Razlomak &r2){
    
    long long int r = Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    long long int nazivnik = r1.nazivnik * (r2.nazivnik/r);
    long long int brojnik = r1.brojnik * (r2.nazivnik/r) + r2.brojnik * (r1.nazivnik/r);
    
    Razlomak r3(brojnik, nazivnik);
    
    return r3;
}

Razlomak operator -(const Razlomak &r1, const Razlomak &r2){
    
    long long int m = std::numeric_limits<long long int>::min();
    long long int M =  std::numeric_limits<long long int>::max();
    if((r2.brojnik < 0 && r1 > Razlomak(M) + r2) || (r2.brojnik > 0 && r1 < Razlomak(m) + r2)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    
    long long int r = Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    long long int nazivnik = r1.nazivnik * (r2.nazivnik/r);
    long long int brojnik = r1.brojnik * (r2.nazivnik/r) - r2.brojnik * (r1.nazivnik/r);
    
    Razlomak r3(brojnik, nazivnik);
    
    return r3;
}

Razlomak operator *(const Razlomak &r1, const Razlomak &r2){
    
    long long int m = std::numeric_limits<long long int>::min();
    long long int M =  std::numeric_limits<long long int>::max();
    if( (r2.brojnik > 0 && !(r1 < (Razlomak(m)/r2) || r1 > Razlomak(M)/r2)) ||( r2.brojnik < 0 && (r1 == Razlomak(m) || (Razlomak(-1) * r1) > Razlomak(M)/(r2*Razlomak(-1))  || (Razlomak(-1)*r1) < Razlomak(m)/(Razlomak(-1) * r2)))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    
    long long int s = Razlomak::NZD(r1.brojnik, r2.nazivnik);
    long long int t = Razlomak::NZD(r2.brojnik, r1.nazivnik);
    
    long long int brojnik = (r1.brojnik/s) * (r2.brojnik/t);
    long long int nazivnik = (r1.nazivnik/t) * (r2.nazivnik/s);
    
    Razlomak r3(brojnik, nazivnik);
    
    return r3;
}

Razlomak operator /(const Razlomak &r1, const Razlomak &r2){
    
    
    long long int r = Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    long long int u = Razlomak::NZD(r1.brojnik, r2.brojnik);
    
    long long int brojnik = (r1.brojnik/u) * (r2.nazivnik/r);
    long long int nazivnik = (r1.nazivnik/r) * (r2.brojnik/u);
    
    Razlomak r3(brojnik, nazivnik);
    
    return r3;
}

Razlomak::operator long double (){
    long double decimalni;
    decimalni = static_cast<long double> (brojnik) / nazivnik;
    return decimalni;
}



int main (){

return 0;
}
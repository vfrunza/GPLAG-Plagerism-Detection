/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <sstream>
class Razlomak{
  long long int brojnik, nazivnik;
  static long long int NZD (long long int p, long long int q);
  static bool PrekoracenjeKodMnozenja (long long int x, long long int y);
  static bool PrekoracenjeKodSabiranja (long long int x, long long int y);
  static bool PrekoracenjeKodOduzimanja (long long int x, long long int y);
  static bool IstiDoubleovi (long double x, long double y, long double eps=1e-10);
  public:
   Razlomak(long long int br = 0, long long int naz = 1);
   long long int DajBrojnik() const {return brojnik;}
   long long int DajNazivnik() const {return nazivnik;}
   friend Razlomak operator+ (const Razlomak &r1, const Razlomak &r2);
   friend Razlomak operator- (const Razlomak &r1, const Razlomak &r2);
   friend Razlomak operator* (const Razlomak &r1, const Razlomak &r2);
   friend Razlomak operator/ (const Razlomak &r1, const Razlomak &r2);
   Razlomak &operator+(){return *this;};
   Razlomak &operator-();
   Razlomak &operator+=(const Razlomak &r);
   Razlomak &operator-=(const Razlomak &r);
   Razlomak &operator*=(const Razlomak &r);
   Razlomak &operator/=(const Razlomak &r);
   Razlomak &operator++();
   Razlomak operator++(int);
   Razlomak &operator--();
   Razlomak operator--(int);
   friend bool operator< (const Razlomak &r1, const Razlomak &r2);
   friend bool operator> (const Razlomak &r1, const Razlomak &r2);
   friend bool operator== (const Razlomak &r1, const Razlomak &r2);
   friend bool operator!= (const Razlomak &r1, const Razlomak &r2);
   friend bool operator<= (const Razlomak &r1, const Razlomak &r2);
   friend bool operator>= (const Razlomak &r1, const Razlomak &r2);
   friend std::ostream &operator<< (std::ostream &tok, const Razlomak &r);
   friend std::istream &operator>> (std::istream &tok, Razlomak &r);
   operator long double() const;
   
};

Razlomak::operator long double() const{
    long double raz((long double)brojnik/nazivnik);
    return raz;
}

bool Razlomak::IstiDoubleovi(long double x, long double y, long double eps){
    return (std::abs(x-y)<eps);
}


Razlomak &Razlomak::operator-(){
    if(PrekoracenjeKodOduzimanja(0, brojnik))
      throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    brojnik*=(-1);
    return *this;
}

long long int Razlomak::NZD(long long int p, long long int q){
    if(q==0)
      return p;
    long long int prvi(p), drugi(q), stari_prvi(p);
    while (drugi!=0) {
        prvi = drugi;
        drugi = stari_prvi % prvi;
        stari_prvi = prvi;
    }
    return prvi;
}

Razlomak::Razlomak(long long int br, long long int naz){
    if(naz==0)
      throw std::logic_error("Nekorektan razlomak");
    long long int djelilac = Razlomak::NZD(br, naz);
    br/=djelilac; naz/=djelilac;
    if(naz<0){
        naz*=(-1);
        br*=(-1);
    }
    brojnik = br; 
    nazivnik = naz;

}

bool Razlomak::PrekoracenjeKodSabiranja(long long int x, long long int y){
    long long int M, m;
    M = std::numeric_limits<long long int>::max();
    m = std::numeric_limits<long long int>::min();
    if((y>0 && x>(M - y)) || (y<0 && x<(m - y)))
      return true;
    return false;
}

bool Razlomak::PrekoracenjeKodMnozenja(long long int x, long long int y){
    long long int M, m;
    M = std::numeric_limits<long long int>::max();
    m = std::numeric_limits<long long int>::min();
    if(y>0 && (x<(m/y) || x>(M/y)))
      return true;
    if(y<0 && (x==m || (-x>(M/(-y))) || (-x<(m/(-y)))  )){
     
      return true;
    }
    return false;
}

bool Razlomak::PrekoracenjeKodOduzimanja(long long int x, long long int y){
    long long int M, m;
    M = std::numeric_limits<long long int>::max();
    m = std::numeric_limits<long long int>::min();
  /*  if((y<0 && x>(M + y)) || (y>0 && (x<(m + y))))
      return true;
    return false;*/
    return PrekoracenjeKodSabiranja(x, -y);
}

Razlomak &Razlomak::operator+=(const Razlomak &r2){
    Razlomak r1(brojnik, nazivnik);
    long long int r(Razlomak::NZD(r1.nazivnik, r2.nazivnik));
    //long long int br, naz;
    if(Razlomak::PrekoracenjeKodMnozenja(r1.brojnik, r2.nazivnik/r) || Razlomak::PrekoracenjeKodMnozenja(r2.brojnik, r1.nazivnik/r) || Razlomak::PrekoracenjeKodMnozenja(r1.nazivnik, r2.nazivnik))
      throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeKodSabiranja(r1.brojnik * (r2.nazivnik/r), r2.brojnik*(r1.nazivnik/r)))
      throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    brojnik = (r1.brojnik * (r2.nazivnik/r)) + (r2.brojnik *(r1.nazivnik/r));
    nazivnik = r1.nazivnik * (r2.nazivnik/r);
    long long int nzd(Razlomak::NZD(brojnik, nazivnik));
    brojnik/=nzd; nazivnik/=nzd;
    return *this;
    
}

inline Razlomak operator+ (const Razlomak &r1, const Razlomak &r2){
    Razlomak r3(r1);
    r3+=r2;
    return r3;
}

Razlomak &Razlomak::operator-=(const Razlomak &r2){
    Razlomak r1(brojnik, nazivnik);
    long long int r(Razlomak::NZD(r1.nazivnik, r2.nazivnik));
   // long long int br, naz;
    if(Razlomak::PrekoracenjeKodMnozenja(r1.brojnik, r2.nazivnik/r) || Razlomak::PrekoracenjeKodMnozenja(r2.brojnik, r1.nazivnik/r) || Razlomak::PrekoracenjeKodMnozenja(r1.nazivnik, r2.nazivnik))
      throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeKodOduzimanja(r1.brojnik * (r2.nazivnik/r), r2.brojnik * (r1.nazivnik/r)))
      throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    brojnik = (r1.brojnik*(r2.nazivnik/r)) - (r2.brojnik * (r1.nazivnik/r));
    nazivnik = r1.nazivnik * (r2.nazivnik/r);
    long long int nzd(Razlomak::NZD(brojnik, nazivnik));
    brojnik/=nzd; nazivnik/=nzd;
    return *this;
}

inline Razlomak operator-(const Razlomak &r1, const Razlomak &r2){
    Razlomak r3(r1);
    r3-=r2;
    return r3;
}

Razlomak &Razlomak::operator*= (const Razlomak &r2){
    Razlomak r1(brojnik, nazivnik);
    long long int s(NZD(brojnik, r2.nazivnik)), t(NZD(r2.brojnik, nazivnik));
    if(PrekoracenjeKodMnozenja(brojnik/s, r2.brojnik/t) || PrekoracenjeKodMnozenja(nazivnik/t, r2.nazivnik/s))
      throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    brojnik/=s;
    brojnik*=(r2.brojnik/t);
    nazivnik/=t;
    nazivnik*=(r2.nazivnik/s);
    long long int nzd(Razlomak::NZD(brojnik, nazivnik));
    brojnik/=nzd;
    nazivnik/=nzd;
    return *this;
    
}

inline Razlomak operator* (const Razlomak &r1, const Razlomak &r2){
    Razlomak r3(r1);
    r3*=r2;
    return r3;
}

Razlomak &Razlomak::operator/=(const Razlomak &r2){
    long long int r(NZD(nazivnik, r2.nazivnik));
    long long int u(NZD(brojnik, r2.brojnik));
    if(PrekoracenjeKodMnozenja(brojnik/u, r2.nazivnik/r) || PrekoracenjeKodMnozenja(nazivnik/r, r2.brojnik/u))
      throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    brojnik/=u;
    brojnik*=(r2.nazivnik/r);
    nazivnik/=r;
    nazivnik*=(r2.brojnik/u);
    long long int nzd(Razlomak::NZD(brojnik,nazivnik));
    brojnik/=nzd;
    nazivnik/=nzd;
    return *this;
}

inline Razlomak operator/ (const Razlomak &r1, const Razlomak &r2){
    Razlomak r3(r1);
    r3/=r2;
    return r3;
}

Razlomak &Razlomak::operator++(){
    *this+=(Razlomak(1));
    return *this;
}

inline Razlomak Razlomak::operator++(int){
    Razlomak pomocni(*this);
    ++(*this);
    return pomocni;
}

Razlomak &Razlomak::operator--(){
    *this-=(Razlomak(1));
    return *this;
}

inline Razlomak Razlomak::operator--(int){
    Razlomak pomocni(*this);
    --(*this);
    return pomocni;
}

bool operator<(const Razlomak &r1, const Razlomak &r2){
    long double prvi, drugi;
    prvi = ((long double)r1.brojnik/r1.nazivnik);
    drugi = ((long double)r2.brojnik / r2.nazivnik);
    return prvi<drugi;
}

bool operator> (const Razlomak &r1, const Razlomak &r2){
    long double prvi, drugi;
    prvi = (long double)r1.brojnik/r1.nazivnik;
    drugi = (long double)r2.brojnik/r2.nazivnik;
    return prvi>drugi;
}

bool operator== (const Razlomak &r1, const Razlomak &r2){
    long double prvi, drugi;
    prvi = (long double)r1.brojnik/r1.nazivnik;
    drugi = (long double)r2.brojnik/r2.nazivnik;
    return Razlomak::IstiDoubleovi(prvi, drugi);
}

inline bool operator!= (const Razlomak &r1, const Razlomak &r2){
    return !(r1==r2);
}

bool operator<= (const Razlomak &r1, const Razlomak &r2){
    return ((r1<r2) || (r1==r2));
}

bool operator>= (const Razlomak &r1, const Razlomak &r2){
    return ((r1>r2) || (r1==r2));
}

std::ostream &operator<< (std::ostream &tok, const Razlomak &r){
    if(r.nazivnik!=1 && r.brojnik!=0){
     tok<<r.brojnik<<"/"<<r.nazivnik;
    }
    else
      tok<<r.brojnik;
    return tok;
}

std::istream &operator>> (std::istream &tok, Razlomak &r){
    //tok>> std::ws;
    tok>>r.brojnik;
    if(!tok)
      tok.setstate(std::ios::failbit);
    if(tok.peek()!='/'){
      r.nazivnik = 1;
      return tok;
    }
    char znak;
    tok>>znak>>r.nazivnik;
    if(!tok)
      tok.setstate(std::ios::failbit);
    if(tok.peek()!=' ' && tok.peek()!='\n')
     tok.setstate(std::ios::failbit);
    long long int nzd(Razlomak::NZD(r.brojnik, r.nazivnik));
    r.brojnik/=nzd;
    r.nazivnik/=nzd;
    return tok;
}
int main ()
{
  try{
  Razlomak r1(10,7), r2(6,11);
  std::cout<<r1+r2<<" "<<r1-r2<<" "<<r1*r2<<" "<<r1/r2<<std::endl;
  r1*=2;
  std::cout<<+r1<<" "<<-r1<<" "<<r1<<std::endl;
  Razlomak r(1,2), r3;
  std::cout<<r<<"\nUnesite razlomak:\n";
  std::cin>>r3;
  r*=r1;
  std::cout<<r<<std::endl;
  std::cout<<r3<<std::endl;
  r3++;
  r1--;
  ++r2;
  std::cout<<r1<<" "<<r2<<" "<<r3<<std::endl;
  if((1/2)==(1/2))
  std::cout<<"isti su"<<std::endl;
  std::cout<<Razlomak(1,3)<<std::endl;
  std::cout<<std::boolalpha<<(Razlomak(1,3)<Razlomak(1,2))<<std::endl;
  std::cout<<std::boolalpha<<(Razlomak(1,19)>Razlomak(1,6))<<std::endl;
  std::cout<<std::boolalpha<<(Razlomak(1,2)<=Razlomak(1,2))<<std::endl;
  std::cout<<(long double)r3<<std::endl;
  r1/=r3;
  std::cout<<r1<<std::endl;
  Razlomak r4(1,2), r5(2,1);
  r4/=r5;
  std::cout<<r4<<std::endl;
  }
  catch(std::overflow_error e){
      std::cout<<" Izuzetak: "<<e.what()<<std::endl;
  }
	return 0;
}
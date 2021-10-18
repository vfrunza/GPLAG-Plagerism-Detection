/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <climits>
#include <initializer_list>


long long int NZD(long long int a, long long int b) {
    long long int n=a, i=0;
    long long int nzd=1;
    if (b<a) n=b;
    for (i=1;i<=n;i++) {
        if(a%i==0 && b%i==0) nzd =i;
    }
    return nzd;
}

class Razlomak {
    
    private:
    long long int brojnik;
    long long int nazivnik;
    public:
    Razlomak(long long int broj=0, long long int naz=1) {
        if (naz==0) throw std::logic_error("Nekorektan razlomak");
        long long int nzd = NZD(broj, naz);
        brojnik=broj/nzd;
        nazivnik=naz/nzd;
        if (brojnik*nazivnik<0) {brojnik=0-abs(brojnik);
            nazivnik=abs(nazivnik);}
        
        else { brojnik=abs(brojnik);
        nazivnik=abs(nazivnik);
    }}
    Razlomak (std::initializer_list<int> lista) {
       auto it = lista.begin();
       brojnik=*it;
       it++;
       nazivnik=*it;
    }

long long int DajBrojnik() {return brojnik;}
long long int DajNazivnik() {return nazivnik;}
void PostaviBrojnik(long long int broj){brojnik = broj;}
void PostaviNazivnik(long long int broj){nazivnik = broj;}
friend const Razlomak operator+(const Razlomak &a, const Razlomak &b);
friend const Razlomak operator-(const Razlomak &a, const Razlomak &b);
friend const Razlomak operator*(const Razlomak &a, const Razlomak &b);
friend const Razlomak operator/(const Razlomak &a, const Razlomak &b);
friend const Razlomak operator+(Razlomak);
friend const Razlomak operator-(Razlomak);

Razlomak &operator=(const Razlomak &r);

friend void operator+=(const Razlomak &r1, Razlomak &r2) {r1+r2;}
friend void operator-=(const Razlomak &r1, Razlomak &r2) {r1-r2;}
friend void operator/=(const Razlomak &r1, Razlomak &r2) {r1/r2;}
friend void operator*=(const Razlomak &r1, Razlomak &r2) {r1*r2;}
friend Razlomak operator ++(Razlomak &r1);
friend Razlomak operator ++(Razlomak &r1, int a);
friend bool operator == (Razlomak r1, Razlomak r2);
friend bool operator != (Razlomak r1, Razlomak r2);
friend bool operator < (Razlomak r1, Razlomak r2);
friend bool operator > (Razlomak r1, Razlomak r2);
friend bool operator <= (Razlomak r1, Razlomak r2);
friend bool operator >= (Razlomak r1, Razlomak r2);
friend std::ostream &operator<<(std::ostream &os, Razlomak r);
friend std::istream &operator>>(std::istream &Os, Razlomak &r);

operator long double() const {return (long double)(brojnik)/(long double)(nazivnik);}
operator long long int() const {return brojnik/nazivnik;}
//operator long double() const {return brojnik/nazivnik;}


};

std::ostream &operator <<(std::ostream &os, Razlomak r) {
    r=Razlomak(r.brojnik, r.nazivnik);
 if (r.nazivnik!=1) os<<r.brojnik<<"/"<<r.nazivnik;
  else os<<r.brojnik;
  return os;
}

std::istream &operator >>(std::istream &os, Razlomak &r) {
 char znak1,znak2;
 long long int broj, naz;
 os>>std::ws;
 if(os.peek()>='a'&& os.peek()<='z') {os.setstate(std::ios::failbit); return os;}
  os>>broj;
  if (os.peek()=='/') os>>znak1>>naz;
  else naz=1;
  //if (os.peek()!=' ') {os.setstate(std::ios::failbit); return os;}
  if ( os.peek()>='a'&& os.peek()<='z') {os>>znak2; os.setstate(std::ios::failbit); return os;}
  r=Razlomak(broj,naz);
  return os;
  //else os.setstate(std::ios::failbit);
  
  
  /*if (znak1=="/"&& znak2==" ") {
  r=Razlomak(r.brojnik,r.nazivnik);
  return os;}
  else if (znak1==" ") {r=Razlomak(r.brojnik,1); return os;
  } 
  else os.setstate(std::ios::failbit);*/
  
}

bool operator == (Razlomak r1, Razlomak r2) {
    long double brojnik1, brojnik2, nazivnik1, nazivnik2;
    brojnik1=r1.brojnik; brojnik2=r2.brojnik; nazivnik1=r1.nazivnik; nazivnik2=r2.nazivnik;
    if (brojnik1/nazivnik1 == brojnik2/nazivnik2) return true; else return false;
    
}

bool operator != (Razlomak r1, Razlomak r2) {
    long double brojnik1, brojnik2, nazivnik1, nazivnik2;
    brojnik1=r1.brojnik; brojnik2=r2.brojnik; nazivnik1=r1.nazivnik; nazivnik2=r2.nazivnik;
    if (brojnik1/nazivnik1 == brojnik2/nazivnik2) return false; else return true;
    
}

bool operator < (Razlomak r1, Razlomak r2) {
    long double brojnik1, brojnik2, nazivnik1, nazivnik2;
    brojnik1=r1.brojnik; brojnik2=r2.brojnik; nazivnik1=r1.nazivnik; nazivnik2=r2.nazivnik;
    if (brojnik1/nazivnik1 < brojnik2/nazivnik2) return true; else return false;
    
}

bool operator > (Razlomak r1, Razlomak r2) {
    long double brojnik1, brojnik2, nazivnik1, nazivnik2;
    brojnik1=r1.brojnik; brojnik2=r2.brojnik; nazivnik1=r1.nazivnik; nazivnik2=r2.nazivnik;
    if (brojnik1/nazivnik1 > brojnik2/nazivnik2) return true; else return false;
    
}

bool operator <= (Razlomak r1, Razlomak r2) {
    long double brojnik1, brojnik2, nazivnik1, nazivnik2;
    brojnik1=r1.brojnik; brojnik2=r2.brojnik; nazivnik1=r1.nazivnik; nazivnik2=r2.nazivnik;
    if (brojnik1/nazivnik1 <= brojnik2/nazivnik2) return true; else return false;
    
}

bool operator >= (Razlomak r1, Razlomak r2) {
    long double brojnik1, brojnik2, nazivnik1, nazivnik2;
    brojnik1=r1.brojnik; brojnik2=r2.brojnik; nazivnik1=r1.nazivnik; nazivnik2=r2.nazivnik;
    if (brojnik1/nazivnik1 >= brojnik2/nazivnik2) return true; else return false;
    
}

Razlomak operator ++(Razlomak &r1) {
    r1.brojnik=r1.brojnik+r1.nazivnik;
    return r1;
}

Razlomak operator ++(Razlomak &r1, int a) {
    Razlomak r2 = r1;
    r1.brojnik=r1.brojnik+r1.nazivnik;
    return r2;
}

Razlomak &Razlomak::operator=(const Razlomak &r){
    brojnik=r.brojnik;
    nazivnik=r.nazivnik;
    return *this;
}




const Razlomak operator+(const Razlomak &a, const Razlomak &b) {
    long long int M=LLONG_MAX;
    long long int m =LLONG_MIN;
    long long int r,s,t,u,p1,p2,q1,q2;
    p1=a.brojnik;
    p2=b.brojnik;
    q1=a.nazivnik;
    q2=b.nazivnik;
    r=NZD(q1,q2);
    s=NZD(p1,q2);;
    t=NZD(q1,p2);
    u=NZD(p1,p2);
    if (p2*(q1/r)>0 && p1*(q2/r)>M-p2*(q1/r)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if (p2*(q1/r)<0 && p1*(q2/r)<m-p2*(q1/r)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int br=p1*(q2/r)+p2*(q1/r);
    long long int n=q1*(q2/r);
    Razlomak raz = Razlomak(br,n);
    return raz;
    
}
const Razlomak operator-(const Razlomak &a, const Razlomak &b) {
    long long int r,s,t,u,p1,p2,q1,q2;
    p1=a.brojnik;
    p2=b.brojnik;
    q1=a.nazivnik;
    q2=b.nazivnik;
    r=NZD(q1,q2);
    s=NZD(p1,q2);;
    t=NZD(q1,p2);
    u=NZD(p1,p2);
    long long int br=p1*(q2/r)-p2*(q1/r);
    long long int n=q1*(q2/r);
    Razlomak raz = Razlomak(br,n);
    return raz;
    
}
const Razlomak operator*(const Razlomak &a, const Razlomak &b) {
    long long int r,s,t,u,p1,p2,q1,q2;
    p1=a.brojnik;
    p2=b.brojnik;
    q1=a.nazivnik;
    q2=b.nazivnik;
    r=NZD(q1,q2);
    s=NZD(p1,q2);;
    t=NZD(q1,p2);
    u=NZD(p1,p2);
    long long int br=(p1/s)*(p2/t);
    long long int n=(q1/t)*(q2/s);
    Razlomak raz = Razlomak(br,n);
    return raz;
    
}
const Razlomak operator/(const Razlomak &a, const Razlomak &b) {
    long long int r,s,t,u,p1,p2,q1,q2;
    p1=a.brojnik;
    p2=b.brojnik;
    q1=a.nazivnik;
    q2=b.nazivnik;
    r=NZD(q1,q2);
    s=NZD(p1,q2);;
    t=NZD(q1,p2);
    u=NZD(p1,p2);
    long long int br=(p1/u)*(q2/r);
    long long int n=(q1/r)*(p2/u);
    Razlomak raz = Razlomak(br,n);
    return raz;
    
}

const Razlomak operator+(Razlomak r) {
    return r;
}
const Razlomak operator-(Razlomak r) {
    return Razlomak(0-r.DajBrojnik(),r.nazivnik);
}

int main ()
{
    /*Razlomak r1{3,4};
    Razlomak r2=Razlomak(5,3);
    Razlomak r;
   //cin>>r;
    cout<<std::endl;
    //if (r1>r2) cout<<"Da"; else cout<<"Ne";
    cout<<r1;
	return 0;*/
	Razlomak r,p,g;
        std::cin >> r>>p>>g; 
        
        std::cout << r<<std::endl<<p<<std::endl<<g;
        
}
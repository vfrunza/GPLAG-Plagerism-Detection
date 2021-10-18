#include <iostream>
#include <stdexcept>
#include <string>
#include <initializer_list>
#include <climits>
#include <cmath>
class Razlomak{
    long long int brojnik, nazivnik;
    public:
    Razlomak(long long int b=0, long long int n=1) {
        brojnik=b;
        nazivnik=n;
        if(n==0) throw std::logic_error("Nekorektan razlomak");
        auto djelilac=NZD(brojnik, nazivnik);
        brojnik/=djelilac; nazivnik/=djelilac;
        if(nazivnik<0) {brojnik*=-1; nazivnik*=-1;}
    }
    Razlomak(std::initializer_list<long long int> l) {
        if(l.size()>2) throw;
        brojnik=*(l.begin());
        if(l.size()==2) {
        for(auto it=l.begin(); it!= l.end(); it++){
        nazivnik=*it;}}
        else nazivnik=1;
    }
    static long long int NZD(long long int p, long long int q);
    long long int DajBrojnik() const {return brojnik;}
    long long int DajNazivnik() const {return nazivnik;}
    bool MozeLiSeMnoziti(long long int zamnozenje1, long long int zamnozenje2) {
         if(zamnozenje2>0 && (zamnozenje1<LLONG_MIN/zamnozenje2 || zamnozenje1>LLONG_MAX/zamnozenje2)) return false;
        else if(zamnozenje2<0 && (zamnozenje1==LLONG_MIN || -zamnozenje1>LLONG_MAX/(-zamnozenje2) || -zamnozenje1<LLONG_MIN/(-zamnozenje2))) return false;
        return true;
    }
 bool MozeLiSeSabrati(long long int zasabiranje1, long long int zasabiranje2) {
         if(zasabiranje2>0 && zasabiranje1>LLONG_MAX-zasabiranje2) return false;
        else if(zasabiranje2<0 && zasabiranje1<LLONG_MIN-zasabiranje2) return false;
        return true;
    }
    
    friend Razlomak operator+(const Razlomak r1, const Razlomak r2) {
        long long int a, b;
        auto r=NZD(r1.DajNazivnik(),r2.DajNazivnik());
        auto zasabiranje1=r1.brojnik*(r2.nazivnik/r), zasabiranje2=r2.brojnik*(r1.nazivnik/r), zamnozenje1=r1.brojnik, zamnozenje2=r2.nazivnik/r, zamnozenje3=r2.brojnik, zamnozenje4=r1.nazivnik/r;
        auto zamnozenje5=r1.nazivnik, zamnozenje6=r2.nazivnik/r;
        if(zamnozenje2>0 && (zamnozenje1>LLONG_MAX/zamnozenje2 || zamnozenje1<LLONG_MIN/zamnozenje2)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje2<0 && (zamnozenje1==LLONG_MIN || -zamnozenje1>LLONG_MAX/(-zamnozenje2))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
         if(zamnozenje4>0 && (zamnozenje3>LLONG_MAX/zamnozenje4 || zamnozenje3<LLONG_MIN/zamnozenje4)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje4<0 && (zamnozenje3==LLONG_MIN || -zamnozenje3>LLONG_MAX/(-zamnozenje4))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
         if(zamnozenje6>0 && (zamnozenje5>LLONG_MAX/zamnozenje6 || zamnozenje5<LLONG_MIN/zamnozenje6)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje6<0 && (zamnozenje5==LLONG_MIN || -zamnozenje5>LLONG_MAX/(-zamnozenje6))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        if(zasabiranje2>0 && zasabiranje1>LLONG_MAX-zasabiranje2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zasabiranje2<0 && zasabiranje1<LLONG_MIN-zasabiranje2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        a=r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r);
        b=r1.nazivnik*(r2.nazivnik/r);
        Razlomak rezultat(a,b);
        return rezultat;
    }
    friend Razlomak operator-(const Razlomak r1, const Razlomak r2) {
        long long int a,b;
        auto r=NZD(r1.DajNazivnik(), r2.DajNazivnik());
        auto zasabiranje1=r1.brojnik*(r2.nazivnik/r), zasabiranje2=r2.brojnik*(r1.nazivnik/r), zamnozenje1=r1.brojnik, zamnozenje2=r2.nazivnik/r, zamnozenje3=r2.brojnik, zamnozenje4=r1.nazivnik/r;
        auto zamnozenje5=r1.nazivnik, zamnozenje6=r2.nazivnik/r;
               if(zamnozenje2>0 && (zamnozenje1>LLONG_MAX/zamnozenje2 || zamnozenje1<LLONG_MIN/zamnozenje2)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje2<0 && (zamnozenje1==LLONG_MIN || -zamnozenje1>LLONG_MAX/(-zamnozenje2))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
         if(zamnozenje4>0 && (zamnozenje3>LLONG_MAX/zamnozenje4 || zamnozenje3<LLONG_MIN/zamnozenje4)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje4<0 && (zamnozenje3==LLONG_MIN || -zamnozenje3>LLONG_MAX/(-zamnozenje4))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
         if(zamnozenje6>0 && (zamnozenje5>LLONG_MAX/zamnozenje6 || zamnozenje5<LLONG_MIN/zamnozenje6)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje6<0 && (zamnozenje5==LLONG_MIN || -zamnozenje5>LLONG_MAX/(-zamnozenje6))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        if(zasabiranje2<0 && zasabiranje1>LLONG_MAX+zasabiranje2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zasabiranje2>0 && zasabiranje1<LLONG_MIN-zasabiranje2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        a=r1.brojnik*(r2.nazivnik/r)-r2.brojnik*(r1.nazivnik/r);
        b=r1.nazivnik*(r2.nazivnik/r);
        Razlomak rezultat(a,b);
        return rezultat;
    }
    friend Razlomak operator*(const Razlomak r1, const Razlomak r2) {
        long long int a,b;
        auto s=NZD(r1.brojnik, r2.nazivnik);
        auto t=NZD(r2.brojnik, r1.nazivnik);
        auto zamnozenje1=r1.brojnik/s, zamnozenje2=r2.brojnik/t, zamnozenje3=r1.nazivnik/t, zamnozenje4=r2.nazivnik/s;
        if(zamnozenje2>0 && (zamnozenje1<LLONG_MIN/zamnozenje2 || zamnozenje1>LLONG_MAX/zamnozenje2)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje2<0 && (zamnozenje1==LLONG_MIN || -zamnozenje1>LLONG_MAX/(-zamnozenje2) || -zamnozenje1<LLONG_MIN/(-zamnozenje2))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        if(zamnozenje4>0 && (zamnozenje3<LLONG_MIN/zamnozenje4 || zamnozenje3>LLONG_MAX/zamnozenje4)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje4<0 && (zamnozenje3==LLONG_MIN || -zamnozenje3>LLONG_MAX/(-zamnozenje4) || -zamnozenje3<LLONG_MIN/(-zamnozenje4))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        a=(r1.brojnik/s)*(r2.brojnik/t);
        b=(r1.nazivnik/t)*(r2.nazivnik/s);
        Razlomak rezultat(a,b);
        return rezultat;
    }
    friend Razlomak operator/(const Razlomak r1, const Razlomak r2) {
        auto r=NZD(r1.nazivnik, r2.nazivnik);
        auto u=NZD(r1.brojnik, r2.brojnik);
        long long int a,b;
        auto zamnozenje1=r1.brojnik/u, zamnozenje2=r2.nazivnik/r, zamnozenje3=r1.nazivnik/r, zamnozenje4=r2.brojnik/u;
        if(zamnozenje2>0 && (zamnozenje1<LLONG_MIN/zamnozenje2 || zamnozenje1>LLONG_MAX/zamnozenje2)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje2<0 && (zamnozenje1==LLONG_MIN || -zamnozenje1>LLONG_MAX/(-zamnozenje2) || -zamnozenje1<LLONG_MIN/(-zamnozenje2))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        if(zamnozenje4>0 && (zamnozenje3<LLONG_MIN/zamnozenje4 || zamnozenje3>LLONG_MAX/zamnozenje4)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje4<0 && (zamnozenje3==LLONG_MIN || -zamnozenje3>LLONG_MAX/(-zamnozenje4) || -zamnozenje3<LLONG_MIN/(-zamnozenje4))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        a=(r1.brojnik/u)*(r2.nazivnik/r);
        b=(r1.nazivnik/r)*(r2.brojnik/u);
        Razlomak rezultat(a,b);
        return rezultat;
    }
    friend Razlomak operator+=(Razlomak r1,  Razlomak r2) {
        auto r=NZD(r1.nazivnik, r2.nazivnik);
         auto zasabiranje1=r1.brojnik*(r2.nazivnik/r), zasabiranje2=r2.brojnik*(r1.nazivnik/r), zamnozenje1=r1.brojnik, zamnozenje2=r2.nazivnik/r, zamnozenje3=r2.brojnik, zamnozenje4=r1.nazivnik/r;
        auto zamnozenje5=r1.nazivnik, zamnozenje6=r2.nazivnik/r;
        if(zamnozenje2>0 && (zamnozenje1>LLONG_MAX/zamnozenje2 || zamnozenje1<LLONG_MIN/zamnozenje2)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje2<0 && (zamnozenje1==LLONG_MIN || -zamnozenje1>LLONG_MAX/(-zamnozenje2))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
         if(zamnozenje4>0 && (zamnozenje3>LLONG_MAX/zamnozenje4 || zamnozenje3<LLONG_MIN/zamnozenje4)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje4<0 && (zamnozenje3==LLONG_MIN || -zamnozenje3>LLONG_MAX/(-zamnozenje4))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
         if(zamnozenje6>0 && (zamnozenje5>LLONG_MAX/zamnozenje6 || zamnozenje5<LLONG_MIN/zamnozenje6)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje6<0 && (zamnozenje5==LLONG_MIN || -zamnozenje5>LLONG_MAX/(-zamnozenje6))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        if(zasabiranje2>0 && zasabiranje1>LLONG_MAX-zasabiranje2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zasabiranje2<0 && zasabiranje1<LLONG_MIN-zasabiranje2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        auto a=r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r);
        auto b=(r1.nazivnik*r2.nazivnik/r);
        Razlomak rezultat(a,b);
        return rezultat;
    }
    friend Razlomak operator-=(const Razlomak r1, const Razlomak r2) {
        auto r=NZD(r1.nazivnik, r2.nazivnik);
         auto zasabiranje1=r1.brojnik*(r2.nazivnik/r), zasabiranje2=r2.brojnik*(r1.nazivnik/r), zamnozenje1=r1.brojnik, zamnozenje2=r2.nazivnik/r, zamnozenje3=r2.brojnik, zamnozenje4=r1.nazivnik/r;
        auto zamnozenje5=r1.nazivnik, zamnozenje6=r2.nazivnik/r;
               if(zamnozenje2>0 && (zamnozenje1>LLONG_MAX/zamnozenje2 || zamnozenje1<LLONG_MIN/zamnozenje2)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje2<0 && (zamnozenje1==LLONG_MIN || -zamnozenje1>LLONG_MAX/(-zamnozenje2))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
         if(zamnozenje4>0 && (zamnozenje3>LLONG_MAX/zamnozenje4 || zamnozenje3<LLONG_MIN/zamnozenje4)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje4<0 && (zamnozenje3==LLONG_MIN || -zamnozenje3>LLONG_MAX/(-zamnozenje4))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
         if(zamnozenje6>0 && (zamnozenje5>LLONG_MAX/zamnozenje6 || zamnozenje5<LLONG_MIN/zamnozenje6)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje6<0 && (zamnozenje5==LLONG_MIN || -zamnozenje5>LLONG_MAX/(-zamnozenje6))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        if(zasabiranje2<0 && zasabiranje1>LLONG_MAX+zasabiranje2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zasabiranje2>0 && zasabiranje1<LLONG_MIN-zasabiranje2) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        auto a=r1.brojnik*(r2.nazivnik/r)-r2.brojnik*(r1.nazivnik/r);
        auto b=r1.nazivnik*r2.nazivnik/r;
        Razlomak rezultat(a,b);
        return rezultat;}
        friend Razlomak operator*=(const Razlomak r1, const Razlomak r2) {
              long long int a,b;
        auto s=NZD(r1.brojnik, r2.nazivnik);
        auto t=NZD(r2.brojnik, r1.nazivnik);
        auto zamnozenje1=r1.brojnik/s, zamnozenje2=r2.brojnik/t, zamnozenje3=r1.nazivnik/t, zamnozenje4=r2.nazivnik/s;
        if(zamnozenje2>0 && (zamnozenje1<LLONG_MIN/zamnozenje2 || zamnozenje1>LLONG_MAX/zamnozenje2)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje2<0 && (zamnozenje1==LLONG_MIN || -zamnozenje1>LLONG_MAX/(-zamnozenje2) || -zamnozenje1<LLONG_MIN/(-zamnozenje2))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        if(zamnozenje4>0 && (zamnozenje3<LLONG_MIN/zamnozenje4 || zamnozenje3>LLONG_MAX/zamnozenje4)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje4<0 && (zamnozenje3==LLONG_MIN || -zamnozenje3>LLONG_MAX/(-zamnozenje4) || -zamnozenje3<LLONG_MIN/(-zamnozenje4))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        a=(r1.brojnik/s)*(r2.brojnik/t);
        b=(r1.nazivnik/t)*(r2.nazivnik/s);
        Razlomak rezultat(a,b);
        return rezultat;
        }
        friend Razlomak operator/=(const Razlomak r1, const Razlomak r2) {
              auto r=NZD(r1.nazivnik, r2.nazivnik);
        auto u=NZD(r1.brojnik, r2.brojnik);
        long long int a,b;
        auto zamnozenje1=r1.brojnik/u, zamnozenje2=r2.nazivnik/r, zamnozenje3=r1.nazivnik/r, zamnozenje4=r2.brojnik/u;
        if(zamnozenje2>0 && (zamnozenje1<LLONG_MIN/zamnozenje2 || zamnozenje1>LLONG_MAX/zamnozenje2)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje2<0 && (zamnozenje1==LLONG_MIN || -zamnozenje1>LLONG_MAX/(-zamnozenje2) || -zamnozenje1<LLONG_MIN/(-zamnozenje2))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        if(zamnozenje4>0 && (zamnozenje3<LLONG_MIN/zamnozenje4 || zamnozenje3>LLONG_MAX/zamnozenje4)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        else if(zamnozenje4<0 && (zamnozenje3==LLONG_MIN || -zamnozenje3>LLONG_MAX/(-zamnozenje4) || -zamnozenje3<LLONG_MIN/(-zamnozenje4))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        a=(r1.brojnik/u)*(r2.nazivnik/r);
        b=(r1.nazivnik/r)*(r2.brojnik/u);
        Razlomak rezultat(a,b);
        return rezultat;
        }
    friend Razlomak operator-(const Razlomak r) {
        if(r.DajBrojnik()==LLONG_MIN) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        return {-r.DajBrojnik(), r.DajNazivnik()};
    }
    friend Razlomak operator+(const Razlomak r) {
        return {r.DajBrojnik(), r.DajNazivnik()};
    }
    friend bool operator<(const Razlomak r1, const Razlomak r2) {
        long double a=(long double)r1.DajBrojnik()/r1.DajNazivnik();
        long double b=(long double)r2.DajBrojnik()/r2.DajNazivnik();
        return a<b;
    }
    friend bool operator>(const Razlomak r1, const Razlomak r2) {
        long double a=(long double)r1.DajBrojnik()/r1.DajNazivnik();
        long double b=(long double)r2.DajBrojnik()/r2.DajNazivnik();
        return a>b;
    }
    friend bool operator >=(const Razlomak r1, const Razlomak r2) {
        long double a=(long double)r1.DajBrojnik()/r1.DajNazivnik();
        long double b=(long double)r2.DajBrojnik()/r2.DajNazivnik();
        return a>=b;
    }
    friend bool operator<=(const Razlomak r1, const Razlomak r2) {
        long double a=(long double)r1.DajBrojnik()/r1.DajNazivnik();
        long double b=(long double)r2.DajBrojnik()/r2.DajNazivnik();
        return a<=b;
    }
    friend bool operator==(const Razlomak r1, const Razlomak r2) {
        long double a=(long double)r1.DajBrojnik()/r1.DajNazivnik();
        long double b=(long double)r2.DajBrojnik()/r2.DajNazivnik();
        return fabs(a-b)<1e-10;
    }
    friend bool operator!=(const Razlomak r1, const Razlomak r2) {
        long double a=(long double)r1.DajBrojnik()/r1.DajNazivnik();
        long double b=(long double)r2.DajBrojnik()/r2.DajNazivnik();
        return fabs(a-b)>1e-10;
    }
    friend std::ostream &operator<<(std::ostream &tok, Razlomak r) {
        tok<<r.DajBrojnik();
        if(r.DajNazivnik()!=1) tok<<"/"<<r.DajNazivnik();
        return tok;
    }
    friend std::istream &operator>>(std::istream &tok, Razlomak &r){
        long long int a, b;
        char znak;
        tok>>std::ws;
        if(!tok) tok.ignore(1000);
        tok>>a;
        if(tok && tok.peek()=='\n') r=Razlomak(a);
        else if(tok.peek()!='\n'){
            tok>>znak;
            if(znak=='/') {tok>>b;
            if(tok.peek()<13){
            r=Razlomak(a,b);}
            
                else tok.setstate(std::ios::failbit);}
            else tok.setstate(std::ios::failbit);
        } else tok.setstate(std::ios::failbit);
        return tok; 
    }
};

  long long int Razlomak::NZD(long long int p, long long int q) {
      if(p==LLONG_MIN && q==LLONG_MIN) return LLONG_MIN;
      if(p<0 && p!=LLONG_MIN) p*=-1;
      if(q<0 && q!=LLONG_MIN) q*=-1;
      if(p==0) return q;
     auto manji(p);
     if(p>q) manji=q;
     for(auto i=manji; i>=1; i--) {
         if(p%i==0 && q%i==0) {
             return i;
         }
}
     return 1;
}

int main ()
{
     
	return 0;
}
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <sstream>
class Razlomak {
    long long int brojnik;
    long long int nazivnik;
   static long long int NZD(long long int brojnik, long long int nazivnik) {
       long long int nzd(1);
       for(int i(2);i<=brojnik;i++) {
           if(brojnik%i==0 && nazivnik%i==0)
           nzd=i;
       }
       return nzd; 
 }
    public:
    
     Razlomak(long long int brojnik) {
        this->brojnik=brojnik;
        nazivnik=1;
    }
     Razlomak() {
        brojnik=0;
        nazivnik=1;
    }
     Razlomak(long long int brojnik, long long int nazivnik);
    long long int DajBrojnik() const {return brojnik;};
    long long int DajNazivnik() const {return nazivnik;};
    friend Razlomak operator+(const Razlomak &r1, const Razlomak &r2) ; //gotovo
    friend Razlomak operator-(const Razlomak &r1, const Razlomak &r2) ;
    friend Razlomak operator*(const Razlomak &r1, const Razlomak &r2) ;
    friend Razlomak operator/(const Razlomak&r1, const Razlomak &r2) ;
    friend Razlomak operator +(Razlomak &r) {
        return r;
    }
    friend Razlomak operator -(Razlomak &r) {
        r.brojnik=-1*r.brojnik;
        return r;
    }
    friend Razlomak & operator+=( Razlomak &r1, const Razlomak &r2) {
         return r1=r1+r2;
    }
   friend Razlomak & operator-=( Razlomak &r1, const Razlomak &r2) {
         return r1=r1-r2;
    }
    friend Razlomak & operator*=( Razlomak &r1, const Razlomak &r2) {
         return r1=r1*r2;
    }
    friend Razlomak & operator/=( Razlomak &r1, const Razlomak &r2) {
         return r1=r1/r2;
    }
   friend Razlomak & operator++(Razlomak &r) {
      
       return r+=1;
   }
   friend Razlomak & operator--(Razlomak &r) {
      
       return r-=1;
   }///////////gtoootovoo
   friend Razlomak operator++(Razlomak &r,int) ;
   friend Razlomak operator--(Razlomak &r,int) ;
   
   friend bool operator <(const Razlomak &r1, const Razlomak &r2);
   friend bool operator >(const Razlomak &r1, const Razlomak &r2) ;
   friend bool operator ==(const Razlomak &r1, const Razlomak &r2) ;
   friend bool operator !=(const Razlomak &r1, const Razlomak &r2) ;
       
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r) ;
    
    friend std::istream & operator>>(std::istream &tok, Razlomak &r) ;
    operator long double const() ;
};
Razlomak::Razlomak(long long int brojnik, long long int nazivnik) {
        if(nazivnik==0) throw std::logic_error ("Nekorektan razlomak");
        if(NZD(brojnik,nazivnik)!=1) {
            long long int p=NZD(brojnik,nazivnik);
            brojnik/=p;
            nazivnik/=p;
            
        }
        if(brojnik<0 && nazivnik<0) {
            brojnik=abs(brojnik);
            nazivnik=abs(nazivnik);
        }
        if(brojnik>0 && nazivnik<0) {
            brojnik=-1*brojnik;
            nazivnik=abs(nazivnik);
        }
    
    this->brojnik=brojnik;
    this->nazivnik=nazivnik;
    }
Razlomak operator+(const Razlomak &r1, const Razlomak &r2) {
        // provjeriti da nece doci do prekoracenja i baciti izuzetak
        long long int r=Razlomak::NZD(r1.nazivnik, r2.nazivnik);
        Razlomak pomocni{r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r), (r1.nazivnik*r2.nazivnik/r)};
        return pomocni;
    }    
Razlomak operator-(const Razlomak &r1, const Razlomak &r2) {
        // provjeriti da nece doci do prekoracenja i baciti izuzetak
        long long int r=Razlomak::NZD(r1.nazivnik, r2.nazivnik);
       
        Razlomak pomocni{r1.brojnik*(r2.nazivnik/r)-r2.brojnik*(r1.nazivnik/r), r1.nazivnik*(r2.nazivnik/r)};
        return pomocni;
    }
Razlomak operator*(const Razlomak &r1, const Razlomak &r2) {
        // provjeriti da nece doci do prekoracenja i baciti izuzetak
        long long int s=Razlomak::NZD(r1.brojnik, r2.nazivnik);
        long long int t=Razlomak::NZD(r2.brojnik,r1.nazivnik);
        Razlomak pomocni {(r1.brojnik/s)*(r2.brojnik/t), (r1.nazivnik/t)*(r2.nazivnik/s)};
        return pomocni;
        
    }
Razlomak operator/(const Razlomak&r1, const Razlomak &r2) {
      // provjeriti da nece doci do prekoracenja i baciti izuzetak
        long long int u=Razlomak::NZD(r1.brojnik,r2.brojnik);
        long long int r=Razlomak::NZD(r1.nazivnik, r2.nazivnik);
        Razlomak pomocni {(r1.brojnik/u)*(r2.nazivnik/r), (r1.nazivnik/r)*(r2.brojnik/u)};
        return pomocni;
}
Razlomak operator++(Razlomak &r,int) {
       Razlomak pomocni=r;
       r+=1;
       return pomocni;
   }
Razlomak operator--(Razlomak &r,int) {
       Razlomak pomocni=r;
       r-=1;
       return pomocni;
   }
 bool operator<(const Razlomak &r1, const Razlomak &r2) {
       long double x1=(r1.brojnik/r1.nazivnik);
       long double x2=(r2.brojnik/r2.nazivnik);
       if(x1<x2) return true;
       return false;
   }
  bool operator>(const Razlomak &r1, const Razlomak &r2) {
       long double x1=(r1.brojnik/r1.nazivnik);
       long double x2=(r2.brojnik/r2.nazivnik);
       if(x1>x2) return true;
       return false;
   }
    bool operator ==(const Razlomak &r1, const Razlomak &r2) {
       long double x1=(r1.brojnik/r1.nazivnik);
       long double x2=(r2.brojnik/r2.nazivnik);
       if(x1==x2) return true;
       return false;
   }
    bool operator !=(const Razlomak &r1, const Razlomak &r2) {
       long double x1=(r1.brojnik/r1.nazivnik);
       long double x2=(r2.brojnik/r2.nazivnik);
        return !(x1==x2);
      }
     std::ostream &operator <<(std::ostream &tok, const Razlomak &r) {
        if(r.nazivnik==1) return tok<<r.brojnik;
        return tok<<r.brojnik<<"/"<<r.nazivnik;
    }
     std::istream & operator>>(std::istream &tok, Razlomak &r) {
        tok>>std::ws;
        char znak;
       tok.clear();
       g:  tok>>r.brojnik>>znak;
        if(znak=='/')  {
            char znak1;
            tok>>r.nazivnik>>znak1;
          //  std::cout<<"USAO"<<std::endl;
            if(znak1!=' ' || znak1!='\n'|| znak1!='\r' ||  znak1!='\f' || znak1!='\v' || znak1!='\t')  tok.setstate(std::ios::failbit);
            if(znak==' ') goto g;
            //else {
                if(Razlomak::NZD(r.brojnik,r.nazivnik)!=1)  {
                    long long int pom=Razlomak::NZD(r.brojnik,r.nazivnik);
                    r.brojnik/=pom;
                    r.nazivnik/=pom;
               }
               // return tok;}
        }
        else if(znak=='\n'|| znak=='\r' ||  znak=='\f' || znak=='\v' || znak=='\t' || znak==' ' || znak=='\0') {
             r.nazivnik=1;
            // if(znak==' ')
             //std::cout << r.nazivnik<<"'''''''''" << std::endl;
            // goto g;
           // tok>>r.brojnik>>znak;
           
        }
        else  tok.setstate(std::ios::failbit);
        return tok;
 }
 Razlomak::operator long double const() {
        brojnik=static_cast<long double>(brojnik);
        nazivnik=static_cast<long double> (nazivnik);
        long double x=brojnik*(1./nazivnik);
        return x;
    }
int main ()
{
    
    Razlomak r, q, t;
     std::istringstream is ("10/20"); //ne mora sa \n zavrsiti
     is >> r;
     std::cout << r << std::endl;

     is.str ("173"); //samo jedan broj, 173/1
     is.clear(); //mora, radi EOF
     is >> r;
     std::cout << r << std::endl;

     is.str ("               173/50"); //ispravno, razmaci prije
     is.clear();
     is >> r;
     std::cout << r << std::endl;

     is.str ("               173/50       "); //ispravno, razmaci prije, poslije
     is.clear();
     is >> r;
     std::cout << r << std::endl;


     is.str ("173/51\n  ne zanima nas sta je nakon     "); //ispravno
     is.clear();
     is >> r; //sljedece citanje bi bilo neispravno
     std::cout << r << std::endl;

     is.str ("17/33e ali je vazno da nakon razlomka ide BJELINA"); //neispravno
     is.clear();
     is >> r;
     if (is.fail()) std::cout << "OK, neispravno!" << std::endl;
     else std::cout << "Nije OK! Ovo nije ispravan unos!" << std::endl;

     //nije ispravno ni npr. 10b/20, ni 10/ 20 ni a20/5
     //necu sve testirati (barem ne u javnim :troll:)

     is.str ("a17/33"); //neispravno
     is.clear();
     is >> r;
     if (is.fail()) std::cout << "OK, neispravno!" << std::endl;
     else std::cout << "Nije OK! Ovo nije ispravan unos!" << std::endl;

     std::cout << "VEOMA VAZNO: " << std::endl;
     //treba biti MOGUCE unijeti vise razlomaka odjednom! (pazite na std::ws)
     is.str (" 1/3   5/7  4/2    nebitno"); //ispravna prva 3
     is.clear();
     is >> r >> q >> t;
     std::cout << "r = " << r << ", q = " << q << ", t = " << t;

    return 0;
}
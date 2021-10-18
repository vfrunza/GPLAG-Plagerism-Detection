#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <new>
#include <stdexcept>
#include <utility>
#include <memory>
#include <cmath>
#include <initializer_list>
#include <sstream>

const double eps(1e-16);
class Razlomak {
    long long int brojnik,nazivnik;
   static int DajNZD(int broj,int drugi) {
        if(drugi==0) return broj;
   return DajNZD(drugi,broj%drugi);
    } 
    public:
    Razlomak(long long int broj=0,long long int drugi=1);
     long long int &DajBrojnik() {
        return brojnik;
    }
    long long int &DajNazivnik() {
        return nazivnik;
    }
    Razlomak (std::initializer_list<long long int> lista) {
        auto it(lista.begin());
         brojnik=*it;
         it++;
         nazivnik=*it;
    }
Razlomak  operator +(Razlomak &razlomak) {
    Razlomak rezultat;
    int nzd(Razlomak::DajNZD(this->nazivnik,razlomak.DajNazivnik()));
    rezultat.DajNazivnik()=this->nazivnik*(razlomak.DajNazivnik()/nzd);
  rezultat.DajBrojnik()=this->brojnik*(razlomak.DajNazivnik()/nzd)+razlomak.DajBrojnik()*(this->nazivnik/nzd);
    return Razlomak(rezultat.DajBrojnik(),rezultat.DajNazivnik());
}
Razlomak operator -(Razlomak razlomak);
Razlomak operator /(Razlomak razlomak);
Razlomak operator *(Razlomak &razlomak);
Razlomak operator +();
Razlomak operator -();
Razlomak operator +=(Razlomak &razlomak);
Razlomak operator -=(Razlomak &razlomak);
Razlomak operator  *=(Razlomak &razlomak);
Razlomak operator /=(Razlomak &razlomak);
Razlomak operator ++();
 friend Razlomak operator ++(Razlomak &razlomak, int);
  Razlomak operator --();
 friend Razlomak operator --(Razlomak &razlomak, int);
 Razlomak operator =(Razlomak kolicnik);
 friend std::ostream &operator<<(std::ostream &tok,Razlomak razlomak);
 friend std::istream &operator>>(std::istream &tok,Razlomak &razlomak);
bool operator<(Razlomak &razlomak);
bool operator>(Razlomak &razlomak);
bool operator<=(Razlomak &razlomak);
bool operator>=(Razlomak &razlomak);
bool operator==(Razlomak razlomak);
bool operator!=(Razlomak &razlomak);
  operator long double() const {
      long double prvi,drugi;
      prvi=this->brojnik;
      drugi=this->nazivnik;
 return prvi/drugi;      
  }
};

 Razlomak::Razlomak(long long int broj,long long int drugi) {
        if(drugi==0) throw std::logic_error("Nekorektan razlomak");
        if(broj>drugi) {
            long long int b1,b2;
            b1=std::abs(broj);
            b2=std::abs(drugi);
            for(int i=2;i<=b2;i++) {
                if(b1%i==0 && b2%i==0) {
                    b1/=i;
                    b2/=i;
                    i--;
                }
            }
            if(b1<0 && b2<0) {
                brojnik=b1;
                this->nazivnik=b2;
            }
            else {
                if(b1<0 && b2>0) {
                    brojnik=-b1;
                    this->nazivnik=b2;
                }
                else {
                    if(b1>0 && b2<0) {
                        brojnik=-b1;
                        this->nazivnik=b2;
                    }
                    else {
                        brojnik=b1;
                       this->nazivnik=b2;
                    }
                }
            }
        }
        else {
            long long int b3,b4;
            b3=std::abs(broj);
            b4=std::abs(drugi);
            for(int j=2;j<=b3;j++) {
                if(b3%j==0 && b4%j==0) {
                    b3/=j;
                    b4/=j;
                    j--;
                }
            }
                  if(b3<0 && b4<0) {
                brojnik=b3;
                this->nazivnik=b4;
            }
            else {
                if(b3<0 &&  b4>0) {
                    brojnik=-b3;
                    this->nazivnik=b4;
                }
                else {
                    if(b3>0 && b4<0) {
                        brojnik=-b3;
                        this->nazivnik=b4;
                    }
                    else {
                        brojnik=b3;
                        this->nazivnik=b4;
                    }
                }
            }
        }
    }
    Razlomak Razlomak::operator -(Razlomak razlomak)  {
        Razlomak rezultat;
         int nzd(Razlomak::DajNZD(this->nazivnik,razlomak.DajNazivnik()));
    rezultat.DajNazivnik()=this->nazivnik*(razlomak.DajNazivnik()/nzd);
  rezultat.DajBrojnik()=this->brojnik*(razlomak.DajNazivnik()/nzd)-razlomak.DajBrojnik()*(this->nazivnik/nzd);
    return rezultat;
    }
Razlomak Razlomak::operator *(Razlomak &razlomak) {
    Razlomak rezultat;
    
    int nzd(Razlomak::DajNZD(this->brojnik,razlomak.DajNazivnik()));
    int nzd2(Razlomak::DajNZD(this->nazivnik,razlomak.DajBrojnik()));
    rezultat.DajNazivnik()=(this->nazivnik/nzd2)*(razlomak.DajNazivnik()/nzd);
    rezultat.DajBrojnik()=(this->brojnik/nzd)*(razlomak.DajBrojnik()/nzd2);
    return rezultat;
}
Razlomak Razlomak::operator /(Razlomak razlomak) {
    Razlomak rezultat;
    int nzd(Razlomak::DajNZD(this->nazivnik,razlomak.DajNazivnik()));
    int drugi(Razlomak::DajNZD(this->brojnik,razlomak.DajBrojnik()));
    rezultat.DajBrojnik()=(this->brojnik/drugi)*(razlomak.DajNazivnik()/nzd);
    rezultat.DajNazivnik()=(this->nazivnik/nzd)*(razlomak.DajBrojnik()/drugi);
    return rezultat;
}
Razlomak Razlomak::operator+() {
    return *this;
}
Razlomak Razlomak::operator -() {
    return -(*this);
}
Razlomak Razlomak::operator +=(Razlomak &razlomak) {
    Razlomak rezultat;
    int nzd(Razlomak::DajNZD(this->nazivnik,razlomak.DajNazivnik()));
    rezultat.DajNazivnik()+=this->nazivnik*(razlomak.DajNazivnik()/nzd);
  rezultat.DajBrojnik()+=this->brojnik*(razlomak.DajNazivnik()/nzd)+razlomak.DajBrojnik()*(this->nazivnik/nzd);
    return rezultat;
}

Razlomak Razlomak::operator -=(Razlomak &razlomak) {
     Razlomak rezultat;
    int nzd(Razlomak::DajNZD(this->nazivnik,razlomak.DajNazivnik()));
    rezultat.DajNazivnik()-=this->nazivnik*(razlomak.DajNazivnik()/nzd);
  rezultat.DajBrojnik()-=this->brojnik*(razlomak.DajNazivnik()/nzd)+razlomak.DajBrojnik()*(this->nazivnik/nzd);
    return rezultat;
}
Razlomak Razlomak::operator *=(Razlomak &razlomak) {
    Razlomak rezultat;
     int nzd(Razlomak::DajNZD(this->brojnik,razlomak.DajNazivnik()));
    int nzd2(Razlomak::DajNZD(this->nazivnik,razlomak.DajBrojnik()));
    rezultat.DajNazivnik()*=(this->nazivnik/nzd2)*(razlomak.DajNazivnik()/nzd);
    rezultat.DajBrojnik()*=(this->brojnik/nzd)*(razlomak.DajBrojnik()/nzd2);
    return rezultat;
}
Razlomak Razlomak::operator /=(Razlomak &razlomak) {
     Razlomak rezultat;
    int nzd(Razlomak::DajNZD(this->nazivnik,razlomak.DajNazivnik()));
    int drugi(Razlomak::DajNZD(this->brojnik,razlomak.DajBrojnik()));
    rezultat.DajBrojnik()/=(this->brojnik/drugi)*(razlomak.DajNazivnik()/nzd);
    rezultat.DajNazivnik()/=(this->nazivnik/nzd)*(razlomak.DajBrojnik()/drugi);
    return rezultat;
}
Razlomak Razlomak::operator ++() {
    this->brojnik=this->brojnik+this->nazivnik;
    return *this;
}
Razlomak operator ++(Razlomak &razlomak,int) {
    Razlomak kolicnik;
    kolicnik.DajBrojnik()=razlomak.DajBrojnik();
    kolicnik.DajNazivnik()=razlomak.DajNazivnik();
    razlomak.DajBrojnik()=razlomak.DajBrojnik()+razlomak.DajNazivnik();
    return kolicnik;
}
Razlomak Razlomak::operator --() {
    this->brojnik=this->brojnik-this->nazivnik;
    return *this;
}
Razlomak operator --(Razlomak &razlomak,int) {
    Razlomak kolicnik;
    kolicnik.DajBrojnik()=razlomak.DajBrojnik();
    kolicnik.DajNazivnik()=razlomak.DajNazivnik();
    razlomak.DajBrojnik()=razlomak.DajBrojnik()-razlomak.DajNazivnik();
    return razlomak;
}
Razlomak Razlomak::operator =(Razlomak kolicnik) {
    Razlomak pomocni(kolicnik.DajBrojnik(),kolicnik.DajNazivnik());
    this->DajBrojnik()=pomocni.DajBrojnik();
    this->DajNazivnik()=pomocni.DajNazivnik();
    return *this;
}

bool Razlomak::operator <(Razlomak &razlomak) {
  long  double prvi,drugi;
  prvi=this->brojnik/this->nazivnik;
  drugi=razlomak.DajBrojnik()/razlomak.DajNazivnik();
  return drugi-prvi>std::fabs(eps);
}
bool Razlomak::operator >(Razlomak &razlomak) {
    long  double prvi,drugi;
    prvi=this->brojnik/this->nazivnik;
    drugi=razlomak.DajBrojnik()/razlomak.DajNazivnik();
    return prvi-drugi>std::fabs(eps);
}
bool Razlomak::operator >=(Razlomak &razlomak) {
    double prvi,drugi;
    prvi=this->brojnik/this->nazivnik;
    drugi=razlomak.DajBrojnik()/razlomak.DajNazivnik();
    return prvi-drugi>=std::fabs(eps);
}
bool Razlomak::operator <=(Razlomak &razlomak) {
    double prvi,drugi;
    prvi=this->brojnik/this->nazivnik;
    drugi=razlomak.DajBrojnik()/razlomak.DajNazivnik();
    return drugi-prvi<=std::fabs(eps);
}
bool Razlomak::operator ==(Razlomak razlomak) {
    return this->brojnik-razlomak.DajBrojnik()<=std::fabs(eps);
}
bool Razlomak::operator !=(Razlomak &razlomak) {
    return !(*this==razlomak);
}
std::istream &operator>>(std::istream &tok,Razlomak &razlomak)  {
    int broj1(0),broj2(0);
    char znak;
    tok>>std::ws;
   tok>>broj1;
   razlomak.DajBrojnik()=broj1;
    if(tok.peek()!='/') {
  razlomak.DajNazivnik()=1;
  return tok;
    }
    else {
        tok>>znak;
          tok>>broj2;
              razlomak.nazivnik=broj2;
              if(tok.peek()!=' ' &&  tok.peek()!='\n' && tok.peek()!='\v' && tok.peek()!='\f' && tok.peek()!='\r' && tok.peek()!='\t')  tok.setstate(std::ios::failbit);
              auto pomoc=razlomak.DajBrojnik();
              razlomak.DajBrojnik()/=Razlomak::DajNZD(razlomak.DajBrojnik(),razlomak.DajNazivnik());
              razlomak.DajNazivnik()/=Razlomak::DajNZD(pomoc,razlomak.DajNazivnik());
          return tok;
  }
}
std::ostream &operator <<(std::ostream &tok,Razlomak razlomak) {
    if(razlomak.DajNazivnik()==1) {
        tok<<razlomak.DajBrojnik();
    }
    else {
    Razlomak pomocni(razlomak.DajBrojnik(),razlomak.DajNazivnik());
    if(pomocni.DajNazivnik()==1) {
        tok<<pomocni.DajBrojnik();
    }
    else 
    tok<<pomocni.DajBrojnik()<<"/"<<pomocni.DajNazivnik();
    }
    return tok;
}
int main ()
{
    std::cout<<"unesite sta hocete ";
    
	return 0;
}
/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <initializer_list>
using std::cin;
using std::cout;
using std::endl;

#include <sstream>
class Razlomak{
  long long int brojnik;
  long long int nazivnik;
  static long long int NZD(long long int prvi,long long int drugi){
      
      if(drugi==0){return prvi;}
      return NZD(drugi,prvi%drugi);
  }
    public:
    
    Razlomak (long long int brojni=0,long long int nazivni=1);
    Razlomak (std::initializer_list<long long int> li);
    Razlomak(const Razlomak &a);
    Razlomak(Razlomak &&a);
    Razlomak &operator =(const Razlomak &a);
    Razlomak &operator =(Razlomak &&a);
    long long int DajBrojnik()const{
        return brojnik;
    }
    long long int DajNazivnik()const{
        return nazivnik;
    }
    friend Razlomak operator +(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator -(const Razlomak &a, const Razlomak &b);
    friend std::ostream &operator <<(std::ostream &tok,const Razlomak &a);
    friend std::istream &operator >>(std::istream &tok,const Razlomak &a);
    friend Razlomak operator *(const Razlomak &a,const Razlomak &b);
    friend Razlomak operator /(const Razlomak &a,const Razlomak &b);
    operator long double(){
    return Razlomak::brojnik/static_cast<long double>(Razlomak::nazivnik);
}
    Razlomak &operator -();
    Razlomak &operator +();
    Razlomak &operator +=(const Razlomak &a);
    Razlomak &operator -=(const Razlomak &a);
    Razlomak &operator *=(const Razlomak &a);
    Razlomak &operator /=(const Razlomak &a);
    friend bool operator  <(Razlomak a, Razlomak b);
    friend bool operator  >(Razlomak a, Razlomak b);
    friend bool operator <=(Razlomak a, Razlomak b);
    friend bool operator >=(Razlomak a, Razlomak b);
    friend bool operator ==( Razlomak a, Razlomak b);
    friend bool operator !=(Razlomak a,Razlomak b);
    Razlomak &operator ++();
    Razlomak operator ++(int);
    Razlomak &operator --();
    Razlomak operator --(int);
};

Razlomak::Razlomak (std::initializer_list<long long int> li){
        if(li.size()==0) {nazivnik=1;brojnik=0;}
        else if(li.size()==1){nazivnik=1;brojnik=*(li.begin());}
        else if(li.size()==2){
        long long int brojni(*(li.begin()));
        auto it(li.begin());it++;
        long long int nazivni(*it);
        if(nazivni==0) throw std::logic_error("Nekorektan razlomak");
        long long int nzd(NZD(brojni,nazivni));
        brojni=brojni/nzd;
        nazivni=nazivni/nzd;
        if(nazivni<0 && brojni>0){brojnik=-brojni;nazivnik=-nazivni;}
        else if(nazivni<0 && brojni<0){brojnik=-brojni;nazivnik=-nazivni;}
        else{
            brojnik=brojni;
            nazivnik=nazivni;
        }
            
        }
    }
Razlomak::Razlomak (long long int brojni,long long int nazivni):brojnik(brojni),nazivnik(nazivni){
        if(nazivnik==0) throw std::logic_error("Nekorektan razlomak");
        long long int nzd(NZD(brojni,nazivni));
        brojni=brojni/nzd;
        nazivni=nazivni/nzd;
        if(nazivni<0 && brojni>0){brojnik=-brojni;nazivnik=-nazivni;}
        else if(nazivni<0 && brojni<0){brojnik=-brojni;nazivnik=-nazivni;}
        else{
            brojnik=brojni;
            nazivnik=nazivni;
        }
    }
Razlomak::Razlomak(const Razlomak &a){
    brojnik=a.brojnik;
    nazivnik=a.nazivnik;
}
Razlomak::Razlomak(Razlomak &&a){
    brojnik=a.brojnik;
    nazivnik=a.nazivnik;
}
Razlomak &Razlomak::operator =(const Razlomak &a){
    brojnik=a.brojnik;
    nazivnik=a.nazivnik;
    return *this;
}
Razlomak &Razlomak::operator =(Razlomak &&a){
    brojnik=a.brojnik;
    nazivnik=a.nazivnik;
    return *this;
}
Razlomak operator +(const Razlomak &a, const Razlomak &b){
    long long int r(Razlomak::NZD(a.nazivnik,b.nazivnik));
    Razlomak c(a.brojnik*(b.nazivnik/r)+b.brojnik*(a.nazivnik/r),a.nazivnik*(b.nazivnik/r));
    return c;
}
Razlomak operator -(const Razlomak &a, const Razlomak &b){
    long long int r(Razlomak::NZD(a.nazivnik,b.nazivnik));
    Razlomak c(a.brojnik*(b.nazivnik/r)-b.brojnik*(a.nazivnik/r),a.nazivnik*(b.nazivnik/r));
    return c;
}
std::ostream &operator <<(std::ostream &tok,const Razlomak &a){
    if(a.brojnik==0 || a.nazivnik==1) tok<<a.brojnik;
    else{
        tok<<a.brojnik<<"/"<<a.nazivnik;
    }
    return tok;
}
std::istream &operator >>(std::istream &tok, Razlomak &a){
    tok>>std::ws;
    long long int brojnik,nazivnik;
    tok>>brojnik;
    if(cin.peek()=='\n' || cin.peek()==' '){
        Razlomak c(brojnik);
        a=c;
    }else if(cin.peek()=='/'){
        char znak;
        znak=cin.get();
        tok>>nazivnik;

        Razlomak c(brojnik,nazivnik);
        a=c;
        if(cin.peek()!=' '||cin.peek()!='\n') tok.setstate(std::ios::failbit);
    }
    return tok;
}
Razlomak operator *(const Razlomak &a,const Razlomak &b){
    return {(a.brojnik/Razlomak::NZD(a.brojnik,b.nazivnik))*(b.brojnik/Razlomak::NZD(b.brojnik,a.nazivnik)),(a.nazivnik/Razlomak::NZD(b.brojnik,a.nazivnik))*(b.nazivnik/Razlomak::NZD(a.brojnik,b.nazivnik))};
    
}
Razlomak operator /(const Razlomak &a,const Razlomak &b){
    long long int r(Razlomak::NZD(a.nazivnik,b.nazivnik)),u(Razlomak::NZD(a.brojnik,b.brojnik));
    return {(a.brojnik/u)*(b.nazivnik/r),(a.nazivnik/r)*(b.brojnik/u)};
}
Razlomak &Razlomak::operator -(){
    brojnik=-brojnik;
    return *this;
}
Razlomak &Razlomak::operator +(){
    return *this;
}
Razlomak &Razlomak::operator +=(const Razlomak &a){
    return *this=*this+a;
    
}
Razlomak &Razlomak::operator *=(const Razlomak &a){
    return *this=*this*a;
    
}
Razlomak &Razlomak::operator -=(const Razlomak &a){
    return *this=*this-a;
    
}
Razlomak &Razlomak::operator /=(const Razlomak &a){
    return *this=*this/a;
    
}
Razlomak &Razlomak::operator ++(){
    brojnik=brojnik+nazivnik;
    return *this;
}
Razlomak Razlomak::operator ++(int){
    Razlomak pomocni(brojnik,nazivnik);
    brojnik=brojnik+nazivnik;
    return pomocni;
}
Razlomak Razlomak::operator --(int){
    Razlomak pomocni(brojnik,nazivnik);
    brojnik=brojnik-nazivnik;
    return pomocni;
}
Razlomak &Razlomak::operator --(){
    brojnik=brojnik-nazivnik;
    return *this;
}
bool operator < ( Razlomak a, Razlomak b){
    return static_cast<long double>(a) < static_cast<long double>(b);
}
bool operator > ( Razlomak a, Razlomak b){
    return static_cast<long double>(a)>static_cast<long double>(b);
}
bool operator <=( Razlomak a, Razlomak b){
   return static_cast<long double>(a)<=static_cast<long double>(b);
}
bool operator >=( Razlomak a, Razlomak b){
    return static_cast<long double>(a)>=static_cast<long double>(b);
}
bool operator ==(Razlomak a,Razlomak b){
    return (static_cast<long double>(a))==(static_cast<long double>(b));
}
bool operator !=( Razlomak a, Razlomak b){
  return static_cast<long double>(a)!=static_cast<long double>(b);
}

int main ()
{
Razlomak r,p;
        cout<<"Unesite prvi razlomak kao a/b: "<<endl;
        cin>>r;
        cout<<"Unesite drugi razlomak kao brojnik i nazivnik: "<<endl;
        cin.ignore(1000,'\n');
        cin.clear();
        long long int a,b;
        cin>>a>>b;
        Razlomak q(a,b);
        cout<<"Unesite treci razlomka kao a/b: "<<endl;
        cin>>p;
        cout<<"Zbir ova dva razlomka je "<<q+r<<" a proizvod je "<<q*r<<endl;
        if(p>q) cout<<"Treci razlomak je veci od drugo."<<endl;
        cout<<"Razlmoci nakon povecanja sa ++ glase: ";
        cout<<r++<<endl;
        cout<<q++<<endl;
        cout<<p++<<endl;
	return 0;
}
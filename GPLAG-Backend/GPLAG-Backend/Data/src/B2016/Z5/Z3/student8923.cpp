/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>
using std::numeric_limits;
using std::cin;
using std::cout;
bool JesuLiIsti(long double x,long double y,double eps=1e-10)
{
    return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));
}
class Razlomak
{
    private:
    long long int brojnik,nazivnik;
    static long long int NZD(long long int brojn,long long int nazivn);
    static bool ZbirPrekoracenje(long long int a,long long int b);
    static bool RazlikaPrekoracenje(long long int a,long long int b);
    static bool ProizvodPrekoracenje(long long int a,long long int b);
    public:
    Razlomak(long long int brojn=0,long long int nazivn=1);
    long long int DajBrojnik() const {return brojnik;}
    long long int DajNazivnik() const {return nazivnik;}
    operator long double() const{long double pom((long double)(brojnik)/nazivnik); return pom;}
    Razlomak &operator +=(const Razlomak &a){return (*this=*this+a);}
    Razlomak &operator -=(const Razlomak &a){return (*this=*this-a);}
    Razlomak &operator *=(const Razlomak &a){return (*this=*this*a);}
    Razlomak &operator /=(const Razlomak &a){return (*this=*this/a);}
    Razlomak &operator ++();
    Razlomak operator ++(int);
    Razlomak &operator --();
    Razlomak operator --(int);
    friend Razlomak operator +(const Razlomak &a){return a;}
    friend Razlomak operator -(const Razlomak &a){Razlomak b((-a.brojnik)/a.nazivnik); return b;}
    friend Razlomak operator +(const Razlomak &a,const Razlomak &b);
    friend Razlomak operator -(const Razlomak &a,const Razlomak &b);
    friend Razlomak operator *(const Razlomak &a,const Razlomak &b);
    friend Razlomak operator /(const Razlomak &a,const Razlomak &b);
    friend bool operator ==(const Razlomak &a, const Razlomak &b) {long double pom1,pom2; pom1=(long double)(a.brojnik)/a.nazivnik; pom2=(long double)(b.brojnik)/b.nazivnik; if(JesuLiIsti(pom1,pom2)) return true; return false;}
    friend bool operator !=(const Razlomak &a,const Razlomak &b) {return (!(a==b));}
    friend bool operator >(const Razlomak &a,const Razlomak &b){return (((long double)(a.brojnik)/a.nazivnik)>(long double)(b.brojnik)/b.nazivnik);}
    friend bool operator <(const Razlomak &a,const Razlomak &b){return (((long double)(a.brojnik)/a.nazivnik)<(long double)(b.brojnik)/b.nazivnik);}
    friend bool operator >=(const Razlomak &a,const Razlomak &b){return (((long double)(a.brojnik)/a.nazivnik)>=(long double)(b.brojnik)/b.nazivnik);}
    friend bool operator <=(const Razlomak &a,const Razlomak &b){return (((long double)(a.brojnik)/a.nazivnik)<=(long double)(b.brojnik)/b.nazivnik);}
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &a) {if(a.nazivnik==1) return (tok<<a.brojnik); return (tok<<a.brojnik<<"/"<<a.nazivnik);}
friend std::istream &operator >>(std::istream &tok, Razlomak &a);
};
long long int Razlomak::NZD(long long int p,long long int q)
{
    if(p<0)
    p*=-1;
    if(q<0)
    q*=-1;
    if(q>p)
    {
        long long int temp(std::move(q));
        q=std::move(p);
        p=std::move(temp);
    }
    if(q==0)
    return p;
    else
    return Razlomak::NZD(q,p%q);
}
Razlomak::Razlomak(long long int brojn,long long int nazivn)
{
    if(nazivn==0)
    throw std::logic_error("Nekorektan razlomak");
    long long int pom=Razlomak::NZD(brojn,nazivn);
    if(pom!=0 && pom!=1)
    {
    brojn/=pom;
    nazivn/=pom;
    }
    if(brojn>=0 && nazivn<0)
    {
    brojn*=-1;
    nazivn*=-1;
    }
    if(brojn<0 && nazivn<0)
    {
    brojn*=-1;
    nazivn*=-1;
    }
    brojnik=brojn;
    nazivnik=nazivn;
}
bool Razlomak::ZbirPrekoracenje(long long int x,long long int y)
{
    if(y>=0)
    {
        if(x>numeric_limits<long long int>::max()-y)
        return true;
        return false;
    }
    if(y<0)
    {
        if(x<numeric_limits<long long int>::lowest()-y)
        return true;
        return false;
    }
    return false;
}
bool Razlomak::RazlikaPrekoracenje(long long int x,long long int y)
{
    y*=-1;
    bool pom=Razlomak::ZbirPrekoracenje(x,y);
    return pom;
}
bool Razlomak::ProizvodPrekoracenje(long long int x,long long int y)
{
    if(y>0)
    {
        if(x<(numeric_limits<long long int>::lowest()/y) || x>(numeric_limits<long long int>::max()/y))
        return true;
        return false;
    }
    if(y<0)
    {
       if(x==numeric_limits<long long int>::lowest() || (-1*x)>(numeric_limits<long long int>::max()/(-1*y)) || (-1*x)<(numeric_limits<long long int>::lowest()/(-1*y)))
        return true;
        return false; 
    }
    return false;
}
inline Razlomak operator +(const Razlomak &a, const Razlomak &b) 
{
 long long int r(Razlomak::NZD(a.nazivnik,b.nazivnik));
 Razlomak c;
 if(Razlomak::ProizvodPrekoracenje(a.brojnik,(b.nazivnik/r)) || Razlomak::ProizvodPrekoracenje(b.brojnik,(a.nazivnik/r)) || Razlomak::ProizvodPrekoracenje(a.nazivnik,(b.nazivnik/r)))
 throw std::overflow_error("Nemoguce dobiti tacan rezultat");
 if(Razlomak::ZbirPrekoracenje(a.brojnik*(b.nazivnik/r),b.brojnik*(a.nazivnik/r)))
 throw std::overflow_error("Nemoguce dobiti tacan rezultat");
 c.brojnik=a.brojnik*(b.nazivnik/r)+b.brojnik*(a.nazivnik/r);
 c.nazivnik=a.nazivnik*(b.nazivnik/r);
 Razlomak d(c.brojnik,c.nazivnik);
 return d;
}
inline Razlomak operator -(const Razlomak &a,const Razlomak &b)
{
long long int r(Razlomak::NZD(a.nazivnik,b.nazivnik));
 Razlomak c;
 if(Razlomak::ProizvodPrekoracenje(a.brojnik,(b.nazivnik/r)) || Razlomak::ProizvodPrekoracenje(b.brojnik,(a.nazivnik/r)) || Razlomak::ProizvodPrekoracenje(a.nazivnik,(b.nazivnik/r)))
 throw std::overflow_error("Nemoguce dobiti tacan rezultat");
 if(Razlomak::RazlikaPrekoracenje(a.brojnik*(b.nazivnik/r),b.brojnik*(a.nazivnik/r)))
 throw std::overflow_error("Nemoguce dobiti tacan rezultat");
 c.brojnik=a.brojnik*(b.nazivnik/r)-b.brojnik*(a.nazivnik/r);
 c.nazivnik=a.nazivnik*(b.nazivnik/r);
 Razlomak d(c.brojnik,c.nazivnik);
 return d;
}
inline Razlomak operator *(const Razlomak &a,const Razlomak &b)
{
    long long int s(Razlomak::NZD(a.brojnik,b.nazivnik)),t(Razlomak::NZD(b.brojnik,a.nazivnik));
    Razlomak c;
    if(Razlomak::ProizvodPrekoracenje((a.brojnik/s),(b.brojnik/t)) || Razlomak::ProizvodPrekoracenje((a.nazivnik/t),(b.nazivnik/s)))
    throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    c.brojnik=(a.brojnik/s)*(b.brojnik/t);
    c.nazivnik=(a.nazivnik/t)*(b.nazivnik/s);
    Razlomak d(c.brojnik,c.nazivnik);
    return d;
}
inline Razlomak operator /(const Razlomak &a,const Razlomak &b)
{
    long long int r(Razlomak::NZD(a.nazivnik,b.nazivnik)),u(Razlomak::NZD(a.brojnik,b.brojnik));
    Razlomak c;
     if(Razlomak::ProizvodPrekoracenje((a.brojnik/u),(b.nazivnik/r)) || Razlomak::ProizvodPrekoracenje((a.nazivnik/r),(b.brojnik/u)))
    throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    c.brojnik=(a.brojnik/u)*(b.nazivnik/r);
    c.nazivnik=(a.nazivnik/r)*(b.brojnik/u);
    Razlomak d(c.brojnik,c.nazivnik);
    return d;
}
inline Razlomak &Razlomak::operator ++()
{
   *this+=1;
   return *this;
}
inline Razlomak Razlomak::operator ++(int)
{
    Razlomak pom(brojnik,nazivnik);
    *this+=1;
    return pom;
}
inline Razlomak &Razlomak::operator --()
{
    *this-=1;
    return *this;
}
inline Razlomak Razlomak::operator --(int)
{
    Razlomak pom(brojnik,nazivnik);
    *this-=1;
    return pom;
}
std::istream &operator >>(std::istream &tok,Razlomak &a) //je li dobro?
{
  /*  char znak;
    tok>>std::ws;
    a.nazivnik=1;
    tok>>a.brojnik>>znak;
    if(znak=='/')
    cin>>a.nazivnik;
    else
    tok.setstate(std::ios::failbit);
    return tok;*/
    char znak='w';
    tok>>std::ws;
    a.nazivnik=1;
    tok>>a.brojnik;
    if(tok.peek()=='\n' || tok.peek()=='\t' || tok.peek()=='\v' || tok.peek()=='\f' || tok.peek()==' ' || tok.peek()=='\r') return tok;
    tok>>znak;
    if(znak!='w' && znak!='/')
    tok.setstate(std::ios::failbit);
    tok>>a.nazivnik;
    if(tok.peek()!='\n' && tok.peek()!='\t' && tok.peek()!='\v' && tok.peek()!='\f' && tok.peek()!=' ' && tok.peek()!='\r')
    tok.setstate(std::ios::failbit);
    int pom=Razlomak::NZD(a.brojnik,a.nazivnik);
    a.brojnik/=pom;
    a.nazivnik/=pom;
    if(a.brojnik<0 && a.nazivnik<0)
    {
        a.brojnik*=-1;
        a.nazivnik*=-1;
    }
    if(a.nazivnik<0 && a.brojnik>=0)
    {
    a.nazivnik*=-1;
    a.brojnik*=-1;
    }
    return tok;
}
int main ()
{
    Razlomak r1(100,50), r2{10,9}, r3{11};
    cout<<r1.DajBrojnik()<<" "<<r1.DajNazivnik()<<std::endl;
    cout<<r2.DajBrojnik()<<" "<<r2.DajNazivnik()<<std::endl<<r3.DajBrojnik()<<" "<<r3.DajNazivnik()<<std::endl;
    Razlomak r4,r5,r6;
    r4=r1+r2;
    r5*=r2;
    r6+=5;
    cout<<r4<<std::endl<<r5<<std::endl<<r6<<std::endl;
    long double pom=r4;
    cout<<pom;
    try
    {
        Razlomak r6(numeric_limits<long long int>::max());
        Razlomak r7(3,1);
        r7=r6*r7;
    }
    catch(...)
    {
        cout<<"izuzetak";
    }
	return 0;
}
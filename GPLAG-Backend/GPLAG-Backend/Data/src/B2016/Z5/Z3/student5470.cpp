/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <sstream>
int sgn(long long int a)
{
    return (0<a)-(a<0);
}
class Razlomak
{
    long long int naz,broj;
public:
    Razlomak(long long int a=0,long long int b=1)
    {
        if(!b) throw std::logic_error("");
        broj=sgn(b)*a/NZD(abs(a),abs(b));
        naz=abs(b/NZD(abs(a),abs(b)));
    }
    static int sgn(long long int a)
    {
        return (0<a)-(a<0);
    }
    static long long int NZD(long long int a,long long int b)
    {
        if(!b) return a;
        return NZD(b,a%b);
    }
    long long int DajBrojnik(){return broj;}
    long long int DajNazivnik(){return naz;}
    Razlomak operator++(int)
    {
        *this+=1;
        return *this;
    }
    Razlomak operator--(int)
    {
        *this-=1;
        return *this;
    }
    Razlomak operator++()
    {
        Razlomak a(DajBrojnik(),DajNazivnik());
        *this+=1;
        return a;
    }
    Razlomak operator--()
    {
        Razlomak a(DajBrojnik(),DajNazivnik());
        *this-=1;
        return a;
    }
    Razlomak operator+=(Razlomak a)
    {
        *this=*this+a;
        return *this;
    }
    Razlomak operator-=(Razlomak a)
    {
        *this=*this-a;
        return *this;
    }
    Razlomak operator*=(Razlomak a)
    {
        *this=*this*a;
        return *this;
    }
    Razlomak operator/=(Razlomak a)
    {
        *this=*this/a;
        return *this;
    }
    friend Razlomak operator+(Razlomak a,Razlomak b)
    {
        if(sab(a.broj*(b.naz/NZD(a.naz,b.naz)),b.broj*(a.naz/NZD(a.naz,b.naz)))||mno(a.broj,(b.naz/NZD(a.naz,b.naz))||mno(b.broj,(a.naz/NZD(a.naz,b.naz)))||mno(a.naz,(b.naz/NZD(a.naz,b.naz))))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        return Razlomak(a.broj*(b.naz/NZD(a.naz,b.naz))+b.broj*(a.naz/NZD(a.naz,b.naz)),a.naz*(b.naz/NZD(a.naz,b.naz)));
    }
    friend Razlomak operator-(Razlomak a,Razlomak b)
    {
        if(sab(a.broj*(b.naz/NZD(a.naz,b.naz)),-b.broj*(a.naz/NZD(a.naz,b.naz)))||mno(a.broj,(b.naz/NZD(a.naz,b.naz))||mno(b.broj,(a.naz/NZD(a.naz,b.naz)))||mno(a.naz,(b.naz/NZD(a.naz,b.naz))))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        return Razlomak(a.broj*(b.naz/NZD(a.naz,b.naz))-b.broj*(a.naz/NZD(a.naz,b.naz)),a.naz*b.naz/NZD(a.naz,b.naz));
    }
    friend Razlomak operator*(Razlomak a,Razlomak b)
    {
        if(mno(a.broj/NZD(a.broj,b.naz),(b.broj/NZD(b.broj,a.naz))||mno(a.naz/NZD(b.broj,a.naz),(b.naz/NZD(a.broj,b.naz))))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        return Razlomak(a.broj/NZD(a.broj,b.naz)*(b.broj/NZD(b.broj,a.naz)),a.naz/NZD(b.broj,a.naz)*(b.naz/NZD(a.broj,b.naz)));
    }
    friend Razlomak operator/(Razlomak a,Razlomak b)
    {
        if(mno(a.broj/NZD(a.broj,b.broj),(b.naz/NZD(b.naz,a.naz)))||mno(a.naz/NZD(b.naz,a.naz),(b.naz/NZD(a.broj,b.broj)))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        return Razlomak(a.broj/NZD(a.broj,b.broj)*(b.naz/NZD(b.naz,a.naz)),a.naz/NZD(b.naz,a.naz)*(b.broj/NZD(a.broj,b.broj)));
    }
    static bool sab(long long int x,long long int y);
    static bool mno(long long int x,long long int y);
    Razlomak operator-()
    {
        if(broj==std::numeric_limits<long long int>::min()) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        return Razlomak(-DajBrojnik(),DajNazivnik());
    }
    Razlomak operator+()
    {
        return Razlomak(DajBrojnik(),DajNazivnik());
    }
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r)
    {
        tok << r.broj;
        if(r.naz!=1) tok << "/" << r.naz;
        return tok;
    }
    friend std::istream &operator >>(std::istream &tok, Razlomak &r);
    operator long double()
    {
        return broj*1./naz;
    }
};
int main ()
{
   {//AT4 (c9): operator >> (2/3) (direktno iz std::cin)
     //NAPOMENA: pogledati AT3 za detaljna objasnjenja (i \R znak je bjelina, malo 'r')
        Razlomak r, p, q;
        std::cin >> r; //5/17
        std::cout << r << std::endl;
        std::cin.clear(); std::cin.ignore (100, '\n');
        //tri zaredom
        std::cin >> r >> p >> q; //10 20 30 -> 10/1 20/1 30/1
        std::cout << r << " " << p << " " << q << std::endl;
        std::cin.clear(); std::cin.ignore (100, '\n');
        std::cin >> r;
        std::cout << r;
    }
	return 0;
}

bool Razlomak::sab(long long int x,long long int y)
{
    if(y>=0)
        return x>std::numeric_limits<long long int>::max()-y;
    return x<std::numeric_limits<long long int>::min()-y;
}

bool Razlomak:: mno(long long int x,long long int y)
{
    if(y>0)
        return x<std::numeric_limits<long long int>::min()/y || x>std::numeric_limits<long long int>::max()/y;
    return x==std::numeric_limits<long long int>::min() || -x<std::numeric_limits<long long int>::min()/-y || -x>std::numeric_limits<long long int>::max()/-y;
}
std::istream &operator >>(std::istream &tok, Razlomak &r)
{
    tok >> r.broj;
    if(tok.peek()=='\n' || tok.peek()==' ' || tok.peek()=='\t' || tok.peek()=='\r' || tok.peek()=='\f' || tok.peek()=='\v'||tok.peek()==EOF)
    {
        r.naz=1;
        return tok;
    }
    char p;
    tok >> p ;
    if(p!='/') tok.setstate(std::basic_ios<char>::failbit);
    tok >> r.naz;
    if(tok.peek()!='\n' && tok.peek()!=' ' && tok.peek()!='\t' && tok.peek()!='\r' && tok.peek()!='\f' && tok.peek()!='\v') {tok.setstate(std::basic_ios<char>::failbit);}
    long long int pom=Razlomak::NZD(abs(r.naz),abs(r.broj));
    r.broj=sgn(r.naz)*r.broj/pom;
    r.naz=abs(r.naz/pom);
    while(tok.peek()==' ' || tok.peek()=='\t' || tok.peek()=='\r' || tok.peek()=='\f' || tok.peek()=='\v'){tok.get(p);}
    return tok;
}
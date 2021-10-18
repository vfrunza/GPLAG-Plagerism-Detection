#include <iostream>
#include <stdexcept>
#include <climits>
#include <cmath>
#include <sstream>
#define eps 1E-18
#define M LLONG_MAX
#define m LLONG_MIN

using namespace std;

class Razlomak {
    long long int brojnik,nazivnik;
    public:
    Razlomak(long long int b=0,long long int n=1)
    {
        int i=2;
        if(n==0)throw;
        while(i<=b && i<=n)
        {
            
            if(b%i==0 && n%i==0)
            {
                b/=i;
                n/=i;
            }
            else 
            i++;
        }
        brojnik=b;
        nazivnik=n;
    }
    Razlomak(initializer_list<long long int>  b_n);
    long long int DajBrojnik() const { return brojnik; };
    long long int DajNazivnik() const { return nazivnik; };
    friend Razlomak operator +(Razlomak r1, const Razlomak &r2)
    {
        return Razlomak(r1.brojnik*r2.nazivnik+r2.brojnik*r1.nazivnik,r1.nazivnik*r2.nazivnik);
    }
    friend Razlomak operator -(Razlomak r1, const Razlomak &r2)
    {
        return Razlomak(r1.brojnik*r2.nazivnik-r2.brojnik*r1.nazivnik,r1.nazivnik*r2.nazivnik);
    }
    friend Razlomak operator *(Razlomak r1, const Razlomak &r2)
    {
        return Razlomak(r1.brojnik*r2.brojnik,r1.nazivnik*r2.nazivnik);
    }
    friend Razlomak operator /(Razlomak r1, const Razlomak &r2)
    {
         return Razlomak(r1.brojnik*r2.nazivnik,r1.nazivnik*r2.brojnik);
    }
    friend Razlomak operator +(const Razlomak &r1)
    {
        return Razlomak(r1);
    }
    friend Razlomak operator -(Razlomak &r1)
    {
        return Razlomak(-r1.brojnik,r1.nazivnik);
    }
    friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2)
    {
        return r1=r1+r2;
    }
    friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2)
    {
        return r1=r1-r2;
    }
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2)
    {
        return r1=r1*r2;
    }
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2)
    {
        return r1=r1/r2;
    }
    friend Razlomak &operator ++(Razlomak &r1)
    {
        return r1+=Razlomak(1,r1.nazivnik);
    }
    friend Razlomak &operator --(Razlomak &r1)
     {
        return r1-=Razlomak(1,r1.nazivnik);
    }
    friend Razlomak operator ++(Razlomak &r1, int){
        Razlomak rh=r1;
        ++r1;
        return rh;
    }
    friend Razlomak operator --(Razlomak &r1, int)
    {
        Razlomak rh=r1;
        --r1;
        return rh;
    }
    friend bool operator <(const Razlomak &r1, const Razlomak &r2)
    {
        return r1.brojnik/r1.nazivnik < r2.brojnik/r2.nazivnik;
    }
    friend bool operator >(const Razlomak &r1, const Razlomak &r2)
    {
         return r1.brojnik/r1.nazivnik > r2.brojnik/r2.nazivnik;
    }
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2)
    {
        return !(r1<r2);
    }
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2)
    {
        return !(r1<r2);
    }
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2)
    {
        return !(r1<r2 || r1>r2);
    }
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2)
    {
        return (r1<r2 || r1>r2);
    }
    friend ostream &operator <<(ostream &tok, const Razlomak &r1)
    {
        
        if(r1.brojnik==0) return tok<<"0";
        else if(r1.nazivnik==1) return tok<<r1.brojnik;
        else return tok<<r1.brojnik<<"/"<<r1.nazivnik;
    }
    friend istream &operator >>(istream &tok,Razlomak &r1)
    {
        char znak;
        tok>>std::ws;
        tok>>r1.brojnik;
        if(tok.peek()!= '/') { r1.nazivnik=1; return tok; }
        else {
            tok>>znak>>r1.nazivnik;
        }
        if(tok.peek()!=' ' && tok.peek()!='\t' && tok.peek()!='\n' && tok.peek()!='\v' && tok.peek()!='\f') tok.setstate(std::ios::failbit);
        r1=Razlomak(r1.brojnik,r1.nazivnik);
       
        return tok;
    }
    explicit operator long double() const { return (double)brojnik/nazivnik; }
    
    
};
int main()
{
    //AT3 (c9): operator >> (1/3) ...
     //NAPOMENA: najlogicnija izvedba op>> ce proci
     //ove ATove. Dodatne izvedbe su nelogicne i nisu u skladu
     //sa ostaim tipovima...

     //ovdje cu koristiti specijalnu klasu (ne radi se naB
     //da preko stringa simuliram ulaz
     //cisto da se vide viska razmaci

     //NAPOMENA: pod "razmakom" se smatra SVAKI znak koji je BJELINA
     //odnosno ovih 6 znakova u en-US:
     //      \n, |r, \f, \v, \t, ' '
     // i |r je sa backshashom, ali zbog buga pisem |r. Znaci, i \R (samo malo r)
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

     //dosta testova :whew:
    return 0;
}
/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <limits>
typedef long long llint;
typedef long double ldouble;
bool is_ws(char x)
{
    return x==' '||x=='\n'||x=='\t'||x=='\v'||x=='\f'||x=='\r';
}
class Razlomak
{
  private:
    llint brojnik, nazivnik;
  public:
   Razlomak():brojnik(0),nazivnik(1){}
   Razlomak(llint a, llint b = 1);
   Razlomak(int a, int b = 1):Razlomak(llint(a),llint(b)){}
   Razlomak(llint a, int b = 1):Razlomak(llint(a),llint(b)){}
   Razlomak(double a, double b = 1) = delete;
   llint DajBrojnik();
   llint DajNazivnik();
   friend Razlomak operator+(Razlomak r1, Razlomak r2);
   friend Razlomak operator*(Razlomak r1, Razlomak r2);
   friend Razlomak operator-(Razlomak r1, Razlomak r2);
   friend Razlomak operator/(Razlomak r1, Razlomak r2);
   Razlomak operator+();
   Razlomak operator-();
   Razlomak& operator+=(Razlomak r1);
   Razlomak& operator-=(Razlomak r1);
   Razlomak& operator*=(Razlomak r1);
   Razlomak& operator/=(Razlomak r1);
   Razlomak& operator++();
   Razlomak& operator--();
   Razlomak operator++(int);
   Razlomak operator--(int);
   friend bool operator<(Razlomak r1, Razlomak r2);
   friend bool operator>(Razlomak r1, Razlomak r2);
   friend bool operator==(Razlomak r1, Razlomak r2);
   friend bool operator!=(Razlomak r1,Razlomak r2);
   friend bool operator<=(Razlomak r1, Razlomak r2);
   friend bool operator>=(Razlomak r1, Razlomak r2);
   operator long double() const;
   friend std::ostream& operator<<(std::ostream& out, Razlomak r1);
   friend std::istream& operator>>(std::istream& in, Razlomak& r1);
  public:
    static const llint M = std::numeric_limits<llint>::max();
    static const llint m = std::numeric_limits<llint>::min();
    static llint NZD(llint a, llint b);
    static void Exc();
    static llint add(llint x, llint y);
    static llint sub(llint x, llint y);
    static llint mul(llint x, llint y);
};
llint Razlomak::NZD(llint a, llint b)
{
    if(b == 0) return std::abs(a);
    return std::abs(NZD(b, a%b));
}
Razlomak::Razlomak(llint a, llint b)
{
    if(b == 0) throw std::logic_error("Nekorektan razlomak");
    auto nzd = NZD(a, b);
    if( b < 0) { b = -b; a = -a; }
    a/=nzd;
    b/=nzd;
    brojnik = a;
    nazivnik = b;
}
llint Razlomak::DajBrojnik() { return brojnik; }
llint Razlomak::DajNazivnik() { return nazivnik; }
void Razlomak::Exc(){ throw std::overflow_error("Nemoguce dobiti tacan rezultat"); }
llint Razlomak::add(llint x, llint y)
{
    if(y > 0 && x > M - y) Exc();
    if(y < 0 && x < m - y) Exc();
    return x + y;
}
llint Razlomak::sub(llint x, llint y)
{
    if(y > 0 && x < m + y) Exc();
    if(y < 0 && x > M + y) Exc();
    return x - y;
}
llint Razlomak::mul(llint x, llint y)
{
    if(y > 0 && ( x < m/y || x > M/y )) Exc();
    if(y < 0 && ( x == m || -x > M/-y || -x < m/-y )) Exc();
    return x * y;
}
Razlomak Razlomak::operator+() { return *this; }
Razlomak Razlomak::operator-() { if(brojnik == m) Exc(); return Razlomak(-brojnik,nazivnik); }
Razlomak operator+(Razlomak r1, Razlomak r2)
{
    llint r = Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    return Razlomak( Razlomak::add(Razlomak::mul(r1.brojnik, r2.nazivnik/ r), Razlomak::mul(r2.brojnik, r1.nazivnik / r) ), r1.nazivnik/r*r2.nazivnik);
}
Razlomak operator-(Razlomak r1, Razlomak r2)
{
    return r1 + -r2;
}
Razlomak operator*(Razlomak r1, Razlomak r2)
{
    llint p1=r1.brojnik,p2=r2.brojnik,q1=r1.nazivnik,q2=r2.nazivnik,s=Razlomak::NZD(p1,q2),t=Razlomak::NZD(p2,q1);
    return Razlomak( Razlomak::mul((p1/s),(p2/t)), Razlomak::mul(q1/t, q2/s));
}
Razlomak operator/(Razlomak r1, Razlomak r2)
{
    r2 = Razlomak(r2.DajNazivnik(),r2.DajBrojnik());
    return r1 * r2;
}
Razlomak& Razlomak::operator+=(Razlomak r1) { return *this = *this + r1; }
Razlomak& Razlomak::operator-=(Razlomak r1) { return *this = *this - r1; }
Razlomak& Razlomak::operator*=(Razlomak r1) { return *this = *this * r1; }
Razlomak& Razlomak::operator/=(Razlomak r1) { return *this = *this / r1; }
Razlomak& Razlomak::operator++() { return *this+=1; }
Razlomak& Razlomak::operator--() { return *this-=1; }
Razlomak Razlomak::operator++(int)
{
    auto pom(*this);
    ++*this;
    return pom;
}
Razlomak Razlomak::operator--(int)
{
    auto pom(*this);
    --*this;
    return pom;
}
bool operator<(Razlomak r1, Razlomak r2)
{
    return ldouble(r1.brojnik)/ldouble(r1.nazivnik) < ldouble(r2.brojnik)/ldouble(r2.nazivnik);
}
bool operator==(Razlomak r1, Razlomak r2)
{
    return r1.brojnik == r2.brojnik && r1.nazivnik == r2.nazivnik;
}
bool operator>(Razlomak r1, Razlomak r2)
{
    return !(r1 < r2) && !(r1 == r2);
}
bool operator!=(Razlomak r1, Razlomak r2)
{
    return !(r1 == r2);
}
bool operator<=(Razlomak r1, Razlomak r2)
{
    return r1 < r2 || r1 == r2;
}
bool operator>=(Razlomak r1, Razlomak r2)
{
    return r1 > r2 || r1 == r2;
}
Razlomak::operator long double() const
{ 
    return (ldouble)brojnik/(ldouble)nazivnik; 
}
std::ostream& operator<<(std::ostream& out, Razlomak r1)
{
    std::cout<< r1.brojnik;
    if(r1.nazivnik != 1) std::cout<< "/" << r1.nazivnik;
    return out;
}
std::istream& operator>>(std::istream& in, Razlomak& r1)
{
    char x;
    r1.nazivnik = 1;
    if((in >> r1.brojnik))
    {
        if(in.peek() == EOF || is_ws(in.peek())) return in;
        x = in.get();
        if(is_ws(x)) return in;
        if(!in) { in.clear(); return in; }
        if(x == '/')
        {
            if((in >> r1.nazivnik))
            {
                r1 = Razlomak(r1.brojnik, r1.nazivnik);
                x = in.peek();
                if(x == EOF || is_ws(x)) in.clear();
                else in.setstate(std::ios::failbit); 
                return in;
            }
            else
            {
                in.setstate(std::ios::failbit);
                return in;
            }
        }
        else 
        {
            in.setstate(std::ios::failbit);
            return in;
        }
    }
    else return in;
}

#include<sstream>
int main ()
{
  Razlomak r1,r2;
  std::cin>> r1 >> r2;
  std::cout<< (r1 += (-r2));
  std::cout<< (r1 -= r2);
  std::cout<< (r1 *= (-r2));
  std::cout<< (r1 /= (-r2));
  std::cout<< (r1 + r2);
  std::cout<< (r1 - r2);
  std::cout<< (r1 * r2);
  std::cout<< (r1 / -r2);
  std::cout<< (r1 == r2);
  std::cout<< (r1 < r2);
}
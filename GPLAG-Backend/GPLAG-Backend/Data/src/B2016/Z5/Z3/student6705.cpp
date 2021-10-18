/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>
#include <math.h>
#include <string>
#include <vector>
class Razlomak
{
    long long int Brojnik, Nazivnik;
    static long long int NZD(long long int p, long long int q);
    static void ProvjeriSabiranje(long long int p1, long long int p2);
    static void ProvjeriOduzimanje(long long int p1, long long int p2);
    static void ProvjeriMnozenje(long long int p1, long long int p2);
    static long long int StringToInt(std::string s);
    static bool DaLiJeIspravan(std::string s);
    public:
    Razlomak(long long int brojnik = 0, long long int nazivnik = 1);
    Razlomak(int brojnik){
        Brojnik = brojnik;
        Nazivnik = 1;
    }
    long long int DajBrojnik() const {return Brojnik;}
    long long int DajNazivnik() const {return Nazivnik;}
    friend Razlomak operator +(const Razlomak &r1);
    friend Razlomak operator -(const Razlomak &r1);
    friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator ++(Razlomak &r1);
    friend Razlomak operator ++(Razlomak &r1, int);
    friend Razlomak &operator --(Razlomak &r1); 
    friend Razlomak operator --(Razlomak &r1, int);
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator > (const Razlomak &r1, const Razlomak &r2);
    friend bool operator < (const Razlomak &r1, const Razlomak &r2);
    friend std::ostream& operator <<(std::ostream& Itok, const Razlomak &r1);
    friend std::istream& operator >>(std::istream& Utok, Razlomak &r1);
    operator long double () const{
        return ((long double)Brojnik)/Nazivnik;
    }
};
long long int Razlomak::NZD(long long int p, long long int q)
{
    if(q == 0)
        return p;
    else
        return NZD(q, p % q);
}
void Razlomak::ProvjeriSabiranje(long long int x, long long int y)
{
    long long int M = std::numeric_limits<long long int>::max();
    long long int m = std::numeric_limits<long long int>::min();
    if(y > 0)
        if(x > (M - y))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(y < 0)
        if(x < (m - y))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
}
void Razlomak::ProvjeriOduzimanje(long long int x, long long int y)
{
    Razlomak::ProvjeriSabiranje(x, -y);
}
void Razlomak::ProvjeriMnozenje(long long int x, long long int y)
{   
    long long int M = std::numeric_limits<long long int>::max();
    long long int m = std::numeric_limits<long long int>::min();
    if(y > 0)
        if(x > (M / y) || x < (m / y))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(y < 0)
        if(x == m || -x > (M / (- y)) || -x < (m / (-y))) 
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
}
long long int Razlomak::StringToInt(std::string s)
{
    std::vector<int> v;
    for(int i(0); i < s.size(); i++)
        v.push_back(s[i] - 48);
    long long int vrati(0), k(1);
    for(int i(v.size() - 1); i >= 0; i--)
    {
        vrati += v[i] * k;
        k *= 10;
    }
    return vrati;
}
bool Razlomak::DaLiJeIspravan(std::string s)
{
    for(int i(0); i < s.size(); i++)
        if(s[i] >= '0' && s[i] <= '9')
            continue;
        else
            return false;
    return true;
}
Razlomak::Razlomak(long long int brojnik, long long int nazivnik)
{
    if(nazivnik == 0)
        throw std::logic_error("Nekorektan razlomak");
    if(brojnik < 0 && nazivnik < 0)
    {
        brojnik *= -1;
        nazivnik *= -1;
        auto nzd = NZD(brojnik, nazivnik);
        Brojnik = brojnik/nzd;
        Nazivnik = nazivnik/nzd;
    }
    else if(nazivnik > 0 && brojnik >= 0)
    {
        auto nzd = NZD(brojnik, nazivnik);
        Brojnik = brojnik/nzd;
        Nazivnik = nazivnik/nzd; 
    }
    else
    {
        if(brojnik < 0)
            brojnik *= -1;
        if(nazivnik < 0)
            nazivnik *= -1;
        auto nzd = NZD(brojnik, nazivnik);
        Brojnik = brojnik/nzd;
        Nazivnik = nazivnik/nzd;
        Brojnik *= -1;
    }
}
Razlomak operator +(const Razlomak &r1)
{
    return r1;
}
Razlomak operator -(const Razlomak &r1)
{
    if(r1.Brojnik == std::numeric_limits<long long int>::min())
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return Razlomak(-r1.DajBrojnik(), r1.DajNazivnik());
}
Razlomak operator +(const Razlomak &r1, const Razlomak &r2)
{

    long long int p1(r1.Brojnik), p2(r2.Brojnik), q1(r1.Nazivnik), q2(r2.Nazivnik);
    auto r = Razlomak::NZD(q1, q2);
    auto temp1 = q2 / r;
    auto temp2 = q1 / r;
    Razlomak::ProvjeriMnozenje(p1, temp1);
    Razlomak::ProvjeriMnozenje(p2, temp2);
    auto temp3 = p1 * temp1;
    auto temp4 = p2 * temp2;
    Razlomak::ProvjeriSabiranje(temp3, temp4);
    auto brojnik = temp3 + temp4;
    Razlomak::ProvjeriMnozenje(q1, (q2 / r));
    auto nazivnik = q1 * (q2 / r);
    return Razlomak(brojnik, nazivnik);
}
Razlomak operator -(const Razlomak &r1, const Razlomak &r2)
{
    long long int p1(r1.Brojnik), p2(r2.Brojnik), q1(r1.Nazivnik), q2(r2.Nazivnik);
    auto r = Razlomak::NZD(q1, q2);
    auto temp1 = q2 / r;
    auto temp2 = q1 / r;
    Razlomak::ProvjeriMnozenje(p1, temp1);
    Razlomak::ProvjeriMnozenje(p2, temp2);
    auto temp3 = p1 * temp1;
    auto temp4 = p2 * temp2;
    Razlomak::ProvjeriOduzimanje(temp3, temp4);
    auto brojnik = temp3 - temp4;
    Razlomak::ProvjeriMnozenje(q1, (q2 / r));
    auto nazivnik = q1 * (q2 / r);
    return Razlomak(brojnik, nazivnik);
}
Razlomak operator *(const Razlomak &r1, const Razlomak &r2)
{
    long long int p1(r1.Brojnik), p2(r2.Brojnik), q1(r1.Nazivnik), q2(r2.Nazivnik);
    auto s = Razlomak::NZD(p1, q2);
    auto t = Razlomak::NZD(p2, q1);
    auto temp1 = p1 / s;
    auto temp2 = p2 / t;
    auto temp3 = q1 / t;
    auto temp4 = q2 / s;
    Razlomak::ProvjeriMnozenje(temp1, temp2);
    Razlomak::ProvjeriMnozenje(temp3, temp4);
    auto brojnik = temp1 * temp2;
    auto nazivnik = temp3 * temp4;
    return Razlomak(brojnik, nazivnik);
}
Razlomak operator /(const Razlomak &r1, const Razlomak &r2)
{
    long long int p1(r1.Brojnik), p2(r2.Brojnik), q1(r1.Nazivnik), q2(r2.Nazivnik);
    auto r = Razlomak::NZD(q1, q2);
    auto u = Razlomak::NZD(p1, p2);
    auto temp1 = p1 / u;
    auto temp2 = q2 / r;
    auto temp3 = q1 / r;
    auto temp4 = p2 / u;
    Razlomak::ProvjeriMnozenje(temp1, temp2);
    Razlomak::ProvjeriMnozenje(temp3, temp4);
    auto brojnik = temp1 * temp2;
    auto nazivnik = temp3 * temp4;
    return Razlomak(brojnik, nazivnik);
}
Razlomak &operator +=(Razlomak &r1, const Razlomak &r2)
{
    return r1 = r1 + r2;
}
Razlomak &operator -=(Razlomak &r1, const Razlomak &r2)
{
    return r1 = r1 - r2;
}
Razlomak &operator *=(Razlomak &r1, const Razlomak &r2)
{
    return r1 = r1 * r2;
}
Razlomak &operator /=(Razlomak &r1, const Razlomak &r2)
{
    return r1 = r1 / r2;
}
Razlomak operator ++(Razlomak &r1, int)
{
    Razlomak pomocni(1, 1);
    r1 += pomocni;
    return pomocni;
}
Razlomak &operator ++(Razlomak &r1)
{
    Razlomak pomocni(1, 1);
    r1 += pomocni;
    return r1;
}
Razlomak operator --(Razlomak &r1, int)
{
    Razlomak pomocni(1, 1);
    r1 -= pomocni;
    return pomocni;
}
Razlomak &operator --(Razlomak &r1)
{
    Razlomak pomocni(1, 1);
    r1 -= pomocni;
    return r1;
}
bool operator ==(const Razlomak &r1, const Razlomak &r2)
{
    if(r1.Brojnik == r2.Brojnik && r1.Nazivnik == r2.Nazivnik)
        return true;
    return false;
}
bool operator !=(const Razlomak &r1, const Razlomak &r2)
{
    return !(r1 == r2);
}
bool operator > (const Razlomak &r1, const Razlomak &r2)
{
    long double razlomak1 = ((long double)r1.Brojnik) / r1.Nazivnik;
    long double razlomak2 = ((long double)r2.Brojnik) / r2.Nazivnik;
    return razlomak1 > razlomak2;
}
bool operator < (const Razlomak &r1, const Razlomak &r2)
{
    long double razlomak1 = ((long double)r1.Brojnik) / r1.Nazivnik;
    long double razlomak2 = ((long double)r2.Brojnik) / r2.Nazivnik;
    return razlomak1 < razlomak2;
}
bool operator >=(const Razlomak &r1, const Razlomak &r2)
{
    if(r1 == r2)
        return true;
    return r1 > r2;
}
bool operator <=(const Razlomak &r1, const Razlomak &r2)
{
    if(r1 == r2)
        return true;
    return r1 < r2;
}
std::ostream& operator <<(std::ostream& Itok, const Razlomak &r1)
{
    if(r1.Nazivnik == 1 )
        Itok << r1.Brojnik;
    else
        Itok << r1.Brojnik << "/" << r1.Nazivnik;
    return Itok;
}
std::istream& operator >>(std::istream& Utok, Razlomak &r1)
{
    std::string s;
    Utok >> s;
    std::string brojnik, nazivnik;
    int i = 0;
    while(s[i] != '/' && i < s.size())
    {
        brojnik += s[i];
        i++;
    }
    i++;
    while(i < s.size())
    {
        nazivnik += s[i];
        i++;
    }
    
    long long int bro(0), naz(0);
    if(Razlomak::DaLiJeIspravan(brojnik))
    {
        bro = Razlomak::StringToInt(brojnik);
        if(nazivnik.size() == 0){
            Razlomak p(bro);
            r1 = p; 
            return Utok;
        }
        if(Razlomak::DaLiJeIspravan(nazivnik)){
            naz = Razlomak::StringToInt(nazivnik);
            Razlomak p1(bro, naz);
            r1 = p1;
            return Utok;
        }
    }
    Utok.setstate(std::ios::failbit);
    return Utok;
}

int main ()
{
    Razlomak r (3, 1), t (21), v;
    std::cout << "r = " << r << ", t = " << t << ", v = " << v << std::endl;
    std::cout << (r + t) << std::endl;
    std::cout << (t - r) << std::endl;
    std::cout << (r * t) << std::endl;
    std::cout << (t / r) << std::endl;
    std::cout << +r << std::endl;
    std::cout << -r << std::endl;
    r += t;
    std::cout << r << std::endl;
    r -= t;
    std::cout << r << std::endl;
    r *= t;
    std::cout << r << std::endl;
    r /= t;
    r++;
    std::cout << r << std::endl;
    std::cout << ++r << std::endl;
    r--;
    std::cout << r << std::endl;
    std::cout << --r << std::endl;
    std::cout << "Brojnik: " << r.DajBrojnik() << std::endl
                      << "Nazivnik: " << r.DajNazivnik() << std::endl;
    Razlomak r1(2, 2), r2(5, 1), r3(7, 7), r4(1524, 50);
    std::cout << "R1 == R3 " << (r1 == r3) << " R2 != R1 " << (r2 != r1) << std::endl;
    std::cout << "R1 > R2 " << (r1 > r2) << " R1 >= R3 " << (r1 >= r3) << std::endl;
    std::cout << "R1 < R2 " << (r1 < r2) << " R1 <= R3 " << (r1 <= r3) << std::endl;
    long double x(r4);
    std::cout << x;
}
/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>

class Razlomak
{
    long long int brojnik, nazivnik;
    static long long int NZD(long long int p, long long int q);
    static void ImaLiPrekoracenja(long long int x, long long int y, char operacija);
    static void IgnoreSpace(std::istream &tok){while (JeLiBjelina(tok)) tok.get();}
    static bool JeLiBjelina(std::istream &tok){
        char z(tok.peek());
        if (z == EOF || z == '\r' || z == ' ' || z == '\f' || z == '\v' || z == '\t')
            return true;
        return false;
    }
public:
    Razlomak(long long int brojnik = 0, long long int nazivnik = 1);
    long long int DajBrojnik()const { return brojnik;}
    long long int DajNazivnik()const { return nazivnik;}
    friend Razlomak operator+(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator-(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator*(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator/(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator+(const Razlomak &r){Razlomak r2(r); return r2;};
    friend Razlomak operator-(const Razlomak &r);
    Razlomak &operator+=(const Razlomak &a){*this = *this + a; return *this;}
    Razlomak &operator-=(const Razlomak &a){*this = *this - a; return *this;}
    Razlomak &operator*=(const Razlomak &a){*this = *this * a; return *this;}
    Razlomak &operator/=(const Razlomak &a){*this = *this / a; return *this;}
    Razlomak &operator++(){*this += 1; return *this;}
    Razlomak operator++(int){Razlomak r(*this); *this += 1; return r;}
    Razlomak &operator--(){*this -= 1; return *this;}
    Razlomak operator--(int){Razlomak r(*this); *this -= 1; return r;}
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r);
    friend std::istream &operator >>(std::istream &tok, Razlomak &r);
    friend bool operator==(const Razlomak &r1, const Razlomak &r2){return static_cast<long double> (r1.brojnik)/r1.nazivnik == static_cast<long double>(r2.brojnik)/r2.nazivnik;};
    friend bool operator >(const Razlomak &r1, const Razlomak &r2){return static_cast<long double> (r1.brojnik)/r1.nazivnik > static_cast<long double>(r2.brojnik)/r2.nazivnik;};
    inline friend bool operator!=(const Razlomak &r1, const Razlomak &r2){return !(r1 == r2);}
    inline friend bool operator >=(const Razlomak &r1, const Razlomak&r2){return r1 > r2 || r1 == r2;}
    inline friend bool operator <(const Razlomak &r1, const Razlomak &r2){return !(r1 >= r2);}
    inline friend bool operator <=(const Razlomak &r1, const Razlomak &r2){return r1 < r2 || r1 == r2;}
    operator long double()const{return static_cast<long double>(brojnik)/nazivnik;}
};
long long int Razlomak::NZD(long long int p, long long int q)
{
    if (q != 0)
        return NZD(q, p%q);
    return p;
}
void Razlomak::ImaLiPrekoracenja(long long int x, long long int y, char operacija)
{
    long long int M(std::numeric_limits<long long int>::max()), m(std::numeric_limits<long long int>::lowest());
    bool prekoracenje(false);
    if (operacija == '+' && ((y > 0 && x > M - y) || (y < 0 && x < m - y))) prekoracenje = true;
    else if (operacija == '-' && ((y < 0 && x > M + y) || (y > 0 && x < m + y))) prekoracenje = true;
    else if (operacija == '*' && ((y > 0 && x < m/y) || (y < 0 && (x == m || -x > M/(-y) || -x < m/(-y))))) prekoracenje = true;
    if (prekoracenje)
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
}
Razlomak::Razlomak(long long int brojnik, long long int nazivnik)
{
    if (nazivnik == 0)
        throw std::logic_error("Nekorektan razlomak");
    long long int nzd(NZD(brojnik, nazivnik));
    brojnik /= nzd; nazivnik /= nzd;
    if (nazivnik < 0)
    {
        brojnik = -brojnik;
        nazivnik = -nazivnik;
    }
    Razlomak::brojnik = brojnik; Razlomak::nazivnik = nazivnik;
}
Razlomak operator+(const Razlomak &a, const Razlomak &b)
{
    long long int p1(a.brojnik), q1(a.nazivnik), p2(b.brojnik), q2(b.nazivnik), r(Razlomak::NZD(q1, q2));
    Razlomak::ImaLiPrekoracenja(p1, q2/r, '*');
    Razlomak::ImaLiPrekoracenja(p2, q1/r, '*');
    Razlomak::ImaLiPrekoracenja(p1*(q2/r), p2*(q1/r), '+');
    Razlomak::ImaLiPrekoracenja(q1, q2/r, '*');
    return Razlomak(p1*(q2/r) + p2*(q1/r), q1*(q2/r));
}
Razlomak operator-(const Razlomak &a, const Razlomak &b)
{
    long long int p1(a.brojnik), q1(a.nazivnik), p2(b.brojnik), q2(b.nazivnik), r(Razlomak::NZD(q1, q2));
    Razlomak::ImaLiPrekoracenja(p1, q2/r, '*');
    Razlomak::ImaLiPrekoracenja(p2, q1/r, '*');
    Razlomak::ImaLiPrekoracenja(p1*(q2/r), p2*(q1/r), '-');
    Razlomak::ImaLiPrekoracenja(q1, q2/r, '*');
    return Razlomak(p1*(q2/r) - p2*(q1/r), q1*(q2/r));
}
Razlomak operator*(const Razlomak &a, const Razlomak &b)
{
    long long int p1(a.brojnik), q1(a.nazivnik), p2(b.brojnik), q2(b.nazivnik), s(Razlomak::NZD(p1, q2)), t(Razlomak::NZD(p2, q1));
    Razlomak::ImaLiPrekoracenja(p1/s, p2/t, '*');
    Razlomak::ImaLiPrekoracenja(q1/t, q2/s, '*');
    return Razlomak((p1/s)*(p2/t), (q1/t)*(q2/s));
}
Razlomak operator/(const Razlomak &a, const Razlomak &b)
{
    long long int p1(a.brojnik), q1(a.nazivnik), p2(b.brojnik), q2(b.nazivnik), r(Razlomak::NZD(q1, q2)), u(Razlomak::NZD(p1,p2));
    return Razlomak((p1/u)*(q2/r), (q1/r)*(p2/u));
}
Razlomak operator-(const Razlomak &r)
{
    Razlomak::ImaLiPrekoracenja(0, -r.brojnik, '+');
    Razlomak r2(r);
    r2.brojnik = -r.brojnik;
    return r2;
}
std::ostream &operator << (std::ostream &tok, const Razlomak &r)
{
    if (r.nazivnik != 1) tok << r.brojnik << "/" << r.nazivnik;
    else tok << r.brojnik;
    return tok;
}
std::istream &operator >> (std::istream &tok, Razlomak &r)
{
    long long int brojnik(1), nazivnik(1);
    Razlomak::IgnoreSpace(tok);
    char z(tok.peek());
    bool greska(false);
    if (!(z >= '0' && z <= '9')) greska = true;
    else{ tok >> brojnik;}
    if (tok.peek()!= '/' && !Razlomak::JeLiBjelina(tok) && tok.peek() != '\n') greska = true;
    else if (tok.peek() != '\n' && tok.peek() == '/')
    {
        tok.get();
        z = tok.peek();
        if (!(z >= '0' && z <= '9')) greska = true;
        tok >> nazivnik;
        if (!Razlomak::JeLiBjelina(tok) && tok.peek() != '\n') greska = true;
    }
    if (greska) tok.setstate(std::ios::failbit);
    else {r = Razlomak(brojnik, nazivnik);}
    return tok;
}

int main ()
{
    Razlomak r;
    std::cin >> r;
    std::cout << r.DajBrojnik() << " " << r.DajNazivnik() << std::endl;
	return 0;
}
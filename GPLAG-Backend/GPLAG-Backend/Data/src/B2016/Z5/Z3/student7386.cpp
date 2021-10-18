/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <stdexcept>
#include <limits>
#include <initializer_list>

class Razlomak
{
    private:
    long long int brojnik;
    long long int nazivnik;
    
    static long long int NZD(long long int p, long long int q)
    {
        if(q==0) return p;
        long long int zajednicki = NZD(q, p%q);
        return zajednicki;
    }
    
    
    static void provjera(long long int x, long long int y, int op)
    {
        long long int M = std::numeric_limits<long long int>::max();
        long long int m = std::numeric_limits<long long int>::lowest();
        if(op == 1) //Sabiranje
        {
            if(y>=0)
            {
                if(x > M - y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
            }
            else
            {
                if(x < m - y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
            }
        }
        if(op == 2) //Oduzimanje
        {
            if(y == m) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
            y = y*(-1);
            if(y>=0)
            {
                if(x > M - y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
            }
            else
            {
                if(x < m - y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
            }
        }
        if(op == 3) // Mnozenje
        {
            if(y>=0)
            {
                if(x < m/y || x>M/y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
            }
            else
            {
                if(x==m || -x>M/(-y) || -x<m/(-y)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
            }
        }
    }
    
    public:
    
    Razlomak(long long int b = 0, long long int n = 1)
    {
        if(n==0) throw std::logic_error("Nekorektan razlomak");
        if(n<0)
        {
            b=b*(-1);
            n=n*(-1);
        }
        long long int zajednicki = NZD(b,n);
        b=b/zajednicki;
        n=n/zajednicki;
        brojnik = b;
        nazivnik = n;
    }
    
    Razlomak(std::initializer_list<long long int> lista)
    {
        if(lista.size() == 0)
        {
            brojnik = 0;
            nazivnik = 1;
        }
        else if(lista.size() == 1)
        {
            brojnik = *(lista.begin());
            nazivnik = 1;
        }
        else
        {
            auto it = lista.begin();
            long long int b,n;
            b = *it;
            it++;
            n = *it;
            long long int zajednicki = NZD(b,n);
            b=b/zajednicki;
            n=n/zajednicki;
            brojnik=b;
            nazivnik=n;
        }
    }
    
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    friend std::ostream &operator <<(std::ostream &tok, Razlomak r);
    friend std::istream &operator >>(std::istream &tok, Razlomak &r);
    friend Razlomak operator + (const Razlomak&, const Razlomak&);
    friend Razlomak operator - (const Razlomak&, const Razlomak&);
    friend Razlomak operator * (const Razlomak&, const Razlomak&);
    friend Razlomak operator / (const Razlomak&, const Razlomak&);
    friend Razlomak operator + (const Razlomak&);
    friend Razlomak operator - (const Razlomak&);
    friend Razlomak &operator += (Razlomak&, const Razlomak&);
    friend Razlomak &operator -= (Razlomak&, const Razlomak&);
    friend Razlomak &operator *= (Razlomak&, const Razlomak&);
    friend Razlomak &operator /= (Razlomak&, const Razlomak&);
    friend Razlomak &operator ++ (Razlomak&);
    friend Razlomak operator ++ (Razlomak&, int);
    friend Razlomak &operator -- (Razlomak&);
    friend Razlomak operator -- (Razlomak&, int);
    friend bool operator < (const Razlomak&, const Razlomak&);
    friend bool operator > (const Razlomak&, const Razlomak&);
    friend bool operator >= (const Razlomak&, const Razlomak&);
    friend bool operator <= (const Razlomak&, const Razlomak&);
    friend bool operator == (const Razlomak&, const Razlomak&);
    friend bool operator != (const Razlomak&, const Razlomak&);
    operator long double() const;
};

Razlomak::operator long double() const
{
    long double b = (brojnik+0.0)/nazivnik;
    return b;
}

bool operator == (const Razlomak &r1, const Razlomak &r2)
{
    if(r1.brojnik == r2.brojnik && r1.nazivnik ==  r2.nazivnik) return true;
    return false;
}

bool operator != (const Razlomak &r1, const Razlomak &r2)
{
    if(r1.brojnik == r2.brojnik && r1.nazivnik == r2.nazivnik) return false;
    return true;
}

bool operator <= (const Razlomak &r1, const Razlomak &r2)
{
    long double b1,b2;
    b1 = r1.brojnik/r1.nazivnik;
    b2 = r2.brojnik/r2.nazivnik;
    return b1<=b2;
}

bool operator >= (const Razlomak &r1, const Razlomak &r2)
{
    long double b1,b2;
    b1 = r1.brojnik/r1.nazivnik;
    b2 = r2.brojnik/r2.nazivnik;
    return b1 >= b2;
}

bool operator < (const Razlomak &r1, const Razlomak &r2)
{
    long double b1,b2;
    b1 = r1.brojnik/r1.nazivnik;
    b2 = r2.brojnik/r2.nazivnik;
    return b1 < b2;
}

bool operator > (const Razlomak &r1, const Razlomak &r2)
{
    long double b1,b2;
    b1 = r1.brojnik/r1.nazivnik;
    b2 = r2.brojnik/r2.nazivnik;
    return b1 > b2;
}

Razlomak &operator -- (Razlomak &r)
{
    Razlomak::provjera(r.brojnik, r.nazivnik, 2);
    r = Razlomak(r.brojnik - r.nazivnik, r.nazivnik);
    return r;
}

Razlomak operator -- (Razlomak &r, int)
{
    Razlomak::provjera(r.brojnik, r.nazivnik, 2);
    auto rr = r;
    r = Razlomak(r.brojnik-r.nazivnik, r.nazivnik);
    return rr;
}

Razlomak &operator ++ (Razlomak &r)
{
    Razlomak::provjera(r.brojnik, r.nazivnik, 1);
    r = Razlomak(r.brojnik + r.nazivnik, r.nazivnik);
    return r;
}

Razlomak operator ++ (Razlomak &r, int)
{
    Razlomak::provjera(r.brojnik, r.nazivnik, 1);
    auto rr = r;
    r = Razlomak(r.brojnik+r.nazivnik, r.nazivnik);
    return rr;
}

Razlomak &operator += (Razlomak &r1, const Razlomak &r2)
{
    r1 = r1 + r2;
    return r1;
}

Razlomak &operator -= (Razlomak &r1, const Razlomak &r2)
{
    r1 = r1 - r2;
    return r1;
}

Razlomak &operator *= (Razlomak &r1, const Razlomak &r2)
{
    r1 = r1 * r2;
    return r1;
}

Razlomak &operator /= (Razlomak &r1, const Razlomak &r2)
{
    r1 = r1/r2;
    return r1;
}

Razlomak operator + (const Razlomak &r)
{
    return r;
}

Razlomak operator - (const Razlomak &r)
{
    if(r.brojnik == std::numeric_limits<long long int>::lowest()) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return Razlomak(r.brojnik*(-1), r.nazivnik);
}

Razlomak operator + (const Razlomak &r1, const Razlomak &r2)
{
    long long int r = Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    Razlomak::provjera(r1.brojnik, r2.nazivnik/r, 3);
    Razlomak::provjera(r2.brojnik, r1.nazivnik/r, 3);
    Razlomak::provjera(r1.nazivnik, r2.nazivnik/r, 3);
    Razlomak::provjera(r1.brojnik*(r2.nazivnik/r), r2.brojnik*(r1.nazivnik/r), 1);
    return Razlomak(r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r),r1.nazivnik*(r2.nazivnik/r));
}

Razlomak operator - (const Razlomak &r1, const Razlomak &r2)
{
    long long int r = Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    Razlomak::provjera(r1.brojnik, r2.nazivnik/r, 3);
    Razlomak::provjera(r2.brojnik, r1.nazivnik/r, 3);
    Razlomak::provjera(r1.nazivnik, r2.nazivnik/r, 3);
    Razlomak::provjera(r1.brojnik*(r2.nazivnik/r), r2.brojnik*(r1.nazivnik/r), 2);
    return Razlomak(r1.brojnik*(r2.nazivnik/r)-r2.brojnik*(r1.nazivnik/r),r1.nazivnik*(r2.nazivnik/r));
}

Razlomak operator * (const Razlomak &r1, const Razlomak &r2)
{
    long long int s,t;
    s = Razlomak::NZD(r1.brojnik, r2.nazivnik);
    t = Razlomak::NZD(r2.brojnik, r1.nazivnik);
    Razlomak::provjera(r1.brojnik/s, r2.brojnik/t, 3);
    Razlomak::provjera(r1.nazivnik/t, r2.nazivnik/s, 3);
    return Razlomak((r1.brojnik/s)*(r2.brojnik/t),(r1.nazivnik/t)*(r2.nazivnik/s));
}

Razlomak operator / (const Razlomak &r1, const Razlomak &r2)
{
    long long int u,r;
    r=Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    u=Razlomak::NZD(r1.brojnik, r2.brojnik);
    Razlomak::provjera(r1.brojnik/u, r2.nazivnik/r, 3);
    Razlomak::provjera(r1.nazivnik/r, r2.brojnik/u, 3);
    return Razlomak((r1.brojnik/u)*(r2.nazivnik/r), (r1.nazivnik/r)*(r2.brojnik/u));
}

std::ostream &operator << (std::ostream &tok, Razlomak r)
{
    if(r.nazivnik == 1) tok << r.brojnik;
    else tok << r.brojnik << "/" << r.nazivnik;
    return tok;
}

std::istream &operator >> (std::istream &tok, Razlomak &r)
{
    long long int br,naz;
    char z;
    tok >> br;
    if(tok.eof())
    {
        r.brojnik=br;
        r.nazivnik=1;
        return tok;
    }
    z = tok.peek();
    if(z == ' ' || z == '\n' || z=='\r' || z=='\f' || z=='\v' || z=='\t')
    {
        r.brojnik = br;
        r.nazivnik = 1;
        return tok;
    }
    else if(z=='/')
    {
        tok >> z;
        if(tok.eof()||tok.peek()==' '||tok.peek()=='\n'||tok.peek()=='\f'||tok.peek()=='\v'||tok.peek()=='\t'||tok.peek()=='\r')
        {
            tok.setstate(std::ios::failbit);
            return tok;
        }
        tok >> naz;
        /*if(!tok.eof()&&tok.peek() != ' '&& tok.peek()!='\n'&&tok.peek()!='\f'&&tok.peek()!='\v'&&tok.peek()!='\t'&&tok.peek()!='\r')
        {
            r.brojnik = br;
            r.nazivnik = naz;
            tok.setstate(std::ios::failbit);
            return tok;
        }*/
        if(tok.eof()||tok.peek()==' '||tok.peek()=='\n'||tok.peek()=='\r'||tok.peek()=='\f'||tok.peek()=='\v'||tok.peek()=='\t');
        else
        {
            tok.setstate(std::ios::failbit);
            return tok;
        }
        try
        {
            r = Razlomak(br,naz);
        }
        catch(...)
        {
            tok.setstate(std::ios::failbit);
            return tok;
        }
    }
    else tok.setstate(std::ios::failbit);
    return tok;
}

int main ()
{
	return 0;
}
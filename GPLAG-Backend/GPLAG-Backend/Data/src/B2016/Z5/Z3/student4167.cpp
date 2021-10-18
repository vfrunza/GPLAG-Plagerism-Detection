/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>

#define MAX std::numeric_limits<long long int>::max()
#define MIN std::numeric_limits<long long int>::min()

class Razlomak {
    long long int brojnik, nazivnik;
    static long long int NZD(const long long int &x, const long long int &y);
public:
    Razlomak(long long int brojnik=0, long long int nazivnik=1);
    long long int DajBrojnik() const {return brojnik;}
    long long int DajNazivnik() const {return nazivnik;}
    friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator +(const Razlomak &r);
    friend Razlomak operator -(const Razlomak &r);
    friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator ++(Razlomak &r);
    friend Razlomak &operator --(Razlomak &r);
    friend Razlomak operator ++(Razlomak &r, int);
    friend Razlomak operator --(Razlomak &r, int);
    friend bool operator <(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2);
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r);
    friend std::istream &operator >>(std::istream &tok, Razlomak &r);
    operator long double() const {return static_cast<long double>(this->DajBrojnik())/this->DajNazivnik();}
};

long long int Razlomak::NZD(const long long int &x, const long long int &y) {
    long long int p(x), q(y), modulo(0);
    while(1) {
        modulo=p%q;
        p=q;
        q=modulo;
        if(q==0) {
            modulo=p;
            break;
        }
    }
    return p;
}

Razlomak::Razlomak(long long int brojnik, long long int nazivnik) {
    if(nazivnik==0) throw std::logic_error("Nekorektan razlomak");
    if(nazivnik<0) {
        brojnik=-brojnik; nazivnik=-nazivnik;
    }
    auto temp(NZD(brojnik,nazivnik));
    brojnik/=temp; nazivnik/=temp;
    Razlomak::brojnik=brojnik;
    Razlomak::nazivnik=nazivnik;
}

Razlomak operator +(const Razlomak &r1, const Razlomak &r2) {
    long long int p1(r1.DajBrojnik()), q1(r1.DajNazivnik()), p2(r2.DajBrojnik()), q2(r2.DajNazivnik());
    long long int r(Razlomak::NZD(q1, q2));
    if(((q2/r)>0 and (p1<(MIN/(q2/r)) or p1>(MAX/(q2/r)))) or ((q2/r)<0 and (p1==MIN or -p1>MAX/(-q2/r) or -p1<MIN/(-q2/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(((q1/r)>0 and (p2<(MIN/(q1/r)) or p2>(MAX/(q1/r)))) or ((q1/r)<0 and (p2==MIN or -p2>MAX/(-q1/r) or -p2<MIN/(-q1/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(((q2/r)>0 and (q1<(MIN/(q2/r)) or q1>(MAX/(q2/r)))) or ((q2/r)<0 and (q1==MIN or -q1>MAX/(-q2/r) or -q1<MIN/(-q2/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int temp1(p1*(q2/r)), temp2(p2*(q1/r));
    if((temp2>0 and temp1>MAX-temp2) or (temp2<0 and temp1<MIN-temp2))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return {(temp1+temp2), q1*(q2/r)};
}

Razlomak operator -(const Razlomak &r1, const Razlomak &r2) {
    long long int p1(r1.DajBrojnik()), q1(r1.DajNazivnik()), p2(r2.DajBrojnik()), q2(r2.DajNazivnik());
    long long int r(Razlomak::NZD(q1, q2));
    if(((q2/r)>0 and (p1<(MIN/(q2/r)) or p1>(MAX/(q2/r)))) or ((q2/r)<0 and (p1==MIN or -p1>MAX/(-q2/r) or -p1<MIN/(-q2/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(((q1/r)>0 and (p2<(MIN/(q1/r)) or p2>(MAX/(q1/r)))) or ((q1/r)<0 and (p2==MIN or -p2>MAX/(-q1/r) or -p2<MIN/(-q1/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(((q2/r)>0 and (q1<(MIN/(q2/r)) or q1>(MAX/(q2/r)))) or ((q2/r)<0 and (q1==MIN or -q1>MAX/(-q2/r) or -q1<MIN/(-q2/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int temp1(p1*(q2/r)), temp2(p2*(q1/r));
    if((temp2<0 and temp1>MAX+temp2) or (temp2>0 and temp1<MIN+temp2))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return {(temp1-temp2),q1*(q2/r)};
}

Razlomak operator *(const Razlomak &r1, const Razlomak &r2) {
    long long int p1(r1.DajBrojnik()), q1(r1.DajNazivnik()), p2(r2.DajBrojnik()), q2(r2.DajNazivnik());
    long long int s(Razlomak::NZD(p1, q2));
    long long int t(Razlomak::NZD(p2, q1));
    if(((p2/t)>0 and ((p1/s)<(MIN/(p2/t)) or (p1/s)>(MAX/(p2/t)))) or ((p2/t)<0 and ((p1/s)==MIN or -(p1/s)>MAX/(-p2/t) or -(p1/s)<MIN/(-p2/t))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(((q2/s)>0 and ((q1/t)<(MIN/(q2/s)) or (q1/t)>(MAX/(q2/s)))) or ((q2/s)<0 and ((q1/t)==MIN or -(q1/t)>MAX/(-q2/s) or -(q1/t)<MIN/(-q2/s))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return {((p1/s)*(p2/t)),((q1/t)*(q2/s))};
}

Razlomak operator /(const Razlomak &r1, const Razlomak &r2) {
    long long int p1(r1.DajBrojnik()), q1(r1.DajNazivnik()), p2(r2.DajBrojnik()), q2(r2.DajNazivnik());
    long long int r(Razlomak::NZD(q1, q2));
    long long int u(Razlomak::NZD(p1, p2));
    if(((q2/r)>0 and ((p1/u)<(MIN/(q2/r)) or (p1/u)>(MAX/(q2/r)))) or ((q2/r)<0 and ((p1/u)==MIN or -(p1/u)>MAX/(-q2/r) or -(p1/u)<MIN/(-q2/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(((p2/u)>0 and ((q1/r)<(MIN/(p2/u)) or (q1/r)>(MAX/(p2/u)))) or ((p2/u)<0 and ((q1/r)==MIN or -(q1/r)>MAX/(-p2/u) or -(q1/r)<MIN/(-p2/u))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return {((p1/u)*(q2/r)),((q1/r)*(p2/u))};
}

Razlomak operator +(const Razlomak &r) {
    return {r.DajBrojnik(), r.DajNazivnik()};
}

Razlomak operator -(const Razlomak &r) {
    if(r.DajBrojnik()==MIN)
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return {-r.DajBrojnik(), r.DajNazivnik()};
}

Razlomak &operator +=(Razlomak &r1, const Razlomak &r2) {
    long long int p1(r1.DajBrojnik()), q1(r1.DajNazivnik()), p2(r2.DajBrojnik()), q2(r2.DajNazivnik());
    long long int r(Razlomak::NZD(q1, q2));
    if(((q2/r)>0 and (p1<(MIN/(q2/r)) or p1>(MAX/(q2/r)))) or ((q2/r)<0 and (p1==MIN or -p1>MAX/(-q2/r) or -p1<MIN/(-q2/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(((q1/r)>0 and (p2<(MIN/(q1/r)) or p2>(MAX/(q1/r)))) or ((q1/r)<0 and (p2==MIN or -p2>MAX/(-q1/r) or -p2<MIN/(-q1/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(((q2/r)>0 and (q1<(MIN/(q2/r)) or q1>(MAX/(q2/r)))) or ((q2/r)<0 and (q1==MIN or -q1>MAX/(-q2/r) or -q1<MIN/(-q2/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int temp1(p1*(q2/r)), temp2(p2*(q1/r));
    if((temp2>0 and temp1>MAX-temp2) or (temp2<0 and temp1<MIN-temp2))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    r1={temp1+temp2, q1*(q2/r)};
    return r1;
}

Razlomak &operator -=(Razlomak &r1, const Razlomak &r2) {
    long long int p1(r1.DajBrojnik()), q1(r1.DajNazivnik()), p2(r2.DajBrojnik()), q2(r2.DajNazivnik());
    long long int r(Razlomak::NZD(q1, q2));
    if(((q2/r)>0 and (p1<(MIN/(q2/r)) or p1>(MAX/(q2/r)))) or ((q2/r)<0 and (p1==MIN or -p1>MAX/(-q2/r) or -p1<MIN/(-q2/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(((q1/r)>0 and (p2<(MIN/(q1/r)) or p2>(MAX/(q1/r)))) or ((q1/r)<0 and (p2==MIN or -p2>MAX/(-q1/r) or -p2<MIN/(-q1/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(((q2/r)>0 and (q1<(MIN/(q2/r)) or q1>(MAX/(q2/r)))) or ((q2/r)<0 and (q1==MIN or -q1>MAX/(-q2/r) or -q1<MIN/(-q2/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int temp1(p1*(q2/r)), temp2(p2*(q1/r));
    if((temp2<0 and temp1>MAX-temp2) or (temp2>0 and temp1<MIN-temp2))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    r1={temp1-temp2, q1*(q2/r)};
    return r1;
}

Razlomak &operator *=(Razlomak &r1, const Razlomak &r2) {
    long long int p1(r1.DajBrojnik()), q1(r1.DajNazivnik()), p2(r2.DajBrojnik()), q2(r2.DajNazivnik());
    long long int s(Razlomak::NZD(p1, q2));
    long long int t(Razlomak::NZD(p2, q1));
    if(((p2/t)>0 and ((p1/s)<(MIN/(p2/t)) or (p1/s)>(MAX/(p2/t)))) or ((p2/t)<0 and ((p1/s)==MIN or -(p1/s)>MAX/(-p2/t) or -(p1/s)<MIN/(-p2/t))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(((q2/s)>0 and ((q1/t)<(MIN/(q2/s)) or (q1/t)>(MAX/(q2/s)))) or ((q2/s)<0 and ((q1/t)==MIN or -(q1/t)>MAX/(-q2/s) or -(q1/t)<MIN/(-q2/s))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    r1 = {((p1/s)*(p2/t)),((q1/t)*(q2/s))};
    return r1;
}

Razlomak &operator /=(Razlomak &r1, const Razlomak &r2) {
    long long int p1(r1.DajBrojnik()), q1(r1.DajNazivnik()), p2(r2.DajBrojnik()), q2(r2.DajNazivnik());
    long long int r(Razlomak::NZD(q1, q2));
    long long int u(Razlomak::NZD(p1, p2));
    if(((q2/r)>0 and ((p1/u)<(MIN/(q2/r)) or (p1/u)>(MAX/(q2/r)))) or ((q2/r)<0 and ((p1/u)==MIN or -(p1/u)>MAX/(-q2/r) or -(p1/u)<MIN/(-q2/r))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(((p2/u)>0 and ((q1/r)<(MIN/(p2/u)) or (q1/r)>(MAX/(p2/u)))) or ((p2/u)<0 and ((q1/r)==MIN or -(q1/r)>MAX/(-p2/u) or -(q1/r)<MIN/(-p2/u))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    r1 = {((p1/u)*(q2/r)),((q1/r)*(p2/u))};
    return r1;
}

Razlomak &operator ++(Razlomak &r) {
    if((r.DajNazivnik()>0 and r.DajBrojnik()>MAX-r.DajNazivnik()) or (r.DajNazivnik()<0 and r.DajBrojnik()<MIN-r.DajNazivnik()))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    r = {r.DajBrojnik()+r.DajNazivnik(), r.DajNazivnik()};
    return r;
}

Razlomak &operator --(Razlomak &r) {
    if((r.DajNazivnik()<0 and r.DajBrojnik()>MAX-r.DajNazivnik()) or (r.DajNazivnik()>0 and r.DajBrojnik()<MIN-r.DajNazivnik()))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    r = {r.DajBrojnik()-r.DajNazivnik(), r.DajNazivnik()};
    return r;
}

Razlomak operator ++(Razlomak &r, int) {
    Razlomak pomocni(r);
    if((r.DajNazivnik()>0 and r.DajBrojnik()>MAX-r.DajNazivnik()) or (r.DajNazivnik()<0 and r.DajBrojnik()<MIN-r.DajNazivnik()))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    r = {r.DajBrojnik()+r.DajNazivnik(), r.DajNazivnik()};
    return pomocni;
}

Razlomak operator --(Razlomak &r, int) {
    Razlomak pomocni(r);
    if((r.DajNazivnik()<0 and r.DajBrojnik()>MAX-r.DajNazivnik()) or (r.DajNazivnik()>0 and r.DajBrojnik()<MIN-r.DajNazivnik()))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    r = {r.DajBrojnik()-r.DajNazivnik(), r.DajNazivnik()};
    return pomocni;
}

bool operator <(const Razlomak &r1, const Razlomak &r2) {
    long double temp1(static_cast<long double>(r1.DajBrojnik())/r1.DajNazivnik()),
                temp2(static_cast<long double>(r2.DajBrojnik())/r2.DajNazivnik());
    return temp1<temp2;
}

bool operator >(const Razlomak &r1, const Razlomak &r2) {
    long double temp1(static_cast<long double>(r1.DajBrojnik())/r1.DajNazivnik()),
                temp2(static_cast<long double>(r2.DajBrojnik())/r2.DajNazivnik());
    return temp1>temp2;
}

bool operator <=(const Razlomak &r1, const Razlomak &r2) {
    long double temp1(static_cast<long double>(r1.DajBrojnik())/r1.DajNazivnik()),
                temp2(static_cast<long double>(r2.DajBrojnik())/r2.DajNazivnik());
    return temp1<=temp2;
}

bool operator >=(const Razlomak &r1, const Razlomak &r2) {
    long double temp1(static_cast<long double>(r1.DajBrojnik())/r1.DajNazivnik()),
                temp2(static_cast<long double>(r2.DajBrojnik())/r2.DajNazivnik());
    return temp1>=temp2;
}

bool operator ==(const Razlomak &r1, const Razlomak &r2) {
    long double temp1(static_cast<long double>(r1.DajBrojnik())/r1.DajNazivnik()),
                temp2(static_cast<long double>(r2.DajBrojnik())/r2.DajNazivnik());
    return temp1-temp2<1e-14;
}

bool operator !=(const Razlomak &r1, const Razlomak &r2) {
    long double temp1(static_cast<long double>(r1.DajBrojnik())/r1.DajNazivnik()),
                temp2(static_cast<long double>(r2.DajBrojnik())/r2.DajNazivnik());
    return temp1-temp2>1e-14;
}

std::ostream &operator <<(std::ostream &tok, const Razlomak &r) {
    if(r.DajNazivnik()==1) tok << r.DajBrojnik();
    else tok << r.DajBrojnik() << "/" << r.DajNazivnik();
    return tok;
}

std::istream &operator >>(std::istream &tok, Razlomak &r) {
    char znak;
    long long int brojnik, nazivnik;
    tok >> std::ws;
    tok >> brojnik;
    if(char(tok.peek())!='/') nazivnik=1;
    else {
        tok >> znak >> nazivnik;
        if(tok.peek()!=' ' and tok.peek()!='\n' and tok.peek()!='\t')
            tok.setstate(std::ios::failbit);
    }
    if(!tok) tok.setstate(std::ios::failbit);
    r={brojnik,nazivnik};
    //tok.ignore(1000, '\n');
    //tok.clear();
    return tok;
}

int main ()
{
    std::cout << "Unesite razlomke:" << std::endl;
    Razlomak r1, r2;
    std::cin >> r1;
    std::cin >> r2;
    std::cout << r1 << " " << r2 << std::endl;
    std::cout << r1+r2;
	return 0;
}
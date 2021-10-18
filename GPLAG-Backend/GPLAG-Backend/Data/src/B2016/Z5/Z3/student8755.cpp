/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cmath>
#include <climits>
#include <stdexcept>
auto m(LLONG_MIN);
auto M(LLONG_MAX);
static long long int NZD(long long int a, long long int b){return b==0 ? a:NZD(b, a%b);}
class Razlomak
{
    long long int p;
    long long int q;
    
        public:
            Razlomak(long long int brojnik, long long int nazivnik);
            Razlomak(long long int brojnik){p=brojnik; q=1;}
            Razlomak(){p=0; q=1;}
            static long long int canPlus(long long int x, long long int y);
            static long long int canMinus(long long int x, long long int y);
            static long long int canMulti(long long int x, long long int y);
            long long int DajBrojnik() const{return p;}
            long long int DajNazivnik() const{return q;}
            friend Razlomak operator +(Razlomak x, Razlomak y);
            friend Razlomak operator -(Razlomak x, Razlomak y);
            friend Razlomak operator *(Razlomak x, Razlomak y);
            friend Razlomak operator /(Razlomak x, Razlomak y);
            friend void operator -(Razlomak &x){x.p*=(-1);}
            friend Razlomak operator +(Razlomak x){return x;}
            friend void operator +=(Razlomak &x, const Razlomak &y){x=x+y;}
            friend void operator -=(Razlomak &x, const Razlomak &y){x=x-y;}
            friend void operator *=(Razlomak &x, const Razlomak &y){x=x*y;}
            friend void operator /=(Razlomak &x, const Razlomak &y){x=x/y;}
            friend void operator ++(Razlomak &x){x.p+=x.q;}
            friend void operator --(Razlomak &x){x.p-=x.q;}
            friend std::istream& operator >> (std::istream& ulaz, Razlomak &x);
            
};
Razlomak::Razlomak(long long int brojnik, long long int nazivnik)
{
    if(nazivnik<0){p=brojnik*(-1); q=nazivnik*(-1);}
    else {p=brojnik; q=nazivnik;}
    auto djelioc(NZD(std::abs(brojnik), std::abs(nazivnik)));
    p=brojnik/djelioc; q=nazivnik/djelioc;
}
Razlomak operator +(Razlomak x, Razlomak y)
{
    auto p1(x.DajBrojnik()); auto p2(y.DajBrojnik());
    auto q1(x.DajNazivnik()); auto q2(y.DajNazivnik());
    auto br(Razlomak::canPlus(Razlomak::canMulti(p1,(q2/NZD(q1,q2))),Razlomak::canMulti(p2,(q1/NZD(q1,q2)))));
    auto na=Razlomak::canMulti(q1,(q2/NZD(q1,q2)));
    return Razlomak{br,na};
}
Razlomak operator -(Razlomak x, Razlomak y)
{
    auto p1(x.DajBrojnik()); auto p2(y.DajBrojnik());
    auto q1(x.DajNazivnik()); auto q2(y.DajNazivnik());
    auto br(Razlomak::canMinus(Razlomak::canMulti(p1,(q2/NZD(q1,q2))),Razlomak::canMulti(p2,(q1/NZD(q1,q2)))));
    auto na=Razlomak::canMulti(q1,(q2/NZD(q1,q2)));
    return Razlomak{br,na};
}
Razlomak operator *(Razlomak x, Razlomak y)
{
    Razlomak z;
    z.p=Razlomak::canMulti((x.p/NZD(x.p,y.q)),(y.p/NZD(y.p,x.q)));
    z.q=Razlomak::canMulti((x.q/NZD(y.p,x.q)),(y.q)/NZD(x.p,y.q));
    return z;
}
Razlomak operator /(Razlomak x, Razlomak y)
{
    Razlomak z;
    z.p=Razlomak::canMulti((x.p/NZD(x.p,y.p)),(y.q/NZD(x.q,y.q)));
    z.q=Razlomak::canMulti((x.q/NZD(x.q,y.q)),(y.p)/NZD(x.p,y.p));
    return z;
}
long long int Razlomak::canPlus(long long int x, long long int y)
{
    if(y>0 && x>M-y)    throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(y>0 && x<m-y)    throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return x+y;
}
long long int Razlomak::canMinus(long long int x, long long int y)
{
    if(y>0 && x>M+y)    throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(y>0 && x<m+y)    throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return x-y;
}
long long int Razlomak::canMulti(long long int x, long long int y)
{
    if(y>0 && (x<m/y || x>M/y))    throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(y>0 && (x==m || -x>M/(-y) || -x<m/(-y)))    throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return x*y;
}
std::istream& operator>>(std::istream& ulaz, Razlomak &x)
{
    char a;
    ulaz >> std::ws;
    ulaz>>x.p;
    if(ulaz.peek()!='/')    x.q=1;
    else
    {
        ulaz >>a;
        ulaz >>x.q;
    }
    if(ulaz.peek()!=' ') ulaz.setstate(std::ios::failbit);
    return ulaz;
}
std::ostream& operator<<(std::ostream& izlaz, Razlomak x)
{
    Razlomak temp(x.DajBrojnik(), x.DajNazivnik());
    if(temp.DajBrojnik()&temp.DajNazivnik()==0) return izlaz<<temp.DajBrojnik()/temp.DajNazivnik();
    else if(temp.DajBrojnik()!= 0 && temp.DajNazivnik()!=1) return izlaz<<temp.DajBrojnik()<<"/"<<temp.DajNazivnik();
    else return izlaz << temp.DajBrojnik();
}
int main ()
{
	return 0;
}
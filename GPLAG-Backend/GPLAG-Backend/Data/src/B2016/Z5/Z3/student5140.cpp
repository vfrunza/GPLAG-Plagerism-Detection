/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>

const long long int m(std::numeric_limits<long long int>::min());
const long long int M(std::numeric_limits<long long int>::min());

static long long int NZD(long long int p, long long int q){
    while(q!=0){
        long long int pomocna;
        pomocna=p;
        p=q;
        q=pomocna%q;
    }
    return p;
}


class Razlomak{
    long long int brojnik,nazivnik;
    static long long int NZD();
public:
    Razlomak(long long int x, long long int y) {
        if(y==0)
            throw std::logic_error("Nekorektan razlomak");
        long long int skrati;
        skrati=::NZD(x,y);
        x/=skrati;
        y/=skrati;
        if(x<0 && y<0) {x=(-1)*x; y=(-1)*y;}
        else if(y<0) {x=(-1)*x; y=(-1)*y;}
        brojnik=x; nazivnik=y;
    }
    Razlomak(long long int x) {brojnik=x; nazivnik=1;}
    Razlomak() {brojnik=0; nazivnik=1;}
    Razlomak(std::initializer_list<long long int> lista){ 
        std::vector<long long int> v(lista);
        Razlomak(v[0],v[1]);
    }
    long long int DajBrojnik() const {return brojnik;}
    long long int DajNazivnik() const {return nazivnik;}
    friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2){
        long long int q1(r1.DajNazivnik());
        long long int q2(r2.DajNazivnik());
        long long int p1(r1.DajBrojnik());
        long long int p2(r2.DajBrojnik());
        auto r(::NZD(q1,q2));
        Razlomak vrati(p1*(q2/r)+p2*(q1/r),q1*(q2/r));
        return vrati;
    }
    friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2){
        long long int q1(r1.DajNazivnik());
        long long int q2(r2.DajNazivnik());
        long long int p1(r1.DajBrojnik());
        long long int p2(r2.DajBrojnik());
        auto r(::NZD(q1,q2));
        Razlomak vrati(p1*(q2/r)-p2*(q1/r),q1*(q2/r));
        return vrati;
    }
    friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2){
        long long int q1(r1.DajNazivnik());
        long long int q2(r2.DajNazivnik());
        long long int p1(r1.DajBrojnik());
        long long int p2(r2.DajBrojnik());
        auto s(::NZD(p1,q2));
        auto t(::NZD(p2,q1));
        Razlomak vrati((p1/s)*(p2/t),(q1/t)*(q2/s));
        return vrati;
    }
   friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2){
        long long int q1(r1.DajNazivnik());
        long long int q2(r2.DajNazivnik());
        long long int p1(r1.DajBrojnik());
        long long int p2(r2.DajBrojnik());
        auto r(::NZD(q1,q2));
        auto u(::NZD(p1,p2));
        Razlomak vrati((p1/u)*(q2/r),(q1/r)*(p2/u));
        return vrati;
    }
    friend Razlomak &operator -(Razlomak &r){
        r.brojnik=(-1)*r.brojnik;
        return r;
    }
    friend Razlomak &operator +(Razlomak &r){return r;}
    friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2){
        r1=r1+r2;
        return r1;
    }
    friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2){
        r1=r1-r2;
        return r1;
    }
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2){
        r1=r1*r2;
        return r1;
    }
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2){
        r1=r1/r2;
        return r1;
    }
    friend Razlomak &operator ++(Razlomak &r1){
        r1=r1+Razlomak(1,1);
        return r1;
    }
    friend Razlomak &operator --(Razlomak &r1){
        r1=r1-Razlomak(1,1);
        return r1;
    }
    friend Razlomak operator --(Razlomak &r1, int){
        auto vrati(r1);
        r1=r1-Razlomak(1,1);
        return vrati;
    }
    friend Razlomak operator ++(Razlomak &r1, int){
        auto vrati(r1);
        r1=r1+Razlomak(1,1);
        return vrati;
    }
    friend bool operator <(const Razlomak &r1, const Razlomak &r2){
        long double v1(((long double)r1.brojnik)/r1.nazivnik);
        long double v2(((long double)r2.brojnik)/r2.nazivnik);
        return v1<v2;
    }
    friend bool operator >(const Razlomak &r1, const Razlomak &r2){
        long double v1(((long double)r1.brojnik)/r1.nazivnik);
        long double v2(((long double)r2.brojnik)/r2.nazivnik);
        return v1>v2;
    }
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2){
        long double v1(((long double)r1.brojnik)/r1.nazivnik);
        long double v2(((long double)r2.brojnik)/r2.nazivnik);
        return v1<=v2;
    }
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2){
        long double v1(((long double)r1.brojnik)/r1.nazivnik);
        long double v2(((long double)r2.brojnik)/r2.nazivnik);
        return v1>=v2;
    }
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2){
        long double v1(((long double)r1.brojnik)/r1.nazivnik);
        long double v2(((long double)r2.brojnik)/r2.nazivnik);
        return v1==v2;
    }
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2){
        long double v1(((long double)r1.brojnik)/r1.nazivnik);
        long double v2(((long double)r2.brojnik)/r2.nazivnik);
        return !(v1==v2);
    }
    friend std::ostream &operator <<(std::ostream &tok,const Razlomak &r){
        if(r.nazivnik==1)
            tok << r.brojnik;
        else
            tok << r.brojnik << "/" << r.nazivnik;
        return tok;
    }
    friend std::istream &operator >>(std::istream &tok, Razlomak &r){
        char znak;
        long long int x,y;
        tok >> std::ws;
        tok >> x;
        if(tok.peek()!='/'){ r=Razlomak(x);}
        else if (tok.peek()=='/'){ tok >> znak >> y; r=Razlomak(x,y);}
        else tok.setstate(std::ios::failbit);
        return tok;
    }
    operator long double () const{
        return (((long double)brojnik)/nazivnik);
    }
};

/*struct RazlomakBroj{
    long long int x;
    RazlomakBroj(long long int x): x(x) {};
};
 Razlomak operator /(const RazlomakBroj &b, const RazlomakBroj &n) {return {b.x,n.x};}
 RazlomakBroj operator "" _r (unsigned long long int x) {return RazlomakBroj(x);}*/

int main ()
{
	return 0;
}
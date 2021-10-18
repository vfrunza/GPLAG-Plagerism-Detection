/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <limits>
#include <stdexcept>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
class Razlomak{
    long long int a=0,b=1;
    void checkOverflow(long long int, long long int, int);
    void throwerr(){throw std::overflow_error("Nemoguce dobiti tacan rezultat");}
    public:
    static long long int NZD(long long int a, long long int b){if(!b)return a;return NZD(b,a%b);}
    Razlomak(long long int a,long long int b){
        this->a = a/std::abs(NZD(a,b));
        if(b<0)this->a*=-1;
        this->b = std::abs(b/NZD(a,b));
    }
    Razlomak(long long int a=0): a(a),b(1){}
    Razlomak operator + (Razlomak r){
        checkOverflow(a*(r.b/std::abs(NZD(b,r.b))),r.a * (b/ std::abs(NZD(b,r.b))),1);
        checkOverflow(b,r.b/NZD(r.b,b),2);
        return Razlomak(a*(r.b/std::abs(NZD(b,r.b))) + r.a * (b/ std::abs(NZD(b,r.b))),b*(r.b/std::abs(NZD(r.b,b))));
    }
    Razlomak operator * (Razlomak r){
        long long int s=NZD(r.a,b);
        long long int t=NZD(a,r.b);
        checkOverflow((a/t),(r.a/s),2);
        checkOverflow(b/t,r.b/s,2);
        return Razlomak((a/t)*(r.a/s),(b/t)*(r.b/s));
    }
    Razlomak operator / (Razlomak r){
        long long int u = NZD(a,r.a);
        long long int e = NZD(b,r.b);
        checkOverflow((a/b),(r.b/e),1);
        checkOverflow((b/e) , (r.a/u),1);
        return Razlomak((a/u)*(r.b/e),(b/e)*(r.a/u));
    }
    Razlomak operator - (){
        if(a==(std::numeric_limits<long long int>::min()))throwerr();
        return Razlomak(a*=-1,b);
    }
    Razlomak operator - (Razlomak r){
        return *this + Razlomak(-r.a,r.b);
    }
    Razlomak operator + () const {return *this;}
    Razlomak &operator += (Razlomak r){*this = *this + r;return *this;}
    Razlomak &operator *= (Razlomak r){*this = *this * r;return *this;}
    Razlomak &operator /= (Razlomak r){*this = *this / r;return *this;}
    Razlomak &operator -= (Razlomak r){*this = *this - r;return *this;}
    Razlomak &operator ++ (){return *this = *this + Razlomak(1,1);}
    Razlomak operator ++ (int){Razlomak tmp = *this; *this=*this+Razlomak(1,1); return tmp;}
    Razlomak &operator -- (){return *this = *this - Razlomak(1,1);}
    Razlomak operator -- (int){Razlomak tmp = *this; *this = *this +Razlomak(1,1); return tmp;}
    bool operator < (Razlomak r) const {return (a/b<r.a/r.b);}
    bool operator > (Razlomak r) const {return (a/b>r.a/r.b);}
    bool operator >= (Razlomak r) const {return (a/b>=r.a/r.b);}
    bool operator <= (Razlomak r) const {return (a/b<=r.a/r.b);}
    bool operator == (Razlomak r) const {return (a==r.a && b==r.b);}
    bool operator != (Razlomak r) const {return !(*this==r);}
    long long int DajBrojnik() const {return a;}
    long long int DajNazivnik() const {return b;}
    friend std::istream &operator >>(std::istream &in,Razlomak &r);
    friend std::ostream &operator <<(std::ostream &out,const Razlomak &r);
    explicit operator long double(){
        return static_cast<long double>(a)/static_cast<long double>(b);
    }
}; 
std::ostream &operator <<(std::ostream &out,const Razlomak &r){
    out<<r.a;
    if(r.b!=1)out<<"/"<<r.b;
    return out;
}
std::istream &operator >>(std::istream &in, Razlomak &r){
    long long int a=0;
    long long int b=1;
    in>>a;
    char t = in.peek();
    char w[]{' ','\n','\t','\v','\f'};
    for (int i = 0; i < 5; i++) {
        if(t==w[i]){
            r.a=a;
            r.b=1;
            return in;
        }
    }
    if(in.get()!='/'){
        r.a=a;
        r.b=1;
        in.setstate(std::ios::failbit);
        return in;
    }
    in>>b;
    char e=in.peek();
    for (int i = 0; i < 5; i++) {
        if(e==w[i]){
            r=Razlomak(a,b);
            return in;
        }
    }
    r=Razlomak(a,b);
    in.setstate(std::ios::failbit);
    return in;
}
Razlomak operator + (long long int a, Razlomak r){
    return r+Razlomak(a,1);
}
void Razlomak::checkOverflow( long long int a, long long int b,int i){
    const long long int max = (std::numeric_limits<long long int>::max());
    const long long int min = (std::numeric_limits<long long int>::min());
    if(i==1){
        if(b>0){if(a>max-b)throwerr();}
        else {if(a<min-b)throwerr();}
    }
    else if(i==2){
        if(b>0){if(a<min/b || a>max/b)throwerr();}
        else {if(b==min || -a>max/(-b) || -a<min/(-b))throwerr();}
        
    }
}
using std::cout;
using std::cin;
using std::endl;
int main ()
{
    Razlomak a(10,7),b(6,11);
    cout<<a/b;
	return 0;
}
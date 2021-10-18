/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cctype>
#include <stdexcept>
#include <limits>

using namespace std;

void test1(long long int a)
{
    if(a==0) throw logic_error("Nekorektan razlomak");
}

class Razlomak
{
    long long int s, t;
    static long long int n(long long int p, long long int q) {
        long long int k;
        while(q!=0) {
            k=p;
            p=q;
            q=k%q;
        }
        return p;
    }
public:
    Razlomak(long long int b=0, long long int na=1) {
        test1(na);
        if(na<0) {
            na*=-1;
            b*=-1;
        }
        auto p=n(b,na);
        s=b/p;
        t=na/p;
    }
    long long int DajBrojnik() const {
        return s;
    }
    long long int DajNazivnik() const {
        return t;
    }
    friend istream &operator >> (istream &cin, Razlomak &r) {
        r.t=1;
        int d=9;
        cin>>r.s;
        if(cin.peek()==' ' || cin.peek()=='\n') d++;
        else {
            char a;
            cin>>a;
            cin>>r.t;
        }
        return cin;
    }
    friend ostream &operator << (ostream &cout, Razlomak r) {
        cout<<r.s;
        if(r.t!=1) cout<<"/"<<r.t;
        return cout;
    }
    operator long double()const {
        return (long double) s/t;
    }
    friend Razlomak operator + (Razlomak r1, Razlomak r2) {
        Razlomak rez((r1.s*(r2.t/n(r1.t,r2.t))+r2.s*r1.t/n(r1.t,r2.t)),r1.t*r2.t/n(r1.t,r2.t));
        return rez;
    }
    friend Razlomak &operator += (Razlomak &r1, Razlomak r2) {
        r1=r1+r2;
        return r1;
    }
    friend Razlomak operator - (Razlomak r1, Razlomak r2) {
        Razlomak rez=r1+-r2;
        return rez;
    }
    friend Razlomak &operator -= (Razlomak &r1, Razlomak r2) {
        r1=r1-r2;
        return r1;
    }
    friend Razlomak operator * (Razlomak r1, Razlomak r2) {
        Razlomak rez(r1.s/n(r1.s, r2.t)*r2.s/n(r2.s,r1.t), r1.t/n(r2.s,r1.t)*r2.t/n(r1.s, r2.t));
        return rez;
    }
    friend Razlomak &operator *= (Razlomak &r1, Razlomak r2) {
        r1=r1*r2;
        return r1;
    }
    friend Razlomak operator / (Razlomak r1, Razlomak r2) {
        Razlomak rez(r1.s/n(r1.s, r2.s)*r2.t/n(r1.t,r2.t), r1.t/n(r1.t,r2.t)*r2.s/n(r1.s, r2.s));
        return rez;
    }
    friend Razlomak &operator /= (Razlomak &r1, Razlomak r2) {
        r1=r1/r2;
        return r1;
    }
    friend Razlomak &operator +(Razlomak &r) {
        return r;
    }
    friend Razlomak &operator -(Razlomak &r) {
        r.s=-r.s;
        return r;
    }
    friend Razlomak &operator ++(Razlomak &r) {
        Razlomak p {1,1};
        r+=p;
        return r;
    }
    friend Razlomak operator ++(Razlomak &r, int) {
        Razlomak p=r, t {1,1};
        r+=t;
        return p;
    }
    friend bool operator ==(Razlomak r1, Razlomak r2) {
        if( r1.s!=r2.s || r1.t!=r2.t) return false;
        return true;
    }
    friend bool operator !=(Razlomak r1, Razlomak r2) {
        return (r1.s!=r2.s || r1.t!=r2.t);
    }
    friend bool operator >(Razlomak r1, Razlomak r2) {
        long double b1=r1.s/r1.t, b2=r2.s/r2.t;
        return b1>b2;
    }
    friend bool operator <(Razlomak r1, Razlomak r2) {
        long double b1=r1.s/r1.t, b2=r2.s/r2.t;
        return b1<b2;
    }
    friend bool operator >=(Razlomak r1, Razlomak r2) {
        return r1>r2 || r1==r2;
    }
    friend bool operator <=(Razlomak r1, Razlomak r2) {
        return !(r1>r2) || r1==r2;
    }

};

int main ()
{

    return 0;
}
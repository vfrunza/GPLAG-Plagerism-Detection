#include <iostream>
#include <cmath>
#include <initializer_list>

class Razlomak{
    long long int b,n;
    static long long int Nzd(long long int p, long long int q);
public:
    Razlomak() : b(0), n(1){}
    Razlomak(long long int brojnik, long long int nazivnik=1){
        long long int nzd(Nzd(brojnik, nazivnik));
        b=brojnik/nzd; n=nazivnik/nzd;
        if(b*n>0 && b<0 && n<0){b*=-1; n*=-1;}
        if(b*n<0 && n<0){b*=-1; n*=-1;}
    }
    Razlomak(std::initializer_list<long long int> l){
        auto it(l.begin()); b=*it++; n=*it;
        //GOTTA FIX DA RADI NZD() OVDJE;
        if(b*n>0 && b<0 && n<0){b*=-1; n*=-1;}
        if(b*n<0 && n<0){b*=-1; n*=-1;}
    }
    long long int& DajBrojnik(){return b;}
    long long int& DajNazivnik(){return n;}
    friend Razlomak operator+(Razlomak r1, Razlomak r2);
    friend Razlomak operator-(Razlomak r1, Razlomak r2);
    friend Razlomak operator*(Razlomak r1, Razlomak r2);
    friend Razlomak operator/(Razlomak r1, Razlomak r2);
    
};

long long int Nzd(long long int p, long long int q){
    if(q!=0)
        return Nzd(q, p%q);
    else return abs(p);
}
Razlomak operator+(Razlomak r1, Razlomak r2){
    long long int r(Nzd(r1.DajNazivnik(), r2.DajNazivnik()));
    return {r1.DajBrojnik()*(r2.DajNazivnik()/r)+r2.DajBrojnik()*(r1.DajNazivnik()/r), r1.DajNazivnik()*(r2.DajNazivnik()/r)};
}
Razlomak operator-(Razlomak r1, Razlomak r2){
    long long int r(Nzd(r1.DajNazivnik(), r2.DajNazivnik()));
    return {r1.DajBrojnik()*(r2.DajNazivnik()/r)-r2.DajBrojnik()*(r1.DajNazivnik()/r), r1.DajNazivnik()*(r2.DajNazivnik()/r)};
}
Razlomak operator*(Razlomak r1, Razlomak r2){
    long long int s(Nzd(r1.DajBrojnik(), r2.DajNazivnik()));
    long long int t(Nzd(r2.DajBrojnik(), r1.DajNazivnik()));
    return {(r1.DajBrojnik()/s)*(r2.DajBrojnik()/t), (r1.DajNazivnik()/t)*(r2.DajNazivnik()/s)};
}
Razlomak operator/(Razlomak r1, Razlomak r2){
    long long int u(Nzd(r1.DajBrojnik(), r2.DajBrojnik()));
    long long int r(Nzd(r1.DajNazivnik(), r2.DajNazivnik()));
    return {(r1.DajBrojnik()/u)*(r2.DajNazivnik()/r), (r1.DajNazivnik()/r)*(r2.DajBrojnik()/u)};
}

int main (){
	return 0;
}
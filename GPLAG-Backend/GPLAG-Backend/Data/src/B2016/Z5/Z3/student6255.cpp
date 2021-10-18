#include<iostream>
#include<stdexcept>
#include<cmath>
#include<limits>
using namespace std;

class Razlomak{
    long long int brojnik;
    long long int nazivnik;
    static long long int NZD(long long int vr_brojnikak, long long int vr_nazivnika);
    public:
    Razlomak(){ brojnik=0; nazivnik=1; } //bez parametara
    Razlomak(long long int vr_brojnika){ brojnik=vr_brojnika; nazivnik=1; } //s jednim parametrom
    Razlomak(long long int vr_brojnika, long long int vr_nazivnika); 
    long long int DajBrojnik()const{ return brojnik; }
    long long int DajNazivnik()const { return nazivnik; }
    friend Razlomak operator+(const Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak operator-(const Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak operator*(const Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak operator/(const Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak operator+(const Razlomak &r){ return r; }
    friend Razlomak operator-(const Razlomak &r);
    friend Razlomak operator+=(Razlomak &p,const Razlomak &q);
    friend Razlomak operator-=(Razlomak &p,const Razlomak &q);
    friend Razlomak operator*=(Razlomak &p,const Razlomak &q);
    friend Razlomak operator/=(Razlomak &p,const Razlomak &q);
    friend Razlomak &operator++(Razlomak &r);
    friend Razlomak operator++(Razlomak &r,int); 
    friend Razlomak &operator--(Razlomak &r);
    friend Razlomak operator--(Razlomak &r,int); 
    friend bool operator<(const Razlomak &p,const Razlomak &q);
    friend bool operator>(const Razlomak &p,const Razlomak &q);
    friend bool operator<=(const Razlomak &p,const Razlomak &q);
    friend bool operator>=(const Razlomak &p,const Razlomak &q);
    friend bool operator==(const Razlomak &p,const Razlomak &q);
    friend bool operator!=(const Razlomak &p,const Razlomak &q);
    friend ostream &operator <<(ostream&tok, const Razlomak &a);
    friend istream &operator >>(istream &tok, Razlomak &r);
    explicit operator long double() const;
    
};

Razlomak::Razlomak(long long int vr_brojnika, long long int vr_nazivnika){
    if(vr_nazivnika==0) throw logic_error("Nekorektan razlomak");
    brojnik=vr_brojnika/NZD(vr_brojnika,vr_nazivnika);
    nazivnik=vr_nazivnika/NZD(vr_brojnika,vr_nazivnika);
    if(nazivnik<0){ nazivnik=nazivnik*(-1); brojnik=brojnik*(-1); }
    if(brojnik<0 && nazivnik<0){ brojnik=brojnik*(-1); nazivnik=nazivnik*(-1); }
}

long long int Razlomak::NZD(long long int x, long long int y){
    if(x%y==0) return y;
    else return NZD(y,x%y);
}

Razlomak operator+(const Razlomak &prvi, const Razlomak &drugi){ 
long long int m,M;
m=numeric_limits<long long int>::min();
M=numeric_limits<long long int>::max();
if(drugi.brojnik>0 && drugi.nazivnik>0 && prvi.brojnik/prvi.nazivnik>M-drugi.brojnik/drugi.nazivnik) throw overflow_error("Nemoguce dobiti tacan rezultst");
if((drugi.brojnik<0 || drugi.nazivnik<0) && prvi.brojnik/prvi.nazivnik>M+drugi.brojnik/drugi.nazivnik) throw overflow_error("Nemoguce dobiti tacan rezultst");
    long long int s,r;
    s=Razlomak::NZD(prvi.brojnik, drugi.nazivnik);
    r=Razlomak::NZD(prvi.nazivnik, drugi.nazivnik);
    Razlomak emo;
    emo.brojnik=prvi.brojnik*(drugi.nazivnik/r)+drugi.brojnik*(prvi.nazivnik/r);
    emo.nazivnik=prvi.nazivnik*(drugi.nazivnik/r);
    Razlomak emo1;
    emo1.brojnik=emo.brojnik/Razlomak::NZD(emo.brojnik,emo.nazivnik);
    emo1.nazivnik=emo.nazivnik/Razlomak::NZD(emo.brojnik,emo.nazivnik);
    return emo1;
}

Razlomak operator-(const Razlomak &prvi, const Razlomak &drugi){ 
long long int m,M;
m=numeric_limits<long long int>::min();
M=numeric_limits<long long int>::max();
if(drugi.brojnik/drugi.nazivnik>0 && prvi.brojnik/prvi.nazivnik>M+drugi.brojnik/drugi.nazivnik) throw overflow_error("Nemoguce dobiti tacan rezultst");
if((drugi.brojnik<0 || drugi.nazivnik<0) && prvi.brojnik/prvi.nazivnik<M+drugi.brojnik/drugi.nazivnik) throw overflow_error("Nemoguce dobiti tacan rezultst");
    long long int s,r;
    s=Razlomak::NZD(prvi.brojnik, drugi.nazivnik);
    r=Razlomak::NZD(prvi.nazivnik, drugi.nazivnik);
    Razlomak emo;
    emo.brojnik=prvi.brojnik*(drugi.nazivnik/r)-drugi.brojnik*(prvi.nazivnik/r);
    emo.nazivnik=prvi.nazivnik*(drugi.nazivnik/r);
    Razlomak(emo.brojnik, emo.nazivnik);
    Razlomak emo1;
    emo1.brojnik=emo.brojnik/Razlomak::NZD(emo.brojnik,emo.nazivnik);
    emo1.nazivnik=emo.nazivnik/Razlomak::NZD(emo.brojnik,emo.nazivnik);
    return emo1;
}

Razlomak operator*(const Razlomak &prvi, const Razlomak &drugi){ 
long long int m,M;
m=numeric_limits<long long int>::min();
M=numeric_limits<long long int>::max();
if(drugi.brojnik>0 && drugi.nazivnik>0 && (prvi.brojnik/prvi.nazivnik<m/(drugi.brojnik/drugi.nazivnik)||prvi.brojnik/prvi.nazivnik>M/(drugi.brojnik/drugi.nazivnik))) throw overflow_error("Nemoguce dobiti tacan rezultst");
if((drugi.brojnik<0 || drugi.nazivnik<0) && ((prvi.brojnik/prvi.nazivnik==M || (prvi.brojnik*(-1))/prvi.nazivnik>M/(drugi.brojnik*(-1))/drugi.nazivnik)|| ((prvi.brojnik*(-1))/prvi.nazivnik)<m/(drugi.brojnik*(-1))/drugi.nazivnik)) throw overflow_error("Nemoguce dobiti tacan rezultst");
    long long int s,t;
    s=Razlomak::NZD(prvi.brojnik, drugi.nazivnik);
    t=Razlomak::NZD(drugi.brojnik, prvi.nazivnik);
    Razlomak emo;
    emo.brojnik=(prvi.brojnik/s)*(drugi.brojnik/t);
    emo.nazivnik=(prvi.nazivnik/t)*(drugi.nazivnik/s);
    Razlomak emo1;
    emo1.brojnik=emo.brojnik/Razlomak::NZD(emo.brojnik,emo.nazivnik);
    emo1.nazivnik=emo.nazivnik/Razlomak::NZD(emo.brojnik,emo.nazivnik);
    return emo1;
}

Razlomak operator/(const Razlomak &prvi, const Razlomak &drugi){ 
    long long int u,r;
    u=Razlomak::NZD(prvi.brojnik,drugi.brojnik);
    r=Razlomak::NZD(prvi.nazivnik, drugi.nazivnik);
    Razlomak emo;
    emo.brojnik=(prvi.brojnik/u)*(drugi.nazivnik/r);
    emo.nazivnik=(prvi.nazivnik/r)*(drugi.brojnik/u);
    Razlomak emo1;
    emo1.brojnik=emo.brojnik/Razlomak::NZD(emo.brojnik,emo.nazivnik);
    emo1.nazivnik=emo.nazivnik/Razlomak::NZD(emo.brojnik,emo.nazivnik);
    return emo1;
}

Razlomak operator-(const Razlomak &r){ 
    Razlomak emo;
    emo.brojnik=r.brojnik*(-1);
    emo.nazivnik=r.nazivnik;
    return emo;
}

Razlomak operator+=(Razlomak &p,const Razlomak &q){
    long long int s,r;
    s=Razlomak::NZD(p.brojnik, q.nazivnik);
    r=Razlomak::NZD(p.nazivnik, q.nazivnik);
    p.brojnik+=p.brojnik*(q.nazivnik/r)+q.brojnik*(q.nazivnik/r);
    p.nazivnik+=p.nazivnik*(q.nazivnik/r);
    return p;
}

Razlomak operator-=(Razlomak &p,const Razlomak &q){
    long long int s,r;
    s=Razlomak::NZD(p.brojnik, q.nazivnik);
    r=Razlomak::NZD(p.nazivnik, q.nazivnik);
    p.brojnik-=p.brojnik*(q.nazivnik/r)-q.brojnik*(q.nazivnik/r);
    p.nazivnik-=p.nazivnik*(q.nazivnik/r);
    return p;
}

Razlomak operator*=(Razlomak &p, const Razlomak &q){ 
    long long int s,t;
    s=Razlomak::NZD(p.brojnik, q.nazivnik);
    t=Razlomak::NZD(p.brojnik, q.nazivnik);
    p.brojnik*=(p.brojnik/s)*(q.brojnik/t);
    p.nazivnik*=(p.nazivnik/t)*(q.nazivnik/s);
    return p;
}

Razlomak operator/=(Razlomak &p,const Razlomak &q){
 long long int u,r;
    u=Razlomak::NZD(p.brojnik,q.brojnik);
    r=Razlomak::NZD(p.nazivnik,q.nazivnik);
    p.brojnik/=(p.brojnik/u)*(q.nazivnik/r);
    p.nazivnik/=(p.nazivnik/r)*(q.brojnik/u);
    return p;   
}

Razlomak &operator++(Razlomak &r){
    r.brojnik=r.brojnik+r.nazivnik;
    r.nazivnik=r.nazivnik;
    return r;
}

Razlomak operator++(Razlomak &r,int){
    Razlomak pomocni=r;
    r.brojnik=r.brojnik+r.nazivnik;
    r.nazivnik=r.nazivnik;
    return pomocni;
}

Razlomak &operator--(Razlomak &r){
    r.brojnik=r.brojnik-r.nazivnik;
    r.nazivnik=r.nazivnik;
    return r;
}

Razlomak operator--(Razlomak &r,int){
    Razlomak pomocni=r;
    r.brojnik=r.brojnik-r.nazivnik;
    r.nazivnik=r.nazivnik;
    return pomocni;
}

bool operator==(const Razlomak &p,const Razlomak &q){
    return p.brojnik==q.brojnik && p.nazivnik==q.brojnik;
}

bool operator!=(const Razlomak &p,const Razlomak &q){
    return !(p==q);
}

bool operator<(const Razlomak &p,const Razlomak &q){
    long long int razlomak1, razlomak2;
    razlomak1=p.brojnik/p.nazivnik;
    razlomak2=q.brojnik/q.nazivnik;
    return razlomak1<razlomak2;
}

bool operator>(const Razlomak &p,const Razlomak &q){
    long long int razlomak1, razlomak2;
    razlomak1=p.brojnik/p.nazivnik;
    razlomak2=q.brojnik/q.nazivnik;
    return razlomak1>razlomak2;
}

bool operator<=(const Razlomak &p,const Razlomak &q){
    long long int razlomak1, razlomak2;
    razlomak1=p.brojnik/p.nazivnik;
    razlomak2=q.brojnik/q.nazivnik;
    return razlomak1<=razlomak2;
}

bool operator>=(const Razlomak &p,const Razlomak &q){
    long long int razlomak1, razlomak2;
    razlomak1=p.brojnik/p.nazivnik;
    razlomak2=q.brojnik/q.nazivnik;
    return razlomak1>=razlomak2;
}

ostream &operator <<(ostream&tok, const Razlomak &a){
    Razlomak emo1;
    emo1.brojnik=a.brojnik/Razlomak::NZD(a.brojnik,a.nazivnik);
    emo1.nazivnik=a.nazivnik/Razlomak::NZD(a.brojnik,a.nazivnik);
    if(emo1.nazivnik==1) return tok<<emo1.brojnik;
    else{
        
        return tok<<emo1.brojnik<<"/"<<emo1.nazivnik;
    } 
}

istream &operator >>(istream &tok, Razlomak &r){ 
        char znak;
        tok>>ws;
            if(tok.peek()<'1' || tok.peek()>'9')  tok.setstate(ios::failbit); 
            tok>>r.brojnik;
            if(tok.peek()==' ' || tok.peek()=='\0' || tok.peek()=='\n' || tok.peek()==-1){r.nazivnik=1;return tok; }
            if(tok.peek()!='/' && tok.peek()!='\0') tok.setstate(ios::failbit);
            if(tok.peek()=='\0'){r.nazivnik=1; tok.setstate(ios::failbit); }
            tok>>znak;
            if(tok.peek()<'1' || tok.peek()>'9') tok.setstate(ios::failbit);
            tok>>r.nazivnik;
            if(tok.peek()==' ' || tok.peek()=='\0' || tok.peek()=='\n' || tok.peek()==-1){ return tok; }
            else tok.setstate(ios::failbit);
            return tok;
}

Razlomak::operator long double() const {
return (long double) brojnik/nazivnik;
}


int main(){
    return 0;
}
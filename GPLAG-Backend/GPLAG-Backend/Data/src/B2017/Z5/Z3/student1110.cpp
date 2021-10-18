/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

class Datum {
    int d,m,g;
    public:
enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August,Septembar, Oktobar, Novembar, Decembar};
const char* imena_mjeseci[12]{"Januar","Februar"," Mart", "April", "Maj", "Juni", "Juli", "August","Septembar", "Oktobar", "Novembar", "Decembar"};
enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
const char* imena_dana[7]{"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};
    Datum(int dan, int mj, int god);
    Datum(int dan, Mjeseci mj, int god);
    Datum Postavi(int dan, int mj, int god);
    Datum Postavi(int dan, Mjeseci mj, int god);
    int DajDan() const {return d;};
    Mjeseci DajMjesec()const {return Mjeseci(m);};
    int DajGodinu() const {return g;};
    const char* DajImeMjeseca() const { return imena_mjeseci[m-1];};
    Dani DanUSedmici ()const{  return Dani(d);};
    const char* DajImeDanaUSedmici() const {return imena_dana[d-1];};
    char* IspisiD();
    friend Datum&operator++(Datum &dat);
    friend const Datum operator++(Datum &dat, int);
    friend Datum&operator--(Datum &dat);
    friend const Datum operator--(Datum &dat,int);
    friend Datum operator+(Datum &dat, int x);
    friend Datum operator -(Datum &dat, int x);
    friend Datum &operator+=(Datum &dat, int x);
    friend Datum &operator -=(Datum &dat, int x);
    friend int operator -(const Datum &dat1,const Datum &dat2);
    friend bool operator==(const Datum &dat1, const Datum &dat2);
    friend bool operator !=(const Datum &dat1, const Datum &dat2);
    friend bool operator<(const Datum &dat1, const Datum &dat2);
    friend bool operator>(const Datum &dat1, const Datum &dat2);
    friend bool operator<=(const Datum &dat1, const Datum &dat2);
    friend bool operator>=(const Datum &dat1, const Datum &dat2);
   friend ostream &operator<<(ostream &tok, const Datum &dat);
   friend istream& operator>>(istream &tok,const Datum &dat);
   
};

Datum::Datum(int dan, int mj, int god) {
    int Dani[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((god%4==0 && god%100!=0) || god%400==0) Dani[1]++;
    if(god<1800 || mj<0 || mj>12 || dan>Dani[mj-1] ) throw domain_error("Nelegalan datum");
    d=dan, m=mj; g=god;
}
Datum::Datum(int dan, Mjeseci mj, int god) {
    int Dani[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((god%4==0 && god%100!=0) || god%400==0) Dani[1]++;
    if(god<1800 || mj<0 || mj>12 || dan>Dani[mj-1] ) throw domain_error("Nelegalan datum");
    d=dan;    m=int(mj);    g=god;
}
Datum Datum::Postavi(int dan, int mj, int god) {
    int Dani[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((god%4==0 && god%100!=0) || god%400==0) Dani[1]++;
    if(god<1800 || mj<0 || mj>12 || dan>Dani[mj-1] ) throw domain_error("Nelegalan datum");
    d=dan, m=mj; g=god;
    return *this;
}
Datum Datum::Postavi(int dan, Mjeseci mj, int god) {
    int Dani[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((god%4==0 && god%100!=0) || god%400==0) Dani[1]++;
    if(god<1800 || mj<0 || mj>12 || dan>Dani[mj-1] ) throw domain_error("Nelegalan datum");
    d=dan;    m=int(mj);    g=god;
    return *this;
}
/*char* Datum::IspisiD(){
    int Dani[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    const char* imena_dana[7]{"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjeja"};
    
    
}
*/
Datum&operator++(Datum &dat) {
    int Dani[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(dat.d==Dani[dat.m-1] && dat.m==12) {
        dat.d=1; dat.m=1; dat.g++;
    }
    else if(dat.d==Dani[dat.m-1]) {
        if(dat.m==2 && ((dat.g%4==0 && dat.g%100!=0) || dat.g%400==0)) dat.d++;
        else {
            dat.d=1;
            dat.m++;
        }
    }
    else dat.d++;
    return dat;
}
const Datum operator++(Datum &dat, int) {
    Datum pom(dat);
    ++pom;
    return pom;
}
Datum&operator--(Datum &dat) {
        int Dani[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if((dat.g%4==0 && dat.g%100!=0) || dat.g%400==0) dat.d++;
    if(dat.d==1) {
        if(dat.m==1) {
            dat.d=Dani[11];
            dat.m=12;
            dat.g--;
        }
        else {
            dat.d=Dani[dat.m-2];
            dat.m--;
        }
    }
    else    dat.d--;
    if(dat.g<1800) throw domain_error("Nelegalan datum");
    return dat;
}
const Datum operator--(Datum &dat,int) {
    Datum pom(dat);
    --pom;
    if(dat.g<1800) throw domain_error("Nelegalan datum");
    return pom;
}
Datum operator+(Datum &dat, int x) {
    Datum pom(dat);
    for(int i=0;i<x;i++){
        if(x<0) pom--;
        else if(x>0) pom++;
    }
    if(pom.g<1800) throw domain_error("Nelegalan datum");
    return pom;
}
Datum operator -(Datum &dat, int x){
    Datum pom(dat);
    for(int i=0;i<x;i++) {
        if(x>0) pom--;
        else if (x<0) pom++;
    }
    if(pom.g<1800) throw domain_error("Nelegalan datum");
    return pom;
}
Datum &operator+=(Datum &dat, int x) {
    dat=dat+x;
    return dat;
}
Datum &operator -=(Datum &dat, int x) {
    dat=dat-x;
    return dat;
}
int operator -(const Datum &dat1,const Datum &dat2) {
    int Dani1[12]={31,28,31,30,31,30,31,31,30,31,30,31},Dani2[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int ugod1(365),ugod2(365);
    if((dat1.g%4==0 && dat1.g%100!=0) || dat1.g%400==0) {
        Dani1[1]++; ugod1++;
    }
    if((dat2.g%4==0 && dat2.g%100!=0) || dat2.g%400==0) {
        Dani2[1]++; ugod2++;
    }
    int br1=dat1.DajDan()+dat1.DajMjesec()*Dani1[dat1.DajMjesec()-1]*ugod1;
    int br2=dat2.DajDan()+dat2.DajMjesec()*Dani2[dat1.DajMjesec()-1]*ugod2;
    int br(br1-br2);
    if(br<0) br*=-1;
    return br;
}
bool operator==(const Datum &dat1, const Datum &dat2){
    if(dat1.d==dat2.d && dat1.m==dat2.m && dat1.g==dat2.g) return true;
return false;
}
bool operator !=(const Datum &dat1, const Datum &dat2) {
    return !(dat1==dat2);
}
bool operator<(const Datum &dat1, const Datum &dat2) {
    if(dat1!=dat2) {
        if(dat1.g<dat2.g) return true;
        else if(dat1.g>dat2.g) return false;
        else if(dat1.g==dat2.g && (dat1.m<dat2.m)) return true;
        else if(dat1.g==dat2.g && (dat1.m>dat2.m)) return false;
        else if(dat1.g==dat2.g && (dat1.m==dat2.m) && dat1.d<dat2.d) return true;
        else if(dat1.g==dat2.g && (dat1.m==dat2.m) && dat1.d>dat2.d) return false;
    }
    return false;
}
bool operator>(const Datum &dat1, const Datum &dat2){
    if(dat1==dat2 || dat1<dat2) return false;
    return true;
}
bool operator<=(const Datum &dat1, const Datum &dat2){
    if(dat1<dat2 || dat1==dat2) return true;
    return false;
}
bool operator>=(const Datum &dat1, const Datum &dat2) {
    if(dat1>dat2 || dat1==dat2) return true;
    return false;
}
ostream &operator<<(ostream &tok, const Datum &dat){
    return tok<<dat.d<<". "<<dat.DajImeMjeseca()<<" "<<dat.g<<". ("<<dat.DajImeDanaUSedmici()<<")";
}
istream& operator>>(istream &tok,const Datum &dat) {
    char c1,c2;
    int d,m,g;
    tok>>ws;
    tok>>d>>c1>>m>>c2>>g;
    try{
        Datum dat(d,m,g);
        if(c1!='/' || c2!='/') {
            tok.setstate(ios::failbit); 
            throw;
        }
    }
    catch(...) {
        throw;
    }
    return tok;
}
int main ()
{
    try{
        Datum d(28,2,2008);
        std::cout << d++ << " ";
        std::cout << ++d << " ";
        std::cout << --d << " ";
        std::cout << d-- << std::endl;
    }
    catch(domain_error c) {cout<<c.what();}
	return 0;
}

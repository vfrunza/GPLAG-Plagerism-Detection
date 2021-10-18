/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <string>
using std::string;
using std::cout;
using std::cin;

int BrojDana(int mjesec,int godina){
    int dani[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) dani[1]++;
    return dani[mjesec-1];
}

class Datum{
    int dan,mjesec,godina;
    public:
    enum Mjeseci{Januar=1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani{Ponedjeljak=1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    Datum(int d,int m,int g);
    Datum(int d,Mjeseci m,int g);
    void Postavi(int d,int m,int g);
    void Postavi(int d,Mjeseci m,int g);
    int DajDan() const{ return dan; }
    Mjeseci DajMjesec() const{ return Mjeseci(mjesec); }
    int DajGodinu() const{ return godina; }
    const char *DajImeMjeseca() const;
    Dani DanUSedmici() const;
    const char *DajImeDanaUSedmici() const;
    friend Datum &operator--(Datum &dat);
    friend Datum &operator++(Datum &dat);
    friend Datum operator--(Datum &dat,int);
    friend Datum operator++(Datum &dat,int);
    friend Datum &operator+=(Datum &dat,int n);
    friend Datum &operator-=(Datum &dat,int n);
    friend Datum operator+(Datum dat,int n);
    friend Datum operator-(Datum dat,int n);
    friend int operator-(const Datum &dat1,const Datum &dat2);
    friend bool operator==(const Datum &dat1,const Datum &dat2);
    friend bool operator!=(const Datum &dat1,const Datum &dat2);
    friend bool operator<(const Datum &dat1,const Datum &dat2);
    friend bool operator>(const Datum &dat1,const Datum &dat2);
    friend bool operator<=(const Datum &dat1,const Datum &dat2);
    friend bool operator>=(const Datum &dat1,const Datum &dat2);
    friend std::ostream &operator<<(std::ostream &tok,const Datum &dat);
    friend std::istream &operator>>(std::istream &tok,const Datum &dat);
    operator string() const;
    operator int() const;
};
Datum::Datum(int d,int m,int g){
    if(g<1 || g<1800 || d<1 || m<1 || m>12 || d>BrojDana(m,g))
    throw std::domain_error("Nelegalan datum!");
    dan=d; mjesec=m; godina=g;
}
Datum::Datum(int d,Mjeseci m,int g){
    if(g<1 || g<1800 || d<1 || m<1 || m>12 || d>BrojDana(m,g))
    throw std::domain_error("Nelegalan datum!");
    dan=d; mjesec=m; godina=g;
}
void Datum::Postavi(int d,int m,int g){
    if(g<1 || g<1800 || d<1 || m<1 || m>12 || d>BrojDana(m,g))
    throw std::domain_error("Nelegalan datum!");
    dan=d; mjesec=m; godina=g;
}
void Datum::Postavi(int d,Mjeseci m,int g){
    if(g<1 || g<1800 || d<1 || m<1 || m>12 || d>BrojDana(m,g))
    throw std::domain_error("Nelegalan datum!");
    dan=d; mjesec=m; godina=g;
}
const char *Datum::DajImeMjeseca() const{
    const char *mjeseci[]{"Januar","Februar","Mart","April","Maj","Juni","Juli","August","Septembar","Oktobar","Novembar","Decembar"};
    return mjeseci[mjesec-1];
}
Datum::Dani Datum::DanUSedmici() const{
    int suma(0);
    for(int i(1800);i<godina;i++){
        if((godina%4==0  && godina%100!=0) || godina%400==0) suma+=356;
        else suma+=365;
    }
    for(int i(0);i<mjesec-1;i++) suma+=BrojDana(i+1,godina);
    suma+=dan;
    while(suma>7) suma-=7; suma--;
    if(suma==0) suma=7;
    return Dani(suma);
}
const char *Datum::DajImeDanaUSedmici() const{
    const char *dani[]{"Ponedjeljak","Utorak","Srijeda","Cetvrtak","Petak","Subota","Nedjelja"};
    return dani[DanUSedmici()-1];
}
Datum &operator--(Datum &dat){
    int poc_mj(dat.mjesec),poc_dan(dat.dan);
    dat.dan--;
    if(dat.dan<1) dat.mjesec--;
    if(dat.mjesec<1){ dat.mjesec=12; dat.dan=BrojDana(dat.mjesec,dat.godina); dat.godina--; }
    if(dat.godina<1800){
        dat.dan=poc_dan; dat.mjesec=poc_mj; dat.godina++;
        throw std::domain_error("Nelegalan datum");
    }
    return dat;
}
Datum &operator++(Datum &dat){
    dat.dan++;
    if(dat.dan>BrojDana(dat.mjesec,dat.godina)){ dat.mjesec++; dat.dan=1; }
    if(dat.mjesec>12){ dat.mjesec=1; dat.godina++; }
    return dat;
}
Datum operator--(Datum &dat,int){
    Datum pom(dat);
    --dat;
    return pom;
}
Datum operator++(Datum &dat,int){
    Datum pom(dat);
    ++dat;
    return pom;
}
Datum &operator+=(Datum &dat,int n){
    if(n>0) for(int i(0);i<n;i++) ++dat;
    if(n<0){
        Datum pom(dat);
        for(int i(0);i<-n;i++) --pom;
        dat=pom;
    }
    return dat;
}
Datum &operator-=(Datum &dat,int n){
    if(n<0) for(int i(0);i<-n;i++) ++dat;
    if(n>0){
        Datum pom(dat);
        for(int i(0);i<n;i++) --pom;
        dat=pom;
    }
    return dat;
}
Datum operator+(Datum dat,int n){
    dat+=n;
    return dat;
}
Datum operator-(Datum dat,int n){
    dat-=n;
    return dat;
}
int operator-(const Datum &d1,const Datum &d2){
    Datum dat1(d1),dat2(d2);
    int br_dana(0);
    if(dat1<=dat2){
        for(;;){
            if(dat1==dat2) break;
            ++dat1;
            br_dana++;
        }
    }
    else{
        for(;;){
            if(dat1==dat2) break;
            ++dat2;
            br_dana++;
        }
    }
    return br_dana;
}
bool operator==(const Datum &dat1,const Datum &dat2){
    return (dat1.dan==dat2.dan && dat1.mjesec==dat2.mjesec && dat1.godina==dat2.godina);
}
bool operator!=(const Datum &dat1,const Datum &dat2){
    return !(dat1==dat2);
}
bool operator<(const Datum &dat1,const Datum &dat2){
    if(dat1.godina!=dat2.godina) return dat1.godina<dat2.godina;
    else{
        if(dat1.mjesec!=dat2.mjesec) return dat1.mjesec<dat2.mjesec;
        else return dat1.dan<dat2.dan;
    }
}
bool operator>(const Datum &dat1,const Datum &dat2){
    if(dat1.godina!=dat2.godina) return dat1.godina>dat2.godina;
    else{
        if(dat1.mjesec!=dat2.mjesec) return dat1.mjesec>dat2.mjesec;
        else return dat1.dan>dat2.dan;
    }
}
bool operator<=(const Datum &dat1,const Datum &dat2){
    return (dat1<dat2 || dat1==dat2);
}
bool operator>=(const Datum &dat1,const Datum &dat2){
    return (dat1>dat2 || dat1==dat2);
}
std::ostream &operator<<(std::ostream &tok,const Datum &dat){
    tok<<dat.dan<<"."<<dat.DajImeMjeseca()<<" "<<dat.godina<<".("<<dat.DajImeDanaUSedmici()<<")";
    return tok;
}
std::istream &operator>>(std::istream &tok,Datum &dat){
    int d(0),m(0),g(0);
    char znak1,znak2;
    tok>>d>>znak1>>m>>znak2>>g;
    if(!cin || znak1!='/' || znak2!='/')  tok.setstate(std::ios::failbit);
    else if(g<1800 || d<1 || m<1 || m>12 || d>BrojDana(m,g))  tok.setstate(std::ios::failbit);
    else dat.Postavi(d,m,g);
    return tok;
}
Datum::operator string() const{
    string s(std::to_string(dan));
    s+='.';
    s+=DajImeMjeseca();
    s+=" ";
    s+=std::to_string(godina);
    s+=".(";
    s+=DajImeDanaUSedmici();
    s+=')';
    return s;
}
Datum::operator int() const{
    int n(Datum(1,1,1800)-(*this));
    return n;
}
    
int main ()
{
    Datum d1(1,1,1800),d2(1,1,1800);
    for(;;){
       try{
           cout<<"Unesi datum rodjenja (d/m/g) : ";
           cin>>d1;
           cout<<"Unesi danasnji datum (d/m/g) : ";
           cin>>d2;
           if(!cin) throw std::domain_error("Greska, unesi oba datum ponovo!");
           if(d1>=d2) throw std::domain_error("Greska, jos se nisi rodio, unesi oba datum ponovo!");
           string s(d1);
           cout<<"Izmedju datuma rodjenja "<<s<<"\ni danasnjeg datuma "<<d2<<" proteklo je tacno "<<d1-d2<<" dana.";
           break;
       } 
        catch(std::domain_error izuzetak){
            cout<<izuzetak.what();
            cin.clear();
            cin.ignore(1000,'\n');
        }
        cout<<std::endl;
    }
    
	return 0;
}

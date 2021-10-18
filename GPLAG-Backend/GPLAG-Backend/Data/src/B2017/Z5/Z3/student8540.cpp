#include <iostream>
#include <cmath>
#include <stdexcept>

class Datum{
     int dan,mjesec,godina;
     public:
     enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
     enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
     Datum(int dan1, int mjesec1, int godina1);
     Datum(int dan1, Mjeseci mjesec, int godina1);
     void Postavi(int dan1, int mjesec1, int godina1);
     void Postavi(int dan1, Mjeseci mjesec, int godina1);
     int DajDan() const {return dan;}
     Mjeseci DajMjesec() const{return Mjeseci(mjesec);}
     int DajGodinu() const{return godina;}
     char *DajImeMjeseca()const;
     Dani DanUSedmici() const;
     char *DajImeDanaUSedmici() const;
     friend Datum operator ++(Datum &d);
     friend Datum operator +(const Datum &d, int n);
     friend Datum operator ++(Datum &d,int);
     friend Datum operator --(Datum &d,int);
     friend Datum operator --(Datum &d);
     friend Datum operator -(const Datum &d, int n);
     friend Datum operator +=(Datum &d, int n);
     friend Datum operator -=(Datum &d, int n);
     friend bool operator ==(const Datum &d1, const Datum &d2);
     friend bool operator !=(const Datum &d1, const Datum &d2);
     friend bool operator >(const Datum &d1, const Datum &d2);
     friend bool operator <(const Datum &d1, const Datum &d2);
     friend bool operator >=(const Datum &d1, const Datum &d2);
     friend bool operator <=(const Datum &d1, const Datum &d2);
     static int BrojDana(int dan1, int mjesec1, int godina1);
     static bool DaLiJePrestupna(int godina1);
     static void TestLegalnosti(int dan1, int mjesec1, int godina1);
     friend std::ostream &operator <<(std::ostream &tok, const Datum &d);
     friend std::istream &operator >>(std::istream &tok, Datum &d);
     friend int operator-(const Datum &d1, const Datum &d2);
};

Datum::Datum(int dan1, int mjesec1, int godina1){
     TestLegalnosti(dan1,mjesec1,godina1);
    dan=dan1;
    mjesec=mjesec1;
    godina=godina1;
}
Datum::Datum(int dan1, Mjeseci mjesec, int godina1){
     int mjesec1=mjesec;
     TestLegalnosti(dan1,mjesec1,godina1);
     dan=dan1;
     Datum::mjesec=mjesec1;
     godina=godina1;
}
void Datum::Postavi(int dan1, int mjesec1, int godina1){
     TestLegalnosti(dan1,mjesec1,godina1);
     dan=dan1;
     mjesec=mjesec1;
     godina=godina1;
}
void Datum::Postavi(int dan1, Mjeseci mjesec, int godina1){
     int mjesec1=mjesec;
     TestLegalnosti(dan1, mjesec1, godina1);
     dan=dan1;
     Datum::mjesec=mjesec1;
     godina=godina1;
}
char *Datum::DajImeMjeseca()const{
     char *imena_mjeseci[12]={
          "Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"
     };
     return imena_mjeseci[mjesec-1];
}
Datum::Dani Datum::DanUSedmici()const{
     int referentni(BrojDana(1,1,1800));
     int datum(BrojDana(dan,mjesec,godina));
     int razlika(fabs(referentni-datum));
     while(razlika>7) razlika-=7;
     return Dani(razlika);
}
char *Datum::DajImeDanaUSedmici()const{
     char *dani[]={"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};
     int referentni(BrojDana(4,1,100));
     int datum(BrojDana(dan,mjesec,godina));
     int razlika(fabs(datum-referentni));
     razlika=razlika%7;
     return dani[razlika];
}
Datum operator ++(Datum &d){
     int broj_dana_umjesecu[]{31,28,31,30,31,30,31,31,30,31,30,31};
     if(Datum::DaLiJePrestupna(d.godina)) broj_dana_umjesecu[1]++;
     d.dan++;
     if(d.dan==broj_dana_umjesecu[d.mjesec-1]+1){
          d.dan=1; d.mjesec++;
     }
     if(d.mjesec==13){d.mjesec=1; d.godina++;}
     return d;
}
Datum operator ++(Datum &d, int){
     Datum pomocni(d.dan, d.mjesec, d.godina);
     int broj_dana_umjesecu[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(Datum::DaLiJePrestupna(d.godina)) broj_dana_umjesecu[1]++;
     d.dan++;
     if(d.dan==broj_dana_umjesecu[d.mjesec-1]+1){
          d.dan=1; d.mjesec++;
     }
     if(d.mjesec==13){d.mjesec=1; d.godina++;}
     return pomocni;
}
Datum operator --(Datum &d){
      int broj_dana_umjesecu[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(Datum::DaLiJePrestupna(d.godina)) broj_dana_umjesecu[1]++;
     d.dan--;
     if(d.dan==0){
          if(d.mjesec==1){d.mjesec=12; d.godina--;}
          else d.mjesec--;
          d.dan=broj_dana_umjesecu[d.mjesec-1];
     }
     return d;
}
Datum operator --(Datum &d, int){
     Datum pomocni(d.dan, d.mjesec, d.godina);
     int broj_dana_umjesecu[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(Datum::DaLiJePrestupna(d.godina)) broj_dana_umjesecu[1]++;
     d.dan--;
     if(d.dan==0){
          if(d.mjesec==1){d.mjesec=12; d.godina--;}
          else d.mjesec--;
          d.dan=broj_dana_umjesecu[d.mjesec-1];
     }
     return pomocni;
}
Datum operator +(const Datum &d, int n){
     if(n<0) return d-fabs(n);
     if(n==0) return d;
     Datum d1(d.dan, d.mjesec, d.godina);
     int broj_dana_umjesecu[]{31,28,31,30,31,30,31,31,30,31,30,31};
     if(Datum::DaLiJePrestupna(d1.godina)) broj_dana_umjesecu[1]++;
     if(n<=broj_dana_umjesecu[d1.mjesec-1]-d1.dan){
          d1.dan+=n; return d1;
     }
     else {
          n-=(broj_dana_umjesecu[d1.mjesec-1]-d1.dan)+1;
          d1.dan=1;
     }
     if(d1.mjesec==12){
          d1.mjesec=1;
          if(Datum::DaLiJePrestupna(++d1.godina))
          broj_dana_umjesecu[1]=29;
          else broj_dana_umjesecu[1]=28;
     }
     else d1.mjesec++;
     while(n>broj_dana_umjesecu[d1.mjesec-1]){
          n-=broj_dana_umjesecu[d1.mjesec-1];
          if(d1.mjesec==12){
               d1.mjesec=1;
               if(Datum::DaLiJePrestupna(++d1.godina))
               broj_dana_umjesecu[1]=29;
               else broj_dana_umjesecu[1]=28;
          }
          else d1.mjesec++;
     }
     d1.dan+=n;
     return d;
}
Datum operator -(const Datum &d, int n){
     if(n<0) return d+fabs(n);
     if(n==0) return d;
     if(n==366 && Datum::DaLiJePrestupna(d.godina-1)) return {d.dan, d.mjesec, d.godina-1};
     Datum d1(d.dan,d.mjesec,d.godina);
     int broj_dana_umjesecu[]{31,28,31,30,31,30,31,31,30,31,30,31};
     if(Datum::DaLiJePrestupna(d1.godina)) broj_dana_umjesecu[1]=29;
     while(n>broj_dana_umjesecu[d1.mjesec-1]){
          n=n-broj_dana_umjesecu[d1.mjesec-1];
          if(d1.mjesec==1){
               d1.godina--;
               if(Datum::DaLiJePrestupna(d1.godina)){
                    broj_dana_umjesecu[1]=29;
               }
               else broj_dana_umjesecu[1]=28;
               d1.mjesec=12;
          }
          else d1.mjesec--;
     }
     if(n!=0){
          if(d1.dan-n<=0){
               if(d1.mjesec==1){
                    d1.godina--;
                    if(Datum::DaLiJePrestupna(d1.godina)){
                         broj_dana_umjesecu[1]=29;
                    } 
                    else broj_dana_umjesecu[1]=28;
                    d1.mjesec=12;
               }
               else d1.mjesec--;
               d1.dan=broj_dana_umjesecu[d1.mjesec-1]-fabs(d1.dan-n);
          }
          else d1.dan+=n;
     }
     return d1;
}
int operator -(const Datum &d1, const Datum &d2){
     return fabs(Datum::BrojDana(d1.dan, d1.mjesec, d1.godina)-Datum::BrojDana(d2.dan, d2.mjesec, d2.godina));
}
Datum operator +=(Datum &d, int n){
     d=d+n;
     return d;
}
Datum operator -=(Datum &d, int n){
     d=d-n;
     return d;
}
bool operator ==(const Datum &d1, const Datum &d2){
     return Datum::BrojDana(d1.dan, d1.mjesec, d1.godina)==Datum::BrojDana(d2.dan, d2.mjesec, d2.godina);
}
bool operator !=(const Datum &d1, const Datum &d2){
     return Datum::BrojDana(d1.dan, d1.mjesec, d1.godina)!=Datum::BrojDana(d2.dan, d2.mjesec, d2.godina);
}
bool operator >(const Datum &d1, const Datum &d2){
     return Datum::BrojDana(d1.dan, d1.mjesec, d1.godina)>Datum::BrojDana(d2.dan, d2.mjesec, d2.godina);
}
bool operator <(const Datum &d1, const Datum &d2){
     return Datum::BrojDana(d1.dan, d1.mjesec, d1.godina)<Datum::BrojDana(d2.dan, d2.mjesec, d2.godina);
}
bool operator >=(const Datum &d1, const Datum &d2){
     return Datum::BrojDana(d1.dan, d1.mjesec, d1.godina)>=Datum::BrojDana(d2.dan, d2.mjesec, d2.godina);
}
bool operator <=(const Datum &d1, const Datum &d2){
     return Datum::BrojDana(d1.dan, d1.mjesec, d1.godina)<=Datum::BrojDana(d2.dan, d2.mjesec, d2.godina);
}
void Datum::TestLegalnosti(int dan, int mjesec, int godina){
     int broj_dana_umjesecu[]{31,28,31,30,31,30,31,31,30,31,30,31};
     if(godina%4==0 && godina%100!=0 && godina%400==0)
     broj_dana_umjesecu[1]++;
     if(godina<1 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana_umjesecu[mjesec-1])
     throw std::domain_error("Nelegalan datum");
}
std::ostream &operator <<(std::ostream &tok, const Datum &d){
     tok<<d.DajDan()<<". "<<d.DajImeMjeseca()<<" "<<d.DajGodinu()<<". ("<<d.DajImeDanaUSedmici()<<")";
     return tok;
}

std::istream &operator >>(std::istream &tok, Datum &d){
    char znak1, znak2;
    tok>>d.dan>>znak1>>d.mjesec>>znak2>>d.godina;
    if(znak1!='/' || znak2!='/') tok.setstate(std::ios::failbit);
    int broj_dana_umjesecu[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(d.godina%4==0 && d.godina%100!=0 || d.godina%400==0)
        broj_dana_umjesecu[1]++;
    if(d.godina<1 || d.mjesec<1 || d.mjesec>12 || d.dan<1 || d.dan>broj_dana_umjesecu[d.mjesec-1])
        tok.setstate(std::ios::failbit);
}
bool Datum::DaLiJePrestupna(int godina){
     return godina%4==0 && godina%100!=0 || godina%400==0;
}
int Datum::BrojDana(int dan, int mjesec, int godina){
     int s_dana=0;
     int broj_dana_umjesecu[]{31,28,31,30,31,30,31,31,30,31,30,31};
     for(int i=0; i<godina; i++){
          s_dana+=365;
          if(DaLiJePrestupna(i)) s_dana++;
     }
     if(Datum::DaLiJePrestupna(godina)) broj_dana_umjesecu[1]++;
     for(int i=1; i<mjesec; i++){
          s_dana+=broj_dana_umjesecu[i-1];
     }
     s_dana+=dan;
     return s_dana;
}
int main (){ try{
    Datum danas(9, 5, 1996);
    std::cout<<danas<<std::endl;
    danas++;
    std::cout<<danas<<std::endl;
    danas--;
    danas--;
    std::cout<<danas<<std::endl;
    danas++;
    danas++;
    danas++;
    std::cout<<danas<<std::endl;
    int n=4;
    danas+=n;
    std::cout<<danas<<std::endl;
    n=2;
    danas=danas+n;
    std::cout<<danas<<std::endl;
    danas=danas+3;
    std::cout<<danas<<std::endl;
    Datum d1(9,6,2018);
    Datum d2(9,7,2018);
    Datum d(1,1,1900);
    std::cin>>d;
    std::cout<<d<<std::endl;
    if(d1>=d2)
    std::cout<<d2;
    else std::cout<<d1;
     
}
    catch (std::domain_error e){
         std::cout<<e.what()<<std::endl;
    }
	return 0;
}

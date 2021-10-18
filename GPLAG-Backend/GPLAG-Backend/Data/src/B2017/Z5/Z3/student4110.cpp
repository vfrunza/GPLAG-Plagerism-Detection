/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
class Datum{
   
    int dan,mjesec,godina;
    bool Provjeri(int d, int m, int g) {
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    if((g%4==0 && g%100!=0) || g%400==0) broj_dana[1]++;
    if(g<1800||m<1||m>12||d<1||d>broj_dana[m-1]) return false;
    return true;}
    public:
    enum Mjeseci{Januar=1,Februar=2,Mart=3,April=4,Maj=5,Juni=6,Juli=7,August=8,Septembar=9,Oktobar=10,Novembar=11,Decembar=12};
    enum Dani{Ponedeljak=1,Utorak,Srijeda,Cetvrtak,Petak,Subota,Nedelja};
    Datum(int d,int m,int g){
        if(!Provjeri(d,m,g))throw std::domain_error("Nelegalan datum");
        dan=d;
        mjesec=m;
        godina=g;
    }
    Datum(int d,Mjeseci m,int g){
        if(!Provjeri(d,int(m),g))throw std::domain_error("Nelegalan datum");
        dan=d;
        mjesec=int(m);
        godina=g;
    }
    Datum& Postavi(int d,int m,int g){
        if(!Provjeri(d,m,g))throw std::domain_error("Nelegalan datum");
        dan=d;
        mjesec=m;
        godina=g;
        return *this;
    }
    Datum&Postavi(int d,Mjeseci m,int g){
        if(!Provjeri(d,int(m),g))throw std::domain_error("Nelegalan datum");
        dan=d;
        mjesec=int(m);
        godina=g;
        return *this;
    }
    int DajDan()const{return dan;}
    int DajMjesec()const{return mjesec;}
    int DajGodinu()const{return godina;}
    
    std::string DajImeMjeseca()const{
        std::vector<std::string>a{"Januar","Februar","Mart","April","Maj","Juni","Juli","August","Septembar","Oktobar","Novembar","Decembar"};
        return a[mjesec];
    }
     std::string DajImeDanaUSedmici()const{
        std::vector<std::string>a{"Ponedeljak","Utorakr","Srijeda","Cetvrtak","Petak","Subota","Nedelja"};
        return a[dan];
    }
    Datum& operator++();
    Datum& operator--();
    Datum operator++(int);
    Datum operator--(int);
      
    
};

Datum& Datum:: operator++(){
  int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
  dan++;
  if(dan>broj_dana[mjesec-1]){dan=1;mjesec++;}
  if(mjesec>12){mjesec=1;godina++;}
  this->Postavi(dan,mjesec,godina);
 return *this; 
}
Datum Datum:: operator++(int){
    Datum pomocna(this->DajDan(),this->DajMjesec(),this->DajGodinu());
  int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
  dan++;
  if(dan>broj_dana[mjesec-1]){dan=1;mjesec++;}
  if(mjesec>12){mjesec=1;godina++;}
  this->Postavi(dan,mjesec,godina);
 return pomocna; 
}

Datum& Datum:: operator--(){
   int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
  dan--;
  if(dan==0){mjesec--;
  dan=broj_dana[mjesec-1];}
  if(mjesec==0){mjesec=12;godina--;}
  this->Postavi(dan,mjesec,godina);
  return *this;
}
Datum Datum:: operator--(int){
     Datum pomocna(this->DajDan(),this->DajMjesec(),this->DajGodinu());
   int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
  dan--;
  if(dan==0){mjesec--;
  dan=broj_dana[mjesec-1];}
  if(mjesec==0){mjesec=12;godina--;}
  this->Postavi(dan,mjesec,godina);
  return pomocna;
}


int main ()
{
	return 0;
}

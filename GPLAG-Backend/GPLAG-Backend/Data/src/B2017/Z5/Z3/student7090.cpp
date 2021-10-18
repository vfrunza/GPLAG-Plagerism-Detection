/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <ctime>



class Datum {
  int dan;
  int mjesec;
  int godina;
  bool DaLiJePrestupna(int godina);
  public:
  enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August,Septembar, Oktobar, Novembar, Decembar};
  enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
  Datum(int d,int m,int g) { Postavi(d,m,g); }
  Datum(int d,Mjeseci m,int g) { Postavi(d,m,g); }
  void Postavi(int d,int m,int g);
  void Postavi(int d,Mjeseci m,int g);
  int DajDan() { return dan; }
  int DajGodinu() { return godina; }
  Mjeseci DajMjesec() { return Mjeseci(mjesec); }
  const char* DajImeMjeseca();
  Dani DanUSedmici(){
    int razlika(0);
    for(int i(1900);i<godina;i++){
        int godina_dana(365);
        if(DaLiJePrestupna(i)) godina_dana++;
        razlika+=godina;
    }
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(DaLiJePrestupna(godina)) broj_dana[1]++;
    for(int i(1);i<mjesec;i++){
        razlika+=broj_dana[mjesec-1];
        razlika--;
    }
    
    razlika+=dan;
    razlika--;
    std::cout << razlika <<std::endl;
    int d(razlika%7);
    return Dani(d+1);
  }
};

bool Datum::DaLiJePrestupna(int godina){
    if((godina%4==0 && godina%100!=0) || godina%400==0) return true;
    return false;
}

void Datum::Postavi(int d,int m,int g){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((g%4==0 && g%100!=0) || g%400==0) broj_dana[1]++;
    if(g<1800 || d<1 || m<1 || m>12 || d>broj_dana[m-1]) throw std::domain_error("Nelegalan datum");
    dan=d; mjesec=m; godina=g;
}

void Datum::Postavi(int d,Mjeseci m,int g){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((g%4==0 && g%100!=0) || g%400==0) broj_dana[1]++;
    if(g<1800 || d<1 || m<1 || m>12 || d>broj_dana[m-1]) throw std::domain_error("Nelegalan datum");
    dan=d; mjesec=m; godina=g;
}

const char* Datum::DajImeMjeseca(){
    const char* imena_mjeseci[12]{"Januar","Februar", "Mart", "April", "Maj", "Juni",
    "Juli","August","Septembar","Oktobar","Novembar","Decembar"};
    return imena_mjeseci[mjesec-1];
}


int main ()
{
    Datum d1(20,8,1900);
    std::cout << d1.DajMjesec() << std::endl;
    std::cout << d1.DajImeMjeseca() <<std::endl;
    std::cout << d1.DanUSedmici();
    
    //Datum d2(15,April,1997);
	return 0;
}

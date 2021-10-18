/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>



class Datum {
  
  
  int dan,mjesec,godina;
  
  public:
  
  
  enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August,Septembar, Oktobar, Novembar, Decembar};
  enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

    
  Datum (int d,int m, int g) {
    if (( d < 1 || d > 31) || (m < 1 || m > 12) || (g < 1800 )) throw std::domain_error ("Neispravan datum");  
      
      
      
      Datum::dan = d;
      Datum::mjesec = m;
      Datum::godina = g;
  }    
    
        
  Datum (int d,Mjeseci m,int g) {
        if (( d < 1 || d > 31) || (m < 1 || m > 12) || (g < 1800 )) throw std::domain_error ("Neispravan datum");
      
      Datum::dan = d;
      //provjeri za Mjeseci
      Datum::mjesec = m;
      Datum::godina = g;
  }  
  
  Datum &Postavi (int d, int m, int g ) {
    
    int brojdana[12]{31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31};
if(g%4 == 0 && g%100 != 0 || g%400 == 0) brojdana[1]++;
if(g < 1 || d < 1 || m < 1 || m > 12 || d > brojdana[m –1] || g < 1800)throw std::domain_error("Neispravan datum!");
    
    Datum::dan = d;
    Datum::mjesec = m;
    Datum::godina = g;
    
    return *this;
  }
  
  Datum &Postavi (int d, Mjeseci m, int g ) {
int brojdana[12]{31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31};
if(g%4 == 0 && g%100!= 0 || g%400 == 0) brojdana[1]++;
if(g < 1 || d < 1 || m < 1 || m > 12 || d > brojdana[m –1] || g < 1800)throw std::domain_error("Neispravan datum!");

    Datum::dan = d;
    Datum::mjesec = m;
    Datum::godina = g;
    
    return *this;
    
  }
  
  int DajDan() const {  return dan; }
  Mjeseci DajMjesec() const {return mjesec; }
  int DajGodinu() const {return godina; }
  
  //Napravi matricu charova i vracaj prvi znak
  //char *DajImeMjeseca () {return  }
  
  /*Sat &operator ++() {
  *this += 1;
  return *this;
 }
 Sat operator ++(int) {
  Sat pomocni(*this);
  *this += 1;
  return pomocni;
 }
 Sat &operator --() {
  *this -= 1;
  return *this;
 }
 Sat operator --(int) {
  Sat pomocni(*this);
  *this -= 1;
  return pomocni;
 }*/
 
 Datum &operator ++(int) {
   
   dan++;
   
   int brojdana[12]{31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31};
   
   if ((dan++) > brojdana[mjesec - 1]) {
     mjesec++;
     dan=1;
   }
   
   if(mjesec == 12 ) {
     mjesec =1 ;
     dan =1;
     godina++;
   }
   return *this;
   
 }
  
  
  
    
    
};

int main ()
{
	return 0;
}

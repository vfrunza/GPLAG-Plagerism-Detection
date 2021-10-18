/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <cmath>
enum Mjeseci {Januar=1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
enum Dani {Ponedjeljak=1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
class Datum{
  /*Dani dan;
  Mjeseci mjesec;
  int godina;*/
  int dan,mjesec,godina;
  static void TestLegalnosti(int dan,int mjesec, int godina);
  static int BrojDana(int dan, int mjesec, int godina);
  static bool DaLiJePrestupna(int godina);
  public:
  Datum(Dani dan, Mjeseci mjesec, int godina);
  Datum(int dan, int mjesec, int godina);
  void Postavi(Dani dan, Mjeseci mjesec, int godina);
  void Postavi(int dan, int mjesec, int godina);
  int DajDan() const {return dan;}
  Mjeseci DajMjesec() const {return Mjeseci(mjesec);}
  int DajGodinu() const {return godina;}
  char *DajImeMjeseca() const;
  Dani DanUSedmici() const;
  char *DajImeDanaUSedmici() const;
  //friend Datum &operator++(Datum &d);
  //friend Datum operator++(Datum &d, int);
  //Datum &operator--(Datum &d);
  //Datum operator--(datum &d, int);
  /*friend int operator-(const Datum &d1, const Datum &d2){
    return fabs(Datum::BrojDana(d1.dan,d1.mjesec,d1.godina)-Datum::BrojDana(d2.dan,d2.mjesec,d2.godina));
  }
  */
  
};
//provjera da li je datum legalan
void Datum::TestLegalnosti(int dan, int mjesec, int godina){
    int br_dana[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && godina%100!=0 || godina%400==0) br_dana[1]++;
    if(godina<1800 || mjesec<1 || mjesec>12 || dan<1 || dan>br_dana[mjesec-1])
    throw std::domain_error("Nelegalan datum");
}
//provjera da li je godina prestupna
bool Datum::DaLiJePrestupna(int godina){
  return (godina%4==0 && godina%100!=0 || godina%400==0);
}
//broj dana u godini
int Datum::BrojDana(int dan, int mjesec, int godina){
  int suma_dana(0);
  int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
  for(int i=1; i<godina; i++){
    suma_dana+=365;
    if(Datum::DaLiJePrestupna(i)) suma_dana++;
  }
  if(Datum::DaLiJePrestupna(godina)) broj_dana[1]++;
  for(int i=1; i<mjesec; i++){
    suma_dana+=broj_dana[i-1];
  }
  suma_dana+=dan;
  return suma_dana;
}
//konstruktori
Datum::Datum(Dani dan, Mjeseci mjesec, int godina){
  Postavi(dan,mjesec,godina);
}
Datum::Datum(int dan, int mjesec, int godina){
  Postavi(dan,mjesec,godina);
}
//metode postavi
void Datum::Postavi(Dani dan, Mjeseci mjesec, int godina){
  int danii=dan;
  int mjesecii=mjesec;
  TestLegalnosti(danii,mjesecii,godina);
  Datum::dan=danii; Datum::mjesec=mjesecii; Datum::godina=godina;
}
void Datum::Postavi(int dan, int mjesec, int godina){
  TestLegalnosti(dan,mjesec,godina);
  Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}
char *Datum::DajImeMjeseca() const{
  char* ime_mj[12]={"Januar","Februar","Mart","April","Maj","Juni","Juli","August","Septembar","Oktobar","Novembar","Decembar"};
  return ime_mj[mjesec-1];
}
Dani Datum::DanUSedmici() const{
  int ref_datum(BrojDana(1,1,1800));
  int moj_datum(BrojDana(dan,mjesec,godina));
  int razlika_dana(fabs(ref_datum-moj_datum));
  while(razlika_dana>7) razlika_dana-=7;
  return Dani(razlika_dana);
}
char* Datum::DajImeDanaUSedmici() const{
  char *ime_dana[]={"Ponedjeljak","Utorak","Srijeda","Cetvrtak","Petak","Subota","Nedjelja"};
  int ref_datum(BrojDana(1,1,1800));
  int moj_datum(BrojDana(dan,mjesec,godina));
  int razlika_dana(fabs(moj_datum-ref_datum));
  razlika_dana=razlika_dana%7;
  return ime_dana[razlika_dana];
}
/*Datum operator++(Datum &d){
  int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
  if(Datum::DaLiJePrestupna(d.godina)) broj_dana[1]++;
  d.dan++;
  if(d.dan==broj_dana[d.mjesec-1]+1){ d.dan=1; d.mjesec++;}
  if(d.mjesec==13){ d.mjesec=1; d.godina++;}
  return d;
}
Datum operator++(Datum &d,int){
  Datum pomocni(d.dan,d.mjesec,d.godina);
  int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
  id(Datum::DaLiJePrestupna(d.godina)) broj_dana[1]++;
  d.dan++;
  if(d.dan==broj_dana[d.mjesec-1]+1){ d.dan=1; d.mjesec++;}
  if(d.mjesec==13){ d.mjesec=1; d.godina++;}
  return pomocna;
}*/
int main (){
  std::cout<<"Prolazi"<<std::endl;
	return 0;
}

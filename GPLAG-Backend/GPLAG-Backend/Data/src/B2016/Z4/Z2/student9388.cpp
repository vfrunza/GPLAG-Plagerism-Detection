/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <new>
#include <list>
class GradjaninBiH{
// enum Pol{Musko, Zensko};
 std::string ime_i_prezime;
 long long int jmbg{1};
 int dan, mjesec, godina, sifra_regije, redni_broj;
 int pol;
// GradjaninBiH *veza;
// GradjaninBiH *veza,*pocetak{nullptr}, *prethodni;
// GradjaninBiH *novi(new G)
// Pol pol;
  public: 
   GradjaninBiH *veza;
   enum Pol{Musko,Zensko};
   GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
   GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
   std::string DajImeIPrezime() const;
   long long int DajJMBG() const;
   int DajDanRodjenja() const;
   int DajMjesecRodjenja() const;
   int DajGodinuRodjenja() const;
   int DajSifruRegije() const;
   Pol DajPol() const;
   void PromijeniImeIPrezime(std::string novo_ime);
};
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
 GradjaninBiH::ime_i_prezime=ime_i_prezime;
 GradjaninBiH::jmbg=jmbg;
 int dan, mjesec, godina, regija, redni_broj, kb;
 int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
 int pol;
 int ind{12}, ostatak{0};
 int c[13]{0};
 while(jmbg>0){
  ostatak=jmbg%10;
  jmbg=(jmbg-ostatak)/10;
  c[ind]=ostatak;
  ind--;
 }
 dan=c[0]*10+c[1];
 mjesec=c[2]*10+c[3];
 if(c[4]==9) godina=1000+c[4]*100+c[5]*10+c[6];
 else godina=2000+c[4]*100+c[5]*10+c[6];
 regija=c[7]*10+c[8];
 if(c[9]>=5) pol=1;
 else pol=0;
 redni_broj=c[9]*100+c[10]*10+c[11];
 if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
 if(dan<1 || dan>broj_dana[mjesec-1] || mjesec<1 || mjesec>12 || godina<1 || regija<0 || regija>99) 
  throw std::logic_error("JMBG nije validan");
 kb=11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11;
 if(kb==11) c[12]=0;
 if(kb==10) throw std::logic_error("JMBG nije validan");
 GradjaninBiH::dan=dan;
 GradjaninBiH::mjesec=mjesec;
 GradjaninBiH::godina=godina;
 GradjaninBiH::sifra_regije=regija;
 GradjaninBiH::redni_broj=redni_broj;
 GradjaninBiH::pol=pol;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
 GradjaninBiH::ime_i_prezime=ime_i_prezime;
 GradjaninBiH::dan=dan_rodjenja;
 GradjaninBiH::mjesec=mjesec_rodjenja;
 GradjaninBiH::godina=godina_rodjenja;
 GradjaninBiH::sifra_regije=sifra_regije;
 GradjaninBiH::pol=pol;
 int kb{0}, c[12]{0}, ind{0}, broj, dan1, mjesec1, godina1, sifra_regije1, broj1;
 int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
 if(pol==0) broj=0;
 else broj=500;
 if((godina_rodjenja%4==0 && godina_rodjenja%100!=0) || godina_rodjenja%400==0) broj_dana[1]++;
 if(dan_rodjenja<1 || dan_rodjenja>broj_dana[mjesec_rodjenja-1] || mjesec_rodjenja<1 || mjesec_rodjenja>12 || godina_rodjenja<1 || sifra_regije<0 || sifra_regije>99)
  throw std::logic_error("Neispravni podaci");
 while(ind!=1){ 
 // std::cout <<"1 "<<kb;
  dan1=dan_rodjenja;
  mjesec1=mjesec_rodjenja;
  godina1=godina_rodjenja;
  sifra_regije1=sifra_regije;
  GradjaninBiH::jmbg=GradjaninBiH::jmbg*dan_rodjenja; 
  GradjaninBiH::jmbg=GradjaninBiH::jmbg*100+mjesec_rodjenja;
  GradjaninBiH::jmbg=GradjaninBiH::jmbg*1000+godina_rodjenja%1000;
  GradjaninBiH::jmbg=GradjaninBiH::jmbg*100+sifra_regije;
  GradjaninBiH::jmbg=GradjaninBiH::jmbg*1000+broj;
  c[1]=dan1%10;
  c[0]=(dan1-c[1])/10;
  c[3]=mjesec1%10;
  c[2]=(mjesec1-c[3])/10;
  c[6]=godina1%10;
  godina1=(godina1-c[6])/10;
  c[5]=godina1%10;
  godina1=(godina1-c[5])/10;
  c[4]=godina1%10;
  c[8]=sifra_regije1%10;
  c[7]=(sifra_regije1-c[8])/10;
  broj1=broj;
  c[11]=broj1%10;
  broj1=(broj1-c[11])/10;
  c[10]=broj1%10;
  c[9]=(broj1-c[10])/10;
  kb=11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11; 
  if(kb==11) kb=0;
  if(kb!=10){ind=1; break;}
  if(kb==10) {kb=0; broj++; GradjaninBiH::jmbg=1;}
 }
 GradjaninBiH::jmbg=GradjaninBiH::jmbg*10+kb;
 GradjaninBiH::redni_broj=broj;
// jmbg=GradjaninBiH::jmbg;
}
long long int GradjaninBiH::DajJMBG() const{
 return GradjaninBiH::jmbg;
}
std::string GradjaninBiH::DajImeIPrezime() const{
 return GradjaninBiH::ime_i_prezime;
}
int GradjaninBiH::DajDanRodjenja() const{
 return GradjaninBiH::dan;
}
int GradjaninBiH::DajMjesecRodjenja() const{
 return GradjaninBiH::mjesec;
}
int GradjaninBiH::DajGodinuRodjenja() const{
 return GradjaninBiH::godina;
}
int GradjaninBiH::DajSifruRegije() const{
 return GradjaninBiH::sifra_regije;
}
/*Pol GradjaninBiH::DajPol() const{
 return GradjaninBiH::Pol pol;
}*/
int main ()
{
 try{
  int izbor{-1},d,m,g, sifra;
  std::string ime;
  long long int jmbg;
  enum Pol{Musko, Zensko};
  int pol;
  GradjaninBiH *pocetak(nullptr), *prethodni;
 // GradjaninBiH *pocetak(nullptr), *prethodni;
//  std::string ime;
  /*for(;;){
   std::getline(std::cin, ime);
   std::cin >>jmbg;
  if(ime[0]=='.') break;
  GradjaninBiH *novi(new GradjaninBiH(ime,jmbg));
  novi->DajImeIPrezime()=ime; novi->veza=nullptr;
  if(!pocetak) pocetak=novi;
  else prethodni->veza=novi;
  prethodni=novi;
 }*/

 while(izbor!=0){
  std::cout <<"Unesite 1 za unos1, 2 za unos2, 0 za kraj: ";
  std::cin >>izbor;
  std::cin.ignore(10000,'\n');
  switch(izbor){
   case 0: 
    break;
   case 1:
    std::cout <<"Unesite ime i prezime: ";
    std::getline(std::cin, ime);
    std::cout <<"Unesite JMBG: ";
    std::cin >>jmbg;
    GradjaninBiH *novi(new GradjaninBiH(ime, jmbg));
    novi->DajImeIPrezime()=ime; //novi->DajJMBG()=jmbg;
    novi->veza=nullptr;
    if(!pocetak) pocetak=novi;
    else prethodni->veza=novi;
    prethodni=novi;
    std::cout <<"1";
    break;
  case 2:
    std::cout <<"Unesite ime i prezime: ";
    std::getline(std::cin, ime);
    std::cout <<"Unesite d m g rodjenja: ";
    std::cin >>d>>m>>g;
    std::cout <<"Unesite sifru regije: ";
    std::cin >>sifra;
    std::cout <<"Unesite pol: ";
    std::cin >>pol;
    novi=new GradjaninBiH(ime,d,m,g,sifra,(GradjaninBiH::Pol)pol);
    novi->DajImeIPrezime()=ime; //novi1->DajDanRodjenja()=d;
   // novi1->DajMjesecRodjenja()=m; novi1->DajGodinuRodjenja()=g;
   // novi1->DajSifruRegije()=sifra;
    novi->veza=nullptr;
    if(!pocetak) pocetak=novi;
    else prethodni->veza=novi;
    prethodni=novi;
    std::cout <<"2";
    break;
   default: break;
  }
 }
 }
 catch(std::logic_error izuzetak){
  std::cout <<izuzetak.what();
 }
	return 0;
}
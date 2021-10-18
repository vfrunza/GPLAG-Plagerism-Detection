/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<memory>
#include<string>
#include<algorithm>
#include<stdexcept>
#include<time.h>
#include<stdlib.h>
using namespace std;

class GradjaninBiH
{
    //gradjanin sadrzi ime i prazime gradjana
    string gradjanin;
    long long int JMBG;
    int dan, mjesec, godina;
    int sifra;
    Pol pol_gradjana;
    public:
    enum Pol{Musko, Zensko};
    GradjaninBiH(string ime_i_prezime, long long int jmbg);
    
    GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    GradjaninBiH *gradjan;
    ~GradjaninBiH();
    long long int DajJMBG () const { return JMBG;}
    int DajDanRodjenja() const { return dan;}
    int DajMjesecRodjenja() const { return mjesec;}
    int DajGodinuRodjenja() const { return godina;}
    int DajSifruRegije() const {return sifra;}
    Pol DajPol() const { return pol_gradjana;}
    void PromijeniImeIPrezime(string novo_ime)
    {
        gradjanin.clear();
        strcpy(gradjanin, novo_ime);
    }
     
};
GradjaninBiH(string ime_i_prezime, long long int jmbg)
{
    strcpy(gradjanin, ime_i_prezime);
    int cifre_jmbga[13]; int brojac=12;
    while(jmbg!=0)
    {
        cifre_jmbga[brojac]=jmbg%10;
        jmbg/=10;
        brojac--;
    }
    if((niz[0] && niz[1]==0 ) || (niz[2]&&niz[3]==0) ||(niz[4]&&niz[5] && niz[6]==0)) throw logic_error("JMBG nije validan");
 int dan_rodjenja=niz[0]*10+niz[1];
 int mjesec_rodjenja=niz[2]*10+niz[3];
 int godina_rodjenja=niz[4]*100+niz[5]*10+niz[6];
 if(godina_rodjenja<=17) godina_rodjenja+=2000;
 else godina_rodjenja+=1000;
 int sifra_regije=niz[7]*10+niz[8];
 dan=dan_rodjenja;
 mjesec=mjesec_rodjenja;
 godina=godina_rodjenja;
 sifra=sifra_regije;
    int broj=niz[9]*100+niz[10]*10+niz[11];
    if(broj<500) pol_gradjana='Musko';
    else pol_gradjana='Zensko';
}
GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol)
{
   strcpy(gradjanin, ime_i_prezime); 
    if(dan_rodjenja<1 || dan_rodjenja>31 || mjesec_rodjenja<1 || mjesec_rodjenja>12 || 2017-godina_rodjenja>100 ||godina_rodjenja>2017 || sifra_regije>99 ||sifra_regije<0 || (Pol!='Musko' && Pol!='Zensko'))
    throw logic_error("Neispravni podaci");
   
   int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13;
   if(dan_rodjenja<10) {c1=0; c2=dan_rodjenja}
   else { int temp=dan_rodjenja; c1=temp%10; temp/=10; c2=temp;}
   if(mjesec_rodjenja<10) { c3=0; c4=mjesec_rodjenja;}
   else { int temp=mjesec_rodjenja; c3=temp%10; temp/=10; c4=temp;}
   int za_godine=godina_rodjenja;
   c5=za_godine%10; za_godine/=10; c6=za_godine%10; za_godine/=10; c7=za_godine%10;
   if((c1==0 && c2==0) || (c3==0 && c4==0) || (c5==0 && c6==0)) throw logic_error("JMBG nije validan");
   
   if(sifra_regije<10) { c8=0; c9=sifra_regije;}
    if(Pol=='Musko')
    {
        //Generisi slucajan broj izmedju 0 i 499
    srand(time(0));    
         const int niza=0;
         const int visa=499;
         int slucajni=rand()%(visa-niza+1)+niza;
         if(slucajni==0) { c10=0; c11=0; c12=0;}
    else if(slucajni>0 && slucajni<100) { c10=0; c11=slucajni%10; slucajni/=10;c12=slucajni%10;}
    
       else
       {
           c10=slucajni%10; slucajni/=10; c11=slucajni%10; slucajni/=10; c12=slucajni%10;
       }
    }
    else if(Pol=='Zensko')
    { srand(time(0));
        const int niza=500;
    const int visa=999;
    int slucajni=rand()%(visa-niza+1)+niza;
     //Generisi slucajan broj izmedju 500 i 999
     c10=slucajni%10; slucajni/=10; c11=slucajni%10; slucajni/=10; c12=slucajni%10;
    }
    c13=11-(7*(c1+c7)+6*(c2+c8)+5*(c3+c9)+4*(c4+c10)+3*(c5+c11)+2*(c6+c11))%11;
    if(c13==11) c13=0;
    if(c13==10) throw logic_error("JMBG nije validan");
    //Formiraj jmbg od postojecih 13 cifara
    long long jmbg=c1;
    jmbg=jmbg*10+c2;
    jmbg=jmbg*10+c3;
    jmbg=jmbg*10+c4;
    jmbg=jmbg*10+c5;
    jmbg=jmbg*10+c6;
    jmbg=jmbg*10+c7;
    jmbg=jmbg*10+c8;
    jmbg=jmbg*10+c9;
    jmbg=jmbg*10+c10;
    jmbg=jmbg*10+c11;
    jmbg=jmbg*10+c12;
    jmbg=jmbg*10+c13;
    JMBG=jmbg;
}

GradjaninBiH::~GradjaninBiH()
{
 if(gradjan!=nullptr)
 {
     delete gradjan;
     gradjan=nullptr;
 }
}
int main ()
{
	return 0;
}
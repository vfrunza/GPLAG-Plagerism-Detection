/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>


using namespace std;

 enum Pol {Musko,Zensko};
 
class GradjaninBiH {
    string ime_i_prezime;
    int niz_jmbg[13];
    long long int jmbg;
    int dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije;
    //long long int KreirajJMBG(int d,int m,int g,int s,Pol p);
    Pol pol;
    GradjaninBiH *sljedeci=nullptr;
    public:
    GradjaninBiH(string ime_i_prezime,long long int jmbg);
    GradjaninBiH(string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol);
    //~GradjaninBiH();
    string DajImeIprezime() const {return ime_i_prezime;}
    long long int DajJMBG() const {return jmbg;}
    int DajDanRodjenja() const {return dan_rodjenja;}
    int DajMjesecRodjenja() const {return mjesec_rodjenja;}
    int DajGodinuRodjenja() const {return godina_rodjenja;}
    int DajSifruRegije() const {return sifra_regije;}
    Pol DajPol() const {return pol;}
    void PromijeniImeIPrezime(string novo_ime);
    GradjaninBiH(const GradjaninBiH &g)=delete;
    GradjaninBiH &operator =(const GradjaninBiH &g)=delete;
};
 GradjaninBiH:: GradjaninBiH(string ime_i_prezime,long long int jmbg){
     int dan,mjesec,godina,sifra;
     int cifre[13];
     long long int br(jmbg);
     int i=12;
     while(br!=0){
         int cifra=br%10;
         cifre[i]=cifra;
         i--;
         br/=10;
     }
     dan=cifre[0]*10+cifre[1];
     mjesec=cifre[2]*10+cifre[3];
     if(cifre[4]==0)godina=2*1000+cifre[4]*100+cifre[5]*10+cifre[6];
     else godina=1000+cifre[4]*100+cifre[5]*10+cifre[6];
     sifra=cifre[7]*10+cifre[8];
     if(sifra<0 || sifra>99)throw logic_error("JMBG nije validan");
     int p=cifre[9]*100+cifre[10]*10+cifre[11],c13;
     if(p<0 || p>999) throw logic_error ("JMBG nije validan");
     c13=11-(7*(cifre[0]+cifre[6])+ 6*(cifre[1]+cifre[7])+ 5*(cifre[2]+cifre[8]) + 4*(cifre[3]+cifre[9]) + 3*(cifre[4]+cifre[10])+ 2*(cifre[5]+cifre[11]))%11;
     if(c13==11)c13=0;
     if(c13==10 || c13!=cifre[12])throw logic_error("JMBG nije validan");
     int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
     if(godina % 4 ==0 && godina % 100!=0 || godina % 400==0)broj_dana[1]++;
     if(godina<1 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1])throw logic_error("JMBG nije validan");
     GradjaninBiH::ime_i_prezime=ime_i_prezime;GradjaninBiH::jmbg=jmbg;
     dan_rodjenja=dan;
     mjesec_rodjenja=mjesec;
     godina_rodjenja=godina;
     sifra_regije=sifra;
     if(p>=0 && p<=499)pol=Musko;
     else pol=Zensko;
     for(int i=0;i<13;i++){
      if(dan>0 && dan<10)niz_jmbg[0]=0;
      niz_jmbg[i]=cifre[i];
     }
 }
long long int GradjaninBiH::KreirajJMBG(int d,int m,int g,int s,Pol p){
 long long int jmbg;
 if(d>0 && d<10){niz_jmbg[0]=0;niz_jmbg[1]=d;}
 else {
  niz_jmbg[1]=d%10;
  d=d/10;
  niz_jmbg[0]=d%10;
 }
if(m>0 && m<10){niz_jmbg[2]=0;niz_jmbg[3]=m;}
else {
 niz_jmbg[3]=m%10;
 m=m/10;
 niz_jmbg[2]=m%10;
}
niz_jmbg[6]=g%10;
g=g/10;
niz_jmbg[5]=g%10;
g=g/10;
niz_jmbg[4]=g%10;
if(s>0 && s<10){niz_jmbg[7]=0;niz_jmbg[8]=s;}
else{
 niz_jmbg[8]=s%10;
 s=s/10; 
 niz_jmbg[7]=s%10;
}
}
GradjaninBiH:: GradjaninBiH(string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol){
 GradjaninBiH::ime_i_prezime=ime_i_prezime;
 int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
 if(godina_rodjenja % 4 ==0 && godina_rodjenja % 100!=0 || godina_rodjenja % 400==0)broj_dana[1]++;
 if(godina_rodjenja<1 || mjesec_rodjenja<1 || mjesec_rodjenja>12 || dan_rodjenja<1 || dan_rodjenja>broj_dana[mjesec_rodjenja-1])throw logic_error("Neispravni podaci");
 if(sifra_regije<0 || sifra_regije>99)throw logic_error("Neispravni podaci");
 if(pol!=Musko && pol!=Zensko)throw logic_error ("Neispravni podaci");
 GradjaninBiH::dan_rodjenja=dan_rodjenja;GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;GradjaninBiH::godina_rodjenja=godina_rodjenja;
 GradjaninBiH::sifra_regije=sifra_regije;GradjaninBiH::pol=pol;
 //GradjaninBiH::jmbg=KreirajJMBG(dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,pol);

 
}
inline void GradjaninBiH::PromijeniImeIPrezime(string novo_ime){
 ime_i_prezime=novo_ime;
}

int main ()
{
 try{
 
 GradjaninBiH /*g1("Rambo Sulejmanovic", 1305956175002),*/g2("Rambo Sulejmanovic",13,5,1956,17,Musko);
//cout<<g1.DajImeIprezime()<<" "<<g1.DajDanRodjenja()<<"."<<g1.DajMjesecRodjenja()<<"."<<g1.DajGodinuRodjenja()<<"."<<g1.DajSifruRegije()<<" "<<g1.DajPol()<<endl;
cout<<g2.DajImeIprezime()<<" "<<g2.DajDanRodjenja()<<"."<<g2.DajMjesecRodjenja()<<"."<<g2.DajGodinuRodjenja()<<"."<<g2.DajSifruRegije()<<" "<<g2.DajPol();

}
catch(logic_error l){
    cout<<l.what();
}
	return 0;
}
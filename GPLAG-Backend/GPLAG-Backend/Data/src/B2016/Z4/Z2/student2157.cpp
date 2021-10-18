/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
class Gradjanin{
  enum Pol {Musko, Zensko};
  Pol p;
  long long int JMBG;
  int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije;
   mutable std::string ime_i_prezime;
  public:
  Gradjanin(std::string i_i_p, long long int J){
      JMBG=J;
      ime_i_prezime=i_i_p;
      int Cifra[13];
      int JMB=JMBG;
      for(int i = 13; i < 13; i--){
          Cifra[i]=(JMB%10);
          JMB/=10;
      }
      dan_rodjenja=Cifra[0]*10+Cifra[1];
      mjesec_rodjenja=Cifra[2]*10+Cifra[3];
      if((Cifra[4]*100+Cifra[5]*10+Cifra[6])>17){
          godina_rodjenja=1000+Cifra[4]*100+Cifra[5]*10+Cifra[6];
      }
      else godina_rodjenja=2000+Cifra[4]*100+Cifra[5]*10+Cifra[6];
      sifra_regije=Cifra[7]*10+Cifra[8];
      if((Cifra[9]*100+Cifra[10]*10+Cifra[11])<500) p=Musko;
      else p=Zensko;
      int Ca=7*(Cifra[0]+Cifra[6]);
      int Cb=6*(Cifra[1]+Cifra[7]);
      int Cc=5*(Cifra[2]+Cifra[8]);
      int Cd=4*(Cifra[3]+Cifra[9]);
      int Ce=3*(Cifra[4]+Cifra[10]);
      int Cf=2*(Cifra[5]+Cifra[11]);
      int Cg=(Ca+Cb+Cc+Cd+Ce+Cf)%11;
      int posljednja_cifra(11-Cg);
      if(posljednja_cifra==11) posljednja_cifra=0;
      if(Cifra[12] != posljednja_cifra || posljednja_cifra==10) throw JMBG; }
        long long int DajJMBG() const {return JMBG;}
        int DajDanRodjenja() const{return dan_rodjenja;}
        int DajMjesecRodjenja() const {return mjesec_rodjenja;}
        int DajGodinuRodjenja() const{return godina_rodjenja;}
        std::string DajImeIPrezime() const {return ime_i_prezime;}
        int DajSifruRegije() const { return sifra_regije;}
        Pol DajPol(){return p;}
        void PromijeniImeIPrezime(std::string IIP){ime_i_prezime=IIP;} 
};
int main ()
{
	return 0;
}
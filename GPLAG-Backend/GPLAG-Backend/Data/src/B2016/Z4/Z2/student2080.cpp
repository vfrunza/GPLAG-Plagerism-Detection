/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
int NapraviBroj(int a, int b){
    return a*10+b;
}
int NapraviBroj(int a, int b, int c){
    return a*100+b*10+c;
}
int NapraviGodinu(int a, int b, int c){
    if(a==0)return 2000+a*100+b*10+c;
    else return 1000+a*100+b*10+c;
}
void ProvjeraZaPrestupnu(int godina, int mjesec, int dan){
    if((godina%4==0 && godina%100!=0) || godina%400==0){
          if((mjesec==1 || mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10 || mjesec==12) && dan>31)throw std::logic_error("JMBG nije validan");
          else if((mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11) && dan>30)throw std::logic_error("JMBG nije validan");
          else if(mjesec==2 && dan>28)throw std::logic_error("JMBG nije validan");
      }
      else{
          if((mjesec==1 || mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10 || mjesec==12) && dan>31)throw std::logic_error("JMBG nije validan");
          else if((mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11) && dan>30)throw std::logic_error("JMBG nije validan");
          else if(mjesec==2 && dan>29)throw std::logic_error("JMBG nije validan");
      }
}

class GradjaninBiH {
    std::string ime_i_prezime;
    long long int JMBG;
    int dan;
    int mjesec;
    int godina;
    int sifra;
    int kontrolna;
    mutable int br=0;
  public:  
  enum Pol{Musko,Zensko};
  Pol pol_gradjanina;
  GradjaninBiH(std::string ime_i_prezime,long long int jmbg){
      long long int pom(jmbg);
      int br(0);
      while(pom!=0){
          pom=pom/10;
          br++;
      }
      int cifre[13]{0};
      if(br==12){
          for(int i(12);i>0;i--){
              int cifra(jmbg%10);
              cifre[i]=cifra;
              jmbg/=10;
          }
          cifre[0]=0;
      }
      else{
      for(int i(12);i>=0;i--){
          int cifra(jmbg%10);
          cifre[i]=cifra;
          jmbg/=10;
          }
      }
      
      godina=NapraviGodinu(cifre[4],cifre[5],cifre[6]); // za datum
      mjesec=NapraviBroj(cifre[2],cifre[3]);
      if(mjesec>12)throw std::logic_error("JMBG nije validan");
      dan=NapraviBroj(cifre[0],cifre[1]);
      ProvjeraZaPrestupnu(godina,mjesec,dan);
      
      sifra=NapraviBroj(cifre[7],cifre[8]);
      int pomocna_za_pol=NapraviBroj(cifre[9],cifre[10],cifre[11]);
      if(pomocna_za_pol>0 && pomocna_za_pol<500)pol_gradjanina=Musko;
      else pol_gradjanina=Zensko;
      int pomocna;
      
      pomocna=cifre[12];
      if(pomocna==11)kontrolna=0;
      else if(pomocna==10)throw std::logic_error("JMBG nije validan"); // provjeriti
      else kontrolna=pomocna;
      }
  GradjaninBiH(std::string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol){
      ime_i_prezime=ime_i_prezime;
      godina=godina_rodjenja;
      mjesec=mjesec_rodjenja;
      if(mjesec>12)throw std::logic_error("JMBG nije validan");
      dan=dan_rodjenja;
      ProvjeraZaPrestupnu(godina,mjesec,dan);
      if(sifra_regije<0 || sifra_regije>99)throw std::logic_error("JMBG nije validan");
      else sifra=sifra_regije;
      pol_gradjanina=pol;
      //Kreiranje JMBG-a
      int cifre[13]{0};
      if(dan>0 && dan<10){cifre[0]=0; cifre[1]=dan;}
      else{cifre[1]=dan%10; cifre[0]=dan/10; }
      if(mjesec>0 && mjesec<10) {cifre[2]=0; cifre[3]=mjesec;}
      else{cifre[3]=mjesec%10; cifre[2]=mjesec/10;}
      if(godina<2000){cifre[4]=(godina-1000)/100; cifre[5]=((godina-1000)/10)%10;cifre[6]=(godina-1000)%10; }
      else{cifre[4]=0; cifre[5]=(godina-2000)/10; cifre[6]=(godina-2000)%10;}
      cifre[7]=sifra/10;
      cifre[8]=sifra%10;
      //if(pol==Musko) // uvesti mozda neki mutable int ...
      if(pol==Musko){
      if(br==0){cifre[9]=0; cifre[10]=0;cifre[11]=0; }
      else if(br>=10 && br<100){cifre[9]=0;cifre[10]=br/10; cifre[11]=br%10;}
      else if(br>=100 && br<1000){cifre[9]=br/100; cifre[10]=(br/10)%10; cifre[11]=br%10;} }
      else{
          cifre[9]=(br+500)/100; cifre[10]=((br+500)/10)&10; cifre[11]=(br+500)%10;
      }
      br++;
      // posljednja kontrolna se racuna po datoj formuli
      cifre[12]=11-(7*(cifre[0]+cifre[6])+6*(cifre[1]+cifre[7])+5*(cifre[2]+cifre[8])+4*(cifre[3]+cifre[9])+3*(cifre[4]+cifre[10])+2*(cifre[5]+cifre[11]))%11;
      int i(13),brojac(0);
      long long int jmbg(0);
      while(i!=0){
          jmbg+=cifre[i-1]*pow(10,brojac);
          brojac++;
          i--;
      }
      JMBG=jmbg;
  }
  long long int DajJMBG()const{ return JMBG;}
  std::string DajImeIPrezime()const{ return ime_i_prezime;}
  int DajDanRodjenja()const{ return dan;}
  int DajMjesecRodjenja()const{return mjesec;}
  int DajGodinuRodjenja()const{return godina;}
  int DajSifruRegije()const{return sifra;}
  Pol DajPol()const{return pol_gradjanina;}
  void PromijeniImeIPrezime(std::string novo_ime){ime_i_prezime=novo_ime;}
};
int main ()
{
    std::cout<<"Koliko gradjana zelite unijeti po JMBG";
	return 0;
}
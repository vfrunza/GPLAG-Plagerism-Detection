/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH{
  
  GradjaninBiH *prethodni;
  GradjaninBiH  *zadnji=nullptr;
  
  std::string ime_i_prezime;
  long long int jmbg;
  //std::string pol;
  int dan_rodj, mjesec_rodj, godina_rodj,sifra_regije,razlika;
  bool ProvjeraDatuma(int d, int m, int g){
      int br_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
      if((g%4==0 && g%100!=0 )|| g%400==0)br_dana[1]++;
      if(g<1 || g<1917 || d<1 || m<1 || m>12 || d>br_dana[m-1])
      return false;
      return true;
  }
  long long int GenerisiJMBG(int razlika);
  public:
  
  ~GradjaninBiH(){
    GradjaninBiH *t=zadnji;
    while(t->prethodni!=nullptr) t=t->prethodni;
    t->prethodni=this->prethodni;
  }
  enum Pol { Musko, Zensko}pol;
  GradjaninBiH(std:: string ime_i_prezime, long long int jmbg);
  GradjaninBiH(std:: string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, 
               int godina_rodjenja, int sifra_regije, Pol pol);
  std::string DajImeIPrezime() const{return ime_i_prezime;}
  long long int DajJMBG() const{return jmbg;}
  int DajDanRodjenja() const{ return dan_rodj;}
  int DajMjesecRodjenja() const{ return mjesec_rodj;}
  int DajGodinuRodjenja()const{ return godina_rodj;}
  int DajSifruRegije() const{ return sifra_regije;}
  Pol DajPol() const{return pol;};
  void PromijeniImeIPrezime( std:: string novo_ime){ime_i_prezime=novo_ime;}
};

long long int GradjaninBiH:: GenerisiJMBG(int razlika=000){
   //std::cout<<std::endl<<dan_rodj<<" "<<mjesec_rodj<<" "<<godina_rodj<<" "<<sifra_regije<<std::endl;
   long long int jmbg=(dan_rodj*100 + mjesec_rodj);
   jmbg*=1000 ;
   jmbg+= (godina_rodj % 1000);
   jmbg*=100;
   jmbg+= sifra_regije;
   jmbg*=1000;
   
   //std::cout<<jmbg<<std::endl;
   
   int br=0;
   GradjaninBiH *t =prethodni;
   //std::cout<<t->DajDanRodjenja();
   while(t!= nullptr){
     if(t->godina_rodj== godina_rodj && t->mjesec_rodj==mjesec_rodj && t->dan_rodj==dan_rodj && t->sifra_regije==sifra_regije && t->pol==pol)
     br++;
     t=t->prethodni;
   }
   //std::cout<<br<<std::endl;
   if(pol==Musko) jmbg+=br;
   else jmbg+=br+500;
   
   int JMBG[13];
   long long int pom=jmbg;
   //std::cout<<pom<<" ";
   int i=11;
   while(pom!=0){
       
     int c=pom%10;
     //std::cout<<c<<" ";
     JMBG[i]=c;
     //std::cout<<JMBG[i]<<std::endl; 
     i--;
     pom/=10;
   }
   //for(int i=0;i<12;i++)
   //std::cout<<JMBG[i]<<" ";
   //std::cout<<std::endl;
   
   int c13=11-(7*(JMBG[0] + JMBG[6]) + 6*(JMBG[1] + JMBG[7]) + 5*(JMBG[2] + JMBG[8]) + 4*(JMBG[3] + JMBG[9]) + 
   3*(JMBG[4] + JMBG[10]) + 2*( JMBG[5] + JMBG[11]))%11;
   if(c13==11) c13=0;
   //std::cout<<" "<<c13<<" ";
   if(c13==10) throw std::logic_error("JMBG nije validan");
   
   jmbg*=10;
   jmbg+=c13;
   
   
   
   return jmbg;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    //zadnji=nullptr;
    GradjaninBiH::ime_i_prezime= ime_i_prezime;
    long long int pom=jmbg;
    GradjaninBiH::jmbg=pom;

    int d=pom/100000000000; dan_rodj=d;
    int m=(pom/1000000000)%100; mjesec_rodj=m;
    int g=((pom/1000000)%1000)+1000; godina_rodj=g;
    sifra_regije=(pom/10000)%100;
    if(((pom/10)%1000)>499) pol=Zensko;
    else pol=Musko;
    int koliko=(pom/10)%1000; razlika=koliko;
    
    if(this->zadnji==nullptr){
        prethodni=nullptr;
        zadnji=this;
    }else
    {
        prethodni=zadnji;
        zadnji=this;
    }
    
    //std::cout<<dan_rodj<<" "<<mjesec_rodj<<" "<<godina_rodj<<" "<<sifra_regije<<std::endl;
    //long long int p=GenerisiJMBG();
    //std::cout<<p;
    if(!ProvjeraDatuma(d,m,g) /*|| this->GenerisiJMBG()%10!= jmbg%10*/) throw std::logic_error("JMBG nije validan");
    while(this->prethodni!=nullptr)
    {
        if(this->GenerisiJMBG()==(this->prethodni)->GenerisiJMBG())throw std::logic_error("bla bla");
    }
}
GradjaninBiH:: GradjaninBiH(std:: string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    if(!ProvjeraDatuma(dan_rodjenja,mjesec_rodjenja, godina_rodjenja)) throw std::logic_error("JMBG nije validan");
    dan_rodj=dan_rodjenja;
    mjesec_rodj=mjesec_rodjenja;
    godina_rodj=godina_rodjenja;
    GradjaninBiH::sifra_regije=sifra_regije;
    GradjaninBiH::pol=pol;
    if(zadnji==nullptr){
        prethodni=nullptr;
        zadnji=this;
    }else
    {
        prethodni=zadnji;
        zadnji=this;
    }
    jmbg=GenerisiJMBG();
 }

int main ()
{
    

	return 0;
}
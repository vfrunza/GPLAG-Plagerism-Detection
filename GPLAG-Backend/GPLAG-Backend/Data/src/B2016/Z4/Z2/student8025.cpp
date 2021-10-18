
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
class GradjaninBih{
  std::string ime;
  long long int maticni_broj;
  GradjaninBih *veza=nullptr;
  static GradjaninBih *prethodni;
  public:
  enum Pol {Musko, Zensko};
  GradjaninBih(std::string ime_i_prezime, long long int jmbg){
    long long int n(jmbg);
    long long int l(jmbg);
    int brojac(0);
    while(n!=0){
      n/=10;
      brojac++;
    }
    int pomocni[13];
    int i(0);
    int a;
    while(jmbg!=0){
      a=jmbg%10;
      pomocni[i]=a;
      i++;
      jmbg/=10;
    }
    if(brojac==12){
    int racun(11-(7*(pomocni[6])+6*(pomocni[11]+pomocni[5])+5*(pomocni[10] + pomocni[4])+
    4*(pomocni[9] + pomocni[3])+ 3*(pomocni[8]+ pomocni[2])+2*(pomocni[7]+pomocni[1]))%11);
    if(pomocni[0]!=racun || racun==10 ) throw std::logic_error("JMBG nije validan");
    if( pomocni[11]<1  || pomocni[10]>1 || (pomocni[10]==1 && 
    pomocni[9]>2)) throw std::logic_error("JMBG nije validan"); 
    }
    if(brojac==13){
    int racun(11-(7*(pomocni[12]+pomocni[6])+6*(pomocni[11]+pomocni[5])+5*(pomocni[10] + pomocni[4])+
    4*(pomocni[9] + pomocni[3])+ 3*(pomocni[8]+ pomocni[2])+2*(pomocni[7]+pomocni[1]))%11);
    if(pomocni[0]!=racun) throw std::logic_error("JMBG nije validan");
    if(pomocni[12]>3 || pomocni[12]<0 || pomocni[11]<1 || (pomocni[12]==3 && pomocni[11]>1) || pomocni[10]>1 || (pomocni[10]==1 && 
    pomocni[9]>2)) throw std::logic_error("JMBG nije validan"); 
    }
    
      if(prethodni==nullptr){
        ime=ime_i_prezime;
        maticni_broj=l;
        veza=nullptr;
      }
       else {
        for(GradjaninBih *it=prethodni; it!=nullptr; it=it->veza){
          if(jmbg==it->maticni_broj) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        }
        ime=ime_i_prezime;
        maticni_broj=l;
        this->veza=prethodni;
        
      }
    prethodni=this;
  }
  GradjaninBih(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
int godina_rodjenja, int sifra_regije, Pol pol){
  if(dan_rodjenja>31 || dan_rodjenja<1 || mjesec_rodjenja>12 || 
  mjesec_rodjenja<1 || sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");

int sifra_covjeka;
int pomocni[13];
int i=0;
if(prethodni==nullptr){
  if(pol==Musko) sifra_covjeka=0;
  else if(pol==Zensko) sifra_covjeka=500;
  if(dan_rodjenja<10){
    pomocni[i]=0;
    i++;
    pomocni[i]=dan_rodjenja;
    i++;
  } else if(dan_rodjenja>9){
    int a(dan_rodjenja%10);
    int b(dan_rodjenja/10);
    pomocni[i]=b;
    i++;
    pomocni[i]=a;
    i++;
  }
  if(mjesec_rodjenja<10){
    pomocni[i]=0;
    i++;
    pomocni[i]=mjesec_rodjenja;
    i++;
  }else if(mjesec_rodjenja>9){
    int a(mjesec_rodjenja%10);
    int b(mjesec_rodjenja/10);
    pomocni[i]=b;
    i++;
    pomocni[i]=a;
    i++;
  }
  if(godina_rodjenja<10){
    pomocni[i]=0;
    i++;
    pomocni[i]=0;
    i++;
    pomocni[i]=godina_rodjenja;
    i++;
  }else if(godina_rodjenja<100){
    int a(godina_rodjenja%10);
    int b(godina_rodjenja/10);
    pomocni[i]=0;
    i++;
    pomocni[i]=b;
    i++;
    pomocni[i]=a;
    i++;
  }else if(godina_rodjenja<1000){
    int a(godina_rodjenja%10);
    int b((godina_rodjenja/10)%10);
    int c(godina_rodjenja/100);
    pomocni[i]=c;
    i++;
    pomocni[i]=b;
    i++;
    pomocni[i]=a;
    i++;
  }
  if(sifra_regije<10){
    pomocni[i]=0;
    i++;
    pomocni[i]=sifra_regije;
    i++;
  }else if(sifra_regije>9){
    int a(sifra_regije%10);
    int b(sifra_regije/10);
    pomocni[i]=b;
    i++;
    pomocni[i]=a;
    i++;
  }
  if(pol==Musko){
  pomocni[i]=0;
  i++;
  pomocni[i]=0;
  i++;
  pomocni[i]=0;
  i++;
  }else if(pol==Zensko){
    pomocni[i]=5;
  i++;
  pomocni[i]=0;
  i++;
  pomocni[i]=0;
  i++;
  }
  pomocni[i]=(11-(7*(pomocni[0]+pomocni[6])+6*(pomocni[1]+pomocni[7])+5*(pomocni[2] + pomocni[8])+
    4*(pomocni[3] + pomocni[9])+ 3*(pomocni[4]+ pomocni[10])+2*(pomocni[5]+pomocni[11]))%11);
    if(pomocni[12]==11) pomocni[12]=0; 
    if(pomocni[0]==0) {
      int j(12);
      long long int suma(0);
      for(int i=1; i<=12; i++){
        pomocni[i]*=pow(10,j);
        j--;
        suma+=pomocni[i];
      }
      maticni_broj=suma;
    }else if(pomocni[0]>0){
       int j(13);
      long long int suma(0);
      for(int i=0; i<13; i++){
        pomocni[i]*=pow(10,j);
        j--;
        suma+=pomocni[i];
      }
      maticni_broj=suma;
    }
    ime=ime_i_prezime;
    this->veza=prethodni;
    prethodni=this;
}else{
int maximum(0);
if(pol==Zensko) maximum=500; 
        for(GradjaninBih *it=prethodni; it!=nullptr; it=it->veza){
          int t;
          int niz[13];
       int z=0;   
          int jmbg=it->maticni_broj;
          while(jmbg!=0){
      t=jmbg%10;
      niz[z]=t;
      z++;
      jmbg/=10;
    }
    int d(niz[11]*10+niz[12]*100);
    int m(niz[9]*10+niz[10]*100);
    int g(niz[6]*10+niz[7]*100+niz[8]*1000);
    int r(niz[4]*10+niz[5]*100);
    int s(niz[1]*10 +niz[2]*100+niz[3]*1000);
    if(d==dan_rodjenja && m==mjesec_rodjenja && g==godina_rodjenja && r==sifra_regije){
      if(s>maximum) maximum=s;
      sifra_covjeka=maximum+1;
    }
        }
        sifra_covjeka=maximum+1;
     if(dan_rodjenja<10){
    pomocni[i]=0;
    i++;
    pomocni[i]=dan_rodjenja;
    i++;
  } else if(dan_rodjenja>9){
    int a(dan_rodjenja%10);
    int b(dan_rodjenja/10);
    pomocni[i]=b;
    i++;
    pomocni[i]=a;
    i++;
  }
  if(mjesec_rodjenja<10){
    pomocni[i]=0;
    i++;
    pomocni[i]=mjesec_rodjenja;
    i++;
  }else if(mjesec_rodjenja>9){
    int a(mjesec_rodjenja%10);
    int b(mjesec_rodjenja/10);
    pomocni[i]=b;
    i++;
    pomocni[i]=a;
    i++;
  }
  if(godina_rodjenja<10){
    pomocni[i]=0;
    i++;
    pomocni[i]=0;
    i++;
    pomocni[i]=godina_rodjenja;
    i++;
  }else if(godina_rodjenja<100){
    int a(godina_rodjenja%10);
    int b(godina_rodjenja/10);
    pomocni[i]=0;
    i++;
    pomocni[i]=b;
    i++;
    pomocni[i]=a;
    i++;
  }else if(godina_rodjenja<1000){
    int a(godina_rodjenja%10);
    int b((godina_rodjenja/10)%10);
    int c(godina_rodjenja/100);
    pomocni[i]=c;
    i++;
    pomocni[i]=b;
    i++;
    pomocni[i]=a;
    i++;
  }
  if(sifra_regije<10){
    pomocni[i]=0;
    i++;
    pomocni[i]=sifra_regije;
    i++;
  }else if(sifra_regije>9){
    int a(sifra_regije%10);
    int b(sifra_regije/10);
    pomocni[i]=b;
    i++;
    pomocni[i]=a;
    i++;
  }  
  if(sifra_covjeka<9){
    pomocni[i]=0;
    i++;
    pomocni[i]=0;
    i++;
    pomocni[i]=sifra_covjeka;
    i++;
  }else if(sifra_covjeka<100){
    int a(sifra_covjeka%10);
    int b(sifra_covjeka/10);
    pomocni[i]=0;
    i++;
    pomocni[i]=b;
    i++;
    pomocni[i]=a;
    i++;
  }else if(sifra_covjeka<1000){
    int a(sifra_covjeka%10);
    int b((sifra_covjeka/10)%10);
    int c(sifra_covjeka/100);
    pomocni[i]=c;
    i++;
    pomocni[i]=b;
    i++;
    pomocni[i]=a;
    i++;
}
 pomocni[i]=(11-(7*(pomocni[0]+pomocni[6])+6*(pomocni[1]+pomocni[7])+5*(pomocni[2] + pomocni[8])+
    4*(pomocni[3] + pomocni[9])+ 3*(pomocni[4]+ pomocni[10])+2*(pomocni[5]+pomocni[11]))%11);
    if(pomocni[12]==11) pomocni[12]=0;
    if(pomocni[0]==0) {
      int j(12);
      long long int suma(0);
      for(int i=1; i<=12; i++){
        pomocni[i]*=pow(10,j);
        j--;
        suma+=pomocni[i];
      }
      maticni_broj=suma;
    }else if(pomocni[0]>0){
       int j(13);
      long long int suma(0);
      for(int i=0; i<13; i++){
        pomocni[i]*=pow(10,j);
        j--;
        suma+=pomocni[i];
      }
      maticni_broj=suma;
    }
    ime=ime_i_prezime;
    this->veza=prethodni;
    prethodni=this;
}
}
GradjaninBih(const GradjaninBih &v)=delete;
GradjaninBih &operator=(const GradjaninBih &v) =delete;
~GradjaninBih(){
  prethodni=nullptr;
  veza=nullptr;
}
long long int DajJMBG() const{
  return maticni_broj;
}
int DajDanRodjenja() const{
  long long int n(maticni_broj);
  int pomocni[13];
  int i(0);
  while(n!=0){
    pomocni[i]=n%10;
    i++;
    n/=10;
  }
  if(i==12) return pomocni[11];
  else return pomocni[11]*10+pomocni[12]*100;
}
int DajMjesecRodjenja() const{
  long long int n(maticni_broj);
  int pomocni[13];
  int i(0);
  while(n!=0){
    pomocni[i]=n%10;
    i++;
    n/=10;
  }
  return (pomocni[9]*10+pomocni[10]*100);
}
int DajGodinuRodjenja() const {
    long long int n(maticni_broj);
  int pomocni[13];
  int i(0);
  while(n!=0){
    pomocni[i]=n%10;
    i++;
    n/=10;
  }
  int godina(pomocni[6]*10+pomocni[7]*100+pomocni[8]*1000);
  if(godina<=17)  godina+=2000;
  else godina+=1000;
  return godina;
}
int DajSifruRegije() const{
  long long int n(maticni_broj);
  int pomocni[13];
  int i(0);
  while(n!=0){
    pomocni[i]=n%10;
    i++;
    n/=10;
  }
  return (pomocni[4]*10+pomocni[5]*100);
}
Pol DajPol() const{
   long long int n(maticni_broj);
  int pomocni[13];
  int i(0);
  while(n!=0){
    pomocni[i]=n%10;
    i++;
    n/=10;
  }
  int broj(pomocni[1]*10+pomocni[2]*100+pomocni[3]*1000);
  if(broj<500) return Musko;
  return Zensko;
}
void PromijeniImeIPrezime(std::string novo_ime){
  ime=novo_ime;
}
};
 GradjaninBih *GradjaninBih::prethodni=nullptr;
int main ()
{
 long long int n=806996191588;
 long long int m=2810996191299;
  GradjaninBih("Harun Mesan",n);
  GradjaninBih("Ferid Hadzic",m );
	return 0;
}
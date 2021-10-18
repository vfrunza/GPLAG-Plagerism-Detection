/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<stdexcept>
#include <vector>
class GradjaninBiH
{
  private:
    long long jmbg;
    std::string ime_i_prezime;

    static GradjaninBiH *posljednji;
    GradjaninBiH *prethodni;
    int Fun(int t1, int t2)const;
  public:
    enum Pol {Musko,Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije,Pol pol);
   std::string DajImeIPrezime()const{
       return ime_i_prezime;
   }
    long long int DajJMBG()const{
        return jmbg;
    }
    int DajDanRodjenja()const{
        return Fun(0,1);
    }
    int DajMjesecRodjenja()const{
        return Fun(2,3);
    }
    int DajGodinuRodjenja()const{
        int godina=Fun(4,5);
        godina=godina+1000;
        return godina;
    }
    int DajSifruRegije()const{
        return Fun(8,9);
    }
    Pol DajPol()const{
        int b=Fun(10,11);
        if(b<=499 && b>=0)  return Musko;
        return Zensko;
    }
    void PromijeniImeIprezime(std::string novo_ime){
        ime_i_prezime=novo_ime;
    }
};

int GradjaninBiH::Fun(int t1, int t2)const{
 long long niz[13];
 long long pom=jmbg;
 int i(12);
 while(pom!=0){
     long long cifra=pom%10;
     pom/=10;
     niz[i]=cifra;
     i--;
 }
 
    
    if(t1==0 && t2==1)  return niz[0]*10+niz[1];
    if(t1==2 && t2==3)  return niz[2]*10+niz[3];
    if(t1==4 && t2==5)  return niz[4]*100+niz[5]*10+niz[6];
    if(t1==8 && t2==9)  return niz[7]*10+niz[8];
    if(t1==10)          return niz[10]*100+niz[11]*10+niz[12];
    
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long jmbg){

 long long niz[13];
 long long pom=jmbg;
 int i(12);
 while(pom!=0){
     long long cifra=pom%10;
     pom/=10;
     niz[i]=cifra;
     i--;
 }
//Prvih 7 cifara     
     int dan=niz[0]*10+niz[1];
     int mjesec=niz[2]*10+niz[3];
     int godina=niz[4]*100+niz[5]*10+niz[6];
     
     if(dan>31 || dan<0 || mjesec>12 || mjesec<0 || godina<0 || (mjesec==2 && dan>29))
        throw std::logic_error("JMBG nije validan");
    
    int kont_cifra=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
    if(kont_cifra==11) kont_cifra=0;
    if(kont_cifra==10) 
        throw std::logic_error("JMBG nije validan");
    
    
    
    GradjaninBiH::jmbg=jmbg;
    GradjaninBiH::ime_i_prezime=ime_i_prezime; 
    
    GradjaninBiH* pocetak,pomoc;
     
    
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije,Pol pol){
    
    if(sifra_regije<0 || sifra_regije>99)   throw std::logic_error("Neispravni podaci");
    if(dan_rodjenja<0 || dan_rodjenja>31|| mjesec_rodjenja>31  || mjesec_rodjenja<0 || (mjesec_rodjenja==2 && dan_rodjenja>29))
        throw std::logic_error("Neispravni podaci");
        
}


int main ()
{
    try{
   GradjaninBiH g1("Rambo Sulejmanovic", 4105956174235);
   g1.PromijeniImeIprezime("Mahira Buturovic");
   std::cout<<g1.DajImeIPrezime();
    }
    catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what();
    }
   return 0;
}
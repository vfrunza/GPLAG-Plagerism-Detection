/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

class GradjaninBiH {
    std::string ime;
    long long int JMBG;
    static GradjaninBiH *p;
    GradjaninBiH *pok;
    
  static  int Cifra(long long int jmbg, int x){
        long long a(jmbg/(std::pow(10, 13-x)));
        return a%10;
    }
  static  int Broj(int pocetni_indeks, int broj_cifara, long long int jmbg){
        int broj(0); 
        while(broj_cifara>0){
            broj+=Cifra(jmbg, pocetni_indeks)*std::pow(10, broj_cifara-1);
            broj_cifara--;
            pocetni_indeks++;
        }
        return broj;
    }
    int PoslednjaCifra(int dan, long long int jmbg){
        int c;
        if(dan<10){
        c=11-(7*(0+Cifra(jmbg,6))+6*(Cifra(jmbg,1)+Cifra(jmbg,7))+5*(Cifra(jmbg,2)+Cifra(jmbg,8))+4*(Cifra(jmbg,3)+Cifra(jmbg,9))+
        3*(Cifra(jmbg,4)+Cifra(jmbg,10))+2*(Cifra(jmbg,5)+Cifra(jmbg,11)))%11;
        }
        else{
        c=11-(7*(Cifra(jmbg,1)+Cifra(jmbg,7)) + 6*(Cifra(jmbg,2) + Cifra(jmbg,8)) + 5*(Cifra(jmbg,3)+Cifra(jmbg,9))+ 4*(Cifra(jmbg,4)+Cifra(jmbg,10))
        + 3*(Cifra(jmbg,5)+Cifra(jmbg,11))+ 2*(Cifra(jmbg,6)+Cifra(jmbg,12)))%11;
        }
        if(c==11) c=0; 
        return c;
    }
    long long int KreirajJmbg(int dan, int mesec, int godina, int regija){
        long long int jmbg;
        if(godina>=2000) godina-=100;
           godina-=1000;
        
        jmbg=dan%100*std::pow(10,11)+ mesec*std::pow(10,9) + godina*std::pow(10,6) + regija*std::pow(10, 4);
        jmbg+=PoslednjaCifra(dan, jmbg);
        return jmbg;
    }
    int BrojCifara(long long int jmbg) const{
        int brojac(0);
        while(jmbg!=0){
            brojac++;
            jmbg/=10;
        }
        return brojac;
    }
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
        p=pok; pok=this;
        if(dan_rodjenja>31 || dan_rodjenja<0 || mjesec_rodjenja>12 || mjesec_rodjenja<0 || godina_rodjenja>2017 || godina_rodjenja<1917 || sifra_regije<0
        || sifra_regije>99) throw std::logic_error ("Neispravni podaci");
        ime=ime_i_prezime; JMBG=KreirajJmbg(dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije);
    }
    std::string DajImeIPrezime() const { return ime; }
    long long int DajJMBG() const { return JMBG; }
    int DajDanRodjenja() const {if(BrojCifara(JMBG)==12) return Cifra(JMBG,1); else return Broj(1,2, JMBG); }
    
    int DajMjesecRodjenja() const { return Broj(3,2, JMBG); }
    int DajGodinuRodjenja() const {
        if(BrojCifara(JMBG==12)){
            int a(Broj(4,3,JMBG)); if(a<=17)a+=2000; else a+=1000; return a;
        }
        else{
        int a(Broj(5,3,JMBG)); if(Broj(5,3,JMBG)<=17) a+=2000; else a+=1000; return a; }
    }
    int DajSifruRegije() const {
        if(BrojCifara(JMBG)==12)
        return Broj(7,2, JMBG);
        else
        return Broj(8,2,JMBG);
        }
    Pol DajPol() const { 
        if(BrojCifara(JMBG)==12){
            if(Broj(9,3,JMBG)>=500) return Zensko; else return Musko;}
        else{
        if(Broj(10,3,JMBG)>=500) return Zensko; else return Musko;}
    }
    void PromijeniImeIPrezime(std::string novo_ime){ ime=novo_ime; }
};
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    p=pok; pok=this;
    if(BrojCifara(jmbg)==12){
        if(Broj(1, 1, jmbg<1) || Broj(2,2,jmbg)>12 || Broj(2,2,jmbg)<1 || Broj(4,3,jmbg)>999 || Broj(4,3,jmbg)<0 || Cifra(jmbg, 7)<0 || Cifra(jmbg,8)<0
        || Cifra(jmbg, 9)<0 || Cifra(jmbg,10)<0 || Cifra(jmbg,11)<0 || Cifra(jmbg,12)<0 || Cifra(jmbg,12)==10 || Cifra(jmbg,12)!=PoslednjaCifra(Cifra(jmbg,1),jmbg))
        throw std::logic_error("JMBG nije validan");
        JMBG=jmbg; ime=ime_i_prezime; }
    else if(BrojCifara(jmbg)==13){
        if(Broj(1,2,jmbg)>31 || Broj(1,2,jmbg)<1 || Broj(3,2,jmbg)>12 || Broj(3,2,jmbg)<1 || Broj(5,3,jmbg)>999 || Broj(5,3,jmbg)<0 ||
        Broj(8,1, jmbg)<0 || Broj(9,1,jmbg)<0 || Broj(10,1,jmbg)<0 || Broj(11,1,jmbg)<0 || Broj(12,1,jmbg)<0 || Broj(13,1, jmbg)<0 || Cifra(jmbg,13)==10
        || Cifra(jmbg,13)!=PoslednjaCifra(Broj(1,2,jmbg), jmbg)) throw std::logic_error("JMBG nije validan");
        JMBG=jmbg; ime=ime_i_prezime;
    }
    else throw std::logic_error("JMBG nije validan");
    }
GradjaninBiH*GradjaninBiH::p=nullptr;    
    

int main ()
{
	return 0;
}
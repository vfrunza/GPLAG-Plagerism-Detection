/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
class GradjaninBiH{
    enum Pol{Musko,Zensko};
    std::string ime_i_prezime;
    long long int jmbg;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int sifra_regije;
    Pol pol;
    GradjaninBiH *veza;
    static GradjaninBiH *zadnji;
    public:
    GradjaninBiH(std::string ime_i_prezime,long long int jmbg): ime_i_prezime(ime_i_prezime) {
        int dan, mjesec, godina, kontrolna;
    int c[13];
    int pom(jmbg);
   for(int i=0;i<12;i++){
       c[i]=pom%10;
       pom/=10;
   }
   kontrolna=11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[10])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11;
   if(kontrolna==11) kontrolna=0;
   if(kontrolna==10) throw std::logic_error("JMBG nije validan");
   if(c[12]!=kontrolna) throw std::logic_error("JMBG nije validan");
        jmbg/=1000000;
        int parcijalna;
        parcijalna=jmbg%1000;
        if(parcijalna>=917 || parcijalna<=999) godina=parcijalna+1000;
        if(parcijalna>=0 || parcijalna<=17) godina=parcijalna+2000;
        if(godina<1917 || godina>2017)  throw std::logic_error("JMBG nije validan");
        jmbg/=1000;
        mjesec=jmbg%100;
        if(mjesec<1 || mjesec>12)  throw std::logic_error("JMBG nije validan");
        jmbg/=100;
        dan=jmbg%100;
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
            if(dan < 1 || dan > broj_dana[mjesec-1])
                    throw std::logic_error("JMBG nije validan");
        GradjaninBiH::jmbg=jmbg;
        int kontrolna_cifra;
         kontrolna_cifra=jmbg%10;
        jmbg/=10;
        int koji_pol;
        koji_pol=jmbg%1000;
        if(koji_pol>=0 && koji_pol<=499) pol=Musko;
        else if(koji_pol>=500 && koji_pol<=990) pol=Zensko;
        jmbg/=1000;
        sifra_regije=jmbg%100;
        jmbg/=100;
        int parcijalna_godina;
        parcijalna_godina=jmbg%1000;
        if(parcijalna_godina>=917 || parcijalna_godina<=999) godina_rodjenja=parcijalna_godina+1000;
        else if(parcijalna_godina>=0 || parcijalna_godina<=17) godina_rodjenja=parcijalna_godina+2000;
        jmbg/=1000;
        mjesec_rodjenja=jmbg%100;
        jmbg/=100;
        dan_rodjenja=jmbg%100;
    }
    
    
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol){
          if(godina_rodjenja<1917 || godina_rodjenja>2017)  throw std::logic_error("Neispravni podaci");
           if(mjesec_rodjenja<1 || mjesec_rodjenja>12)  throw std::logic_error("Neispravni podaci");
            int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina_rodjenja % 4 == 0 && godina_rodjenja % 100 != 0) || godina_rodjenja % 400 == 0) broj_dana[1]++;
            if(dan_rodjenja < 1 || dan_rodjenja > broj_dana[mjesec_rodjenja - 1])
                    throw std::logic_error("Neispravni podaci");
        if(sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");
                 
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
        GradjaninBiH::dan_rodjenja=dan_rodjenja;
        GradjaninBiH::godina_rodjenja=godina_rodjenja;
        GradjaninBiH::pol=pol;
        GradjaninBiH::sifra_regije=sifra_regije;   
        
    }
   
   
    std::string DajImeIPrezime() const{return ime_i_prezime;}
    long long int DajJMBG() const{return jmbg;}
    int DajDanRodjenja() const{return dan_rodjenja;}
    int DajMjesecRodjenja() const{return mjesec_rodjenja;}
    int DajGodinuRodjenja() const{return godina_rodjenja;}
    int DajSifruRegije() const{return sifra_regije;}
    Pol DajPol()const{return pol;}
    void PromijeniImeIPrezime(std::string novo_ime){
        ime_i_prezime=novo_ime;
    }
    
    
};





int main ()
{
	return 0;
}
#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>


class GradjaninBiH{
    std::string ime_prezime;
    long long int jmbg;
    GradjaninBiH *prethodni;
  public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const {return ime_prezime;}
    long long int DajJMBG() const {return jmbg;}
    int DajDanRodjenja() const {return (int)jmbg/100000000000;}
    int DajMjesecRodjenja() const { int JMBG=jmbg%100000000000;  return (int) JMBG / 1000000000;}
    int DajGodinuRodjenja() const {
        int JMBG=jmbg%100000000000;
        JMBG=JMBG%1000000000;
        int god=JMBG/1000000;
        if((god - god%100)!=0) return god+1000;
        else return 2000+god;
    }
    int DajSifruRegije() const{
        int JMBG=jmbg%100000000000;
        JMBG=JMBG%1000000000;
        JMBG=JMBG%1000000;
        return (int) JMBG/10000;
    }
    Pol DajPol() const {return Pol;}
    void PromijeniImeIPrezime(std::string novo_ime);
};

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    GradjaninBiH::ime_prezime=ime_i_prezime; GradjaninBiH::jmbg=jmbg;
    long long int JMBG=jmbg;
    if(jmbg<1000000000000){
      int dan=jmbg%100000000000;
      .
      .
    }
    else{
     int dan=(int)JMBG /100000000000;
     JMBG=jmbg%100000000000;
     int mjesec=(int)JMBG/1000000000;
     JMBG=JMBG%1000000000;
     int godina=JMBG /1000000;
     int broj_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
     if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
     if(dan<1 || mjesec<1 || mjesec>12 || godina<1 || dan>broj_dana[mjesec-1]) throw std::logic_error ("JMBG nije validan");
     //zq 13. sve cifre trebaju -.-
    } 
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    GradjaninBiH::ime_prezime=ime_i_prezime;
    
    int broj_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
     if(godina_rodjenja % 4 == 0 && godina_rodjenja % 100 != 0 || godina_rodjenja % 400 == 0) broj_dana[1]++;
     if(dan_rodjenja<1 || mjesec_rodjenja<1 || mjesec_rodjenja>12 || godina_rodjenja<1 || dan_rodjenja>broj_dana[mjesec_rodjenja-1] || sifra_regije<0 || sifra_regije>99 || ) throw std::logic_error ("Neispravni podaci");
}

int main ()
{
    
	return 0;
}
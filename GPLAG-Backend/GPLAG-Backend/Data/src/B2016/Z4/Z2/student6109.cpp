/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <new>
#include <stdexcept>
#include <utility>
#include <algorithm>

class GradjaninBiH {
    std::string ime_i_prezime;
    int dan, mjesec, godina, Sifra;
    long long int JMBG;
    GradjaninBiH::Pol polovi;
public:    
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);
};

GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    ime_i_prezime = ime_i_prezime;
    int suma=0;
    
    jmbg/=10;
    for(long long int i=jmbg; i>0; i=i/10) suma++;
    
    int temp = jmbg%1000;
    if(temp >= 0 && temp < 500){
        polovi = Pol::Musko;
    } else if (temp >= 500 && temp < 1000 ){
        polovi = Pol::Zensko;
    }
    jmbg/=1000;
    
    Sifra = jmbg%100;
    jmbg/=100;
    
    godina = jmbg%1000;
    jmbg/=1000;
    
    mjesec = jmbg%100;
    jmbg/=100;
    
    if(suma == 12) {
        dan = jmbg%100;
    } else {
        dan = jmbg%10;
    }
    
}

GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    
    ime_i_prezime = ime_i_prezime;
    dan = dan_rodjenja;
    mjesec = mjesec_rodjenja;
    godina = godina_rodjenja;
    Sifra = sifra_regije;
    polovi1 = pol;
    polovi1=GradjaninBiH.polovi;
    if(dan<10) {
        c13== 11−(7*(dan+(godina%10))+6*((mjesec/10)+(Sifra/10))+5*((mjesec%10) + )+4∙ ( + )+3∙ ( + )+2∙ ( + ))%11
    } else {
         c13== 11−(7*((dan/10)+(godina%10))+6*((mjesec/10)+(Sifra/10))+5*( + )+4∙ ( + )+3∙ ( + )+2∙ ( + ))%11
    }

    
    
    jmbg= 1E+12*dan + 1E+11*mjesec + 1E+9*(godina%1000) + 1E+6*Sifra + 1E+4*1+ c13;
    
}

std::string DajImeIPrezime() const {
    return ime_i_prezime;
}

int GradjaninBiH::DajDanRodjenja() const{
    return dan;
}

int GradjaninBiH::DajMjesecRodjenja() const{
    return mjesec;
}

int GradjaninBiH::DajGodinuRodjenja() const{
    return godine;
}

int GradjaninBiH::DajSifruRegije() const{
    return Sifra;
}

long long int GradjaninBiH::DajJMBG() const{
    return JMBG;
}

void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime) {
    this->ime_i_prezime = novo_ime;
}

Pol GradjaninBiH::DajPol() const {
    return polovi;
}

int main () {
    
	return 0;
}
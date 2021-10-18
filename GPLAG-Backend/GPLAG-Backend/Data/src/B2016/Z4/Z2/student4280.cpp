/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept<

class GradjaninBiH {
    private:
    
    public::
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
                 int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);

}

DaLiSuIsti () {
    
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {//jmbg trebamo rastaviti na cifre
    int c13=11-(7*(c1+c7)+6*(c2+c8)+5*(c3+c9)+4*(c4+c10)+3*(c5+c11)+2*(c6+c12))%11;
    if(c13=11) c13=0;
    if(c13=10 || (c1<=0 && c1>3) || c2<0 || (c1>3 && c2>1) || c4<0 || c5!=0 ||c5!=9 || c6!=0 || c6!=9 || c9!=1 || c7<0 || c8<0 || c9<0 || c10<0 || c11<0 || c12<0)  {
                   throw std::logic_error("JMBG nije validan");
    }
    if(JMBG1=JMBG2) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
}
    
    
    
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {

if((dan_rodjenja<0 && dan_rodjenja>31) || (mjesec_rodjenja<0 && mjesec_rodjenja>12) || (mjesec_rodjenja = 2 && dan_rodjenja>29) || (godina_rodjenja<0 && godina_rodjenja>2017) ||
 (sifra_regije<0 || sifra_regije>99)) throw std::logic_error("Neispravni podaci");
}

GradjaninBiH::DajImeIPrezime() const {
    return;
}

GradjaninBiH::DajJMBG() const {
    return;
}

GradjaninBiH::DajDanRodjenja() const {
    return;
}

GradjaninBiH::DajMjesecRodjenja() const {
    return;
}

GradjaninBiH::DajGodinuRodjenja() const {
    return;
}

GradjaninBiH::DajSifruRegije() const {
    return;
}

Pol GradjaninBiH::DajSifruRegije() const {
    return;
}
int main ()
{
    return 0;
}
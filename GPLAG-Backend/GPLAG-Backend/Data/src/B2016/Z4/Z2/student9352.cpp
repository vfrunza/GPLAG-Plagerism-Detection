/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>

using namespace std;

class GradjaninBiH{
    string ime_i_prezime;
    long long int JMBG;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int sifra_regije;
    Pol pol;
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(string ime_i_prezime, long long int jmbg);
    GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(string novo_ime);
};
GradjaninBiH::GradjaninBiH(string ime_i_prezime, long long int jmbg)
{
    int dan{jmbg/pow(10,11)};
    int mjesec{(jmbg/pow(10,9))%100};
    int godina{((jmbg)/pow(10,6))%1000};
    int regija{(jmbg/1000)%100};
    if(dan>31 || dan<1 || mjesec<1 || mjesec>12 godina<916 || godina>017) throw logic_error("JMBG nije validan");
    GradjaninBiH::ime_i_prezime=ime_i_prezime;  JMBG=jmbg;  dan_rodjenja=dan; mjesec_rodjenja=mjesec;
    godina_rodjenja=godina; sifra_regije=regija; 
    int kod{(jmbg/10)%1000};
    if(kod<500 && kod>=0) pol=Musko;
    else pol=Zensko;
}
GradjaninBiH::GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol)
{
    if(dan_rodjenja>31 || dan_rodjenja<1 || mjesec_rodjenja>12 || mjesec_rodjenja<1 || godina_rodjenja<1916 || godina_rodjenja>2017) throw logic_error("Neispravan datum");
    int cifra{11-(7*(dan_rodjenja/10+godina_rodjenja%10)+6*(dan_rodjenja%10+sifra_regije/10)+5*(mjesec_rodjenja/10+sifra_regije%10)+4*(mjesec_rodjenja%10+  )+3*(godina_rodjenja/100+ )+2*((godina_rodjenja/10)%10+ ))%11};
    if(cifra==10) //biramo novi kod
    if(cifra==11) cifra=0;
    GradjaninBiH::ime_i_prezime=ime_i_prezime;  GradjaninBiH::dan_rodjenja=dan_rodjenja; GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;
    GradjaninBiH::godina_rodjenja=godina_rodjenja;  GradjaninBiH::sifra_regije=sifra_regije; GradjaninBiH::pol=pol;
    JMBG=dan_rodjenja*pow(10,11)+mjesec_rodjenja*pow(10,9)+godina_rodjenja*pow(10,6)+sifra_regije*(10,4)+    *10+cifra;
}

string GardjaninBiH::DajImeIPrezime() const{ return ime_i_prezime; }
long long int GradjaninBiH::DajJMBG() const{ return JMBG; }
int GradjaninBiH::DajDanRodjenja() const{ return dan_rodjenja; }
int GradjaninBiH::DajMjesecRodjenja() const{ return mjesec_rodjenja; }
int GradjaninBiH::DajGodinuRodjenja() const{ return godina_rodjenja; }
int GradjaninBiH::DajSifruRegije() const{ return sifra_regije; }
Pol GradjaninBiH::DajPol() const{ return pol; }
void GradjaninBiH::PromijeniImeIPrezime(string novo_ime){
    ime_i_prezime=novo_ime;
}





int main ()
{
	return 0;
}
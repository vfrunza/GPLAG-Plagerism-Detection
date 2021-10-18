/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
enum Pol{Musko,Zensko};
class GradjaninBiH {
    std::string ime_i_prezime;
    long long int jmbg;
    int dan_rodjenja;
    int godina_rodjenja;
    int mjesec_rodjenja;
    int sifra_regije;
    Pol pol;
    public:
    GradjaninBiH(std::string ime_i_prezime,long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol);
    std::string DajImeIPrezime() const { return ime_i_prezime; }
    long long int DajJMBG() const;
    int DajDanRodjenja() const { return dan_rodjenja; }
    int DajMjesecRodjenja() const { return mjesec_rodjenja; }
    int DajGodinuRodjenja() const { return godina_rodjenja; }
    int DajSifruRegije() const { return sifra_regije; }
    Pol DajPol() const { return pol; }
    void PromijeniImeIPrezime(std::string novo_ime);
};
int main ()
{
	return 0;
}
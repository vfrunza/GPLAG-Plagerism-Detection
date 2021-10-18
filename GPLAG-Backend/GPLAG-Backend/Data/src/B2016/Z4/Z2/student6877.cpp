/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>

class GradjaninBiH{
    std::string ime_i_prezime;
    long long int jmbg;
    public:
    enum Pol{Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
        GradjaninBiH::jmbg=jmbg;
    }
    GradjaninBiH(std::String ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImePrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromjeniImePrezime(std::string novo_ime);
};
int main ()
{
	return 0;
}
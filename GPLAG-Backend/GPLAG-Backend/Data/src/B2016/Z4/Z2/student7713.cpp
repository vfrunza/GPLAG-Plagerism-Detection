/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>

using namespace std;

class GradjaninBiH{
    string ime_i_prezime;
    long long int jmbg;
    int dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije;
    enum Pol{Musko,Zensko};
    public:
    GradjaninBiH(string ime_i_prezime,long long int jmbg);
    GradjaninBiH(string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol);
    string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(string novo_ime);
};

int main ()
{
	return 0;
}
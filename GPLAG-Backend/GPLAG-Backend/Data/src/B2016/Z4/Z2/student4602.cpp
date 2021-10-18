/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
using namespace std;

class GradjaninBiH{
    long long int jmbg;
    string ime_i_prezime;
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
        ime_i_prezime=ime_i_prezime;
        if(jmbg)
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const {return ime_i_prezime; }
    long long int DajJMBG() const { return jmbg; }
    int DajDanRodjenja() const { return jmbg/100000000000; }
    int DajMjesecRodjenja() const {
        int pom=jmbg-DajDanRodjenja()*100000000000;
        return pom/1000000000;
    }
    int DajGodinuRodjenja() const {
        long long int pom=jmbg-DajDanRodjenja()*100000000000;
        int a=DajMjesecRodjenja()*1000000000;
        return (pom-a)/1000000;
    }
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);
}


int main ()
{
	return 0;
}
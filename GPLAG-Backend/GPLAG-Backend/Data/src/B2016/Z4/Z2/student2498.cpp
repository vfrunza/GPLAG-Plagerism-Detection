/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

enum Pol{Musko, Zensko};

class GradjaninBiH {
    
    std::string ime_i_prezime;
    long long int jmbg;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int sifra_regije;
    Pol pol;
    
    public:
    
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) : ime_i_prezime(ime_i_prezime), jmbg(jmbg) {
        
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) : 
        ime_i_prezime(ime_i_prezime), dan_rodjenja(dan_rodjenja), mjesec_rodjenja(mjesec_rodjenja), godina_rodjenja(godina_rodjenja), sifra_regije(sifra_regije), pol(pol) {
            
    }
    std::string DajImeIPrezime() const {
        return ime_i_prezime;
    }
    long long int DajJMBG() const {
        return jmbg;
    }
    int DajDanRodjenja() const {
        return dan_rodjenja;
    }
    int DajMjesecRodjenja() const {
        return mjesec_rodjenja;
    }
    int DajGodinuRodjenja() const {
        return godina_rodjenja;
    }
    int DajSifruRegije() const {
        return sifra_regije;
    }
    Pol DajPol() const {
        return pol;
    }
    void PromijeniImeIPrezime(std::string novo_ime) {
        ime_i_prezime = novo_ime;
    }
    
};
int main ()
{
	return 0;
}
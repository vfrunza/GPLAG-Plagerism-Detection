#include <iostream>
#include <algorithm>

class GradjaninBiH {
    int jmbg[13];
    std::string ime_i_prezime;
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
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    int cifra;
    for(int i(0); i < 13; i++){
        cifra = jmbg % 10;
        jmbg /= 10;
        GradjaninBiH::jmbg[i] = cifra;
    }
    std::reverse(GradjaninBiH::jbmg, GradjaninBiH::jbg + 13);
}

    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    
}
int main ()
{
	return 0;
}
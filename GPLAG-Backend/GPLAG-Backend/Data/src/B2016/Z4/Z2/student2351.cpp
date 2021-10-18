/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>

class GradjaninBiH {
    int jmbg;
    char ime_i_prezime[50];
    GradjaninBiH (const char imeprezime[], int jmbg) : 
    
    enum Pol {Musko,Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime () const ;
    long long int DajJMBG () const;
    int DajDanRodjenja () const;
    int DajMjesecRodjenja () const;
    int DajGodinuRodjenja () const;
    int DajSifruRegije () const;
    Pol DajPol () const;
    void PromijeniImeIPrezime(std::string novo_ime);
};

int main ()
{
    
	return 0;
}
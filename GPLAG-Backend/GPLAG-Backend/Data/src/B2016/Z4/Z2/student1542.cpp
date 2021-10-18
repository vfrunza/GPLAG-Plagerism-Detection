#include <iostream>
class GradjaninBiH {
    enum Pol{Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime,int datum_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol);
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDatumRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol Daj_Pol() const;
    void PromijeniImeIPrezime(std::strign novo_ime);
    
};
int main ()
{
    
	return 0;
}
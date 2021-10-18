/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>

class GradjaninBiH{
    std::string imeiprezime;
    long long int jmbg;
    mutable broj=0;
    if (broj==0) GradjaninBiH *p(nullptr);
    else GradjaninBiH *p()
    
    
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
        
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
        jmbg+=dan_rodjenja*100;
        jmbg+=mjesec_rodjenja;
        jmbg*=1000;
        if (godina_rodjenja<2000)jmbg+=1000-godina_rodjenja;
        else jmbg+=2000-godina_rodjenja;
        jmbg*=100;
        jmbg+=sifra_regije;
        jmbg*=1000;
        if (Pol==musko) jmbg+=;
        else jmbg+=;
        
        
    }
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);
};


int main ()
{
	return 0;
}
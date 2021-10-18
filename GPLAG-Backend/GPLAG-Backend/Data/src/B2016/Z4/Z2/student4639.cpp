/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>

class GradjaninBiH{
    
    std::string ime_i_prezime;
    GradjaninBiH veza;
    long long int jmbg;
   
    
    public:
    enum Pol{musko,zensko};
    GradjaninBiH (std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH (std::string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol);
    
    std::string DajImeIPrezime()const;
    long long int DajJMBG()const;
    int DajDanRodjenja()const;
    int DajMjesecRodjenja()const;
    int DajGodinuRodjenja()const;
    int DajSifruRegije()const;
    Pol DajPol()const;
    
    void PromijeniImeIPrezime(std::string novo_ime);
    void Ispisi()const{
        std::cout<<GradjaninBiH::ime_i_prezime<<" | "<<GradjaninBiH::jmbg<<std::endl;
    }
};

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime,long long int jmbg){
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    GradjaninBiH::jmbg = jmbg;
}
int main ()
{
    
    GradjaninBiH g1 ("Mirela Dedic",1402996175023);
    g1.Ispisi();

	return 0;
}
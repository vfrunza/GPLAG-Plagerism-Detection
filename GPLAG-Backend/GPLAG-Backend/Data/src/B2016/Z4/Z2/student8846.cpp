/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cstring>
class GradjaninBiH{
    std::string i_i_p;
    long long int jmbg;
    int dan_rodjenja,mjesec_rodjenja,godina_rodjenja;
    public:
    enum Pol{Musko,Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
        std::strcpy(ime_i_prezime,i_i_p);
    }
    GradjaninBiH(std::string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije, Pol pol);
    std::string DajImeIPrezime()const{
        return i_i_p;
    }
    long long int DajJMBG()const{
        return jmbg;
    }
    int DajDanRodjenja()const{
        return dan_rodjenja;
    }
    int DajMjesecRodjenja()const{
        return mjesec_rodjenja;
    }
    int DajGodinuRodjenja()const{
        return godina_rodjenja;
    }
    int DajSifruRegije()const;
    Pol DajPol()const{
        
    }
    void PromijeniImeIPrezime(std::string novo_ime);
};
int main ()
{
	return 0;
}
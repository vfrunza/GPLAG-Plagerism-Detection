/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class GradjaninBiH{
    string ime_i_prezime1, novo_ime1;
    long long int jmbg1;
    int dan_rodjenja1, mjesec_rodjenja1,godina_rodjenja1,sifra_regije1;
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(string ime_i_prezime, long long int jmbg);
    GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(string novo_ime);
};
GradjaninBiH::GradjaninBiH(string ime_i_prezime,long long int jmbg){
    ime_i_prezime1=ime_i_prezime;
    jmbg1=jmbg;
}
GradjaninBiH::GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    ime_i_prezime1=ime_i_prezime;
    dan_rodjenja1=dan_rodjenja;
    mjesec_rodjenja1=mjesec_rodjenja;
    godina_rodjenja1=godina_rodjenja;
    sifra_regije1=sifra_regije;
    pol=pol;
}
string GradjaninBiH::DajImeIPrezime() const{
    return ime_i_prezime1;
}
long long int GradjaninBiH::DajJMBG() const{
    
}
int GradjaninBiH::DajDanRodjenja() const{
    
}
int GradjaninBiH::DajMjesecRodjenja() const{
    
}
int GradjaninBiH::DajGodinuRodjenja() const{
    
}
int GradjaninBiH::DajSifruRegije() const{
    
}
/* GradjaninBiH::DajPol() const{
    
}*/
void GradjaninBiH::PromijeniImeIPrezime(string novo_ime){
    
}
int main ()
{
	return 0;
}
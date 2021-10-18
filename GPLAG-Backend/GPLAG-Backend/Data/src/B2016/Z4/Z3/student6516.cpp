/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector>

class GradjaninBiH {
enum Pol {Musko, Zensko};
GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    int cifra;
    std::vector<int> v;
    
    for(int i=0;i<13;i++){
        cifra=jmbg%10;
        jmbg=jmbg/10;
    }
    for(int i=0;i<v.size;i++){
        v.push_back(cifra);
        
    }
    for(int i=0;i<)
    
}
GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
 int godina_rodjenja, int sifra_regije, Pol pol);
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
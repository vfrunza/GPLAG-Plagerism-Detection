/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<string>
using namespace std;
class GradjaninBiH{
    string ime_i_prezime;
    long long int jmbg;
public:
enum Pol {Musko, Zensko};
GradjaninBiH(std::string ime_i_prezime, long long int jmbg){}
GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
 int godina_rodjenja, int sifra_regije, Pol pol){}
std::string DajImeIPrezime() const{ return ime_i_prezime; }
long long int DajJMBG() const{ return jmbg; }
int DajDanRodjenja() const{ return jmbg/100000000000000; }
int DajMjesecRodjenja() const{ int privremeno = jmbg/1 000 000 00; }
int DajGodinuRodjenja() const{}
int DajSifruRegije() const{}
Pol DajPol() const{ if(jmbg%1000>499)return Zensko; else return Musko; }
void PromijeniImeIPrezime(std::string novo_ime){
    GradjaninBiH::ime_i_prezime = novo_ime;
}

};
int main ()
{
	return 0;
}
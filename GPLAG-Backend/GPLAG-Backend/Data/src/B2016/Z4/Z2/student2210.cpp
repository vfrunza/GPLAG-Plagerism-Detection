/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
class GradjaninBiH {
    string ime_i_prezime;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int sifra_regije;
    long long int jmbg;
    public:
    enum Pol{Musko,Zensko};
    GradjaninBiH(string ime_i_prezime,long long int jmbg);
    GradjaninBiH(string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol);
    string DajImeIPrezime() const{return ime_i_prezime;}
    long long int DajJMBG() const{return jmbg;}
    int DajDanRodjenja() const{return dan_rodjenja;}
    int DajMjesecRodjenja() const{return mjesec_rodjenja;}
    int DajGodinuRodjenja() const{return godina_rodjenja;}
    int DajSifruRegije() const{return sifra_regije;}
    Pol DajPol() const{return pol;}
    void PromijeniImeIPrezime(string novo_ime);
};
GradjaninBiH(string ime_i_prezime,long long int jmbg){
    int cifra;
    vector<int>v;
    while(jmbg!=0){
        cifra=jmbg%10;
        v.push_back(cifra);
        jmbg/=10;
    }
}
int main ()
{
	return 0;
}
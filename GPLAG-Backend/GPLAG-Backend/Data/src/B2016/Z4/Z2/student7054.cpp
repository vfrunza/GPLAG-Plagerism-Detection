/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>

enum Pol {Musko, Zensko};
class GradjaninBiH
{
    std::string imePrezime;
    long long int maticni;
    int dan, mjesec, godina, sifra, kod, kontrolna;
public:
GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    imePrezime=ime_i_prezime;
    int niz[13];
    long long int broj=jmbg;
    for(int i=13; i>0;i--){
        niz[i]=broj%10;
        broj/=10;
    }
    dan=niz[0]*10+niz[1];
    mjesec=niz[2]*10+niz[3];
    godina=1000+niz[4]*100+niz[5]*10+niz[6];
    sifra=niz[7]*10+niz[8];
    kod=niz[9]*100+niz[10]*10+niz[11];
    kontrolna=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+ 4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
    if(kontrolna==11) kontrolna=0;
    else if(kontrolna==10)
}
GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    
}
std::string DajImeIPrezime() const;
long long int DajJmbg () const;
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
/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <new>
#include <stdexcept>
#include <iomanip>
#include <string>
class GradjaninBiH
{
    // enum Poll {M, Z};
    // Poll pol;
    std::string iip;
    int dan, mjesec, godina, sifra;
    long long int jmbg;
    // Pol pol;
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() {
        return iip;
    }
    long long int DajJMBG() const {
        return jmbg;
    }
    int DajDanRodjenja () const {
        return dan;
    }
    int DajMjesecRodjenja() const {
        return mjesec;
    }
    int DajGodinuRodjenja() const {
        return godina;
    }
    int DajSifruRegije() const {
        return sifra;
    }
    // Pol DajPol() const { return pol; }
    void PromijeniImeIPrezime(std::string novo_ime) {
        iip=novo_ime;
    }

};

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg)
{
    iip=ime_i_prezime;
    GradjaninBiH::jmbg=jmbg;
    jmbg/=10;
    int n=jmbg%10;
    jmbg/=10;
    n+=((jmbg%10)*10);
    jmbg/=10;
    n+=((jmbg%10)*100);
    jmbg/=10;
    // if(n>=0 && n<=499) Pol=Musko;
    //  else Pol=Zensko;
    n=0;
    n=jmbg%10;
    jmbg/=10;
    n+=((jmbg%10)*10);
    jmbg/=10;
    sifra=n;
    n=0;
    n=jmbg%10;
    jmbg/=10;
    n+=((jmbg%10)*10);
    jmbg/=10;
    n+=((jmbg%10)*100);
    jmbg/=10;
    n+=1000;
    godina=n;
    n=0;
    n=jmbg%10;
    jmbg/=10;
    n+=((jmbg%10)*10);
    jmbg/=10;
    mjesec=n;
    n=0;
    n=jmbg%10;
    jmbg/=10;
    n+=((jmbg%10)*10);
    jmbg/=10;
    dan=n;
    n=0;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol)
{
    // izuzeci...
    long long int jmbg;
    iip=ime_i_prezime;
    dan=dan_rodjenja;
    mjesec=mjesec_rodjenja;
    godina=godina_rodjenja;
    sifra=sifra_regije;
// GradjaninBiH::pol=pol;
    int k=1;
    for(int i=0; i<12; i++) {
    // napraviti za jmbg
    }
GradjaninBiH::jmbg=jmbg;
    }

int main ()
{
    // long long int n=0910996130009;
    GradjaninBiH ja("Ajdin Zorlak", 910996130009);
    std::cout<<ja.DajDanRodjenja()<<" "<<ja.DajMjesecRodjenja()<<" "<<ja.DajGodinuRodjenja()<<" "<<ja.DajImeIPrezime()<<" "<<ja.DajJMBG();
    std::cout<<std::endl<<ja.DajSifruRegije();

    return 0;
}
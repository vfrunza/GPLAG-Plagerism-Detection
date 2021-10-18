/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<string>
#include<stdexcept>

using namespace std;

class GradjaninBiH
{
    enum Pol {Musko, Zensko};
    static GradjaninBiH* zadnji;
    GradjaninBiH* prije;
    string ime_i_prezime;
    static int ID;
    int kod_razlike;
    long long int jmbg;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int sifra_regije;
    Pol pol;
    bool Provjerijmbg(long long int jmbg);
public:

    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
                 int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    ~GradjaninBiH();
//implementirati funkcije
    void PromijeniImeIPrezime(std::string novo_ime);

};
int GradjaninBiH::ID=0;
GradjaninBiH* GradjaninBiH::zadnji=nullptr;
GradjaninBiH::GradjaninBiH(string ime_i_prezime, long long int _jmbg)
{
    if(zadnji!=nullptr) {
        prije=zadnji;
        if(Provjerijmbg(_jmbg)==true)
            throw domain_error;
        zadnji=this;
    } else {
        prije=nullptr;
        zadnji=this;
    }
    GradjaninBiH::ime_i_prezime=ime_i_prezime;
    GradjaninBiH::jmbg=_jmbg;
    int c13=_jmbg%10;
    _jmbg=_jmbg/10;
    int P=_jmbg%1000;
    if(P<500) GradjaninBiH::pol=Musko;
    else
        GradjaninBiH::pol=Zensko;
    _jmbg=_jmbg/1000;
    GradjaninBiH::sifra_regije=_jmbg%100;
    _jmbg=_jmbg/100;
    int godina=_jmbg%1000;
    if(godina>17)
        GradjaninBiH::godina_rodjenja=godina+1000;
    else
        GradjaninBiH::godina_rodjenja=godina+2000;
    _jmbg=_jmbg/1000;
    GradjaninBiH::mjesec_rodjenja=_jmbg%100;
    _jmbg=_jmbg/100;
    GradjaninBiH::dan_rodjenja=_jmbg%100;
    //if mjesec>12 ......
}
GradjaninBiH::GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
                           int godina_rodjenja, int sifra_regije, Pol pol)
{
    //c1,,,c13+jmbg ne dodjeljujem nista
    if(zadnji!=nullptr) {
        prije=zadnji;
        //if(Provjerijmbg())
        zadnji=this;
    } else {
        prije=nullptr;
        zadnji=this;
    }
    GradjaninBiH::ime_i_prezime=ime_i_prezime;
    GradjaninBiH::dan_rodjenja=dan_rodjenja;
    GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;
    GradjaninBiH::godina_rodjenja=godina_rodjenja;
    GradjaninBiH::sifra_regije=sifra_regije;
    GradjaninBiH::pol=pol;
    kod_razlike=++ID;
    int c2=dan_rodjenja%10;
    int c1=(dan_rodjenja/10);
    int c4=mjesec_rodjenja%10;
    int c3=mjesec_rodjenja/10;
    int c7=godina_rodjenja%10;
    godina_rodjenja=godina_rodjenja/10;
    int c6=godina_rodjenja%10;
    godina_rodjenja=godina_rodjenja/10;
    int c5=godina_rodjenja%10;
    int c9=sifra_regije%10;
    int c8=sifra_regije/10;
    int c10,c11,c12;
    int count=kod_razlike;
    if(count<10) {
        c10=0;
        c11=0;
        c12=count;
    } else if(count<100) {
        int c=count;
        c10=0;
        c12=c%10;
        c11=c/10;

    } else {
        int c=count;
        c12=c%10;
        c=c/10;
        c11=c%10;
        c10=c/10;

    }
    int c13=11-(7*(c1+c7)+6*(c2+c8)+5*(c3+c9)+4*(c4+c10)+3*(c5+c11)+2*(c6+c12))%11;//sastavijmbg
    //izuzeci

}
GradjaninBiH::~GradjaninBiH()
{
    GradjaninBiH* pomocni=nullptr;
    if(zadnji==this) {
        zadnji=this->prije;
        return ;
    } else {
        for(GradjaninBiH* pok; pok!=nullptr; pok=pok->prije) {
            if(this==pok->prije) {
                pomocni=pok;
                break;
            }
        }
        pomocni->prije=pomocni->prije->prije;
    }
}
bool GradjaninBiH::Provjerijmbg(long long int jmbg)
{
    if(zadnji!=nullptr) {
        for(auto pok=zadnji; pok!=nullptr; pok = pok->prije) {
            if(pok==this) continue;
            if(pok->jmbg==this->jmbg) return true;;
        }
    }
    return false;
}



int main ()
{

    return 0;
}
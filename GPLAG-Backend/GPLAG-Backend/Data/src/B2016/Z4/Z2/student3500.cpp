#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

enum Pol {Musko, Zensko};
std::vector<long long int*> Log;

bool lookfor(std::vector<long long int*> V, long long int B){
    if(V.size()==0) return false;
    for(int i(0);i<V.size();i++){
        if(*V[i]==B) return true;
    }
    return false;
}

int Indeks(std::vector<long long int*> V, long long int L){
    for(int i(0);i<V.size();i++){
        if(*V[i]==L) return i;
    }
}

class GradjaninBiH{
    Pol pol;
    std::string ime_i_prezime;
    long long int JMBG
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije;
public:
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);

};

std::string GradjaninBiH::DajImeIPrezime(){
    return this->ime_i_prezime;
}

long long int GradjaninBiH::DajJMBG() {
    return this->JMBG;
}
int GradjaninBiH::DajDanRodjenja(){
    return this->dan_rodjenja;
}
int GradjaninBiH::DajMjesecRodjenja(){
    return this->mjesec_rodjenja;
}
int GradjaninBiH::DajGodinuRodjenja(){
    return this->godina_rodjenja;
}
int GradjaninBiH::DajSifruRegije(){
    return this->sifra_regije;
}
Pol GradjaninBiH::DajPol(){
    return this->pol;
}
void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime){
    this->ime_i_prezime=novo_ime;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    if(lookfor(V, jmbg)) throw std::logic_error;
    JMBG=jmbg;
    long long int help(jmbg);
    dan_rodjenja=help/100000000000;
    help/=100;
    mjesec_rodjenja=help/1000000000;
    help/=100;
    godina_rodjenja=help/1000000;
    if(godina_rodjenja<=17) godina_rodjenja+=2000;
    else godina_rodjenja+=1000;
    help/=1000;
    sifra_regije=help/10000;
    
    
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    if((sifra_regije>99)||(sifra_regije<0)) throw std::logic_error("Neispravni podaci");
    if(greskadatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja)) throw std::logic_error("Neispravni podaci");
    long long int jmbg;
    jmbg=
}
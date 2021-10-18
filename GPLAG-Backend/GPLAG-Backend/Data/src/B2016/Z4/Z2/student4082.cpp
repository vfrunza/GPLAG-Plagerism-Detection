/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <deque>

class GradjaninBiH {
    std::string ime_prezime;
    long long int JMBG;
    
    static int male;
    static int female;
    
    std::vector<int> dajVektor(long long int jmbg){
        std::vector<int> vek_jmbg;
        while(jmbg != 0){
            vek_jmbg.push_back(jmbg%10);
            jmbg/=10;
        }
        return vek_jmbg;
    }
    
    bool ispravnost_jmbg( std::vector<int> vek){
        int day(vek[0]*10 + vek[1]), month(vek[2]*10 + vek[3]);
        int zadnja;
        zadnja = 11-(7*(vek[0]+vek[6])+ 6*(vek[1]+vek[7])+ 5*(vek[2]+vek[8])+ 4*(vek[3]+vek[9])+ 3*(vek[4]+vek[10])+ 2*(vek[5]+vek[11]))%11;
        if(zadnja == 11) zadnja = 0;
        if(zadnja == 10) return 0;
        if(zadnja != vek[12]) return 0;
        if(day > 31) return 0;
        if(month > 12) return 0;
        return 1;
    }
    
    GradjaninBiH *prethodni;
    static GradjaninBiH *zadnji;
    
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    ~GradjaninBiH();
    std::string DajImeIPrezime() const{ return ime_prezime; }
    long long int DajJMBG() const{ return JMBG; }
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime){ ime_prezime=novo_ime; }
};

GradjaninBiH* GradjaninBiH::zadnji(nullptr);
int GradjaninBiH::male(0);
int GradjaninBiH::female(500);


GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    // provjera za ispravnost jmbg logic_error
    // provjera dal postoji od ranije isti jmbg logic_error
    
    if(ispravnost_jmbg(dajVektor(jmbg)) == 0) throw std::logic_error("JMBG nije validan");
    
    ime_prezime = ime_i_prezime;
    JMBG = jmbg;
    
    if(zadnji == nullptr){
        prethodni = nullptr;
        zadnji = this;
    }
    else{
        prethodni = zadnji;
        zadnji = this;
    }
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    long long int jmbg(0);
    // racunanje jmbg(provjera ispravnosti datuma), ispravnosti
    // provjera dal postoji od ranije isti jmbg logic_error
    ime_prezime = ime_i_prezime;
    JMBG = jmbg;
    
     if(zadnji == nullptr){
        prethodni = nullptr;
        zadnji = this;
    }
    else{
        prethodni = zadnji;
        zadnji = this;
    }
}

GradjaninBiH::~GradjaninBiH(){}

int main ()
{
    
    
    
    
	return 0;
}
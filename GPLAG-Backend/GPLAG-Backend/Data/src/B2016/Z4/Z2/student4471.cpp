/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!

#include <iostream>
#include <string>
using std::string;

struct Datum{
    int dan,mjesec,godina;
};

class GradjaninBiH{
    private:
    string ime_i_prezime;
    int JMBG[13];
    Datum datum;
    int sifra;
    int pol;
    static bool ValidirajJMBG(long long int jmbg);
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);
        
};

GradjaninBiH::GradjaninBiH(std::string ime_prez, long long int jmbg){
    ime_i_prezime = ime_prez;
    bool validan = ValidirajJMBG(jmbg);
}

bool GradjaninBiH::ValidirajJMBG(long long int jmbg){ //ako je negativan !
    int i = 0;
    int niz2[13];
    long long int copy = jmbg;
    while(jmbg != 0){
        niz2[i] = jmbg%10;
        jmbg/=10;
        i++;
    }
    jmbg = copy;
    if(jmbg<0 || i<11)return false;
    
    int niz[13];
    for(int j=0;j<13;j++){
        niz[j]=niz2[i-j];
    }
    
    int dan = niz[0]*10+niz[1];
    int mjesec = niz[2]*10 + niz[3];
    int godina
    
}


int main ()
{
	return 0;
}
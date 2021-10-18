/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>

class GradjaninBiH {
    private:
    std::string ime_i_prezime;
    long long int jmbg;
    //int dan, mjesec, godina;
    GradjaninBiH *prethodni;
    static GradjaninBiH *posljednji;
    
    public:
    enum Pol {Musko, Zensko} pol;
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
    ~GradjaninBiH();
};

    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
        this->ime_i_prezime=ime_i_prezime;
        this->jmbg=jmbg;
        if(posljednji==nullptr) prethodni=nullptr;
        else 
            prethodni=posljednji;
            posljednji=this;
    }
    GradjaninBiH *GradjaninBiH::posljednji=nullptr;
    
    GradjaninBiH::~GradjaninBiH() {
        if(this==posljednji) {
            if(prethodni==nullptr) {
                posljednji=nullptr;
            }
            posljednji=prethodni;
            prethodni=nullptr;
        }
    }
    
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
        this->ime_i_prezime=ime_i_prezime;
    }

    
    long long int DajJMBG() const {
        return jmbg;
    }
    
    int DajDanRodjenja() const {
        int dan()
        return ;
    }
    int DajMjesecRodjenja() const {
        
        return ;
    }
    int DajGodinuRodjenja() const {
        
        return ;
    }
    int DajSifruRegije() const {
        
        return ;
    }
    Pol DajPol() const {
        
        return pol;
    }
    


int main ()
{
	return 0;
}
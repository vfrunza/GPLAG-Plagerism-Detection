#include <iostream>
#include <string>
#include <stdexcept>

enum Pol {Musko, Zensko};

class GradjaninBiH {
    std::string name_surname;
    long long int jmb;
    Pol sex;
    GradjaninBiH *previous = nullptr;
    static GradjaninBiH *last_created; //=nullptr
    static int *Make (long long int jmbg) {
        int JMBG[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int i(0);
        while (jmbg!=0) {
            JMBG[12 - i] = jmbg%10;
            jmbg/=10;
            i++;
        }
        return JMBG;
    }
    static bool ValidirajDatum(int *jmbg) {
        
    } 
public:
    GradjaninBiH (std::string ime_i_prezime, long long int jmbg) {
        
    }
    GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
        
    }
    ~GradjaninBiH() {
        
    }

    std::string DajImeIPrezime() const {return name_surname;}
    long long int DajJMBG() const {return jmb;}
    int DajDanRodjenja() const {
        auto x = Make(DajJMBG());
        return x[0]*10 + x[1];
    }
    int DajMjesecRodjenja() const {
        auto x = Make(DajJMBG());
        return x[2]*10 + x[3];
    }
    int DajGodinuRodjenja() const {
        auto x = Make(DajJMBG());
        int year = x[4]*100 + x[5]*10 + x[6];
        if (year<=17) year+=2000;
        else year+=1000;
        return year;
    }
    int DajSifruRegije() const {
        auto x = Make(DajJMBG());
        return x[7]*10 + x[8];
    }
    Pol DajPol() const {return sex;}
    void PromijeniImeIPrezime (std::string novo_ime) {name_surname = novo_ime;}
};

int main () {
	return 0;
}
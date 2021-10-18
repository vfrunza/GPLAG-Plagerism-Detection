/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>

class GradjaninBiH
{
    std::string ime_i_prezime;
    int jmbg[13];
    GradjaninBiH* prethodi = nullptr;

    static void Test_datum (int dan,int mjesec, int godina) {
        int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina % 4 == 0 and godina % 100 != 0) or godina % 400 == 0) broj_dana[1]++;
        if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1|| dan > broj_dana[mjesec - 1])
            throw std::domain_error("Neispravan datum!");
    }
    static bool uporedi_jmbg (int niz1[],int niz2[]) {
        for (int i = 0; i < 13; i++) {
            if (niz1[i] != niz2[i]) return false;
        }
        return true;
    }
    static bool Test_jmbg (int niz[]) {
        auto pomocni(posljednji);
        while (1) {
            if(pomocni == nullptr) break;
            if (uporedi_jmbg(niz,pomocni->jmbg)) return true;
            if (pomocni->prethodi == nullptr) break;
            pomocni = pomocni->prethodi;
        }
        return false;
    }
public:
    static GradjaninBiH* posljednji;
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) : ime_i_prezime(ime_i_prezime) {
        int c[13];
        for (int i = 12; i >= 0; i--) {
            c[i] = jmbg%10;
            jmbg /= 10;
        }
        int dan = c[0]*10 + c[1];
        int mjesec = c[2]*10 + c[3];
        int godina;
        if (c[4] == 0) {
            if (c[5]*10+c[6] > 17) throw std::logic_error ("JMBG nije validan");
            else godina = 2000 + c[5]*10+c[6];
        } else if (c[4] == 9) {
            if (c[5]*10+c[6] < 17) throw std::logic_error ("JMBG nije validan");
            else godina = 1900 + c[5]*10+c[6];
        } else throw std::logic_error ("JMBG nije validan");
        try {
            Test_datum(dan,mjesec,godina);
        } catch (...) {
            throw std::logic_error ("JMBG nije validan");
        }
        int zad (11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11);
        if (zad == 11) zad = 0;
        if (zad == 10 or zad != c[12]) throw std::logic_error ("JMBG nije validan");
        if (Test_jmbg(c)) throw std::logic_error ("JMBG nije validan");
        for (int i = 0; i < 13; i++) {
            GradjaninBiH::jmbg[i] = c[i];
        }
        if (posljednji != nullptr) {
            prethodi = posljednji;
        }
        posljednji = this;
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) : ime_i_prezime(ime_i_prezime) {
        try {
            Test_datum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja);
        } catch (...) {
            throw std::logic_error ("1 Neispravni podaci");
        }
        if (sifra_regije < 0 or sifra_regije > 99) throw std::logic_error ("2 Neispravni podaci");
        int c[13];
        c[1] = dan_rodjenja%10;
        dan_rodjenja /=10;
        c[0] = dan_rodjenja%10;
        c[3] = mjesec_rodjenja %10;
        mjesec_rodjenja /= 10;
        c[2] = mjesec_rodjenja%10;
        c[6] = godina_rodjenja%10;
        godina_rodjenja /= 10;
        c[5] = godina_rodjenja%10;
        godina_rodjenja /= 10;
        c[4] = godina_rodjenja%10;
        c[8] = sifra_regije%10;
        sifra_regije /= 10;
        c[7] = sifra_regije%10;
        if (pol == GradjaninBiH::Musko) {
            c[9] = c[10] = c[11] = 0;
        } else  {
            c[9] = 5;
            c[10] = 0;
            c[11] = 0;
        }
        int zad (11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11);
        if (zad == 11) zad = 0;
        c[12] = zad;
        while (c[12] == 10 or Test_jmbg(c)) {
            if (c[11] == 9) {
                c[11] = 0;
                if (c[10] == 9) {
                    c[10] = 0;
                    if (c[9] == 9) throw std::logic_error ("3 Neispravni podaci");
                    else c[9]++;
                } else c[10]++;
            } else c[11]++;
            zad = 11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11;
            if (zad == 11) zad = 0;
            c[12] = zad;
        }
        for (int i = 0; i < 13; i++) {
            GradjaninBiH::jmbg[i] = c[i];
        }
        if (posljednji != nullptr) {
            prethodi = posljednji;
        }
        posljednji = this;
    }
    ~GradjaninBiH() {
        auto pomocni(posljednji);
        if (posljednji == this) {
            posljednji = this->prethodi;
        } else {

            while (true) {
                if(pomocni->prethodi == this) break;
                pomocni = pomocni->prethodi;
            }
            pomocni->prethodi = this->prethodi;
        }
    }
    std::string DajImeIPrezime() const {
        return ime_i_prezime;
    }
    long long int DajJMBG() const {
        long long int suma(0);
        for (int i = 0; i < 13; i++) {
            suma = suma*10 + jmbg[i];
        }
        return suma;
    }
    int DajDanRodjenja() const {
        return jmbg[0]*10+jmbg[1];
    }
    int DajMjesecRodjenja() const {
        return jmbg[2]*10+jmbg[3];
    }
    int DajGodinuRodjenja() const {
        if (jmbg[4] == 9) return 1900 +jmbg[5]*10+jmbg[6];
        else return 2000 + jmbg[5]*10 + jmbg[6];
    }
    int DajSifruRegije() const {
        return jmbg[7]*10 + jmbg[8];
    }
    Pol DajPol() const {
        if (jmbg[9] < 5) return Musko;
        return Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime) {
        ime_i_prezime = novo_ime;
    }
};
GradjaninBiH* GradjaninBiH::posljednji = nullptr;
int main ()
{
    std::string ime = "Gile Sampion";
           GradjaninBiH g(ime, 1212992170000);
           std::cout << g.DajDanRodjenja() <<"/"<<g.DajMjesecRodjenja() <<"/" <<g.DajGodinuRodjenja()<<std::endl;
           std::cout <<  g.DajSifruRegije()<< std::endl; 
           std::cout << g.DajPol() << std::endl;
    return 0;
}
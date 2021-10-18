/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>

class  GradjaninBiH {
private:
    std::string imeIPrezime;
    int jedinstveniMaticniBroj[13];
    static GradjaninBiH * ptrZadnjiGradjanin;
    GradjaninBiH * ptrPrethodniGradjanin;
    static bool DaLiJeJmbgIdentican(const GradjaninBiH & gradjanin1, const GradjaninBiH & gradjanin2);
    void DaLiSeJmbgPonavlja() const;
    void DaLiJeJmbgUredu() const;
    int KontrolnaCifra() const;

public:
    enum Pol {Musko, Zensko};
    explicit GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    explicit GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
                          int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const {
        return imeIPrezime;
    }
    long long int DajJMBG() const {
        long long int jmbg(0), dec(1);
        for(int i = 12; i >= 0; i--) {
            jmbg += jedinstveniMaticniBroj[i] * dec;
            dec *= 10;
        }
        return jmbg;
    }
    int DajDanRodjenja() const {
        return jedinstveniMaticniBroj[0] * 10 + jedinstveniMaticniBroj[1];
    }
    int DajMjesecRodjenja() const {
        return jedinstveniMaticniBroj[2] * 10 + jedinstveniMaticniBroj[3];
    }
    int DajGodinuRodjenja() const {
        int god;
        god = jedinstveniMaticniBroj[4]*100 + jedinstveniMaticniBroj[5]*10 + jedinstveniMaticniBroj[6];
        if(god < 17) god += 2000;
        else god += 1000;
        return god;
    }
    int DajSifruRegije() const {
        return jedinstveniMaticniBroj[7] * 10 + jedinstveniMaticniBroj[8];
    }
    Pol DajPol() const {
        if(jedinstveniMaticniBroj[9] < 5) return Pol::Musko;
        return Pol::Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime) {
        imeIPrezime = novo_ime;
    }
    ~GradjaninBiH();
};
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
    imeIPrezime = ime_i_prezime;
    for(int i = 12; i >= 0; i--) {
        jedinstveniMaticniBroj[i] = jmbg%10;
        jmbg /= 10;
    }
//Provjera da li je jmbg uredu
    DaLiJeJmbgUredu();
//ptrPrethodniGradjanin ne postoji
//ptrZadnjiGradjanin je zapravo prethodni
    ptrPrethodniGradjanin = ptrZadnjiGradjanin;
    ptrZadnjiGradjanin = this;
}
GradjaninBiH * GradjaninBiH::ptrZadnjiGradjanin = nullptr;
bool GradjaninBiH::DaLiJeJmbgIdentican (const GradjaninBiH & gradjanin1, const GradjaninBiH & gradjanin2) {
    for(int i = 0; i < 13; i++) {
        if(gradjanin1.jedinstveniMaticniBroj[i] != gradjanin2.jedinstveniMaticniBroj[i])
            return false;
    }
    return true;
}
void GradjaninBiH::DaLiSeJmbgPonavlja() const {
    //
    //TODO: testirati ovaj kod kad ostalo bude spremno
    //
    //pomPtr ne pocinje kao this, ali provjerit cu za svaki slucaj
    GradjaninBiH * pomPtr(ptrZadnjiGradjanin);
    if(pomPtr == nullptr) return;
    while(pomPtr->ptrPrethodniGradjanin != nullptr) {
        if(pomPtr == this) pomPtr = pomPtr->ptrPrethodniGradjanin;
        if(DaLiJeJmbgIdentican(*this, *pomPtr)) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        pomPtr = pomPtr->ptrPrethodniGradjanin;
    }
}
void GradjaninBiH::DaLiJeJmbgUredu() const {
    int dan(jedinstveniMaticniBroj[0]*10 + jedinstveniMaticniBroj[1]), mjesec(jedinstveniMaticniBroj[2]*10 + jedinstveniMaticniBroj[3]);
    int godina(jedinstveniMaticniBroj[4]*100 + jedinstveniMaticniBroj[5]*10 + jedinstveniMaticniBroj[6]);
//provjera datuma
//iako nemamo 4. cifru, to ne smeta da odredimo da li je godina bila prestupna
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1]) throw std::logic_error("JMBG nije validan");
//provjera kontrolne cifre
    if(jedinstveniMaticniBroj[12] != KontrolnaCifra()) throw std::logic_error("JMBG nije validan");
//provjera da li vec postoji osoba s istim jmbg
    DaLiSeJmbgPonavlja(); //baca izuzetak ako se ponavlja

}
int GradjaninBiH::KontrolnaCifra() const {
    int cifra(0);
    for(int i = 0; i < 6; i++) {
        cifra += (7-i) * (jedinstveniMaticniBroj[i] + jedinstveniMaticniBroj[i+6]);
    }
    cifra = 11 - cifra%11;
    if(cifra == 11) cifra = 0;
    if(cifra == 10) throw std::logic_error("JMBG nije validan");
    return cifra;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina_rodjenja % 4 == 0 && godina_rodjenja % 100 != 0 || godina_rodjenja % 400 == 0) broj_dana[1]++;
    if(godina_rodjenja < 1 || dan_rodjenja < 1 || mjesec_rodjenja < 1 || mjesec_rodjenja > 12 || dan_rodjenja > broj_dana[mjesec_rodjenja - 1]) throw std::logic_error("Neispravni podaci");
    if(sifra_regije < 0 || sifra_regije > 99) throw std::logic_error("Neispravni podaci");
    if(godina_rodjenja > 999) godina_rodjenja = godina_rodjenja%1000;
    //podaci su sada u redu
    imeIPrezime = ime_i_prezime;
    //dan
    jedinstveniMaticniBroj[1] = dan_rodjenja%10;
    dan_rodjenja /= 10;
    jedinstveniMaticniBroj[0] = dan_rodjenja%10;
    //mjesec
    jedinstveniMaticniBroj[3] = mjesec_rodjenja%10;
    mjesec_rodjenja /= 10;
    jedinstveniMaticniBroj[2] = mjesec_rodjenja%10;
    //godina
    jedinstveniMaticniBroj[6] = godina_rodjenja%10;
    godina_rodjenja /= 10;
    jedinstveniMaticniBroj[5] = godina_rodjenja%10;
    godina_rodjenja /= 10;
    jedinstveniMaticniBroj[4] = godina_rodjenja%10;
    //regija
    jedinstveniMaticniBroj[8] = sifra_regije%10;
    sifra_regije /= 10;
    jedinstveniMaticniBroj[7] = sifra_regije%10;
    if(pol == Pol::Musko) {
        for(int i = 0; i < 500; i++) {
            try {
                int j(i);
                jedinstveniMaticniBroj[11] = j%10;
                j /= 10;
                jedinstveniMaticniBroj[10] = j%10;
                j /= 10;
                jedinstveniMaticniBroj[9] = j%10;
                //i kontrolna cifra
                jedinstveniMaticniBroj[12] = KontrolnaCifra();
                DaLiJeJmbgUredu();
                break;
            } catch(...) {
                continue;
            }
        }
    }
    if(pol == Pol::Zensko) {
        for(int i = 500; i < 1000; i++) {
            try {
                int j(i);
                jedinstveniMaticniBroj[11] = j%10;
                j /= 10;
                jedinstveniMaticniBroj[10] = j%10;
                j /= 10;
                jedinstveniMaticniBroj[9] = j%10;
                //i kontrolna cifra
                jedinstveniMaticniBroj[12] = KontrolnaCifra();
                DaLiJeJmbgUredu();
                break;
            } catch(...) {
                continue;
            }
        }
    }
//ptrPrethodniGradjanin ne postoji
//ptrZadnjiGradjanin je zapravo prethodni
    ptrPrethodniGradjanin = ptrZadnjiGradjanin;
    ptrZadnjiGradjanin = this;
}
GradjaninBiH::~GradjaninBiH() {
    GradjaninBiH * pom(ptrZadnjiGradjanin);
    if(ptrZadnjiGradjanin == this) {
        ptrZadnjiGradjanin = this->ptrPrethodniGradjanin;
        return;
    }
    while(pom->ptrPrethodniGradjanin != this) {
        pom = pom->ptrPrethodniGradjanin;
    }
    ptrZadnjiGradjanin = this->ptrPrethodniGradjanin;
}

void ispisiUnesenog (GradjaninBiH x) {
    std::cout << "Unijeli ste gradjanina " << x.DajImeIPrezime() << " rodjenog " << x.DajDanRodjenja() << "." << x.DajMjesecRodjenja() << "." << x.DajGodinuRodjenja() << " u regiji "<< x.DajSifruRegije() << ", ";
    if(x.DajPol() == GradjaninBiH::Pol::Musko) std::cout << "musko.\n";
    if(x.DajPol() == GradjaninBiH::Pol::Zensko) std::cout << "zensko.\n";
}
int main() {
    GradjaninBiH * niz[100];
    std::cout << "Koliko gradjana zelite unijeti po JMBG? \n";
    int brojGradjana;
    std::cin >> brojGradjana;
    int i;
    try {
        for(i = 0; i < brojGradjana; i++) {
            std::cout << "Unesite ime i prezime (u istom redu): \n";
            std::string ime_i_prezime;
            std::getline(std::cin, ime_i_prezime);
            std::cout << ime_i_prezime;
            std::cout << "Unesite JMBG: \n";
            long long int jmbg;
            std::cin >> jmbg;
            try {
                niz[i] = new GradjaninBiH(ime_i_prezime, jmbg);
            } catch (std::logic_error e) {
                std::cout << e.what() << "\n";
            }
            ispisiUnesenog(*niz[i]);
        }
    } catch(std::logic_error e) {
        std::cout << e.what();
    } catch(...) {
        std::cout << "Da ga jebes";
    }
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
    std::cin >> brojGradjana;
    for(int j = i; j < i + brojGradjana; j++) {
        std::cout << "Unesite ime i prezime (u istom redu): \n";
        std::string ime_i_prezime;
        std::getline(std::cin, ime_i_prezime);
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): \n";
        int dan, mjesec, godina;
        char blaa;
        std::cin >> dan >> blaa >> mjesec >> blaa >> godina;
        std::cout << "Unesite sifru regije: \n";
        int sifra_regije;
        std::cin >> sifra_regije;
        std::cout << "Unesite M za musko, Z za zensko: \n";
        std::cin >> blaa;
        try {
            if(blaa == 'M') niz[j] = new GradjaninBiH(ime_i_prezime, dan, mjesec, godina, sifra_regije, GradjaninBiH::Pol::Musko);
            if(blaa == 'Z') niz[j] = new GradjaninBiH(ime_i_prezime, dan, mjesec, godina, sifra_regije, GradjaninBiH::Pol::Zensko);
        } catch (std::logic_error e) {
            std::cout << e.what() << "\n";
        }
        std::cout << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " JMBG: " << niz[i]->DajJMBG() << ".\n";
    }
    for(int j = 0; j < i + brojGradjana; j++) {
        delete niz[j];
    }
}

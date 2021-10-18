/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

    
class GradjaninBiH {
    
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    ~GradjaninBiH();
    std::string DajImeIPrezime() const { return ime_i_prezime; }
    long long int DajJMBG() const { return jmbg; }
    int DajDanRodjenja() const { return dan_rodjenja; }
    int DajMjesecRodjenja() const { return mjesec_rodjenja; }
    int DajGodinuRodjenja() const { return godina_rodjenja; }
    int DajSifruRegije() const { return sifra_regije; }
    Pol DajPol() const { return spol; }
    void PromijeniImeIPrezime(std::string novo_ime) { ime_i_prezime = novo_ime; }
    
    private:
    GradjaninBiH::Pol spol;
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, kod_osobe;
    long long int jmbg;
    std::string ime_i_prezime;
    static GradjaninBiH *zadnji;
    GradjaninBiH *prethodni = nullptr;
};

    GradjaninBiH* GradjaninBiH::zadnji(nullptr);

GradjaninBiH::~GradjaninBiH() {
    if(prethodni == nullptr) {
        GradjaninBiH *p(zadnji);
        for(;;) {
            if(p->prethodni == nullptr) {
                p = nullptr;
                break;
            }
            p = p->prethodni;
        }
    }
    else if(zadnji == this) zadnji = prethodni;
    else {
        GradjaninBiH *p(zadnji);
        for(;;) {
            if(p->prethodni == this) {
                p->prethodni = this->prethodni;;
                break;
            }
        }
    }
}


GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
    prethodni = zadnji;
    zadnji = this;
    GradjaninBiH *p(prethodni);
    while(p != nullptr) {
        if(p->jmbg == jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        p = p->prethodni;
    }
    this->ime_i_prezime = ime_i_prezime;
    this->jmbg = jmbg;
    long long int pomocna(jmbg);
    int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13;
    long long int pomocna2(jmbg);
    int brojac(0);
    while(pomocna2 != 0) {
        pomocna2 /= 10;
        brojac++;
    }
    c13 = pomocna % 10;
    pomocna /= 10;
    c12 = pomocna % 10;
    pomocna /= 10;
    c11 = pomocna % 10;
    pomocna /= 10;
    c10 = pomocna % 10;
    pomocna /= 10;
    c9 = pomocna % 10;
    pomocna /= 10;
    c8 = pomocna % 10;
    pomocna /= 10;
    c7 = pomocna % 10;
    pomocna /= 10;
    c6 = pomocna % 10;
    pomocna /= 10;
    c5 = pomocna % 10;
    pomocna /= 10;
    c4 = pomocna % 10;
    pomocna /= 10;
    c3 = pomocna % 10;
    pomocna /= 10;
    if(brojac == 12) {
        c2 = pomocna;
        c1 = 0;
    }
    else {
    c2 = pomocna % 10;
    pomocna /= 10;
    c1 = pomocna;
    }
    
    // Dan
    if(c1 == 0) dan_rodjenja = c2;
    else dan_rodjenja = c1 * 10 + c2;
    if(dan_rodjenja == 0 || dan_rodjenja > 31) throw std::logic_error("JMBG nije validan");
    
    //Mjesec
    if(c3 == 0) mjesec_rodjenja = c4;
    else mjesec_rodjenja = c3 * 10 + c4;
    if(mjesec_rodjenja == 0 || mjesec_rodjenja > 12) throw std::logic_error("JMBG nije validan");
    
    // Godina
    if(c5 == 0) {
        if(c6 == 0) godina_rodjenja = 2000 + c7;
        else {
            if(c6 > 1) godina_rodjenja = 1000 + c6 * 10 + c7;
            else godina_rodjenja = 2000 + c6 * 10 + c7;
        }
    }
    else godina_rodjenja = 1000 + c5 * 100 + c6 * 10 + c7;
    if(godina_rodjenja == 0) throw std::logic_error("JMBG nije validan");
    
    // Sifra regije
    sifra_regije = c8 * 10 + c9;
    
    // Spol - Kod osobe
    kod_osobe = c10 * 100 + c11 * 10 + c12;
    if(kod_osobe < 500) spol = Pol::Musko;
    else spol = Pol::Zensko;
    
    int zadnja_cifra(11 - (7 * (c1 + c7) + 6 * (c2 + c8) + 5 *(c3 + c9) + 4 * (c4 + c10) + 3 * (c5 + c11) + 2 * (c6 + c12)) % 11);
    if(zadnja_cifra == 11) zadnja_cifra = 0;
    if(zadnja_cifra == 10) throw std::logic_error("JMBG nije validan");
    if(zadnja_cifra != c13) throw std::logic_error("JMBG nije validan");
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
    if(dan_rodjenja < 0 || dan_rodjenja > 31) throw std::logic_error("Neispravni podaci");
    if(mjesec_rodjenja < 0 || mjesec_rodjenja > 12) throw std::logic_error("Neispravni podaci");
    if(godina_rodjenja < 0 || godina_rodjenja > 2017) throw std::logic_error("Neispravni podaci");
    if(sifra_regije < 0 || sifra_regije > 99) throw std::logic_error("Neispravni podaci");
    prethodni = zadnji;
    zadnji = this;
    this->ime_i_prezime = ime_i_prezime;
    this->dan_rodjenja = dan_rodjenja;
    this->mjesec_rodjenja = mjesec_rodjenja;
    this->godina_rodjenja = godina_rodjenja;
    this->sifra_regije = sifra_regije;
    this->spol = pol;
    int c1(0), c2(0), c3(0), c4(0), c5(0), c6(0), c7(0), c8(0), c9(0), c10(0), c11(0), c12(0), c13(0), prvi_slbodan_kod;
    
    if(pol == GradjaninBiH::Pol::Musko) prvi_slbodan_kod = 0;
    else prvi_slbodan_kod = 500;
    bool vec_ima(false);
    for(;;) {
        GradjaninBiH *p(zadnji);
        while(p->prethodni != nullptr) {
            if(p->kod_osobe == prvi_slbodan_kod) {
                vec_ima = true;
                break;
            }
            p = p->prethodni;
        }
        if(vec_ima) prvi_slbodan_kod++;
        else break;
    }
    if(dan_rodjenja < 10) {
        c1 = 0;
        c2 = dan_rodjenja;
    }
    else {
    c1 = dan_rodjenja / 10;
    c2 = dan_rodjenja % 10;
    }
    c3 = mjesec_rodjenja / 10;
    c4 = mjesec_rodjenja % 10;
    if(godina_rodjenja >= 2000 && godina_rodjenja < 2010) {
        c5 = 0;
        c6 = 0;
        c7 = godina_rodjenja % 10;
    }
    else if(godina_rodjenja >= 2010) {
        c5 = 0;
        c6 = (godina_rodjenja % 100) / 10;
        c7 = godina_rodjenja % 10;
    }
    else if(godina_rodjenja >= 1917) {
        c5 = (godina_rodjenja - 1000) / 100;
        c6 = ((godina_rodjenja - 1000) % 100) / 10;
        c7 = godina_rodjenja % 10;
    }
    else {}
    c8 = sifra_regije / 10;
    c9 = sifra_regije % 10;
    if(prvi_slbodan_kod >= 0 && prvi_slbodan_kod < 10) {
        c10 = 0;
        c11 = 0;
        c12 = prvi_slbodan_kod;
    }
    else if(prvi_slbodan_kod >= 10 && prvi_slbodan_kod < 100) {
        c10 = 0;
        c11 = prvi_slbodan_kod / 10;
        c12 = prvi_slbodan_kod % 10;
    }
    else {
        c10 = prvi_slbodan_kod / 100;
        c11 = (prvi_slbodan_kod % 100) / 10;
        c12 = prvi_slbodan_kod % 10;
    }
    c13 = 11 - (7 * (c1 + c7) + 6 * (c2 + c8) + 5 *(c3 + c9) + 4 * (c4 + c10) + 3 * (c5 + c11) + 2 * (c6 + c12)) % 11;
    if(c13 == 11) c13 = 0;
    if(c13 == 10) throw std::logic_error("JMBG nije validan");
    jmbg = 1000000000000 * c1 + 100000000000 * c2 + 10000000000 * c3 + 1000000000 * c4 + 100000000 * c5 + 10000000 * c6 + 1000000 * c7 + 100000 * c8 + 10000 * c9 + 1000 * c10 + 100 * c11 + 10 * c12 + c13;
}


int main ()
{
    std::cout << "Koliko gradjana zelite unijeti po JMBG? \n";
    int n;
    std::cin >> n;
    GradjaninBiH *gradjani[100];
    for(int i(0); i < n; i++) {
        pocetak:
        std::cout << "Unesite ime i prezime (u istom redu): \n";
        std::string ime;
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, ime);
        std::cout << "Unesite JMBG: \n";
        long long int jmbg;
        std::cin >> jmbg;
        try {
            gradjani[i] = new GradjaninBiH(ime, jmbg);
            std::cout << "Unijeli ste gradjanina " << gradjani[i]->DajImeIPrezime() << " rodjenog " << gradjani[i]->DajDanRodjenja() << "." <<
            gradjani[i]->DajMjesecRodjenja() << "." << gradjani[i]->DajGodinuRodjenja() << " u regiji " << gradjani[i]->DajSifruRegije() << ", ";
            if(gradjani[i]->DajPol() == GradjaninBiH::Pol::Musko) std::cout << "musko.\n";
            else std::cout << "zensko.\n";

        }
        catch(std::logic_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            delete gradjani[i];
            //gradjani[i] = nullptr;
            goto pocetak;
        }
    }
    
    
    GradjaninBiH *gradjani2[100];
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
    std::cin >> n;
    for(int i(0); i < n; i++) {
        std::cout << "Unesite ime i prezime (u istom redu): \n";
        std::string ime;
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, ime);
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): \n";
        int dan, mjesec, godina;
        char c;
        std::cin >> dan >> c >> mjesec >> c >> godina;
        std::cout << "Unesite sifru regije: \n";
        int sifra;
        std::cin >> sifra;
        std::cout << "Unesite M za musko, Z za zensko: \n";
        std::cin >> c;
        GradjaninBiH::Pol spol;
        if(c == 'M') spol = GradjaninBiH::Pol::Musko;
        else spol = GradjaninBiH::Pol::Zensko;
        try {
            gradjani2[i] = new GradjaninBiH(ime, dan, mjesec, godina, sifra, spol);
            std::cout << "Unijeli ste gradjanina " << gradjani2[i]->DajImeIPrezime() << " JMBG: " << gradjani2[i]->DajJMBG() << "." << std::endl;
        }
        catch(std::logic_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
    }
    
	return 0;
}
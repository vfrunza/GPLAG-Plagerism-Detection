/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH {
    public:
    enum Pol {Musko, Zensko};
    
    private:
    std::string ime_i_prezime;
    long long int jmbg;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int sifra_regije;
    Pol pol;
    void ProvjeriJMBG(long long int jmbg);//
    int KontrolnaCifra(long long int jmbg);//
    static int DajCifru(long long int jmbg, int cifra);//
    int BrojCifara(long long int jmbg);//
    static void OcitajInformacije(long long int jmbg, int &dan_rodjenja, int &mjesec_rodjenja, int &godina_rodjenja, int &sifra_regije, Pol &pol);//
    static bool ProvjeriDatum(int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja);//
    GradjaninBiH *prethodni;
    static GradjaninBiH *posljednji;
    public:
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);//
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);//
    std::string DajImeIPrezime() const { return ime_i_prezime; }//
    long long int DajJMBG() const { return jmbg; }; //
    int DajDanRodjenja() const { return dan_rodjenja; } //
    int DajMjesecRodjenja() const { return mjesec_rodjenja; } //
    int DajGodinuRodjenja() const { return godina_rodjenja; } //
    int DajSifruRegije() const { return sifra_regije; } //
    Pol DajPol() const { return pol; } //
    void PromijeniImeIPrezime(std::string novo_ime) { ime_i_prezime = novo_ime; } //
    ~GradjaninBiH();
    GradjaninBiH(const GradjaninBiH &g) = delete;
    GradjaninBiH &operator =(const GradjaninBiH &g) = delete;
};
GradjaninBiH *GradjaninBiH::posljednji(nullptr);
GradjaninBiH::~GradjaninBiH() {
    if (posljednji == this) posljednji = prethodni, prethodni = nullptr;
    else if(this->prethodni) {
        auto pom = GradjaninBiH::posljednji;
        while (pom->prethodni != this) pom--;
        pom->prethodni = this->prethodni;
        this->prethodni = nullptr;
    }
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
    if (!ProvjeriDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja)) throw std::logic_error ("Neispravni podaci");
    if (sifra_regije < 0 || sifra_regije > 99) throw std::logic_error ("Neispravni podaci");
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    GradjaninBiH::dan_rodjenja = dan_rodjenja;
    GradjaninBiH::mjesec_rodjenja = mjesec_rodjenja;
    GradjaninBiH::godina_rodjenja = godina_rodjenja;
    GradjaninBiH::sifra_regije = sifra_regije;
    GradjaninBiH::pol = pol;
    auto pom(posljednji);
    int sifra(0);
    while (pom) {
        if (pom->DajDanRodjenja() == dan_rodjenja && pom->DajMjesecRodjenja() == mjesec_rodjenja && pom->DajGodinuRodjenja() == godina_rodjenja
        && pom->DajSifruRegije() == sifra_regije && pom->DajPol() == pol) sifra++;
        pom = pom->prethodni;
    }
    if (pol == Pol::Zensko) sifra += 500;
    int mat_broj[13] = {0};
    mat_broj[1] = dan_rodjenja%10; dan_rodjenja /= 10;
    mat_broj[0] = dan_rodjenja;
    mat_broj[3] = mjesec_rodjenja%10; mjesec_rodjenja /= 10;
    mat_broj[2] = mjesec_rodjenja;
    mat_broj[6] = godina_rodjenja%10; godina_rodjenja /= 10;
    
    mat_broj[5] = godina_rodjenja%10; godina_rodjenja /= 10;
    mat_broj[4] = godina_rodjenja%10;
    mat_broj[8] = sifra_regije%10; sifra_regije /= 10;
    mat_broj[7] = sifra_regije;
    mat_broj[11] = sifra%10; sifra /= 10;
    mat_broj[10] = sifra%10; sifra /= 10;
    mat_broj[9] = sifra%10;
    mat_broj[12] = 0;
    long long int jmbg_pom(0);
    for (int i = 0; i < 13; i++) jmbg_pom *= 10, jmbg_pom += mat_broj[i];
    auto kontrolni(GradjaninBiH::KontrolnaCifra(jmbg_pom));
    if (kontrolni == 11) kontrolni = 0;
    jmbg_pom += kontrolni;
    jmbg = jmbg_pom;
    prethodni = posljednji;
    posljednji = this;
};
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg)  {
    ProvjeriJMBG(jmbg);
    if (posljednji) {
        auto pom(GradjaninBiH::posljednji);
        while (pom) {
            if (pom->DajJMBG() == jmbg) throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
            pom = pom->prethodni;
        }
    }
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije;
    Pol pol;
    OcitajInformacije(jmbg, dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, pol);
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    GradjaninBiH::jmbg = jmbg;
    GradjaninBiH::dan_rodjenja = dan_rodjenja;
    GradjaninBiH::mjesec_rodjenja = mjesec_rodjenja;
    GradjaninBiH::godina_rodjenja = godina_rodjenja;
    GradjaninBiH::sifra_regije = sifra_regije;
    GradjaninBiH::pol = pol;
    prethodni = posljednji;
    posljednji = this;
};
bool GradjaninBiH::ProvjeriDatum(int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja) {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (godina_rodjenja % 4 == 0 && godina_rodjenja % 100 != 0 || godina_rodjenja % 400 == 0) broj_dana[1]++;
    if (godina_rodjenja < 1 || mjesec_rodjenja < 1 || mjesec_rodjenja > 12 || dan_rodjenja < 1 || dan_rodjenja > broj_dana[mjesec_rodjenja-1])
        return false;
    return true;
}
void GradjaninBiH::OcitajInformacije(long long int jmbg, int &dan_rodjenja, int &mjesec_rodjenja, int &godina_rodjenja, int &sifra_regije, Pol &pol) {
    dan_rodjenja = DajCifru(jmbg, 1) * 10 + DajCifru(jmbg, 2);
    mjesec_rodjenja = DajCifru(jmbg, 3) * 10 + DajCifru(jmbg, 4);
    godina_rodjenja = DajCifru(jmbg, 5) * 100 + DajCifru(jmbg, 6) * 10 + DajCifru(jmbg, 7);
    if (godina_rodjenja <= 17) godina_rodjenja += 2000;
    else godina_rodjenja += 1000;
    sifra_regije = DajCifru(jmbg, 8) * 10 + DajCifru(jmbg, 9);
    if (DajCifru(jmbg, 10) < 5) pol = Musko;
    else pol = Zensko;
}
int GradjaninBiH::DajCifru(long long int jmbg, int cifra) {
    for (int i = 13; jmbg != 0; i--) {
        if (i == cifra) return jmbg%10;
        jmbg /= 10;
    }
    return 0; //12 cifara;
}
int GradjaninBiH::KontrolnaCifra(long long int jmbg) {
    return 11 - (7 * (DajCifru(jmbg, 1) + DajCifru(jmbg, 7)) + 6 * (DajCifru(jmbg, 2) + DajCifru(jmbg, 8)) + 5 * (DajCifru(jmbg, 3) + DajCifru(jmbg, 9))
    + 4 * (DajCifru(jmbg, 4) + DajCifru(jmbg, 10)) + 3 * (DajCifru(jmbg, 5) + DajCifru(jmbg, 11)) + 2 * (DajCifru(jmbg, 6) + DajCifru(jmbg, 12)))%11;
}
int GradjaninBiH::BrojCifara(long long int jmbg) {
    int brojac(0);
    while (jmbg) brojac++, jmbg /= 10;
    return brojac;
}
void GradjaninBiH::ProvjeriJMBG(long long int jmbg) {
    auto broj_cifara(BrojCifara(jmbg));
    if (broj_cifara != 12 && broj_cifara != 13) throw std::logic_error ("JMBG nije validan");
    if (KontrolnaCifra(jmbg) == 10) throw std::logic_error ("JMBG nije validan");
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije;
    Pol pol;
    OcitajInformacije(jmbg, dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, pol);
    if (!ProvjeriDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja)) throw std::logic_error ("JMBG nije validan");
}

int main ()
{
	try {
	    GradjaninBiH *niz[100];
	    int n;
	    std::cout << "Koliko gradjana zelite unijeti po JMBG? " << std::endl;
	    std::cin >> n;
	    for (int i = 0; i < n; i++) {     
	        std::cin.ignore(10000, '\n');
	        std::string ime_i_prezime;
	        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
	        std::getline(std::cin, ime_i_prezime);
	        long long int jmbg;
	        std::cout << "Unesite JMBG: " << std::endl;
	        std::cin >> jmbg;
	        try {
	            niz[i] = new GradjaninBiH(ime_i_prezime, jmbg);
	            std::cout << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " rodjenog " << niz[i]->DajDanRodjenja()
	            << "." <<  niz[i]->DajMjesecRodjenja() << "." << niz[i]->DajGodinuRodjenja() << " u regiji " << niz[i]->DajSifruRegije() << ", ";
	            if (niz[i]->DajPol() == GradjaninBiH::Pol::Musko) std::cout << "musko." << std::endl;
	            else std::cout << "zensko." << std::endl;;
	        }
	        catch (std::logic_error e) {
	            std::cout << e.what() << std::endl;
	            i--;
	        }
	    }
	    int m;
	    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
	    std::cin >> m;
	    for (int i = n; i < n + m; i++) {
	        std::cin.ignore(10000, '\n');
	        std::string ime_i_prezime;
	        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
	        std::getline(std::cin, ime_i_prezime);
	        int dan_rodjenja, mjesec_rodjenja, godina_rodjenja;
	        char znak1, znak2;
	        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): " << std::endl;
	        std::cin >> dan_rodjenja >> znak1 >> mjesec_rodjenja >> znak2 >> godina_rodjenja;
	        int sifra_regije;
	        std::cout << "Unesite sifru regije: " << std::endl;
	        std::cin >> sifra_regije;
	        char gender;
	        std::cout << "Unesite M za musko, Z za zensko: " << std::endl;
	        std::cin >> gender;
	        GradjaninBiH::Pol pol(GradjaninBiH::Musko);
	        if (gender == 'Z') pol = GradjaninBiH::Zensko;
	        try {
	            niz[i] = new GradjaninBiH(ime_i_prezime, dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, pol);
	            std::cout << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " JMBG: " << niz[i]->DajJMBG() << "." << std::endl;
	        }
	        catch(std::logic_error e) {
	            std::cout << e.what() << std::endl;
	            i--;
	        }
	        
	    }
	    
	}
	catch(...) {
	    
	}
	return 0;
}
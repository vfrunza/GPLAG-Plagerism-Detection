/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

int brojac = 0;

class GradjaninBiH {
    long long int jmbg;
    std::string ime_prezime;
    int dan, mjesec, godina, sifra;
    mutable int kod_fe = 500, kod_ma = 0;
    static GradjaninBiH *zadnji;
    GradjaninBiH *prethodni = nullptr;
    bool provjera_datuma (int d, int m, int g) {
        int b_d [12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) b_d[1]++;
        if (g < 1 || d < 1 || m < 1 || m > 12 || d > b_d[m - 1]) return false;
        return true;
    }
    int vrati_13 (int c[]) { // za 13.cifru jmbg-a
        int c_13;
        c_13 = 11 - (7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2]+c[8]) + 4*(c[3]+c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11])) % 11;
        if (c_13 == 11) c_13 = 0;
        return c_13;
    }
    public:
    enum Pol { Musko, Zensko } ;
    GradjaninBiH (std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
   // ~GradjaninBiH();
    std::string DajImeIPrezime() const { return ime_prezime; }
    long long int DajJMBG() const { return jmbg; }
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime (std::string novo_ime) { ime_prezime = novo_ime; }
};
GradjaninBiH *GradjaninBiH::zadnji = nullptr;

GradjaninBiH::GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
    if (sifra_regije < 0 || sifra_regije > 99 || !(provjera_datuma(dan_rodjenja,mjesec_rodjenja,godina_rodjenja))) 
        throw std::domain_error ("Neispravni podaci");
    brojac++;
    int neki_kod;
    if (pol == Pol::Zensko) 
        neki_kod = kod_fe;
    
    else if (pol == Pol::Musko) 
        neki_kod = kod_ma;
    
    int temp_neki_kod (neki_kod);
    int dan_temp (dan_rodjenja), mjesec_temp(mjesec_rodjenja), temp_godina (godina_rodjenja), temp_regija(sifra_regije);
    int niz_jmbg[13];
   
    if (dan_rodjenja < 10) {
        niz_jmbg[0] = 0;
        niz_jmbg[1] = dan_rodjenja;
    }
    else {
        niz_jmbg[0] = int(dan_temp/10);
        niz_jmbg[1] = dan_temp%10; 
    }
    if (mjesec_rodjenja < 10) {
        niz_jmbg[2] = 0;
        niz_jmbg[3] = mjesec_rodjenja;
    }
    else {
        niz_jmbg[2] = int(mjesec_temp/10);
        niz_jmbg[3] = mjesec_temp%10;
    }
    niz_jmbg[4] = int ((temp_godina%1000)/100);
    niz_jmbg[5] = int ((temp_godina%100)/10);
    niz_jmbg[6] = int (temp_godina%10);
    if (sifra_regije < 10) {
        niz_jmbg[7] = 0;
        niz_jmbg[8] = sifra_regije;
    }
    else {
        niz_jmbg[7] = int (temp_regija/10);
        niz_jmbg[8] = int (temp_regija%10);
    }
    if (neki_kod == 0) {
        niz_jmbg[9] = 0;
        niz_jmbg[10] = 0;
        niz_jmbg[11] = neki_kod;
    }
    if (neki_kod > 0 && neki_kod < 10) {
        niz_jmbg[9] = 0;
        niz_jmbg[10] = 0;
        niz_jmbg[11] = neki_kod;
    }
    else if (neki_kod >=10 && neki_kod <100) {
        niz_jmbg[9] = 0;
        niz_jmbg[10] = int (temp_neki_kod/10);
        niz_jmbg[11] = int (temp_neki_kod%10);
    }
    else if (neki_kod >= 100 && neki_kod < 1000) {
        niz_jmbg[9] = int ((temp_neki_kod%1000)/100);
        niz_jmbg[10] = int ((temp_neki_kod%100) /10);
        niz_jmbg[11] = int (temp_neki_kod%10);
    }
    int c_13 = vrati_13(niz_jmbg);
    niz_jmbg[12] = c_13;
 
   /* GradjaninBiH *pok(this);
    if (brojac == 1) zadnji = pok;
    else {
        this->prethodni = zadnji;
        zadnji = pok;
    }
    GradjaninBiH *temp = zadnji->prethodni;
    for (GradjaninBiH *it = zadnji; it != nullptr; it=it->prethodni) {
        if (it->DajJMBG() == 0) {
            zadnji = nullptr;
            zadnji = temp;
            throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
            break;
        }
    }*/
    long long int pravi_jmbg(0);
    for (int i=0; i<13; i++) {
        pravi_jmbg = 10 * pravi_jmbg + niz_jmbg[i];
    }
    ime_prezime = ime_i_prezime; dan = dan_rodjenja; mjesec = mjesec_rodjenja; godina = godina_rodjenja; sifra = sifra_regije;
    jmbg = pravi_jmbg;
    if (pol == Pol::Zensko) kod_fe++;
    else kod_ma++;
}
GradjaninBiH::GradjaninBiH (std::string ime_i_prezime, long long int jmbg) {
    brojac++;
    GradjaninBiH *pok(this);
    if (brojac == 1) zadnji = pok;
    else {
        this->prethodni = zadnji;
        zadnji = pok;
    }
  /*  GradjaninBiH *temp = zadnji->prethodni;
    for (GradjaninBiH *it = zadnji; it != nullptr; it=it->prethodni) {
        if (it->GradjaninBiH::jmbg == jmbg) {
            zadnji = nullptr;
            zadnji = temp;
            throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
            break;
        }
    }*/
    long long int ne = jmbg;
    int vektor[13];
    for (long long int i=12; i>=0; i--) {
        vektor[i] = ne % 10;
        ne /= 10;
    }
    int c_13 = vrati_13(vektor);
    if (c_13 == 10 || vektor[12] != c_13) throw std::logic_error ("JMBG nije validan");
    if (vektor[9] >= 5) kod_fe++;
    else if (vektor[9] < 5) kod_ma++;
    int dan_rod = vektor[0]*10 + vektor[1];
    int mj_rod = vektor[2]*10 + vektor[3];
    int go_rod = vektor[4]*100 + vektor[5]*10 + vektor[6];
    if (!provjera_datuma(dan_rod,mj_rod,go_rod)) throw std::logic_error ("JMBG nije validan");
    ime_prezime = ime_i_prezime; GradjaninBiH::jmbg = jmbg;
}
/*GradjaninBiH::~GradjaninBiH() {
    auto p = zadnji;
    do {
        if (p->prethodni == nullptr) {
            GradjaninBiH::zadnji = nullptr;
            p = nullptr;
            break;
        }
        GradjaninBiH::zadnji = p->prethodni;
        p = nullptr;
        p = zadnji;
    } while (p->prethodni != nullptr);
}*/
int GradjaninBiH::DajDanRodjenja() const {
    long long int jm = DajJMBG();
    int niz[13];
    for (long long int i=12; i>=0; i--) {
        niz[i] = jm % 10;
        jm /= 10;
    }
  double nesto = (niz[0]*10 + niz[1]);
  return nesto;
}
int GradjaninBiH::DajMjesecRodjenja() const {
    long long int m = DajJMBG();
    int niz[13];
    for (int i=12; i>=0; i--) {
        niz[i] = m % 10;
        m /= 10;
    }
    return niz[2]*10 + niz[3];
}
int GradjaninBiH::DajGodinuRodjenja() const {
    long long int god = DajJMBG();
    int niz[13];
    for (int i=12; i>=0; i--) {
        niz[i] = god % 10;
        god /= 10;
    }
    double izraz = niz[4]*100 + niz[5]*10 + niz[6];
    if (niz[4] == 0) izraz+=2000;
    else izraz += 1000;
    return izraz;
}
int GradjaninBiH::DajSifruRegije() const {
    long long int sifra = DajJMBG();
    int niz[13];
    for (int i=12; i>=0; i--) {
        niz[i] = sifra%10;
        sifra /= 10;
    }
    return niz[7]*10 + niz[8];
}
GradjaninBiH::Pol GradjaninBiH::DajPol() const {
    Pol nesto;
    long long int s = DajJMBG();
    int niz[13];
    for (int i=12; i>=0; i--) {
        niz[i] = s % 10;
        s /= 10;
    }
    double izraz = niz[9]*100 + niz[10]*10 + niz[11];
    if (izraz <= 499) nesto = GradjaninBiH::Pol::Musko;
    else nesto = GradjaninBiH::Pol::Zensko;
    return nesto;
}
int main ()
{
    std::cout << "Koliko gradjana zelite unijeti po JMBG? " << std::endl;
    int n;
    std::cin >> n;
    std::cin.ignore(10000,'\n');
        for (int i=0; i<n; i++) {
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::string ime;
        std::getline (std::cin, ime);
        std::cout << "Unesite JMBG: " << std::endl;
        long long int jmbg;
        std::cin >> jmbg;
        std::cin.ignore(10000,'\n');
        try {
            GradjaninBiH ciko (ime, jmbg);
            std::cout << "Unijeli ste gradjanina " << ciko.DajImeIPrezime();
            std::cout << " rodjenog " << ciko.DajDanRodjenja() << "." << ciko.DajMjesecRodjenja() << "." << ciko.DajGodinuRodjenja();
            std::cout << " u regiji " << ciko.DajSifruRegije() << ", ";
            GradjaninBiH::Pol temp = ciko.DajPol();
            if (temp == 1) std::cout << "zensko.";
            else std::cout << "musko.";
            std::cout << std::endl;
        }
        catch (std::logic_error poruka) {
                std::cout << poruka.what() << std::endl;
               i--;
            }
        }
    int m;
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
    std::cin >> m;
    for (int i=0; i<m; i++) {
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::string ime;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::getline (std::cin, ime);
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): " << std::endl;
        int dan, mjesec, godina;
        char z1, z2;
        std::cin >> dan >> z1 >> mjesec >> z2 >> godina;
        std::cout << "Unesite sifru regije: " << std::endl;
        int sifra;
        std::cin >> sifra;
        std::cout << "Unesite M za musko, Z za zensko: " << std::endl;
        char spol;
        std::cin >> spol;
        try{
            GradjaninBiH::Pol spol1;
            if (spol == 'M') spol1 = GradjaninBiH::Pol::Musko;
            else spol1 = GradjaninBiH::Pol::Zensko;
            GradjaninBiH  ciko (ime, dan, mjesec, godina,sifra, spol1) ;
            std::cout << "Unijeli ste gradjanina " << ciko.DajImeIPrezime() << " JMBG: " << ciko.DajJMBG() <<"." << std::endl;
        }
        catch (std::logic_error poruka) {
            std::cout << poruka.what() << std::endl;
            i--;
        }
    }
	return 0;
}
#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>

class GradjaninBiH {
    std::string ime_i_prezime;
    long long int jmbg;
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, kod;
    GradjaninBiH *prethodni;
    static GradjaninBiH *zadnji;
    static bool NeispravanDatum(int d, int m, int g);
    static void VecPostojiJMBG(long long int jmbg);
    static int c13(int d, int m, int g, int sifra, int kod);
    static long long int KreirajJMBG(int d, int m, int g, int sifra, int p);
public:
    enum Pol{Musko, Zensko};
    ~GradjaninBiH();
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol);
    GradjaninBiH(const GradjaninBiH &gr) = delete;
    GradjaninBiH operator =(const GradjaninBiH &gr) = delete;
    std::string DajImeIPrezime() const { return ime_i_prezime; }
    long long int DajJMBG() const { return jmbg; }
    int DajDanRodjenja() const { return dan_rodjenja; }
    int DajMjesecRodjenja() const { return mjesec_rodjenja; }
    int DajGodinuRodjenja() const { return godina_rodjenja; }
    int DajSifruRegije() const { return sifra_regije; }
/**/Pol DajPol() const { return Pol(kod >= 500); }
    void PromijeniImeIPrezime(std::string novo_ime) { ime_i_prezime = novo_ime; }
};

GradjaninBiH *GradjaninBiH::zadnji(nullptr);
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, kod, sifra_regije;
    long long int temp(jmbg / 10);
    kod = temp % 1000; temp /= 1000;
    sifra_regije = temp % 100; temp /= 100;
    godina_rodjenja = temp % 100; temp /= 100;
    if(temp % 10 == 0) godina_rodjenja += 2000;
    else godina_rodjenja += 1900;
    temp /= 10;
    mjesec_rodjenja = temp % 100; temp /= 100;
    dan_rodjenja = temp % 100; 
    int c(c13(dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, kod));
    if(NeispravanDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja) || c == 10 || c != jmbg%10)
        throw std::logic_error("JMBG nije validan");
    VecPostojiJMBG(jmbg);
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    GradjaninBiH::jmbg = jmbg;
    GradjaninBiH::dan_rodjenja = dan_rodjenja; 
    GradjaninBiH::mjesec_rodjenja = mjesec_rodjenja; 
    GradjaninBiH::godina_rodjenja = godina_rodjenja;
    GradjaninBiH::sifra_regije = sifra_regije; 
    GradjaninBiH::kod = kod;
    if(zadnji == nullptr) prethodni = nullptr;
    else prethodni = zadnji;
    zadnji = this;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
int godina_rodjenja, int sifra_regije, Pol pol) {
    if(NeispravanDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja) || sifra_regije < 0 || sifra_regije > 99)
        throw std::logic_error("Neispravni podaci");
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    GradjaninBiH::dan_rodjenja = dan_rodjenja; 
    GradjaninBiH::mjesec_rodjenja = mjesec_rodjenja; 
    GradjaninBiH::godina_rodjenja = godina_rodjenja;
    GradjaninBiH::sifra_regije = sifra_regije;
    GradjaninBiH::jmbg = KreirajJMBG(dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, pol);
    GradjaninBiH::kod = jmbg%10;
    if(zadnji == nullptr) prethodni = nullptr;
    else prethodni = zadnji;
    zadnji = this;
}
bool GradjaninBiH::NeispravanDatum(int d, int m, int g) {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++;
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m-1])
        return true;
    return false;
}
int GradjaninBiH::c13(int d, int m, int g, int sifra, int kod) {
    int c1(d/10), c2(d%10), c3(m/10), c4(m%10), c5, c6, c7, c8, c9, c10, c11, c12;
    c5 = (g/100)%10; c6 = (g/10)%10; c7 = g%10;
    c8 = sifra/10; c9 = sifra%10;
    c10 = kod/100; c11 = (kod/10)%10; c12 = kod%10;
    int c = 11 - (7*(c1+c7) + 6*(c2+c8) + 5*(c3+c9) + 4*(c4+c10) + 3*(c5+c11) + 2*(c6+c12)) % 11;
    if(c == 11) c = 0;
    return c;
}
void GradjaninBiH::VecPostojiJMBG(long long int jmbg) {
    GradjaninBiH *pok(zadnji);
    while(pok != nullptr) {
        if(pok->jmbg == jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        pok = pok->prethodni;
    }
}
long long int GradjaninBiH::KreirajJMBG(int d, int m, int g, int sifra, int p) {
    GradjaninBiH *pok(zadnji);
    int kod(0), n(500);
    bool uvecaj_kod;
    if(p) { kod = 500; n = 1000; }
    while(kod < n) {
        pok = zadnji; uvecaj_kod = false;
        while(pok != nullptr) {
            if(kod == pok->kod && pok->dan_rodjenja == d && pok->sifra_regije == sifra) {
                uvecaj_kod = true;
                break;
            } pok = pok->prethodni;
        }
        if(uvecaj_kod) kod++;
        else break;
    }
    long long int mj(m), gj(g);
    long long int b = d*100000000000 + mj*1000000000;
    return b + c13(d, m, g, sifra, kod) + kod*10 + sifra*10000 + (gj%1000)*1000000;
}
GradjaninBiH::~GradjaninBiH() {
    GradjaninBiH *pok(zadnji);
    if(zadnji == this) {
        zadnji = zadnji->prethodni;
        pok->prethodni = nullptr;
    }
    else {
        while(pok->prethodni != this) pok = pok->prethodni;
        pok->prethodni = prethodni;
    }
}
void Ispisi(const GradjaninBiH &gr) {
    std::cout << "Unijeli ste gradjanina " << gr.DajImeIPrezime() << " rodjenog " << gr.DajDanRodjenja() << "." << gr.DajMjesecRodjenja()
    << "." << gr.DajGodinuRodjenja() << " u regiji " << gr.DajSifruRegije() << ", ";
    if(gr.DajPol()) std::cout << "zensko." << std::endl;
    else std::cout << "musko." << std::endl;
} 
int main ()
{
    try {
    int n1, n2;
    std::cout << "Koliko gradjana zelite unijeti po JMBG? " << std::endl;
    std::cin >> n1; std::cin.ignore(1000, '\n');
    for(int i=0; i<n1; i++) {
        try {
        std::string ime;
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::getline(std::cin, ime); 
        long long int jmbg;
        std::cout << "Unesite JMBG: " << std::endl;
        std::cin >> jmbg;
        std::cin.ignore(1000, '\n');
        GradjaninBiH gr(ime, jmbg);
        Ispisi(gr);
        }
        catch(std::logic_error e) {
            std::cout << e.what() << std::endl;
            i--;
        }
    }
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
    std::cin >> n2; std::cin.ignore(1000, '\n');
    for(int i=0; i<n2; i++) {
        try {
        std::string ime;
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::getline(std::cin, ime);
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): " << std::endl;
        int d, m, g;
        char znak;
        std::cin >> d >> znak >> m >> znak >> g;
        std::cin.ignore(1000, '\n');
        int sifra_regije;
        std::cout << "Unesite sifru regije: " << std::endl;
        std::cin >> sifra_regije; 
        char z; GradjaninBiH::Pol pol;
        std::cout << "Unesite M za musko, Z za zensko: " << std::endl;
        std::cin >> z;
        if(z == 'M') pol = GradjaninBiH::Musko;
        else pol = GradjaninBiH::Zensko;
        std::cin.ignore(1000, '\n');
        GradjaninBiH gr(ime, d, m, g, sifra_regije, pol);
        std::cout << "Unijeli ste gradjanina " << gr.DajImeIPrezime() << " JMBG: " << gr.DajJMBG() 
        << "." << std::endl;
        }
        catch(std::logic_error e) {
            std::cout << e.what() << std::endl;
            i--;
        }
    }
    } catch(std::logic_error e) { std::cout << e.what() << std::endl; }
    catch(...) {}
	return 0;
}
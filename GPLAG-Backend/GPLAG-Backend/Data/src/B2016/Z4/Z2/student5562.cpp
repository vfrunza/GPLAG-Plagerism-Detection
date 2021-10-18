/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <cmath>

class GradjaninBiH{
    //Atributi
    std::string ime;
    long long int jmbg;
    int c[13];
    GradjaninBiH* prethodni{nullptr};
    static GradjaninBiH* zadnji;
    //Pomocne funkcije
    static bool JeLiIspravanDatum(int d, int m, int g);
    static int c13(int *c){
        return 11-(7*(c[0] + c[6]) + 6*(c[1] + c[7]) + 5*(c[2] + c[8]) + 4*(c[3] + c[9]) + 3*(c[4] + c[10]) + 2*(c[5] + c[11]))%11;
    }
    
    void IzvadiPodatke(long long int jmbg, int* c);
    void TestJmbg(long long int jmbg);
    void Uvezi(){
        prethodni = zadnji;
        zadnji = this;
    }
    int DajKod()const{
        return c[9]*100 + c[10]*10 + c[11];
    }
    
public:
    enum Pol{Musko, Zensko};
    //Konstruktori
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    //Destruktor 
    ~GradjaninBiH();
    //Inspektori
    std::string DajImeIPrezime()const{
        return ime;
    };
    long long int DajJMBG()const {return jmbg;};
    int DajDanRodjenja()const{
        return c[0]*10 + c[1];
    };
    int DajMjesecRodjenja()const{
        return c[2]*10 + c[3];
    };
    int DajGodinuRodjenja()const;
    int DajSifruRegije()const{
        return c[7]*10 + c[8];
    };
    Pol DajPol()const;
    //Mutatori
    void PromijeniImeIPrezime(std::string novo_ime){
        ime = novo_ime;
    };
};
GradjaninBiH* GradjaninBiH::zadnji(nullptr);
void GradjaninBiH::IzvadiPodatke(long long int jmbg, int*c){
    int niz[13];
    for (int i = 0; i < 13; i++){
        niz[i] = jmbg%10;
        jmbg /= 10;
    }
    std::reverse_copy(niz, niz + 13, c);
    int x(c13(c));
    if (x == 11) {c[12] = 0;}
}
bool GradjaninBiH::JeLiIspravanDatum(int d, int m, int g){
    int br_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if ((g % 4 == 0 && g % 100 != 0) || g%400 == 0) br_dana[1]++;
    if (d < 1 || d < 1 || m < 1 || m > 12 || d > br_dana[m - 1])
        return false;
    return true;
}
void GradjaninBiH::TestJmbg(long long int jmbg){
    int x(c13(c));
    if ((x != 11 && c[12] != x) || !JeLiIspravanDatum(DajDanRodjenja(), DajMjesecRodjenja(), DajGodinuRodjenja()))
        throw std::logic_error("JMBG nije validan");
    for (GradjaninBiH* p = zadnji; p != nullptr; p = p->prethodni){
        if (p->jmbg == jmbg)
            throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    }
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    IzvadiPodatke(jmbg, c);
    TestJmbg(jmbg);
    GradjaninBiH::jmbg = jmbg;
    ime = ime_i_prezime;
    Uvezi();
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    //Provjeri podatke
    if (!JeLiIspravanDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja) || sifra_regije < 0 || sifra_regije > 99)
        throw std::logic_error("Neispravni podaci");
    int kod;
    if (pol == Musko) kod = 0; else kod = 500; //Pocetak ovisi od spola
    //Nadji prvi slobodan kod
    for (GradjaninBiH* p = zadnji; p != nullptr; p = p->prethodni){
        if (p->DajPol() == pol && p->DajDanRodjenja() == dan_rodjenja && p->DajMjesecRodjenja() == mjesec_rodjenja && p->DajDanRodjenja() == dan_rodjenja)
        {
            int kod2(p->DajKod());
            if (kod == kod2 && p != this) kod = kod2 + 1;
            else break;
        }
    }
    //Formiraj jmbg
    int gr = godina_rodjenja;
    while(gr >= 1000)
        gr -= 1000;
    jmbg = dan_rodjenja*std::pow(10, 11) + mjesec_rodjenja*std::pow(10,9) + gr*std::pow(10,6) + sifra_regije*std::pow(10,4) + kod*std::pow(10,1);
    IzvadiPodatke(jmbg, c); // Iz njega povadi podatke
    int x(c13(c)); if (x == 11) x = 0; 
    jmbg += x;//Dodaj c13
    ime = ime_i_prezime;
    Uvezi(); //Ubaci u lanac
}
GradjaninBiH::~GradjaninBiH(){
    GradjaninBiH* temp(nullptr);
    for (GradjaninBiH* p = zadnji; p!= nullptr; p = p->prethodni)
    {
        if (p == this)
        {
            if (temp){ 
                if (p->prethodni)
                    temp->prethodni = p->prethodni;
                else 
                    temp->prethodni = nullptr;
            }
            p->prethodni = nullptr;
            break;
        }
        temp = p;
    }
}
int GradjaninBiH::DajGodinuRodjenja()const{
    int g(c[4]*100 + c[5]*10 + c[6]);
    if (g <= 17) g+=2000;
    else g += 1000;
    return g;
}
GradjaninBiH::Pol GradjaninBiH::DajPol()const{
    int kod(DajKod());
    if (kod < 500) return Musko;
    return Zensko;
}
int main ()
{   
    int n;
    std::cout << "Koliko gradjana zelite unijeti po JMBG? \n";
    std::cin >> n;
    GradjaninBiH* gradjani[100];
    std::fill(gradjani, gradjani + 100, nullptr);
    int br(0);
    
    for (int i = 0; i < n; i++)
    {   std::cin.ignore(100, '\n');
        std::string iip;
        std::cout << "Unesite ime i prezime (u istom redu): \n";
        std::getline(std::cin, iip);
        long long int jmbg;
        std::cout << "Unesite JMBG: \n";
        std::cin >> jmbg;
        try
        {
            gradjani[br] = new GradjaninBiH(iip, jmbg);
            std::cout << "Unijeli ste gradjanina " << gradjani[br]->DajImeIPrezime() << " rodjenog " 
            << gradjani[br]->DajDanRodjenja() << "." << gradjani[br]->DajMjesecRodjenja() << "." << gradjani[br]->DajGodinuRodjenja() << " u regiji " << gradjani[br]->DajSifruRegije() << ", ";
            if (gradjani[br]->DajPol() == GradjaninBiH::Pol::Musko) std::cout << "musko.\n";
            else std::cout << "zensko.\n"; 
            br++;
        }
        catch(std:: logic_error e)
        {
            std::cout << e.what() << "\n";
            i--;
        }
    }
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin.ignore(100,'\n');
        std::string iip;
        std::cout << "Unesite ime i prezime (u istom redu): \n";
        std::getline(std::cin, iip);
        int d, m, g;
        char znak;
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): \n";
        std::cin >> d >> znak >> m >> znak >> g;
        int sifra_regije;
        std::cout << "Unesite sifru regije: \n";
        std::cin >> sifra_regije;
        char p;
        std::cout << "Unesite M za musko, Z za zensko: \n";
        std::cin >> p;
        GradjaninBiH::Pol pol;
        if (p == 'M') pol = GradjaninBiH::Pol::Musko;
        else if (p == 'Z') pol = GradjaninBiH::Pol::Zensko;
        try{
            gradjani[br] = new GradjaninBiH(iip, d, m, g, sifra_regije, pol);
            std::cout << "Unijeli ste gradjanina " << gradjani[br]->DajImeIPrezime() << " JMBG: " << gradjani[br]->DajJMBG() << ".\n";
            br++;
        }
        catch(std::logic_error e)
        {
            std::cout << e.what() << "\n";
            i--;
        }
    }
    for (int i = 0; i < 100; i++)
        delete gradjani[i];
	return 0;
}
/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <deque>
#include <stdexcept>

enum Pol{Musko, Zensko};

/*class Datum {
  int dan, mjesec, godina; 
  public:
  Datum(int d, int m, int g);
  void Postavi(int d, int m, int g);
  int DajDan() const {return dan;}
  int DajMjesec() const {return mjesec;}
  int DajGodinu() const {return godina;}
};

void Datum::Postavi(int d, int m, int g) {
    int mjeseci[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0) mjeseci[1]++;
    if(d < 1 || m < 1 || g < 1 || d > mjeseci[m - 1] || m > 12) throw std::logic_error("Neispravni podaci");
    dan = d; mjesec = m; godina = g;
}

Datum::Datum(int d, int m, int god) {
    int mjeseci[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(god % 4 == 0 && god % 100 != 0 || god % 400 == 0) mjeseci[1]++;
    if(d < 1 || m < 1 || god < 1 || d > mjeseci[m - 1] || m > 12) throw std::logic_error("Neispravni podaci");
    dan = d; mjesec = m; godina = god;
}*/

class GradjaninBiH {
    std::string ime_i_prezime;
    long long int JMBG;
    //Datum dan_rodjenja;
    int dan, mjesec, godina;
    Pol poll;
    GradjaninBiH* prethodni=nullptr;
    static GradjaninBiH* posljednji;
    public:
    //enum Pol{Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    ~GradjaninBiH();
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);
    void Ispisi() const {
        std::cout << ime_i_prezime << " " << JMBG << " " << dan << "/" << mjesec << "/" << godina << " " << poll << std::endl;
    }
};

GradjaninBiH* GradjaninBiH::posljednji = nullptr;

GradjaninBiH::~GradjaninBiH() {
    if(prethodni == nullptr && posljednji == this) {}
    else if(prethodni == nullptr) {
        GradjaninBiH* pom(posljednji);
        while(pom->prethodni  != this) {
            pom = pom->prethodni;
        }
        pom->prethodni = nullptr;
    }
    else if(this == posljednji) {
        posljednji = posljednji->prethodni;
        this->prethodni = nullptr;
    }
    else {
        GradjaninBiH* pom(posljednji);
        while (pom->prethodni != this) {
            pom = pom->prethodni;
        }
        pom->prethodni = this->prethodni;
        this->prethodni = nullptr;
    }
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
    if(prethodni == nullptr){
        posljednji = this;
    }
    else {
        this->prethodni = posljednji;
        posljednji = this;
        
    }
    GradjaninBiH* pomoc(posljednji);
    while(pomoc != nullptr) {
        //if(pomoc->JMBG == jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        pomoc = pomoc->prethodni;
    }
    int dek[13];
    long long int pom(jmbg);
    int brojac{};
    while(pom != 0) {
        int br(pom%10);
        dek[brojac] = br;
        brojac++;
        pom /= 10;
    }
    //for(int i = 0; i < 13; i++) std::cout << dek[i] << " ";
    int c(11 - (7 * (dek[12] + dek[6]) + 6 * (dek[11] + dek[5]) + 5 * (dek[10] + dek[4]) + 4 * (dek[9] + dek[3]) + 3 * (dek[8] + dek[2])
    + 2 * (dek[1] + dek[7]))%11);
    if(c == 10) throw std::logic_error("JMBG nije validan\n");
    if(c == 11) c=0;
    int dan((dek[12] * 10) + dek[11]), mjesec((dek[10] * 10) + dek[9]), godina((dek[8] * 100) + (dek[7] * 10) + dek[6]);
    if (godina <= 917) godina += 2000;
    if(godina > 917 && godina <= 999) godina += 1000; 
    int mjeseci[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0)) mjeseci[1]++;
    if(dan < 1 || dan > mjeseci[mjesec - 1] || mjesec < 1 || mjesec > 12 || godina < 1 || godina > 2017) throw std::logic_error("JMBG nije validan\n");
    if(dek[3] >= 0 && dek[3] < 5) poll = Musko;
    if(dek[3] >= 5 && dek[3] < 10) poll = Zensko;
    GradjaninBiH::dan = dan; GradjaninBiH::mjesec = mjesec; GradjaninBiH::godina=godina;
    JMBG = jmbg;
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    int mjeseci[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //std::cout << mjesec_rodjenja << std::endl;
    //std::cout << godina_rodjenja << std::endl;
    //std::cout << sifra_regije << std::endl;
    if(godina_rodjenja % 4 == 0 && (godina_rodjenja % 100 != 0 || godina_rodjenja % 400 == 0)) mjeseci[1]++;
    if(dan_rodjenja < 1 || mjesec_rodjenja < 1 || mjesec_rodjenja > 12 || dan_rodjenja > mjeseci[mjesec_rodjenja - 1] || 
    godina_rodjenja < 1850 || godina_rodjenja > 2017 || sifra_regije < 0 || sifra_regije > 99) throw std::logic_error("Neispravni podaci\n");
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    dan = dan_rodjenja;
    mjesec = mjesec_rodjenja;
    godina = godina_rodjenja;
    poll = pol;
    int pomocni1(godina_rodjenja);
    int brojac1{};
    int dek1[4];
    while(pomocni1 != 0) {
        int br(pomocni1%10);
        dek1[brojac1] = br;
        brojac1++;
        pomocni1 /= 10;
    }
    long long int  pom2(mjesec_rodjenja * 100000000);
    long long int pom1(dan_rodjenja * 100000000000), pom3(((dek1[2] * 100 + dek1[1] * 10 + dek1[0])) * 1000000), 
    pom4(sifra_regije * 10000);
    //std::cout << pom2 << std::endl;
    long int pom5(0);
    if(pol == Musko || pol == 0) pom5 = 0;
    if(pol == Zensko || pol == 1) pom5 = 500;
    //GradjaninBiH* pomocni(posljednji);
    /*if(pol == Musko) {
        while(pomocni->DajPol() != Zensko && pomocni != nullptr) {
            pomocni = pomocni->prethodni;
        }
        if(pomocni == nullptr) pom5 = 0;
        long long int pom(pomocni->DajJMBG());
        int niz[13];
        int bojac{};
        while(pom != 0) {
            int br(pom%10);
            niz[bojac] = br;
            bojac++;
            pom /= 10;
        }
        pom5 = niz[1] + niz[2] * 10 + niz[3] * 100;
        pom5++;
    }
    else if(pol == Zensko) {
        while(pomocni->DajPol() != Musko && pomocni != nullptr) {
            pomocni = pomocni->prethodni;
        }
        if(pomocni == nullptr) pom5 = 500;
        long long int pomo(pomocni->DajJMBG());
        int niz[13];
        int bojac{};
        while(pomo != 0) {
            int br(pomo%10);
            niz[bojac] = br;
            bojac++;
            pomo /= 10;
        }
        pom5 = niz[1] + niz[2] * 10 + niz[3] * 100;
        pom5++;
    }*/
    //std::cout << pom5 << std::endl;
    JMBG = pom1 + pom2*10 + pom3 + pom4 + pom5*10;
    int dek[13];
    long long int pom(JMBG);
    int brojac{};
    while(pom != 0) {
        int br(pom%10);
        dek[brojac] = br;
        brojac++;
        pom /= 10;
    }
    int c(11 - (7 * (dek[12] + dek[6]) + 6 * (dek[11] + dek[5]) + 5 * (dek[10] + dek[4]) + 4 * (dek[9] + dek[3]) + 3 * (dek[8] + dek[2])
    + 2 * (dek[1] + dek[7]))%11);
    if(c == 11) c = 0;
    JMBG = pom1 + pom2*10 + pom3 + pom4 + pom5*10 + c;
    //std::cout << JMBG << std::endl;
}

std::string GradjaninBiH::DajImeIPrezime() const {
    return ime_i_prezime;
}

long long int GradjaninBiH::DajJMBG() const {
    return JMBG;
}

int GradjaninBiH::DajDanRodjenja() const {
    return dan;
}

int GradjaninBiH::DajMjesecRodjenja() const {
    return mjesec;
}
    
int GradjaninBiH::DajGodinuRodjenja() const{
    return godina;
}

int GradjaninBiH::DajSifruRegije() const {
    int niz[13];
    long long int pom(DajJMBG());
    int br{};
    while(pom != 0) {
        int broj(pom%10);
        niz[br] = broj;
        br++;
        pom /= 10;
    }
    int vracam(niz[5] * 10 + niz[4]);
    return vracam;
}

Pol GradjaninBiH::DajPol() const {
    return poll;
}

void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime) {
    ime_i_prezime = novo_ime;
}

int main ()
{
    GradjaninBiH* niz[100];
    for(int i = 0; i < 100; i++) niz[i] = nullptr;
    std::cout << "Koliko gradjana zelite unijeti po JMBG? \n";
    int n;
    std::cin >> n;
    //std::cout <<  std::endl;
    //std::cin.ignore();
    //std::cin.clear();
    for(int i = 0; i < n; i++) {
        try{
        std::cout << "Unesite ime i prezime (u istom redu): \n";
        std::cin.ignore(10000, '\n');
        std::cin.clear();
        std::string pom;
        std::getline(std::cin, pom);
        //std::cout <<  std::endl;
        std::cout << "Unesite JMBG: \n";
        long long int jmbg;
        std::cin >> jmbg;
        try{
            niz[i] = new GradjaninBiH(pom, jmbg);
        std::cout << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " rodjenog " << 
        niz[i]->DajDanRodjenja() << "." << niz[i]->DajMjesecRodjenja() << "." << niz[i]->DajGodinuRodjenja() << " u regiji " <<
        niz[i]->DajSifruRegije() << ", ";
        int a(niz[i]->DajPol());
        if(a == 0) std::cout << "musko.";
        if(a == 1) std::cout << "zensko.";
        //std::cout <<  std::endl;
        std::cout << std::endl;
        }
        catch(std::bad_alloc){
            delete niz[i];
            niz[i] = nullptr;
        }
        //std::cin.ignore();
        //std::cin.clear();
        }
        catch(std::logic_error izuzetak) {
            std::cout << izuzetak.what();
            //std::cin.clear();
            //std::cin.ignore(10000, '\n');
            i--;
        }
    
    }
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
    int m;
    std::cin >> m;
    //std::cin.ignore(10000, '\n');
    //std::cin.clear();
    for(int i = n; i < m + n; i++) {
        try{
        std::cout << "Unesite ime i prezime (u istom redu): \n";
        std::cin.ignore(10000, '\n');
        std::cin.clear();
        std::string pom;
        std::getline(std::cin, pom);
        //std::cout <<  std::endl;
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): \n";
        char znak;
        int dan,mjesec,godina;
        std::cin >> dan >> znak >> mjesec >> znak >> godina;
        std::cin.clear();
        //std::cin.ignore(10000, '\n');
        std::cout << "Unesite sifru regije: \n";
        int regija;
        std::cin >> regija;
        //std::cin.clear();
        //std::cin.ignore(10000, '\n');
        std::cout << "Unesite M za musko, Z za zensko: \n";
        char slovo;
        std::cin >> slovo;
        //std::cin.clear();
        //std::cin.ignore(10000, '\n');
        Pol pol;
        if(slovo == 'M') pol = Musko;
        if(slovo == 'Z') pol = Zensko;
        try{
        niz[i+n] = new GradjaninBiH(pom, dan, mjesec, godina, regija, pol);
        std::cout << "Unijeli ste gradjanina " << niz[i+n]->DajImeIPrezime() << " JMBG: " << niz[i+n]->DajJMBG() << ".";
        std::cout << std::endl;
        //std::cin.ignore();
        //std::cin.clear();
        }
        catch(std::bad_alloc) {
            delete niz[i];
            niz[i] = nullptr;
        }
        }
        catch(std::logic_error izuzetak) {
            std::cout << izuzetak.what();
            i--;
            //std::cin.ignore();
            //std::cin.clear();
        }
    }
    /*try{
    GradjaninBiH gradjanin("Rogo Arnes", 2731996131538);
    gradjanin.Ispisi();
    std::cout << gradjanin.DajJMBG();
    }
    catch(std::logic_error izuzetak) {
        std::cout << izuzetak.what();
    }*/
    return 0;
}
/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!

#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <memory>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::logic_error;
using std::make_shared;
using std::shared_ptr;
using std::fill;

const long long int ZaDan = 10e10;
const long long int ZaMjesec = 10e8;
const int ZaGodinu = 10e5;

class GradjaninBiH {
        
    string ime_i_prezime;
    long long int jmbg;
    GradjaninBiH *prethodni;
    
    static GradjaninBiH *posljednji;
    
    public :
        enum Pol {Musko, Zensko};
    private :
        GradjaninBiH(const GradjaninBiH &g) = delete;
        GradjaninBiH &operator=(const GradjaninBiH &g) = delete;
        
        static bool VecPostoji(long long int jmbg);
        static int kontrolna(long long int jmbg);
        static bool check_jmbg(long long int jmbg);
    public :
        GradjaninBiH(string ime_i_prezime, long long int jmbg);
        GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
            int godina_rodjenja, int sifra_regije, Pol pol);
        
        // ~GradjaninBiH();
        
        string DajImeIPrezime() const { return ime_i_prezime; }
        long long int DajJMBG() const { return jmbg; }
        int DajDanRodjenja() const { return jmbg / ZaDan; };
        int DajMjesecRodjenja() const;
        int DajGodinuRodjenja() const;
        int DajSifruRegije() const;
        Pol DajPol() const;
        
        void PromijeniImeIPrezime(string novo_ime) { ime_i_prezime = novo_ime; };
};

GradjaninBiH *GradjaninBiH::posljednji(nullptr);

int DajDan(long long int jmbg) {
    return jmbg / ZaDan;
}

int DajMjesec(long long int jmbg) {
    return (jmbg / ZaMjesec) % 100;
}

int DajGodinu(long long int jmbg)
{
    int godina = (jmbg / ZaGodinu) % 1000;
    if (godina < 18)
        godina += 2000;
    else
        godina += 1000;
    return godina; 
}

int DajRegiju(long long int jmbg)
{
    return (jmbg / 10000) % 100;
}

int Kontrolna(int c[12])
{
    return 11 - (7*(c[0] + c[6]) + 6*(c[1] + c[7]) + 5*(c[2] + c[8]) + 4*(c[3] + c[9]) +
        3*(c[4] + c[10]) + 2*(c[5] + c[11])) % 11;
}

// Pretpostavljamo da su svi datumi iz 2017. validni?
bool GradjaninBiH::check_jmbg(long long int jmbg)
{
    int dan(DajDan(jmbg)), mjesec(DajMjesec(jmbg)), godina(DajGodinu(jmbg)), regija(DajRegiju(jmbg)),
        kod((jmbg % 10000) / 10);

    // Ispravnost datuma
    if (jmbg < 0 || dan == 0 || dan > 31 || mjesec == 0 || mjesec > 12 || godina < 1918 || godina > 2017) {
        return false;
    }
    if (mjesec == 4 || mjesec == 6 || mjesec == 9 || mjesec == 11) {
        if (dan > 30)
            return false;
    }
    if (mjesec == 2) {
        if (godina % 4 == 0 && godina % 100 != 0 && godina % 400 == 0) {
            if (dan > 29) 
                return false;
        } else {
            if (dan > 28)
                return false;
        }
    }
    // Ispravnost kontrolne cifre
    int c13(jmbg % 10);
    int cifre[] = {dan / 10, dan % 10, mjesec / 10, mjesec % 10, (godina / 100) % 10,
        (godina / 10) % 10, godina % 10, regija / 10, regija % 10, kod / 100, (kod / 10) % 10,
        kod % 10};
    int kontrolna = Kontrolna(cifre);
    if (kontrolna == 10)
        return false;
    if (kontrolna == 11)
        kontrolna = 0;
    return c13 == kontrolna;
}

bool GradjaninBiH::VecPostoji(long long int jmbg)
{
    GradjaninBiH *trenutni(posljednji);
    while(trenutni != nullptr) {
        if (jmbg == trenutni->jmbg)
            return true;
        trenutni = trenutni->prethodni;
    }
    
    return false;
}

GradjaninBiH::GradjaninBiH(string ime_i_prezime, long long int jmbg)
{
    if (!check_jmbg(jmbg))
        throw logic_error("JMBG nije validan");
        
    if (GradjaninBiH::VecPostoji(jmbg))
        throw logic_error("Vec postoji gradjanin sa istim JMBG");
        
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    GradjaninBiH::jmbg = jmbg;
    prethodni = posljednji;
    posljednji = this;
}


GradjaninBiH::GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol)
{
    // Ispravnost datuma
    if (dan_rodjenja < 0 || dan_rodjenja > 31 || mjesec_rodjenja < 0 || mjesec_rodjenja > 12 ||
        godina_rodjenja < 1918 || godina_rodjenja > 2017 || sifra_regije < 0 || sifra_regije > 99)
            throw logic_error("Neispravni podaci");
    if (mjesec_rodjenja == 4 || mjesec_rodjenja == 6 || mjesec_rodjenja == 9 || mjesec_rodjenja == 11) {
        if (dan_rodjenja > 30)
            throw logic_error("Neispravni podaci");
    }
    if (mjesec_rodjenja == 2) {
        if (godina_rodjenja % 4 == 0 && godina_rodjenja % 100 != 0 && godina_rodjenja % 400 == 0) {
            if (dan_rodjenja > 29) 
                throw logic_error("Neispravni podaci");
        } else {
            if (dan_rodjenja > 28)
                throw logic_error("Neispravni podaci");
        }
    }
    // Ispravnost sifre regije
    if (sifra_regije < 0 || sifra_regije > 100)
        throw logic_error("Neispravni podaci");
    
    jmbg = dan_rodjenja*ZaDan + mjesec_rodjenja*ZaMjesec +
        (godina_rodjenja % 1000)*ZaGodinu + sifra_regije * 10000;


    bool slobodan[500];
    fill(slobodan, slobodan + 500, true);
    long long int prvi_dio(jmbg / 10000);
    GradjaninBiH *trenutni(posljednji);
    while (trenutni != nullptr) {
        if (trenutni->jmbg / 10000 == prvi_dio && pol == trenutni->DajPol())
            slobodan[((trenutni->jmbg % 10000) / 10) % 500] = true;
        trenutni = trenutni->prethodni;
    }

    int kod(0);
    bool cond(true);
    int cifre[12] = {dan_rodjenja / 10, dan_rodjenja % 10, mjesec_rodjenja / 10,
        mjesec_rodjenja % 10, (godina_rodjenja / 100) % 10, (godina_rodjenja / 10) % 10,
        godina_rodjenja % 10, sifra_regije/ 10, sifra_regije % 10};
    int c13(0);
    // Trazimo prihvatljiv kod
    while(cond) {
        // Nadjimo sljedeci slobodni kod
        for (int i = kod; i < 500; i++) {
            if (slobodan[i]) {
                kod = i + 500*(pol == Zensko);
                break;
            }
        }
        cifre[9] = kod / 100;
        cifre[10] = (kod / 10) % 10;
        cifre[10] = kod % 10;
        c13 = Kontrolna(cifre);
        if (c13 == 11) {
            c13 = 0;
            cond = false;
        } else if(c13 == 10) {
            kod += 1;
        } else {
            cond = false;
        }
    }
    
    jmbg += kod*10 + c13;
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
}

/* GradjaninBiH::~GradjaninBiH() {
    GradjaninBiH *sljedeci(nullptr);
    // Ako nije zadnji gradjanin, naci gradjanina koji pokazuje na ovog
    if (posljednji != this) {
        sljedeci = posljednji;
        while(sljedeci->prethodni != this) {
            sljedeci = sljedeci->prethodni;
        }
        sljedeci->prethodni = this->prethodni;
    } else { // Ako je zadnji, prethodni postaje i posljednji 
    cout << 8;
        posljednji = prethodni;
    }
} */

int GradjaninBiH::DajMjesecRodjenja() const {
    return DajMjesec(jmbg);
}

int GradjaninBiH::DajGodinuRodjenja() const {
    return DajGodinu(jmbg);
}

int GradjaninBiH::DajSifruRegije() const {
    return DajRegiju(jmbg);
}

GradjaninBiH::Pol GradjaninBiH::DajPol() const
{
    if ((jmbg / 10) % 1000 < 500) {
        return Musko;
    } else {
        return Zensko;
    }
}


int main ()
{
    int n;
    cout << "Koliko gradjana zelite unijeti po JMBG? \n";
    cin >> n;
    shared_ptr<GradjaninBiH> niz[100];
    shared_ptr<GradjaninBiH> p(nullptr);
    //GradjaninBiH *niz[100];
    cin.ignore(10000, '\n');
    
    bool cond(true);
    string ime_i_prezime;
    long long int jmbg(0);
    for (int i = 0; i < n; i++) {
        cond = true;
        while (cond) {
            cout << "Unesite ime i prezime (u istom redu): \n";
            getline(cin, ime_i_prezime);
            cout << "Unesite JMBG: \n";
            cin >> jmbg;
            cin.ignore(10000, '\n');
            try {
                niz[i] = make_shared<GradjaninBiH>(ime_i_prezime, jmbg);
                cout << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " rodjenog " <<
                    niz[i]->DajDanRodjenja() << "." << niz[i]->DajMjesecRodjenja() << "." <<
                    niz[i]->DajGodinuRodjenja() << " u regiji " << niz[i]->DajSifruRegije() << ", ";
                if (niz[i]->DajPol() == GradjaninBiH::Musko)
                    cout << "musko.";
                else
                    cout << "zensko.";
                cout << endl;
                cond = false;
            } catch(logic_error &e) {
                    cout << e.what() << endl;
            }
        }
    }
    
    cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
    cin >> n;
    int d, m, g, reg;
    char pol;
    cin.ignore(10000, '\n');
    for (int i = 0; i < n; i++) {
        cond = true;
        while (cond) {
            cout << "Unesite ime i prezime (u istom redu): \n";
            getline(cin, ime_i_prezime);
            cout << "Unesite datum rodjenja (format dd/mm/gggg): \n";
            cin >> d;
            cin.ignore(10000, '/');
            cin >> m;
            cin.ignore(10000, '/');
            cin >> g;
            cout << "Unesite sifru regije: \n";
            cin >> reg;
            cout << "Unesite M za musko, Z za zensko: \n";
            cin >> pol;
            cin.ignore(10000, '\n');
            try {
                niz[i] = make_shared<GradjaninBiH>(ime_i_prezime, d, m, g, reg,
                    pol == 'M' ? GradjaninBiH::Musko : GradjaninBiH :: Zensko);
                cout << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " JMBG: " <<
                    niz[i]->DajJMBG() << ".\n";
                cond = false;
            } catch(logic_error &e) {
                    cout << e.what() << endl;
            }
        }
    }
    p = nullptr;
    
    return 0;
}
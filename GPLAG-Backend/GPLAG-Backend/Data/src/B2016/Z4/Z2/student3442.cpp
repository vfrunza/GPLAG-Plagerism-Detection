#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

template<typename T> std::string PretvoriUString(T x) {
    std::ostringstream s; s << x; return s.str();
}

static int unikatna_cifra_musko = 0;
static int unikatna_cifra_zensko = 500;

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
    GradjaninBiH::Pol pol;
    static GradjaninBiH* zadnji;
    GradjaninBiH* p = nullptr;
    
    bool DaLiJeDatumIspravan(int dd, int mm, int gg);
    
   static int izracunajC13(std::string s);
    
    static long long int generirajJMBG(int dan_rodjenja, int mjesec_rodjenja, 
        int godina_rodjenja, int sifra_regije, GradjaninBiH::Pol pol);
public:
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, 
        int godina_rodjenja, int sifra_regije, Pol pol);

    std::string DajImeIPrezime() const {
        return ime_i_prezime;
    }
    long long int DajJMBG() const {
        return jmbg;
    }
    int DajDanRodjenja() const {
        return dan_rodjenja;
    }
    int DajMjesecRodjenja() const {
        return mjesec_rodjenja;
    }
    int DajGodinuRodjenja() const {
        return godina_rodjenja;
    }
    int DajSifruRegije() const {
        return sifra_regije;
    }
    Pol DajPol() {
        return pol;
    }
    void PromijeniImeIPrezime(std::string novo_ime) {
        ime_i_prezime = novo_ime;
    }
    ~GradjaninBiH() {
        if(zadnji == this && p == nullptr) 
            zadnji = nullptr;
        else if(p == nullptr) {
            auto pok = zadnji; 
            while(pok->p != this)
                pok = pok->p;
            pok->p = nullptr;
        }
        else if(zadnji == this) {
            zadnji = p;
            p = nullptr;
        }
        else {
            auto pok = zadnji;
            while(pok->p != this) {
                pok = pok->p;
            }
            pok->p = p;
            p = nullptr;
        }
    }
    GradjaninBiH(const GradjaninBiH &g) = delete;
    GradjaninBiH &operator = (const GradjaninBiH &g) = delete;
};

GradjaninBiH* GradjaninBiH::zadnji = nullptr;

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg)
                          : ime_i_prezime(ime_i_prezime), jmbg(jmbg){
    std::string jmbg_string = PretvoriUString(jmbg);
    if(jmbg_string.length() < 12 || jmbg_string.length() > 13) 
        throw std::logic_error("JMBG nije validan");
        
    if(jmbg_string.length() == 12) 
        jmbg_string = "0" + jmbg_string;
    
    for(int i = 0; i < jmbg_string.length(); i++) {
        if(i == 0) {
            std::string temp = jmbg_string.substr(i, 2);
            dan_rodjenja = std::stoi(temp);
        }
        else if(i == 2) {
           std::string temp = jmbg_string.substr(i, 2);
           mjesec_rodjenja = std::stoi(temp);
        }
        else if(i == 4) {
            int temp_cifra = std::stoi(jmbg_string.substr(i, 3));
            std::string temp = "";
            if(temp_cifra >= 0 && temp_cifra <= 17) 
                temp = "2";
            else 
                temp = "1";
            temp += jmbg_string.substr(i, 3);
            godina_rodjenja = std::stoi(temp);
        }
        else if(i == 7) {
            std::string temp = jmbg_string.substr(i, 2);
            sifra_regije = std::stoi(temp);
        }
        else if(i == 9) {
            std::string temp = jmbg_string.substr(i, 3);
            int pol_cifra = std::stoi(temp);
            if(pol_cifra >= 0 && pol_cifra <= 499) 
                pol = Musko;
            else if(pol_cifra >= 500 && pol_cifra <= 999)
                pol = Zensko;
        }
    }
    
    if(!DaLiJeDatumIspravan(dan_rodjenja, mjesec_rodjenja, godina_rodjenja))
        throw std::logic_error("JMBG nije validan");
        
    int c13_jmbg = jmbg_string.back() - '0';
    int c13_fun = izracunajC13(jmbg_string);
    
    if(c13_fun == 10)
        throw std::logic_error("JMBG nije validan");
    
    if(c13_jmbg != c13_fun) {
        jmbg = generirajJMBG(dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, pol);
    }
    if(zadnji == nullptr) {
        zadnji = this;
        p = nullptr;
    }
    else {
        auto pok = zadnji;
        while(pok != nullptr) {
            if(pok->jmbg == jmbg) 
                throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
            pok = pok->p;
        }
        p = zadnji;
        zadnji = this;
    }
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, 
        int godina_rodjenja, int sifra_regije, Pol pol)
        : ime_i_prezime(ime_i_prezime), dan_rodjenja(dan_rodjenja), mjesec_rodjenja(mjesec_rodjenja), 
          godina_rodjenja(godina_rodjenja), sifra_regije(sifra_regije), pol(pol) {
        
    if(!DaLiJeDatumIspravan(dan_rodjenja, mjesec_rodjenja, godina_rodjenja) || !(sifra_regije >= 0 && sifra_regije <= 99))
        throw std::logic_error("Neispravni podaci");
        
    try {
        jmbg = generirajJMBG(dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, pol);

        if(zadnji == nullptr) {
            zadnji = this;
            p = nullptr;
        }
        else {
            auto pok = zadnji;
            while(pok != nullptr) {
                if(pok->jmbg == jmbg) 
                    throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
                pok = pok->p;
            }
            p = zadnji;
            zadnji = this;
        }
    }
    catch(...) {
        throw;
    }
}   

bool GradjaninBiH::DaLiJeDatumIspravan(int dd, int mm, int gg) {
    if(gg >= 1917 && gg <= 2017) {
        if(mm >= 1 && mm <= 12) {
            if((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm ==8 || mm == 10 || mm == 12))
                return true;
            else if((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                return true;
            else if((dd >= 1 && dd <= 28) && mm == 2)
                return true;
            else if(dd == 29 && mm == 2 && (gg%400 == 0 || (gg%4 == 0 && gg%100 != 0)))
                return true;
            else return false;
        }
        return false;
    }
    return false;
}

int GradjaninBiH::izracunajC13(std::string s) {
   if(s.length() != 12 && s.length() != 13) throw std::range_error("Neispravna JMBG duzina");
   int c[13] = {0};
   for(int i = 0; i < 12; i++) {
       c[i] = s[i] - '0';
   }
   int c13 = 11 - (7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2]+c[8]) 
    + 4*(c[3]+c[9]) + 3*(c[4]+c[10])+2*(c[5]+c[11])) % 11;
    
   if(c13 == 11) 
        return 0;
   return c13;
}

long long int GradjaninBiH::generirajJMBG(int dan_rodjenja, int mjesec_rodjenja, 
        int godina_rodjenja, int sifra_regije, GradjaninBiH::Pol pol) {
    long long int jmbg_novi = dan_rodjenja;
    
    jmbg_novi *= 100;
    jmbg_novi += mjesec_rodjenja;
        
    {
        jmbg_novi *= 1000;
        std::string temp = PretvoriUString(godina_rodjenja);
        jmbg_novi += std::stoi(temp.substr(1,3));
    }
    
    jmbg_novi *= 100;
    jmbg_novi += sifra_regije;
    
    // --------------- ovaj dio koda je nedovrsen -----------------
    
    if(pol == Musko) {
        if(unikatna_cifra_musko >= 0 && unikatna_cifra_musko <= 499) {
            jmbg_novi *= 1000;
            jmbg_novi += 0; //unikatna_cifra_musko; <----------------------
            //unikatna_cifra_musko++;
        }
    }
    else if(pol == Zensko) {
        if(unikatna_cifra_zensko >= 500 && unikatna_cifra_zensko <= 999) {
            jmbg_novi *= 1000;
            jmbg_novi += 500;// unikatna_cifra_zensko; <----------------------
            //unikatna_cifra_zensko++;
        }
    }
    
    // --------------- ovaj dio koda je nedovrsen -----------------
    
    std::string jmbg_novi_string = "";
    if(dan_rodjenja < 10) 
        jmbg_novi_string += "0";
    jmbg_novi_string += PretvoriUString(jmbg_novi);
    
    int c13 = izracunajC13(jmbg_novi_string);
    
    if(c13 == 10) 
        throw std::logic_error("JMBG nije validan");
    
    jmbg_novi *= 10;
    jmbg_novi += c13;
    
    return jmbg_novi;
}

int main() {
    std::cout << "Koliko gradjana zelite unijeti po JMBG? ";
    int broj_gr;
    std::cin >> broj_gr;
    
    GradjaninBiH* niz[10000];
    
    for(int i = 0; i < broj_gr; i++) {
        std::cin.ignore(1000, '\n'); std::cin.clear();
        std::cout << "\nUnesite ime i prezime (u istom redu): ";
        std::string iip;
        std::getline(std::cin, iip); 
        long long int jmbg;
        std::cout << "\nUnesite JMBG: ";
        std::cin >> jmbg;
        try {
            niz[i] = new GradjaninBiH(iip, jmbg);
        }
        catch(std::logic_error e) {
            std::cout << std::endl << e.what(); 
            i--;
            continue;
        }
        std::cout << "\nUnijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " rodjenog " << niz[i]->DajDanRodjenja() << "." <<
            niz[i]->DajMjesecRodjenja() << "." << niz[i]->DajGodinuRodjenja() << " u regiji " << niz[i]->DajSifruRegije() << ", ";
        if(niz[i]->DajPol() == GradjaninBiH::Pol::Musko) std::cout << "musko.";
        else std::cout << "zensko.";
    }
    
    std::cout << "\nKoliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
    int broj_gr_2;
    std::cin >> broj_gr_2;
    
    for(int i = broj_gr; i < broj_gr_2+broj_gr; i++) {
        std::cin.ignore(1000, '\n'); std::cin.clear();
        std::cout << "\nUnesite ime i prezime (u istom redu): ";
        std::string iip;
        std::getline(std::cin, iip);
        std::cout << "\nUnesite datum rodjenja (format dd/mm/gggg): ";
        std::string datum_rodjenja;
        std::getline(std::cin, datum_rodjenja);
        
        int dan_rodjenja = std::stoi(datum_rodjenja.substr(0,2));
        int mjesec_rodjenja = std::stoi(datum_rodjenja.substr(3,2));
        int godina_rodjenja = std::stoi(datum_rodjenja.substr(6,4));
        
        int sifra_regije;
        std::cout << "\nUnesite sifru regije: "; 
        std::cin >> sifra_regije;
        
        std::cout << "\nUnesite M za musko, Z za zensko: ";
        char pol;
        std::cin >> pol;
        try {
            if(pol == 'Z') {
                niz[i] = new GradjaninBiH(iip, dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, GradjaninBiH::Pol::Zensko);
            }
            else niz[i] = new GradjaninBiH(iip, dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, GradjaninBiH::Pol::Musko);
        }
        catch(std::logic_error e) {
            std::cout << std::endl << e.what(); 
            i--;
            continue;
        }
    
        std::cout << "\nUnijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " JMBG: " << niz[i]->DajJMBG() << "."; 
    }
    
    for(int i = 0; i < broj_gr + broj_gr_2; i++) delete niz[i];
    
    return 0;
}
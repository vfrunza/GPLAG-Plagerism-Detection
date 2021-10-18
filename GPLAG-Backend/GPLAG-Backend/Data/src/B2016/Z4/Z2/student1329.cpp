#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH {
    std::string ime_i_prezime, jmbg;
    static std::string PretvoriUString(long long int jmbg);
    static GradjaninBiH *zadnji_lik;
    static long long int Stepen(int baza, int stepen);
    static long long int PretvoriUBroj(std::string s);
    static int BrojDana(int mjesec, int godina);
    static bool Jednaki(int kontrolna_cifra, std::string jmbg);
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);
};

GradjaninBiH* GradjaninBiH::zadnji_lik(nullptr);

bool GradjaninBiH::Jednaki(int kontrolna_cifra, std::string jmbg) {
    int broj(0);
    
    broj += 11 - (7 * (jmbg[0] + jmbg[6]) + 6 * (jmbg[1] + jmbg[7]) + 5 * (jmbg[2] + jmbg[8]) + 4 * (jmbg[3] + jmbg[9]) + 3 * (jmbg[4] + jmbg[10]) + 2 * (jmbg[5] + jmbg[11])) % 11;
    
    if(kontrolna_cifra == broj) return true;
    return false;
}

std::string GradjaninBiH::PretvoriUString(long long int jmbg) {
    std::string s;
    while(jmbg != 0) {
        s.insert(s.begin(), (jmbg % 10) + '0'); jmbg /= 10;
    }
    if(s.size() < 13) s.insert(s.begin(), '0');
    if(s[12] == 11) s[12] = '0';
    return s;
}

long long int GradjaninBiH::Stepen (int baza, int stepen) {
    long long int proizvod(1);
    for(int i = 0; i < abs(stepen); i++) proizvod *= baza;
    return proizvod;
}

long long int GradjaninBiH::PretvoriUBroj(std::string s) {
    long long int broj(0);
    int stepen(0);
    
    for(int i = s.size() - 1; i >= 0; i--, stepen++)
        broj += (s[i] - '0') * Stepen(10, stepen);
    
    return broj;
}

int GradjaninBiH::BrojDana(int mjesec, int godina) {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        broj_dana[1]++;
    return broj_dana[mjesec - 1];
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
    std::string s(PretvoriUString(jmbg));
    int mjesec(PretvoriUBroj(s.substr(2, 2))), godina(PretvoriUBroj(s.substr(4, 3))), dan(PretvoriUBroj(s.substr(0, 2)));
    if(mjesec < 1 || mjesec > 12 || dan < 1 || dan > BrojDana(mjesec, godina) || godina > 2017 || godina < 1 || s.size() != 13) throw std::logic_error("JMBG nije validan");
    int sifra_regiona(PretvoriUBroj(s.substr(7, 2))), pol_osobe(PretvoriUBroj(s.substr(9, 3)));
    if(sifra_regiona < 0 || sifra_regiona > 99 || pol_osobe < 0 || pol_osobe > 999) throw std::logic_error("JMBG nije validan");
    int kontrolna_cifra(PretvoriUBroj(s.substr(12, 1)));
    if(!GradjaninBiH::Jednaki(kontrolna_cifra, s) && kontrolna_cifra == 10) throw std::logic_error("JMBG nije validan");
    //if(GradjaninBiH::DaLiPostoji(s)) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    zadnji_lik = ;
    GradjaninBiH::ime_i_prezime = ime_i_prezime; GradjaninBiH::jmbg = PretvoriUString(jmbg);
}

inline GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
    //if(mjesec_rodjenja < 1 || mjesec_rodjenja > 12 || dan_rodjenja < 1 || dan_rodjenja > BrojDana(mjesec, godina) || godina_rodjenja > 2017 || godina_rodjenja < 1) throw std::logic_error("Neispravni podaci");
    if(sifra_regije < 0 || sifra_regije > 99) throw std::logic_error("Neispravni podaci");
    
    
}

inline std::string GradjaninBiH::DajImeIPrezime() const { return ime_i_prezime; }
inline long long int GradjaninBiH::DajJMBG() const { return PretvoriUBroj(jmbg); }
inline int GradjaninBiH::DajDanRodjenja() const { return PretvoriUBroj(jmbg.substr(0, 2)); }
inline int GradjaninBiH::DajMjesecRodjenja() const { return PretvoriUBroj(jmbg.substr(2, 2)); }
inline int GradjaninBiH::DajGodinuRodjenja() const {
    std::string s(jmbg.substr(4, 3));
    if(s[0] == 0) s.insert(s.begin(), '2');
    else s.insert(s.begin(), '1');
    return PretvoriUBroj(s);
}
inline int GradjaninBiH::DajSifruRegije() const { return PretvoriUBroj(jmbg.substr(7, 2)); }
inline GradjaninBiH::Pol GradjaninBiH::DajPol() const { 
    if(PretvoriUBroj(jmbg.substr(9, 3)) <= 499) return Pol::Musko;
    return Pol::Zensko;
}
inline void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime) { ime_i_prezime = novo_ime; }

int main() {
    
    GradjaninBiH g1("Rambo Sulejmanovic", 3004956174255);
    std::cout << g1.DajImeIPrezime() << std::endl << g1.DajJMBG() << std::endl << g1.DajDanRodjenja() << std::endl << g1.DajMjesecRodjenja() << std::endl;
    std::cout << g1.DajGodinuRodjenja() << std::endl << g1.DajSifruRegije() << std::endl;
    g1.PromijeniImeIPrezime("Hamo Hasic Sikira"); std::cout << g1.DajImeIPrezime() << std::endl;
    
    return 0;
}
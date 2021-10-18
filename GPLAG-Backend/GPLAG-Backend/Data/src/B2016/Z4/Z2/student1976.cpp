/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH {
    std::string ime_prezime;
    long long int JMBG;
    static GradjaninBiH *kraj;
    GradjaninBiH *prethodni = nullptr;
    
    bool Provjera(int d, int m, int g) {
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(g % 4 == 0 && (g % 100 != 0 || g % 400 == 0)) broj_dana[1]++;
        if(g < 1917 || g > 2017 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1]) return false;
        return true;
    }
public:
    enum Pol {Musko, Zensko};
    
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
        ime_prezime = ime_i_prezime; 
        int niz[13];
        long long int maticni_br = jmbg;
        for(int i = 0; i < 13; i++) {
            niz[i] = maticni_br%10;
            maticni_br /= 10;
        }
        if(niz[12] == 11) niz[12] = 0;
        
        int dan (niz[12]*10 + niz[11]);
        int mjesec (niz[10]*10 + niz[9]);
        int godina (1000 + niz[8]*100 + niz[7]*10 + niz[6]);
        if(godina < 1917) godina = 2000 + niz[8]*100 + niz[7]*10 + niz[6];
        int c13 = 11 - (7*(niz[12] + niz[6]) + 6*(niz[11] + niz[5]) + 5*(niz[10] + niz[4]) + 4*(niz[9] + niz[3]) + 3*(niz[8] + niz[2]) + 2*(niz[7] + niz[1])) % 11;
        if(!Provjera(dan, mjesec, godina)) throw std::logic_error ("JMBG nije validan");
        if(c13 == 10) throw std::logic_error ("JMBG nije validan");
        JMBG = jmbg;
        
       if(!prethodni)
           kraj = prethodni;
        else {
            prethodni = kraj;
            kraj = this;
        }
        for(auto p = kraj; p != nullptr; p = p -> prethodni) {
            if(p->JMBG == jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        }
    }
    
    explicit GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
        ime_prezime = ime_i_prezime;
        if(Provjera(dan_rodjenja, mjesec_rodjenja, godina_rodjenja) == false || sifra_regije <= 0 || sifra_regije >= 99) 
            throw std::logic_error("Neispravni podaci");
        int niz[13];
        int dan(dan_rodjenja), mjesec(mjesec_rodjenja), godina(godina_rodjenja), sifra(sifra_regije);
        niz[11] = dan % 10;
        niz[12] = dan / 10;
        niz[9] = mjesec % 10;
        niz[10] = mjesec / 10;
        niz[6] = godina % 10;
        godina /= 10;
        niz[7] = godina % 10;
        godina /= 10;
        niz[8] = godina % 10;
        niz[4] = sifra % 10;
        niz[5] = sifra / 10;
        int kod(0);
        if(pol == Zensko) kod = 500;
        for(auto p = kraj; p != nullptr; p = p -> prethodni) {
            if(p->DajDanRodjenja() == dan_rodjenja && p->DajPol() == pol && p->DajSifruRegije() == sifra_regije) kod++;
        }
        niz[1] = kod % 10;
        kod /= 10;
        niz[2] = kod % 10;
        niz[3] = kod / 10;
        niz[0] = 11 - (7*(niz[12] + niz[6]) + 6*(niz[11] + niz[5]) + 5*(niz[10] + niz[4]) + 4*(niz[9] + niz[3]) + 3*(niz[8] + niz[2]) + 2*(niz[7] + niz[1])) % 11;
        if(niz[0] == 11) niz[0] = 0;
        if(niz[0] == 10) throw std::logic_error("JMBG nije validan");
         
        std::string tmp = "";
        for(int i = 12; i >= 0; i--) 
            tmp += niz[i] + '0';

 /*     int k = 1;       
        for(int i = 0; i < tmp.length(); i++){
            if(i == 0) JMBG = tmp[i];
            else{
                JMBG += tmp[i]*k;
                k *= 10;
            } 
        }
 */      
    }
   
//    GradjaninBiH(const GradjaninBiH &g) = delete;
//    GradjaninBiH &operator =(const GradjaninBiH &g) = delete; 
    std::string DajImeIPrezime() const { return ime_prezime; }
   
    long long int DajJMBG() const { return JMBG; }
   
    int DajDanRodjenja() const {
        long long int jmbg = JMBG;
        int niz[13];
        for(int i = 0; i < 13; i++) {
            niz[i] = jmbg%10;
            jmbg /= 10;
        }
        if(niz[12] == 11) niz[12] = 0;
        return niz[12]*10 + niz[11];
    }
    
    int DajMjesecRodjenja() const {
        long long int jmbg = JMBG;
        int niz[13];
        for(int i = 0; i < 13; i++) {
            niz[i] = jmbg%10;
            jmbg /= 10;
        }
        if(niz[12] == 11) niz[12] = 0;
        return niz[10]*10 + niz[9];
    }
    
    int DajGodinuRodjenja() const {
        long long int jmbg = JMBG;
        int niz[13];
        for(int i = 0; i < 13; i++) {
            niz[i] = jmbg%10;
            jmbg /= 10;
        }
        if(niz[12] == 11) niz[12] = 0;
        int god = 1000 + niz[8]*100 + niz[7]*10 + niz[6];
        if(god < 1917) god = 2000 + niz[8]*100 + niz[7]*10 + niz[6];
        return god;
    }
    
    int DajSifruRegije() const {
        long long int jmbg = JMBG;
        int niz[13];
        for(int i = 0; i < 13; i++) {
            niz[i] = jmbg%10;
            jmbg /= 10;
        }
        if(niz[12] == 11) niz[12] = 0;    
        return niz[5]*10 + niz[4];
    }
    Pol DajPol() const{
        long long int jmbg = JMBG;
        int niz[13];
        for(int i = 0; i < 13; i++) {
            niz[i] = jmbg%10;
            jmbg /= 10;
        }
        if(niz[12] == 11) niz[12] = 0;
        int pol(niz[3]*100 + niz[2]*10 + niz[1]);
        if(pol < 500) return Pol::Musko;
        return Pol::Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime) { ime_prezime = novo_ime; }
};
GradjaninBiH *GradjaninBiH::kraj = nullptr;

int main ()
{
    std::cout << "Koliko gradjana zelite unijeti po JMBG? ";
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::string s;
        std::cout << "\nUnesite ime i prezime (u istom redu): ";
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, s);
        std::cout << "\nUnesite JMBG: ";
        long long int j;
        std::cin >> j;
        try{
            GradjaninBiH g = GradjaninBiH(s, j);
            std::cout << "\nUnijeli ste gradjanina " << g.DajImeIPrezime() << " rodjenog " << g.DajDanRodjenja() << "." << g.DajMjesecRodjenja() << "."  << g.DajGodinuRodjenja() << " u regiji " << g.DajSifruRegije() << ", ";
            if(g.DajPol() == 1) std::cout << "zensko.";
            else std::cout << "musko.";
        } catch(std::logic_error e){
            std::cout << e.what();
            i--;
        }
    }
    std::cin.ignore(1000,'\n');
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
    for(int i = 0; i < n; i++) {
        std::string s;
        std::cout << "\nUnesite ime i prezime (u istom redu): ";
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, s);
        std::cout << "\nUnesite datum rodjenja (format dd/mm/gggg): ";
        char znak; 
        int dan, mjesec, godina;
        std::cin >> dan; std::cin.get(znak); std::cin>> mjesec; std::cin.get(znak); std::cin >> godina;
        std::cout << "\nUnesite sifru regije: ";
        int sifra;
        std::cin >> sifra;
        std::cout << "\nUnesite M za musko, Z za zensko: ";
        char slovo;
        std::cin.get(slovo);
        GradjaninBiH::Pol pol;
        if(slovo == 'M') pol = GradjaninBiH::Musko;
        else pol = GradjaninBiH::Zensko;
        try {
            GradjaninBiH g = GradjaninBiH(s, dan, mjesec, godina, sifra, pol);
            std::cout << "\nUnijeli ste gradjanina " << g.DajImeIPrezime() << " JMBG: " << g.DajJMBG();
        }
        catch (std::logic_error e) {
            std::cout << e.what();
            i--;
        }
    }
    return 0;
}
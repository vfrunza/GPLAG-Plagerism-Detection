/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <memory>
#include <cmath>
#include <algorithm>

class GradjaninBiH {
    std::string ip;
    int JMBG[13]{};
    GradjaninBiH* prosli{nullptr};
    static GradjaninBiH* posljednji;
    
    bool datum(int dan, int mjesec, int god);
    int StvoriBroj(int a, int b, int c=-1) const {
        if(c == -1) return a*10 + b;
        else return a*100 + 10*b + c;
    }
    int formula(int c[]) const {
        int c13 = 11 - (7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2]+c[8]) + 4*(c[3]+ c[9]) + 3*(c[4] + c[10]) + 2*(c[5] + c[11]))%11;
        if (c13 == 11) return 0;
        return c13;
    }
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    GradjaninBiH(const GradjaninBiH &gr) = delete;
    GradjaninBiH &operator =(const GradjaninBiH &gr) = delete;
    ~GradjaninBiH();
    std::string DajImeIPrezime() const {return ip;}
    long long int DajJMBG() const;
    int DajDanRodjenja() const {return StvoriBroj(JMBG[0], JMBG[1]);}
    int DajMjesecRodjenja() const {return StvoriBroj(JMBG[2],JMBG[3]);}
    int DajGodinuRodjenja() const {
        int god(StvoriBroj(JMBG[4], JMBG[5], JMBG[6]));
        if(god +1000 < 2017-100) return god+2000;
        if(god+2000 > 2017) return god+1000;
    }
    int DajSifruRegije() const {return StvoriBroj(JMBG[7], JMBG[8]);}
    Pol DajPol() const {
        int br(StvoriBroj(JMBG[9], JMBG[10], JMBG[11]));
        if(br < 500) return GradjaninBiH::Musko;
        return GradjaninBiH::Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime) {
        ip = novo_ime;
    }
    
};
GradjaninBiH* GradjaninBiH::posljednji(nullptr);
bool GradjaninBiH::datum(int d, int m, int g) {
    int br_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0) br_dana[1]++;
    if((g+1000 < 2017-100 && g+2000 > 2017) || d < 1 || m < 1 || m > 12 || d > br_dana[m-1]) return false;
    return true;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) : ip(ime_i_prezime) {
    for(int i = 12; i >= 0; i--) {
        JMBG[i] = jmbg%10;
        jmbg /= 10;
    }
    bool valjan = datum(StvoriBroj(JMBG[0], JMBG[1]), StvoriBroj(JMBG[2], JMBG[3]), StvoriBroj(JMBG[4], JMBG[5], JMBG[6]));
    if(!valjan || JMBG[12] != formula(JMBG) || formula(JMBG) == 10) throw std::logic_error("JMBG nije validan");
    auto p(posljednji);
    while(p != nullptr) {
        if(std::equal(std::begin(JMBG), std::end(JMBG), std::begin(p->JMBG))){ throw std::logic_error("Vec postoji gradjanin sa istim JMBG");}
        p = p->prosli;
    }
    prosli = posljednji;
    posljednji = this;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) : ip(ime_i_prezime) {
    JMBG[4] = (godina_rodjenja/100)%10;
    JMBG[5] = (godina_rodjenja%100)/10;
    JMBG[6] = godina_rodjenja%10;
    bool valjan = datum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja);
    if(!valjan || sifra_regije < 0 || sifra_regije > 99) throw std::logic_error("Neispravni podaci");
    JMBG[0] = dan_rodjenja/10; JMBG[1] = dan_rodjenja%10; JMBG[2] = mjesec_rodjenja/10; JMBG[3] = mjesec_rodjenja%10;
    JMBG[7] = sifra_regije/10; JMBG[8] = sifra_regije%10;
    int brojac(0), granica(500);
    if(pol == GradjaninBiH::Zensko) {brojac = 500; granica = 1000;}
    for(;;) {
        if(brojac == granica) throw std::logic_error("");
        JMBG[9] = brojac / 100;
        JMBG[10] = (brojac / 10) % 10;
        JMBG[11] = brojac% 10;
        if(formula(JMBG) != 10) {
            bool pronadjen(false);
            auto p(posljednji);
            while(p != nullptr) {
                if(std::equal(JMBG, JMBG+12, p->JMBG)) {
                    pronadjen = true;
                    break;
                }
                p = p->prosli;
            }
            if(!pronadjen) {
                JMBG[12] = formula(JMBG);
                break;
            }
        }
        brojac++;
    }
    prosli = posljednji;
    posljednji = this;
}

GradjaninBiH::~GradjaninBiH() {
    if (posljednji == this) {
        posljednji = prosli;
    }
    else{
        auto p(posljednji), p2(posljednji);
        while(p != this) {
            p2 = p;
            p = p->prosli;
        }
    p2 -> prosli = p->prosli;
    }
}

long long int GradjaninBiH::DajJMBG() const {
    long long int br(0);
    for(int i = 0; i < 13; i++) {
        br += JMBG[i];
        if(i != 12) br *= 10;
    }
    return br;
}
int main ()
{
    GradjaninBiH* gradjani[100]{};
    int brojac_kreiranih(0);
    try{
        std::cout << "Koliko gradjana zelite unijeti po JMBG? \n";
        int n;
        std::cin >> n;
        std::cin.ignore(1000, '\n');
        for(int i = 0; i < n; i++) {
            std::cout << "Unesite ime i prezime (u istom redu): \n";
            std::string ime;
            getline(std::cin, ime);
            std::cout << "Unesite JMBG: \n";
            long long int jmbg;
            std::cin >> jmbg;
            std::cin.ignore(10000, '\n');
            try{
                gradjani[i] = new GradjaninBiH(ime, jmbg);
                std::cout << "Unijeli ste gradjanina " << gradjani[i]->DajImeIPrezime() <<" rodjenog " << gradjani[i]->DajDanRodjenja() << "." << gradjani[i]->DajMjesecRodjenja() << "." << gradjani[i]->DajGodinuRodjenja() << " u regiji " << gradjani[i]->DajSifruRegije() << ", ";
                if(gradjani[i]->DajPol() == GradjaninBiH::Musko) std::cout << "musko.\n";
                else std::cout << "zensko.\n";
                brojac_kreiranih++;
            }
            catch(std::logic_error e) {
                std::cout << e.what() << std::endl;
                i--;
            }
        }
        std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
        std::cin >> n;
        std::cin.ignore(1000, '\n');
        for(int i=0; i < n; i++) {
            std::cout << "Unesite ime i prezime (u istom redu): \n";
            std::string ime;
            getline(std::cin, ime);
            std::cout << "Unesite datum rodjenja (format dd/mm/gggg): \n";
            int d,m,g;
            char c;
            std::cin >> d >> c >> m >> c >> g;
            std::cout << "Unesite sifru regije: \n";
            int sifra;
            std::cin >> sifra;
            std::cin.ignore(1000,'\n');
            std::cout << "Unesite M za musko, Z za zensko: \n";
            std::cin >> c;
            std::cin.ignore(1000, '\n');
            try{
                if(c == 'M') gradjani[brojac_kreiranih] = new GradjaninBiH(ime, d, m, g, sifra, GradjaninBiH::Musko);
                else gradjani[brojac_kreiranih] = new GradjaninBiH(ime, d, m, g, sifra, GradjaninBiH::Zensko);
                std::cout << "Unijeli ste gradjanina " <<gradjani[brojac_kreiranih]->DajImeIPrezime() <<" JMBG: " << gradjani[brojac_kreiranih]->DajJMBG()<<".\n";
                
                brojac_kreiranih++;
            }
            catch(std::logic_error e) {
                std::cout << e.what() << std::endl;
                i--;
            }
            
        }
        
    }
    catch(std::bad_alloc) {
    }
for(int i = 0; i < 100; i++)
    delete gradjani[i];
    
	return 0;
}
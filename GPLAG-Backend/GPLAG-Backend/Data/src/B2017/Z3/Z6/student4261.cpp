/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <memory>
#include <stdexcept>
#include <map>
#include <string>
#include <stack>



enum class Boje {Pik, Tref, Herc, Karo};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    std::shared_ptr<Cvor> sljedeci;
};


std::shared_ptr<Cvor> KreirajSpil() {
    
    const char* karte[13]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    
    std::shared_ptr<Cvor> prva(nullptr), prethodna, nova;
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<13; j++) {
            nova=std::make_shared<Cvor>();
            nova->karta={Boje(i), karte[j]}; nova->sljedeci=nullptr;
            if (!prva) prva=nova;
            else prethodna->sljedeci=nova;
            prethodna=nova;
        }
    }
    prethodna->sljedeci=prva;
    return prva;
}

bool Nije_Kruzna (std::shared_ptr<Cvor> prva) {
    std::shared_ptr<Cvor> trenutna(prva); 
    for (int i=0; i<52; i++) {
        trenutna=trenutna->sljedeci;
        if (trenutna==nullptr) return true;
        if (trenutna==prva) return false;
    }
    return true;
}

bool Prije (Karta trenutna, Karta sljedeca) {
    const char* karte[13]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int trenutna_vrijednost, sljedeca_vrijednost;
    for (int i=0; i<13; i++) if (trenutna.vrijednost==karte[i]) trenutna_vrijednost=i;
    for (int i=0; i<13; i++) if (sljedeca.vrijednost==karte[i]) sljedeca_vrijednost=i;
    if ((trenutna.boja==sljedeca.boja && trenutna_vrijednost>sljedeca_vrijednost) || int(trenutna.boja)>int(sljedeca.boja)) return false;
    return true;
}

bool Nije_Sortirana (std::shared_ptr<Cvor> prva) {
    std::shared_ptr<Cvor> trenutna(prva);
    do {
        std::shared_ptr<Cvor> sljedeca(trenutna->sljedeci);
        if (sljedeca==prva) return false;
        if (trenutna->karta.boja==sljedeca->karta.boja && trenutna->karta.vrijednost==sljedeca->karta.vrijednost) return true;
        if (Prije(sljedeca->karta, trenutna->karta)) return true;
        
        trenutna=trenutna->sljedeci;
    } while (trenutna!=prva);
    return false;
}

bool Besmisleni (std::string naziv_boje, std::string vrijednost) {
    const char* karte[13]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    const char* boje[4]{"Pik", "Tref", "Herc", "Karo"};
    for (int i=0; i<4; i++) {
        for (int j=0; j<13; j++) {
            if (naziv_boje==boje[i] && vrijednost==karte[j]) return false;
        }
    }
    return true;
}

bool BesmislenaLista (std::shared_ptr<Cvor> prva) {
    const char* boje[4]{"Pik", "Tref", "Herc", "Karo"};
    if (Besmisleni(boje[int((*prva).karta.boja)], (*prva).karta.vrijednost)) return true;
    for (std::shared_ptr<Cvor> trenutna=prva->sljedeci; trenutna!=prva; trenutna=trenutna->sljedeci) if (Besmisleni(boje[int((*trenutna).karta.boja)], (*trenutna).karta.vrijednost)) return true;
    return false;
}

bool Neispravna (std::shared_ptr<Cvor> prva) {
    if (Nije_Kruzna(prva)) return true;
    if (BesmislenaLista(prva)) return true;
    if (Nije_Sortirana(prva)) return true;
    return false;
}

std::shared_ptr<Cvor> Obrisi (std::shared_ptr<Cvor> &prethodna, std::shared_ptr<Cvor> &trenutna) {
    prethodna->sljedeci=trenutna->sljedeci;
    trenutna->sljedeci=nullptr;
    trenutna=nullptr;
    return prethodna->sljedeci;
}

void IzbaciKarte (std::shared_ptr<Cvor> &prva, std::multimap<Boje, std::string> &multimapa) {
    if (prva==nullptr) return;
    if (Neispravna(prva)) throw std::logic_error("Neispravna lista!");
    
    for (auto it=multimapa.begin(); it!=multimapa.end(); it++) {
        
        std::shared_ptr<Cvor> zadnja(prva);
        while(zadnja->sljedeci!=prva) zadnja=zadnja->sljedeci;
        
        if ((*prva).karta.boja==(*it).first && (*prva).karta.vrijednost==(*it).second) {
            prva=Obrisi(zadnja, prva);
            if (prva==nullptr) return;
        }
        else {
            std::shared_ptr<Cvor> prethodna(prva);
            for (std::shared_ptr<Cvor> trenutna=prva->sljedeci; trenutna!=prva; trenutna=trenutna->sljedeci) {
                
                if (trenutna!=prva->sljedeci) prethodna=prethodna->sljedeci;
                if ((*trenutna).karta.boja==(*it).first && (*trenutna).karta.vrijednost==(*it).second) {
                    trenutna=Obrisi(prethodna, trenutna);
                    if (trenutna==nullptr) return;
                }
            }
        }
    }
    return;
}

std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem (std::shared_ptr<Cvor> &prva, const short int &korak_razbrajanja, int &broj_karata) {
    std::stack<std::pair<std::string, std::string>> red;
    if (prva==nullptr) return red;
    if (korak_razbrajanja<1 || korak_razbrajanja>52 || broj_karata<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if (Neispravna(prva)) throw std::logic_error("Neispravna lista!");
    
    int brojac(1), br_karata(broj_karata);
    const char* boje[4]{"Pik", "Tref", "Herc", "Karo"};
    std::shared_ptr<Cvor> trenutna(prva);
    std::shared_ptr<Cvor> prethodna(prva);
    while (prethodna->sljedeci!=trenutna) prethodna=prethodna->sljedeci;
    
    while (br_karata) {
        
        while (brojac!=korak_razbrajanja) { trenutna=trenutna->sljedeci; prethodna=prethodna->sljedeci; brojac++; }
        
        red.push(std::make_pair(boje[int((*trenutna).karta.boja)], (*trenutna).karta.vrijednost));
        if (trenutna==prva) {
            prva=Obrisi(prethodna, trenutna);
            if (prva==nullptr) return red;
            trenutna=prva;
            prethodna->sljedeci=prva;
        }
        else trenutna=Obrisi(prethodna, trenutna);
        if (trenutna==nullptr) return red;
        brojac=1;
        br_karata--;
    }
    return red;
}

bool BesmislenStek (std::stack<std::pair<std::string, std::string>> red) {
    
    while (!red.empty()) {
        if (Besmisleni(red.top().first, red.top().second)) return true;
        red.pop();
    }
    return false;
}

std::shared_ptr<Cvor> Ubaci (std::shared_ptr<Cvor> &prethodna, std::shared_ptr<Cvor> &trenutna, Karta karta) {
    std::shared_ptr<Cvor> nova=std::make_shared<Cvor>();
    nova->karta=karta; nova->sljedeci=trenutna;
    prethodna->sljedeci=nova;
    return nova;
}

void VratiPosljednjihNKarata (std::shared_ptr<Cvor> &prva, std::stack<std::pair<std::string, std::string>> &red, int n) {
    
    if (n<0) throw std::domain_error("Broj n je besmislen!");
    if (n>int(red.size())) throw std::range_error ("Nedovoljno karata u steku!");
    if (BesmislenStek(red)) throw std::logic_error("Neispravne karte!");
    if (n==0 || red.empty()) return;
    
    const char* boje[4]{"Pik", "Tref", "Herc", "Karo"};
    
    std::pair<std::string, std::string> karta(red.top());
    int redni_broj(0);
    for (int i=0; i<4; i++) if (karta.first==boje[i]) redni_broj=i;
    
    if (prva==nullptr) {
        prva=std::make_shared<Cvor>();
        prva->karta={Boje(redni_broj), karta.second};
        prva->sljedeci=prva;
        red.pop();
        n--;
    }
    
    while (n && red.size()) {
        
        std::shared_ptr<Cvor> trenutna(prva), prethodna(prva);
        while (prethodna->sljedeci!=prva) prethodna=prethodna->sljedeci;
        
        karta=red.top();
        for (int i=0; i<4; i++) if (karta.first==boje[i]) redni_broj=i;
        
        for (;;) {
            if (int((*trenutna).karta.boja)==redni_broj && (*trenutna).karta.vrijednost==karta.second) {
                red.pop();
                break;
            }
            else if (int((*prethodna).karta.boja)==redni_broj && (*prethodna).karta.vrijednost==karta.second) {
                red.pop();
                break;
            }
            else if ((int((*trenutna).karta.boja)==redni_broj && Prije({Boje(redni_broj), karta.second}, (*trenutna).karta)) || int((*trenutna).karta.boja)>redni_broj || (trenutna==prva && ((int((*prethodna).karta.boja)==redni_broj && Prije((*prethodna).karta, {Boje(redni_broj), karta.second})) || int((*prethodna).karta.boja)<redni_broj ))) {
                if (trenutna==prva && redni_broj<=int((*prva).karta.boja)) prva=Ubaci(prethodna, prva,  {Boje(redni_broj), karta.second});
                else trenutna=Ubaci(prethodna, trenutna, {Boje(redni_broj), karta.second});
                red.pop();
                n--;
                break;
            }
            trenutna=trenutna->sljedeci; prethodna=prethodna->sljedeci;
        }
    }
    return;
}

void Ispisi (std::shared_ptr<Cvor> prva) {
    const char* boje[4]{"Pik", "Tref", "Herc", "Karo"};
    
    for (int i=0; i<4; i++) {
        std::cout << std::endl << boje[i] << ": ";
        if (prva==nullptr) continue;
        if (int((*prva).karta.boja)==i) std::cout << (*prva).karta.vrijednost << " ";
        for (std::shared_ptr<Cvor> trenutna=prva->sljedeci; trenutna!=prva; trenutna=trenutna->sljedeci) {
            if (int((*trenutna).karta.boja)==i) std::cout << (*trenutna).karta.vrijednost << " ";
        }
    }
    std::cout << std::endl;
    return;
}

int main ()
{
    short int r;
    int n, b;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> b;
    std::shared_ptr<Cvor> prva;
    try {
        prva=KreirajSpil();
        std::stack<std::pair<std::string, std::string>> stek(IzbaciKarteRazbrajanjem(prva, r, b));
        std::cout << "U spilu trenutno ima " << 52-stek.size() << " karata, i to:";
        Ispisi(prva);
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> n;
        VratiPosljednjihNKarata(prva, stek, n);
        std::cout << "U spilu trenutno ima " << 52-stek.size() << " karata, i to:";
        Ispisi(prva);
        
        if (prva!=nullptr) {
            std::shared_ptr<Cvor> zadnja(prva);
            while(zadnja->sljedeci!=prva) zadnja=zadnja->sljedeci;
            zadnja->sljedeci=nullptr;
        }
        
    }
    catch (std::exception &izuzetak) {
        if (prva!=nullptr) {
            std::shared_ptr<Cvor> zadnja(prva);
            while(zadnja->sljedeci!=prva) zadnja=zadnja->sljedeci;
            zadnja->sljedeci=nullptr;
        }
        std::cout << "Izuzetak: " << izuzetak.what();
    }
    
	return 0;
}

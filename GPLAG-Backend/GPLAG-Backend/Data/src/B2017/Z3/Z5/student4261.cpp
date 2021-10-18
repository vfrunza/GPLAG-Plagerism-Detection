/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <utility>

enum class Boje {Pik, Tref, Herc, Karo};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor* sljedeci;
};

void UnistiSpil (Cvor* prva) {
    if (prva!=nullptr) {
        Cvor* zadnja(prva);
        while (zadnja->sljedeci!=prva) zadnja=zadnja->sljedeci;
        zadnja->sljedeci=nullptr;
        while (prva->sljedeci!=nullptr) {
            Cvor* temp(prva);
            prva=prva->sljedeci;
            temp->sljedeci=temp;
            delete temp;
        }
        delete prva;
    }
    return;
}


Cvor *KreirajSpil() {
    
    const char* karte[13]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    
    Cvor *prva(nullptr);
    Cvor *prethodna(nullptr);
    Cvor *nova(nullptr);
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<13; j++) {
            nova=new Cvor;
            nova->karta={Boje(i), karte[j]}; nova->sljedeci=nullptr;
            if (!prva) prva=nova;
            else prethodna->sljedeci=nova;
            prethodna=nova;
        }
    }
    prethodna->sljedeci=prva;
    return prva;
}

bool Nije_Kruzna (Cvor* prva) {
    Cvor* pomocni(prva);
    for (int i=0; i<52; i++) {
        pomocni=pomocni->sljedeci;
        if (pomocni==nullptr) return true;
        if (pomocni==prva) return false;
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

bool Nije_Sortirana (Cvor* prva) {
    Cvor* trenutna(prva);
    do {
        Cvor* sljedeca=trenutna->sljedeci;
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

bool BesmislenaLista (Cvor* prva) {
    const char* boje[4]{"Pik", "Tref", "Herc", "Karo"};
    if (Besmisleni(boje[int((*prva).karta.boja)], (*prva).karta.vrijednost)) return true;
    for (Cvor* trenutna=prva->sljedeci; trenutna!=prva; trenutna=trenutna->sljedeci) if (Besmisleni(boje[int((*trenutna).karta.boja)], (*trenutna).karta.vrijednost)) return true;
    return false;
}

bool Neispravna (Cvor* prva) {
    if (Nije_Kruzna(prva)) return true;
    if (BesmislenaLista(prva)) return true;
    if (Nije_Sortirana(prva)) return true;
    return false;
}

Cvor* Obrisi (Cvor* &prethodna, Cvor* &trenutna) {
    if (trenutna==prethodna) { delete trenutna; return nullptr; }
    prethodna->sljedeci=trenutna->sljedeci;
    trenutna->sljedeci=trenutna;
    delete trenutna;
    return prethodna->sljedeci;
}

void IzbaciKarte (Cvor* &prva, std::multimap<Boje, std::string> &multimapa) {
    if (prva==nullptr) return;
    if (Neispravna(prva)) throw std::logic_error("Neispravna lista!");
    
    for (auto it=multimapa.begin(); it!=multimapa.end(); it++) {
        
        Cvor* zadnja(prva);
        for (Cvor* trenutna=prva->sljedeci; trenutna!=prva; trenutna=trenutna->sljedeci) zadnja=trenutna;
        
        if ((*prva).karta.boja==(*it).first && (*prva).karta.vrijednost==(*it).second) {
            prva=Obrisi(zadnja, prva);
            if (prva==nullptr) return;
        }
        else {
            Cvor* prethodna(prva);
            for (Cvor* trenutna=prva->sljedeci; trenutna!=prva; trenutna=trenutna->sljedeci) {
                if (!(trenutna==prva->sljedeci)) prethodna=prethodna->sljedeci;
                if ((*trenutna).karta.boja==(*it).first && (*trenutna).karta.vrijednost==(*it).second) {
                    trenutna=Obrisi(prethodna, trenutna);
                    if (trenutna==nullptr) return;
                }
            }
        }
    }
    return;
} 

std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem (Cvor* &prva, const short int &korak_razbrajanja, int &broj_karata) {
    std::stack<std::pair<std::string, std::string>> red;
    if (prva==nullptr) return red;
    if (korak_razbrajanja<1 || korak_razbrajanja>52 || broj_karata<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if (Neispravna(prva)) throw std::logic_error("Neispravna lista!");
    
    int brojac(1), br_karata(broj_karata);
    const char* boje[4]{"Pik", "Tref", "Herc", "Karo"};
    Cvor* trenutna(prva);
    Cvor* prethodna(prva);
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

Cvor* Ubaci (Cvor* &prethodna, Cvor* &trenutna, Karta karta) {
    Cvor* nova=new Cvor;
    nova->karta=karta; nova->sljedeci=trenutna;
    prethodna->sljedeci=nova;
    return nova;
}

void VratiPosljednjihNKarata (Cvor* &prva, std::stack<std::pair<std::string, std::string>> &red, int n) {
    
    if (n<0) throw std::domain_error("Broj n je besmislen!");
    if (n>int(red.size())) throw std::range_error ("Nedovoljno karata u steku!");
    if (BesmislenStek(red)) throw std::logic_error("Neispravne karte!");
    if (n==0 || red.empty()) return;
    
    const char* boje[4]{"Pik", "Tref", "Herc", "Karo"};
    
    std::pair<std::string, std::string> karta(red.top());
    int redni_broj(0);
    for (int i=0; i<4; i++) if (karta.first==boje[i]) redni_broj=i;
    try {
        if (prva==nullptr) {
            prva=new Cvor({{Boje(redni_broj), karta.second}, nullptr});
            prva->sljedeci=prva;
            red.pop();
            n--;
        }
    }
    catch(...) {
        UnistiSpil(prva);
        return;
    }
    
    try {
    
        while (n && red.size()) {
            
            Cvor* trenutna(prva), *prethodna(prva);
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
    }
    catch(...) {
        UnistiSpil(prva);
        return;
    }
    return;
}


void Ispisi (Cvor* prva) {
    const char* boje[4]{"Pik", "Tref", "Herc", "Karo"};
    
    for (int i=0; i<4; i++) {
        std::cout << std::endl << boje[i] << ": ";
        if (prva==nullptr) continue;
        if (int((*prva).karta.boja)==i) std::cout << (*prva).karta.vrijednost << " ";
        for (Cvor* trenutna=prva->sljedeci; trenutna!=prva; trenutna=trenutna->sljedeci) {
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
    Cvor* prva;
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
        UnistiSpil(prva);
    }
    catch (std::exception &izuzetak) {
        UnistiSpil(prva);
        std::cout << "Izuzetak: " << izuzetak.what();
    }
    
	return 0;
}

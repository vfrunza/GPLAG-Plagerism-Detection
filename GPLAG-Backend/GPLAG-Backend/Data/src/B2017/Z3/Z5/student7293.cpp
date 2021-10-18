/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <utility>

enum class Boje {Pik, Tref, Herc, Karo};

typedef std::stack<std::pair<std::string, std::string>> StekParova;
typedef std::multimap<Boje, std::string> Multimapa;

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor *sljedeci;
};


void UnistiSpil(Cvor* pocetak) {
    if (pocetak==nullptr) return;
    
    Cvor* p=pocetak;
    p = p->sljedeci;
    if (p==pocetak) {
        delete pocetak;
        return;
    }
    pocetak->sljedeci = nullptr;
    
    while (p) {
        auto pok = p->sljedeci;
        delete p;
        p = nullptr;
        p = pok;
    }
}

int VelicinaSpila (Cvor* &Spil) {
    int br(0);
    for (auto *p=Spil;;) {
        br++;
        p = p->sljedeci;
        if (p==Spil) break;
    }
    return br;
}

Cvor* KreirajSpil () {                                                          // vraca pok na pocetak "cvora"
    std::vector<std::string> vr {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    Cvor *pocetak(nullptr), *prethodni;
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<vr.size(); j++) {
            Karta nova_karta;
            nova_karta.boja = Boje(i);
            nova_karta.vrijednost = vr.at(j);
            Cvor *novi (new Cvor);
            novi->karta = nova_karta;
            novi->sljedeci = nullptr;
            if (!pocetak) {
                pocetak = novi;
                prethodni = novi;
            }
            else if (i==3 && j==vr.size()-1) {                                  //kruzna lista
                prethodni->sljedeci = novi;
                novi->sljedeci = pocetak;
            }
            else {
                prethodni->sljedeci = novi;
                prethodni = novi;
            }
        }
    }
    return pocetak;
}

void IzbaciKarte (Cvor* &pocetak, Multimapa &m) {
    if (VelicinaSpila(pocetak)) {
        UnistiSpil(pocetak);
        throw std::logic_error ("Neispravna lista!");
    }
    for (auto *p = pocetak; p!=nullptr; p=p->sljedeci) {
        Karta temp = p->karta;
        for (auto it=m.begin(); it!=m.end(); it++) {
            if (temp.boja==it->first && temp.vrijednost==it->second) {
                auto pok = (p+1)->sljedeci;
                p = pok;
                m.erase(it);
                break;
            }
        }
        p--;
    }
}

StekParova IzbaciKarteRazbrajanjem (Cvor* &pocetak, const short int &r, const int &b) {
    if (r<1 || r>52 || b<1) { 
        UnistiSpil(pocetak);
        throw std::logic_error ("Neispravni elementi za izbacivanje!");
    }
    if (VelicinaSpila(pocetak)>52) {
        UnistiSpil(pocetak);
        throw std::logic_error ("Neispravna lista!");
    }
    StekParova stek;
    int br(0);
    for (auto *p=pocetak;;) {
        Karta trenutna = p->karta;
        short int pom(r);
        while (pom>1) {
            p=p->sljedeci;
            pom--;
        }
        
        std::string pom1;
        int prvi = int(trenutna.boja);
        if (prvi==0) pom1 = "Pik";
        else if (prvi==1) pom1 = "Tref";
        else if (prvi==2) pom1 = "Herc";
        else if (prvi==3) pom1 = "Karo";
        
        std::string pom2(trenutna.vrijednost);
        
        std::pair<std::string, std::string> par = std::make_pair(pom1, pom2);
        stek.push(par);
        auto tmp_p = p->sljedeci;
        
        p = tmp_p->sljedeci;
        delete tmp_p;
        //p = p->sljedeci;
        //if (VelicinaSpila(pocetak)==0) break;
        
        br++;
        if (br==0) break;
    }
    return stek;
}

void VratiPosljednjihNKarata (Cvor* &pocetak, StekParova &stek, int n) {
    if (n<1 || n>52) {
        UnistiSpil(pocetak);
        throw std::logic_error ("Broj n je besmislen");
    }
    if (stek.size()<n) {
        UnistiSpil(pocetak);
        throw std::range_error ("Nedovoljno karata u steku");
    }
}

int main ()
{
    /*Cvor* pocetak = KreirajSpil();
    for (auto *p=pocetak;;) {
        Karta pom = p->karta;
        std::cout << int(pom.boja) << " " << pom.vrijednost << std::endl;
        p = p->sljedeci;
        if (p==pocetak) break;
    }*/
    Cvor* Spil;
    try {
        Spil = KreirajSpil();                                                 // Spil je pok na prvu kartu u spilu
        int korak;
        std::cout << "Unesite korak razbrajanja: ";
        std::cin >> korak;
        int br_karata1;
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        std::cin >> br_karata1;
        StekParova stek = IzbaciKarteRazbrajanjem(Spil, korak, br_karata1);
        std::cout << "U spilu trenutno ima " << 52-br_karata1 << " karata, i to:" << std::endl;
        std::cout << "Pik: ";
        for (auto *p=Spil; ;) {
            Karta pom = p->karta;
            if (int(pom.boja)==0) std::cout << pom.vrijednost << " ";
            p = p->sljedeci;
            if (p==Spil) break;
        }
        std::cout << std::endl << "Tref: ";
        for (auto *p=Spil;;) {
            Karta pom = p->karta;
            if (int(pom.boja)==1) std::cout << pom.vrijednost << " ";
            p = p->sljedeci;
            if (p==Spil) break;
        }
        std::cout << std::endl << "Herc: ";
        for (auto *p=Spil;;) {
            Karta pom = p->karta;
            if (int(pom.boja)==2) std::cout << pom.vrijednost << " ";
            p = p->sljedeci;
            if (p==Spil) break;
        }
        std::cout << std::endl << "Karo: ";
        for (auto *p=Spil;;) {
            Karta pom = p->karta;
            if (int(pom.boja)==3) std::cout << pom.vrijednost << " ";
            p = p->sljedeci;
            if (p==Spil) break;
        }
        int br_karata2;
        std::cout << std::endl << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> br_karata2;
        std::cout << "U spilu trenutno ima " << 52-br_karata1+br_karata2 << " karata, i to:" << std::endl;
        VratiPosljednjihNKarata(Spil, stek, br_karata2);
        std::cout << "Pik: ";
        for (auto *p=Spil;;) {
            Karta pom = p->karta;
            if (int(pom.boja)==0) std::cout << pom.vrijednost << " ";
            p = p->sljedeci;
            if (p==Spil) break;
        }
        std::cout << std::endl << "Tref: ";
        for (auto *p=Spil;;) {
            Karta pom = p->karta;
            if (int(pom.boja)==1) std::cout << pom.vrijednost << " ";
            p = p->sljedeci;
            if (p==Spil) break;
        }
        std::cout << std::endl << "Herc: ";
        for (auto *p=Spil;;) {
            Karta pom = p->karta;
            if (int(pom.boja)==2) std::cout << pom.vrijednost << " ";
            p = p->sljedeci;
            if (p==Spil) break;
        }
        std::cout << std::endl << "Karo: ";
        for (auto *p=Spil;;) {
            Karta pom = p->karta;
            if (int(pom.boja)==3) std::cout << pom.vrijednost << " ";
            p = p->sljedeci;
            if (p==Spil) break;
        }
        //UnistiSpil(Spil);
    }
    catch (std::bad_alloc) {
        std::cout << "Greska u memoriji" << std::endl;
    }
    catch (std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
    UnistiSpil(Spil);
	return 0;
}
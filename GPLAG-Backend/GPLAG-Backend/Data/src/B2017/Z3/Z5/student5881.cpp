/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <stdexcept>
#include <stack>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor *sljedeci;
};

const std::string imena[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

void UnistiSpil(Cvor* pocetak)
{
    if (!pocetak)
        return;
    Cvor *p(pocetak);
    p = p->sljedeci;
    if (p==pocetak) {
        delete p;
        return;
    }
    pocetak->sljedeci=nullptr;
    for (; p!=nullptr;) {
        Cvor *temp(p);
        p = p->sljedeci;
        delete temp;
    }
}

Cvor* KreirajSpil()
{
    Cvor *pocetak(nullptr), *prethodni;
    for (int i = 0; i < 4; i++) {
        Boje boja;
        if (i==0)
            boja=Boje::Pik;
        else if (i==1)
            boja=Boje::Tref;
        else if (i==2)
            boja=Boje::Herc;
        else
            boja=Boje::Karo;
        for (int br=0; br!=13; br++) {
            Cvor *novi(nullptr);
            try {
                novi=new Cvor {{boja, imena[br]}, nullptr}; // Kreiranje novog čvora
            } catch (...) {
                UnistiSpil(pocetak);
                throw;
            }
            if(!pocetak) pocetak = novi; // Prvi čvor...
            else prethodni->sljedeci = novi; // Svi osim prvog...
            prethodni = novi;
        }
    }
    prethodni->sljedeci=pocetak;
    return pocetak;
}

int BrojKarti(Cvor *pocetak)
{
    int br(0);
    if (!pocetak)
        return br;
    Karta prva(pocetak->karta);
    br++;
    Cvor *p(pocetak);
    p = p->sljedeci;
    for(; p!=pocetak ; p = p->sljedeci)
        br++;
    return br;
}


bool SpilValja(Cvor *pocetak)
{
    if (BrojKarti(pocetak)>52)
        return false;
    if (!pocetak)
        return true;
    auto p(pocetak);
    if (p->karta.boja!=Boje::Pik && p->karta.boja!=Boje::Tref && p->karta.boja!=Boje::Herc && p->karta.boja!=Boje::Karo)
        return false;
    int i(0);
    for (; i < 13; i++)
        if (p->karta.vrijednost==imena[i])
            break;
    if (i==13)
        return false;
    p = p->sljedeci;
    for (; p!=pocetak; p = p->sljedeci) {
        if (p->karta.boja!=Boje::Pik && p->karta.boja!=Boje::Tref && p->karta.boja!=Boje::Herc && p->karta.boja!=Boje::Karo)
            return false;
        for (i=0; i < 13; i++)
            if (p->karta.vrijednost==imena[i])
                break;
        if (i==13)
            return false;
    }
    if (BrojKarti(pocetak)<=1)
        return true;
    p=pocetak;
    auto prethodni(p);
    Boje pocetna_boja(p->karta.boja);
    Boje sljedeca_boja(Boje::Karo);
    if (pocetna_boja==Boje::Pik)
        sljedeca_boja=Boje::Tref;
    else if (pocetna_boja==Boje::Tref)
        sljedeca_boja=Boje::Herc;
    else if (pocetna_boja==Boje::Herc)
        sljedeca_boja=Boje::Karo;
    int pocetni_indeks(0);
    for (i = 0; i < 13; i++) {
        if (prethodni->karta.vrijednost==imena[i]) {
            pocetni_indeks=i;
            break;
        }
    }
    p = p->sljedeci;
    for (; p!=pocetak; p=p->sljedeci) {
        if (p->karta.boja!=prethodni->karta.boja) {
            if (p->karta.boja!=sljedeca_boja)
                return false;

            pocetna_boja=p->karta.boja;
            sljedeca_boja=Boje::Karo;
            if (pocetna_boja==Boje::Pik)
                sljedeca_boja=Boje::Tref;
            else if (pocetna_boja==Boje::Tref)
                sljedeca_boja=Boje::Herc;
            else if (pocetna_boja==Boje::Herc)
                sljedeca_boja=Boje::Karo;
            pocetni_indeks=0;
        } else {
            int sljedeci_indeks(0);
            for (i = 0; i < 13; i++) {
                if (p->karta.vrijednost==imena[i]) {
                    sljedeci_indeks=i;
                    break;
                }
            }
            if (pocetni_indeks>=sljedeci_indeks)
                return false;
            pocetni_indeks=sljedeci_indeks;
        }
        prethodni=prethodni->sljedeci;
    }

    return true;
}


void IzbaciKarte(Cvor *&pocetak, std::multimap<Boje, std::string> &karte)
{
    if (!SpilValja(pocetak))
        throw std::logic_error("Neispravna lista!");
    if (!pocetak)
        return;
    auto p(pocetak);
    auto prethodni(pocetak);
    p = p->sljedeci;
    bool izbrisao(false);
    for(int jos_jedan(0); jos_jedan!=1; jos_jedan++) {
        for (; ; p = p->sljedeci) {
            for (auto it2(karte.begin()); it2 != karte.end(); it2++) {
                if (p->karta.boja==it2->first && p->karta.vrijednost==it2->second) {
                    if (BrojKarti(pocetak)==1) {
                        delete p;
                        pocetak=nullptr;
                        it2=karte.erase(it2);
                        return;
                    } else {
                        prethodni->sljedeci=p->sljedeci;
                        if (p==pocetak)
                            pocetak=prethodni->sljedeci;
                        delete p;
                        p=prethodni;
                        izbrisao=true;
                        it2=karte.erase(it2);
                        if (it2==karte.begin())
                            break;
                    }
                }
            }
            if (p==pocetak || jos_jedan==1) {
                if (izbrisao) {
                    izbrisao=false;
                    continue;
                }
                break;
            }
            if (!izbrisao)
                prethodni=prethodni->sljedeci;
            else
                izbrisao=false;
        }
    }
}



std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Cvor *&pocetak, short int &r, const int &b)
{
    std::stack<std::pair<std::string, std::string>> rez;
    if (r<1 || r>52 || b<1)
        throw std::logic_error("Neispravni elementi za izbacivanje!");
    if (!SpilValja(pocetak))
        throw std::logic_error("Neispravna lista!");
    if (!pocetak)
        return rez;
    int br(1), br_izbacenih(0);
    auto p(pocetak);
    auto prethodni(pocetak);
    while (prethodni->sljedeci!=pocetak)
        prethodni=prethodni->sljedeci;
    bool izbrisao(false);
    for (; ; p = p->sljedeci) {
        if (br==r) {
            switch (p->karta.boja) {
            case Boje::Pik :
                rez.push(std::make_pair("Pik", p->karta.vrijednost));
                break;
            case Boje::Tref :
                rez.push(std::make_pair("Tref", p->karta.vrijednost));
                break;
            case Boje::Herc :
                rez.push(std::make_pair("Herc", p->karta.vrijednost));
                break;
            case Boje::Karo :
                rez.push(std::make_pair("Karo", p->karta.vrijednost));
                break;
            }
            if (BrojKarti(pocetak)==1) {
                delete p;
                pocetak=nullptr;
                return rez;
            } else {
                prethodni->sljedeci=p->sljedeci;
                if (p==pocetak)
                    pocetak=prethodni->sljedeci;
                delete p;
                p=prethodni;
                izbrisao=true;
            }
            br_izbacenih++;
            if (br_izbacenih==b)
                break;
            br=0;
        }
        br++;
        if (!izbrisao)
            prethodni=prethodni->sljedeci;
        else
            izbrisao=false;
    }
    return rez;
}


bool StekValja(std::stack<std::pair<std::string, std::string>> red)
{
    while(!red.empty()) {
        if (red.top().first!="Pik" && red.top().first!="Tref" && red.top().first!="Herc" && red.top().first!="Karo")
            return false;
        int i(0);
        for (; i < 13; i++)
            if (red.top().second==imena[i])
                break;
        if (i==13)
            return false;
        red.pop();
    }
    return true;
}


void IspisiSpil(Cvor *pocetak)
{
    std::cout << "U spilu trenutno ima " << BrojKarti(pocetak) << " karata, i to: " << std::endl;
    if (BrojKarti(pocetak)==0) {
        std::cout << "Pik:" << std::endl << "Tref:" << std::endl << "Herc:" << std::endl << "Karo:" << std::endl;
        return;
    }
    Karta prva(pocetak->karta);
    for (int i = 0; i < 4; i++) {
        bool sami_pocetak(true);
        Cvor *p(pocetak);
        bool sljedeci(false);
        Boje boja;
        if (i==0) {
            std::cout << "Pik:";
            boja=Boje::Pik;
        } else if (i==1) {
            std::cout << "Tref:";
            boja=Boje::Tref;
        } else if (i==2) {
            std::cout << "Herc:";
            boja=Boje::Herc;
        } else {
            std::cout << "Karo:";
            boja=Boje::Karo;
        }
        for (; sami_pocetak || p!=pocetak ; p = p->sljedeci) {
            sami_pocetak=false;
            if (p->karta.boja==boja) {
                std::cout << " " << p->karta.vrijednost;
                sljedeci=true;
            } else if (sljedeci)
                break;
        }
        std::cout << std::endl;
    }
}


void VratiPosljednjihNKarata(Cvor *&pocetak, std::stack<std::pair<std::string, std::string>> &red, int n)
{
    if (n<0)
        throw std::domain_error("Broj n je besmislen!");
    if (n>red.size())
        throw std::range_error("Nedovoljno karata u steku!");
    if (!StekValja(red))
        throw std::logic_error("Neispravne karte!");
    if (!SpilValja(pocetak))
        throw std::logic_error("Neispravna lista!");

    while(n!=0) {
        Boje b(Boje::Pik);
        if (red.top().first=="Tref")
            b=Boje::Tref;
        else if (red.top().first=="Herc")
            b=Boje::Herc;
        else if (red.top().first=="Karo")
            b=Boje::Karo;
        if (!pocetak) {
            try {
                pocetak = new Cvor {{b, red.top().second}, nullptr}; // Kreiranje novog čvora
            } catch (...) {
                UnistiSpil(pocetak);
                throw;
            }
            pocetak->sljedeci=pocetak;
            continue;
        }


        auto p(pocetak);
        int br(BrojKarti(pocetak));
        while (p->karta.boja!=b) { 
            p = p->sljedeci;
            br--;
            if (br==0)
                break;
        }
        if (br==0 && b==Boje::Pik)
            p = pocetak;
        else if (br==0) {
            if (b==Boje::Tref) {
                br=BrojKarti(pocetak);
                p=pocetak;
                while (p->karta.boja==Boje::Pik) {
                    p = p->sljedeci;
                    br--;
                    if (br==0)
                        break;
                }
                if (br==0)
                    p=pocetak;
            } else if (b==Boje::Herc) {
                br=BrojKarti(pocetak);
                p=pocetak;
                while (p->karta.boja==Boje::Tref || p->karta.boja==Boje::Pik) {
                    p = p->sljedeci;
                    br--;
                    if (br==0)
                        break;
                }
                if (br==0)
                    p=pocetak;
            } else if (b==Boje::Karo) {
                br=BrojKarti(pocetak);
                p=pocetak;
                while (p->karta.boja==Boje::Herc || p->karta.boja==Boje::Tref || p->karta.boja==Boje::Pik) {
                    p = p->sljedeci;
                    br--;
                    if (br==0)
                        break;
                }
                if (br==0)
                    p=pocetak;
            }
        }
        
        int j(0), k(0);
        for (; j < 13; j++)
            if (red.top().second==imena[j])
                break;
        auto prethodni(p);
        while (prethodni->sljedeci!=p)
            prethodni=prethodni->sljedeci;
        do {
            for (; k < 13; k++)
                if (p->karta.vrijednost==imena[k])
                    break;
            if (k>=j) {
                if (p->karta.boja==b && p->karta.vrijednost==red.top().second)
                    break;
                Cvor *novi(nullptr);
                try {
                    novi=new Cvor {{b, red.top().second}, nullptr}; // Kreiranje novog čvora
                } catch (...) {
                    UnistiSpil(pocetak);
                    throw;
                }
                novi->sljedeci=p;
                prethodni->sljedeci=novi;
                if (p==pocetak)
                    pocetak=novi;
                break;
            }
            prethodni=p;
            p = p->sljedeci;
            if (BrojKarti(pocetak)==1 || p->karta.boja!=b) {
                Cvor *novi(nullptr);
                try {
                    novi=new Cvor {{b, red.top().second}, nullptr}; // Kreiranje novog čvora
                } catch (...) {
                    UnistiSpil(pocetak);
                    throw;
                }
                
                if (prethodni==pocetak) {
                    novi->sljedeci=prethodni;
                    auto preprethodni(prethodni);
                    while (preprethodni->sljedeci!=prethodni)
                        preprethodni=preprethodni->sljedeci;
                    preprethodni->sljedeci=novi;
                    break;
                }
                
                novi->sljedeci=p;
                prethodni->sljedeci=novi;
                break;
            }
        } while (true);
        red.pop();
        n--;
    }

}


int main ()
{
    auto spil(KreirajSpil());
    short int r;
    int b;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> b;
    std::stack<std::pair<std::string, std::string>> red;
    try {
        red=IzbaciKarteRazbrajanjem(spil, r ,b);
    } catch (const std::exception &greska) {
        std::cout << "Izuzetak: " << greska.what();
        UnistiSpil(spil);
        return 0;
    }

    IspisiSpil(spil);
    int n;
    std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
    std::cin >> n;
    try {
        VratiPosljednjihNKarata(spil, red, n);
    } catch (const std::exception &greska) {
        std::cout << "Izuzetak: " << greska.what();
        UnistiSpil(spil);
        return 0;
    }
    IspisiSpil(spil);
    UnistiSpil(spil);
    return 0;
}

#include <iostream>
#include <list>
#include <map>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
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

int Pretvaranje (std::string s)
{
    int y;
    if (s=="2") y=2;
    if (s=="3") y=3;
    if (s=="4") y=4;
    if (s=="5") y=5;
    if (s=="6") y=6;
    if (s=="7") y=7;
    if (s=="8") y=8;
    if (s=="9") y=9;
    if (s=="10") y=10;
    if (s=="J") y=11;
    if (s=="Q") y=12;
    if (s=="K") y=13;
    if (s=="A") y=14;
    return y;
}

bool Ispravan (Cvor *&pocetak)
{
    std::vector<std::string> karte {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    auto p(pocetak);
    if (!pocetak) return true;
    do {
        for (int i=0; i<karte.size(); i++) {
            if (p->karta.vrijednost==karte.at(i)) {
                p=p->sljedeci;
                break;
            }
            if (i==karte.size()-1) return false;
        }
    } while (p!=pocetak);
    return true;
}

bool IspravnoSortiran (Cvor *&pocetak)
{
    auto p(pocetak);
    if (!pocetak) return true;
    p=p->sljedeci;
    while (p!=pocetak) {
        auto pom(pocetak);
        while (pom!=p) {
            if (pom->karta.boja<p->karta.boja) pom=pom->sljedeci;
            else if (pom->karta.boja==p->karta.boja) {
                int x,y;
                x=Pretvaranje(pom->karta.vrijednost);
                y=Pretvaranje(p->karta.vrijednost);
                if (x<y) pom=pom->sljedeci;
                else if (x>y || x==y) return false;
            } else if (pom->karta.boja>p->karta.boja) return false;
        }
        p=p->sljedeci;
    }
    return true;
}

void IzbaciJednu (Cvor *&pocetak,Cvor *&prethodni,Cvor *&p)
{
    if (p == pocetak) {
        prethodni=pocetak;
        while (prethodni -> sljedeci != pocetak)
            prethodni = prethodni -> sljedeci;
        pocetak = p->sljedeci;
        prethodni->sljedeci = pocetak;
        auto a=p;
        p=p->sljedeci;
        delete a;
    } else {
        prethodni->sljedeci = p->sljedeci;
        auto a=p;
        p=p->sljedeci;
        delete a;
    }
}

Cvor *KreirajSpil()
{
    Cvor *pocetak(nullptr), *prethodni;
    std::vector<std::string> karte {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int j(0);
    for (int i=0; i<52; i++) {
        Karta k;
        if (j==13) j=0;
        k.vrijednost=karte.at(j);
        if (i<13) k.boja=Boje::Pik;
        if (i>=13 && i<26) k.boja=Boje::Tref;
        if (i>=26 && i<39) k.boja=Boje::Herc;
        if (i>=39 && i<52) k.boja=Boje::Karo;
        Cvor *novi (new Cvor {k, pocetak});
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci = novi;
        prethodni=novi;
        j++;
    }
    return pocetak;
}

void IzbaciKarte (Cvor *&pocetak, std::multimap<Boje, std::string> &karte)
{
    auto ispravan(Ispravan(pocetak));
    if (ispravan==false) throw std::logic_error ("Neispravna lista!");
    auto sortiran(IspravnoSortiran(pocetak));
    if (sortiran==false) throw std::logic_error ("Neispravna lista!");
    Cvor *p=pocetak;
    auto pomocna(pocetak);
    int brojac(0);
    do {
        brojac++;
    } while (pomocna!=pocetak);
    if (brojac>52) throw std::logic_error ("Neispravna lista!");
    Cvor *prethodni(pocetak);
    while (prethodni->sljedeci!=pocetak) {
        prethodni=prethodni->sljedeci;
    }
    do {
        for (auto it2(karte.begin()); it2!=karte.end(); it2++) {
            if (p->karta.boja==it2->first && p->karta.vrijednost==it2->second) {
                if (pocetak->sljedeci==pocetak) {
                    pocetak = nullptr;
                    delete p;
                    break;
                }
                IzbaciJednu(pocetak,prethodni,p);
            }
        }
        if (pocetak==nullptr) break;
        prethodni=p;
        p=p->sljedeci;
    } while (p!=pocetak);
}

std::stack<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem (Cvor *&pocetak,const short int &korak,const int &broj)
{
    if (korak<1 || korak>52 || broj<1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    auto ispravan(Ispravan(pocetak));
    if (ispravan==false) throw std::logic_error ("Neispravna lista!");
    auto sortiran(IspravnoSortiran(pocetak));
    if (sortiran==false) throw std::logic_error ("Neispravna lista!");
    Cvor *p=pocetak;
    auto pomocna(pocetak);
    int brojanje(0);
    do {
        brojanje++;
    } while (pomocna!=pocetak);
    if (brojanje>52) throw std::logic_error ("Neispravna lista!");
    std::stack<std::pair<std::string,std::string>> izbacene;
    int brojac(0);
    int i(1),prolaz(0);
    Cvor *prethodni(pocetak);
    while (prethodni->sljedeci!=pocetak) {
        prethodni=prethodni->sljedeci;
    }
    while (brojac!=broj) {
        while (i!=korak  ) {
            i++;
            prethodni=p;
            p=p->sljedeci;
        }
        if (i==korak) {
            if (p->karta.boja==Boje::Pik) izbacene.push({"Pik",p->karta.vrijednost});
            else if (p->karta.boja==Boje::Tref) izbacene.push({"Tref",p->karta.vrijednost});
            else if (p->karta.boja==Boje::Herc) izbacene.push({"Herc",p->karta.vrijednost});
            else if (p->karta.boja==Boje::Karo) izbacene.push({"Karo",p->karta.vrijednost});
            brojac++;
            if (pocetak->sljedeci==pocetak) {
                pocetak = nullptr;
                delete p;
                return izbacene;
            }
            IzbaciJednu(pocetak,prethodni,p);
        }
        prethodni=p;
        i=1;
        prolaz++;
        if (brojac==broj) break;
    }
    return izbacene;
}

void VratiPosljednjihNKarata (Cvor *&pocetak, std::stack<std::pair<std::string,std::string>> &bacene, int n)
{
    if (n!=int(n) || n<0) throw std::domain_error ("Broj n je besmislen!");
    if (n>bacene.size()) throw std::range_error ("Nedovoljno karata u steku!");
    auto ispravan(Ispravan(pocetak));
    if (ispravan==false) throw std::logic_error ("Neispravna lista!");
    auto sortiran(IspravnoSortiran(pocetak));
    if (sortiran==false) throw std::logic_error ("Neispravna lista!");
    auto pomocna(pocetak);
    int brojanje(0);
    Karta k;
    do {
        brojanje++;
    } while (pomocna!=pocetak);
    if (brojanje>52) throw std::logic_error ("Neispravna lista!");
    int brojac(0);
    while (brojac!=n) {
        Cvor *p=pocetak, *prethodni;
        if(!pocetak) {
            if (bacene.top().first=="Pik")
                k.boja=Boje::Pik;
            if (bacene.top().first=="Tref")
                k.boja=Boje::Tref;
            if (bacene.top().first=="Herc")
                k.boja=Boje::Herc;
            if (bacene.top().first=="Karo")
                k.boja=Boje::Karo;
            k.vrijednost=bacene.top().second;
            Cvor *novi (new Cvor {k, nullptr});
            pocetak=novi;
            pocetak->sljedeci=pocetak;
            bacene.pop();
            brojac++;
            continue;
        } else if (pocetak->sljedeci==pocetak) {
            if (bacene.top().first=="Pik")
                k.boja=Boje::Pik;
            if (bacene.top().first=="Tref")
                k.boja=Boje::Tref;
            if (bacene.top().first=="Herc")
                k.boja=Boje::Herc;
            if (bacene.top().first=="Karo")
                k.boja=Boje::Karo;
            k.vrijednost=bacene.top().second;
            Cvor *novi (new Cvor {k, pocetak});
            if (k.boja<p->karta.boja)  {
                prethodni=novi;
                pocetak=prethodni;
            } else if (k.boja>p->karta.boja) {
                pocetak->sljedeci=novi;
                p=novi;
            } else {
                if (Pretvaranje(k.vrijednost)<Pretvaranje(p->karta.vrijednost)) {
                    prethodni=novi;
                    pocetak=prethodni;
                } else if (Pretvaranje(k.vrijednost)>Pretvaranje(p->karta.vrijednost)) {
                    pocetak->sljedeci=novi;
                    p=novi;
                }
            }
            bacene.pop();
            brojac++;
            continue;
        } else {
            for(prethodni=pocetak; prethodni->sljedeci!=pocetak; prethodni=prethodni->sljedeci);
        }
        int x,y;
        y=Pretvaranje(bacene.top().second);
        x=Pretvaranje(p->karta.vrijednost);
        if (bacene.top().first=="Pik") {
            while (p->karta.boja==Boje::Pik && x<=y) {
                prethodni=prethodni->sljedeci;
                p=p->sljedeci;
                x=Pretvaranje(p->karta.vrijednost);
            }
        } else if (bacene.top().first=="Tref") {
            while (p->karta.boja==Boje::Pik) {
                prethodni=prethodni->sljedeci;
                p=p->sljedeci;
                x=Pretvaranje(p->karta.vrijednost);
            }
            while (p->karta.boja==Boje::Tref && x<=y) {
                prethodni=prethodni->sljedeci;
                p=p->sljedeci;
                x=Pretvaranje(p->karta.vrijednost);
            }
        } else if (bacene.top().first=="Herc") {
            while (p->karta.boja==Boje::Pik) {
                prethodni=prethodni->sljedeci;
                p=p->sljedeci;
                x=Pretvaranje(p->karta.vrijednost);
            }
            while (p->karta.boja==Boje::Tref) {
                prethodni=prethodni->sljedeci;
                p=p->sljedeci;
                x=Pretvaranje(p->karta.vrijednost);
            }
            while (p->karta.boja==Boje::Herc && x<=y) {
                prethodni=prethodni->sljedeci;
                p=p->sljedeci;
                x=Pretvaranje(p->karta.vrijednost);
            }
        } else if (bacene.top().first=="Karo") {
            while (p->karta.boja==Boje::Pik) {
                prethodni=prethodni->sljedeci;
                p=p->sljedeci;
                x=Pretvaranje(p->karta.vrijednost);
            }
            while (p->karta.boja==Boje::Tref) {
                prethodni=prethodni->sljedeci;
                p=p->sljedeci;
                x=Pretvaranje(p->karta.vrijednost);
            }
            while (p->karta.boja==Boje::Herc) {
                prethodni=prethodni->sljedeci;
                p=p->sljedeci;
                x=Pretvaranje(p->karta.vrijednost);
            }
            while (p->karta.boja==Boje::Karo && x<=y) {
                prethodni=prethodni->sljedeci;
                p=p->sljedeci;
                x=Pretvaranje(p->karta.vrijednost);
            }
        }
        if (bacene.top().first=="Pik")
            k.boja=Boje::Pik;
        if (bacene.top().first=="Tref")
            k.boja=Boje::Tref;
        if (bacene.top().first=="Herc")
            k.boja=Boje::Herc;
        if (bacene.top().first=="Karo")
            k.boja=Boje::Karo;
        k.vrijednost=bacene.top().second;
        Cvor *novi (new Cvor {k, p});
        prethodni->sljedeci=novi;
        if(p==pocetak && (novi->karta.boja<p->karta.boja || (novi->karta.boja==p->karta.boja && Pretvaranje(novi->karta.vrijednost)<Pretvaranje(p->karta.vrijednost)))) {
            pocetak=novi;
        }
        p=novi;

        bacene.pop();
        brojac++;
        if (brojac==n) break;
    }
}

void UnistiSpil (Cvor *pocetak)
{
    if (pocetak!=nullptr) {
        Cvor *prethodni(nullptr);
        Cvor *p;
        for(p=pocetak; p->sljedeci!=pocetak; p=p->sljedeci) {
            delete prethodni;
            prethodni=p;
        }
        delete prethodni;
        delete p;
    }
}

void IspisiSpil (Cvor *pocetak)
{
    int brojac(1);
    int brojac2(0);
    if (pocetak!=nullptr)
        for (Cvor *p=pocetak; p->sljedeci!=pocetak; p=p->sljedeci) brojac++;
    std::cout<<"Pik: ";
    if (pocetak!=nullptr)
        while (pocetak->karta.boja==Boje::Pik && brojac2!=brojac) {
            std::cout<<pocetak->karta.vrijednost<<" ";
            pocetak=pocetak->sljedeci;
            brojac2++;
        }
    std::cout<<std::endl<<"Tref: ";
    if (pocetak!=nullptr)
        while (pocetak->karta.boja==Boje::Tref && brojac2!=brojac) {
            std::cout<<pocetak->karta.vrijednost<<" ";
            pocetak=pocetak->sljedeci;
            brojac2++;
        }
    std::cout<<std::endl<<"Herc: ";
    if (pocetak!=nullptr)
        while (pocetak->karta.boja==Boje::Herc && brojac2!=brojac) {
            std::cout<<pocetak->karta.vrijednost<<" ";
            pocetak=pocetak->sljedeci;
            brojac2++;
        }
    std::cout<<std::endl<<"Karo: ";
    if (pocetak!=nullptr) {
        while (pocetak->karta.boja==Boje::Karo && brojac2!=brojac) {
            std::cout<<pocetak->karta.vrijednost<<" ";
            pocetak=pocetak->sljedeci;
            brojac2++;
        }
    }

}

int main ()
{
    auto pocetak (KreirajSpil());
    try {
        short int n;
        int r;
        std::cout<<"Unesite korak razbrajanja: ";
        std::cin>>n;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>r;
        std::stack<std::pair<std::string,std::string>> izbacene(IzbaciKarteRazbrajanjem(pocetak,n,r));
        Cvor *p;
        int brojac(1);
        if (pocetak!=nullptr) for (p=pocetak; p->sljedeci!=pocetak; p=p->sljedeci) brojac++;
        else brojac=0;
        std::cout<<"U spilu trenutno ima "<<brojac<<" karata, i to: "<<std::endl;
        IspisiSpil(pocetak);
        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int m;
        std::cin>>m;
        VratiPosljednjihNKarata(pocetak,izbacene,m);
        int brojac2(1);
        for(p=pocetak; p->sljedeci!=pocetak; p=p->sljedeci) brojac2++;
        std::cout<<"U spilu trenutno ima "<<brojac2<<" karata, i to: "<<std::endl;
        IspisiSpil(pocetak);
        UnistiSpil(pocetak);
    } catch (std::domain_error l) {
        std::cout<<"Izuzetak: "<<l.what();
        UnistiSpil(pocetak);
    } catch (std::logic_error r) {
        std::cout<<"Izuzetak: "<<r.what();
        UnistiSpil(pocetak);
    } catch (std::range_error d) {
        std::cout<<"Izuzetak: "<<d.what();
        UnistiSpil(pocetak);
    }
    return 0;
}

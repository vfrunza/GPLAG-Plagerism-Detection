/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <stdexcept>
#include <map>
#include <queue>
#include <algorithm>

enum class Boje
{
    Pik,Tref,Herc,Karo
};

std::list<std::pair<Boje,std::string>> KreirajSpil()
{
    std::list<std::pair<Boje,std::string>> spil {{Boje::Pik,"2"},{Boje::Pik,"3"},{Boje::Pik,"4"},{Boje::Pik,"5"},{Boje::Pik,"6"},{Boje::Pik,"7"},{Boje::Pik,"8"},{Boje::Pik,"9"},{Boje::Pik,"10"},{Boje::Pik,"J"},{Boje::Pik,"Q"},{Boje::Pik,"K"},{Boje::Pik,"A"},
        {Boje::Tref,"2"},{Boje::Tref,"3"},{Boje::Tref,"4"},{Boje::Tref,"5"},{Boje::Tref,"6"},{Boje::Tref,"7"},{Boje::Tref,"8"},{Boje::Tref,"9"},{Boje::Tref,"10"},{Boje::Tref,"J"},{Boje::Tref,"Q"},{Boje::Tref,"K"},{Boje::Tref,"A"},
        {Boje::Herc,"2"},{Boje::Herc,"3"},{Boje::Herc,"4"},{Boje::Herc,"5"},{Boje::Herc,"6"},{Boje::Herc,"7"},{Boje::Herc,"8"},{Boje::Herc,"9"},{Boje::Herc,"10"},{Boje::Herc,"J"},{Boje::Herc,"Q"},{Boje::Herc,"K"},{Boje::Herc,"A"},
        {Boje::Karo,"2"},{Boje::Karo,"3"},{Boje::Karo,"4"},{Boje::Karo,"5"},{Boje::Karo,"6"},{Boje::Karo,"7"},{Boje::Karo,"8"},{Boje::Karo,"9"},{Boje::Karo,"10"},{Boje::Karo,"J"},{Boje::Karo,"Q"},{Boje::Karo,"K"},{Boje::Karo,"A"}
    };

    return spil;
}

void IzbaciKarte(std::list<std::pair<Boje,std::string>> &spil,std::multimap<Boje, std::string> &multimapa)
{
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    auto pocetakliste1(spil.begin());
    auto izakrajaliste1(spil.end());
    while(pocetakliste1!=izakrajaliste1) {
        pocetakliste1++;
        auto pom(pocetakliste1);
        pocetakliste1--;
        if(!(pocetakliste1->first==Boje::Pik or pocetakliste1->first==Boje::Tref or pocetakliste1->first==Boje::Herc or pocetakliste1->first==Boje::Karo))
            throw std::logic_error("Neispravna lista!");
        if(int(pocetakliste1->first) > int(pom->first)) throw std::logic_error("Neispravna lista!");
    }
    pocetakliste1=spil.begin();
    /*    while(pocetakliste1!=izakrajaliste){
            if(!(pocetakliste1->second=="2" or pocetakliste1->second=="3")
        }
    */
    auto pocetakliste(spil.begin());
    auto izakrajaliste(spil.end());
    while(pocetakliste!=izakrajaliste) {
        auto pocetakmultimape(multimapa.begin());
        auto krajmultimape(multimapa.end());
        while(pocetakmultimape!=krajmultimape) {
            if(pocetakmultimape->first==pocetakliste->first and pocetakmultimape->second==pocetakliste->second) {
                pocetakliste=spil.erase(pocetakliste);
                pocetakmultimape=multimapa.erase(pocetakmultimape);
                pocetakliste--;
                break;
            }
            pocetakmultimape++;
        }
        pocetakliste++;
    }
}

std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &spil,short int &r,int &b)
{
    //Bacanje izuzetaka
    if(r<1 or r>52 or b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    auto pocetakliste1(spil.begin());
    auto izakrajaliste1(spil.end());
    while (pocetakliste1!=izakrajaliste1) {
        pocetakliste1++;
        auto pom(pocetakliste1);
        pocetakliste1--;
        if(!(pocetakliste1->first==Boje::Pik or pocetakliste1->first==Boje::Tref or  pocetakliste1->first==Boje::Herc or pocetakliste1->first==Boje::Karo))
            throw std::logic_error("Neispravna lista!");
        if(int(pocetakliste1->first) > int(pom->first)) throw std::logic_error("Neispravna lista!");
        if(!(pocetakliste1->second=="2" or pocetakliste1->second=="3" or pocetakliste1->second=="4" or pocetakliste1->second=="5" or pocetakliste1->second=="6" or
                pocetakliste1->second=="7" or pocetakliste1->second=="8" or pocetakliste1->second=="9" or pocetakliste1->second=="10"
                or pocetakliste1->second=="J" or pocetakliste1->second=="Q" or pocetakliste1->second=="K" or  pocetakliste1->second=="A"))throw std::logic_error("Neispravna lista!");
        //jos trebam za pogresno sortirano pocetakliste1-second
        pocetakliste1++;
    }
    //Obrada funkcije
    std::queue<std::pair<std::string,std::string>> red;
    auto pocetakspila(spil.begin());
    auto izakrajaspila(spil.end());
    int razbrajanje(0);
    int m(b);
    while(pocetakspila!=izakrajaspila) {
        razbrajanje++;
        if(m==0) break;
        if(razbrajanje==r) {
            std::pair<std::string,std::string> pomoc;
            if(pocetakspila->first==Boje::Pik) {
                pomoc.first="Pik";
            } else if(pocetakspila->first==Boje::Tref) {
                pomoc.first="Tref";
            } else if(pocetakspila->first==Boje::Herc) {
                pomoc.first="Herc";
            } else if(pocetakspila->first==Boje::Karo) {
                pomoc.first="Karo";
            }
            pomoc.second=pocetakspila->second;
            red.push(pomoc);
            pocetakspila=spil.erase(pocetakspila);
            razbrajanje=0;
            m--;
        } else {
            pocetakspila++;
        }
        if(pocetakspila==izakrajaspila) pocetakspila=spil.begin();
    }
    return red;
}
std::pair<Boje,std::string> PretvoriStringUEnum(std::pair<std::string,std::string> str)
{
    std::pair<Boje,std::string> vraca;
    if(str.first=="Pik") {
        vraca.first=Boje::Pik;
    } else if(str.first=="Tref") {
        vraca.first=Boje::Tref;
    } else if(str.first=="Herc") {
        vraca.first=Boje::Herc;
    } else if(str.first=="Karo") {
        vraca.first=Boje::Karo;
    }
    vraca.second=str.second;
    return vraca;
}
bool NemaUSpilu(std::list<std::pair<Boje,std::string>> &spil,std::pair<Boje,std::string> element)
{
    auto pocetak(spil.begin());
    auto izakraja(spil.end());

    while(pocetak!=izakraja) {
        if(pocetak->first==element.first and pocetak->second==element.second)return false;
        pocetak++;
    }
    return true;
}
int PronadjiVrijednostInta(std::string vrijednost){
    int br(0);
    std::vector<std::string> v{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int i(0);
    while(vrijednost!=v[i]){
        i++;
        br++;
    }
    return br;
}
void Sortiraj(std::list<std::pair<Boje,std::string>> &spil)
{
    //moram osmislit sortiranje ovo je uzas
    typename std::list<std::pair<Boje,std::string>>::iterator  pocetak(spil.begin());
    typename std::list<std::pair<Boje,std::string>>::iterator  izakraja(spil.end());
    typename std::list<std::pair<Boje,std::string>>::iterator  pom(spil.begin());
    while(pocetak!=izakraja) {
        pom=pocetak;
        pom++;
        while (pom!=izakraja) {
            if(pocetak->first>pom->first or( pocetak->first==pom->first and PronadjiVrijednostInta(pocetak->second)>PronadjiVrijednostInta(pom->second))){
                auto temp(*pocetak);
                *pocetak=*pom;
                *pom=temp;
            }
            pom++;
        }
       pocetak++;
    }
}
void VratiPrvihNKarata(std::list<std::pair<Boje,std::string>> &spil,std::queue<std::pair<std::string,std::string>> &red,int n)
{
    //Bacanje izuzetaka
    if(n<0) throw std::domain_error("Broj n je besmislen!");  //smisliti kako ispitati d ali je cjelobrojna vrijednost
    if(n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(spil.size()>52 ) throw std::logic_error ("Neispravna lista!");
    auto pomocnired(red);
    while (!pomocnired.empty()) {
        auto pomoc(pomocnired.front());
        if(!(pomoc.first=="Pik" or pomoc.first=="Tref" or pomoc.first=="Herc" or pomoc.first=="Karo")) throw std::logic_error("Neispravne karte!");
        if(!(pomoc.second=="2" or pomoc.second=="3" or pomoc.second=="4" or pomoc.second=="5" or pomoc.second=="6" or pomoc.second=="7" or pomoc.second=="8" or pomoc.second=="9"
                or pomoc.second=="10" or pomoc.second=="J" or pomoc.second=="Q" or pomoc.second=="K"  or pomoc.second=="A")) throw std::logic_error("Neispravne karte!");
        pomocnired.pop();
    }
    //ovo treba jos doradit ispod
    auto pocetakliste1(spil.begin());
    auto izakrajaliste1(spil.end());
    while (pocetakliste1!=izakrajaliste1) {
        pocetakliste1++;
        auto pom(pocetakliste1);
        pocetakliste1--;
        if(!(pocetakliste1->first==Boje::Pik or pocetakliste1->first==Boje::Tref or  pocetakliste1->first==Boje::Herc or pocetakliste1->first==Boje::Karo))
            throw std::logic_error("Neispravna lista!");
        if(int(pocetakliste1->first) > int(pom->first)) throw std::logic_error("Neispravna lista!");
        pocetakliste1++;
    }

    //Obrada funkcije
    std::pair<Boje,std::string> pomocred=PretvoriStringUEnum(red.front());
    int broj(n);
    while(broj>0) {
        auto pocetakspila(spil.begin());
        auto izakraja(spil.end());
        pomocred=PretvoriStringUEnum(red.front());
        if(NemaUSpilu(spil,pomocred)) {
            spil.insert(pocetakspila,pomocred);
            pocetakspila=spil.begin();
        }
        red.pop();
        if(red.empty()) break;
        broj--;
    }
      Sortiraj(spil);
}

int main ()
{
    std::cout<<"Unesite korak razbrajanja: ";
    short int korakRazbrajanja;
    std::cin >> korakRazbrajanja;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int brkarata;
    std::cin>>brkarata;
    try {
        auto KreiraniSpil=KreirajSpil();
        auto red=IzbaciKarteRazbrajanjem(KreiraniSpil,korakRazbrajanja,brkarata);
        std::cout<<"U spilu trenutno ima "<<52-brkarata<<" karata, i to:"<< std::endl;
        for(auto it(KreiraniSpil.begin()); it!=KreiraniSpil.end(); it++) {
            std::cout<<"Pik: ";
            while(it->first==Boje::Pik) {
                std::cout<<it->second <<" ";
                it++;
            }
            std::cout<<std::endl<<"Tref: ";
            while(it->first==Boje::Tref) {
                std::cout<<it->second <<" ";
                it++;
            }
            std::cout<<std::endl <<"Herc: ";
            while(it->first==Boje::Herc) {
                std::cout<<it->second <<" ";
                it++;
            }
            std::cout<<std::endl<<"Karo: ";
            while(it->first==Boje::Karo) {
                std::cout<<it->second <<" ";
                if(std::distance(it,--KreiraniSpil.end())==0)break;
                it++;
            }
        }

        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int brkarata2;
        std::cin>>brkarata2;
        VratiPrvihNKarata(KreiraniSpil,red,brkarata2);
        std::cout<<"U spilu trenutno ima "<<52-brkarata+brkarata2<<" karata, i to:"<<std::endl;
        auto it(KreiraniSpil.begin());
        std::cout<<"Pik: ";
        while(it->first==Boje::Pik and it!=KreiraniSpil.end()) {
            std::cout<<it->second <<" ";
            it++;
        }
        std::cout<<std::endl<<"Tref: ";
        while(it->first==Boje::Tref and it!=KreiraniSpil.end()) {
            std::cout<<it->second <<" ";
            it++;
        }
        std::cout<<std::endl <<"Herc: ";
        while(it->first==Boje::Herc and it!=KreiraniSpil.end()) {
            std::cout<<it->second <<" ";
            it++;
        }
        std::cout<<std::endl<<"Karo: ";
        while(it->first==Boje::Karo and it!=KreiraniSpil.end()) {
            std::cout<<it->second <<" ";
            if(std::distance(it,--KreiraniSpil.end())==0)break;
            it++;
        }

    } catch(std::domain_error poruka) {
        std::cout<<"Izuzetak: "<<poruka.what();
    } catch(std::range_error poruka) {
        std::cout<<"Izuzetak: "<<poruka.what();
    } catch(std::logic_error poruka) {
        std::cout<<"Izuzetak: "<<poruka.what();
    }
    return 0;
}
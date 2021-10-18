/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <map>
#include <stdexcept>
#include <queue>
#include <vector>
#include <iterator>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

std::list<std::pair<Boje, std::string>> KreirajSpil()
{
    std::vector<std::string> vrijednost_karte {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    std::list<std::pair<Boje, std::string>> spil;
    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            std::pair<Boje, std::string> tmp= {Boje(i), vrijednost_karte[j]};
            spil.push_back(tmp);
        }
    }
    return spil;
}

bool PrijeUStingu_i_PostojiUStringu(std::string s1, std::string s2);
bool DobroSortirano(const std::list<std::pair<Boje, std::string>> &spil);

int BrojKarataUSpilu(const std::list<std::pair<Boje, std::string>> &spil)
{
    int br(0);
    for(auto it=spil.begin(); it!=spil.end(); it++) br++;
    return br;
}

void IzbaciKarte(std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> &mapa)
{
    if(BrojKarataUSpilu(spil)>52 || !DobroSortirano(spil)) throw std::logic_error("Neispravna lista!");
    for(auto it_mapa=mapa.begin(); it_mapa!=mapa.end(); it_mapa++)
        for(auto it_lista=spil.begin(); it_lista!=spil.end(); it_lista++)
            if(it_mapa->first==it_lista->first && it_mapa->second==it_lista->second) {
                spil.erase(it_lista);
                mapa.erase(it_mapa);
            }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &spil, const short int &r, const int &b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(BrojKarataUSpilu(spil)>52 || !DobroSortirano(spil)) throw std::logic_error("Neispravna lista!");
    int br_karata(0);
    std::vector<std::string> nazivi_boja {"Pik", "Tref", "Herc", "Karo"};
    std::queue<std::pair<std::string, std::string>> red;
    auto it(spil.begin());
    while(br_karata<b) {
        int i=0;
        while(i<r-1) {
            if(it==spil.end()) it=spil.begin();
            it++;
            i++;
        }
        std::string pom(nazivi_boja[int(it->first)]);
        std::pair<std::string, std::string> par {pom, it->second};
        red.push(par);
        br_karata++;
        it=spil.erase(it);
        auto poc(spil.begin());
        auto kraj(spil.end());
        if(poc==kraj) return red;
    }
    return red;
}

bool NesipravneKarte(std::pair<std::string, std::string> par)
{
    std::vector<std::string> nazivi_boja {"Pik", "Tref", "Herc", "Karo"};
    std::vector<std::string> vrijednost_karte {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for(int i=0; i<4; i++)
        for(int j=0; j<13; j++)
            if(par.first==nazivi_boja[i] && par.second==vrijednost_karte[j]) return false;
    return true;
}

void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &spil, std::queue<std::pair<std::string, std::string>> &red, int n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(BrojKarataUSpilu(spil)>52 || !DobroSortirano(spil)) throw std::logic_error("Neispravna lista!");
    for(int i=0; i<n; i++) {
        std::pair<std::string, std::string> el_reda(red.front());
        if(NesipravneKarte(el_reda))throw std::logic_error("Neispravne karte!");
        Boje boja;
        std::vector<std::string> nazivi_boja {"Pik", "Tref", "Herc", "Karo"};
        for(int j=0; j<nazivi_boja.size(); j++) {
            if(nazivi_boja[j]==el_reda.first) {
                boja=Boje(j);
                break;
            }
        }
        //napravili smo par koji se nalazi u redu
        std::pair<Boje, std::string> par=std::make_pair(boja, el_reda.second);
        auto prethodni(spil.begin());
        auto next(spil.end());
        auto sljedeci(spil.begin());
        sljedeci++;
        next--;
        if(spil.begin()==spil.end()) {
            spil.insert(spil.begin(), par);
            red.pop();
            continue;
        }
        for(auto it=spil.begin(); it!=spil.end(); it++) {
            if(par==*it) break;
            else if(it->first>par.first || (it->first==par.first && PrijeUStingu_i_PostojiUStringu(par.second, it->second))) {
                prethodni=spil.insert(it, par);
                break;
            } else if((it->first==par.first && PrijeUStingu_i_PostojiUStringu(it->second, par.second)) && it==next) {
                it=spil.insert(sljedeci, par);
                it--;
                break;
            }
            prethodni=it;
            sljedeci++;
        }
        red.pop();
    }
}

void IspisiKarte(const std::list<std::pair<Boje, std::string>> &spil)
{
    std::vector<std::string> nazivi_boja {"Pik", "Tref", "Herc", "Karo"};
    std::cout<<"U spilu trenutno ima "<<BrojKarataUSpilu(spil)<<" karata, i to:"<<std::endl;
    auto it(spil.begin());
    for(int i=0; i<4; i++) {
        std::cout<<nazivi_boja[i]<<":";
        auto boja=Boje(i);
        while(boja==it->first && it!=spil.end()) {
            std::cout<<" "<<it->second;
            it++;
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::list<std::pair<Boje, std::string>> spil(KreirajSpil());
    int b, br_karata;
    short int r;
    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>>r;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    std::cin>>b;
    try {
        auto red(IzbaciKarteRazbrajanjem(spil, r, b));
        IspisiKarte(spil);
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        std::cin>>br_karata;
        VratiPrvihNKarata(spil, red, br_karata);
        IspisiKarte(spil);
    } catch(std::domain_error iz) {
        std::cout<<"Izuzetak: "<<iz.what()<<std::endl;
    } catch(std::logic_error iz) {
        std::cout<<"Izuzetak: "<<iz.what()<<std::endl;
    } catch(std::range_error iz) {
        std::cout<<"Izuzetak: "<<iz.what()<<std::endl;
    } catch(...) {
        std::cout<<"Neocekivani izuzetak!"<<std::endl;
    }
    return 0;
}

bool PrijeUStingu_i_PostojiUStringu(std::string s1, std::string s2)
{
    std::vector<std::string> vrijednost_karte {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int mjesto_s1(-1), mjesto_s2(-1);
    for(int i=0; i<vrijednost_karte.size(); i++) {
        if(vrijednost_karte[i]==s1) mjesto_s1=i;
        if(vrijednost_karte[i]==s2) mjesto_s2=i;
    }
    if(mjesto_s2==-1 || mjesto_s1==-1) return false;
    return mjesto_s1<mjesto_s2;
}

bool DobroSortirano(const std::list<std::pair<Boje, std::string>> &spil)
{
    auto prethodni(spil.begin());
    for(auto it=spil.begin(); it!=spil.end(); it++) {
        if(it==spil.begin()) continue;
        else {
            if(prethodni->first>it->first) return false;
            if(prethodni->first==it->first) {
                if(!PrijeUStingu_i_PostojiUStringu(prethodni->second, it->second)) return false;
            }
            prethodni=it;
        }
    }
    return true;
}
/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <utility>
#include <string>
#include <stdexcept>

enum class Boje {Pik, Tref, Herc, Karo};

std::list<std::pair<Boje, std::string>> KreirajSpil() {
    std::list<std::pair<Boje, std::string>> spil;
    for(int i=0; i<4; i++) {
        for(int j=2; j<15; j++) {
            std::pair<Boje, std::string> par;
            par.first=Boje(i);
            if(j==11) par.second='J';
            else if(j==12) par.second='Q';
            else if(j==13) par.second='K';
            else if(j==14) par.second='A';
            else par.second=std::to_string(j);
            spil.push_back(par);
        }
    }
    return spil;
}

bool TestirajRed(std::queue<std::pair<std::string, std::string>> red) {
    while(!red.empty()) {
        if(!(red.front().first=="Pik" || red.front().first=="Tref" || red.front().first=="Herc" || red.front().first=="Karo")) return false;
        if(!(red.front().second=="2" || red.front().second=="3" || red.front().second=="4" || red.front().second=="5" ||
        red.front().second=="6" || red.front().second=="7" || red.front().second=="8" || red.front().second=="9" ||
        red.front().second=="10" || red.front().second=="J" || red.front().second=="Q" || red.front().second=="K" ||
        red.front().second=="A")) return false;
        red.pop();
    }
    return true;
}

bool TestirajSpil(const std::list<std::pair<Boje, std::string>> &spil) {
    if(spil.size()>52) return false;
    for(auto it(spil.begin()); it!=spil.end(); it++) {
        if(!(it->first==Boje::Pik || it->first==Boje::Tref || it->first==Boje::Herc || it->first==Boje::Karo)) return false;
        if(!(it->second=="2" || it->second=="3" || it->second=="4" || it->second=="5" || it->second=="6" || it->second=="7" ||
        it->second=="8" || it->second=="9" || it->second=="10" || it->second=="J" || it->second=="Q" || it->second=="K" ||
        it->second=="A")) return false;
    }
    auto it(spil.begin());
    Boje prethodni=it->first;
    while(it!=spil.end()) {
        it++;
        if(it!=spil.end()) {
            if(prethodni>it->first) return false;
            prethodni=it->first;
        }
    }
    it=spil.begin();
    prethodni=it->first;
    int vrijednost1;
    if(it->second=="J") vrijednost1=11;
    else if(it->second=="Q") vrijednost1=12;
    else if(it->second=="K") vrijednost1=13;
    else if(it->second=="A") vrijednost1=14;
    else vrijednost1=std::stoi(it->second);
    while(it!=spil.end()) {
        it++;
        if(it!=spil.end()) {
            int vrijednost2;
            if(it->second=="J") vrijednost2=11;
            else if(it->second=="Q") vrijednost2=12;
            else if(it->second=="K") vrijednost2=13;
            else if(it->second=="A") vrijednost2=14;
            else vrijednost2=std::stoi(it->second);
            if(prethodni==it->first && vrijednost1>=vrijednost2) return false;
            prethodni=it->first;
        }
    }
    return true;
}

int DajVrijednost(std::string s) {
    int vrijednost;
    if(s=="J") vrijednost=11;
    else if(s=="Q") vrijednost=12;
    else if(s=="K") vrijednost=13;
    else if(s=="A") vrijednost=14;
    else vrijednost=std::stoi(s);
    return vrijednost;
}

void IzbaciKarte(std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> &mapa) {
    
    if(!TestirajSpil(spil)) throw std::logic_error("Izuzetak: Neispravna lista!");
    
    auto it(spil.begin());
    auto it1(mapa.begin());
    while(it1!=mapa.end()) {
        it=spil.begin();
        while(it!=spil.end() && it1!=mapa.end()) {
        if(it->first==it1->first && it->second==it1->second) {
            it=spil.erase(it);
            auto it2(mapa.begin());
            Boje prva=it1->first;
            std::string druga=it1->second;
            while(it2!=mapa.end()) {
                if(it2->first==prva && it2->second==druga) it2=mapa.erase(it2);
                else it2++;
            }
        }
        else it++;
        }
     it1++;
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &spil, const short int &r, const int &b) {
    if(r<1 || r>52 || b<1) throw std::logic_error("Izuzetak: Neispravni elementi za izbacivanje!");
    if(!TestirajSpil(spil)) throw std::logic_error("Izuzetak: Neispravna lista!");
    std::queue<std::pair<std::string, std::string>> red;
    int BROJAC(0);
    auto it(spil.begin());
    while(BROJAC<b) {
        int brojac(1);
        while(brojac<=r) {
            if(brojac==r && it!=spil.end()) {
                std::string s;
                if(it->first==Boje::Pik) s="Pik";
                else if(it->first==Boje::Tref) s="Tref";
                else if(it->first==Boje::Herc) s="Herc";
                else s="Karo";
                auto par=std::make_pair(s,it->second);
                red.push(par);
                it=spil.erase(it);
                BROJAC++;
                brojac++;
            }
            else if(brojac<r && it==spil.end()) {
                it=spil.begin();
            }
            else {
                brojac++;
                it++;
                if(it==spil.end()) it=spil.begin();
            }
        }
    }
    return red;
}

void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &spil, std::queue<std::pair<std::string, std::string>> &red, int n) {
    if(n<0) throw std::domain_error("Izuzetak: Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Izuzetak: Nedovoljno karata u redu!");
    if(!TestirajRed(red)) throw std::logic_error("Izuzetak: Neispravne karte!");
    if(!TestirajSpil(spil)) throw std::logic_error("Izuzetak: Neispravna lista!");
    
    int brojac(0);
    while(!red.empty() && brojac<n) {
        Boje boja;
        if(red.front().first=="Pik") boja=Boje::Pik;
        else if(red.front().first=="Tref") boja=Boje::Tref;
        else if(red.front().first=="Herc") boja=Boje::Herc;
        else boja=Boje::Karo;
       // std::cout<<int(boja)<<" "<<red.front().second<<" "<<brojac<<std::endl;
            if(boja<spil.begin()->first) {
                spil.insert(spil.begin(), {boja, red.front().second});
                brojac++;
            }
            else if(boja==spil.begin()->first && DajVrijednost(red.front().second)<DajVrijednost(spil.begin()->second)) {
                spil.insert(spil.begin(), {boja, red.front().second});
                brojac++;
            }
            else {
                for(auto it(spil.begin()); it!=spil.end(); it++) {
                    auto prethodni(it);
                    it++;
                    if(it!=spil.end()) {
                        auto sljedeci(it);
                        if(boja==prethodni->first && boja==sljedeci->first &&
                        DajVrijednost(red.front().second)>DajVrijednost(prethodni->second) && DajVrijednost(red.front().second)<DajVrijednost(sljedeci->second)) {
                            spil.insert(sljedeci, {boja, red.front().second});
                            brojac++;
                            break;
                        }
                        else if(boja==prethodni->first && boja<sljedeci->first &&
                        DajVrijednost(red.front().second)>DajVrijednost(prethodni->second)) {
                            spil.insert(sljedeci, {boja, red.front().second});
                            brojac++;
                            break;
                        }
                        else if(boja>prethodni->first && boja==sljedeci->first && 
                        DajVrijednost(red.front().second)<DajVrijednost(sljedeci->second)) {
                            spil.insert(sljedeci, {boja, red.front().second});
                            brojac++;
                            break;
                        }
                    }
                    else {
                        if(boja>prethodni->first) {
                            spil.insert(spil.end(), {boja, red.front().second});
                            brojac++;
                            break;
                        }
                        else if(boja==prethodni->first && DajVrijednost(red.front().second)>DajVrijednost(prethodni->second)) {
                            spil.insert(spil.end(), {boja, red.front().second});
                            brojac++;
                            break;
                        }
                    }
                    it--;
                }
            }
            red.pop();
        }
    }


int main ()
{
    try {
    short int r;
    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>>r;
    int d;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    std::cin>>d;
    auto spil(KreirajSpil());
    auto red(IzbaciKarteRazbrajanjem(spil, r, d));
    std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
    auto it(spil.begin());
    std::cout<<"Pik: ";
        while(it->first==Boje::Pik && it!=spil.end()) {
            std::cout<<it->second<<" ";
            it++;
        }
        std::cout<<std::endl;
        std::cout<<"Tref: ";
        while(it->first==Boje::Tref && it!=spil.end()) {
            std::cout<<it->second<<" ";
            it++;
        }
    std::cout<<std::endl;
    std::cout<<"Herc: ";
    while(it->first==Boje::Herc && it!=spil.end()) {
        std::cout<<it->second<<" ";
        it++;
    }
    std::cout<<std::endl;
    std::cout<<"Karo: ";
    while(it->first==Boje::Karo && it!=spil.end()) {
        std::cout<<it->second<<" ";
        it++;
    }
    std::cout<<std::endl;
    int n;
    std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    std::cin>>n;
    VratiPrvihNKarata(spil, red, n);
    it=spil.begin();
    std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
    std::cout<<"Pik: ";
    while(it->first==Boje::Pik && it!=spil.end()) {
        std::cout<<it->second<<" ";
        it++;
    }
    std::cout<<std::endl;
    std::cout<<"Tref: ";
    while(it->first==Boje::Tref && it!=spil.end()) {
        std::cout<<it->second<<" ";
        it++;
    }
    std::cout<<std::endl;
    std::cout<<"Herc: ";
    while(it->first==Boje::Herc && it!=spil.end()) {
        std::cout<<it->second<<" ";
        it++;
    }
    std::cout<<std::endl;
    std::cout<<"Karo: ";
    while(it->first==Boje::Karo && it!=spil.end()) {
        std::cout<<it->second<<" ";
        it++;
    }
    }
    catch(std::logic_error poruka) {
        std::cout<<poruka.what();
        return 0;
    }
    catch(std::range_error poruka) {
        std::cout<<poruka.what();
        return 0;
    }
    catch(std::domain_error poruka) {
        std::cout<<poruka.what();
    }
    
	return 0;
}

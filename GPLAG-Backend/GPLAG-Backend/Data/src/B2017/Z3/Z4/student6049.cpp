#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<stdexcept>
#include<queue>
#include<map>
enum class Boje {Pik, Tref, Herc, Karo};
std::list<std::pair<Boje,std::string>> KreirajSpil() {
    std::list<std::pair<Boje,std::string>> spil;
    std::vector<std::string> nazivi{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int j(0);
    for(int i=0; i<52; i++) {
        if(i<13) spil.push_back(std::make_pair(Boje::Pik,nazivi[j]));
        else if(i>=13 && i<26) spil.push_back(std::make_pair(Boje::Tref,nazivi[j]));
        else if(i>=26 && i<39) spil.push_back(std::make_pair(Boje::Herc,nazivi[j]));
        else spil.push_back(std::make_pair(Boje::Karo,nazivi[j]));
        if(i==12 || i==25 || i==38) j=-1;
        j++;
    }
    return spil;
}
bool DaLiJeSpilSortiran(std::list<std::pair<Boje,std::string>> spil) {
    auto poc(spil.begin()), kraj(spil.end());
    if(poc==kraj) return true;
    auto sljedeci(poc);
    sljedeci++;
    while(sljedeci!=kraj) {
        if(sljedeci->first<poc->first) return false;
        poc++;
        sljedeci++;
    }
    return true;
}
bool ImaDuplih(std::list<std::pair<Boje,std::string>> spil) {
    auto poc(spil.begin()), kraj(spil.end());
    if(poc==kraj) return false;
    auto sljedeci(poc);
    sljedeci++;
    while(sljedeci!=kraj) {
        if(sljedeci->first==poc->first && sljedeci->second==poc->second) return true;
        poc++;
        sljedeci++;
    }
    return false;
}
bool KriterijSortiranja(std::pair<Boje,std::string> p1, std::pair<Boje,std::string> p2) {
    if(p1.first<p2.first) return true;
    else if(p1.first==p2.first) {
        
       /* if((p1.second=="2"  || p1.second=="3" || p1.second=="4" || p1.second=="5" || p1.second=="6" || p1.second=="7" || p1.second=="8" || p1.second=="9" ) && (p2.second=="2"  || p2.second=="3" || p2.second=="4" || p2.second=="5" || p2.second=="6" || p2.second=="7" || p2.second=="8" || p2.second=="9")) return p1.second<p2.second;
        else if(p1.second=="10" && (p2.second=="J" || p2.second=="Q" || p2.second=="K" || p2.second=="A")) return true;
        else if(p2.second=="10" && (p1.second!="J" && p1.second!="Q" && p1.second!="K" && p1.second!="A")) return true;
        else if(p1.second=="J" && (p2.second=="Q" || p2.second=="K" || p2.second=="A")) return true;
        else if(p1.second=="Q" && (p2.second=="K" || p2.second=="A")) return true;
        else if(p1.second=="K" && p2.second=="A") return true;
        else if((p2.second=="10" || p2.second=="J" || p2.second=="Q" || p2.second=="K" || p2.second=="A")  && p1.second!="10" && p1.second!="K" && p1.second!="Q" && p1.second!="J" && p1.second!="K" && p1.second!="A") return true;
        else return false;*/
        std::vector<std::string> nazivi  {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
        int prvi(0),drugi(0);
        for(int i=0; i<nazivi.size(); i++) {
            if(p1.second==nazivi[i]) prvi=i;
            if(p2.second==nazivi[i]) drugi=i;
        }
        return prvi<drugi;
    }
    else return false;
}
void IspisiSpilKarata(std::list<std::pair<Boje,std::string>> spil) {
    for(auto it=spil.begin(); it!=spil.end(); it++) {
        if(it->first==Boje::Pik) {
            std::cout<<"Pik: ";  
            while(it->first==Boje::Pik) {
                std::cout<<it->second<<" ";
                it++;
                if(it==spil.end()) break;
            }
            std::cout<<std::endl;
        }
        else if(it->first==Boje::Tref) {
            std::cout<<"Tref: ";
            while(it->first==Boje::Tref) {
                std::cout<<it->second<<" ";
                it++;
                if(it==spil.end()) break;
            }
            std::cout<<std::endl;
        }
        else if(it->first==Boje::Herc) {
            std::cout<<"Herc: ";
            while(it->first==Boje::Herc) {
                std::cout<<it->second<<" ";
                it++;
                if(it==spil.end()) break;
            }
            std::cout<<std::endl;
        }
        else {
            std::cout<<"Karo: ";
            while(it->first==Boje::Karo) {
                std::cout<<it->second<<" ";
                it++;
                if(it==spil.end()) break;
            }
            std::cout<<std::endl;
        }
        if(it==spil.end()) break;
        else it--;
    }
}
void IzbaciKarte(std::list<std::pair<Boje,std::string>> &spil, std::multimap<Boje,std::string> &mapa) {
    if(!DaLiJeSpilSortiran(spil) || spil.size()>52 || ImaDuplih(spil)) throw std::logic_error("Neispravna lista!");
    for(auto it=spil.begin(); it!=spil.end(); it++) {
        std::string karta(it->second);
        if(karta!="2" && karta!="3" && karta!="4" && karta!="5" && karta!="6" && karta!="7" && karta!="8"&& karta!="9" && karta!="10" && karta!="J" && karta!="Q" && karta!="K" && karta!="A") throw std::logic_error("Neispravna lista!");
    }
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        auto it1=spil.end();
        for(auto i=spil.begin(); i!=spil.end(); i++) {
            if(i->first==it->first && i->second==it->second) {
                it1=i;
                break;
            }
        }
        if(it1!=spil.end()) {
            mapa.erase(it->first);
            it1=spil.erase(it1);
            it--;
        }
    }
}
std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &spil, const short int &r, const int &b) {
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(!DaLiJeSpilSortiran(spil) || spil.size()>52 || ImaDuplih(spil)) throw std::logic_error("Neispravna lista!");
    for(auto it=spil.begin(); it!=spil.end(); it++) {
         std::string karta(it->second);
        if(karta!="2" && karta!="3" && karta!="4" && karta!="5" && karta!="6" && karta!="7" && karta!="8"&& karta!="9" && karta!="10" && karta!="J" && karta!="Q" && karta!="K" && karta!="A") throw std::logic_error("Neispravna lista!");
    }
    int brojk(b);
    auto it=spil.begin();
    std::queue<std::pair<std::string,std::string>> izbaceni;
    while(brojk!=0) {
        short int korakr(r);
        korakr--;
        while(korakr!=0) {
            it++;
            if(it==spil.end()) it=spil.begin();
            korakr--;
        }
        auto izbaci(*it);
        std::string naziv;
        if(izbaci.first==Boje::Herc) naziv="Herc";
        else if(izbaci.first==Boje::Pik) naziv="Pik";
        else if(izbaci.first==Boje::Tref) naziv="Tref";
        else naziv="Karo";
        izbaceni.push(std::make_pair(naziv,izbaci.second));
        it=spil.erase(it);
        if(spil.size()==0) break;
        brojk--;
    }
    return izbaceni;
}
void VratIPrvihNKarata(std::list<std::pair<Boje,std::string>> &spil, std::queue<std::pair<std::string,std::string>> &izbaceni, int n) {
    if(n>int(izbaceni.size())) throw std::range_error("Nedovoljno karata u redu!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(!DaLiJeSpilSortiran(spil) || ImaDuplih(spil) || spil.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto it=spil.begin(); it!=spil.end(); it++) {
         std::string karta(it->second);
        if(karta!="2" && karta!="3" && karta!="4" && karta!="5" && karta!="6" && karta!="7" && karta!="8"&& karta!="9" && karta!="10" && karta!="J" && karta!="Q" && karta!="K" && karta!="A") throw std::logic_error("Neispravna lista!");
    }
    int vel(izbaceni.size());
    while (vel!=0) {
        auto tmp(izbaceni.front());
        if((tmp.first!="Herc" && tmp.first!="Karo" && tmp.first!="Tref" && tmp.first!="Pik" ) || (tmp.second!="2" && tmp.second!="3" && tmp.second!="4" && tmp.second!="5" && tmp.second!="6" && tmp.second!="7" && tmp.second!="8" && tmp.second!="9" && tmp.second!="10" && tmp.second!="J" && tmp.second!="Q" && tmp.second!="K" && tmp.second!="A")) throw std::logic_error("Neispravne karte!");
        izbaceni.pop();
        izbaceni.push(tmp);
        vel--;
    }
    while(n!=0) {
        auto par(izbaceni.front());
        auto it(spil.end());
        for(auto i=spil.begin(); i!=spil.end(); i++) {
            std::string naziv;
            if(i->first==Boje::Herc) naziv="Herc";
            else if(i->first==Boje::Pik) naziv="Pik";
            else if(i->first==Boje::Tref) naziv="Tref";
            else naziv="Karo";
            if(naziv==par.first && i->second==par.second) {
                it=i;
                break;
            }
        }
        if(it==spil.end()) {
            Boje pomocna;
            if(par.first=="Herc") pomocna=Boje::Herc;
            else if(par.first=="Pik") pomocna=Boje::Pik;
            else if(par.first=="Tref") pomocna=Boje::Tref;
            else pomocna=Boje::Karo;
            spil.push_back(std::make_pair(pomocna,par.second));
        }
        izbaceni.pop();
        n--;
    }
    spil.sort(KriterijSortiranja);
}
int main () {
    try {
        std::list<std::pair<Boje,std::string>> spil(KreirajSpil());
        short int korak;
        std::cout<<"Unesite korak razbrajanja: ";
        std::cin>>korak;
        int brojk;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>brojk;
        std::queue<std::pair<std::string,std::string>> izbaceni(IzbaciKarteRazbrajanjem(spil,korak,brojk));
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<std::endl;
        IspisiSpilKarata(spil);
        int vrati;
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        std::cin>>vrati;
        VratIPrvihNKarata(spil,izbaceni,vrati);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<std::endl;
        IspisiSpilKarata(spil);
    }
    catch(std::domain_error izuz) {
        std::cout<<"Izuzetak: "<<izuz.what()<<std::endl;
    }
    catch(std::logic_error izuz) {
        std::cout<<"Izuzetak: "<<izuz.what()<<std::endl;
    }
    catch(std::range_error izuz) {
        std::cout<<"Izuzetak: "<<izuz.what()<<std::endl;
    }
	return 0;
}
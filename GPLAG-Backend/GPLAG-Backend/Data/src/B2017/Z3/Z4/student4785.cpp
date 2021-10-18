/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <queue>
#include <iterator>
#include <map>
#include <stdexcept>

enum class Boje{Pik,Tref,Herc,Karo};

std::vector<std::string> ime_karte{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

typedef std::list<std::pair<Boje,std::string>> Spil_karata;

void IspravnostReda(std::queue<std::pair<std::string,std::string>> red){
    while(!(red.empty())){
        auto b=red.front().first;
        if(b!="Karo" && b!="Tref" && b!="Herc" && b!="Pik") throw std::logic_error("Neispravne karte!");
        auto d=red.front().second;
        bool ima(false);
        for(int i=0;i<13;i++){
            if(d==ime_karte[i]) {
                ima=true;
                break;
            }
        }
        if(!ima) throw std::logic_error("Neispravne karte!");
        red.pop();
    }
}

void IspravnostSpila(Spil_karata &spil){
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto it=spil.begin();it!=spil.end();it++){
        auto b=it->first;
        if(b!=Boje::Pik && b!=Boje::Herc && b!=Boje::Tref && b!=Boje::Karo) throw std::logic_error("Neispravna lista!");
        auto d=it->second;
        bool ima(false);
        for(int i=0;i<13;i++){
            if(d==ime_karte[i]) {
                ima=true;
                break;
            }
        }
        if(!ima) throw std::logic_error("Neispravna lista!");
    }
    for(auto it=spil.begin();it!=spil.end();it++){
        int i;
        for(i=0;i<13;i++) if(ime_karte[i]==it->second) break;
        for(auto it2=spil.begin();it2!=it;it2++){
            if(it2->first>it->first) throw std::logic_error("Neispravna lista!");
            int j;
            for(j=0;j<13;j++) if(ime_karte[j]==it2->second) break;
            if(it2->first==it->first && j>i) throw std::logic_error("Neispravna lista!");
            if(it2->first==it->first && j==i) throw std::logic_error("Neispravna lista!");
        }
    }
}

Spil_karata KreirajSpil(){
    Spil_karata spil;
    for(int i=0;i<13;i++) spil.push_back({Boje::Pik,ime_karte.at(i)});
    for(int i=0;i<13;i++) spil.push_back({Boje::Tref,ime_karte.at(i)});
    for(int i=0;i<13;i++) spil.push_back({Boje::Herc,ime_karte.at(i)});
    for(int i=0;i<13;i++) spil.push_back({Boje::Karo,ime_karte.at(i)});
    return spil;
}

void IzbaciKarte(Spil_karata &spil, std::multimap<Boje,std::string> &izbaci){
    try{
        IspravnostSpila(spil);
    }
    catch(std::logic_error izuzetak){
        throw;
    }
    for(auto it=izbaci.begin();it!=izbaci.end();){
        bool nasao(false);
        auto lista=spil.begin();
        while(lista!=spil.end()){
            if(it->first==lista->first && it->second==lista->second){
                lista=spil.erase(lista);
                it=izbaci.erase(it);
                nasao=true;
                break;
            }
            lista++;
        }
        if(!nasao) it++;
    }
}

std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(Spil_karata &spil, const short int &r, const int &b){
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    try{
        IspravnostSpila(spil);
    }
    catch(std::logic_error izuzetak){
        throw;
    }
    std::queue<std::pair<std::string,std::string>> red;    
    int izbaceno(0);
    auto it=spil.begin();
    while(izbaceno!=b){
        for(int i=0;i<r-1;i++){
            it++;
            if(it==spil.end()) it=spil.begin();
        }
        std::string ime_boje;
        if(it->first==Boje::Pik) ime_boje="Pik";
        else if(it->first==Boje::Herc) ime_boje="Herc";
        else if(it->first==Boje::Karo) ime_boje="Karo";
        else ime_boje="Tref";
        red.push({ime_boje,it->second});
        auto pomocni=it;
        pomocni++;
        if(pomocni==spil.end()){
            spil.erase(it);
            it=spil.begin();
        }
        else it=spil.erase(it);
        izbaceno++;
        if(spil.size()==0) break;
    }
    return red;
}

void VratiPrvihNKarata(Spil_karata &spil, std::queue<std::pair<std::string,std::string>> &red, int n){
    int velicina_reda=red.size();
    if(n>velicina_reda) throw std::range_error("Nedovoljno karata u redu!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    try{
        IspravnostReda(red);
    }
    catch(std::logic_error izuzetak){
        throw;
    }
    try{
        IspravnostSpila(spil);
    }
    catch(std::logic_error izuzetak){
        throw;
    }
    for(int i=0;i<n;i++){
        Boje b;
        if(red.front().first=="Pik") b=Boje::Pik;
        else if(red.front().first=="Karo") b=Boje::Karo;
        else if(red.front().first=="Tref") b=Boje::Tref;
        else b=Boje::Herc;
        bool uspjesno(false);
        bool duplikat(false);
        for(auto it=spil.begin();it!=spil.end();it++){
            if(it->first<b) continue;
            int i,j;
            for(i=0;i<13;i++) if(ime_karte[i]==it->second) break;
            for(j=0;j<13;j++) if(ime_karte[j]==red.front().second) break;
            if(it->first==b && i<j) continue;
            if(it->first==b && i==j) {
                duplikat=true;
                break;
            }
            spil.insert(it,{b,ime_karte[j]});
            uspjesno=true;
            break;
        }
        if(!duplikat && !uspjesno) spil.insert(spil.end(),{b,red.front().second});
        red.pop();
    }
}

void IspisiKarte(Spil_karata &spil){
    std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:";
    bool kraj(false);
    if(spil.size()==0) kraj=true;
    auto it=spil.begin();
    while(kraj || it!=spil.end()){
        std::cout<<std::endl<<"Pik: ";
        while(!kraj && it->first==Boje::Pik){
            std::cout<<it->second<<" ";
            it++;
            if(it==spil.end()) kraj=true;
        }
        std::cout<<std::endl<<"Tref: ";
        while(!kraj && it->first==Boje::Tref){
            std::cout<<it->second<<" ";
            it++;
            if(it==spil.end()) kraj=true;
        }
        std::cout<<std::endl<<"Herc: ";
        while(!kraj && it->first==Boje::Herc){
            std::cout<<it->second<<" ";
            it++;
            if(it==spil.end()) kraj=true;
        }
        std::cout<<std::endl<<"Karo: ";
        while(!kraj && it->first==Boje::Karo){
            std::cout<<it->second<<" ";
            it++;
            if(it==spil.end()) kraj=true;
        }
        if(kraj) break;
        it++;
    }
    std::cout<<std::endl;
}

int main ()
{
    try{
    Spil_karata s=KreirajSpil();
    std::cout<<"Unesite korak razbrajanja: ";
    short int r;
    std::cin>>r;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int b;
    std::cin>>b;
    auto red=IzbaciKarteRazbrajanjem(s,r,b);
    IspisiKarte(s);
    std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    int n;
    std::cin>>n;
    VratiPrvihNKarata(s,red,n);
    IspisiKarte(s);
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
    catch(std::range_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}






























/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <queue>
#include <iterator>
#include <map>
#include <stdexcept>

enum class Boje{Pik,Tref,Herc,Karo};

std::vector<std::string> ime_karte{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

typedef std::list<std::pair<Boje,std::string>> Spil_karata;

void IspravnostReda(std::queue<std::pair<std::string,std::string>> red){
    while(!(red.empty())){
        auto b=red.front().first;
        if(b!="Karo" && b!="Tref" && b!="Herc" && b!="Pik") throw std::logic_error("Neispravne karte!");
        auto d=red.front().second;
        bool ima(false);
        for(int i=0;i<13;i++){
            if(d==ime_karte[i]) {
                ima=true;
                break;
            }
        }
        if(!ima) throw std::logic_error("Neispravne karte!");
        red.pop();
    }
}

void IspravnostSpila(Spil_karata &spil){
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto it=spil.begin();it!=spil.end();it++){
        auto b=it->first;
        if(b!=Boje::Pik && b!=Boje::Herc && b!=Boje::Tref && b!=Boje::Karo) throw std::logic_error("Neispravna lista!");
        auto d=it->second;
        bool ima(false);
        for(int i=0;i<13;i++){
            if(d==ime_karte[i]) {
                ima=true;
                break;
            }
        }
        if(!ima) throw std::logic_error("Neispravna lista!");
    }
    for(auto it=spil.begin();it!=spil.end();it++){
        int i;
        for(i=0;i<13;i++) if(ime_karte[i]==it->second) break;
        for(auto it2=spil.begin();it2!=it;it2++){
            if(it2->first>it->first) throw std::logic_error("Neispravna lista!");
            int j;
            for(j=0;j<13;j++) if(ime_karte[j]==it2->second) break;
            if(it2->first==it->first && j>i) throw std::logic_error("Neispravna lista!");
            if(it2->first==it->first && j==i) throw std::logic_error("Neispravna lista!");
        }
    }
}

Spil_karata KreirajSpil(){
    Spil_karata spil;
    for(int i=0;i<13;i++) spil.push_back({Boje::Pik,ime_karte.at(i)});
    for(int i=0;i<13;i++) spil.push_back({Boje::Tref,ime_karte.at(i)});
    for(int i=0;i<13;i++) spil.push_back({Boje::Herc,ime_karte.at(i)});
    for(int i=0;i<13;i++) spil.push_back({Boje::Karo,ime_karte.at(i)});
    return spil;
}

void IzbaciKarte(Spil_karata &spil, std::multimap<Boje,std::string> &izbaci){
    try{
        IspravnostSpila(spil);
    }
    catch(std::logic_error izuzetak){
        throw;
    }
    for(auto it=izbaci.begin();it!=izbaci.end();){
        bool nasao(false);
        auto lista=spil.begin();
        while(lista!=spil.end()){
            if(it->first==lista->first && it->second==lista->second){
                lista=spil.erase(lista);
                it=izbaci.erase(it);
                nasao=true;
                break;
            }
            lista++;
        }
        if(!nasao) it++;
    }
}

std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(Spil_karata &spil, const short int &r, const int &b){
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    try{
        IspravnostSpila(spil);
    }
    catch(std::logic_error izuzetak){
        throw;
    }
    std::queue<std::pair<std::string,std::string>> red;    
    int izbaceno(0);
    auto it=spil.begin();
    while(izbaceno!=b){
        for(int i=0;i<r-1;i++){
            it++;
            if(it==spil.end()) it=spil.begin();
        }
        std::string ime_boje;
        if(it->first==Boje::Pik) ime_boje="Pik";
        else if(it->first==Boje::Herc) ime_boje="Herc";
        else if(it->first==Boje::Karo) ime_boje="Karo";
        else ime_boje="Tref";
        red.push({ime_boje,it->second});
        auto pomocni=it;
        pomocni++;
        if(pomocni==spil.end()){
            spil.erase(it);
            it=spil.begin();
        }
        else it=spil.erase(it);
        izbaceno++;
        if(spil.size()==0) break;
    }
    return red;
}

void VratiPrvihNKarata(Spil_karata &spil, std::queue<std::pair<std::string,std::string>> &red, int n){
    int velicina_reda=red.size();
    if(n>velicina_reda) throw std::range_error("Nedovoljno karata u redu!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    try{
        IspravnostReda(red);
    }
    catch(std::logic_error izuzetak){
        throw;
    }
    try{
        IspravnostSpila(spil);
    }
    catch(std::logic_error izuzetak){
        throw;
    }
    for(int i=0;i<n;i++){
        Boje b;
        if(red.front().first=="Pik") b=Boje::Pik;
        else if(red.front().first=="Karo") b=Boje::Karo;
        else if(red.front().first=="Tref") b=Boje::Tref;
        else b=Boje::Herc;
        bool uspjesno(false);
        bool duplikat(false);
        for(auto it=spil.begin();it!=spil.end();it++){
            if(it->first<b) continue;
            int i,j;
            for(i=0;i<13;i++) if(ime_karte[i]==it->second) break;
            for(j=0;j<13;j++) if(ime_karte[j]==red.front().second) break;
            if(it->first==b && i<j) continue;
            if(it->first==b && i==j) {
                duplikat=true;
                break;
            }
            spil.insert(it,{b,ime_karte[j]});
            uspjesno=true;
            break;
        }
        if(!duplikat && !uspjesno) spil.insert(spil.end(),{b,red.front().second});
        red.pop();
    }
}

void IspisiKarte(Spil_karata &spil){
    std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:";
    bool kraj(false);
    if(spil.size()==0) kraj=true;
    auto it=spil.begin();
    while(kraj || it!=spil.end()){
        std::cout<<std::endl<<"Pik: ";
        while(!kraj && it->first==Boje::Pik){
            std::cout<<it->second<<" ";
            it++;
            if(it==spil.end()) kraj=true;
        }
        std::cout<<std::endl<<"Tref: ";
        while(!kraj && it->first==Boje::Tref){
            std::cout<<it->second<<" ";
            it++;
            if(it==spil.end()) kraj=true;
        }
        std::cout<<std::endl<<"Herc: ";
        while(!kraj && it->first==Boje::Herc){
            std::cout<<it->second<<" ";
            it++;
            if(it==spil.end()) kraj=true;
        }
        std::cout<<std::endl<<"Karo: ";
        while(!kraj && it->first==Boje::Karo){
            std::cout<<it->second<<" ";
            it++;
            if(it==spil.end()) kraj=true;
        }
        if(kraj) break;
        it++;
    }
    std::cout<<std::endl;
}

int main ()
{
    try{
    Spil_karata s=KreirajSpil();
    std::cout<<"Unesite korak razbrajanja: ";
    short int r;
    std::cin>>r;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int b;
    std::cin>>b;
    auto red=IzbaciKarteRazbrajanjem(s,r,b);
    IspisiKarte(s);
    std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    int n;
    std::cin>>n;
    VratiPrvihNKarata(s,red,n);
    IspisiKarte(s);
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
    catch(std::range_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}































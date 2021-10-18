/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <map>
#include <string>
#include <stdexcept>
#include <queue>
#include <vector>
#include <algorithm>

enum class Boje {Pik, Tref, Herc, Karo};

typedef std::list<std::pair<Boje, std::string>> ListaParova;
typedef std::queue<std::pair<std::string, std::string>> RedParova;
typedef std::multimap<Boje, std::string> Multimapa;

bool DaLiJeBesmisleno (RedParova red) {
    std::vector<std::string> vr {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    std::pair<std::string, std::string> par = red.front();
    std::string pocetak = par.first;
    if (pocetak!="Pik" && pocetak!="Tref" && pocetak!="Herc" && pocetak!="Karo") return true;
    red.push(par);
    red.pop();
    //bool ima(false);
    for (;;) {
        par = red.front();
        std::string prvi = par.first;
        if (prvi!="Pik" && prvi!="Tref" && prvi!="Herc" && prvi!="Karo") return true;
        /*std::string drugi = par.second;
        for (int i=0; i<vr.size(); i++) {
            if (drugi==vr.at(i)) ima==true;
        }
        if (!ima) return true;*/
        red.push(par);
        red.pop();
        par = red.front();
        if (par.first==pocetak) break;
    }
    return false;
}

bool DaLiJeSortiran (ListaParova spil){
    std::vector<std::string> vr {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    auto it=spil.begin();
    int boja = int(it->first);
    it++;
    for (; it!=spil.end(); it++) {
        if (boja > int(it->first)) return false;
        boja = int(it->first);
    }
    return true;
}

bool DaLiJeBesmisleno (ListaParova spil) {
    std::vector<std::string> vr {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    bool ima(true);
    for (auto it=spil.begin(); it!=spil.end(); it++) {
        auto boja = it->first;
        if (boja!=Boje::Pik && boja!=Boje::Tref && boja!=Boje::Herc && boja!=Boje::Karo) return true;
        std::string drugi = it->second;
        for (int i=0; i<vr.size(); i++) {
            if (drugi==vr.at(i)) ima=true;
        }
        if (!ima) return true;
    }
    return false;
}

ListaParova KreirajSpil () {
    ListaParova lista (52);
    std::vector<std::string> vr {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int br(0), i(0);
    for (auto it=lista.begin(); it!=lista.end(); it++) {
        if (br<13)
            *it = std::make_pair(Boje::Pik, vr.at(i));
        else if (br>=13 && br<26)
            *it = std::make_pair(Boje::Tref, vr.at(i));
        else if (br>=26 && br<39)
            *it = std::make_pair(Boje::Herc, vr.at(i));
        else 
            *it = std::make_pair(Boje::Karo, vr.at(i));
        br++;
        if (i<12) i++;
        else i=0;
    }
    return lista;
}


void IzbaciKarte (ListaParova &spil, Multimapa &m) {
    if (spil.size()>52 || !DaLiJeSortiran(spil) || DaLiJeBesmisleno(spil)) throw std::logic_error ("Neispravna lista!");
   
    for (auto it1=spil.begin(); it1!=spil.end(); it1++) {
        for (auto it2=m.begin(); it2!=m.end(); it2++) {
            if (it1->first==it2->first && it1->second==it2->second) {
                it1 = spil.erase(it1);
                m.erase(it2->first);
                break;
            }
        }
        it1--;
    }
}


RedParova IzbaciKarteRazbrajanjem (ListaParova &spil, const short int &r, const int &b) { // r->korak razbrajanja; b->broj karata koje treba izbaciti;
    if (r<1 || r>52 || b<1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    if (spil.size()>52 || !DaLiJeSortiran(spil) || DaLiJeBesmisleno(spil)) throw std::logic_error ("Neispravna lista!");
    RedParova red;
    int br(0);
    for (auto it=spil.begin();; it++) {
        
        short int pom(r);
        while(pom>1) {
            if (it==spil.end()) it=spil.begin();
            it++;
            pom--;
        }
        std::string pom1;
        int prvi = int(it->first);
        if (prvi==0) pom1 = "Pik";
        else if (prvi==1) pom1 = "Tref";
        else if (prvi==2) pom1 = "Herc";
        else if (prvi==3) pom1 = "Karo";
        
        std::string pom2 (it->second);
        
        std::pair<std::string, std::string> par = std::make_pair (pom1, pom2);
        red.push(par);
        
        it = spil.erase(it);
        it--;
        
        if (spil.size()==0) break;
        
        br++;
        if (br==b) break;
    }
    
    return red;
}


void VratiPrvihNKarata (ListaParova &spil, RedParova &red, int n) {
    if (n<0 || n>52) throw std::domain_error ("Broj n je besmislen!");
    if (n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    if (DaLiJeBesmisleno(red)) throw std::logic_error ("Neispravne karte");
    if (spil.size()>52 || !DaLiJeSortiran(spil) || DaLiJeBesmisleno(spil)) throw std::logic_error ("Neispravna lista!");
    
    std::vector<std::string> vr {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"}; 
    
    int i(0);
    //bool ima(false);
    while (i<n) {
        bool ima = false;
        std::pair<std::string, std::string> pom = red.front();
        std::string boja_s = pom.first;
        Boje prvi;
        if (boja_s=="Pik") prvi = Boje::Pik;
        else if (boja_s=="Tref") prvi = Boje::Tref;
        else if (boja_s=="Herc") prvi = Boje::Herc;
        else if (boja_s=="Karo") prvi = Boje::Karo;
        std::pair<Boje, std::string> par = std::make_pair(prvi, pom.second);
        for (auto it=spil.begin(); it!=spil.end(); it++) {
            if (par.first==it->first && par.second==it->second) {
                ima=true;
                break;
            }
        }
        if (!ima) {
            spil.insert(spil.begin(), par);
            i++;
        }
        else {
            red.push(pom);
        }
        red.pop();
    }
    
    spil.sort([vr](std::pair<Boje, std::string> par1, std::pair<Boje, std::string> par2) {
        int br1(-1), br2(-1);
        for (int i=0; i<vr.size(); i++) {
            if (par1.second==vr.at(i)) br1=i;
            if (par2.second==vr.at(i)) br2=i;
            if (br1!=-1 && br2!=-1) break;
        }
        return br1<br2;
    });
}


int main ()
{
    try {
        ListaParova Spil (KreirajSpil());
        
        int korak(0);
        std::cout << "Unesite korak razbrajanja: ";
        std::cin >> korak;
        int br_karata1(0);
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        std::cin >> br_karata1;
        RedParova red = IzbaciKarteRazbrajanjem(Spil, korak, br_karata1);
        std::cout << "U spilu trenutno ima " << 52-br_karata1 << " karata, i to:" << std::endl;
        std::cout << "Pik: ";
        for (auto it=Spil.begin(); it!=Spil.end(); it++) {
            if (int(it->first)==0) std::cout << it->second << " ";
        }
        std::cout << std::endl << "Tref: ";
        for (auto it=Spil.begin(); it!=Spil.end(); it++) {
            if (int(it->first)==1) std::cout << it->second << " ";
        }
        std::cout << std::endl << "Herc: ";
        for (auto it=Spil.begin(); it!=Spil.end(); it++) {
            if (int(it->first)==2) std::cout << it->second << " ";
        }
        std::cout << std::endl << "Karo: ";
        for (auto it=Spil.begin(); it!=Spil.end(); it++) {
            if (int(it->first)==3) std::cout << it->second << " ";
        }
        
        int br_karata2(0);
        std::cout << std::endl << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> br_karata2;
        VratiPrvihNKarata(Spil, red, br_karata2);
        std::cout << "U spilu trenutno ima " << 52-br_karata1+br_karata2 << " karata, i to:" << std::endl;
        std::cout << "Pik: ";
        for (auto it=Spil.begin(); it!=Spil.end(); it++) {
            if (int(it->first)==0) std::cout << it->second << " ";
        }
        std::cout << std::endl << "Tref: ";
        for (auto it=Spil.begin(); it!=Spil.end(); it++) {
            if (int(it->first)==1) std::cout << it->second << " ";
        }
        std::cout << std::endl << "Herc: ";
        for (auto it=Spil.begin(); it!=Spil.end(); it++) {
            if (int(it->first)==2) std::cout << it->second << " ";
        }
        std::cout << std::endl << "Karo: ";
        for (auto it=Spil.begin(); it!=Spil.end(); it++) {
            if (int(it->first)==3) std::cout << it->second << " ";
        }
    }
    catch (std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
    catch (std::range_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
	return 0;
}

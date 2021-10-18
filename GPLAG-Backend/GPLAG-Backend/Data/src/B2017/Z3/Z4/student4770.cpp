/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
#include <iterator>
#include <queue>

enum class Boje
{
    Pik, Tref, Herc, Karo
};
bool Broj(std::string x)
{
    if(x[0]>='0' && x[0]<='9') return true;
    return false;
}
int PretvoriUbroj(std::string s)
{
    int broj(0);
    if(s=="J") {    broj=11;        return broj;}
    else if(s=="Q") {        broj=12;        return broj;    }
    else if(s=="K") {        broj=13;        return broj;    } 
    else if(s=="A") {        broj=14;        return broj;    }
    else if(s=="10") {        broj=10;        return broj;    }
    for(int i=0; i<s.size(); i++) {
        broj+=s.at(i)-'0';
    }

    return broj;
}
void IspravnostListe(std::list<std::pair<Boje,std::string>> spil){
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto x : spil) {
        if(!(x.second.size()>2 || x.second[0]=='A' || x.second[0]=='Q' || x.second[0]=='K' || x.second[0]=='J' || (x.second[0]>='0' && x.second[0]<='9'))) throw std::logic_error("Neispravna lista!");
        if(!(x.first==Boje::Pik || x.first == Boje::Tref || x.first == Boje::Herc || x.first == Boje::Karo)) throw std::logic_error("Neispravna lista!");
    }
}
std::list<std::pair<Boje ,std::string>> KreirajSpil()
{
    std::list<std::pair<Boje, std::string>> vrati;
    int brojac(0);
    Boje boja;
    for(int j = 0; j < 4; j++) {
        boja = Boje(brojac);
        for(int i = 2 ; i<15; i++) {
            std::pair<Boje,std::string> pomocni;
            pomocni.first = boja;
            if(i<10) pomocni.second.push_back('0'+i);
            else if(i==10) pomocni.second="10";
            else if(i==11) pomocni.second.push_back('J');
            else if(i==12) pomocni.second.push_back('Q');
            else if(i==13) pomocni.second.push_back('K');
            else if(i==14) pomocni.second.push_back('A');
            vrati.push_back(pomocni);
        }
        brojac++;

    }
    return vrati;
}
void IzbaciKarte(std::list<std::pair<Boje,std::string>> &spil, std::multimap<Boje,std::string> &mapa)
{
    IspravnostListe(spil);
    for(auto it = spil.begin(); it != spil.end(); it++) {
        auto it2 = mapa.find(it->first);
        if(it2!=mapa.end() && it2->second == it->second) {
            mapa.erase(it2);
            it = spil.erase(it);
        } else continue;
    }

}
std::queue<std::pair<Boje,std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &spil, const short int &korak_razbrajanja, const int &br_karata)
{
    if(korak_razbrajanja<1 || korak_razbrajanja>52 || br_karata<1 ) throw std::logic_error("Neispravni elementi za izbacivanje!");
    IspravnostListe(spil);
    std::queue<std::pair<Boje,std::string>> arman;
    auto it = spil.begin();
    std::advance(it,korak_razbrajanja-1);
    int brojac(br_karata);
    while(brojac!=0) {
        arman.push(*it);
        it = spil.erase(it);
        for(int i = 0; i<korak_razbrajanja-1; i++) {
            it++;
            if(it == spil.end()) it = spil.begin();
        }
        brojac--;
    }
    return arman;

}
void IspisiSpil(const std::list<std::pair<Boje ,std::string>> &spil)
{
    std::cout<<"Pik: ";
    for(auto it = spil.begin(); it != spil.end(); it++) {
        if((int)it->first==0) std::cout<<it->second<<" ";
    }

    std::cout<<std::endl<<"Tref: ";
    for(auto it = spil.begin(); it != spil.end(); it++) {
        if((int)it->first==1) std::cout<<it->second<<" ";
    }

    std::cout<<std::endl<<"Herc: ";
    for(auto it = spil.begin(); it != spil.end(); it++) {
        if((int)it->first==2) std::cout<<it->second<<" ";
    }
    std::cout<<std::endl<<"Karo: ";
    for(auto it = spil.begin(); it != spil.end(); it++) {
        if((int)it->first==3) std::cout<<it->second<<" ";
    }
}

void VratiPrvihNKarata(std::list<std::pair<Boje,std::string>> &spil, std::queue<std::pair<Boje,std::string>> &red,int n)
{
    if(n>red.size() && n>0) throw std::range_error("Nedovoljno karata u redu!");
    else if(n<0) throw std::logic_error("Broj n je besmislen!");
    IspravnostListe(spil);
    int k(n);
    for(;;) {
        if(k==0) break;
        for(auto it = spil.begin(); it!=spil.end(); it++) {
            if(k==0) break;
            if((int)it->first == (int)red.front().first) {
                if(PretvoriUbroj(it->second) > PretvoriUbroj(red.front().second)) {
                    spil.insert(it,red.front());
                    red.pop();
                    k--;
                } else if(PretvoriUbroj(it->second) < PretvoriUbroj(red.front().second) && PretvoriUbroj(it->second)==13 && PretvoriUbroj(red.front().second)==14) {
                    it++;
                    spil.insert(it,red.front());
                    red.pop();
                    k--;
                }
            }
        }
    }
}
int main ()
{
    try {
        std::cout<<"Unesite korak razbrajanja: ";
        int korak_raz;
        std::cin>>korak_raz;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int br_karata;
        std::cin>>br_karata;
        auto spil(KreirajSpil());
        auto red(IzbaciKarteRazbrajanjem(spil,korak_raz,br_karata));
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
        IspisiSpil(spil);
        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        VratiPrvihNKarata(spil,red,n);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
        IspisiSpil(spil);
    } catch (std::range_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    } catch (std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    return 0;
}

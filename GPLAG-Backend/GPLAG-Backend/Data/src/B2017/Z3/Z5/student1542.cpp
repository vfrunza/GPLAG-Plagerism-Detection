/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>

int main ()
{
	return 0;
}
#include <iostream>
#include <list>
#include <iterator>
#include <stack> 
#include <set>
#include <utility>
#include <stdexcept>
#include <vector> 
#include <string>

enum class Boje {Herc, Karo, Pik, Tref};

std::string KonvertujBoje(Boje x)
{
    if(x == Boje::Herc)return "Herc";
    if(x == Boje::Karo)return "Karo";
    if(x == Boje::Pik)return "Pik";
    if(x == Boje::Tref)return "Tref";
}
std::string KonvertujBrojeve(int broj)
{
    if (broj==0)return "2";
    if (broj==1)return "3";
    if (broj==2)return "4";
    if (broj==3)return "5";
    if (broj==4)return "6";
    if (broj==5)return "7";
    if (broj==6)return "8";
    if (broj==7)return "9";
    if (broj==8)return "10";
    if (broj==9)return "J";
    if (broj==10)return "Q";
    if (broj==11)return "K";
    if (broj==12)return "A";
}
Boje OcitajBoju (std::string x)
{
    if(x == "Herc")return Boje::Herc;
    if(x == "Karo")return Boje::Karo;
    if(x == "Pik")return Boje::Pik;
    if(x == "Tref")return Boje::Tref;
}
int OcitajBroj (std::string s)
{
    if (s=="2")return 0;
    if (s=="3")return 1;
    if (s=="4")return 2;
    if (s=="5")return 3;
    if (s=="6")return 4;
    if (s=="7")return 5;
    if (s=="8")return 6;
    if (s=="9")return 7;
    if (s=="10")return 8;
    if (s=="J")return 9;
    if (s=="Q")return 10;
    if (s=="K")return 11;
    if (s=="A")return 12;
    
}
std::list<std::set<Boje>> KreirajSpil()
{
    std::list<std::set<Boje>>spil;
    std::set<Boje> skup;
    skup.insert(Boje::Pik);
    skup.insert(Boje::Tref);
    skup.insert(Boje::Herc);
    skup.insert(Boje::Karo);
    for(int i=0; i<13; i++)
    {
        spil.push_back(skup);
    }
    return spil;
}

int PrebrojiKarte(const std::list<std::set<Boje>> &spil)
{
    int suma(0);
    if(std::distance(spil.begin(),spil.end()) != 13)throw std::logic_error("Neispravna lista!");
    for(auto it(spil.begin()); it!=spil.end(); it++)
    {
        suma+=it->size();
    }
    return 52-suma;
}

std::stack<std::pair<std::string,std::string>> IzbaciKarte(std::list<std::set<Boje>> &spil, const std::pair<int,int> &par)
{
    if (par.first < 1 || par.first > 52 || par.second < 1)throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(std::distance(spil.begin(),spil.end()) != 13)throw std::logic_error("Neispravna lista!");
    int provjera(52-PrebrojiKarte(spil));
    int r(par.first),b(par.second);
    if(b > provjera)b=provjera;
    std::stack<std::pair<std::string,std::string>>stek;
    auto it(spil.begin()); int pozicija(0);int k(0);
    for(int i= 0; i < b ; i++)
    {
        
        int br(0);
        for(;; it++)
        {
            if(it==spil.end())it=spil.begin(),pozicija=0,k++;
            if(k==4)k=0; 
            if(it->count(Boje(k))!=0) br++;
            if(br==r)break;
            pozicija++;
        }
        
        stek.push({KonvertujBoje(Boje(k)),KonvertujBrojeve(pozicija)});
        it->erase(Boje(k));
        
    }
    return stek;
}
bool IspravnostSteka(std::stack<std::pair<std::string,std::string>> stek)
{
    std::vector<std::string>v { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    std::vector<std::string>v1 {"Herc", "Karo", "Pik", "Tref"};
    bool a(false),b(false);
    while(!stek.empty())
    {
        auto par(stek.top());
        stek.pop();
        for(int i=0; i < 4; i++)
        if(par.first == v1[i])a=true;
        for(int i=0; i < 13; i++)
        if(par.second == v[i])b=true;
    }
    return a&&b;
}
void VratiPosljednjihNKarata(std::list<std::set<Boje>> &spil, std::stack<std::pair<std::string,std::string>> &stek, int n)
{
    if(std::distance(spil.begin(),spil.end()) != 13)throw std::logic_error("Neispravna lista!");
    if(n > stek.size())throw std::range_error("Nedovoljno karata u steku!");
    if(!IspravnostSteka(stek))throw std::logic_error("Neispravne karte!");
    for(int i=0; i<n; i++)
    {   
        auto it(spil.begin());
        auto par(stek.top());
        stek.pop();
        std::advance(it,OcitajBroj(par.second));
        if(it->count(OcitajBoju(par.first))==0)
        it->insert(OcitajBoju(par.first));
    }
}

void IspisiSpil(const std::list<std::set<Boje>> &spil)
{
    auto it(spil.begin()); 
    for(int i=0; i < 4 ; i++)
    {
        std::cout << KonvertujBoje(Boje(i)) <<": ";
        if(i==2)std::cout <<" ";
        int br(0);
        for(auto it(spil.begin()); it!=spil.end();it++)
        {
            if(it->count(Boje(i))!=0)
                std::cout << KonvertujBrojeve(br) <<" ";
            br++;
        }
        std::cout<<std::endl;
    }
    
}
int main() {
    try{
        auto spil(KreirajSpil());
        std::cout << "Unesite korak razbrajanja: ";
        int korak(0);
        std::cin >> korak;
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        int br_karata(0);
        std::cin >> br_karata;
        auto stek(IzbaciKarte(spil,{korak,br_karata}));
        std::cout << "U spilu trenutno ima: " <<52 - PrebrojiKarte(spil)<<" karata, i to:" <<std::endl;
        IspisiSpil(spil);
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        int n(0);
        std::cin >> n;
        VratiPosljednjihNKarata(spil,stek,n);
        std::cout << "Broj karata u steku: " <<stek.size()<<std::endl;
        std::cout << "Trenutne karte u steku:" << std::endl;
        while(!stek.empty()) {
        auto par=stek.top();
        std::cout<<par.first<<" "<<par.second;
        std::cout  << std::endl;
        stek.pop(); 
        }
    }
    catch(std::logic_error poruka){
        std::cout << "Izuzetak: "<<poruka.what() << std::endl;
    }
    catch(std::range_error poruka){
        std::cout << "Izuzetak: "<<poruka.what() << std::endl;
    }
    return 0;
}


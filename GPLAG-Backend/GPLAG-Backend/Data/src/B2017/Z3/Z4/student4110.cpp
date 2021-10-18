/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <queue>
#include <iterator>
#include <functional>
enum class Boje {Pik, Tref, Herc, Karo};
typedef std::list<std::pair<Boje, std::string>> Spil;
typedef std::multimap<Boje, std::string> multimapa;
typedef std::queue<std::pair<Boje, std::string>> red;

Spil KreirajSpil(){
    Spil a;
    std::vector<std::string> karte {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            a.push_back(std::make_pair(Boje(i),karte[j]));
        }
    }
    return a;
}
int Pretvori(std::string a){
     std::vector<std::string> karte {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
     int vrati{15};
     for(int i=0;i<karte.size();i++){ if(a==karte[i]) vrati=i;}
     return vrati;
}

bool Sortirano(const Spil &a){
    for(auto it=a.begin();it!=--a.end();it++){
        if(int(it->first)>int((++it)->first))return false;
        else {
            --it;
            if(int(it->first)==int((++it)->first)&&Pretvori(it->second)>Pretvori((++it)->second))return false;
            --it;
        }
    }
    return true;
}
bool Kriterij(std::pair<Boje,std::string> a, std::pair<Boje,std::string> b){
        if(int(a.first)<int(b.first))return true;
        if(int(a.first)==int(b.first)&&Pretvori(a.second)<Pretvori(b.second))return true;
    return false;
}

bool Smisleno(const Spil &a){
    for(auto it=a.begin();it!=a.end();it++){
        if(int(it->first)<0||int(it->first)>3)return false;
        if(Pretvori(it->second)==15)return false;
    }
    return true;
}

bool Smisleno2(red a){
    while(!a.empty()){
        if(int(a.front().first)<0||int(a.front().first)>3)return false;
        if(Pretvori(a.front().second)==15) return false;
        a.pop();
    }
    return true;
}

void IzbaciKarte(Spil &a, multimapa &b){
    if(a.size()>52||!Sortirano(a)||!Smisleno(a)) throw std::logic_error("Izuzetak: Neispravna lista!");
    for(auto it=b.begin();it!=b.end();it++){
        for(auto it2=a.begin();it2!=a.end();it2++){
            if(it->first==it2->first && it->second==it2->second){
               it=b.erase(it);
               it--;
               a.erase(it2);
            }
        }
    }
}

red IzbaciKarteRazbrajanjem(Spil &a,const short int r, const int b){
    if(r<1||r>52||b<1)throw std::logic_error("Izuzetak: Neispravni elementi za izbacivanje!");
    if(a.size()>52||!Sortirano(a)||!Smisleno(a)) throw std::logic_error("Izuzetak: Neispravna lista!");
    short int br{0};
    red izbacene;
    auto it(a.begin());
    while(br!=b&&!a.empty()){
        for(int i=1;i<r;i++){if(it==a.end())it=a.begin();it++;}
        izbacene.push(*it);
        it=a.erase(it);
        br++;
    }
    return izbacene;
    
}

void VratiPrvihNKarata(Spil &a, red &b, int n){
    int g(b.size());
    if(n>g) throw std::range_error("Izuzetak: Nedovoljno karata u redu!");
    if(n<0)throw std::domain_error("Izuzetak: Broj n je besmislen!");
    if(!Smisleno2(b)) throw std::logic_error("Izuzetak: Neispravne karte!");
   if(a.size()>52||!Smisleno(a)) throw std::logic_error("Izuzetak: Neispravna lista!");
    int br{0};
    while(br!=n){
        for(auto it=a.begin();it!=a.end();it++){
            if(int(it->first)==int(b.front().first) && it->second==b.front().second){
                b.pop();
            }
        }
        a.push_back(b.front());
        b.pop();
        br++;
    }
    
}
void Ispisi(Spil &a, int boja){
    for(auto it=a.begin();it!=a.end();it++){
        if(int(it->first)==boja) std::cout<<it->second<<" ";
    }
}

int main ()
{
    try{
    Spil a(KreirajSpil());
    short int r;
    int b;
    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>>r;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    std::cin>>b;
    red izbacene(IzbaciKarteRazbrajanjem(a,r,b));
    std::cout<<"U spilu trenutno ima "<<a.size()<<" karata, i to:"<<std::endl<<"Pik: ";
    Ispisi(a,0);
    std::cout<<std::endl<<"Tref: ";
    Ispisi(a,1);
    std::cout<<std::endl<<"Herc: ";
    Ispisi(a,2);
    std::cout<<std::endl<<"Karo: ";
    Ispisi(a,3);
    std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
    int c;
    std::cin>>c;
    //a.sort(Kriterij);
    VratiPrvihNKarata(a,izbacene,c);
    a.sort(Kriterij);
    std::cout<<"U spilu trenutno ima "<<a.size()<<" karata, i to:"<<std::endl<<"Pik: ";
    Ispisi(a,0);
    std::cout<<std::endl<<"Tref: ";
    Ispisi(a,1);
    std::cout<<std::endl<<"Herc: ";
    Ispisi(a,2);
    std::cout<<std::endl<<"Karo: ";
    Ispisi(a,3);
	return 0;}
	catch(std::domain_error e){
	    std::cout<<e.what();
	}
	catch(std::logic_error e){
	    std::cout<<e.what();
	}
	catch(std::range_error e){
	    std::cout<<e.what();
	}
}

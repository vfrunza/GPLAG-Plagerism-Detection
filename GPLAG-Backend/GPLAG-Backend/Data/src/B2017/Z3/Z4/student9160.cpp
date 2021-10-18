/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
enum class Boje {Pik, Tref, Herc, Karo};

typedef std::pair<Boje,std::string> Karta;
typedef std::list<Karta> Spil;

bool CompCard(std::string a, std::string b){
    const std::vector<std::string> karte {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    auto prvi = std::find(karte.begin(),karte.end(),a);
    auto drugi = std::find(karte.begin(),karte.end(),b);
    if(std::distance(prvi,drugi) <= 0)return false;
    return true;
}
bool Sortirano(Spil spil){
   auto pocetak(spil.begin()), kraj(spil.end());
   if(pocetak == kraj)return true;
   auto sljedeci(pocetak);
   while(++sljedeci!=kraj){
       if(sljedeci->first == pocetak->first && CompCard(sljedeci->second,pocetak->second))
       return false;
       ++pocetak;
   }
   return true;
}
bool Sadrzaj(Spil spil){
    const std::vector<std::string>karte{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(auto x : spil){
        int brojac(0);
        for(int i(0);i<karte.size();i++)
            if(x.second != karte[i])brojac++;
        if(brojac == karte.size())return false;    
    }
    return true;
}
bool ImaLi(std::string s, std::vector<std::string> v){
    for(int i(0);i<v.size();i++)
        if(s == v.at(i))return true;
    return false;    
}
bool Sadrzaj(std::queue<std::pair<std::string, std::string>> karte){
    const std::vector<std::string>spil{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    const std::vector<std::string>boja{"Pik", "Tref", "Herc", "Karo"};
    while(!karte.empty()){
        auto x(karte.front());
        if(!ImaLi(x.first,boja) || !ImaLi(x.second,spil))return false;
        karte.pop();
    }
    return true;
}
void Testiraj(Spil spil){
    if(spil.size()>52 || !Sortirano(spil) || !Sadrzaj(spil))
        throw std::logic_error("Neispravna lista!");
}
bool Isti(Karta a, Karta b){
    return a.first == b.first && a.second == b.second;
}
Spil KreirajSpil(){     
  const std::vector<std::string>karte{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
  Spil spil;
  for(int i(0);i<4;i++){
      for(int j(0);j<13;j++)
            spil.push_back(std::make_pair( Boje(i), karte.at(j)));
  }
  return spil;  
}
void IzbaciKarte(Spil &spil, std::multimap<Boje,std::string> parovi){
    Testiraj(spil);
    for(auto itList(spil.begin()); itList != spil.end(); ){
        for(auto itMap(parovi.begin()); itMap != parovi.end();){
            if(Isti(*itMap,*itList)){
                itList = spil.erase(itList);
                itMap = parovi.erase(itMap);
            }else{
                ++itMap;
            }
        }
        ++itList;
    }
}

std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(Spil &spil, const short int &r, int b){
    Testiraj(spil);
    if(r<1 || r>52 || b<1)throw std::logic_error("Neispravni elementi za izbacivanje!");
    std::queue<std::pair<std::string,std::string>> pravi_pov;
    int brojac(0);
    const std::vector<std::string>boja{"Pik","Tref","Herc","Karo"};
    auto it(spil.begin());
    while(brojac!=b){
        for(short int i(0); i < r-1; i++){
            if(std::distance(it,spil.end()) == 1)
                it = spil.begin();
            else it++;    
        }
        pravi_pov.push(std::make_pair( boja[int(it->first)] , it->second ));
        it = spil.erase(it);
        brojac++;
        if(spil.empty())break;
    }
    return pravi_pov;
}
Karta NapraviKartu(std::pair<std::string,std::string> k){
    const std::vector<std::string>boja{"Pik", "Tref", "Herc", "Karo"};
    int j(0);
    for(int i(0);i<boja.size();i++)
        if(boja.at(i) == k.first) j = i;
    Boje b = Boje(j);
    Karta sklj = std::make_pair(b,k.second);
    return sklj;
}
void Ubaci(Spil &spil, Karta k){
    
    for(auto it(spil.begin()); it!=spil.end();it++){
        if(it->first == k.first){
            auto stanje(CompCard(it->second,k.second));
            while (stanje){
                it++;
                stanje = CompCard(it->second,k.second);
            }
            it = spil.insert(it,k);
            return;
        }else if(it->first < k.first)it++;
    }
}
void VratiPrvihNKarata(Spil &spil, std::queue<std::pair<std::string,std::string>> karte, int n){
    Testiraj(spil);
    if(n < 0)throw std::domain_error("Broj n je besmislen!");
    if(n > karte.size())throw std::range_error("Nedovoljno karata u redu!");
    if(!Sadrzaj(karte))throw std::logic_error("Neispravne karte!");
    
    int brojac(0);
    while(brojac<n){
        auto temp(karte.front());
        Karta k(NapraviKartu(temp));
        int x(std::count(spil.begin(),spil.end(),k));
        if(x == 0)Ubaci(spil,k);
        karte.pop();
        brojac++;
    }
}
void IspisiSpil(Spil spil){
    Boje prethodna(Boje::Pik);
    std::string boja[]{"Pik", "Tref", "Herc", "Karo"};
    std::cout<<boja[0]<<": ";
    for(auto it(spil.begin()); it!=spil.end();it++  ){
        if(prethodna != it->first){
            std::cout<<std::endl;
            std::cout<<boja[int(it->first)]<<": ";
        }
        prethodna = it->first;
        std::cout<<it->second<<" ";
    }
    std::cout<<std::endl;
}
int main ()
{
    try{
        Spil spil(KreirajSpil());
        std::cout<<"Unesite korak razbrajanja: ";
        short int r; std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int b; std::cin>>b;
        auto red(IzbaciKarteRazbrajanjem(spil,r,b));
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
        IspisiSpil(spil);
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int sdf; std::cin>>sdf;
        VratiPrvihNKarata(spil,red,sdf);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
        IspisiSpil(spil);
        
    }catch(std::domain_error e){
        std::cout<<"Izuzetak: "<<e.what()<<std::endl;
    }catch(std::range_error e){
        std::cout<<"Izuzetak: "<<e.what()<<std::endl;
    }catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what()<<std::endl;
    }
    return 0;
}

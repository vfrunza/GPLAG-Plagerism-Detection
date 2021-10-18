/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <stdexcept>
#include <queue>
#include <algorithm>
#include <utility>
//#include <vector>

enum class Boje {Pik, Tref, Herc, Karo};


bool kriterij(std::pair<Boje, std::string> prvi, std::pair<Boje, std::string> drugi){
    int prvaBoja(0);
    int drugaBoja(0);
    int prvaKarta(0);
    int drugaKarta(0);
    
    prvaBoja=int(prvi.first);
    drugaBoja=int(drugi.first);
    
    if(prvi.second=="2") prvaKarta=2;
    else if(prvi.second=="3") prvaKarta=3;
    else if(prvi.second=="4") prvaKarta=4;
    else if(prvi.second=="5") prvaKarta=5;
    else if(prvi.second=="6") prvaKarta=6;
    else if(prvi.second=="7") prvaKarta=7;
    else if(prvi.second=="8") prvaKarta=8;
    else if(prvi.second=="9") prvaKarta=9;
    else if(prvi.second=="10") prvaKarta=10;
    else if(prvi.second=="J") prvaKarta=11;
    else if(prvi.second=="Q") prvaKarta=12;
    else if(prvi.second=="K") prvaKarta=13;
    else if(prvi.second=="A") prvaKarta=14;
    
    if(drugi.second=="2") drugaKarta=2;
    else if(drugi.second=="3") drugaKarta=3;
    else if(drugi.second=="4") drugaKarta=4;
    else if(drugi.second=="5") drugaKarta=5;
    else if(drugi.second=="6") drugaKarta=6;
    else if(drugi.second=="7") drugaKarta=7;
    else if(drugi.second=="8") drugaKarta=8;
    else if(drugi.second=="9") drugaKarta=9;
    else if(drugi.second=="10") drugaKarta=10;
    else if(drugi.second=="J") drugaKarta=11;
    else if(drugi.second=="Q") drugaKarta=12;
    else if(drugi.second=="K") drugaKarta=13;
    else if(drugi.second=="A") drugaKarta=14;
    
    if(prvaBoja==drugaBoja) return prvaKarta<drugaKarta;
    return prvaBoja<drugaBoja;
    
}
    

std::list<std::pair<Boje, std::string>> KreirajSpil(){
    std::list<std::pair<Boje, std::string>> povratna;
    std::vector<std::string> vrijednosti {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int j=0;
    for(int i=0;i<52;i++){
        if(i<13) povratna.push_back({Boje::Pik, vrijednosti.at(j)}), j++;
        else if(i>12 && i<26) povratna.push_back({Boje::Tref, vrijednosti.at(j)}), j++;
        else if(i>25 && i<39) povratna.push_back({Boje::Herc, vrijednosti.at(j)}), j++;
        else if(i>38) povratna.push_back({Boje::Karo, vrijednosti.at(j)}), j++;
        if(j>12) j=0;
    }
    return povratna;
}

void IzbaciKarte(std::list<std::pair<Boje, std::string>> &karte, std::multimap<Boje, std::string> &mapa){
    if(karte.size()==0) return;
    // errori 
    if(karte.size()>52) throw std::logic_error("Neispravna lista!");
    
    
    std::list<std::pair<Boje, std::string>>::iterator krozKarte=karte.begin();
    std::list<std::pair<Boje, std::string>>::iterator dokle=karte.begin();
    dokle++;
    for(int i=0;i<karte.size()-1;i++){
        if(int(krozKarte->first)>int(dokle->first)) throw std::logic_error("Neispravna lista!");
        krozKarte++;
        dokle++;
    }

    krozKarte=karte.begin();
    dokle=karte.begin();
    dokle++;
    
    for(int i=0;i<karte.size()-1;i++){
        int krozKarteBroj(0);
        int dokleBroj(0);
        if(krozKarte->second=="2") krozKarteBroj=2;
        else if(krozKarte->second=="3") krozKarteBroj=3;
        else if(krozKarte->second=="4") krozKarteBroj=4;
        else if(krozKarte->second=="5") krozKarteBroj=5;
        else if(krozKarte->second=="6") krozKarteBroj=6;
        else if(krozKarte->second=="7") krozKarteBroj=7;
        else if(krozKarte->second=="8") krozKarteBroj=8;
        else if(krozKarte->second=="9") krozKarteBroj=9;
        else if(krozKarte->second=="10") krozKarteBroj=10;
        else if(krozKarte->second=="J") krozKarteBroj=11;
        else if(krozKarte->second=="Q") krozKarteBroj=12;
        else if(krozKarte->second=="K") krozKarteBroj=13;
        else if(krozKarte->second=="A") krozKarteBroj=14;
        
         if(dokle->second=="2") dokleBroj=2;
        else if(dokle->second=="3") dokleBroj=3;
        else if(dokle->second=="4") dokleBroj=4;
        else if(dokle->second=="5") dokleBroj=5;
        else if(dokle->second=="6") dokleBroj=6;
        else if(dokle->second=="7") dokleBroj=7;
        else if(dokle->second=="8") dokleBroj=8;
        else if(dokle->second=="9") dokleBroj=9;
        else if(dokle->second=="10") dokleBroj=10;
        else if(dokle->second=="J") dokleBroj=11;
        else if(dokle->second=="Q") dokleBroj=12;
        else if(dokle->second=="K") dokleBroj=13;
        else if(dokle->second=="A") dokleBroj=14;
        
        if(dokleBroj<=krozKarteBroj && int(krozKarte->first)==int(dokle->first)) throw std::logic_error("Neispravna lista!");
        krozKarte++;
        dokle++;
    }
    
    krozKarte=karte.begin();
    
    for(int i=0;i<karte.size();i++){
        if(krozKarte->first!=Boje::Pik && krozKarte->first!=Boje::Tref && krozKarte->first!=Boje::Herc && krozKarte->first!=Boje::Karo) throw std::logic_error("Neispravna lista!");
        if(krozKarte->second!="2" && krozKarte->second!="3" && krozKarte->second!="4" && krozKarte->second!="5" && krozKarte->second!="6" && krozKarte->second!="7" && krozKarte->second!="8" && krozKarte->second!="9" && krozKarte->second!="10" && krozKarte->second!="J" && krozKarte->second!="Q" && krozKarte->second!="K" && krozKarte->second!="A")
        throw std::logic_error("Neispravna lista!");
        krozKarte++;
    }
    
    
    
    
    
    
    // Glavni dio funkjcije 
    std::list<std::pair<Boje, std::string>>::iterator it=karte.begin();
    
    while(it!=karte.end()){
        std::multimap<Boje, std::string>::iterator itm=mapa.begin();
        while(itm!=mapa.end()){
            if(it->first==itm->first && it->second==itm->second){
                Boje pomocnaBoja=it->first;
                std::string s=it->second;
                std::list<std::pair<Boje, std::string>>::iterator pomocni=karte.begin();
                while(pomocni!=karte.end()){
                    if(pomocni->first==it->first && pomocni->second==it->second){
                        karte.erase(pomocni);
                    }
                    pomocni++;
                }
                std::multimap<Boje, std::string>::iterator pomocniIterator=mapa.begin();
                while(pomocniIterator!=mapa.end()){
                    if(pomocniIterator->first==pomocnaBoja && pomocniIterator->second==s) mapa.erase(pomocniIterator);
                    pomocniIterator++;
                }
            }
            itm++;
        }
        it++;
    }
}



std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &karte, short int &r, int &b){
    

    if(r<1 || r>52) throw std::logic_error("Neispravni elementi za izbacivanje!");
    else if(b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    
    if(karte.size()>52) throw std::logic_error("Neispravna lista!");
    
    std::queue<std::pair<std::string, std::string>> povratni;
    if(karte.size()==0) return povratni;
    
    std::list<std::pair<Boje, std::string>>::iterator krozKarte=karte.begin();
    std::list<std::pair<Boje, std::string>>::iterator dokle=karte.begin();
    dokle++;
    for(int i=0;i<karte.size()-1;i++){
        if(int(krozKarte->first)>int(dokle->first)) throw std::logic_error("Neispravna lista!");
        krozKarte++;
        dokle++;
    }
    
    krozKarte=karte.begin();
    dokle=karte.begin();
    dokle++;
    
    for(int i=0;i<karte.size()-1;i++){
        int krozKarteBroj(0);
        int dokleBroj(0);
        if(krozKarte->second=="2") krozKarteBroj=2;
        else if(krozKarte->second=="3") krozKarteBroj=3;
        else if(krozKarte->second=="4") krozKarteBroj=4;
        else if(krozKarte->second=="5") krozKarteBroj=5;
        else if(krozKarte->second=="6") krozKarteBroj=6;
        else if(krozKarte->second=="7") krozKarteBroj=7;
        else if(krozKarte->second=="8") krozKarteBroj=8;
        else if(krozKarte->second=="9") krozKarteBroj=9;
        else if(krozKarte->second=="10") krozKarteBroj=10;
        else if(krozKarte->second=="J") krozKarteBroj=11;
        else if(krozKarte->second=="Q") krozKarteBroj=12;
        else if(krozKarte->second=="K") krozKarteBroj=13;
        else if(krozKarte->second=="A") krozKarteBroj=14;
        
         if(dokle->second=="2") dokleBroj=2;
        else if(dokle->second=="3") dokleBroj=3;
        else if(dokle->second=="4") dokleBroj=4;
        else if(dokle->second=="5") dokleBroj=5;
        else if(dokle->second=="6") dokleBroj=6;
        else if(dokle->second=="7") dokleBroj=7;
        else if(dokle->second=="8") dokleBroj=8;
        else if(dokle->second=="9") dokleBroj=9;
        else if(dokle->second=="10") dokleBroj=10;
        else if(dokle->second=="J") dokleBroj=11;
        else if(dokle->second=="Q") dokleBroj=12;
        else if(dokle->second=="K") dokleBroj=13;
        else if(dokle->second=="A") dokleBroj=14;
        
        if(dokleBroj<=krozKarteBroj && int(krozKarte->first)==int(dokle->first)) throw std::logic_error("Neispravna lista!");
        krozKarte++;
        dokle++;
    }
    
    krozKarte=karte.begin();
    
    for(int i=0;i<karte.size();i++){
        if(krozKarte->first!=Boje::Pik && krozKarte->first!=Boje::Tref && krozKarte->first!=Boje::Herc && krozKarte->first!=Boje::Karo) throw std::logic_error("Neispravna lista!");
        if(krozKarte->second!="2" && krozKarte->second!="3" && krozKarte->second!="4" && krozKarte->second!="5" && krozKarte->second!="6" && krozKarte->second!="7" && krozKarte->second!="8" && krozKarte->second!="9" && krozKarte->second!="10" && krozKarte->second!="J" && krozKarte->second!="Q" && krozKarte->second!="K" && krozKarte->second!="A")
        throw std::logic_error("Neispravna lista!");
        krozKarte++;
    }
    
    
    
    
    std::list<std::pair<Boje, std::string>>::iterator it=karte.begin();
    
    if (karte.size()==0) return povratni;
    
    int koliko(0);
    while(koliko!=b){
        short int dokle(1);
        
        
        
        while(dokle!=r){
            dokle++;
            it++;
            if(it==karte.end()) it=karte.begin();
        }
        std::string prvi;
        std::string drugi;
        drugi=it->second;
        if(int(it->first)==0) prvi="Pik";
        else if(int(it->first)==1) prvi="Tref";
        else if(int(it->first)==2) prvi="Herc";
        else if(int(it->first)==3) prvi="Karo";
        
        std::pair<std::string, std::string> povratniPar=std::make_pair(prvi, drugi);
        povratni.push(povratniPar);
        it=karte.erase(it);
        koliko++;
        if(karte.size()==0) break;
    }
    return povratni;
    
    
}


void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &karte, std::queue<std::pair<std::string, std::string>> &red, int n){
    
    if(n>(int)red.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    
    
    int velicina=red.size();
    for(int i=0; i<velicina; i++){
        std::string pomocniPrvi;
        std::string pomocniDrugi;
        
        std::pair<std::string, std::string> nestoZaNesto=red.front();
        pomocniPrvi=nestoZaNesto.first;
        pomocniDrugi=nestoZaNesto.second;
        red.pop();
        red.push(nestoZaNesto);
        if((pomocniPrvi!="Pik" && pomocniPrvi!="Tref" && pomocniPrvi!="Herc" && pomocniPrvi!="Karo") || (pomocniDrugi!="2" && pomocniDrugi!="3" && pomocniDrugi!="4" && pomocniDrugi!="5" && pomocniDrugi!="6" && pomocniDrugi!="7" && pomocniDrugi!="8" && pomocniDrugi!="9" && pomocniDrugi!="10" && pomocniDrugi!="J" && pomocniDrugi!="Q" && pomocniDrugi!="K" && pomocniDrugi!="A"))
        throw std::logic_error("Neispravne karte!");
    }
    
    
    
    if(karte.size()>52) throw std::logic_error("Neispravna lista!");
    if(karte.size()==0) return;
    
    std::list<std::pair<Boje, std::string>>::iterator krozKarte=karte.begin();
    std::list<std::pair<Boje, std::string>>::iterator dokle=karte.begin();
    dokle++;
    for(int i=0;i<karte.size()-1;i++){
        if(int(krozKarte->first)>int(dokle->first)) throw std::logic_error("Neispravna lista!");
        krozKarte++;
        dokle++;
    }
    krozKarte=karte.begin();
    dokle=karte.begin();
    dokle++;
    
    for(int i=0; i<karte.size()-1; i++){
        int krozKarteBroj(0);
        int dokleBroj(0);
        if(krozKarte->second=="2") krozKarteBroj=2;
        else if(krozKarte->second=="3") krozKarteBroj=3;
        else if(krozKarte->second=="4") krozKarteBroj=4;
        else if(krozKarte->second=="5") krozKarteBroj=5;
        else if(krozKarte->second=="6") krozKarteBroj=6;
        else if(krozKarte->second=="7") krozKarteBroj=7;
        else if(krozKarte->second=="8") krozKarteBroj=8;
        else if(krozKarte->second=="9") krozKarteBroj=9;
        else if(krozKarte->second=="10") krozKarteBroj=10;
        else if(krozKarte->second=="J") krozKarteBroj=11;
        else if(krozKarte->second=="Q") krozKarteBroj=12;
        else if(krozKarte->second=="K") krozKarteBroj=13;
        else if(krozKarte->second=="A") krozKarteBroj=14;
        
        if(dokle->second=="2") dokleBroj=2;
        else if(dokle->second=="3") dokleBroj=3;
        else if(dokle->second=="4") dokleBroj=4;
        else if(dokle->second=="5") dokleBroj=5;
        else if(dokle->second=="6") dokleBroj=6;
        else if(dokle->second=="7") dokleBroj=7;
        else if(dokle->second=="8") dokleBroj=8;
        else if(dokle->second=="9") dokleBroj=9;
        else if(dokle->second=="10") dokleBroj=10;
        else if(dokle->second=="J") dokleBroj=11;
        else if(dokle->second=="Q") dokleBroj=12;
        else if(dokle->second=="K") dokleBroj=13;
        else if(dokle->second=="A") dokleBroj=14;
        
        if(dokleBroj<=krozKarteBroj && int(krozKarte->first)==int(dokle->first)) throw std::logic_error("Neispravna lista!");
        krozKarte++;
        dokle++;
    }
    krozKarte=karte.begin();
    for(int i=0; i<karte.size();i++){
        if(krozKarte->first!=Boje::Pik && krozKarte->first!=Boje::Tref && krozKarte->first!=Boje::Herc && krozKarte->first!=Boje::Karo) throw std::logic_error("Neispravna lista!");
        if(krozKarte->second!="2" && krozKarte->second!="3" && krozKarte->second!="4" && krozKarte->second!="5" && krozKarte->second!="6" && krozKarte->second!="7" && krozKarte->second!="8" && krozKarte->second!="9" && krozKarte->second!="10" && krozKarte->second!="J" && krozKarte->second!="Q" && krozKarte->second!="K" && krozKarte->second!="A")
        throw std::logic_error("Neispravna lista!");
        krozKarte++;
    }
    
    int i=0;
    int k(0);
    k=red.size();
    int v(0);
   while(i<n){
       v++;
       std::pair<std::string, std::string> ubacujem;
       ubacujem=red.front();
       std::string prvi;
       std::string drugi;
       
       prvi=ubacujem.first;
       drugi=ubacujem.second;
       
       Boje ubacujemPrvi;
       std::string ubacujemDrugi;
       
       if(prvi=="Pik") ubacujemPrvi=Boje::Pik;
       else if(prvi=="Tref") ubacujemPrvi=Boje::Tref;
       else if(prvi=="Herc") ubacujemPrvi=Boje::Herc;
       else if(prvi=="Karo") ubacujemPrvi=Boje::Karo;
       
       ubacujemDrugi=drugi;
       
       std::list<std::pair<Boje, std::string>>::iterator it=karte.begin();
       std::pair<Boje, std::string> konacno=std::make_pair(ubacujemPrvi, ubacujemDrugi);
       
       while(it!=karte.end()){
           if(konacno.first==it->first && konacno.second==it->second) break;
           it++;
       }
       
       if(it==karte.end()){
        i++;   
        karte.insert(karte.begin(), konacno);
       }
       else 
           red.push(ubacujem);
          
           
       
       red.pop();
       if(v==k) break;
    }
    
    karte.sort(kriterij);
  
    
}
/*
void IspSpi(std::list<std::pair<Boje, std::string>>& spil)
{
     std::vector<std::string> b {"Pik", "Tref", "Herc", "Karo"};

     auto it(spil.begin());
     for (int i{0}; i < 4; i++)
     {
          std::cout << b.at(i) << ": ";
          while ((*it).first == Boje(i) && it != spil.end())
          {
               std::cout << (*it).second << " ";
               it++;
          }
          std::cout << std::endl;
     }
}
*/
int main ()
{
    
    //Test funkcije IzbaciKarte
    /* std::list<std::pair<Boje, std::string>> spil = KreirajSpil();
     
    
     
  
     std::multimap <Boje, std::string> mapa4 {{Boje(0), "A"}, {Boje(1), "K"}, {Boje(0), "A"}, {Boje(1), "K"}};
     
     
     
     spil.resize(0);
     IzbaciKarte(spil, mapa4);
     std::cout << mapa4.size() << std::endl;
     std::cout<<"armin";*/
     
    
    std::cout<<"Unesite korak razbrajanja: ";
    short int r(0);
    std::cin>>r;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int b(0);
    std::cin>>b;
    
    std::list<std::pair<Boje, std::string>> proba;
    
    proba=KreirajSpil();
   
    std::queue<std::pair<std::string, std::string>> redIzbacivanje;
    try{
        
    redIzbacivanje=IzbaciKarteRazbrajanjem(proba, r, b);
   
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
        return 0;
    }
    std::cout<<"U spilu trenutno ima "<<proba.size()<<" karata, i to:"<<std::endl;
    
   
    auto it=proba.begin();
       std::cout<<"Pik: ";
       while(it->first==Boje::Pik){
           std::cout<<it->second<<" ";
           it++;
       }
       
       std::cout<<std::endl<<"Tref: ";
       while(it->first==Boje::Tref){
           std::cout<<it->second<<" ";
           it++;
       }
       
       std::cout<<std::endl<<"Herc: ";
       while(it->first==Boje::Herc){
           std::cout<<it->second<<" ";
           it++;
       }
       
       std::cout<<std::endl<<"Karo: ";
       while(it->first==Boje::Karo){
           std::cout<<it->second<<" ";
           it++;
       }
 
    std::cout<<std::endl;
    int n(0);
    try{
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        std::cin>>n;
        VratiPrvihNKarata(proba, redIzbacivanje, n);
        
        std::cout<<"U spilu trenutno ima "<<proba.size()<<" karata, i to:"<<std::endl;
        
        auto it=proba.begin();
        
        std::cout<<"Pik: ";
        while(it->first==Boje::Pik){
            std::cout<<it->second<<" ";
            it++;
        }
        
        std::cout<<std::endl<<"Tref: ";
        while(it->first==Boje::Tref){
            std::cout<<it->second<<" ";
            it++;
        }
        
        std::cout<<std::endl<<"Herc: ";
        while(it->first==Boje::Herc){
            std::cout<<it->second<<" ";
            it++;
        }
        
        std::cout<<std::endl<<"Karo: ";
        while(it->first==Boje::Karo){
            std::cout<<it->second<<" ";
            it++;
        }
       
    

        
    }
    catch(std::range_error e){
        std::cout<<"Izuzetak: "<<e.what();
        return 0;
    }
    catch(std::domain_error e){
        std::cout<<"Izuzetak: "<<e.what();
        return 0;
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
        return 0;
    }
    
    /*std::list<std::pair<Boje, std::string>> nesto{{Boje::Pik, "2"}, {Boje::Pik, "3"}, {Boje::Tref, "3"}, {Boje::Tref, "3"}};
    nesto=KreirajSpil();
    nesto.push_back({Boje::Karo, "armin"});
    for(auto it=nesto.begin(); it!=nesto.end(); it++) std::cout<<int(it->first)<<" "<<it->second<<std::endl;
    
    std::list<std::pair<Boje, std::string>> test{{Boje::Pik, "4"}, {Boje::Tref, "6"}};
    std::multimap<Boje, std::string> testMapa{{Boje::Pik, "5"}};
    std::multimap<Boje, std::string> mapa{{Boje::Pik, "4"}, {Boje::Pik, "5"}, {Boje::Pik, "kuca"}, {Boje::Pik,"4"}, {Boje::Pik,"5"}, {Boje::Pik, "6"}};
    try{
    IzbaciKarte(nesto, testMapa);
    std::cout<<std::endl;
    }
    catch(std::logic_error e){
        std::cout<<e.what();
        return 0;
    }
    */
   /* 
    std::cout<<"armin";
    std::cout<<std::endl;
    short int r=12;
    int b=6;
    std::queue<std::pair<std::string, std::string>> redTest=IzbaciKarteRazbrajanjem(nesto, r, b);
    for(auto it=nesto.begin(); it!=nesto.end(); it++) std::cout<<int(it->first)<<" "<<it->second<<std::endl;
    std::cout<<std::endl;
    
    
    for(int i=0;i<6; i++){
        std::pair<std::string, std::string> pokusaj=redTest.front();
        std::cout<<pokusaj.first<<" "<<pokusaj.second;
        std::cout<<std::endl;
        redTest.pop();
    }
    std::pair<std::string, std::string> pokusaj=redTest.front();
    std::cout<<pokusaj.first<<" "<<pokusaj.second;
   
    for(auto it=nesto.begin(); it!=nesto.end(); it++) std::cout<<int(it->first)<<" "<<it->second<<std::endl;
    std::cout<<std::endl;
    
    std::multimap<Boje, std::string>::iterator k=testMapa.begin();
    
    while(k!=testMapa.end()){
        std::cout<<(int)k->first<<" "<<k->second<<std::endl;
        k++;
    }
    
    std::list<int> mojaLista;
    mojaLista.push_back(2);
    mojaLista.push_back(2);
    for(auto it=mojaLista.begin(); it!=mojaLista.end(); it++) std::cout<<*it<<" ";
    
    
    std::multimap<Boje, std::string> mojaMapa{{Boje::Pik,"armin"}, {Boje::Tref,"aadwe"}, {Boje::Pik,"neko"}, {Boje::Pik,"armin"}};
    
    Boje pomocna=Boje::Pik;
    std::string s="armin";
    
    std::multimap<Boje, std::string>::iterator pomocniIterator=mojaMapa.begin();
    while(pomocniIterator!=mojaMapa.end()){
        if(pomocniIterator->first==pomocna && pomocniIterator->second==s) mojaMapa.erase(pomocniIterator);
        pomocniIterator++;
    }
    
    
    mojaMapa.erase(Boje::Pik);
    std::multimap<Boje, std::string>::iterator it=mojaMapa.begin();
    while(it!=mojaMapa.end()) {
        std::cout<<int(it->first)<<" "<<it->second<<std::endl;
        it++;
    }*/
	return 0;
}

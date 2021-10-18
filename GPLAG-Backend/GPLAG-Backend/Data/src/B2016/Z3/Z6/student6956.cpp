/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <memory>
//#include "TestCurenja.h"
struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
}lista;
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int brTimova){
    if(brTimova<1 || brTimova>int(v.size())) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> rezultat;
    std::vector<int>timovi;
    for(int i=0; i<int(v.size()%brTimova); i++) timovi.push_back(v.size()/brTimova+1);
    while(int(timovi.size())<=brTimova){
        timovi.push_back(v.size()/brTimova);
    }
    for(int i(0); i<brTimova;i++) rezultat.push_back(std::set<std::string>());
    try{
        auto pocetak(std::make_shared<Dijete>()), prethodni(std::make_shared<Dijete>());
        for(int i=0;i<int(v.size());i++){
            auto novi(std::make_shared<Dijete>());
            novi->ime=v[i];
            novi->sljedeci=pocetak;
            if(i==0){
                pocetak=novi;
            }
            else {
                prethodni->sljedeci=novi;
            }
            prethodni=novi;
        }
        auto it(std::make_shared<Dijete>());
        it=pocetak;
        int br=0, duzina=0;
        while(pocetak->sljedeci != pocetak){
            duzina=it->ime.length();
            if(timovi[br]==rezultat[br].size()) br++;
            rezultat[br].insert(it->ime);
            it=it->sljedeci;
            //delete prethodni->sljedeci;
            prethodni->sljedeci=it;
            while(duzina>1){
                prethodni=it;
                it=it->sljedeci;
                duzina--;
            }
            pocetak=it;
            if(it->sljedeci==(it->sljedeci)->sljedeci)break;
        }
        rezultat[br].insert(it->ime);
        //delete it->sljedeci;
        pocetak=nullptr;
        prethodni=nullptr;
        it->sljedeci=nullptr;
        return rezultat;
    }
    catch(...){
        
    }
}
int main ()
{
    try{
    std::vector<std::string>v;
    std::cout<<"Unesite broj djece: ";
    int brDjece;
    std::cin>>brDjece;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::cin.ignore();
    for(int i=0; i<brDjece;i++){
        std::string s;
        std::getline(std::cin,s);
        v.push_back(s);
    }
    std::cout<<"Unesite broj timova: ";
    int brTimova;
    std::cin>>brTimova;
    auto rez(Razvrstavanje(v,brTimova));
    int br=1;
    for( auto kanta : rez){
        std::cout<<"Tim "<<br++<<": ";
        auto it=kanta.begin();
        while(!kanta.empty()){
            std::cout<<*it;
            it=kanta.erase(it);
            if(!kanta.empty()) std::cout<<", ";
            
        }
        std::cout<<std::endl;
    }
    
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
        return 0;
    }
    
    
    
    
    
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <set>
#include <string>
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v,int brTimova){
    if(brTimova<1 || brTimova>int(v.size())) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::list<std::string> lista;
    std::vector<std::set<std::string>> rezultat;
    std::vector<int>timovi;
    for(int i=0; i<int(v.size()%brTimova);i++) timovi.push_back(v.size()/brTimova + 1);
    while(int (timovi.size()) <= brTimova){
        timovi.push_back(v.size()/brTimova);
    }
    for(auto x : v) lista.push_back(x);
    auto it(lista.begin());
    int br=0, duzina=0;
    for(int i=0;i<brTimova; i++) rezultat.push_back(std::set<std::string>());
    while(!lista.empty()){
        duzina=(*it).length();
        rezultat[br].insert(*it);
        it=lista.erase(it);
        if(lista.empty()){
            //radi!!
            //std::cout<<"OK";
            break;
        }
        if(it==lista.end()) it=lista.begin();
        while(duzina>1){
            it++;
            if(it==lista.end()) it=lista.begin();
            duzina--;
        }
        if(timovi[br]==rezultat[br].size()) br++;
    }
    return rezultat;
}
int main ()
{try{
    std::vector<std::string>v;
    std::cout<<"Unesite broj djece: ";
    int brDjece;
    std::cin>>brDjece;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::cin.ignore();
    for(int i=0; i<brDjece; i++){
         std::cin.clear();
        std::string s;
        std::getline(std::cin, s);
        v.push_back(s);
    }
    std::cout<<"Unesite broj timova: ";
    int brTimova;
    std::cin>>brTimova;
    auto rez(Razvrstavanje(v,brTimova));
    int br=1;
    for(auto kanta : rez){
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
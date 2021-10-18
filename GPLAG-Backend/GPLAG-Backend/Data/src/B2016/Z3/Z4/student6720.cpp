/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>
#include <iterator>

int BrojSlova(std::string ime){
    int broj_slova{};
    for(int i=0;i<ime.size();i++)
        if((ime[i]>='A' && ime[i]<='Z') || (ime[i]>='a' && ime[i]<='z') || (ime[i]>='0' && ime[i]<='9'))
            broj_slova++;
    return broj_slova;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int broj_timova){
    if(broj_timova<1 || broj_timova>imena.size())
        throw std::logic_error("Razvrstavanje nemoguce");
        
    std::list<std::string> imena_list;
    for(auto ime : imena)
        imena_list.push_back(ime);
        
    int broj_prvih_timova= (int)imena.size()%broj_timova;
    int broj_clanova=(int)imena.size()/broj_timova;
    
    std::vector<std::set<std::string>> razvrstana_djeca;
    std::list<std::string>::iterator it(imena_list.begin());
    int broj_slova=0;
    for(int i=0;i<broj_timova;i++){
        razvrstana_djeca.push_back({});
        for(int clan=0;clan<broj_clanova+(int)(i<broj_prvih_timova);clan++){
            for(int i=0;i<broj_slova;it++,i++)
                if(it==imena_list.end())it=imena_list.begin();
            if(it==imena_list.end())it=imena_list.begin();
            razvrstana_djeca[i].insert(*it);
            broj_slova=BrojSlova(*it);
            it=imena_list.erase(it);
            if(it==imena_list.begin()) it=--(imena_list.end());
            else it--;
        }
    }
    return razvrstana_djeca;   
}

int main (){
    std::cout<<"Unesite broj djece: ";
    int broj_djece;
    std::cin>>broj_djece;
    std::cin.ignore(1000,'\n');
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::vector<std::string> imena;
    for(int i=0;i<broj_djece;i++){
        std::string ime;
        std::getline(std::cin, ime);
        imena.push_back(ime);
    }
    
    std::cout<<"Unesite broj timova: ";
    int broj_timova;
    std::cin>>broj_timova;
    
    try{
        int i=1;
        for(auto tim: Razvrstavanje(imena, broj_timova)){
            std::cout<<"Tim "<<i++<<": ";
            auto ime=tim.begin();
            for(;ime!=--(tim.end());ime++)
                std::cout<<*ime<<", ";
            std::cout<<*ime<<std::endl;
        }
    }catch(std::logic_error izuzetak){std::cout<<"Izuzetak: "<<izuzetak.what();}
    
	return 0;
}
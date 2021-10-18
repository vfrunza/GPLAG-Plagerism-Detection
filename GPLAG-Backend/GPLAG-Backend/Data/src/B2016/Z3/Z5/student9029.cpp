#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

int BrojSlova(std::string ime){
    int broj_slova{};
    for(int i=0;i<ime.size();i++)
        if((ime[i]>='A' && ime[i]<='Z') || (ime[i]>='a' && ime[i]<='z') || (ime[i]>='0' && ime[i]<='9'))
            broj_slova++;
    return broj_slova;
}

struct Dijete {
    std::string ime;
    Dijete *sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int broj_timova){
    if(broj_timova<1 || broj_timova>imena.size())
        throw std::logic_error("Razvrstavanje nemoguce");
    
    Dijete *pocetak(nullptr), *prethodni;
    try{
    for(int i=0; i<imena.size();i++){
        Dijete *novi(new Dijete);
        novi->ime= imena[i]; novi->sljedeci=nullptr;
        if(!pocetak) pocetak= novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    }catch(std::bad_alloc){
        for(auto ime_alc=pocetak;ime_alc!=prethodni;ime_alc=ime_alc->sljedeci)
            delete ime_alc;
        throw std::bad_alloc();
    }
    std::vector<std::set<std::string>> razvrstana_djeca;
    int broj_prvih_timova= (int)imena.size()%broj_timova;
    int broj_clanova=(int)imena.size()/broj_timova;
    auto it=pocetak;
    
    int broj_slova{};
    for(int i=0;i<broj_timova;i++){
        razvrstana_djeca.push_back({});
        for(int clan=0;clan<broj_clanova+(int)(i<broj_prvih_timova);clan++){
            for(int slovo=0;slovo<broj_slova;slovo++){
               it=it->sljedeci; 
               prethodni=prethodni->sljedeci;
            }
            razvrstana_djeca[i].insert(it->ime);
            broj_slova=BrojSlova(it->ime);
            if(it==prethodni){delete it; continue;}
            prethodni->sljedeci=it->sljedeci;
            delete it;
            it=prethodni->sljedeci;
            broj_slova--;
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
    catch(std::bad_alloc){}
    
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>
#include <string>
#include <set>

bool SlovoIliCifra(char a){
    return ((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'));
}

int Duzina(std::string ime){
    int brojac(0);
    for(int i=0; i<ime.size(); i++) {
        if(SlovoIliCifra(ime[i]))
            brojac++;
    }
    return brojac;
}

void IspisiSkup(std::set<std::string> skup){
    auto it=skup.begin();
    if(it!=skup.end()){
        std::cout<<*it;
        it++;
    }
    while(it!=skup.end()){
        std::cout<<", "<<*it;
        it++;
    }
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> djeca, int BrojTimova){

    if(BrojTimova <=0 || BrojTimova > djeca.size()) {
        throw std::logic_error("Razvrstavanje nemoguce");
    }

    std::list<std::string> lista;
    std::vector<std::set<std::string>> timovi(BrojTimova);

    for(int i=djeca.size()-1; i>=0; i--) {
        lista.insert(lista.begin(), djeca[i]);
    }

    auto dijete=lista.begin();


    for(int i=0; i<BrojTimova; i++) {
        if((i+1)<=(djeca.size()%BrojTimova)) {
            for(int j=0; j<djeca.size()/BrojTimova+1; j++) {
                timovi[i].insert(*dijete);
                int pomak = Duzina(*dijete)-1;
                dijete=lista.erase(dijete);
                if(dijete==lista.end()) {
                    dijete=lista.begin();
                }
                for(int k=0; k<pomak; k++) {
                    dijete++;
                    if(dijete==lista.end()) {
                        dijete=lista.begin();
                    }
                }
            }
        } else {
            for(int j=0; j<djeca.size()/BrojTimova; j++) {
                timovi[i].insert(*dijete);
                int pomak = Duzina(*dijete)-1;
                dijete=lista.erase(dijete);
                if(dijete==lista.end()) {
                    dijete=lista.begin();
                }
                for(int k=0; k<pomak; k++) {
                    dijete++;
                    if(dijete==lista.end()) {
                        dijete=lista.begin();
                    }
                }
            }
        }
    }

    return timovi;
}

int main (){

    int broj_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_djece;
    std::cin.ignore(1000,'\n');
    
    std::cout<<"Unesite imena djece: "<<std::endl;
    
    std::string ime;
    std::vector<std::string> Djeca;
    
    for(int i=0; i<broj_djece; i++) {
        std::getline(std::cin,ime);
        Djeca.push_back(ime);
    }
    int broj_timova;
    
    std::cout<<"Unesite broj timova: ";
    std::cin>>broj_timova;
    try{
        auto v=Razvrstavanje(Djeca, broj_timova);
        for(int i=0;i<v.size();i++){
            std::cout<<"Tim "<<i+1<<": ";
            IspisiSkup(v[i]);
            std::cout<<std::endl;
        }
    }
    catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    return 0;
}
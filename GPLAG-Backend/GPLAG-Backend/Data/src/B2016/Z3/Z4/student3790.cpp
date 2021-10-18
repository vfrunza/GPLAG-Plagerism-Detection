/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <string>
#include <set>

int Znakovi(std::string ime) {
    int BrojZnakova(0);
    for(int i = 0; i < ime.size(); i++) {
        if((toupper(ime[i]) >= 'A' && toupper(ime[i]) <= 'Z') || (ime[i] >= '0' && ime[i] <= '9')) BrojZnakova++;
    }
    return BrojZnakova;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int broj_timova){
    if(broj_timova<1 || broj_timova>djeca.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    std::vector<std::set<std::string>> povratni(broj_timova);
    for(int i=0; i<djeca.size(); i++){
        lista.push_back(djeca[i]);          
    }
    int baza_tima;
    baza_tima=djeca.size()/broj_timova;      
    int broj_sa_vise;
    broj_sa_vise=djeca.size()%broj_timova; 
    std::vector<bool> mozel;                  
    for(int k=0; k<broj_sa_vise; k++){
        mozel.push_back(1);
    }
    for(int k=0; k<broj_timova-broj_sa_vise; k++){
        mozel.push_back(0);
    }
    auto it=lista.begin();
    int i=0;
    while(lista.size()!=0){
        povratni[i].insert(*it);           
        int velicina = Znakovi(*it);
        it = lista.erase(it);                    
        if(it == lista.end()) it = lista.begin();
        for(int j=0; j<velicina - 1; j++){                      
            it++;
            if(it==lista.end()) it=lista.begin();
        }
        //bool tacnost = 1;
        if(povratni[i].size()==baza_tima && mozel[i]==0) {         
            i++;
        }
        else if(povratni[i].size()==baza_tima + 1 && mozel[i] == 1) {
            i++;
        }
    }
    return povratni;
}
int main ()
{
    int broj_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_djece;
    std::cin.ignore(10000, '\n');
    std::cout<<"Unesite imena djece: " << std::endl;
    std::vector<std::string> imena;
    for(int i=0; i<broj_djece; i++){
        std::string ime;
        getline(std::cin, ime);
        imena.push_back(ime);
    }
    std::cout<<"Unesite broj timova: ";
    int broj_timova;
    std::cin>>broj_timova;
    try {
        std::vector<std::set<std::string>> ekipe;
        ekipe=Razvrstavanje(imena, broj_timova);
        for(int i=0; i<ekipe.size(); i++){
            std::cout<<"Tim "<<i+1<<": ";
            for(auto it=ekipe[i].begin(); it!=ekipe[i].end(); it++){
                if(*it == *ekipe[i].rbegin()) std::cout << *it;
                else std::cout<<*it<<", ";
            }
            std::cout<<std::endl;
        }
    }
    catch(std::logic_error izuzetak) { std::cout <<"Izuzetak: "<< izuzetak.what(); }
	return 0;
}
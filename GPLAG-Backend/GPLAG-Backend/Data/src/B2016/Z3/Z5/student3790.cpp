/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <set>

struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};

int Znakovi(std::string ime) {
    int BrojZnakova(0);
    for(int i = 0; i < ime.size(); i++) {
        if((toupper(ime[i]) >= 'A' && toupper(ime[i]) <= 'Z') || (ime[i] >= '0' && ime[i] <= '9')) BrojZnakova++;
    }
    return BrojZnakova;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int broj_timova){
    if(broj_timova<1 || broj_timova>djeca.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    Dijete *pocetak(nullptr);
    Dijete *prethodni;
    for(int i=0; i<djeca.size(); i++){
        Dijete *novi(new Dijete);
        novi->ime=djeca[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    auto *it=pocetak;
    while(it->sljedeci!=nullptr){
        it=it->sljedeci;
    }
    it->sljedeci=pocetak;
    std::vector<std::set<std::string>> povratni(broj_timova);
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
    it=pocetak;
    int izbaceni=0;
    int i=0;
    while(izbaceni!=djeca.size()){
        izbaceni++;
        povratni[i].insert(it->ime);           
        int velicina = Znakovi(it->ime);
        auto it1=it;
        while(it1->sljedeci!=it) it1=it1->sljedeci;
        it1->sljedeci=it->sljedeci;
        delete it;
        it=nullptr;
        if (izbaceni!=djeca.size()) it=it1->sljedeci;
        else break;
        for(int j=0; j<velicina - 1; j++){                      
            it=it->sljedeci;
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
    catch(std::logic_error izuzetak) { std::cout << "Izuzetak: "<<izuzetak.what(); }
	return 0;
}
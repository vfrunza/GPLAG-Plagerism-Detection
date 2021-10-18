/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <stdexcept>
#include <new>
#include <vector>
#include <string>
#include <set>

struct Dijete{
    std::string ime;
    Dijete* sljedeci;
};

bool SlovoIliCifra(char a){
    return ((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'));
}

int Duzina(std::string ime){
    int brojac(0);
    for(int i=0;i<ime.size();i++){
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

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int BrojTimova){

    std::vector<std::set<std::string>> timovi(BrojTimova);
    int n=djeca.size();
    
    if(BrojTimova<=0 || BrojTimova > djeca.size()){
        throw std::logic_error("Razvrstavanje nemoguce");
    }
    
    
    Dijete* pocetak=nullptr, *prethodni=nullptr;
    try{
    for(int i=0 ; i<djeca.size() ; i++){
        Dijete *novi (new Dijete);
        novi->ime=djeca[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci = novi;
        prethodni=novi;
    }
    if(n)
    prethodni->sljedeci = pocetak;}
    catch(std::bad_alloc){
        while(pocetak!=nullptr){
            Dijete* pomocna=pocetak;
            pocetak=pocetak->sljedeci;
            delete pomocna;
        }
        throw;
    }

    int x;
    Dijete* trenutni = pocetak;
    for(int i=0;i<BrojTimova;i++){
        if((i+1)<=(djeca.size()%BrojTimova)){x=djeca.size()/BrojTimova+1;}
        else {x=djeca.size()/BrojTimova;}
    
        for(int j=0;j<x;j++){
            timovi[i].insert(pocetak->ime);
            int pomak=Duzina(pocetak->ime)-1;
            Dijete* za_brisati=pocetak;
            for(int k=0;k<n-1;k++)
                trenutni=trenutni->sljedeci;
            pocetak=pocetak->sljedeci;
            delete za_brisati;
            n--;
            if(n){
                trenutni->sljedeci=pocetak;
                for(int k=0;k<pomak;k++)
                    pocetak=pocetak->sljedeci;
            }
            trenutni=pocetak;
        }
    }
    return timovi;
} 

int main ()
{
    int broj_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_djece;
    std::cin.ignore(1000,'\n');
    
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::string ime;
    std::vector<std::string> Djeca;
    
    for(int i=0;i<broj_djece;i++){
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
    catch(std::bad_alloc){
        std::cout<<"Alokacija nije uspjela";
    }
	return 0;
}
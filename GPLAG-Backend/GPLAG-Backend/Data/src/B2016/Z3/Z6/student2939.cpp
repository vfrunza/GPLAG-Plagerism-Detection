/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <stdexcept>
#include <new>
#include <memory>

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

int mod(int n, int k){
    int a(n/k);
    return n-a*k;
}

int DuzinaImena(std::string ime){
    int n(0);
    for(int i=0; i<ime.size(); i++)
        if((ime[i]>='A' && ime[i]<='Z') || (ime[i]>='a' && ime[i]<='z') || (ime[i]>='0' && ime[i]<='9')) n++;

    return n;
}

std::shared_ptr<Dijete> KreirajListu(const std::vector<std::string> &imena_djece){
    std::shared_ptr<Dijete> pocetak(nullptr), prethodni;
    std::string posljednje_ime(imena_djece[imena_djece.size()-1]);
    int i(0);
    for(;;){
     if(i==imena_djece.size()) break;
     std::string el(imena_djece[i]);
     try{
         auto novi(std::make_shared<Dijete> ());
         novi->ime=el;
         novi->sljedeci=nullptr;
         if(!pocetak) pocetak=novi;
         else prethodni->sljedeci=novi;
         prethodni=novi;
         if(i==imena_djece.size()-1) prethodni->sljedeci=pocetak;
     }
     catch(...){
         for(int k=0; k<i; k++){
             auto brisi(pocetak);
             pocetak=pocetak->sljedeci;
             brisi=nullptr;
         }
         throw;
     }
     i++;
    }
    return pocetak;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena_djece, int k){
    if(k<1 || k>imena_djece.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int n(imena_djece.size());
    auto pocetak_liste(KreirajListu(imena_djece));
    int prva_velicina(std::floor(n/k) + 1), broj_prvih_timova(mod(n,k)), 
    druga_velicina(std::floor(n/k));
    std::vector<std::set<std::string>> razvrstano(k);
    auto it(pocetak_liste), it1(pocetak_liste);
    std::shared_ptr<Dijete> prethodni;
    for(int i=0; i<n-1; i++) it1=it1->sljedeci;
    prethodni=it1;
    it1=nullptr;
    int prvi(0), duzina(0), broj(0);
    while(broj!=n-1){
        if(prvi<broj_prvih_timova){
            razvrstano[prvi].insert(it->ime);
            duzina=DuzinaImena(it->ime);
            broj++;
            it=it->sljedeci;
            prethodni->sljedeci=it;
            if(razvrstano[prvi].size()==prva_velicina) prvi++;
            if(broj==n-1) {razvrstano[prvi].insert(it->ime); it->sljedeci=nullptr; it=nullptr; break;}
        }
        else{
            razvrstano[prvi].insert(it->ime);
            duzina=DuzinaImena(it->ime);
            broj++;
            it=it->sljedeci;
            prethodni->sljedeci=it;
            if(razvrstano[prvi].size()==druga_velicina) prvi++;
            if(broj==n-1) { razvrstano[prvi].insert(it->ime); it->sljedeci=nullptr; it=nullptr; break;}
        }
        
        for(int i=0; i<duzina-1; i++){
            it=it->sljedeci;
            prethodni=prethodni->sljedeci;
        }
    }
    return razvrstano;
}
int main ()
{
    try{
        std::cout<<"Unesite broj djece: ";
        int n;
        std::cin>>n;
        std::cin.ignore(1000, '\n');
        std::cout<<"Unesite imena djece: "<<std::endl;
        std::vector<std::string> imena_djece(n);
        for(auto &x : imena_djece) std::getline(std::cin, x);
        std::cout<<"Unesite broj timova: ";
        int k;
        std::cin>>k;
        auto timovi(Razvrstavanje(imena_djece, k));
        for(int i=0; i<k; i++){
            std::cout<<"Tim "<<i+1<<": ";
            int j(0);
            for(auto x : timovi[i]){
                if(j==timovi[i].size()-1) std::cout<<x<<std::endl;
                else std::cout<<x<<", ";
                j++;
            }
        }
    }
    catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }
	return 0;
}
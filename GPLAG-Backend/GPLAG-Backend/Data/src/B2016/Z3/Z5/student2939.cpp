/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <stdexcept>
#include <new>

struct Dijete{
    std::string ime;
    Dijete* sljedeci;
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
void UnistiListu(Dijete* pocetak, std::string posljednje_ime){
    Dijete* k(pocetak);
    for(Dijete* p(pocetak->sljedeci); p->ime!=posljednje_ime; p=p->sljedeci){
        Dijete* l(k);
        k=k->sljedeci;
        delete l;
        if(k->ime==posljednje_ime) {delete k; break;}
    }
}

Dijete* KreirajListu(const std::vector<std::string> &imena_djece){
    Dijete *pocetak(nullptr), *prethodni;
    std::string posljednje_ime(imena_djece[imena_djece.size()-1]);
    int i(0);
    for(;;){
        if(i==imena_djece.size()) break;
        std::string el(imena_djece[i]);
        try{
            Dijete* novi(new Dijete);
            novi->ime=el; 
            novi->sljedeci=nullptr;
            if(!pocetak) pocetak=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
            if(i==imena_djece.size()-1) prethodni->sljedeci=pocetak;
        }
        catch(...){
            UnistiListu(pocetak, posljednje_ime);
            throw;
        }
      i++;  
    }
    return pocetak;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena_djece, int k){
    if(k<1 || k>imena_djece.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int n(imena_djece.size());
    auto* pocetak_liste(KreirajListu(imena_djece));
    int prva_velicina(std::floor(n/k)+1), broj_prvih_timova(mod(n,k));
    int druga_velicina(std::floor(n/k));
    std::vector<std::set<std::string>> razvrstano(k);
    auto it(pocetak_liste), it1(pocetak_liste);
    Dijete* prethodni;
    for(int i=0; i<n-1; i++)  it1=it1->sljedeci; 
    prethodni=it1;
    int prvi(0), duzina(0), broj(0);
    while(broj!=n-1){
        if(prvi<broj_prvih_timova){
            razvrstano[prvi].insert(it->ime);
            duzina=DuzinaImena(it->ime);
            broj++;
            auto obrisi(prethodni->sljedeci);
            it=it->sljedeci;
            prethodni->sljedeci=it;
            delete obrisi;
            if(razvrstano[prvi].size()==prva_velicina) prvi++;
            if(broj==n-1){razvrstano[prvi].insert(it->ime); delete it; break;}
        }
        else{
            razvrstano[prvi].insert(it->ime);
            duzina=DuzinaImena(it->ime);
            broj++;
            auto obrisi(prethodni->sljedeci);
            it=it->sljedeci;
            prethodni->sljedeci=it;
            delete obrisi;
            if(razvrstano[prvi].size()==druga_velicina) prvi++;
            if(broj==n-1){ razvrstano[prvi].insert(it->ime); delete it; break;}
        }
        for(int a=0; a<duzina-1 && it!=nullptr; a++){
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
        std::vector<std::string>imena_djece(n);
        std::cout<<"Unesite imena djece: ";
        for(auto &x : imena_djece) std::getline(std::cin, x);
        std::cout<<std::endl<<"Unesite broj timova: ";
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
/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <new>
#include <memory>

typedef std::vector<std::set<std::string>> VektorSkupovaStringova;


struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};


int Prebroji(std::string s) {
    int brojac(0);
    for(int i=0; i<s.length(); i++) {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            brojac++;
    }
    return brojac;
}

std::shared_ptr<Dijete> NadjiPrethodni(std::shared_ptr<Dijete> ovaj) {
    for(auto p=ovaj;; p=p->sljedeci) {
        if(p->sljedeci==ovaj) return p;
    }
}

std::shared_ptr<Dijete> Obrisi(std::shared_ptr<Dijete> &ovaj) {
    std::shared_ptr<Dijete> poslije_ovog(ovaj->sljedeci);
    std::shared_ptr<Dijete> prije_ovog(NadjiPrethodni(ovaj));
    if(prije_ovog->sljedeci==poslije_ovog) {
        ovaj->sljedeci=nullptr;
        return nullptr;
    }
    
    prije_ovog->sljedeci=poslije_ovog;
    return poslije_ovog;
    
}


VektorSkupovaStringova Razvrstavanje(std::vector<std::string> v, int br_timova) {
    
    if(br_timova<1 || br_timova>v.size())
        throw std::logic_error ("Razvrstavanje nemoguce");
    
    VektorSkupovaStringova timovi(br_timova);
    int br_djece(v.size());
    
    std::shared_ptr<Dijete> pocetak(nullptr);
    std::shared_ptr<Dijete> prethodni;
    try {
    for(int i=0; i<br_djece; i++) {
        
        std::shared_ptr<Dijete> novi(new Dijete);
        
        if(i==0) pocetak=novi;
        else prethodni->sljedeci=novi;
        novi->ime=v[i];
        novi->sljedeci=pocetak;
        prethodni=novi;
        
    }
    prethodni=nullptr; 
    
    for(int i=0; i<br_timova; i++) {
        int vel_tima;
        if(i+1<=br_djece%br_timova) vel_tima=(br_djece/br_timova)+1;
        else vel_tima=br_djece/br_timova;
        
        std::set<std::string> tim;
        
        for(int j=0; j<vel_tima; j++) {
            tim.insert(pocetak->ime);
            int br(Prebroji(pocetak->ime));
            pocetak=Obrisi(pocetak);
            if(pocetak==nullptr) {
                
                break;
            }
            pocetak=NadjiPrethodni(pocetak);
            for(int k=0; k<br; k++)
                pocetak=pocetak->sljedeci;
        }
        timovi[i]=tim;
    }
    }
    catch(...) { //Ukoliko se ne uspije alocirat neko dijete, hvata se izuzetak i postavljaju svi pokazivaci na nullptr kako bi doslo do dealokacije
        while(pocetak!=nullptr) {
            auto dalje(pocetak->sljedeci);
            pocetak=nullptr;
            pocetak=dalje;
        }
        throw;
    }
    
    return timovi;
}


int main ()
{
    std::vector<std::string> djeca;
    int n;
    
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::cin.ignore(1000, '\n');
    std::cout<<"Unesite imena djece: "<<std::endl;
    for(int i=0; i<n; i++) {
        std::string ime;
        std::getline(std::cin, ime);
        djeca.push_back(ime);
    }
    std::cout<<"Unesite broj timova: ";
    int br_timova;
    std::cin>>br_timova;
    try {
        VektorSkupovaStringova timovi(Razvrstavanje(djeca, br_timova));
        for(int i=0; i<timovi.size(); i++) {
            std::set<std::string> tim(timovi[i]);
            auto it(tim.begin());
            std::cout<<"Tim "<<i+1<<": ";
            while(it!=tim.end()) {
                if((++it)--==tim.end())
                    std::cout<<*it;
                else
                    std::cout<<*it<<", ";
                it++;
            }
            std::cout<<std::endl;
        }
    }
    
    catch(std::logic_error greska) {
        std::cout<<"Izuzetak: "<<greska.what();
    }
    catch(std::bad_alloc) {
        std::cout<<"Problemi sa memorijom";
    }
    
    return 0;
}
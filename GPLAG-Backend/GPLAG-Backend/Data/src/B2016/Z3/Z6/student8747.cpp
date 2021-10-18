/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci=nullptr;
};

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int broj_timova){
    if(broj_timova>v.size() || broj_timova<1) throw std::logic_error("Razvrstavanje nemoguce");
    std::shared_ptr<Dijete>pocetak(nullptr);
    std::shared_ptr<Dijete> kraj;
    for(int i=0;i<v.size();i++){
        std::shared_ptr<Dijete> novi(std::make_shared<Dijete>());
        novi->ime=v[i]; novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else kraj->sljedeci=novi;
        kraj=novi;
    }
    kraj->sljedeci=pocetak;
    if(broj_timova==1){
        std::set<std::string> skup;
        std::shared_ptr<Dijete> trenutni=pocetak;
        while(pocetak->sljedeci!=pocetak){
            skup.insert(pocetak->ime);
            pocetak=pocetak->sljedeci;
            kraj->sljedeci=pocetak;
            trenutni->sljedeci=nullptr;
            trenutni=pocetak;
        }
        skup.insert(pocetak->ime);
        pocetak->sljedeci=nullptr; pocetak=nullptr;kraj=nullptr; trenutni=nullptr;
        std::vector<std::set<std::string>> v2;
        v2.push_back(skup);
        return v2;
    }
    std::vector<std::string> poredani;
    int broj=v.size();
    while(broj!=0){
        int brojac=0;
        std::string s=pocetak->ime;
        std::shared_ptr<Dijete> trenutni=pocetak;
        if(broj>1){
            for(int i=0;i<s.size();i++){
                if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) brojac++;
            }
            pocetak=pocetak->sljedeci;
            kraj->sljedeci=pocetak;
            trenutni->sljedeci=nullptr;
            trenutni=pocetak;
            for(int i=0;i<brojac-1;i++){
                pocetak=pocetak->sljedeci;
                if(i==brojac-3) kraj=pocetak;
            }
        }else{
            kraj=nullptr; pocetak=nullptr; trenutni->sljedeci=nullptr; trenutni=nullptr;
        }
        poredani.push_back(s);
        broj--;
    }
    std::vector<std::set<std::string>> timovi;
    int h=v.size()/broj_timova;
    int g=v.size()%broj_timova;
    for(int i=0;i<broj_timova;i++){
        int broj_clanova=h;
        std::set<std::string> skup;
        if(i<g) broj_clanova+=1;
        for(int j=0;j<broj_clanova;j++){
            skup.insert(poredani[0]);
            poredani.erase(poredani.begin());
        }
        timovi.push_back(skup);
    }
    return timovi;
}

int main ()
{
    try{
        std::cout << "Unesite broj djece: ";
        int broj;
        std::cin >> broj;
        std::cin.ignore(10000, '\n');
        std::cout << "Unesite imena djece: " << std::endl;
        std::vector<std::string> v;
        for(int i=0;i<broj;i++){
            std::string s;
            std::getline(std::cin,s);
            v.push_back(s);
        }
        std::cout << "Unesite broj timova: ";
        int x;
        std::cin >> x;
        auto m=Razvrstavanje(v,x);
        for(int i=0;i<m.size();i++){
            std::cout << "Tim " << i+1 << ": ";
            auto skup=m[i];
            for(auto it=skup.begin(); it!=skup.end();it++){
                auto c=it;
                c++;
                if(c==skup.end()) std::cout << *it << std::endl;
                else std::cout << *it << ", ";
            }
        }
        return 0;
    }catch(std::logic_error e){
        std::cout << "Izuzetak: " <<  e.what() << std::endl;
        return 0;
    }
}
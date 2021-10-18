/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <set>
#include <memory>

struct Dijete{
  std::string ime;
  std::shared_ptr<Dijete> sljedeci;
};

int OdrediDuzinu(const std::string &s){
    int duzina(0);
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')) duzina++;
    }
    return duzina;
}

std::vector<int> OdrediKapacitet(int broj_djece, int broj_timova){
    std::vector<int> v;
    int def(broj_djece/broj_timova);
    int mod(broj_djece%broj_timova);
    int i;
    for(i=0;i<broj_timova;i++){
        v.push_back(def);
    }
    i=0;
    while(mod>0){
        v[i]=v[i]+1;
        mod--;
        i++;
    }
    return v;
}

std::shared_ptr<Dijete> NoviClan(std::shared_ptr<Dijete> pok, int broj_iteracija){
    auto novipok=pok;
    for(auto i=0;i<broj_iteracija-1;i++)novipok=novipok->sljedeci;
    return novipok;
}

/*void IzbrisiClan(Dijete* pok,int n){
    auto pomocni(pok);
    static int brojac(0);
    brojac++;
    if(brojac==n)delete pok;
    else{
        pok=pok->sljedeci;
        delete pomocni;
    }
}*/


std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int n){
    if(n<1 || v.size()<n) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::shared_ptr<Dijete> pocetak(nullptr), prethodni;
    for(int i=0;i<v.size();i++){
        std::shared_ptr<Dijete> novi(std::make_shared<Dijete>());
        novi->ime=v[i]; novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    
    std::vector<std::set<std::string>> rez;
    std::vector<int> kapaciteti;
    kapaciteti=OdrediKapacitet(v.size(),n);
    int broj(v.size());
    for(int i=0;i<n;i++){
        int broj_clanova=kapaciteti[i];
        std::set<std::string> skup;
        for(int j=0;j<broj_clanova;j++){
            skup.insert(pocetak->ime);
            broj--;
            if(broj>1){
                auto skip(pocetak->sljedeci);
                prethodni->sljedeci=skip;
                auto pomocni(pocetak);
                int move=OdrediDuzinu(pocetak->ime);
                pocetak=pocetak->sljedeci;
                pocetak=NoviClan(pocetak, move);
                prethodni=NoviClan(prethodni, move);
                }
             else if(broj==1){
                auto brisi(pocetak);
                pocetak=pocetak->sljedeci;
            }
            else{
                pocetak->sljedeci=nullptr;
            }
        }
        rez.push_back(skup);
    }
    return rez;
}

int main(){
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::vector<std::string> v;
    std::cin.ignore(1000,'\n');
    for(int i=0;i<n;i++){
        std::string ime;
        std::getline(std::cin, ime);
        v.push_back(ime);
    }
    std::cout<<"Unesite broj timova: ";
    int broj_timova;
    std::cin>>broj_timova;
    std::vector<std::set<std::string>> rez;
    try{
    rez=Razvrstavanje(v, broj_timova);
    for(int i=0;i<rez.size();i++){
        std::cout<<"Tim "<<i+1<<": ";
        auto end(rez[i].end());
        end--;
        for(auto it=rez[i].begin();it!=rez[i].end();it++){
            std::cout<<*it;
            if(it!=end) std::cout<<", ";
        }
        std::cout<<std::endl;
    }
    }
    catch(std::logic_error msg){
        std::cout<<"Izuzetak: "<<msg.what();
    }
    return 0;
}
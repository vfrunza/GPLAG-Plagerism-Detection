/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include<set>
#include<vector>
#include<string>
#include<stdexcept>
#include<memory>

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete>sljedeci;
};

int broj_znakova(std::string s){
    int broj=0;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) broj++;
    }
    return broj;
}
std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string>v, int broj_timova){
   if(broj_timova<1 || broj_timova>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
   
   std::shared_ptr<Dijete> pocetak(nullptr);
   std::shared_ptr<Dijete> prethodni(nullptr);
    try{
    for(int i=0;i<v.size();i++){
        std::shared_ptr<Dijete> novi(new Dijete);
        if(pocetak==nullptr) pocetak=novi;
        else prethodni->sljedeci=novi;
        novi->ime=v[i];
        novi->sljedeci=pocetak;
        prethodni=novi;
     }
    }
    catch(...){
        while(pocetak!=prethodni){
           std::shared_ptr<Dijete>pom=pocetak;
            pocetak=pocetak->sljedeci;
            pom->sljedeci=nullptr;
            pom=nullptr;
        }
        prethodni=nullptr;
    }
    
    int mod=v.size()%broj_timova;
    std::vector<std::set<std::string>>vrati;
    vrati.resize(broj_timova);
    int n=v.size();
    int limit;
    std::shared_ptr<Dijete>trenutni=pocetak;
    for(int i=0;i<broj_timova;i++){
        if(i<mod) limit=(int) n/broj_timova+1;
        else limit=(int)n/broj_timova;
        std::set<std::string>s;
        for(int i=0;i<limit;i++){
            s.insert(trenutni->ime);
            int brojac=1;
            int j=broj_znakova(trenutni->ime);
            std::shared_ptr<Dijete>pom;
            pom=trenutni;
            while(pom->sljedeci!=trenutni){
                pom=pom->sljedeci;
            }
            pom->sljedeci=trenutni->sljedeci;
            if(pom->sljedeci==trenutni){
                trenutni->sljedeci=nullptr;
                break;
            }
            trenutni=nullptr;
            trenutni=pom->sljedeci;
            while(brojac<j){
                trenutni=trenutni->sljedeci;
                brojac++;
            }
        }
        vrati[i]=s;
    }
    return vrati;
    
}
int main ()
{
    try{
        std::cout<<"Unesite broj djece: ";
        int n;
        std::cin>>n;
        std::cout<<"Unesite imena djece: \n";
        std::vector<std::string>v;
        v.resize(n);
        std::cin.ignore(1000,'\n');
        for(int i=0;i<n;i++){
            std::string s;
            std::getline(std::cin, s);
            v[i]=s;
        }
        std::cout<<"Unesite broj timova: ";
        int br;
        std::cin>>br;
        std::vector<std::set<std::string>> vrati=Razvrstavanje(v,br);
        for(int i=0;i<vrati.size();i++){
            std::cout<<"Tim "<<i+1<<": ";
            auto zadnji=vrati[i].end();
            zadnji--;
            for(auto it=vrati[i].begin();it!=vrati[i].end();it++){
                if(it!=zadnji) std::cout<<*it<<", ";
                else std::cout<<*it;
            }
            std::cout<<std::endl;
        }
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}
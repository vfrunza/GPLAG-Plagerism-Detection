/B2016/2017: Zadaća 3, Zadatakk 6
#include <iostream>
#include <string>
#include <vector> 
#include <stdexcept>
#include <set>
#include <memory>

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci=nullptr;
};

int dajduzinu(std::string a){
    int r=0;
    for(auto i:a)if((i>='a' && i<='z')||(i>='A' && i<='Z')||(i>='0' && i<='9'))r++;
    return r;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k){
    int n=v.size();
    if(k<1 || k>n)throw std::logic_error("Razvrstavanje nemoguce");
    std::shared_ptr<Dijete> trenutni;
    try{
        trenutni=std::make_shared<Dijete> ();
    }
    catch(...){
        throw;
    }
    trenutni->ime=v[0];
    std::shared_ptr<Dijete> pocetak=trenutni;
    std::shared_ptr<Dijete> prethodni=trenutni;
    for(int i=1;i<n;i++){
        try{
            trenutni->sljedeci=std::make_shared<Dijete>();
        }
        catch(...){
            throw;
        }
        trenutni->sljedeci->ime=v[i];
        trenutni=trenutni->sljedeci;
        prethodni=trenutni;
    }
    trenutni->sljedeci=pocetak;
    std::vector<std::set<std::string>> rjes(k);
    std::vector<int> veltima(k, n/k);
    for(int i=0;i<n%k;i++){
        veltima[i]++;
    }
    int kojitim=0;
    int ostalo=n;
    trenutni=pocetak;
    while(ostalo){
        int g=dajduzinu(trenutni->ime);
        if(veltima[kojitim]==rjes[kojitim].size()){
            kojitim++;
        }
        rjes[kojitim].insert(trenutni->ime);
        prethodni->sljedeci=trenutni->sljedeci;
        if(ostalo==1){
            trenutni->sljedeci=nullptr;
            trenutni=nullptr;
            break;
        }
        trenutni=nullptr;
        trenutni=prethodni->sljedeci;
        while(--g){
            trenutni=trenutni->sljedeci;
            prethodni=prethodni->sljedeci;
        }
        ostalo--;
    }
    return rjes;
}

int main ()
{
    try{
        int n;
        std::cout<<"Unesite broj djece: ";
        std::cin>>n;
        std::cin.ignore(1000, '\n');
        std::vector<std::string> v(n);
        std::cout<<"Unesite imena djece:\n";
        for(auto &i:v)std::getline(std::cin, i);
        int k;
        std::cout<<"Unesite broj timova: ";
        std::cin>>k;
        auto a=Razvrstavanje(v, k);
        int b=0;
        for(auto i:a){
            std::cout<<"Tim "<<++b<<":";
            for(auto j=i.begin();j!=i.end();){
                std::cout<<" "<<*j;
                if(++j!=i.end())std::cout<<",";
            }
            std::cout<<'\n';
        }
    }
    catch(std::logic_error gg){
        std::cout<<"Izuzetak: "<<gg.what();
    }
    catch(...){
        return 0;
    }
	return 0;
}
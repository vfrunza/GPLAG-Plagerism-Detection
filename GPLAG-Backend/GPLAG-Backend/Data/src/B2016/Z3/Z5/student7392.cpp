/B2016/2017: Zadaća 3, Zadatakk 5
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <set>

struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};

int dajduzinu(std::string s){
    int r=0;
    for(auto i:s)if((i>='0' && i<='9')||(i>='a' && i<='z')||(i>='A' && i<='Z'))r++;
    return r;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k){
    int n=v.size();
    if(k<1 || k>n)throw std::logic_error("Razvrstavanje nemoguce");
    Dijete *trenutni;
    try{
        trenutni=new Dijete{v[0], nullptr};
    }
    catch(...){
        throw;
    }
    Dijete *pocetak=trenutni;
    Dijete *prethodni=trenutni;
    for(int i=1;i<n;i++){
        try{
            trenutni->sljedeci=new Dijete{v[i], nullptr};
        }
        catch(...){
            Dijete *temp;
            while(true){
                temp=pocetak->sljedeci;
                delete pocetak;
                pocetak=temp;
                if(temp==nullptr)throw;
            }
        }
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
    while(ostalo!=0){
        int g=dajduzinu(trenutni->ime);
        if(veltima[kojitim]==rjes[kojitim].size()){
            kojitim++;
        }
        rjes[kojitim].insert(trenutni->ime);
        prethodni->sljedeci=trenutni->sljedeci;
        delete trenutni;
        if(ostalo!=1){
            trenutni=prethodni->sljedeci;
            while(--g){
                trenutni=trenutni->sljedeci;
                prethodni=prethodni->sljedeci;
            }
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
            std::cout<<"\n";
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
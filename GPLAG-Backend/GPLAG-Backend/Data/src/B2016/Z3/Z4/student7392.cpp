/B2016/2017: Zadaća 3, Zadatakk 4
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

int dajduzinu(std::string a){
    int k=0;
    for(auto i:a)if((i>='a' && i<='z')||(i>='A' && i<='Z')||(i>='0' && i<='9'))k++;
    return k;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k){
    int n=v.size();
    if(k<1 || k>n)throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> rjes(k);
    std::list<std::string> l(n);
    std::copy(v.begin(), v.end(), l.begin());
    std::vector<int> veltima(k, n/k);
    for(int i=0;i<n%k;i++){
        veltima[i]++;
    }
    auto kogatreba=l.begin();
    int kojitim=0;
    while(!l.empty()){
        int g=dajduzinu(*kogatreba);
        if(veltima[kojitim]==rjes[kojitim].size()){
            kojitim++;
        }
        rjes[kojitim].insert(*kogatreba);
        kogatreba=l.erase(kogatreba);
        if(l.size()==0)break;
        if(kogatreba==l.end())kogatreba=l.begin();
        for(int i=1;i<g;i++){
            kogatreba++;
            if(kogatreba==l.end())kogatreba=l.begin();
        }
    }
    return rjes;
}

int main ()
{
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
    try{
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
	return 0;
}
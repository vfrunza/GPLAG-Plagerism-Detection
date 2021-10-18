/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <string>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> vek,int k)
{
    int n=vek.size();
    if(k<=0 || k>vek.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    std::copy(vek.begin(),vek.end(),std::back_inserter(lista));
    int clan=0,skup=0,uskupu=0;
    std::vector<std::set<std::string>> timovi(k);
    auto it=lista.begin();
    while(lista.size()!=0)
    {
        if(clan<=1)
        {
           clan=std::count_if((*it).begin(),(*it).end(),[](char x){return ((x>='A'&&x<='Z')||(x>='a'&&x<='z')||(x>='0'&&x<='9'));});
           timovi[skup].insert(*it);
           uskupu++;
           if(skup<n%k && uskupu==n/k+1) skup++,uskupu=0;
           if(skup>=n%k && uskupu==n/k) skup++,uskupu=0;
           it=lista.erase(it);
           if(it==lista.end()) it=lista.begin();
        }
        else{ it++;
        clan--;}
        if(it==lista.end()) it=lista.begin();
    }
    return timovi;
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite imena djece:\n";
    if(n>0)std::cin >> std::ws;
    std::vector<std::string> vek (n);
    for(std::string &s:vek) std::getline(std::cin, s);
    std::cout << "Unesite broj timova: ";
    std::cin >> n;
    try
    {
        std::vector<std::set<std::string>> s=Razvrstavanje(vek,n);
        for(int i=0;i<n;i++)
        { 
            std::cout << "Tim " << i+1 << ": ";
            bool prvi=true;
            for(auto b:s[i])
            {
                if(!prvi) std::cout << ", ";
                std::cout << b; 
                prvi=false;
            }
            std::cout << "\n";
        }
    }
    catch(std::logic_error x){std::cout << "Izuzetak: " << x.what();}
	return 0;
}

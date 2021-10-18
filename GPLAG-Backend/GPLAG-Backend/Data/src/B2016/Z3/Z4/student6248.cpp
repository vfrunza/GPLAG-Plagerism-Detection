/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <iterator>
#include <cmath>
#include <stdexcept>

int Duzina(std::string s)
{
    int br(0);
    for(int i(0); i<s.length(); i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) br++;
    }
    return br;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k)
{
    if(k<1 || k>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    int n(v.size());
    int broj_timova1(n%k);
    int clanovi_prvog_tima((n/k)+1);
    int clanovi_drugog_tima(n/k);
    
    std::list<std::string> lista;
    for(int i(0); i<v.size(); i++)
    {
        lista.push_back(v[i]);
    }
    
    std::vector<int> clanovi(k);
    for(int i(0); i<broj_timova1; i++) clanovi[i]=clanovi_prvog_tima;
    for(int i(broj_timova1); i<k; i++) clanovi[i]=clanovi_drugog_tima;
    
    std::vector<std::set<std::string>> timovi(k);
    auto iter(lista.begin());
    for(int i(0); i<k; i++)
    {
        int br_clanova(clanovi[i]);
        
        while(!lista.empty() && br_clanova!=0)
        { 
            std::string dijete;
            dijete=*iter;
            int duzina(Duzina(dijete));
            iter=lista.erase(iter);
            if(iter==lista.end()) iter=lista.begin();
            br_clanova--;
            timovi[i].insert(dijete);
            
            for(int p(1); p<duzina; p++)
            {
                iter++;
                if(iter==lista.end()) iter=lista.begin();
            }
        }
    }
    return timovi;
}

int main ()
{
    try
    {
        std::cout << "Unesite broj djece: ";
        int n; 
        std::cin >> n;
        std::cout << "Unesite imena djece: " << std::endl;;
        std::cin.ignore(10000,'\n');
        std::vector<std::string> v(n);
        for(int i(0); i<n; i++)
        {
            std::getline(std::cin, v[i]);
        }
        std::cout << "Unesite broj timova: ";
        int k;
        std::cin >> k;
        std::vector<std::set<std::string>> s;
        s=Razvrstavanje(v,k);
        for(int i(0); i<k; i++)
        {
            std::cout << "Tim " << i+1 << ": ";
            int duzina(std::distance(s[i].begin(),s[i].end()));
            auto it(s[i].begin());
            for(int j(0); j<duzina-1; j++)
            {
                std::cout << *it++ << ", ";
            } 
            std::cout << *it << std::endl;
        }
    }
    catch(std::logic_error izuzetak)
    {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
	return 0;
}
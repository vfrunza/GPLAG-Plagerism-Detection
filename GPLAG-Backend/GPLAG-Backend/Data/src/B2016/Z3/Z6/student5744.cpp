/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <memory>

struct Dijete
{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> vek,int k)
{
    int n=vek.size();
    if(k<=0 || k>vek.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int clan=0;
    std::shared_ptr<Dijete> tr=nullptr,poc=nullptr;
    std::vector<std::set<std::string>> timovi(k);
    for(int i=0;i<n;i++)
    {
        try
        {
            std::shared_ptr<Dijete> novi(new Dijete);
            novi->ime=vek[i];
            if(!poc) poc=novi;
            else (tr->sljedeci)=novi;
            novi->sljedeci=poc;
            tr=novi;
        }
        catch(std::bad_alloc x)
        {
            for(int k=0;k<i;k++)
            {
                tr->sljedeci=poc->sljedeci;
                poc=tr->sljedeci;
            }
            tr->sljedeci=nullptr;
            throw x;
        }
    }
    int vel=n,skup=0,uskupu=0;
    while(1)
    {
        if(clan<=1)
        {
            tr->sljedeci=poc->sljedeci;
            clan=std::count_if(poc->ime.begin(),poc->ime.end(),[](char x){return ((x>='A'&&x<='Z')||(x>='a'&&x<='z')||(x>='0'&&x<='9'));});
            timovi[skup].insert(poc->ime);
            vel--;
            uskupu++;
            if(skup<n%k && uskupu==n/k+1) skup++,uskupu=0;
            if(skup>=n%k && uskupu==n/k) skup++,uskupu=0;
            if(vel)poc=tr->sljedeci;
            else break;
        }
        else
        {
            clan--;
            tr=tr->sljedeci;
            poc=poc->sljedeci;
        }
    }
     tr->sljedeci=nullptr;
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
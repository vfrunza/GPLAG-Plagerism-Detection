/B2016/2017: Zadaća 3,  Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <string>
#include <list>
int broj_slova(std::string s)
{
    int cnt = 0;
    for(auto e: s) cnt += ((e>='0' && e<='9') || (e>='a' && e<='z') || (e>='A' && e<='Z'));
    return cnt;
}
std::vector<std::set<std::string> > Razvrstavanje(std::vector<std::string> v, int tim)
{
    if(tim < 1 || tim > v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    for(auto e: v) lista.push_back(e);
    std::vector<std::set<std::string> > rez(tim);
    std::list<std::string>::iterator iter = lista.begin();
    int vrti = 0;
    for(int t=0; t < tim; t++)
    {
        for(int c = 0; c < v.size()/tim + (t < v.size() % tim); c++)
        {
            for(int i=1; i<vrti; i++)
            {
                auto sepet = lista.end(); 
                if(iter == lista.end() || iter == --sepet) iter = lista.begin();
                else iter++;
            }
            vrti = broj_slova(*iter);
            rez[t].insert(*iter);
            iter = lista.erase(iter);
            if(iter == lista.end()) iter = lista.begin();
        }
    }
    return rez;
}
int main ()
{
    std::vector<std::string> v;
    std::string s;
    int N;
    std::cout<<"Unesite broj djece: ";
    std::cin>> N;
    std::cin.ignore(1000,'\n');
    std::cout<<"Unesite imena djece:\n";
    for(int i=0;i<N;i++) 
    {
        std::getline(std::cin, s);
        v.push_back(s);
    }
    std::cout<< "Unesite broj timova: ";
    std::cin>> N;
    try
    {
        auto hehe = Razvrstavanje(v, N);
        for(int i=0;i<N;i++)
        {
            std::cout<< "Tim "<<i+1<<": ";
            for(auto e: hehe[i]) 
                if(*hehe[i].rbegin() != e) std::cout<<e<<", ";
                else std::cout<<e<<"\n";
            
        }
    }
    catch(std::logic_error e)
    {
        std::cout<<"Izuzetak: "<< e.what();
    }
	return 0;
}
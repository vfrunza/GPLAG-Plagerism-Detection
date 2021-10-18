/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <set> 
#include <cmath>
#include <iterator>
#include <stdexcept>
typedef std::vector<std::set<std::string>> grupe;
bool Slovo (char a)
{
    if((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
        return true;
    return false;
}
bool Broj(char a)
{
    if(a >= '0' && a <= '9') return true;
    return false;
}
int BrojSlova(std::string s)
{
    int brojac(0);
    for(int i = 0; i < s.size(); i++)
        if(Slovo(s[i]) || Broj(s[i])) brojac++;
    return brojac;
}
grupe Razvrstavanje (std::vector<std::string> v, int k)
{
    if(k < 1 || k > v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    grupe g(k);
    int n(v.size());
    std::list<std::string> lista(n);
    std::list<std::string>::iterator a(std::copy(v.begin(), v.end(), lista.begin()));
    std::vector<int> tim(k);
    if(n % k == 0) for(int i = 0; i < k; i++) tim[i] = n / k;
    else {
        for(int i = 0; i < n % k; i++)
            tim[i] = floor(n / k) + 1;
        for(int i = n % k; i < k; i++)
            tim[i] = floor(n / k);
    }
    int brojac(0), brojac2(0);
    for(auto it = lista.begin(); lista.size() != 0;)
    {
        if(it == lista.end()) it = lista.begin();
        int broj(BrojSlova(*it) - 1);
        g[brojac].insert(*it);
        brojac2++;
        if(brojac2 == tim[brojac])
        {
            brojac++;
            brojac2 = 0;
        }
        it = lista.erase(it);
        for(int i = 0; i < broj; i++)
        {
            if(it == lista.end())  it = lista.begin(); 
           it++;
           if(it == lista.end())  it = lista.begin();
        }
        if(it == lista.end()) it = lista.begin();
    }
    return g;
} 
int main ()
{
    try {
        int n; 
        std::cout<<"Unesite broj djece: ";
        std::cin>>n;
        std::vector<std::string> s(n);
        std::cin.ignore(10000, '\n');
        std::cout<<"Unesite imena djece: \n";

        for(int i = 0; i < n; i++)
        {
            std::getline(std::cin, s[i]);

        }
        int k;
        std::cout<<"Unesite broj timova: ";
        std::cin>>k;
        grupe g(Razvrstavanje(s, k));
        int brojac(0);
        for(int i = 0; i < g.size(); i++)
        {
            std::cout<<"Tim "<<i+1<<": ";
            for(auto j = g[i].begin(); j != g[i].end(); j++)
            {
                std::cout<<*j;
                if(brojac < g[i].size() - 1) std::cout<<", ";
                brojac++;
            } std::cout<<std::endl;
            brojac = 0;
        }
    }
    catch(std::logic_error izuzetak)
    {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
} 
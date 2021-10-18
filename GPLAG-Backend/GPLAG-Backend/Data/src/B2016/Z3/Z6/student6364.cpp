/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set> 
#include <cmath>
#include <memory>
#include <stdexcept>
typedef std::vector<std::set<std::string>> grupe;
struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};
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
int BrojSlova(std::string &s)
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
    std::shared_ptr<Dijete> pocetak = nullptr, prethodni;
    try {
        for(int i = 0; i < n; i++)
        {
            std::shared_ptr<Dijete> novo(new Dijete);
            novo->ime = v[i]; novo->sljedeci = nullptr;
            if(!pocetak) pocetak = novo;
            else prethodni->sljedeci = novo;
            prethodni = novo;
        } prethodni->sljedeci = pocetak;
    } catch(std::bad_alloc) {
        if(pocetak.get() == nullptr) throw;
        pocetak -> sljedeci = nullptr;
        throw;
    }
    std::vector<int> tim(k);
    if(n % k == 0) for(int i = 0; i < k; i++) tim[i] = n / k;
    else {
        for(int i = 0; i < n % k; i++)
            tim[i] = floor(n / k) + 1;
        for(int i = n % k; i < k; i++)
            tim[i] = floor(n / k);
    }
    int brojac(0), brojac2(0);
    for(std::shared_ptr<Dijete> p = pocetak; pocetak != prethodni;)
    {
        int broj(BrojSlova(p->ime) - 1);
        g[brojac].insert(p->ime);
        brojac2++;
        if(brojac2 == tim[brojac])
        {
            brojac++; brojac2 = 0;
        }
        p = p -> sljedeci;
        prethodni -> sljedeci = p;
        if(p == prethodni)
        {
            g[brojac].insert(p -> ime);
            p -> sljedeci = nullptr;
            break;
        }
        for(int i = 0; i < broj; i++)
        {
            p = p -> sljedeci;
            prethodni = prethodni->sljedeci;
        }
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
        std::cout<<"Unesite imena djece: \n";
        std::cin.ignore(10000, '\n');
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
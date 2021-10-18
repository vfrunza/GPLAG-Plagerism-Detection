#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>
int BrojSlova(std::string s)
{
    int brojac(0);
    for(int i(0); i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
            brojac++;
        else if(s[i] >= 'a' && s[i] <= 'z')
            brojac++;
        else if(s[i] >= 'A' && s[i] <= 'Z')
            brojac++;
    }
    return brojac;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int brojTimova)
{
    if(brojTimova < 1 || brojTimova > v.size())
        throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    for(int i(0); i < v.size(); i++)
        lista.push_back(v[i]);
        
    int brojDjece = v.size();
    int brojTimovaSaClanomVise = brojDjece % brojTimova;
    std::vector<std::set<std::string>> clanovi(brojTimova);
    std::vector<int>brojClanovaPoTimu(brojTimova, brojDjece/brojTimova);
    for(int i(0); i < brojTimovaSaClanomVise; i++)
       brojClanovaPoTimu[i]++;
        
    auto p(lista.begin()), k(lista.end());
    int brojSlova = BrojSlova(*p);
    clanovi[0].insert(*p);
    p = lista.erase(p);
    
    int brojDjeceUTimu = 1;
    int brojSkupa = 0;
    for(int i(1); i < v.size(); i++)
    {
        if(brojDjeceUTimu == brojClanovaPoTimu[brojSkupa])
        {
            brojSkupa++;
            brojDjeceUTimu = 0;
        }
        int brojac(1);
        while(brojac < brojSlova)
        {
            p++;
            brojac++;
            if(p == k)
                p = lista.begin();
        }
        brojSlova = BrojSlova(*p);
        clanovi[brojSkupa].insert(*p);
        brojDjeceUTimu++;
        p = lista.erase(p);
        if(p == k)
            p = lista.begin();
    }
    return clanovi;
}
int main ()
{
    try
    {
        std::cout << "Unesite broj djece: ";
        int n;
        std::cin >> n;
        std::cout << "Unesite imena djece: \n";
        std::vector<std::string> v;
        std::cin.ignore(1000, '\n');
        for(int i(0); i < n; i++)
        {
            std::string s;
            std::getline(std::cin, s);
            v.push_back(s);
        }
        std::cout << "Unesite broj timova: ";
        std::cin >> n;
        auto novi = Razvrstavanje(v, n);
        for(int i(0); i < n; i++)
        {
            std::cout << "Tim " << i + 1<< ": ";
            auto pok = novi[i].begin();
            for(int j(0); j < novi[i].size() - 1; ++j, ++pok)
                std::cout << *pok << ", ";
            std::cout << *pok << std::endl;
        }
    	return 0;
    }
    catch(std::logic_error e)
    {
        std::cout << "Izuzetak: " << e.what();
        return 0;
    }
}
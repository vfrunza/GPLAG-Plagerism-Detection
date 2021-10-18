#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>
struct Dijete
{
    std::string ime;
    Dijete *sljedeci;
};
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
    Dijete *pocetak(nullptr), *prethodni(nullptr);
    try
    {
        for(int i(0); i < v.size(); i++)
        {
            Dijete *novo(new Dijete);
            novo->ime = v[i];
            novo->sljedeci = nullptr;
            if(!pocetak)
                pocetak = novo;
            else
                prethodni->sljedeci = novo;
            prethodni = novo;
        }
    }
    catch(std::bad_alloc)
    {
        while (pocetak != nullptr) {
            Dijete *temp = pocetak->sljedeci;
            delete pocetak;
            pocetak = temp;
        }
    }
    prethodni->sljedeci = pocetak;
    
    int brojDjece = v.size();
    int brojTimovaSaClanomVise = brojDjece % brojTimova;
    std::vector<std::set<std::string>> clanovi(brojTimova);
    std::vector<int>brojClanovaPoTimu(brojTimova, brojDjece/brojTimova);
    for(int i(0); i < brojTimovaSaClanomVise; i++)
       brojClanovaPoTimu[i]++;
        
    
    int brojSlova = BrojSlova(pocetak->ime);
    clanovi[0].insert(pocetak->ime);
    Dijete *obrisi(pocetak);
    pocetak = pocetak->sljedeci;
    prethodni->sljedeci = pocetak;
    delete obrisi;
    
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
            pocetak = pocetak->sljedeci;
            brojac++;
            prethodni = prethodni->sljedeci;
        }
        brojSlova = BrojSlova(pocetak->ime);
        clanovi[brojSkupa].insert(pocetak->ime);
        brojDjeceUTimu++;
        Dijete *obrisi(pocetak);
        pocetak = pocetak->sljedeci;
        prethodni->sljedeci = pocetak;
        delete obrisi;
        
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
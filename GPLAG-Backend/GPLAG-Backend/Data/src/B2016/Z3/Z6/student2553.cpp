/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <memory>

struct Dijete
{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

typedef std::vector<std::set<std::string>> Timovi;

Timovi Razvrstavanje (std::vector<std::string> djeca, int br_timova)
{
    if (br_timova < 1 || br_timova > djeca.size())
        throw std::logic_error("Razvrstavanje nemoguce");
    
    Timovi timovi;
    std::shared_ptr<Dijete> novo, prethodno, prvo(nullptr);
    try
    {
        for (int i = 0; i < djeca.size(); i++)
        {
            novo = std::make_shared<Dijete>();
            novo->ime = djeca[i]; novo->sljedeci = nullptr;
            if (!prvo) prvo = novo;
            else prethodno->sljedeci = novo;
            prethodno = novo;
        }
    }
    catch(std::bad_alloc)
    {
        throw;
    }
    prethodno->sljedeci = prvo;
    
    int tim(0), vel_tima, u_timu(0), naprijed(0), preostalih(djeca.size());
    std::shared_ptr<Dijete> p(prvo);
    while (preostalih)
    {
        if (tim < djeca.size()%br_timova) vel_tima = djeca.size()/br_timova  + 1;
        else vel_tima = djeca.size()/br_timova;
        
        timovi.push_back(std::set<std::string>());
        while (u_timu < vel_tima)
        {
            for (int i = 0; i < naprijed; i++){prethodno = p; p = p->sljedeci;}
            naprijed = std::count_if(p->ime.begin(), p->ime.end(), 
            [](char x)
            {
                if (x < '0' || (x > '9' && x < 'A') || (x > 'Z' && x < 'a') || x > 'z')
                    return false;
                return true;
            });
            timovi[tim].insert(p->ime);
            prethodno->sljedeci = p->sljedeci; 

            p = prethodno;
            preostalih--;
            u_timu++;
        }
        u_timu = 0;
        tim++;
    }
    p->sljedeci = nullptr;
    
    return timovi;
}

int main ()
{
    int br_djece;
    std::cout << "Unesite broj djece: ";
    std::cin >> br_djece;
    std::cin.ignore(10, '\n');
    std::vector<std::string> djeca(br_djece);
    std::cout << "Unesite imena djece:\n";
    for (int i = 0; i < djeca.size(); i++)
        std::getline(std::cin, djeca[i]);
    int br_timova;
    std::cout << "Unesite broj timova: ";
    
    std::cin >> br_timova;
    try
    {
        Timovi timovi(Razvrstavanje(djeca, br_timova));
        Timovi::iterator it(timovi.begin());
        for (int i = 0; i < timovi.size(); i++)
        {
            std::cout << "Tim " << i + 1 << ": ";
            typename std::set<std::string>::iterator it2(timovi[i].begin());
            for (int j = 0; j < timovi[i].size() - 1; j++)
                std::cout << *it2++ << ", ";
            std::cout << *it2 << "\n";
            it++;
        }
    }
    catch(std::bad_alloc)
    {
        
    }
    catch(std::logic_error e)
    {
        std::cout << "Izuzetak: " << e.what();
    }
	return 0;
}
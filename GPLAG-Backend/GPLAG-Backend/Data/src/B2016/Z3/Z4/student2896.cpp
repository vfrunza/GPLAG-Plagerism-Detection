/B2016/2017: Zadaća 3, Zadatak 4.
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <list>
#include <cmath>
#include <new>

bool slovo(char a)
{
    if(a >= 48 && a <= 57) return true;
    if(a >= 65 && a <= 90) return true;
    if(a >= 97 && a <= 122) return true;
    return false;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int k)
{
    int n = djeca.size();
    if(k<1 ||k>n) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    for(int i=0; i<n; i++)
    {
        lista.push_back(djeca.at(i));
    }
    auto it = lista.begin();
    std::vector<std::set<std::string>> timovi(k);
    int brojvise;
    brojvise = n % k;
    int i;
    for(i=0; i<brojvise; i++)
    {
        for(int j=0; j<(n/k + 1); j++)
        {
            std::string dijete = *it;
            int pomak = 0;
            for(int m = 0; m<dijete.length(); m++)
            {
                if(slovo(dijete.at(m)))
                {
                    pomak++;
                }
            }
            timovi.at(i).insert(dijete);
            auto it2 = it;
            it2++;
            if(it2 == lista.end())
            {
                lista.erase(it);
                it = lista.begin();
            }
            else it = lista.erase(it);
            pomak--;
            for(int m=0; m<pomak; m++)
            {
                it++;
                if(it == lista.end()) it = lista.begin();
            }
        }
    }
    for(i=brojvise; i<k; i++)
    {
        for(int j=0; j<(n/k); j++)
        {
            std::string dijete = *it;
            int pomak = 0;
            for(int m=0; m<dijete.length(); m++)
            {
                if(slovo(dijete.at(m)))
                {
                    pomak++;
                }
            }
            timovi.at(i).insert(dijete);
            auto it2 = it;
            it2++;
            if(it2 == lista.end())
            {
                lista.erase(it);
                it = lista.begin();
            }
            else it = lista.erase(it);
            pomak--;
            for(int m=0; m<pomak; m++)
            {
                it++;
                if(it == lista.end()) it = lista.begin();
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
        std::cin.ignore(10000, '\n');
        std::cout << "Unesite imena djece:\n";
        std::vector<std::string> djeca(0);
        for(int i=0; i<n; i++)
        {
            std::string pomocni;
            std::getline(std::cin, pomocni);
            djeca.push_back(pomocni);
        }
        std::cout << "Unesite broj timova: ";
        int k;
        std::cin >> k;
        try
        {
            std::vector<std::set<std::string>> timovi = Razvrstavanje(djeca, k);
            for(int i=0; i<timovi.size(); i++)
            {
                std::cout << "Tim " << i+1 << ": ";
                int br=1;
                for(auto x : timovi.at(i))
                {
                    if(br == timovi.at(i).size()) std::cout << x;
                    else std::cout << x << ", ";
                    br++;
                }
                std::cout << std::endl;
            }
        }
        catch(std::logic_error e)
        {
            std::cout << "Izuzetak: " << e.what();
            return 0;
        }
    }
    catch(...)
    {
        return 0;
    }
	return 0;
}
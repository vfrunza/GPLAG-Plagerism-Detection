/B2016/2017: Zadaća 3, Zadatak 2

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iterator> 

std::vector<std::string> DajRijeci(const std::string &recenica, std::vector<int> &v2)
{
    if(recenica.size() <= 0) throw std::domain_error("Ne valja recenica");
    bool logika (true);
    std::vector<std::string> v;
    std::string rijec;
    auto it(recenica.begin());
    int brojac(0);
    while(it <= recenica.end())
    {
        if(it == recenica.end() || !((*it >= 'a' && *it <= 'z') || (*it >= 'A' && *it <= 'Z') || (*it >= '0' && *it <= '9')))
        {
            if(!logika)
            {
                brojac++;
                v.push_back(rijec);
                rijec.clear();
            }
            logika = true;
        }
        else
        {
            v2.resize(brojac+1);
            v2[brojac] = std::distance(recenica.begin(), it)-rijec.size();
            logika = false;
            rijec += *it;
        }
        it++;
    }
    return v;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(const std::string &recenicaa)
{
    std::string recenica = recenicaa;
    if(recenica.size() <= 0) throw std::domain_error("Ne valja recenica");
    std::transform(recenica.begin(), recenica.end(), recenica.begin(), tolower);
    std::vector<int> pozicije;
    auto v = DajRijeci(recenica, pozicije);
    std::string rijec;
    std::set<int> skup;
    std::map<std::string, std::set<int>> mapa;
    for(int i=0; i<v.size(); i++)
    {
        auto it(mapa.find(v[i]));
        if(it == mapa.end())
        {
            int brojac(0);
            for(int j=0; j<v.size(); j++)
            {
                if(v[i] == v[j])
                {
                    brojac++;
                    skup.insert(pozicije[j]);
                }
            }
            mapa.insert(std::make_pair(v[i], skup));
            skup.clear();
        }        
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(const std::string &rijec, const std::map<std::string, std::set<int>> &mapa)
{
    auto it(mapa.find(rijec));
    if(it == mapa.end()) throw std::logic_error("Pojam nije nadjen");
    return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa)
{
    for(auto it = mapa.begin(); it != mapa.end(); it++) 
    {
        std::cout << it->first << ": ";
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            std::cout << *it2;
            auto uslov(it->second.end());
            uslov--;
            if(it2 != uslov) std::cout << ",";
        }
        std::cout << std::endl;
    }
}

int main ()
{
    std::cout << "Unesite tekst: ";
    std::string s, rijec;
    std::getline(std::cin, s);
    auto m (KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(m);
    for(;;)
    {
        try {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec == ".") break;
        
        auto skup (PretraziIndeksPojmova(rijec, m));
        for(auto it = skup.begin(); it != skup.end(); it++) std::cout << *it << " ";
        std::cout << std::endl;
        }catch(std::logic_error a){ std::cout << "Unesena rijec nije nadjena!" << std::endl;}
    }

	return 0;
}
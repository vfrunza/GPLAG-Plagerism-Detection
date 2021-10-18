/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stdexcept>
typedef std::map<std::string, std::set<int>> Mapa;

void mala(std::string &s)
{
    for(char &c : s)
        if(c >= 'A' && c <= 'Z')
            c += 32;
}

bool slovo(char c)
{
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        return true;
        
    return false;
}

Mapa KreirajIndeksPojmova (std::string s)
{
    std::map<std::string, std::set<int>> m;
    
    bool razmak = true;
    int i = 0, p;
    
    while(i < s.size())
    {
        if(slovo(s.at(i)) == false)
            razmak = true;
            
        else if(razmak)
        {
            razmak = false;
            p = i;
            
            if(s.at(i) >= 'A' && s.at(i) <= 'Z')
                s.at(i) += 32;
                
            while(p < s.size() && slovo(s.at(p)))
            { 
                if(s.at(p) >= 'A' && s.at(p) <= 'Z')
                s.at(p) += 32;
                p++;
            }
                
            std::string s1 = s.substr(i, p - i);
            m[s1].insert(i);
        }
        i++;
    }
    return m;
}

std::set<int> PretraziIndeksPojmova(std::string s, Mapa m)
{
    mala(s);
    auto i = m.find(s);
    if(i == m.end())
        throw std::logic_error("Pojam nije nadjen");
        
    return i->second;
}

void IspisiSkup (std::set<int> s)
{
    for(auto i = s.begin(); i != s.end();)
    {
        std::cout << *i;
        i++;
        
        if(i != s.end())
        std::cout << ",";
    }
}

void IspisiIndeksPojmova(Mapa m)
{
    for(auto i : m)
    {
        std::cout << i.first << ": ";
        IspisiSkup(i.second);
        std::cout << std::endl;
    }
}
int main ()
{
    std::string s;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, s);
    
    Mapa m = KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(m);
    
    std::string a;
    for(; ;)
    {
        std::cout << "\nUnesite rijec: ";
        std::getline(std::cin, a);
        
        if(a == ".")
            break;
        try
        {
            std::set<int> skup = PretraziIndeksPojmova(a, m);
            for(auto i : skup)
                std::cout << i << " ";
        }
        
        catch(std::logic_error)
        {
            std::cout << "Unesena rijec nije nadjena!";
        }
    }
    return 0;
}
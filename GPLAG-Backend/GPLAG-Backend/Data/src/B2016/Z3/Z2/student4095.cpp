/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <set>
#include <utility>

bool DaLiJeSlovoIliBroj (char znak)
{
    if ((znak>='0' && znak<='9') || (znak>='A' && znak<='Z') || (znak>='a' && znak<='z'))
        return true;
    return false;
}

char VelikaSlova(char znak)
{
    if (znak>='a' && znak<='z')
        return znak-'a'+'A';
    return znak;
}

bool DaLiSuIsteRijeci (std::string prva, std::string druga)
{
    
    auto it1(prva.begin()), it2(druga.begin());
    while (it1!=prva.end() && it2!=druga.end())
    {
        if(VelikaSlova(*it1)!=VelikaSlova(*it2))
            return false;
        it1++;
        it2++;
    }
    if (it1!=prva.end()) return false;
    if (it2!=druga.end()) return false;
    return true;
}

std::map<std::string,std::set<int>> KreirajIndeksPojmova (std::string s)
{
    std::map<std::string, std::set<int>> indeks_pojmova;
    auto it(s.begin());
    for ( auto it1=s.begin(); it1!=s.end(); it1++)
    {
        if (DaLiJeSlovoIliBroj(*it1))
        {   
            int pozicija(it1-it);
            std::string pomocni;
            auto it2(it1);
            for (it2=it1; it2!=s.end(); it2++)
            {
                if(DaLiJeSlovoIliBroj(*it2))
                    pomocni.push_back(*it2);
                else
                    break;
            }
            it1=it2-1; //-1 jer bi onda otislo preko
            //broj_rijeci++;
            //std::cout<<pomocni<<" "<<pozicija<<std::endl;
            bool postoje_iste(false);
            for (auto iterator=indeks_pojmova.begin();  iterator!=indeks_pojmova.end(); iterator++)
            {
                if (DaLiSuIsteRijeci(pomocni, iterator->first))
                {
                    iterator->second.insert(pozicija);
                    postoje_iste=true;
                    break;
                }
            }
            if (!postoje_iste) 
            { 
                indeks_pojmova[pomocni];
                auto it(indeks_pojmova.find(pomocni));
                it->second.insert(pozicija);
            }
        }
    }
    return indeks_pojmova;
}

std::set<int> PretraziIndeksPojmova (std::string s, std::map<std::string, std::set<int>> indeks_pojmova)
{
    auto it(indeks_pojmova.begin());
    for (it=indeks_pojmova.begin(); it!=indeks_pojmova.end(); it++)
    {
        if(DaLiSuIsteRijeci(it->first, s))
            break;
    }
    if (it==indeks_pojmova.end())
        throw std::logic_error("Unesena rijec nije nadjena!");
    return it->second;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> indeks_pojmova)
{
    for (auto it=indeks_pojmova.begin(); it!=indeks_pojmova.end(); it++)
    {
        std::cout<<it->first<<": ";
        for (auto it1=it->second.begin(); it1!=it->second.end(); it1++)
        {
            if(*it1==*(it->second.rbegin())) 
                std::cout<<*it1;    
            else
                std::cout<<*it1<<",";
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::string tekst;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, tekst);
    std::map<std::string, std::set<int>> indeks_pojmova(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(indeks_pojmova);
    for (;;)
    {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::cin>>rijec;
        if(rijec==".")
            break;
        try{
            std::set<int> pozicije1(PretraziIndeksPojmova(rijec, indeks_pojmova));
            for (int x : pozicije1)
                std::cout<<x<<" ";
            std::cout<<std::endl;
        }
        catch (std::logic_error e)
        {
            std::cout<<e.what()<<std::endl;
        }
    }
	return 0;
}
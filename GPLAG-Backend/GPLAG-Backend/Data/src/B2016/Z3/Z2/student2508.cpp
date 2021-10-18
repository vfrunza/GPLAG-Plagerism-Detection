/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s)
{
    for(int i(0); i<s.length();i++)
        if(s[i]>='A' && s[i]<='Z') s[i]+=('a'-'A'); //samo se mala slova gledaju
    std::map<std::string,std::set<int>> indeks;
    bool razmak(true);
    for(int i(0);i<s.length();i++)
    {
        if(!((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))) razmak=true; //ako nije ni slovo ni broj onda je razmak
        else if(razmak)
        {
            razmak=false;
            int j(i);
            std::string rijec;
            while(j<s.length() && ((s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9')))
            {
                rijec.push_back(s[j]);
                j++;
            }
            auto it(indeks.find(rijec));
            if(it==indeks.end()) indeks.insert(std::make_pair(rijec,std::set<int>{i})); //ako nema vec rijeci unosi se novi par
            else (it->second).insert(i);
        }
    }
    return indeks;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> indeks)
{
    auto it(indeks.find(rijec));
    if(it==indeks.end()) throw std::logic_error("Pojam nije nadjen");
    return it->second;
}

void IspisiIndeksPojmova(std::map <std::string, std::set<int>> indeks)
{
    for(auto it(indeks.begin());it!=indeks.end();it++)
    {
        std::cout<<it->first<<": ";
        int brojac(0);
        for(int x : it->second)
        {
            std::cout<<x;
            if(brojac<(it->second).size()-1) std::cout<<",";
            brojac++;
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin,tekst);
    auto indeks (KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(indeks);
    for(;;)
    {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin,rijec);
         for(int i(0); i<rijec.length();i++)
            if(rijec[i]>='A' && rijec[i]<='Z') rijec[i]+=('a'-'A');
        if(rijec==".") break;
        try
        {
            auto skup(PretraziIndeksPojmova(rijec,indeks));
            for(int x: skup) std::cout<<x<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error izuzetak)
        {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
	return 0;
}
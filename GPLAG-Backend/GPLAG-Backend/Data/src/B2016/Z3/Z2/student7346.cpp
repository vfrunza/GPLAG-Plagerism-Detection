/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include<stdexcept>
std::string PretvoriUMalaSlova(std::string s)
{
    for(int i(0); i < s.size(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 'a' - 'A';
    }
    return s;
}
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s)
{
    std::map<std::string, std::set<int>> IndeksPojmova;
    for(int i(0); i < s.size(); i++)
    {
        if(s[i] == ' ')
            continue;
        if(!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
            continue;
        
        int PozicijaKursora(i);
        std::string temp;
        while(((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) 
        && i < s.size())
        {
            temp = temp + s[i];
            i++;
        }
        if(!IndeksPojmova.count(PretvoriUMalaSlova(temp)))
        {
            std::set<int> skup{PozicijaKursora};
            IndeksPojmova[PretvoriUMalaSlova(temp)] = skup;
        }
        else
        {
            auto it(IndeksPojmova.find(PretvoriUMalaSlova(temp)));
            it->second.insert(PozicijaKursora);
        }
    }
    
    return IndeksPojmova;
}
std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> IndeksPojmova)
{
    auto it(IndeksPojmova.find(s));
    if(it == IndeksPojmova.end())
        throw std::logic_error("Pojam nije nadjen");
    else
        return it->second;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> IndeksPojmova)
{
    for(auto it(IndeksPojmova.begin()); it != IndeksPojmova.end(); it++)
    {
        std::cout << it->first << ": ";
        int brojac = it->second.size();
        for(auto x : it->second)
        {
            if(brojac != 1)
                std::cout << x << ",";
            else
                std::cout << x;
            brojac--;
        }
        std::cout << std::endl;
    }
}
int main ()
{
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    auto Knjiga(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(Knjiga);
    for(;;)
    {
        std::cout << "Unesite rijec: ";
        std::string temp;
        std::cin >>temp;
        if(temp == ".") break;
        try
        {
            auto skup = PretraziIndeksPojmova(temp, Knjiga);
            for(auto x: skup)
                std::cout << x << " ";
            std::cout << std::endl;
        }
        catch(std::logic_error e)
        {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}
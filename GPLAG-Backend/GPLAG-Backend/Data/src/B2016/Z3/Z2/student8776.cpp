#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
#include <vector>

bool Da_Li_Je_Znak (char c)
{
    if (c>='0' && c<='9')
        return true;
    if (c>='A' && c<='Z')
        return true;
    if (c>='a' && c<='z')
        return true;
    
    return false;
}


std::map<std::string,std::set<int>> KreirajIndeksPojmova (std::string s)
{
    std::map<std::string,std::set<int>> rezultat;
    
    for (int i{};i<s.length();i++)
        {
            if (Da_Li_Je_Znak(s[i]) == true)
                {
                    std::string pomocni;
                    int j = i;
                    for (j;j<s.length();j++)
                        {
                            if (Da_Li_Je_Znak(s[j]) == false)
                                break;
                                
                            pomocni.push_back(s[j]);
                        }
                        
                    for (int k{};k<pomocni.length();k++)
                        {
                            if (pomocni[k]>='A' && pomocni[k]<='Z')
                                pomocni[k] += 32;
                        }
                    
                    auto it = rezultat.find(pomocni);
                    
                    if (it == rezultat.end())
                        rezultat.insert (std::pair<std::string,std::set<int>> (pomocni,{i}));
                    else
                        it->second.insert(i);
                    
                    
                    i = j;
                }
        }
    
    return rezultat;
}

std::set<int> PretraziIndeksPojmova (std::string s, std::map<std::string,std::set<int>> mapa)
{
    for (int i{};i<s.length();i++)
        {
            if (s[i]>='A' && s[i]<='Z')
                s[i] += 32;
        }
    
    auto it = mapa.find(s);
    
    if (it == mapa.end())
        throw std::logic_error ("Pojam nije nadjen");
    else
        return it->second;
}

void IspisiIndeksPojmova (std::map<std::string,std::set<int>> mapa)
{
    auto it = mapa.begin();
    while(it!=mapa.end())
        {
            std::cout<<it->first<<": ";
            
            std::set<int> pomocni = it->second;
            
            auto ispis = pomocni.begin();
            std::vector<int> upis;
            while (ispis!=pomocni.end())
                {
                    upis.push_back(*ispis);
                    ispis++;
                }
                
            for (int i{};i<upis.size();i++)
                {
                    if (i == upis.size()-1)
                        std::cout<<upis[i];
                    else
                        std::cout<<upis[i]<<",";
                }
            
            std::cout<<std::endl;
            it++;
        }
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin,s);
    auto mapa = KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    
    while (true)
        {
            std::cout<<"Unesite rijec: ";
            std::string rijec;
            std::getline(std::cin,rijec);
            
            if (rijec == ".")
                break;
            
            try
            {
                auto skup = PretraziIndeksPojmova(rijec,mapa);
                
                auto it = skup.begin();
                while (it!=skup.end())
                    std::cout<<*it++<<" ";
                std::cout<<std::endl;
            }
            catch (std::logic_error e)
            {
                std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
            }
            
        }
    
    
    
    
	return 0;
}
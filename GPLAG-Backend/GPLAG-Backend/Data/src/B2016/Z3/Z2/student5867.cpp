#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s)
{
    std::map<std::string, std::set<int>> mapa;
    std::string pomocni;
    int poc, kraj;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = (char)(tolower(s[i]));
    }
    for(int i = 0; i < s.size(); i++)
    {
        std::set<int>skup;
        if((s[i] < 'A' && s[i] > 57) || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z' || s[i] == ' ' || s[i] < 48)
        {
            while((s[i] < 'A' && s[i] > 57) || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z' || s[i] == ' ' || s[i] < 48)
            {
                i++;
            }
        }
        //if(i == s.size())
          //  break;
        if(((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 48 && s[i] <= 57)) && (s[i] == s[0] || (s[i-1] <= 'A' || (s[i-1] >= 'Z' && s[i-1] <= 'a') || s[i-1] >= 'z')))
        {
            poc = i;
            while((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 48 && s[i] <= 57)) 
            {
                i++;
            }
            kraj = i;
        
        pomocni = s.substr(poc, kraj - poc);
        //std::cout<<pomocni<<std::endl;
        skup.insert(poc);
        int pom;
        for(int j = kraj; j < s.size(); j++)
        {
            for(int k = 0; k < pomocni.size(); k++)
            {
                if(pomocni[0] != s[j])
                    break;
                if(pomocni[0] == s[j])
                {
                    pom = j;
                    while(pomocni[k] == s[j] && j < s.size())
                    {
                        k++;
                        j++;
                    }
                }
                if((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >=48 && s[j] <= 57) || (s[pom-1] >= 'A' && s[pom-1] <= 'Z') || (s[pom-1] >= 'a' && s[pom-1] <= 'z') || (s[pom-1] >= 48 && s[pom-1] <= 57))
                    break;
                if((j - pom) == pomocni.size())
                    skup.insert(pom);
                break;
            }
        }
        
        mapa.insert(std::make_pair(pomocni, skup));
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova (std::string s, std::map<std::string, std::set<int>> mapa)
{
    std::set<int>skup;
    auto it(mapa.find(s));
    if(it == mapa.end())
        throw std::logic_error ("Pojam nije nadjen");
    for(auto it1 : it -> second)
        skup.insert(it1);
    return skup;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa)
{
    for(auto it = mapa.begin(); it != mapa.end(); it++)
    {
        std::cout<<it -> first<<": ";
        std::set<int>skup = it -> second;
        auto it1 = skup.begin();
        while(3)
        {
            std::cout<<*it1;
            it1++;
            if(it1 == skup.end())
                break;
            else
                std::cout<<",";
        }
        std::cout<<std::endl;
    }
}
int main ()
{
	std::string s;
	std::cout<<"Unesite tekst: ";
	std::getline(std::cin, s);
	if(s[0] == '.' && s.size() == 1)
	    return 0;
	auto mapa = KreirajIndeksPojmova(s);
	IspisiIndeksPojmova(mapa);
    while(17)
	{
	    std::cout<<"Unesite rijec: ";
	    std::string s;
	    std::getline(std::cin, s);
	    for(int i = 0; i < s.size(); i++)
	        s[i] = (char)(tolower(s[i]));
	    if(s[0] == '.')
	        return 0;
	    try
	    {
	    auto skup = PretraziIndeksPojmova(s, mapa);
	    for(auto it = skup.begin(); it != skup.end(); it++)
	        std::cout<<*it<<" ";
	    std::cout<<std::endl;
	    }
	    catch(std::logic_error er1)
	    {
	        std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
	        continue;
	    }
	}
	
	return 0;
}
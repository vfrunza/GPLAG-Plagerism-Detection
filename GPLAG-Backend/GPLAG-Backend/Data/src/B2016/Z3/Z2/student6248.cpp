/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector> 
#include <iterator>

bool ProvjeraZnaka(char znak)
{
    if((znak>='0' && znak<='9') || (znak>='A' && znak<='Z') || (znak>='a' && znak<='z')) return true;
    else return false;
}

void PretvoriUMala(std::vector<std::string> &s)
{
    for(int i(0); i<s.size(); i++)
    {
        for(int j(0); j<s[i].length(); j++)
        {
            if((s[i][j]>='a' && s[i][j]<='z') || (s[i][j]>='A' && s[i][j]<='Z'))
            s[i][j]=tolower(s[i][j]);
        }
    }
}

bool PorediZnakove(char a, char b)
{
    if((a>='a' && a<='z') || (a>='A' && a<='Z') || (b>='a' && b<='z') || (b>='A' && b<='Z'))
    {
        a=std::tolower(a);
        b=std::tolower(b);
    }
    if(a==b) return true;
    else return false;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s)
{
    std::map<std::string, std::set<int>> indeks_pojmova;
    std::vector<std::string> izdvojene_rijeci;
    
    for(int i(0); i<s.length(); i++)
    {
        if((i==0 && ProvjeraZnaka(s[i])==true) || (i>0 && ProvjeraZnaka(s[i])==true && ProvjeraZnaka(s[i-1])==false))
        {
            std::string izdvojena{};
            while(i<s.length() && ProvjeraZnaka(s[i])==true)
            {
                izdvojena.push_back(s[i]);
                i++;
                if(i==s.length()) break;
            }
            izdvojene_rijeci.push_back(izdvojena);
        }
    }
    
    PretvoriUMala(izdvojene_rijeci);
    
    for(int i(0); i<izdvojene_rijeci.size(); i++)
    {
        std::string pomocna{izdvojene_rijeci[i]};
        
        std::set<int> skup;
        for(int j(0); j<s.length(); j++)
        {
            if(((j==0 && ProvjeraZnaka(s[j])==true) || (j>0 && ProvjeraZnaka(s[j])==true && ProvjeraZnaka(s[j-1])==false)) && PorediZnakove(s[j],pomocna[0])==true)
            {
                int temp(0);
                int poc(j);
                while(PorediZnakove(s[j],pomocna[temp])==true)
                {
                    j++;
                    temp++;
                    if(j==s.length() || temp==pomocna.length()) break;
                }
                if(j==s.length() || temp==pomocna.length()) skup.insert(poc);   // ovo moramo ovako da ne bi na kraju recenice doslo do memorijske greske
                // do greske bi doslo kad bismo u ovom momentu pristupili s[j] ili s[temp]
                else if(ProvjeraZnaka(s[j])==false && ProvjeraZnaka(pomocna[temp])==false)
                {
                    skup.insert(poc);
                }
                j--;
            }
            if(j==s.length()) break;
        }
        indeks_pojmova.insert(std::make_pair(pomocna,skup));
        if(i==izdvojene_rijeci.size()) break;
    }
    return indeks_pojmova;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa)
{
    std::set<int> skup;
    auto it(mapa.find(s));
    if(it==mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    else
    {
        skup=mapa[s];
    }
    return skup;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa)
{
    for(auto it=mapa.begin(); it!=mapa.end(); it++)
    {
        std::cout << it->first << ": ";
        std::set<int> skup;
        skup=mapa[it->first];
        auto iter(skup.begin()); 
        for(int i(0); i<std::distance(skup.begin(),skup.end())-1; i++) 
        {
            std::cout << *iter << ",";
            iter++;
        }
        std::cout << *iter; 
        std::cout << std::endl;
    }
}

int main ()
{
        std::string tekst;
        std::cout << "Unesite tekst: ";
        std::getline(std::cin, tekst);
        std::map<std::string, std::set<int>> indeks_pojmova;
        indeks_pojmova=KreirajIndeksPojmova(tekst);
        IspisiIndeksPojmova(indeks_pojmova);
        for(;;)
        {
            std::cout << "Unesite rijec: ";
            std::string s;
            std::getline(std::cin, s);
            if(s==".") break;
            std::set<int> skup;
            try
            {
            skup=PretraziIndeksPojmova(s,indeks_pojmova);
            for(auto x : skup) std::cout << x << " ";
            }
            catch(std::logic_error izuzetak)
            {
                std::cout << izuzetak.what();
            }
            std::cout << std::endl;
        }
	return 0;
}
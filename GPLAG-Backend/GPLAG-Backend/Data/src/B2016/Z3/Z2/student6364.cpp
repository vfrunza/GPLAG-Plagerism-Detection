/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <set>
#include <vector>
#include <cctype>
#include <stdexcept>
bool slovo(char a)
{
    if((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') || (a >= '0' && a <= '9')) return true;
    return false;
}
std::string MalaSlova(std::string s)
{
    std::string a;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z') a.push_back(s[i] + 'a' - 'A');
        else a.push_back(s[i]);
    } return a;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string tekst)
{
    std::string s(MalaSlova(tekst));
    std::vector<std::string> vs;
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        int poc;
        while(i < n && !slovo(s[i])) i++;
        poc = i;
        int kraj(0);
        while(i < n && slovo(s[i])) i++;
        kraj = i;
        if(kraj - poc > 0) vs.push_back(s.substr(poc, kraj - poc));
    }
    for(int i = 0; i < vs.size(); i++)
    {
        bool obrisano(false);
        for(int j = i + 1; j < vs.size(); j++)
        {
            if(vs[i] == vs[j]) 
            {
                vs.erase(vs.begin() + j);
                j--;
                obrisano = true;
            }
        } if (obrisano) i--;
    }
    std::vector<std::vector<int>> novi(vs.size());
    int m, k;
    int vel(vs.size());
    for(int i = 0; i < vel; i++)
    {
        m = vs[i].size();
        k = 0;
        for(int j = 0; j <= n - m; j++)
        {
           if( (j == 0 || j == n - m || !slovo(s[j-1])) && !slovo(s[m+j]) && vs[i] == s.substr(j,m))
            {  
                novi[i].push_back(j);
                k++;
            }
        }
    }
    std::map<std::string, std::set<int>> mapa;
    for(int i = 0; i < vel; i++)
    {
        for(int j = 0; j < novi[i].size(); j++)
        {
            mapa[vs[i]].insert(novi[i][j]);
        }
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova (std::string s, std::map<std::string, std::set<int>> mapa)
{
    bool ima(false);
    std::string tmp = MalaSlova(s);
    std::set<int> setic;
    for(auto it = mapa.begin(); it != mapa.end(); it++)
    {
        if(tmp == it -> first) 
        {
            ima = true;
            for(auto i = (it -> second).begin(); i != (it -> second).end(); i++)
                setic.insert(*i);
        }
    }
    if(!ima) throw std::logic_error("Pojam nije nadjen");
    return setic;
}
void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa)
{
    for(auto it = mapa.begin(); it != mapa.end(); it++)
    {
        std::cout<<it->first<<": ";
        for(auto x = (it -> second).begin(); x != (it -> second).end(); x++)
        {
            if( x == it -> second.begin()) std::cout<<*x;
            else std::cout<<","<<*x;
        } std::cout<<std::endl;
            
    }
} 
int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin, tekst);
    std::map<std::string, std::set<int>> mapa(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(mapa);
    std::string pom = { "."};
    for(;;)
    {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
        if(rijec == pom) break;
        try {
            std::set<int> setic(PretraziIndeksPojmova(rijec, mapa));
            for(auto it = setic.begin(); it != setic.end(); it++)
                std::cout<<*it<<" ";
            } 
        catch(std::logic_error)
            {
                std::cout<<"Unesena rijec nije nadjena!";
            }
        std::cout<<std::endl;
    }
    
	return 0;
}
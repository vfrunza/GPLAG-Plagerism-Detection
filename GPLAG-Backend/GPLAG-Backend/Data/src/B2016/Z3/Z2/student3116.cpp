/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

bool Provjera(char s)
{
    if((s>='A' && s<='Z')||(s>='a' && s<='z')||(s>='0' && s<='9'))
        return true;
    return false;
}

map<string,set<int>> KreirajIndeksPojmova(string s)
{
    
    map<string,set<int>> m;
    
        for(int i=0;i<s.size();i++)
        {
            string rijec;set<int> pom;
            if(i==0 || !Provjera(s[i]))
            {  
                if(i!=0) i++;int k=i;int br=0;
                while(Provjera(s[i])){
                        i++;br++;
                }
                rijec=s.substr(k,br);
                for(int l=0;l<rijec.size();l++)
                {
                if(rijec[l]>='A' && rijec[l]<='Z')
                    rijec[l]+=32;
                }
                pom.insert(k);
            
            for(int j=i;j<s.size();j++)
            {
                string dup;
                if(!Provjera(s[j]))
                {
                    j++;int g=j;int br=0;
                    while(Provjera(s[j])){
                            j++;br++;}
                   dup=s.substr(g,br);
                   for(int l=0;l<dup.size();l++)
                    {
                        if(dup[l]>='A' && dup[l]<='Z')
                                 dup[l]+=32;
                     }
                    if(dup==rijec) pom.insert(g);
                }
                else continue;
            }
            }
            if(rijec.size()!=0)
                m.insert(make_pair(rijec,pom));
            
        }
        return m;
}

int main ()
{   
    
    std::map<std::string, std::set<int>> m = KreirajIndeksPojmova("abc cde def ghi ghi def cde abc");
    for (const auto &i : m)
    {
        for (const auto &j : i.second)
            std::cout << j << " ";
        std::cout << " <--- " << i.first << std::endl;
    }
	return 0;
}
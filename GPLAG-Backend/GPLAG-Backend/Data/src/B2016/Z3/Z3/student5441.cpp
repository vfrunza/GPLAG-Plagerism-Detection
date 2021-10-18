/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <list>
#include <set>
#include <vector>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v1, int n)
{
    std::vector<std::set<std::string>> v2(n);
    int prvi_timovi=v1.size()%n;
    int broj_cl_prvih_timova(v1.size()/n+1);
    int br_cl_preostalih(v1.size()/n);
    std::list<std::string> lista;
    for(int i=0; i<v1.size(); i++)
    lista.push_back(v1[i]);
    
    int i(0);
        while(lista.size()!=0)
        {
            for(auto it=lista.begin(); it!=lista.end; it++)
            {
                v2[i].push_back(*it);
                int duzina_imena(0);
                std::string ime(*it);
                int j(0); 
                while(j!=ime.length())
                {
                    if(ime[j]>='A' && ime[j]<='Z' || ime[j]>='a' && ime[j]<='z' &&)
                    duzina_imena++;
                }
                
            }
        }
    
}
int main ()
{
	return 0;
}
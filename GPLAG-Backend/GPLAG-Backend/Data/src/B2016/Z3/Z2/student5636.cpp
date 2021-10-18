/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <set>
#include <stdexcept>
typedef std::map<std::string,std::vector<int> > mapa;
bool JeLiSlovo(char c)
{
    return((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9'));
}

mapa KreirajIndeksPojmova(std::string &recenica)
{
    mapa indeks;
   for(int i=0;i<recenica.size();i++)
    {
        std::string pomocni;
        while(JeLiSlovo(recenica[i]) && i!=(int)recenica.size()-1)
        {
            pomocni+=recenica[i];
            i++;
            if(i==(int)recenica.size()-1)
            {
                if(JeLiSlovo(recenica[i]))
                {
                    pomocni+=recenica[i];
                    break;
                }
            }
        }
        if(pomocni.size()!=0)
         {
             if(i==recenica.size()-1)
             {
                 indeks[pomocni].push_back(i-pomocni.size()+1);
             }
             else
             {
             indeks[pomocni].push_back(i-pomocni.size());
             i--;
             }
         }
    }
    return indeks;
}

std::vector<int> PretraziIndeksPojmova(const std::string rijec,mapa &indeks)
{
    for(const auto &p:indeks)
    {
        if(p.first==rijec) return p.second;
    }
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(mapa &indeks)
{
    for (const auto &p : indeks) 
    {
    std::cout<< p.first << ": ";
        for(int i=0;i<p.second.size();i++)
        {
            std::cout<<p.second[i];
             if(i!=p.second.size()-1) std::cout<<",";
        }
         std::cout<<"\n";
    }
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    char c;
    std::string recenica;
    for(;;)
    {
        std::cin>>c;
        if(c!='.') recenica+=c;
        else break;
    }
     mapa indeks=KreirajIndeksPojmova(recenica);
     IspisiIndeksPojmova(indeks);
     for(;;)
     {
         std::cout<<"Unesite rijec: ";
         char a;
         std::string rijec;
         for(;;)
         {
             std::cin>>a;
             if(a=='.') return 0;
             else if(a!='\n') rijec+=a;
         }
         try
         {
            std::vector<int> pozicije=PretraziIndeksPojmova(rijec,indeks);
            for(int i=0;i<(int)pozicije.size();i++)
            {
                std::cout<<pozicije[i]<<" ";
            }
         }
         catch(std::logic_error e)
         {
             std::cout<<"Unesena rijec nije nadjena!";
         }
     }
   /* std::string test="abc qwe stsda abc abc dhi qwe hrkw dhi";
    std::map<std::string,std::vector<int>> indeks=KreirajIndeksPojmova(test);
    IspisiIndeksPojmova(indeks);*/

	return 0;
}
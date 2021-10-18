/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <stdexcept>
#include <string>
#include <cstring>

bool DaLiJeDobro(char a)
{
    return ((a>='A' && a<='Z') || (a>='a' && a<='z') || (a>='0' && a<='9'));
}

int KolikoIhIma (std::string s)
{
    int brojac=0;
    int i=0;
    while(i<s.size())
    {
        if(DaLiJeDobro(s[i]))
        brojac++;
        i++;
    }
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>v, int n)
{
   if(n<1 || n>v.size()) throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
   std::list<std::string> ListaS;
   std::vector<std::set<std::string>> VektorSS;
   int i=0;
   while(i<v.size())
   {
       ListaS.push_back(v[i]);
       i++;
   }
   int brt1=v.size()%n;
   int brt2=0;
   int brc1=0;
   int brc2=0;
   if(brt1==0) 
   {
       brt1=n;
       brc1=v.size()/n;
   }
   else
   {
       brt1=v.size()%n;
       brc1=(v.size()/n)+1;
       brt2=n-brt1;
       brc2=v.size()/n;
   }
   int brs=KolikoIhIma(*(ListaS.begin()));
   bool MozeNemoze=true;
   auto it=ListaS.begin();
   do
   {
       int a=brc1;
       std::set<std::string> Skup;
       if(MozeNemoze)
       {
           MozeNemoze=false;
           Skup.insert(*(ListaS.begin()));
           auto pok=ListaS.begin();
           pok=ListaS.erase(pok);
           a--;
           brs--;
       }
       it=ListaS.begin();
       do{
           do{
              it++;
              brs--;
              if(it==ListaS.end())
              {
                  it=ListaS.begin();
              }
           }while(brs!=0);
        Skup.insert(*it);
        brs=KolikoIhIma(*it);
        it=ListaS.erase(it);
        brs--;
        a--;
       }while(a>0);
    VektorSS.push_back(Skup);
    brt1--;
}while(brt1!=0);

    do{
        int a=brc2;
        std::set<std::string> Skup;
        do{
            bool problem=false;
            do
            {
                it++;
                brs--;
                if(it==ListaS.end())
                {
                    it=ListaS.begin();
                    problem=true;
                }
            }while(brs!=0);
        Skup.insert(*it);
        brs=KolikoIhIma(*it);
        it=ListaS.erase(it);
        if(!problem) brs--;
        a--;
        }while(a>0);
    VektorSS.push_back(Skup);
    brt2--;
    }while(brt2!=0);
return VektorSS;
}

int main()
{
    try
    {
        int broj_djece;
        std::cout<<"Unesite broj djece: ";
        std::cin>>broj_djece;
        std::cout<<"Unesite imena djece: ";
        std::cout<<std::endl;
        std::vector<std::string> V;
        for(int i=0; i<broj_djece; i++) 
        {
            std::string S;
            std::cin>>S;
            V.push_back(S);
        }
    
        std::cout<<"Unesite broj timova: ";
        int broj_timova;
        std::cin>>broj_timova;
        auto skup=Razvrstavanje(V, broj_timova);
        for(int i=0; i<skup.size(); i++)
        {
            std::cout<<"Tim "<<i+1<<": ";
            int br=skup[i].size();
            for(auto x:skup[i]) 
            {
                if(br<=1) std::cout<<x;
                else std::cout<<x<<", ";
                //else std::cout<<x;
                br--;
            }
        std::cout<<std::endl;
        }
    return 0;
}catch(std::logic_error Greska)
    {
        std::cout<<Greska.what();
    }
}









    
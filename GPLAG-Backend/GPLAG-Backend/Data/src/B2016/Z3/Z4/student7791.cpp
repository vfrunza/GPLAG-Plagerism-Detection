/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <stdexcept>
using std::list;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::set;
int Prebroji(string ime)
{
    
    int brojac(0);
    for(int i=0;i<ime.size();i++)
    {
        if((ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9'))
        brojac++;
    }
    return brojac;
}
vector<set<string>> Razvrstavanje(vector<string> imena,int broj)
{
    list<string> lista;
    vector<set<string>> ekipe;
    for(int i=0;i<imena.size();i++)
    {
        lista.push_back(imena[i]);
    }
    if(broj<1 || broj>lista.size())
    throw std::logic_error("Razvrstavanje nemoguce");
    int n=lista.size()/broj;
    int m=lista.size()%broj;
   set<string> skup;
    for(auto it=lista.begin();it!=lista.end();)
    {
    //  set<string> skup;
     int pom(0);
     if(lista.size()==n)
     {
         for(auto it2=lista.begin();it2!=lista.end();)
         {
             skup.insert(*it2);
             it2=lista.erase(it2);
         }
         ekipe.push_back(skup);
         //return ekipe;
         break;
     }
     skup.insert(*it);
     pom=Prebroji(*it);
     it=lista.erase(it);
     if(it==lista.end())
     it=lista.begin();
     while(pom>1)
     {
         it++;
         if(it==lista.end())
         it=lista.begin();
         pom--;
     }
     if((ekipe.size()<m && skup.size()==n+1) || (ekipe.size()>=m && skup.size()==n))
     {
     ekipe.push_back(skup);
     set<string> skup1;
     skup=skup1;
   //  for(auto it3=skup.begin();it3!=skup.end();it3++)
   //  skup.erase(it3);
     }
    }
    return ekipe;
}
int main ()
{
    cout<<"Unesite broj djece: ";
    int br;
    cin>>br;
    cout<<"Unesite imena djece: "<<std::endl;
    vector<string> imena;
    cin.ignore(10000,'\n');
    for(int i=0;i<br;i++)
    {
        string pom;
        std::getline(cin,pom);
        imena.push_back(pom);
    }
    cout<<"Unesite broj timova: ";
    int broj;
    cin>>broj;
    vector<set<string>> timovi;
    try
    {
        timovi=Razvrstavanje(imena,broj);
        int i(0);
            for(auto pom1: timovi)
            {
            i++;
            int brojac(0);
            cout<<"Tim "<<i<<": ";
            for(auto pom2: pom1)
            {
               if(brojac!=timovi.at(i-1).size()-1)
                cout<<pom2<<", ";
               else
              cout<<pom2;
              brojac++;
            }
            cout<<std::endl;
            }
    }
    catch(std::logic_error izuzetak)
    {
        cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
	return 0;
}
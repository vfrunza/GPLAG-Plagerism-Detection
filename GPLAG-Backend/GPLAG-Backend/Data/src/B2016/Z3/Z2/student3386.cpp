/B2016/2017: Zadaća 3, Zadatak 2

/*DA LI TREBA SORTIRATI RIJECI PO ABECEDNOM PORETKU ??*/



#include <iostream>
#include <string>
#include <set>
#include <map>
#include <memory>
#include <stdexcept>
#include <algorithm>

using std::set;
using std::map;
using std::cin;
using std::cout;
using std::string;

typedef map<string,set<int>> mapica;
char Validna(char a)
{
    return (a>='A' and a<='Z') or (a>='a' and a<='z')or(a>='0' and a<='9');
}
char Slovo(char a)
{
    return (a>='A' and a<='Z')or(a>='a' and a<='z');
}
void Spremna(string &s)
{
    for(int i=0;i<s.size();i++)
    {
        if(!Slovo(s[i]))
            continue;
        s[i]=tolower(s[i]);
        //s[i]+=32;
    }
}
mapica KreirajIndeksPojmova(string s)
{
    mapica mapa;
    if(s.length()==0)
        return mapa;
    auto it=s.begin();
    int index(0);
    while(it!=s.end())
    {
        if(!Validna(*it))
        {
            it++;
            index++;
            continue;
        }
        auto pomoc=it;
        while(Validna(*pomoc) and pomoc!=s.end())
            pomoc++;
        string rijec=s.substr(index,pomoc-it);
        Spremna(rijec);
        if(!mapa.count(rijec))
        {
            mapa.insert({rijec,{index}});
            index+=pomoc-it;
            it=pomoc;
        }
        else
        {
            mapa[rijec].insert(index);
            index+=pomoc-it;
            it=pomoc;
        }
    }
    //std::sort(mapa.begin(),mapa.end(),[](std::pair<string,set<int>> it1,std::pair<string,set<int>> it2){return (it1.first)<(it2.first);});
    return mapa;
}
set<int> PretraziIndeksPojmova(string s,mapica mapa)
{
    Spremna(s);
    if(!mapa.count(s))
        throw std::logic_error("Pojam nije nadjen");
    return mapa[s];
}
void IspisiIndeksPojmova(mapica mapa)
{
    auto it=mapa.begin();
    while(it!=mapa.end())
    {
        cout<<it->first  <<": ";      
        auto it2=(it->second).begin();
        if(it2==(it->second).end())
        {
            it++;
            continue;
        }
        for(int i=0;i<(it->second).size()-1;i++)
                cout<<*it2++<<",";
        cout<<*it2<<"\n";
        it++;
    }
}
int main ()
{
    cout<<"Unesite tekst: ";
    string s;
    getline(cin,s);
    auto mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    for(;;)
    {
        cout<<"\nUnesite rijec: ";
        string rijec;
        getline(cin,rijec);
        if(rijec==std::string("."))
            break;
        try
        {
            auto skup=PretraziIndeksPojmova(rijec,mapa);
            auto it=skup.begin();
            while(it!=skup.end())
                cout<<*it++<<" ";
            cout<<"\n";
        }
        catch(std::logic_error e)
        {
            cout<<"Unesena rijec nije nadjena!";
            continue;
        }
    }
    
	return 0;
}
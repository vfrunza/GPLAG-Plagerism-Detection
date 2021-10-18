/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
using std::cout;
using std::cin;
using std::map;
using std::string;
using std::vector;
using std::set;
void PretvoriUMala(string &s)
{
    int i(0);
    while(i<s.size())
    {
        if(s[i]>='A' && s[i]<='Z')
        s[i]+=('a'-'A');
        i++;
    }
}
map<string,set<int>> KreirajIndeksPojmova(string s)
{
    map<string,set<int>> mapa;
    PretvoriUMala(s);
    int i(0);
    while(i<s.size())
    {
        while(!((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) && i<s.size())
        i++;
        int j=i;
        while(((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) && i<s.size())
        i++;
        if(j!=i)
        mapa[s.substr(j,i-j)].insert(j);
    }
    return mapa;
}
set<int> PretraziIndeksPojmova(string s,map<string,set<int>> mapa)
{
    PretvoriUMala(s);
    if(mapa.count(s))
    return mapa[s];
    throw std::logic_error("Pojam nije nadjen");
}
void IspisiIndeksPojmova(map<string,set<int>> mapa)
{
    auto it(mapa.begin());
    while(it!=mapa.end())
    {
        cout<<it->first<<": ";
        auto it1((it->second).begin());
        int i(0);
        while(it1!=(it->second).end())
        {
            if((it->second).size()==1)
            {
                cout<<*it1;
                break;
            }
            cout<<*it1<<",";
            it1++;
            i++;
            if(i==(it->second).size()-1)
            break;
        }
        if((it->second).size()!=1)
        cout<<*it1;
        cout<<"\n";
        it++;
    }
}
int main ()
{
    string s,t;
    cout<<"Unesite tekst: ";
    std::getline(cin,s);
    IspisiIndeksPojmova(KreirajIndeksPojmova(s));
    cout<<"Unesite rijec: ";
    std::getline(cin,t);
    while(!((t.size()==1) && (t[0]=='.')))
    {
        try
        {
            for(auto x : PretraziIndeksPojmova(t,KreirajIndeksPojmova(s)))
            cout<<x<<" ";
            cout<<"\n";
        }
        catch(std::logic_error)
        {
            cout<<"Unesena rijec nije nadjena!\n";
        }
        cout<<"Unesite rijec: ";
        std::getline(cin,t);
    }
	return 0;
}
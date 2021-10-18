/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <stdexcept>
using namespace std;
bool JeliBila(map<string, set<int>> mapa, string x)
{
    auto it(mapa.find(x));
    if(it == mapa.end()) return false;
    return true;
}
void IspisiSkup(set<int> skup)
{
    for(auto it = skup.begin(); it != skup.end(); it++)
    {
        auto test(it);
        test++;
        if(test==skup.end())cout<<*it;
        else cout<<*it<<",";
    }
}
map<string, set<int>> KreirajIndeksPojmova(string s)
{
    map<string, set<int>> mapa;
    int brojac(0), pozicija(0);
    string temp;
    for (int i=0; i < s.length(); i++)
    {
        if (s[i] !=  ' ')
        {
            brojac++;
            int j = i;
            while (s[j] != ' ' && j < s.length()) j++;
            if(brojac>0)
            {
                pozicija+=i;
                temp=s.substr (i, j-i);
                if(!JeliBila(mapa, temp))
                {
                    set<int> skup;
                    skup.insert(pozicija);
                    mapa.insert(make_pair(temp, skup));
                }
                else
                {
                    auto it(mapa.find(temp));
                    it->second.insert(pozicija);

                }
                i=j;
                pozicija=0;
            }
        }
    }
    return mapa;
}


set<int>PretraziIndeksPojmova(string x, map<string, set<int>> mapa)
{
    auto it(mapa.find(x));
    if(it == mapa.end()) throw logic_error("Unesena rijec nije nadjena!");
    return it->second;
}


void IspisiIndeksPojmova(map<string, set<int>> mapa)
{
    for(auto it = mapa.begin(); it != mapa.end(); it++)
    {
        cout<<it->first <<": ";
        IspisiSkup(it->second);
        cout<<endl;
    }
}

int main()
{
    map<string, set<int>> mapa;
    string text;
    cout<<"Unesite tekst: ";
    getline(cin, text);
    mapa=KreirajIndeksPojmova(text);
    IspisiIndeksPojmova(mapa);
    for(;;)
    {
        string rijec;
        cout<<"Unesite rijec: ";
        getline(cin, rijec);
        if(rijec==".") break;
        else
        {
            try
            {
                for(auto x: PretraziIndeksPojmova(rijec, mapa)) cout<<x<<" ";
                cout<<endl;
            }
            catch(logic_error x)
            {
                cout<<x.what()<<endl;
            }
        }
    }
    return 0;
}

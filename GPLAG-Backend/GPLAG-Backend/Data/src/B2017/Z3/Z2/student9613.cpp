#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <stdexcept>

using namespace std;

typedef map<string, vector<string>> Knjiga;

string PretvoriUMalaSlova(string s)
{
    string pom;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='A' && s[i]<='Z')
            pom.push_back(s[i]+('a'-'A'));
        else
            pom.push_back(s[i]);
    }
    return pom;
}

bool SlovoIliBroj(char c)
{
    if((c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z'))
        return true;
    return false;
}

map<string, set<tuple<string, int, int>>> KreirajIndeksPojmova(Knjiga k)
{
    map<string, set<tuple<string, int, int>>> mapa;
    for(const auto &x:k)
    {
        for(int i=0; i<x.second.size(); i++)
        {
            for(int j=0; j<x.second[i].length(); j++)
            {
                int markacija;
                string pomocni;
                if(!SlovoIliBroj(x.second[i][j]) && SlovoIliBroj(x.second[i][j+1]) && j+1<x.second[i].size())
                {
                    j++;
                    markacija=j;
                    while(SlovoIliBroj(x.second[i][j]) && j<x.second[i].length())
                    {
                        pomocni.push_back(x.second[i][j]);
                        j++;
                    }
            
                }
                else if(SlovoIliBroj(x.second[i][j]))
                {
                    markacija=j;
                    while(SlovoIliBroj(x.second[i][j]) && j<x.second[i].length())
                    {
                        pomocni.push_back(x.second[i][j]);
                        j++;
                    }
                }
                pomocni=PretvoriUMalaSlova(pomocni);
                tuple<string, int, int> t{x.first, i+1, markacija};
                set<tuple<string, int, int>> skup;
                skup.insert(t);
                
                auto it(mapa.find(pomocni));
                if(it==mapa.end()) mapa[pomocni]=skup;
                else (it->second).insert(t);
            }
        }
    }
    return mapa;
}

set<tuple<string, int, int>> PretraziIndeksPojmova(string s, map<string, set<tuple<string, int, int>>> mapa)
{
    /*auto it(mapa.find(PretvoriUMalaSlova(s)));
    if(it==mapa.end()) throw logic_error("Pojam nije nadjen");
    else return it->second;*/
    for(auto &x:mapa)
        if(x.first.length()==s.length() && equal(s.begin(), s.end(), x.first.begin(),[](char prvi, char drugi){if(tolower(prvi)==tolower(drugi)) return 1; return 0;}))
            return x.second;
    throw logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(map<string, set<tuple<string, int, int>>> mapa)
{
    for(const auto &x:mapa)
    {
        cout<<x.first<<": ";
        for(set<tuple<string, int, int>>::iterator it=(x.second).begin(); it!=(x.second).end(); it++)
        {
            set<tuple<string, int, int>>::iterator pomit=(x.second).end();
            pomit--;
            if(it==pomit)
                cout<<get<0>(*it)<<"/"<<get<1>(*it)<<"/"<<get<2>(*it);
            else
                cout<<get<0>(*it)<<"/"<<get<1>(*it)<<"/"<<get<2>(*it)<<", ";
        }
        cout<<endl;
    }
}

int main ()
{
    Knjiga k;
    for(;;)
    {
        string s;
        cout<<"Unesite naziv poglavlja: ";
        getline(cin, s);
        if(s==".") break;
        int br(0);
        vector<string> v;
        for(;;)
        {
            string pom;
            br++;
            cout<<"Unesite sadrzaj stranice "<<br<<": ";
            getline(cin, pom);
            if(pom==".") break;
            v.push_back(pom);
        }
        k.insert({s, v});
    }
    map<string, set<tuple<string, int, int>>> Indeks=KreirajIndeksPojmova(k);
    cout<<endl<<"Kreirani indeks pojmova: "<<endl;
    IspisiIndeksPojmova(Indeks);
    
    for(;;)
    {
        string s;
        cout<<"Unesite rijec: ";
        getline(cin, s);
        if(s==".") break;
        try{
        set<tuple<string, int, int>> komp=PretraziIndeksPojmova(s, Indeks);
        for(auto &x:komp)
        {
            cout<<get<0>(x)<<"/"<<get<1>(x)<<"/"<<get<2>(x)<<" ";
        }
        }
        catch(logic_error)
        {
            cout<<"Unesena rijec nije nadjena!";
        }
        cout<<endl;
    }
    
	return 0;
}

/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

map<string,set<int>> KreirajIndeksPojmova (string s)
{
    map<string,set<int>> m;
    unsigned int i{0};
    vector<string>rijeci;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    
    while(i!=s.size())
    {
        while(i!=s.size() && !isalnum(s[i]))
            ++i;
        unsigned int j{i};
        while(j!=s.size() && isalnum(s[j]))
            j++;
        if(i!=j)
        {
            rijeci.push_back(s.substr(i,j-i));
            i=j;
        }
    }
    set<int> skup;
    
    for(unsigned int k=0;k<rijeci.size();k++)
    {
        size_t j{s.find(rijeci[k])};
        while(j!=string::npos && (j==0 || !isalnum(s[j-1])))
        {
            skup.insert(j);
            j=s.find(rijeci[k],j+(rijeci[k]).size());
        }
        m.insert(make_pair(rijeci[k],skup));
        skup.clear();
    }
    
    return m;
}

void IspisiIndeksPojmova(map<string,set<int>> mapa)
{
    for(map<string,set<int>>::iterator it1=mapa.begin();it1!=mapa.end();it1++)
    {
        cout<<it1->first<<": ";
        for(set<int>::iterator it2=(it1->second).begin();it2!=(it1->second).end();it2++)
        {
            auto sljedeci=it2;
            sljedeci++;
            if(sljedeci==(it1->second).end()) cout<< *it2;
            else cout<< *it2<<",";
        }
        cout<<endl;
    }
}

set<int> PretraziIndeksPojmova(string pojam,map<string,set<int>> mapa)
{
    bool PostojiPojam{false};
    set<int> skup;
    string low_pojam{pojam};
    transform(pojam.begin(),pojam.end(), low_pojam.begin(),::tolower);
    for(map<string,set<int>>::iterator it=mapa.begin();it!=mapa.end();it++)
    {
        if(low_pojam==it->first)
        {
            PostojiPojam=true;
            skup=it->second;
            break;
        }
    }
    if(!PostojiPojam) throw logic_error("Unesena rijec nije nadjena!");
    return skup;
}

int main ()
{
    cout<<"Unesite tekst: ";
    string s;
    getline(cin,s);
   map<string,set<int>> mapa;
   mapa=KreirajIndeksPojmova(s);
   IspisiIndeksPojmova(mapa);
   set<int> skup;
   cout<<"Unesite rijec: ";
   string pojam;
   getline(cin,pojam);
  
    while(pojam!=".")
   {
       try{
           skup=PretraziIndeksPojmova(pojam,mapa);
       for(int p : skup) cout<<p<<" ";
       cout<<endl;
       }
       catch(logic_error e) {cout<<e.what()<<endl;}
       cout<<"Unesite rijec: ";
       getline(cin,pojam);
   }
   
	return 0;
}
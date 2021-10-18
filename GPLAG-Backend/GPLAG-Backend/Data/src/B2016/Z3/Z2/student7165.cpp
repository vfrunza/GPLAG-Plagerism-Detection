/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<stdexcept>
#include<set>

using namespace std;

bool slova(char p)
{
    if((p>='a' && p<='z') || (p>='A'&& p<='Z'))
    return true;
    else
    return false;
}

map<string,set<int>>KreirajIndeksPojmova(string s)
{
    map<string,set<int>> mapa;
    string pomocni;
    int  index(0);
    
    for(int i=0;i<int(s.length());i++)
    {
        if(slova (s[i]) && i<int(s.length()))
        {
        index=i;
        while(slova(s[i]) && i<int(s.length()))
        {
            pomocni.push_back(s[i]);
            i++;
        }
        
        mapa[pomocni].insert(index);
        pomocni.resize(0);
    }
    }
    
    return mapa;
}

 set<int> PretraziIndeksPojmova(string s, map<string,set<int>> mapa)
{
    if(!mapa.count(s))
    {
    throw logic_error ("Pojam nije nadjen");}
    else
    return mapa[s];
}

void IspisiIndeksPojmova(map<string,set<int>> mapa)
{
    for(auto it1=mapa.begin();it1!=mapa.end();it1++)
    {
        cout<<(*it1).first<<": ";
        auto it2=(it1->second).begin();
        while(it2!=--(it1->second).end())
        {
            cout<<*it2<<",";
            it2++;
        }
        cout<<*it2<<endl;
    }
    
    
}


int main ()
{
    string p;
    cout<<"Unesite tekst: ";
    getline(cin,p);
    map<string,set<int>>mapa=KreirajIndeksPojmova(p);
    IspisiIndeksPojmova(mapa);
    string l={"."};
    for(;;)
    {
        cout<<"Unesite rijec: ";
        string rijec;
        getline(cin,rijec);
        if(rijec==l) break;
        try
        {
        set<int> skup;
        skup=PretraziIndeksPojmova(rijec,mapa);
        for(auto x:skup)
        cout<<x<<" ";
    }
    catch(...)
    {
        cout<<"Unesena rijec nije nadjena!";
    }
    cout<<endl;
}
return 0;
}
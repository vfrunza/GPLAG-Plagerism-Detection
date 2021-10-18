/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <string>
#include <cmath>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::set;
using std::map;
using std::logic_error;
using std::string;
using std::make_pair;

map<string,set<int>> KreirajIndeksPojmova (string recenica)
{
    bool tacnost;
    map<string,set<int>> rez;
    vector<string> kopija, ne;
    vector<int>lokacija;
    string temp, cisto, zapamti;
    set<int> skup, prazan;
    
    for (int i=0; i<recenica.length(); i++)
    {
        if ((recenica[i]>='A'&&recenica[i]<='Z')||(recenica[i]>='a'&&recenica[i]<='z')||(recenica[i]>='0'&&recenica[i]<='9'))
        {
            lokacija.push_back(i);
        }
        while((recenica[i]>='A'&&recenica[i]<='Z')||(recenica[i]>='a'&&recenica[i]<='z')||(recenica[i]>='0'&&recenica[i]<='9'))
        {
            temp.push_back(recenica[i]);
            i++;
        }
        
        kopija.push_back(temp);
        temp=cisto;
    }
    
    for (int j=0; j<kopija.size(); j++)
    {
        tacnost=false;
        for (int b=0; b<ne.size(); b++)
        {
            if (kopija[j]==ne[b])
            {
                tacnost=true;
            }
        }
        
        if (tacnost==false)
        {
            skup=prazan;
            skup.insert(lokacija[j]);
            for (int k=j+1; k<kopija.size(); k++)
            {
                if (kopija[j]==kopija[k])
                {
                    skup.insert(lokacija[k]);
                }
            }
            rez.insert(make_pair(kopija[j],skup));
        }
    }
    
    return rez;
}

void IspisiIndeksPojmova (map<string,set<int>> prva)
{
    for (auto i=prva.begin(); i!=prva.end(); i++)
    {
        cout<<i->first<<": ";
        for (auto x=i->second.begin(); x!=i->second.end(); x++)
        {
            cout<<*x;
            if (x!=--i->second.end())
            {
                cout<<",";
            }
        }
        cout<<endl;
    }
}

set<int> PretraziIndeksPojmova (string rijec, map<string,set<int>> prva)
{
    set <int> rez;
    auto it(prva.find(rijec));
    if (it==prva.end())
    {
        throw logic_error ("Unesena rijec nije nadjena!");
    }
    
    else
    {
        rez=it->second;
        return rez;
    }
}

int main ()
{
    map<string,set<int>> prva;
    string recenica, rijec("!!");
    set<int> skup, prazan;
    cout<<"Unesite tekst: ";
    getline(cin,recenica);
    prva=KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(prva);
    
    while (rijec!=".")
    {
        cout<<"Unesite rijec: ";
        getline(cin,rijec);
        if (rijec==".")
        {
            break;
        }
        try
        {
            skup=PretraziIndeksPojmova(rijec,prva);
        }
        catch (logic_error izuzetak)
        {
            skup=prazan;
            cout<<izuzetak.what()<<endl;
        }
        for (auto x=skup.begin(); x!=skup.end(); x++)
        {
            cout<<*x<<" ";
        }
        cout<<endl;
    }
    
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>
#include <algorithm>

using namespace std;

map<string,set<int>> KreirajIndeksPojmova(string recenica)
{
    string rijec;
    map<string,set<int>> mapa;
    for(int i=0; i<recenica.size();i++)
    {
        int zapamti = i; // ovo ce zapamtiti gdje je rijec zapocela prije nego sto ude u petlju
        while(i!=recenica.size() and ((recenica.at(i)>='0' and recenica.at(i)<='9') or (recenica.at(i)>='a' and recenica.at(i)<='z')))
        {
            rijec.push_back(recenica.at(i)); // formira rijec
            i++;
        }
        
    auto it(mapa.find(rijec)); // trazi postoji li rijec u mapi vec
    if(it!=mapa.end()) // ako je nasao u rjecniku da vec postoji
        (it->second).insert(zapamti);
    else 
    {
        set<int> setic;
        setic.insert(zapamti);
        mapa.insert(make_pair(rijec,setic));
    }
    
        rijec.clear(); // isprazni za nove rijeci
    }
    return mapa;
}

set<int> PretraziIndeksPojmova(string rijec, map<string, set<int>> mapa)
{
    auto it(mapa.find(rijec));
    if(it==mapa.end()) throw logic_error("Unesena rijec nije nadjena!");
    auto setic = it->second;
    return setic;
}

void IspisiSet1(set<int> setic)
{
    int brojac(1);
    for(auto i = setic.begin(); i!=setic.end(); i++)
    {
        if(brojac==setic.size()) cout << *i;
        else cout << *i << ",";
        brojac++;
    }
}

void IspisiSet2(set<int> setic)
{
    for(auto i = setic.begin(); i!=setic.end(); i++)
    {
         cout << *i << " ";
    }
}

void IspisiIndeksPojmova(map<string,set<int>> mapa)
{
    for(auto it = mapa.begin(); it!=mapa.end(); it++)
    {
        cout << it->first << ": ";
        IspisiSet1(it->second);
        cout << endl;
    }
    
}

int main ()
{
    string recenica, rijec;
 
     cout << "Unesite tekst: ";
     getline(cin, recenica);
     transform(recenica.begin(), recenica.end(), recenica.begin(), ::tolower);
     auto mapa=KreirajIndeksPojmova(recenica);
     IspisiIndeksPojmova(mapa);
     
    while(rijec!=".")
    {
        cout << "Unesite rijec: ";
        getline(cin, rijec);
        try
        {
            if(rijec==".") break;
            else IspisiSet2(PretraziIndeksPojmova(rijec,mapa));
        }
        catch(logic_error e)
        {
            cout << e.what();
        }
        
        cout << endl;
    }
    
	return 0;
}
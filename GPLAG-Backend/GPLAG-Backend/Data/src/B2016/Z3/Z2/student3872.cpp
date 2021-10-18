/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<map>
#include<set>
#include<cctype>
#include<string>
#include<stdexcept>
#include<vector>

using namespace std;

map<string, set<int>> KreirajIndeksPojmova(const string &MojString)
{
    map<string, set<int>> NovaMapa;
    for(int i(0);i<MojString.length();i++)
    {
        if(isalpha(MojString[i]))
        {
            set<int> Skup;
            string pomocni;
            while(MojString[i]!=' ' && i<MojString.length())
            {
                pomocni.push_back(MojString[i]);
                i++;
            }
            auto temp(NovaMapa.find(pomocni));
            if(temp!=NovaMapa.end())
            temp->second.insert(i-pomocni.size());
            else
            {
                Skup.insert(i-pomocni.size());
                NovaMapa.insert(pair<string, set<int>>(pomocni, Skup));
            }
        }
    }
    return NovaMapa;
}

set<int> PretraziIndeksPojmova(const string &MojString, map<string, set<int>> MojaMapa)
{
    auto temp(MojaMapa.find(MojString));
    if(temp==MojaMapa.end()) throw logic_error("Unesena rijec nije nadjena!");
    return temp->second;
}
void IspisiIndeksPojmova(map<string, set<int>> MojaMapa)
{
 for(map<string, set<int>>::iterator it(MojaMapa.begin()); it!=MojaMapa.end();it++)
 {
     cout<< it->first<<": ";
     int i=0;
     for(set<int>::iterator iter(it->second.begin());iter!=it->second.end();iter++, i++)
     {
         cout<<*iter;
         if(i!=int(it->second.size())-1)
         cout<<",";
     }
     cout<<endl;
 }
}
int main ()
{
	string test;
	getline(cin, test);
	auto Indeks(KreirajIndeksPojmova(test));
	cout<<"Unesite tekst: ";
	IspisiIndeksPojmova(Indeks);
	vector<string> MojVektor;
	while(1)
	{
	    cin>>test;
	    
	    MojVektor.push_back(test);
	    if(test==".") break;
	}
	for(string test: MojVektor)
	{
	    cout<<"Unesite rijec: ";
	    if(test==".") break;
	    try
	    {
	        auto p(PretraziIndeksPojmova(test, Indeks));
	        
	        for(int novi: p) 
	        cout<<novi<<" "; 
	        cout<<endl;
	    }
	    catch(logic_error izuzetak)
	    {
	        cout<<izuzetak.what()<<endl;
	    }
	}
	return 0;
}
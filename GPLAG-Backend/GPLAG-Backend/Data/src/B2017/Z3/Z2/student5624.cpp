/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <set>


using std::cin;
using std::cout;
using std::vector;
using std::map;
using std::string;
using std::set;

typedef map<string, vector<string>> Knjiga;

string Mala(string rijec)
{
    for(int i=0; i<rijec.size(); i++)
        if (rijec[i]>='A' && rijec[i]<='Z')
            rijec[i]+='a'-'A';
    
    return rijec;        
}


map<string, std::set<std::tuple<string, int, int>>> KreirajIndeksPojmova(Knjiga objekat)
{
    map<string, std::set<std::tuple<string, int, int>>> novi;
    for(auto it=objekat.begin(); it!=objekat.end(); it++)
    {
        for(int i=0; i<it->second.size(); i++)
        {
            string strana=it->second[i];
            for(int j=0;j<strana.length();j++)
            {
                string rijec="";
                int pom=j;
                while(j<strana.length() && strana.substr(j,1)!=" ")
                    rijec+=strana.substr(j++,1);
                novi[Mala(rijec)].insert(std::make_tuple(it->first,i+1,pom));
            }
        }
    }
    return novi;
}

set<std::tuple<string, int, int>> PretraziIndeksPojmova(string rijec, map<string, set<std::tuple<string, int, int>>> indeks)
{
   auto it(indeks.find(rijec));
    if (it == indeks.end())
        throw std::logic_error("Pojam nije nadjen");
    else
        return it->second;
}

void IspisiIndeksPojmova(map<string, set<std::tuple<string, int, int>>> indeks)
{
    for(auto it=indeks.begin(); it!=indeks.end(); it++)
    {
        cout<<it->first<<": ";
        for(auto it2=it->second.begin(); it2!=it->second.end(); it2++)
        {
            if (it2!=it->second.begin())
                cout<<", ";
            cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2);
        }
        cout<<"\n";
    }
        
}


int main ()
{
    Knjiga knjiga;
    while(1)
    {
        cout<<"Unesite naziv poglavlja: ";
        string s;
        std::getline(cin, s);
        if (s[s.length()-1]=='.')
            break;
        int br(1);    
        while(1)
        {
            cout<<"Unesite sadrzaj stranice "<<br<<": ";
            string rijeci;
            std::getline(cin, rijeci);
            if (rijeci[rijeci.length()-1]=='.')
                break;
            knjiga[s].push_back(rijeci);
            br++;    
        }    
    }
    auto indekspojmova=KreirajIndeksPojmova(knjiga);
    cout<<"\nKreirani indeks pojmova: \n";
    IspisiIndeksPojmova(indekspojmova);
    while(1)
    {
        try
        {
            cout<<"Unesite rijec: ";
            string rijec;
            std::getline(cin, rijec);
            if (rijec[rijec.length()-1]=='.')
                break;
             auto skup(PretraziIndeksPojmova(rijec,indekspojmova));
             for(auto it=skup.begin(); it!=skup.end(); it++)
                cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it) << " ";
            std::cout << "\n";
        }
        catch(std::logic_error izuzetak)
        {
            cout << "Unesena rijec nije nadjena!\n";
        }
    }
	return 0;
}

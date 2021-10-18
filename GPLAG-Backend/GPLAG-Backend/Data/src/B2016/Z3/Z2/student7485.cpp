#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::set;
using std::map;



string MalaSlova(string rijec)
{
    string mala_rijec;
    for(int i=0;i<rijec.length();i++)
    {
        if (rijec[i]>='A' && rijec[i]<='Z') 
            rijec[i]+='a'-'A';
    }
    mala_rijec=rijec;
    
    return mala_rijec;
}

map<string,set<int>> KreirajIndeksPojmova(string recenica)
{
    map<string,set<int>> pojmovi;
    for(int i=0;i<recenica.length();i++)
    {
        int brojac(0); 
        if (!((recenica[i]>47 && recenica[i]<58) || (recenica[i]>64 && recenica[i]<91) || (recenica[i]>96 && recenica[i]<123))) continue;
        else
        {
            int j;
            for(j=i;j<recenica.length();j++)
            {
             if (!((recenica[j]>47 && recenica[j]<58) || (recenica[j]>64 && recenica[j]<91) || (recenica[j]>96 && recenica[j]<123)))
                    break;
                else 
                    brojac++;
            }    
            string rijec;
            rijec=recenica.substr(i,brojac);
            string rijec2;
            rijec2=MalaSlova(rijec);
            pojmovi[rijec2].insert(i);
            i=j;
        }
    } 
    
    return pojmovi;
}

set<int> PretraziIndeksPojmova(string rijec,map<string,set<int>> pojmovi)
{
    auto it(pojmovi.find(rijec));
    if (it==pojmovi.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    else return it->second;
}

void IspisiIndeksPojmova(std::map < string , set<int> > pojmovi)
{
    for(auto it=pojmovi.begin();it!=pojmovi.end();it++)
    {
        cout<<it->first<<": ";
        for (auto it2=it->second.begin();it2!=it->second.end();it2++)
        {
            if (++it2==it->second.end())
            {
                it2--;
                cout<<*it2;
            }
            else//(++it2!=it->second.end())
            {
                it2--;
                cout<<*it2<<",";
            }
        }   
        cout<<"\n";    
    }
}


int main ()
{
    
    string s;
    cout<<"Unesite tekst: ";
    std::getline(cin,s);
    map<string,set<int>> pojmovi;
    pojmovi=(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(pojmovi);
    
    string s2;
    while(1)
    {
        cout<<"Unesite rijec: ";
        std::getline(cin,s2);
        if (s2==".") break;
        try
        {   
            for(int x:PretraziIndeksPojmova(s2,pojmovi))
                cout<<x<<" ";
        }
        catch(std::logic_error izuzetak)
        {
            cout<<izuzetak.what();
        }  
        cout<<"\n";
    }
	return 0;
}
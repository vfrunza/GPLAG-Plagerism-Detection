/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <set>
#include <string>
#include <algorithm>
#include <stdexcept>


using namespace std;


bool VratiChar(char c)
{
    
    return (tolower(c)>='a' && tolower(c)<='z')|| (c>='0' && c<='z');
}

string DownCase(string s)
{
    for(auto &a:s)
        a=tolower(a);
    return s;
}

map<string,set<tuple<string,int,int>>>KreirajIndeksPojmova(map<string,vector<string>> knjiga)
{
    map<string,set<tuple<string,int,int>>> indeks;
    
        for(auto a:knjiga)
        {   int brojac=1;
            for(auto b:a.second)
            {   
                
                for(int i=0;i<b.size();i++)
                {   
                   set<tuple<string,int,int>> s;
                   int j=i;
                   for(;VratiChar(b[j]);j++);
                   string rijec=b.substr(i,j-i);
                   //cout<<rijec<<endl;
                   rijec=DownCase(rijec);
                   auto it=find_if(indeks.begin(),indeks.end(),[rijec](pair<string,set<tuple<string,int,int>>> s){return rijec==s.first;});
                    int duz=j-i;
                    if(it==indeks.end()) 
                    {
                        s.insert(make_tuple(a.first,brojac,i));
                        for(int br=j;br<=b.size();br++)
                        {    
                            if(rijec==DownCase(b.substr(br-duz,duz))){
                                s.insert(make_tuple(a.first,brojac,br-duz));
                               
                                
                            }
                        }
                        
                       indeks[rijec]=s;
                    }
                    else 
                    {
                        for(int br=j;br<=b.size();br++)
                        {    
                            if(rijec==DownCase(b.substr(br-duz,duz))){
                                indeks[rijec].insert(make_tuple(a.first,brojac,br-duz));
                               
                                
                            }
                        }
                    }
                    i+=duz;
                  
                }
                brojac++;
            }
        }
    return indeks;
}

set<tuple<string,int,int>> PretraziIndeksPojmova(string rijec,map<string,set<tuple<string,int,int>>> i)
{
    auto it=find_if(i.begin(),i.end(),[rijec](pair<string,set<tuple<string,int,int>>> s){return rijec==s.first;});
    if(it==i.end()) throw logic_error("Unesena rijec nije nadjena!");
    return it->second;
                    
}

void IspisiIndeksPojmova(map<string,set<tuple<string,int,int>>> i)
{
    for(auto a:i)
    {
        cout<<a.first<<": ";int br=0;
        for(auto b:a.second)
        {   
            if(br<a.second.size()-1)
                cout<<get<0>(b)<<"/"<<get<1>(b)<<"/"<<get<2>(b)<<", ";
            else 
                cout<<get<0>(b)<<"/"<<get<1>(b)<<"/"<<get<2>(b);
          br++;  
        }
        cout<<endl;
    }
}
int main ()
{   
    map<string,vector<string>>  k;
    while(1)
    {
        cout<<"Unesite naziv poglavlja: ";
        string s;int br=1; vector<string>v;
        getline(cin,s);
        if(s.size()==1 && s[0]=='.') break;
        string stranica;
        while(1)
        {
            cout<<"Unesite sadrzaj stranice "<<br<<": ";
            getline(cin,stranica);
            if(stranica.size()==1 && stranica[0]=='.') break;
            v.push_back(stranica);
            br++;
        }
        k.insert(make_pair(s,v));
        
    }
    cout<<endl;
    map<string,set<tuple<string,int,int>>> i=KreirajIndeksPojmova(k);
    cout<<"Kreirani indeks pojmova:"<<endl;
    IspisiIndeksPojmova(i);
    
    while(1)
    {
        string s;
        cout<<"Unesite rijec: ";
        getline(cin,s);
        if(s.size()==1 && s[0]=='.') break;
        
        try
        {
        set<tuple<string,int,int>> skup=PretraziIndeksPojmova(s,i);
        for(auto b:skup)
        {
            cout<<get<0>(b)<<"/"<<get<1>(b)<<"/"<<get<2>(b)<<" ";
        }
        cout<<endl;
            
        }
        catch(logic_error e)
        {
            cout<<e.what()<<endl;
        }
        
    }
    
	return 0;
}

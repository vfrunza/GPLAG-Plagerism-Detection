/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <set>
using std::cout;
using std::cin;
using std::endl;


void PretvoriUMala( std::string &s)
{
    for(int i(0); i<s.length(); i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            s[i]=s[i]+32;
        }
    }
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova( std::string s)
{
    PretvoriUMala(s);
   
    std::string rijec;
    std::map<std::string, std::set<int>> pojmovi;
    for( int i(0); i<s.length(); i++)
    {
        
        int indeks(i);
        rijec="";
        if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        {
            
            while((s[i]>='a' && s[i]<='z')  ||  (s[i]>='0' && s[i]<='9'))
            {
                rijec=rijec+s[i];
                i++;
            }
            pojmovi[rijec].insert(indeks);
        }
    }
    return pojmovi;
}

std::set<int> PretraziIndeksPojmova( std::string s, std::map< std::string, std::set<int>> m)
{
    bool tacno(false);
    PretvoriUMala(s);
    std::set<int> skup;
    for( const auto &i: m)
    {
        if(s==i.first)
        {
            tacno=true;
            for( const auto &j: i.second)
            {
                skup.insert(j);
            }
            break;
        }
    }
    if(tacno==false) throw std::logic_error("Unesena rijec nije nadjena!");
     return skup;
}

void IspisiIndeksPojmova( const std::map<std::string , std::set<int>> &m  )
{
   
    for(const auto &i: m )
    {
        int ispis(0);
        int br(0);
        cout<<i.first<<": ";
        for(const auto &j: i.second)
        {
            br++;
        }
        for( const auto &j : i.second)
        {
            ispis++;
            if(ispis==br) cout<<j;
            else cout<<j<<",";
        }
    cout<<endl;
    }
   
}


int main ()
{
   cout<<"Unesite tekst: ";
   std::string recenica;
   std::getline(cin,recenica);
   std::map<std::string, std::set<int>> m=KreirajIndeksPojmova(recenica);
   IspisiIndeksPojmova(m);
   std::string rijec;
   do{
   
    cout<<"Unesite rijec: ";
    std::getline(cin, rijec);
    if(rijec==".") break;
    
    std::set<int> skup; 
    try
    {
        skup=PretraziIndeksPojmova(rijec, m);
        for( const auto &i: skup)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    catch( std::logic_error e)
    {
        cout<<e.what()<<endl;
    }
    
    
   }
    while(rijec!=".");
    
    
	return 0;
}
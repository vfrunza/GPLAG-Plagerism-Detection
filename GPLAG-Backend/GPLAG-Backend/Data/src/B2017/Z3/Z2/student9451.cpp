/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <tuple>
#include <stdexcept>

using namespace std;

typedef std::map<std::string, std::vector<std:: string>> Knjiga;
typedef map<string,set<tuple<string,int,int>>> Indeks;
typedef std::vector<std:: string> Stranica;
typedef set<tuple<string,int,int>> Skup;

bool JelSlovo(char c)
{
    return (c>='0' && c<='9') || (tolower(c)>='a' && tolower(c)<='z'); 
}

Stranica VratiRijeci(Stranica s)
{   
    Stranica r;
    for(int i=0;i<s.size();i++)
    {   
        
        for(int j=0;j<s[i].size();j++)
        {   
            int br=0;
            while(JelSlovo(s[i][j]))
            {
                br++;
                j++;
            }
            if(!JelSlovo(s[i][j]))
                r.push_back(s[i].substr(j-br,br));
        }
    }
    return r;
}

void IspisStranicu(Stranica s)
{
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i]<<endl;
    }
}
void IspisiIndeksPojmova(Indeks i)
{   
    //cout<<i.size()<<" ";
   // cout<<"Indeks: "<<endl;
    for(auto it=i.begin();it!=i.end();it++)
    {   
        
        cout<<it->first<<": ";
        int br=0;
        for(auto it1=it->second.begin();it1!=it->second.end();it1++,br++)
        {
            cout<<get<0>(*it1)<<"/";
            
            cout<<get<1>(*it1)<<"/";
            
            
            if(br==it->second.size()-1)
                    cout<<get<2>(*it1);
            else 
                cout<<get<2>(*it1)<<", ";
        }   
        cout<<endl;
    }
    
}

int VratiPoziciju(string s,string p)
{
    for(int i=0;i<p.size();i++)
    {
        if(s==p.substr(i,s.size()))
            return i;
    }
}

Indeks KreirajIndeksPojmova(Knjiga k)
{
    Indeks i;
    
    for(auto it=k.begin();it!=k.end();it++)
    {  
        Stranica s=it->second;
        for(int j=0;j<s.size();j++)
        {  
            string r;
            int duz; 
            
            for(int k=0;k<s[j].size();k++)
            {
                int br=0;
                Skup skup;
                while(JelSlovo(s[j][k]))
                {
                    br++;
                    k++;
                }
                if(!JelSlovo(s[j][k]))
                    r=s[j].substr(k-br,br);
                
                for(auto &a:r)
                    a=tolower(a);
                    
                bool ima=0;
                for(auto a:i)
                    if(r==a.first) ima=1;
                
                
                skup.insert(make_tuple(it->first,j+1,k-br));
                
               
                    for(int p=k;p<=s[j].size();p++)
                    {       
                        if(r==s[j].substr(p-br,br))
                            skup.insert(make_tuple(it->first,j+1,p-br));
                    }
                if(ima==0)
                  i[r]=skup;
                 else
                 { 
                     for(auto a:skup)
                     i[r].insert(a);
                 }
            }
           
           
        }
        
    }
    
    return i;
}

Skup PretraziIndeksPojmova(string s,Indeks i)
{
    for(auto a:i)
    {
        if(a.first==s)
            return a.second;
    }
    throw logic_error("Unesena rijec nije nadjena!");
}

int main ()
{   
    Knjiga k;
     for(;;)
     {
          cout<<"Unesite naziv poglavlja: ";
          string s; getline(cin,s);
          if(s==".") break;
          vector<string> v;
          int br=1;
          for(;;)
          {
               cout<<"Unesite sadrzaj stranice "<<br++<<": ";
               string trojka;
               getline(cin,trojka);
               if(trojka==".") break;
               else v.push_back(trojka);
          }
          k[s]=v;
     }
     Indeks ind=KreirajIndeksPojmova(k);
     cout<<endl<<"Kreirani indeks pojmova: "<<endl;
     IspisiIndeksPojmova(ind);
     for(;;)
     {
          cout<<"Unesite rijec: ";
          string trojka; getline(cin,trojka);
          if(trojka==".") break;
          try{
          auto str=PretraziIndeksPojmova(trojka,ind);
          int i=0;
          for(auto it=str.begin(); it!=str.end(); it++,i++)
               {
                    auto trojka=*it;
                    cout<<get<0>(trojka)<<"/"<<get<1>(trojka)<<"/"<<get<2>(trojka)<<" ";
                    if(i==(str.size())-1) cout<<endl;
                    
               }
          }catch(logic_error e) {cout<<e.what()<<endl; }
     }
    return 0;
}

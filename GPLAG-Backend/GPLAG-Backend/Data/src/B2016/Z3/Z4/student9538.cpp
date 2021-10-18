/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <stdexcept>

using namespace std;

void IspisiTimove(vector<set<string>> Timovi)
{
    for(int i=0;i<Timovi.size();i++)
    {   
        cout<<"Tim "<<i+1<<": ";int br=0;
        for(auto it=Timovi[i].begin();it!=Timovi[i].end();it++)
        {    br++;
            if(br==Timovi[i].size())cout<<*it; 
                else cout<<*it<<", ";
                
        }
        cout<<endl;
    }
}

void IspisiSkup(set<string> s)
{
    for(auto i=s.begin();i!=s.end();i++)
        cout<<*i<<endl;
}

void IspisiListu(list<string> l)
{   
    cout<<"Ovdje: "<<endl;
    for(auto i=l.begin();i!=l.end();i++)
            cout<<*i<<endl;
    cout<<"----------------------------"<<endl;
}

int PrebrojiSlova(string s)
{  int br=0;
    for(int i=0;i<s.size();i++)
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
                br++;
    
    return br;
    
}

vector<set<string>> Razvrstavanje(vector<string> v,int k)
{   
    if(k<1 || k>v.size()) throw logic_error("Razvrstavanje nemoguce");
    vector<set<string>> timovi;
    list<string> l(v.begin(),v.end());
    
    
    int brc,brm;
    brc=v.size()/k;
    if(v.size()%k!=0)
         brm=v.size()/k+1;
    else brm=brc;
    int brt=v.size()%k;
    
    
    auto i=l.begin();
    for(int j=0;j<k;j++)
    {   
        set<string> pom;
        
            int br=0;
        while (!l.empty())
        {
            pom.insert(*i);br++;
            int vel=PrebrojiSlova(*i);
            
            i=l.erase(i);
            if(i==l.end())i=l.begin();
            
            for(int p=0;p<vel-1;p++){
                   i++;
                   if(i==l.end()){i=l.begin();}
            }
           
            if(br==brm && j<brt){break;}
            else if(br==brc && j>=brt) {break;}
            
        }
        timovi.push_back(pom);
    }
    
    return timovi;
}


int main ()
{   
   
    int n;
    cout<<"Unesite broj djece: ";
    cin>>n;
    vector<string> v;
    cout<<"Unesite imena djece: "<<endl;
    cin.clear();
    cin.ignore(10000,'\n');
    for(int i=0;i<n;i++)
    {   
        
        string s;
        getline(cin,s);
        v.push_back(s);
    }
   
    int br;
    cout<<"Unesite broj timova: ";
    cin>>br;
    try{
    vector<set<string>> timovi=Razvrstavanje(v,br);
    IspisiTimove(timovi);
    }
    catch(logic_error e){cout<<"Izuzetak: "<<e.what();}
    return 0;
}
/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>
using namespace std;

struct Dijete
{
    string ime;
    shared_ptr<Dijete> sljedeci;
};

int PrebrojiSlova(string s)
{  int br=0;
    for(int i=0;i<s.size();i++)
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
                br++;
    
    return br;
    
}

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

shared_ptr<Dijete> KreirajListu(vector<string> v)
{   
    shared_ptr<Dijete> poc=nullptr;
    shared_ptr<Dijete> trenutni=nullptr;
    
    for(int i=0;i<v.size();i++)
    {
        shared_ptr<Dijete> novi=make_shared<Dijete>();
        novi->ime=v[i];
        
        if(i==0)
        {
            poc=novi;
            trenutni=novi;
        }
        else 
        {
            trenutni->sljedeci=novi;
            trenutni=novi;
        }
        if(v.size()-1==i) novi->sljedeci=poc;
    }
    return poc;
}


vector<set<string>> Razvrstavanje(vector<string> v,int k)
{   
    if(k<1 || k>v.size()) throw logic_error("Razvrstavanje nemoguce");
    
    vector<set<string>> timovi;
    int brc,brm;int brd=v.size();
    brc=v.size()/k;
    if(v.size()%k!=0)
         brm=v.size()/k+1;
    else brm=brc;
    int brt=v.size()%k;
    
    shared_ptr<Dijete> l=KreirajListu(v);
    
    shared_ptr<Dijete> pom=l,pom1=l;
    while(pom1->sljedeci!=pom) pom1=pom1->sljedeci;
    
    
    for(int j=0;j<k;j++)
    {   
        set<string> skup;
        
        int br=0;
        while(brd!=0)
        {   
            
            skup.insert(pom->ime);br++;brd--;
            int vel=PrebrojiSlova(pom->ime);
            
            if(brd!=0)
            {
                pom1->sljedeci=pom->sljedeci;
                pom->sljedeci=nullptr;
                //delete pom;
                pom=pom1->sljedeci;
                
                for(int i=0;i<vel-1;i++)
                {
                    pom1=pom1->sljedeci;
                    pom=pom->sljedeci;
                }
            
          
            }
            else{
                pom->sljedeci=nullptr;
                //delete pom;
            }
            if(br==brm && j<brt){break;}
            else if(br==brc && j>=brt) {break;}
            
        }
        timovi.push_back(skup);
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
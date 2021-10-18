/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>


using namespace std;

char ToLower(char c)
{   
    if(c>='A' && c<='Z')
             c+=32;
    return c;
}
    
string ToLower(string c)
{  
    for(int i=0;i<c.size();i++)
        if(c[i]>='A' && c[i]<='Z')
                c[i]+=32;
    return c;
}

bool JelSlovo(char s)
{
    if((ToLower(s)>='a' && ToLower(s)<='z') || (s>='1' && s<='9'))
        return true;
    return false;
}

set<int> VratiDuplikate(string c,string s)
{   
    set<int> skup;
     for(int i=0;i<s.size();i++)
        {
            string pom;int index;
            if(i==0 || s[i-1]==' ' || !JelSlovo(s[i-1]))
            {  
                int br=0;index=i;
                while((ToLower(s[i])>='a' && ToLower(s[i])<='z') || (s[i]>='1' && s[i]<='9'))
                {
                    i++;
                    br++;
                }
              
                pom=s.substr(index,br);
                
                pom=ToLower(pom);
            }
            if (pom==c) skup.insert(index);
        }
    return skup;    
}

map<string,set<int>> KreirajIndeksPojmova(string s)
{
    map<string,set<int>> m;
                
    
        for(int i=0;i<s.size();i++)
        {
            string pom;
            if(i==0 || s[i-1]==' ' || !JelSlovo(s[i-1]))
            {  int br=0;int index=i;
                while((ToLower(s[i])>='a' && ToLower(s[i])<='z') || (s[i]>='1' && s[i]<='9'))
                {
                    i++;
                    br++;
                    
                }
               
                pom=s.substr(index,br);
                pom=ToLower(pom);
            
            }
            if(pom.size()!=0)
            {
             set<int> skup=VratiDuplikate(pom,s);
             m.insert(make_pair(pom,skup));
            }
            
        }
    
    return m;
    
}

set<int> PretraziIndeksPojmova(string s,map<string,set<int>> m)
{
    bool postoji=false;
    for(auto i=m.begin();i!=m.end();i++)
    {
        if(i->first==s){postoji=true; return i->second;}
    }
    if(postoji==false) throw logic_error("Unesena rijec nije nadjena!");
}

void IspisiIndeksPojmova(map<string,set<int>> m)
{
    for(auto i=m.begin();i!=m.end();i++)
    { int br=0;
        cout<<i->first<<": ";
            for(auto j:i->second)
             { 
                 br++;
                 if(br==i->second.size())
                      cout<<j;
                 else cout<<j<<",";
             }
        
        cout<<endl;            
    }   
}

void IspisiSkup(set<int> s)
{
    for(auto i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
int main ()
{
    string s;
    cout<<"Unesite tekst: ";
    getline(cin,s);
    
    map<string,set<int>> m=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(m);
    
    for(;;)
    {   
        string rijec;
        cout<<"Unesite rijec: ";
        cin.clear();
        cin>>rijec;
        if(rijec==".") break;
        try{
        set<int> skup=PretraziIndeksPojmova(rijec,m);
        IspisiSkup(skup);
        }
        catch(logic_error e){cout<<e.what()<<endl;}
    }
    
	return 0;
}
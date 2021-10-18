/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <string>
#include <map>
#include <cctype>

using namespace std;

map<string,set<int>> KreirajIndeksPojmova(string s)
{
    map<string,set<int>>m;
    string novi="",novi2="";
    int poc=0,poc2=0,kraj=0;
    for(int i=0;i<s.size();i++)
    {
        if((toupper(s[i])>='A' && toupper(s[i])<='Z') || (s[i]>='0' && s[i]<='9') &&(i==0 || (toupper(s[i-1])<'A' || toupper(s[i-1])>>'Z') || (s[i-1]<'0' && s[i-1]>'9')))
        {
            set<int> skup;
            poc=i;
            skup.insert(i);
            while((toupper(s[i])>='A' && toupper(s[i])<='Z') || (s[i]>='0' && s[i]<='9') && i<s.size()){
            if(s[i]>='A' && s[i]<='Z') novi+=(s[i]-'A'+'a');
            else
            novi+=s[i];
            
                i++;
            }
            kraj=i;
            for(int i=kraj;i<s.size();i++)
            {
                if(((toupper(s[i])>='A' && toupper(s[i])<='Z') || (s[i]>='0' && s[i]<='9')) && ((toupper(s[i-1])<'A' || toupper(s[i-1])>'Z') || (s[i-1]<'0' && s[i-1]>'9')))
                { poc2=i;
                while((toupper(s[i])>='A' && toupper(s[i])<='Z') || (s[i]>='0' && s[i]<='9') && i<s.size())
                {
                   if(s[i]>='A' && s[i]<='Z') novi2+=(s[i]-'A'+'a');
                else
                novi2+=s[i];
                i++;
                 } 
                 if(novi==novi2) skup.insert(poc2);
            }
            novi2="";
           
            }
            m.insert(make_pair(novi,skup));
        }
        novi="";
    }
    return m;
}

set<int> PretraziIndeksPojmova(string s, map<string,set<int>> m)
{
    set<int> skup;
    for(int i=0;i<s.size();i++)
    if(s[i]>='A' && s[i]<='Z')s[i]-=('A'-'a');
    bool ima=false;
    for(const auto &i : m)
    
        if(s==(i).first)
        { ima=true;
            for(const auto &j : i.second)
                skup.insert(j);
                return skup;
        }
        if(!ima)
        throw logic_error ("Pojam nije nadjen");
        
        
}

void IspisiIndeksPojmova(map<string,set<int>>m)
{
    
    for(const auto &i : m)
    {   int k=0;
        cout<<(i).first<<": ";
        for(const auto &j : i.second)
        {   
            if(k<(i.second).size()-1){
            cout<<j<<",";
            k++;
            }
            else cout<<j;
        }
        cout<<endl;
    }
}
int main ()
{
    string s,s1;
    set<int> skup;
    cout<<"Unesite tekst: ";
    getline(cin,s);
    map<string,set<int>> m;
    m=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(m);
    do
    {
        pocetak:
        cout<<"Unesite rijec: ";
        getline(cin, s1);
        if(s1==".") break;
        
    
    try
    {
        skup=PretraziIndeksPojmova(s1,m);
    }
    catch(logic_error)
    {
        cout<<"Unesena rijec nije nadjena!"<<endl;
        goto pocetak;
    }
    for(const auto &i : skup)
    cout<<i<<" ";
    cout<<endl;
    }
    while(true);
	return 0;
}
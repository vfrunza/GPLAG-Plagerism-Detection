/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <set>
#include <cstring>
using namespace std;

bool slovo(char a)
{
    if((toupper(a)>='A'&&toupper(a)<='Z') || (a>='0'&&a<='9')) return true;
    return false;
}

map<string,set<int>> KreirajIndeksPojmova(string s)
{
    for(int i=0; i<s.size(); i++)
    {
        if(toupper(s[i])>='A' && toupper(s[i])<='Z') s[i]=tolower(s[i]);
    }
    map<string, set<int>> m;
    for(int i=0; i<s.size(); i++)
    {
        if(slovo(s[i]))
        {
            int p=i;
            while(i!=s.size() && slovo(s[i])) {i++;}
            int k=i;
            string pom=s.substr(p,k-p);
            set<int> pr;
            for(int j=0; j<s.size(); j++)
                if(s.substr(j, pom.size())==pom && (j==0 || !slovo(s[j-1])) && (j+pom.size()==s.size() || !slovo(s[j+pom.size()]))) pr.insert(j);
            m.insert(make_pair(pom,pr));
        }
        
    }
    return m;
}

set<int> PretraziIndeksPojmova(string s, map<string, set<int>> m)
{
    for(int i=0; i<s.size(); i++)
    {
        if(toupper(s[i])>='A' && toupper(s[i])<='Z') s[i]=tolower(s[i]);
    }
    for(auto it=m.begin(); it!=m.end(); it++)
    {
        if(it->first==s) return it->second;
    }
    throw logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova (map<string, set<int>> m)
{
    for(auto it=m.begin(); it!=m.end(); it++)
	{
	    cout<<it->first<<": ";
	    int br=it->second.size();
	    for(auto x: it->second)
	    {
	        if(br!=1) cout<<x<<",";
	        else cout<<x;
	        br--;
	    }
	    cout<<endl;
	}
}

int main ()
{
	string s;
	cout<<"Unesite tekst: ";
	getline(cin,s);
	auto m=KreirajIndeksPojmova(s);
	IspisiIndeksPojmova(m);
	while(1)
	{
	    cout<<"Unesite rijec: ";
	    string p; getline(cin,p);
	    if(p==".") break;
	    try{
	        set<int> pom=PretraziIndeksPojmova(p,m);
	        for(auto x: pom) cout<<x<<" ";
	        cout<<endl;
	    }
	    catch(logic_error) { cout<<"Unesena rijec nije nadjena!"<<endl;}
	}
	return 0;
}
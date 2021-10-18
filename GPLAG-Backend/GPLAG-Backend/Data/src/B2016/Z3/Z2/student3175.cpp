/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <string>
#include <stdexcept>
#include <map>
#include <cstring>
using namespace std;

void smanjirecenicu(string &s)
{
    for(int i=0; i<s.length(); i++)
        if(s[i]>='A'&&s[i]<='Z') s[i]=tolower(s[i]);
}

bool abcda(char a)
{
    if(a>='a'&&a<='z') return true;
    else return false;
}

bool brj(char a)
{
    if(a>='0'&&a<='9') return true;
    else return false;
}

bool pocetak(int n)
{
    return n==0;
}

bool kraj(int j, int n, int d)
{
    return j+n==d;
}

map<string,set<int>> KreirajIndeksPojmova(string s)
{
    smanjirecenicu(s);
    map<string,set<int>> rez;
    for(int i=0; i<s.length(); i++)
    {
        if(abcda(s[i])==true || brj(s[i])==true)
        {
            auto marker=i;
            while((i!=s.length())&&(abcda(s[i])==true || brj(s[i])==true)){ 
                i++;}
            string clan;
            set<int>clandr; 
            for(int j=marker; j<i; j++) clan+=s[j];
            for(int j=0; j<s.length(); j++)
                if(s.substr(j,clan.length())==clan && (j==0||(!abcda(s[j-1])&&!brj(s[j-1]))) && (j+clan.length()==s.length()||(!abcda(s[j+clan.size()])&&!brj(s[j+clan.length()]))))
                {
                    clandr.insert(j);
                }
            pair<string,set<int>> par=make_pair(clan,clandr);
            rez.insert(par);
        }
    }
    return rez;
}

void IspisiIndeksPojmova(map<string,set<int>> mapa)
{
    for(auto i=mapa.begin(); i!=mapa.end(); i++)
    {
        cout<<i->first<<": ";
        auto a=i->second.size();
        a--;
        for(auto it: i->second)
        {
            cout<<it;
            if(a!=0) cout<<",";
            a--;
        }
        cout<<endl;
    }
}

set<int> PretraziIndeksPojmova(string rec, map<string,set<int>> mapa)
{
    smanjirecenicu(rec);
    bool ima=false;
    set<int> rez;
    for(auto i=mapa.begin(); i!=mapa.end(); i++)
    {
        if(rec==i->first) { ima=true; rez=i->second;}
    }
    if(ima) return rez;
    else throw logic_error("Pojam nije nadjen");
}

int main ()
{
	
	cout<<"Unesite tekst: ";
	string rec; 
	getline(cin,rec);
	map<string,set<int>> mapa=KreirajIndeksPojmova(rec);
	IspisiIndeksPojmova(mapa);
	for(;;)
	{
	    string p;
	    cout<<"Unesite rijec: ";
	    getline(cin,p);
	    if(p!=".")
	    {
	        try
	        {
	            auto skup=PretraziIndeksPojmova(p,mapa);
	            for(auto x: skup) cout<<x<<" ";
	            cout<<endl;
	        } catch(logic_error) { cout<<"Unesena rijec nije nadjena!"<<endl;}
	    }
	    else break;
	}
	return 0;
}
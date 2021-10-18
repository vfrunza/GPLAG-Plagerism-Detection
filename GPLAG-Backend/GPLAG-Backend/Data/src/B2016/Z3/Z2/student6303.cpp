/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <stdexcept>
using namespace std;

bool sl(char s)
{
    if((s>='A'&&s<='Z')||(s>='a'&&s<='z')) return true;
    return false;
}

bool moze(char s)
{
    return ((s>='a'&&s<='z')||(s>='0'&&s<='9'));
}

bool ispred(int k, string t)
{
    return (k==0 || !moze(t[k-1]));
}

bool iza(int k, string t, string tem)
{
    return (k+tem.size()==t.size()||!moze(t[k+tem.size()]));
}

set<int> PretraziIndeksPojmova(string t, map<string,set<int>> m)
{
    set<int> s;
    for(int i=0; i<t.size(); i++)
        if(sl(t[i])) t[i]=tolower(t[i]);
    for(auto p=m.begin(); p!=m.end(); p++)
    {
        if(p->first!=t) continue;
        else s= p->second;
    }
    if(s.size()==0) throw logic_error("Pojam nije nadjen");
    else return s;
}

void IspisiIndeksPojmova(map<string,set<int>> mapa)
{
    auto it=mapa.begin();
    while(it!=mapa.end())
    {
        cout<<it->first<<": ";
        int s=it->second.size()-1;
        auto it1=it->second.begin();
        while(it1!=it->second.end())
        {
            if(s==0) cout<<*it1;
            else cout<<*it1<<",";
            s--;
            it1++;
        }
        cout<<endl;
        it++;
    }
}

map<string,set<int>> KreirajIndeksPojmova(string t)
{
    for(int i=0; i<t.size(); i++)
        if(sl(t[i])) t[i]=tolower(t[i]);
    map<string,set<int>> mapa;
    int i=0;
    while(i!=t.size())
    {
        if((t[i]>='a'&&t[i]<='z')||(t[i]>='0'&&t[i]<='9'))
        {
            string tem;
            for(int k=i; moze(t[k]); k++) {tem+=t[k]; i=k;}
            set<int> s;
            for(int k=0; k<t.size(); k++)
                if(t.substr(k,tem.size())==tem && ispred(k,t) && iza(k,t,tem))
                    {
                        char o=t[k];
                        int ind=k;
                        s.insert(ind);
                        o='a';
                    }
        
            mapa.insert(make_pair(tem,s));
        }
        i++;
    }
    return mapa;
}

int main ()
{

    cout<<"Unesite tekst: ";
    string r;
    getline(cin,r);
    auto mapa=KreirajIndeksPojmova(r);
    IspisiIndeksPojmova(mapa);
    while(1==1)
    {
        string dv;
        cout<<"Unesite rijec: ";
        cin>>dv;
        if(dv==".") break;
        else
        try
        {
            ///cout<<"aaa "<<dv<<endl;
            auto s=PretraziIndeksPojmova(dv,mapa);
            for(auto it=s.begin(); it!=s.end(); it++) cout<<*it<<" ";
            cout<<endl;
        }
        catch(logic_error izuz) { cout<<"Unesena rijec nije nadjena!"; cout<<endl;}
    }
	return 0;
}
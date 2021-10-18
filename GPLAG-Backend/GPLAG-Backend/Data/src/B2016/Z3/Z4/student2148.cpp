#include<iostream>
#include<vector>
#include<set>
#include<list>
#include<stdexcept>
#include<string>
#include<cstring>
using namespace std;

bool slovo(char a)
{
    return (toupper(a)>='A'&&toupper(a)<='Z' || a>='0'&&a<='9');
}

int slova(string s)
{
    int br=0;
    for(int i=0; i<s.size(); i++)
        if(slovo(s[i])) br++;
    return br;
}

vector<set<string>> Razvrstavanje(vector<string> v, int n)
{
    if(n<1||  n>v.size()) throw logic_error("Razvrstavanje nemoguce");
    list<string> l;
    vector<set<string>> rez;
    for(int i=0; i<v.size(); i++) l.push_back(v[i]);
    int brt1=v.size()%n, brc1=0;
    int brt2=0, brc2=0;
    if(brt1==0)
    {
        //cout<<"ADSASD  ";
        brt1=n; brc1=v.size()/n;
        //cout<<brt1<<" "<<brc1<<endl;
    }
    else
    {
        brt1=v.size()%n; brc1=(v.size()/n)+1;
        brt2=n-brt1; brc2=v.size()/n;
    }
    int brs=slova(*(l.begin()));
    bool nes=true;
    auto it=l.begin();
    while(brt1!=0)
    {
        int a=brc1;
        set<string> skup;
        if(nes){ nes=false; skup.insert(*(l.begin())); auto ite=l.begin(); ite=l.erase(ite); a--; brs--;it=l.begin();}
        while(a>0)
        {
            while(brs!=0) { it++; brs--; if(it==l.end()) { it=l.begin(); }}
            //cout<<*it<<endl;
            skup.insert(*it);
            brs=slova(*it);
            it=l.erase(it);
            if(it==l.end()) {it=l.begin();}
            brs--;
            a--;
        }
        rez.push_back(skup);
        brt1--;
    }
    //for(auto ite=l.begin(); ite!=l.end(); ite++) cout<<*ite<<" ";
    //cout<<endl;
    while(brt2!=0)
    {
        int a=brc2;
        set<string> skup;
        while(a>0)
        {
            while(brs!=0) { it++; brs--; if(it==l.end()){ it=l.begin();  }}
            skup.insert(*it);
            brs=slova(*it);
            it=l.erase(it);
            if(it==l.end()) { it=l.begin();}
            //for(auto ite=l.begin(); ite!=l.end(); ite++) cout<<*ite<<" ";
    //cout<<endl;
            brs--;
            a--;
        }
        rez.push_back(skup);
        brt2--;
    }
    return rez;
}

int main ()
{
    try
    {
        int n;
        cout<<"Unesite broj djece: ";
        cin>>n;
        cout<<"Unesite imena djece: "<<endl;
        vector<string> v; 
        cin.clear();
        cin.ignore(10000, '\n');
        for(int i=0; i<n; i++)
        {
            string s;
             getline(cin,s);
            v.push_back(s);
        }
        cout<<"Unesite broj timova: ";
        int k; cin>>k;
        //for(int i=0; i<v.size(); i++) cout<<"cla "<<v[i]<<endl;
        //cout<<endl<<k<<endl;
        auto rez=Razvrstavanje(v,k);
        for(int i=0; i<rez.size(); i++)
        {
            cout<<"Tim "<<i+1<<": ";
            int br=rez[i].size();
            for(auto x:rez[i])
            {
                cout<<x;
                if(br>1) cout<<", ";
                br--;
            }
            cout<<endl;
        }
        return 0;
    }
    catch(logic_error l) { cout<<"Izuzetak: "<<l.what(); }
}
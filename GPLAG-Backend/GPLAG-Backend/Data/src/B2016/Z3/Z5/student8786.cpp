#include<iostream>
#include<vector>
#include<set>
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

struct Dijete
{
    string ime;
    Dijete *slj;
};

Dijete *transformisi(vector<string> v)
{
    Dijete *p=nullptr;
    Dijete *t=nullptr;
    for(int i=0; i<v.size(); i++)
    {
        Dijete *n= new Dijete;
        n->ime=v[i];
        if(i==0) { p=n; t=n;}
        else { t->slj=n; t=n;}
        if(i==v.size()-1) n->slj=p;
    }
    return p;
}

vector<set<string>> Razvrstavanje(vector<string> v, int n)
{
    if(n<1||  n>v.size()) throw logic_error("Razvrstavanje nemoguce");
    vector<set<string>> rez;
    Dijete* li=transformisi(v);
    Dijete* pr=li;
    Dijete* l=li;
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
    int brs=slova(l->ime);
    bool nes=true;
    while(pr->slj!=l) pr=pr->slj;
    while(brt1!=0)
    {
        int a=brc1;
        set<string> skup;
        if(nes){ nes=false; skup.insert(l->ime); pr->slj=l->slj; l->slj=nullptr; delete l; l=pr->slj; a--; brs--;}
        while(a>0)
        {
            while(brs!=0) { l=l->slj; pr=pr->slj; brs--; }
            //cout<<*it<<endl;
            skup.insert(l->ime);
            brs=slova(l->ime);
            if(brt1==1 && a==1 && brt2==0) { l->slj=nullptr; delete l;}
            else { pr->slj=l->slj; l->slj=nullptr; delete l; l=pr->slj;}
            brs--;
            a--;
        }
        rez.push_back(skup);
        brt1--;
    }
    while(brt2!=0)
    {
        int a=brc2;
        set<string> skup;
        while(a>0)
        {
            while(brs!=0) { l=l->slj; pr=pr->slj; brs--; }
            skup.insert(l->ime);
            brs=slova(l->ime);
            if(brt2==1 && a==1) { l->slj=nullptr; delete l;}
            else { pr->slj=l->slj; l->slj=nullptr; delete l; l=pr->slj;}
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
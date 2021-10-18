/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <iomanip>
#include <stdexcept>
#include <map>
#include <vector>
using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};



list<pair<Boje,string>> KreirajSpil()
{
    list<pair<Boje,string>> spil;
    for(int i=2; i<=14; i++)
    {
        char a=i+48;
        if(a=='>') a='A';
        if(a==';') a='J';
        if(a=='<') a='Q';
        if(a=='=') a='K';
        string pom; pom+=a;
        if(a==':') pom="10";
        spil.push_back(make_pair(Boje::Pik,pom));
    }
    for(int i=2; i<=14; i++)
    {
        char a=i+48;
        if(a=='>') a='A';
        if(a==';') a='J';
        if(a=='<') a='Q';
        if(a=='=') a='K';
        string pom; pom+=a;
        if(a==':') pom="10";
        spil.push_back(make_pair(Boje::Tref,pom));
    }
    for(int i=2; i<=14; i++)
    {
        char a=i+48;
        if(a=='>') a='A';
        if(a==';') a='J';
        if(a=='<') a='Q';
        if(a=='=') a='K';
        string pom; pom+=a;
        if(a==':') pom="10";
        spil.push_back(make_pair(Boje::Herc,pom));
    }
    for(int i=2; i<=14; i++)
    {
        char a=i+48;
        if(a=='>') a='A';
        if(a==';') a='J';
        if(a=='<') a='Q';
        if(a=='=') a='K';
        string pom; pom+=a;
        if(a==':') pom="10";
        spil.push_back(make_pair(Boje::Karo,pom));
    }
    return spil;
}

void IzbaciKarte(list<pair<Boje,string>> &spil, multimap<Boje,string> &m)
{
    for(auto it=m.begin(); it!=m.end(); it++)
    {
        for(auto it1=spil.begin(); it1!=spil.end(); it1++)
        {
            if(it->first==it1->first && it->second==it1->second)
            {
                it1=spil.erase(it1); it=m.erase(it);
            }
        }
    }
}

queue<pair<Boje,string>> IzbaciKarteRazbrajanjem(list<pair<Boje,string>> &spil, const short int r, const int n1)
{
    int br=1, n=n1;
    ///cout<<r<<" "<<n<<endl;
    queue<pair<Boje,string>> rez;
    auto it=spil.begin();
    while(1)
    {
        if(br==r)
        {
            pair<Boje,string> pom=*it;
            rez.push(pom);
            br=1;
            it=spil.erase(it);
            //it++;
            //cout<<it->second<<" "<<spil.size()<<endl;
            n--;
        }
        if(it==spil.end()) it=spil.begin();
        it++;
        br++;
        if(n==0) break;
    }
    return rez;
}

void IspisiSpil(list<pair<Boje,string>> &spil)
{
    auto it=spil.begin();
    int br=0;
    while(it!=spil.end() && it->first==Boje::Pik)
    {
        if(br==0) {cout<<"Pik: "; br=1;}
        cout<<it->second<<" ";
        it++;
    }
    cout<<endl; br=0;
    while(it!=spil.end() && it->first==Boje::Tref)
    {
        if(br==0) {cout<<"Tref: "; br=1;}
        cout<<it->second<<" ";
        it++;
    }
    cout<<endl; br=0;
    while(it!=spil.end() && it->first==Boje::Herc)
    {
        if(br==0) {cout<<"Herc: "; br=1;}
        cout<<it->second<<" ";
        it++;
    }
    cout<<endl; br=0;
    while(it!=spil.end() && it->first==Boje::Karo)
    {
        if(br==0) {cout<<"Karo: "; br=1;}
        cout<<it->second<<" ";
        it++;
    }
}

bool iza(string a, string b)
{
    vector<string> v={"","","","","","","","","","","","",""};
    int i1, i2;
    for(int i=0; i<v.size(); i++) if(v[i]==a) i1=i;
    for(int i=0; i<v.size(); i++) if(v[i]==b) i2=i;
    return i1<i2;
}

void VratiPrvihNKarata(list<pair<Boje,string>> & spil, queue<pair<Boje,string>> &red, int n)
{
    int br=0;
    while(br!=n)
    {
        auto it=spil.begin();
        while((int)red.front().first!=(int)it->first) it++;
        while(iza(it->second, red.front().second)&&(int)it->first==(int)red.front().first) it++;
        spil.insert(it, red.front());
        red.pop();
        br++;
    }
}

int main ()
{
    auto spil=KreirajSpil();
    cout<<"Unesite korak razbrajanja: ";
    short int r;
    int n;
    cin>>r;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    cin>>n;
    //IspisiSpil(spil); cout<<endl;
    auto rez=IzbaciKarteRazbrajanjem(spil,r,n);
    cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<endl;
    IspisiSpil(spil);
    
	return 0;
}

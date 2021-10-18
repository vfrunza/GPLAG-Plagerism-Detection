/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <stdexcept>
#include <iomanip>
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


bool testliste(list<pair<Boje,string>> &spil)
{
     bool a=true;
     vector<string> v={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
     if(spil.size()>52) return false;
     for(auto it=spil.begin(); it!=spil.end(); it++){
          bool znj=false;
          for(int i=0; i<v.size(); i++) if(it->second==v[i]) znj=true;
          if(!znj) return false;
     }
     return a;
}

void IzbaciKarte(list<pair<Boje,string>> &spil, multimap<Boje,string>&m)
{
     if(!testliste(spil)) throw logic_error("Neispravna lista!");
     for(auto it=m.begin(); it!=m.end(); it++)
          for(auto it1=spil.begin(); it1!=spil.end(); it1++)
               if(it->first==it1->first && it->second==it1->second) { it1=spil.erase(it1); it=m.erase(it);}
}

queue<pair<Boje, string>> IzbaciKarteRazbrajanjem(list<pair<Boje,string>> &spil, const short int r, const int n)
{
     if(r<1 || r>52 || n<1) throw logic_error("Neispravni elementi za izbacivanje!");
     if(!testliste(spil)) throw logic_error("Neispravna lista!");
     int br=1, n1=n;
     queue<pair<Boje,string>> rez;
     auto it=spil.begin();
     while(n1!=0)
     {
          if(it==spil.end()) it=spil.begin();
          if(br==r){
               //cout<<"DADADA ";
               pair<Boje,string> pom=*it;
               rez.push(pom); br=1; it=spil.erase(it); n1--;
          }
          it++; br++; 
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
    cout<<endl;
}

bool iza(string s, int ind)
{
     vector<string> v={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
     int ind1;
     for(int i=0; i<v.size(); i++) if(v[i]==s) ind1=i;
     return ind1<ind;
}

void VratiPrvihNKarata(list<pair<Boje,string>> &spil, queue<pair<Boje,string>> &red, int n)
{
     int br=0;
     if(n<0) throw domain_error("Broj n je besmislen!");
     if(n>red.size()) throw range_error("Nedovoljno karata u redu!");
     if(!testliste(spil)) throw logic_error("Neispravna lista!");
     vector<string> v={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
     while(br!=n)
     {
          auto it=spil.begin();
          while(red.front().first!=it->first) it++;
          int ind=0;
          for(int i=0; i<v.size(); i++) if(v[i]==red.front().second) ind=i;
          while(iza(it->second,ind)){
               if(it->first!=red.front().first) break; 
               it++;
          }
          spil.insert(it,red.front());
          red.pop();
          br++;                                                                      
     }
}

int main ()
{ 
     auto spil=KreirajSpil();
    // IspisiSpil(spil);
     int n;
     cout<<"Unesite korak razbrajanja: ";
     cin>>n;
     cout<<"Unesite broj karata koje zelite izbaciti: ";
     int n1;
     cin>>n1;
     try{
          auto red = IzbaciKarteRazbrajanjem(spil,n,n1);
          cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<endl;
          IspisiSpil(spil);
     
          cout<<"Unesite broj karata koje zelite vratiti u spil: ";
          cin>>n;
          VratiPrvihNKarata(spil,red,n);
          cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<endl;
          IspisiSpil(spil); 
     }
     catch(domain_error iz) { cout<<"Izuzetak: "<<iz.what();}
     catch(range_error iz) { cout<<"Izuzetak: "<<iz.what();}
     catch(logic_error iz) { cout<<"Izuzetak: "<<iz.what();}
	return 0;
}

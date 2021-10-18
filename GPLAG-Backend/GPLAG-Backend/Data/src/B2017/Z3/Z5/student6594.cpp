/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <stack>
using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};

struct Karta {
     Boje boja;
     string vr;
};

struct Cvor{
    Karta karta;
    Cvor *sljedeci;
};

Cvor *KreirajSpil()
{
     vector<string> v={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
     Cvor *rez=nullptr, *pom=nullptr;
     Karta k; k.boja=Boje::Pik; k.vr=v[0];
     rez=new Cvor;
     rez->karta=k;
     pom=rez;
     for(int i=1; i<v.size(); i++)
     {
          Karta k1; k1.boja=Boje::Pik; k1.vr=v[i];
          Cvor *n= new Cvor; n->karta=k1;
          pom->sljedeci=n;
          pom=pom->sljedeci;
     }
     for(int i=0; i<v.size(); i++)
     {
          Karta k1; k1.boja=Boje::Tref; k1.vr=v[i];
          Cvor *n= new Cvor; n->karta=k1;
          pom->sljedeci=n;
          pom=pom->sljedeci;
     }
     for(int i=0; i<v.size(); i++)
     {
          Karta k1; k1.boja=Boje::Herc; k1.vr=v[i];
          Cvor *n= new Cvor; n->karta=k1;
          pom->sljedeci=n;
          pom=pom->sljedeci;
     }
     for(int i=0; i<v.size(); i++)
     {
          Karta k1; k1.boja=Boje::Karo; k1.vr=v[i];
          Cvor *n= new Cvor; n->karta=k1;
          pom->sljedeci=n;
          pom=pom->sljedeci;
          if(i==v.size()-1) pom->sljedeci=rez;
     }
     pom=nullptr;
     return rez;
}

void UnistiSpil(Cvor* spil)
{
     Cvor *cv=spil;
     Cvor *pom1=spil->sljedeci;
     while(pom1->sljedeci!=spil){
          delete cv; cv=pom1; pom1=pom1->sljedeci;
     }
     delete cv; delete pom1;
}

void IzbaciKarte(Cvor* &spil, multimap<Boje,string>&m)
{
     Cvor *pom=spil, *cv=spil;
     for(auto it=m.begin(); it!=m.end(); it++)
     {
          pom=spil;
          cv=spil;
          while(cv->sljedeci!=spil)
          {
               if(it->first==cv->karta.boja && it->second==cv->karta.vr) 
               { 
                    it=m.erase(it);
                    Cvor*pom1=spil;
                    while(pom1->sljedeci!=cv) pom1=pom1->sljedeci;
                    pom1->sljedeci=cv->sljedeci;
                    delete cv; cv=nullptr;
                    pom1=nullptr;
                    break;
               }
               cv=cv->sljedeci;
          }
     }
}

stack<pair<Boje, string>> IzbaciKarteRazbrajanjem(Cvor* &spil, const short int r, const int n)
{
     //if(r<1 || r>52 || n<1) throw logic_error("Neispravni elementi za izbacivanje!");
     //if(!testliste(spil)) throw logic_error("Neispravna lista!");
     if(r<1 || r>52 || n<1) throw logic_error("Neispravni elementi za izbacivanje!");
     int br=1, n1=n;
     stack<pair<Boje,string>> rez;
     Cvor *it=spil, *cv=spil;
     while(1)
     {
          if(br==r)
          {
               pair<Boje,string> pom=make_pair(it->karta.boja, it->karta.vr);
               rez.push(pom); br=1; 
               cv=spil; while(cv->sljedeci!=it) cv=cv->sljedeci;
               cv->sljedeci=it->sljedeci;
               it->sljedeci=nullptr;
               delete it;
               it=cv->sljedeci;
               n1--;
          }
          else 
          {
              it=it->sljedeci; 
              br++; 
          }
          if(n1==0) break;
     }
     return rez;
}


bool iza(string s, int ind)
{
     vector<string> v={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
     int ind1;
     for(int i=0; i<v.size(); i++) if(v[i]==s) ind1=i;
     return ind1<ind;
}

int broj(Cvor* spil)
{
     int br=1;
     Cvor *pom=spil, *pom1=spil;
     pom=pom->sljedeci;
     while(pom!=pom1) 
     {
          br++;
          pom=pom->sljedeci;
     }
     return br;
}


void VratiPosljednjihNKarata(Cvor* &spil,stack<pair<Boje,string>> &s,int n)
{
    if(n<0) throw domain_error("Broj n je besmislen!");
    if(n>s.size()) throw range_error("Nedovoljno karata u steku!");
    Cvor* pom=spil;
    vector<string> v={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int br=0;
    while(br!=n)
    {
          Cvor *it=spil;
        while(it->sljedeci!=spil)     
        {
            if(it->karta.boja==s.top().first)
            {
                 int ind1;
                 for(int i=0; i<v.size(); i++) 
                    if(v[i]==s.top().second) ind1=i;
               
                while(iza(it->karta.vr,ind1)){
                     if(it->karta.boja!=s.top().first) break;
                    it=it->sljedeci;
                }
               
                pom=spil;
                while(pom->sljedeci!=it)pom=pom->sljedeci;
                Cvor *k=new Cvor;
                k->karta.boja=s.top().first;
                k->karta.vr=s.top().second;
                s.pop();
                pom->sljedeci=k;
                k->sljedeci=it;
                it=k;
                break;

            }
          it=it->sljedeci;
        }
        br++;
    }
}


void ispisispil(Cvor *spil)
{
     int br=1;
     Cvor *pom=spil, *pom1=spil;
     cout<<pom->karta.vr<<" ";
     pom=pom->sljedeci;
     while(pom!=pom1) 
     {
          br++;
          cout<<pom->karta.vr<<" ";
          pom=pom->sljedeci;
     }
     cout<<endl<<br;
}


void IspisiSpil(Cvor* spil)
{
     int brcl=broj(spil);
    int br=0;cout<<"U spilu trenutno ima "<<brcl<<" karata, i to:"<<endl;
    Cvor* cv=spil;
     vector<string> boje { "Pik", "Tref", "Herc","Karo"  };
    cout<<boje[(int)cv->karta.boja]<<": ";
    cout<<cv->karta.vr<<" ";
    cv=cv->sljedeci;
    for(int i=1;cv!=spil;i++,cv=cv->sljedeci)
    {
        if(br!=(int)cv->karta.boja)
        {
            cout<<endl;
            cout<<boje[(int)cv->karta.boja]<<": ";
            br++;
        }
        cout<<cv->karta.vr<<" ";
    }
    cout<<endl;
}


int main ()
{
   
    Cvor* spil=KreirajSpil();
    try{
    
    int n,br;
    cout<<"Unesite korak razbrajanja: ";
    cin>>n;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    cin>>br;
     stack<pair<Boje,string>> s;
    s=IzbaciKarteRazbrajanjem(spil,n,br);
    IspisiSpil(spil);
    cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    cin>>n;
    VratiPosljednjihNKarata(spil,s,n);
    IspisiSpil(spil);
     } catch(domain_error iz) { cout<<"Izuzetak: "<<iz.what();}
     catch(range_error iz) { cout<<"Izuzetak: "<<iz.what();}
     catch(logic_error iz) {cout<<"Izuzetak: "<<iz.what();}
     UnistiSpil(spil);
    
	return 0;
}

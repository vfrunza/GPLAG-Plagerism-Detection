/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <queue> 
#include <stdexcept>
using namespace std;

enum class Boje{Pik, Tref, Herc, Karo};

const vector<string> Karte={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

void IspisiSpil(list<pair<Boje,string>> karte)
{   
    cout<<"U spilu trenutno ima "<<karte.size()<<" karata, i to:"<<endl;
    const vector<string> boje={"Pik","Tref","Herc","Karo"}; 
    
    if(karte.size()==0)
    {
        for(int i=0;i<4;i++)
        {
            cout<<boje[i]<<": "<<endl;
        }
    }
 //   const vector<string> boje={"Pik","Tref","Herc","Karo"}; 
   else
   {
    pair<Boje,string> par=*karte.begin();
    cout<<boje[(int)par.first]<<": ";
    for(auto a:karte)
    {   
        if((int)par.first!=(int)a.first){cout<<endl; cout<<boje[(int)a.first]<<": ";par=a;}
       
        cout<<a.second<<" ";
        
    }
   }
    cout<<endl;
}

list<pair<Boje,string>> KreirajSpil()
{    
    list<pair<Boje,string>> karte;
    for(int i=0;i<4;i++)
        for(int j=0;j<13;j++)
            karte.push_back(make_pair((Boje)i,Karte[j]));
    return karte;
}   

void IzbaciKarte(list<pair<Boje,string>> &karte,multimap<Boje,string> &mapa)
{   
    
   
    if(karte.size()>52) throw logic_error("Neispravna Lista");
    for(auto a:karte)
    {
         bool ValjaLi=false;
        for(int i=0;i<Karte.size();i++)
            if(Karte[i]==a.second) ValjaLi=true;
        if(ValjaLi==false) throw logic_error("Neispravna Lista");
    }
    
    
    
    
    for(auto m=mapa.begin();m!=mapa.end();m++)
        for(auto k=karte.begin();k!=karte.end();k++)
            if((int)m->first==(int)k->first && m->second==k->second)
            {
                m=mapa.erase(m);
                k=karte.erase(k);
                break;
            }
}


queue<pair<Boje,string>> IzbaciKarteRazbrajanjem(list<pair<Boje,string>> &karte,const short int &r,int &b)
{   
    
    int pom=r;auto it=karte.begin();
    queue<pair<Boje,string>>red;
        
    if(r<1 || r>52 || b<1) throw logic_error("Neispravni elementi za izbacivanje!");
    if(karte.size()>52) throw logic_error("Neispravna Lista");
    for(auto a:karte)
    {
        bool ValjaLi=false;
        for(int i=0;i<Karte.size();i++)
            if(Karte[i]==a.second) ValjaLi=true;
        if(ValjaLi==false) throw logic_error("Neispravna Lista");
    }
    
    
    
    while(b!=0)
    {
        pom=r;   
        while(pom!=1)
        {
            it++;
            if(it==karte.end()) it=karte.begin();
            pom--;
        }
        
        red.push(*it);
        it=karte.erase(it);
        
        
        b--;
    }
    return red;
}

void VratiPrvihNkarata(list<pair<Boje,string>> &karte,queue<pair<Boje,string>> &red,int n)
{
    
    if(n<0) throw domain_error("Broj n je besmislen!");
    else if(n>red.size()) throw range_error("Nedovoljno karata u redu!");
    
    if(karte.size()>52) throw logic_error("Neispravna Lista");
    for(auto a:karte)
    {
        bool ValjaLi=false;
        for(int i=0;i<Karte.size();i++)
            if(Karte[i]==a.second) ValjaLi=true;
        if(ValjaLi==false) throw logic_error("Neispravna Lista");
    }
   
    if(karte.size()==0)
    {
        karte.push_back(make_pair(red.front().first,red.front().second));
        red.pop();
        n--;
    }
    if(karte.size()==1 && red.size()!=0)
    {    
        auto it=karte.begin();
       
        if((int)red.front().first<(int)it->first)
          karte.push_front(make_pair(red.front().first,red.front().second));
        else
          karte.push_back(make_pair(red.front().first,red.front().second));
        
         red.pop();
         n--;
    }
    
    while(n!=0 && red.size()!=0)
    {   
       // int p=0;int q=0;
        for(auto i=karte.begin();i!=karte.end();i++)
        {   
           // i--;
        // cout<<red.size();
            
           if ((int)i->first>(int)red.front().first) {karte.push_front(make_pair(red.front().first,red.front().second)); red.pop();break;}
           else 
             while((int)i->first<(int)red.front().first)
                i++;
             
             //if(i==karte.end()) karte.insert(i,red.front());
             
             while([](string a,string b){  
                                    int p,q;
                                    for(p=0;p<Karte.size();p++)
                                        if(a==Karte[p]) break;            
                                    for(q=0;q<Karte.size();q++)
                                        if(b==Karte[q]) break;            
                 
                                    if(p<q) return true;
                                    return false;
                                  }(i->second,red.front().second) && (int)red.front().first==(int)i->first)i++;
            
             
             karte.insert(i,red.front());
             red.pop();
             break;
        }
        n--;
    }
}

int main ()
{   
    int n;
    list<pair<Boje,string>> spil=KreirajSpil();
    int a,b;
    queue<pair<Boje,string>> red;
    
    try
    {
        cout<<"Unesite korak razbrajanja: ";
        cin>>n;
        cout<<"Unesite broj karata koje zelite izbaciti: ";
        cin>>a;
        red=IzbaciKarteRazbrajanjem(spil,n,a);
        IspisiSpil(spil);
        cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        cin>>b;
        VratiPrvihNkarata(spil,red,b);
        IspisiSpil(spil);
    }
    catch(domain_error e)
    {
        cout<<"Izuzetak: "<<e.what();
    }
    catch(range_error e)
    {
         cout<<"Izuzetak: "<<e.what();   
    }
    catch(logic_error e)
    {
         cout<<"Izuzetak: "<<e.what();
    }
    return 0;
}

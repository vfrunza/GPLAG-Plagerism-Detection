/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <memory>

using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};

const vector<string> Karte{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
const vector<string> Znakovi{"Pik","Tref","Herc","Karo"};
const vector<int> Vrijednosti{2,3,4,5,6,7,8,9,10,12,13,14,15};

typedef multimap<Boje,string> Mapa;
typedef pair<Boje,string> Par;
typedef stack<Par> Stek;

struct Karta
{
    Boje boja;
    string vrijednost;
};

struct Cvor
{
    Karta karta;
    shared_ptr<Cvor> sljedeci;
};

void IspisiStek(Stek s)
{   
    while(s.size())
    {
        cout<<Znakovi[(int)s.top().first]<<"->"<<s.top().second<<" ";
        s.pop();
    }
            
}

shared_ptr<Cvor> KreirajSpil()
{
    shared_ptr<Cvor> p;
    shared_ptr<Cvor> temp;
    int br=0;
    
    for(int i=0;i<52;i++)
    {
        Karta k;
        if(i%13==0 && i!=0) br++;
        k.boja=(Boje)br;
        k.vrijednost=Karte[i%13];
        
        
        shared_ptr<Cvor> novi=make_shared<Cvor>();
        novi->karta=k;
        
        if(i==0)
            p=novi;
        else 
            temp->sljedeci=novi;
        
        temp=novi;
        novi->sljedeci=p;
        
       
    }
    
    return p;
}

int VratiBroj(shared_ptr<Cvor> dek)
{
    shared_ptr<Cvor> temp=dek;
    int i;
    for(i=1;temp->sljedeci!=dek;temp=temp->sljedeci,i++);
    return i;
}

void IspisiSpil(shared_ptr<Cvor> dek)
{
    int br=0;cout<<"U spilu trenutno ima "<<VratiBroj(dek)<<" karata, i to:"<<endl;
    shared_ptr<Cvor> temp=dek;
    
    cout<<Znakovi[(int)temp->karta.boja]<<": ";
    cout<<temp->karta.vrijednost<<" ";
    temp=temp->sljedeci;
    
    for(int i=1;temp!=dek;i++,temp=temp->sljedeci)
    {  
        if(br!=(int)temp->karta.boja)
        {   
            cout<<endl;
            cout<<Znakovi[(int)temp->karta.boja]<<": ";
            br++;
        }
        cout<<temp->karta.vrijednost<<" ";
    }
    cout<<endl;
}

void IzbaciKarte(shared_ptr<Cvor> &dek,Mapa &m)
{
    shared_ptr<Cvor> temp=dek;
    shared_ptr<Cvor> pret=dek;
      
    while(temp->sljedeci!=dek)
    {
        for(auto a=m.begin();a!=m.end();a++)
        {
            if((int)temp->karta.boja==(int)a->first 
                    && temp->karta.vrijednost==a->second)
            {
                shared_ptr<Cvor> pom=temp;
                
                while(pret->sljedeci!=pom)
                    pret=pret->sljedeci;
                
                
                if(pom==dek)
                {
                    pret->sljedeci=dek->sljedeci;
                    dek=dek->sljedeci;
                }
                else 
                    pret->sljedeci=pom->sljedeci;
                
                pom=nullptr;
                //delete pom;
                pom=pret->sljedeci;
                a=m.erase(a);
                if(a==m.end()) break;
            }
           
        }
        temp=temp->sljedeci;    
    }
    
}
Stek IzbaciKarteRazbrajanjem(shared_ptr<Cvor> &dek,short int r,int b)
{
     if(r<1 || r>52 || b<1) throw logic_error("Neispravni elementi za izbacivanje!");
    auto it=dek;auto pret=dek;
    Stek s;
    for(int i=0;i<b;i++)
    {
        for(int j=0;j!=r-1;it=it->sljedeci,j++);
            
            s.push(make_pair(it->karta.boja,it->karta.vrijednost));
                
            while(pret->sljedeci!=it)
                pret=pret->sljedeci;
                
                pret->sljedeci=it->sljedeci;
                
                
                it=nullptr;
                it=pret->sljedeci;
        
    }
    return s;
}

bool ManjiString(string a,string b)
{   
    int i,j;
    for(i=0;i<Karte.size();i++)
        if(a==Karte[i]) break;
    for(j=0;j<Karte.size();j++)
        if(b==Karte[j]) break;
        
        return i<j;
}

void VratiPosljednjihNKarata(shared_ptr<Cvor> &dek,Stek &s,int n)
{   
    if(n<0) throw domain_error("Broj n je besmislen!");
    if(n>s.size()) throw range_error("Nedovoljno karata u redu!");
    if(VratiBroj(dek)>52) throw logic_error("Neispravna lista!");
    shared_ptr<Cvor> pret=dek;
    for(int i=n;i!=0;i--)
    {   
         
        for(shared_ptr<Cvor> it=dek;it->sljedeci!=dek;it=it->sljedeci)
        {
            if((int)it->karta.boja==(int)s.top().first)
            {
                while(ManjiString(it->karta.vrijednost,s.top().second)&& (int)it->karta.boja==(int)s.top().first)
                    it=it->sljedeci;
                  
                pret=dek;  
                while(pret->sljedeci!=it)
                    pret=pret->sljedeci;
                
                shared_ptr<Cvor> novi=make_shared<Cvor>();
                novi->karta.boja=s.top().first;
                novi->karta.vrijednost=s.top().second;
                
                pret->sljedeci=novi;
                novi->sljedeci=it;
                it=novi;
                s.pop();
                break;
               
            }
          
        }
    }
}

int main ()
{
    shared_ptr<Cvor> dek=KreirajSpil();
    
    try{
    
    
    cout<<"Unesite korak razbrajanja: ";
    int n;cin>>n;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    int a;cin>>a;
     Stek s;
    s=IzbaciKarteRazbrajanjem(dek,n,a);
    IspisiSpil(dek);
    cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    cin>>n;
   
   VratiPosljednjihNKarata(dek,s,n);
   IspisiSpil(dek);
    
    dek->sljedeci=nullptr;
    dek=nullptr;
    }
    catch(domain_error er) { cout<<"Izuzetak: "<<er.what();dek->sljedeci=nullptr;
    dek=nullptr;}
     catch(range_error er) { cout<<"Izuzetak: "<<er.what();dek->sljedeci=nullptr;
    dek=nullptr;}
     catch(logic_error er) {cout<<"Izuzetak: "<<er.what();dek->sljedeci=nullptr;
    dek=nullptr;}
  // UnistiSpil(dek);
  /*  Mapa m;
    m.insert(make_pair((Boje)2,"5"));
    m.insert(make_pair((Boje)3,"9"));
    m.insert(make_pair((Boje)0,"2"));
    
    //IzbaciKarte(dek,m);
    //IspisiSpil(dek);
    cout<<endl;
    Stek s=IzbaciKarteRazbrajanjem(dek,12,6);
    IspisiStek(s);
    cout<<endl;
    IspisiSpil(dek);
    cout<<endl;
    VratiPosljednjihNKarata(dek,s,4);
    IspisiSpil(dek);*/
    return 0;
}

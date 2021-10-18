/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>

using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};

struct Karta
{
    Boje boja;
    string vrijednost;
};

struct Cvor
{
    Karta karta;
    Cvor* sljedeci;
};



Cvor* KreirajSpil()
{
    Cvor *poc=nullptr;    
    Cvor *tren=nullptr;
    
    for(int i=0;i<4;i++)
    {
        for(int j=2;j<16;j++)
        {
            if(j==11) continue;
            
            Karta k;
            k.boja=(Boje)i;
            
            string c;
            
           switch(j)
           {
               case 10:
                c.push_back('1');
                c.push_back('0');
                break;
               
               case 12:
                c.push_back('J');
                break;
                
               case 13:
                c.push_back('Q');
                break;
                
                case 14:
                 c.push_back('K');
                 break;
                
                case 15:
                  c.push_back('A');
                  break;
                  
                default:
                  c.push_back(j+'0');
           }
            
            k.vrijednost=c;
            
            Cvor *novi=new Cvor;
            novi->karta=k;
            
            if(i==0 && j==2)
            {
                poc=novi;
                tren=novi;
            }
            else 
            {
                tren->sljedeci=novi;
                tren=novi;
            }    
            
            
                novi->sljedeci=poc;
                //delete novi;
        }
        
        
    }
    
    return poc;
}
int VratiVelicinu(Cvor *spil)
{
    int br=0;
    Cvor *temp=spil;
    while(temp->sljedeci!=spil)
    {
        br++;
        temp=temp->sljedeci;
    }
    return br+1;
    
}
void IspisiSpil(Cvor *spil)
{

    cout<<"U spilu trenutno ima "<<VratiVelicinu(spil)<<" karata, i to:"<<endl;
    vector<string> v={"Pik","Tref","Herc","Karo"};
    
    
    auto it=spil;
    
    
    int br=(int)it->karta.boja;
    
    for(;it->sljedeci!=spil;)
    {   
        cout<<v[br]<<": ";
        while(br==(int)it->karta.boja)
        {
            cout<<it->karta.vrijednost<<" ";
            it=it->sljedeci;
            if(it==spil)break;
        }
        cout<<endl;
        br=(int)it->karta.boja;   
        if(it==spil) break;
    }
    
    cout<<endl;
}

void IspisiStack(stack<pair<Boje,string>> s)
{
    while(s.size()!=0)
    {
        cout<<(int)s.top().first<<" "<<s.top().second<<" ";
        s.pop();
    }
}

bool JesuIsti(Karta k,pair<Boje,string> p)
{
    return k.vrijednost==p.second && k.boja==p.first;
}

void IzbaciKarte(Cvor *Spil,multimap<Boje,string> m)
{
    for(auto i=Spil;i->sljedeci!=Spil;i=i->sljedeci)
    {
        for(auto j=m.begin();j!=m.end();j++)
        {
            if(JesuIsti(i->karta,*j))
            {
                //IzbrisiCvor
                Cvor *tren=i;
                Cvor *pret=Spil;
                while(pret->sljedeci!=tren)
                    pret=pret->sljedeci;
                    
              pret->sljedeci=tren->sljedeci;
              tren=nullptr;
              delete tren;
              tren=pret->sljedeci;
                
                
                j=m.erase(j);
                if(j==m.end())break;
            }
        }
    }
}


stack<pair<Boje,string>>  IzbaciKarteRazbrajanjem(Cvor *spil,const short int &r,const int b)
{
    stack<pair<Boje,string>> s;
    int i=0;auto it=spil;
    for(;i<b;i++)
    {
        int br=0;
        while(br!=r-1)
        {
            it=it->sljedeci;
            br++;
        }
        
        s.push(make_pair(it->karta.boja,it->karta.vrijednost));
        
                Cvor *tren=it;
                Cvor *pret=spil;
                while(pret->sljedeci!=tren)
                    pret=pret->sljedeci;
                    
              pret->sljedeci=tren->sljedeci;
              //tren=nullptr;
              delete tren;
              tren=pret->sljedeci;
              it=tren;
    }
    
    return s;
}

bool JelManji(string a,string b)
{
    vector<string> v={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int index,index1;
    
    for(int i=0;i<v.size();i++)
        if(v[i]==a) index=i;
    
    for(int i=0;i<v.size();i++)
        if(v[i]==b) index1=i;
   
    return index<index1;
}
void VratiPosljednjihNKarata(Cvor *spil,stack<pair<Boje,string>> &s,int n)
{
    
    int br=0;
     if(n>s.size())throw range_error("Nedovoljno karata u steku!");
    while(br!=n)
    {
        auto it=spil;
        
        while((int)s.top().first!=(int)it->karta.boja)
            it=it->sljedeci;
            
        while(JelManji(it->karta.vrijednost,s.top().second) && (int)s.top().first==(int)it->karta.boja)
            it=it->sljedeci;
            
            Karta k;
            
            k.boja=s.top().first;
            k.vrijednost=s.top().second;
        //Umetni cvor
              Cvor *novi=new Cvor;
              novi->karta=k;
            
            
                
                Cvor *pret=spil;
                while(pret->sljedeci!=it)
                    pret=pret->sljedeci;
        
                pret->sljedeci=novi;
                novi->sljedeci=it;
                
                
                
        s.pop();
        br++;
        
    }
    
}

void UnistiSpil(Cvor *spil)
{
    Cvor *poc=spil;
    Cvor *pom=spil->sljedeci;
    while(pom->sljedeci!=spil)
    {
        delete poc;
        poc=pom;
        pom=pom->sljedeci;
    }
    delete poc;
    delete pom;
}

int main ()
{
   /* Cvor *spil=KreirajSpil();
    IspisiListu(spil);
    
      multimap<Boje,string> m;
    
    string c;
    c.push_back('A');
    m.insert(make_pair((Boje)2,c));
    m.insert(make_pair((Boje)0,c));
    m.insert(make_pair((Boje)1,c));
    m.insert(make_pair((Boje)3,c));
    IzbaciKarte(spil,m);
    
    cout<<endl;
    IspisiListu(spil); 
    
    spil=KreirajSpil();//const short int n=6;
    stack<pair<Boje,string>> s=IzbaciKarteRazbrajanjem(spil,2,23);
    IspisiStack(s);
    cout<<endl;*/
    
    int n,n1,n2;
    
    Cvor *spil;
    spil=KreirajSpil();
   // IspisiSpil(spil);
    cout<<"Unesite korak razbrajanja: ";
    cin>>n;
    
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    cin>>n1;
    
    if(n<0 || n1<0) {
        cout<<"Izuzetak: Neispravni elementi za izbacivanje!";
        return 0; 
    }
    
   stack<pair<Boje,string>> q=IzbaciKarteRazbrajanjem(spil,n,n1);
   //IspisiStack(q);
   IspisiSpil(spil);
    
    
    try {
    
    cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    cin>>n2;
    
    if(n2<0 || !cin) throw domain_error("Broj n je besmislen!");
    
   VratiPosljednjihNKarata(spil,q,n2);
    IspisiSpil(spil);
    }
    catch(domain_error &e) {cout<<"Izuzetak: "<<e.what();}
    catch(range_error e) {cout<<"Izuzetak: "<<e.what(); }
    
    UnistiSpil(spil);
	return 0;
}

/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <stdexcept>


using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};

typedef list<pair<Boje,string>> Lista;
typedef pair<Boje,string> par;
typedef multimap<Boje,string> Mapa;
typedef queue<Boje,string> Que;
typedef pair<string,string> Red;

bool Provjera(Lista l1,par p1){
    
    for(par x:l1){
        if(x==p1)return true;
    }
    return false;
}

bool Provjera(queue<Red> r1,par p1,int n){
    
   for(int i=0;i<n;i++){
       
       Boje b1;
       Red temp=r1.front();
       r1.pop();
       if(temp.first=="Pik")b1=Boje::Pik;
       else if(temp.first=="Tref")b1=Boje::Tref;
        else if(temp.first=="Herc")b1=Boje::Herc;
         else if(temp.first=="Karo")b1=Boje::Karo;
         
         par test(b1,temp.second);
         
         if(test==p1)return true;
       
   }
    return false;
}

Lista KreirajSpil(){
    
    Lista l1;
    
    string s[13]{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    
    for(int i=0;i<13;i++){
        Boje temp=Boje::Pik;
        par p1(temp,s[i]);
        l1.push_back(p1);
    }

     for(int i=0;i<13;i++){
        Boje temp=Boje::Tref;
        par p1(temp,s[i]);
        l1.push_back(p1);
    }
     for(int i=0;i<13;i++){
        Boje temp=Boje::Herc;
        par p1(temp,s[i]);
        l1.push_back(p1);
    }
     for(int i=0;i<13;i++){
        Boje temp=Boje::Karo;
        par p1(temp,s[i]);
        l1.push_back(p1);
    }
    
    return l1;
}

Lista KreirajSpilBolji(Lista l,queue<Red> r1,int n){
    
    int brojac=0;
    Lista l1;
    
    string s[13]{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    
    for(int i=0;i<13;i++){
        Boje temp=Boje::Pik;
        par p1(temp,s[i]);
        if(Provjera(l,p1) || Provjera(r1,p1,n))
        l1.push_back(p1);
    }

     for(int i=0;i<13;i++){
        Boje temp=Boje::Tref;
        par p1(temp,s[i]);
        if(Provjera(l,p1) || Provjera(r1,p1,n))
        l1.push_back(p1);
    }
     for(int i=0;i<13;i++){
        Boje temp=Boje::Herc;
        par p1(temp,s[i]);
        if(Provjera(l,p1) || Provjera(r1,p1,n))
        l1.push_back(p1);
    }
     for(int i=0;i<13;i++){
        Boje temp=Boje::Karo;
        par p1(temp,s[i]);
        if(Provjera(l,p1) || Provjera(r1,p1,n))
        l1.push_back(p1);
        
    }
    
    return l1;
}

void Remove(Mapa &m1,par p1){
    
    for(auto it=m1.begin();it!=m1.end();it++){
        
        if(it->first==p1.first && it->second==p1.second) m1.erase(it);
    }
    
}

void IzbaciKarte(Lista &l1,Mapa &m1){
    
    for(par x: m1){
        if(Provjera(l1,x)==true){
        l1.remove(x);
        Remove(m1,x);
        }
    }
    
}

queue<Red> IzbaciKarteRazbrajanjem(Lista &l1, const short int a,int b){
    
    queue<Red>q1;
    Lista l2=l1;
    
    if (a<1||a>52 || b<1)throw logic_error("Neispravni elementi za izbacivanje!");
    int bra=1,brb=0;
    
    string boja;
    
    while(brb!=b){
        l1=l2;
        for(par x:l1){
        if (brb==b) break;
        if(bra==a){
            Red zared;
            zared.second=x.second;
            if(x.first==Boje::Pik)zared.first="Pik";
            else if(x.first==Boje::Tref)zared.first="Tref";
            else if(x.first==Boje::Herc)zared.first="Herc";
            else if(x.first==Boje::Karo)zared.first="Karo";
            
            q1.push(zared);
            l2.remove(x);
            bra=0;
            brb++;
        }
        bra++;
        }
    }
    
    l1=l2;
    return q1;
}

void VratiPrvihNKarata(Lista &l1,queue<Red> &r1,int n){
    
    if(n<0) throw domain_error("Broj n je besmislen!");
    if(n>r1.size()) throw range_error("Nedovoljno karata u redu!");
    
    l1=KreirajSpilBolji(l1,r1,n);
}

void Ispis(const Lista &list1){
    
    cout<<"Pik: ";
    for(par x:list1){
       if(x.first==Boje::Pik)
       cout<<x.second<<" ";
   }cout<<endl<<"Tref: ";
   for(par x:list1){
       if(x.first==Boje::Tref)
       cout<<x.second<<" ";
   }cout<<endl<<"Herc: ";
   for(par x:list1){
       if(x.first==Boje::Herc)
       cout<<x.second<<" ";
   }cout<<endl<<"Karo: ";
   for(par x:list1){
       if(x.first==Boje::Karo)
       cout<<x.second<<" ";
   }cout<<endl;
    
}
 
int main ()
{
   try{
       
   cout<<"Unesite korak razbrajanja: ";
   int korakrazb;
   cin>>korakrazb;
   
   cout<<"Unesite broj karata koje zelite izbaciti: ";
   int izbacit;
   cin>>izbacit;
   
   Lista list1;
   list1=KreirajSpil();
   
   queue<Red> r1;
   r1=IzbaciKarteRazbrajanjem(list1,korakrazb,izbacit);
   
   
   cout<<"U spilu trenutno ima "<<list1.size()<<" karata, i to: "<<endl;
   
   Ispis(list1);
   
   
   cout<<"Unesite broj karata koje zelite vratiti u spil: ";
   int vrati;
   cin>>vrati;
   
   
    VratiPrvihNKarata(list1,r1,vrati);
   cout<<"U spilu trenutno ima "<<list1.size()<<" karata, i to: "<<endl;
   Ispis(list1);
   
   
   }catch(exception &ex){
       cout<<"Izuzetak: "<<ex.what();
   }
   
   
	return 0;
}

/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <memory>
#include <stdexcept>

using namespace std;

enum class Boje{Pik, Tref, Herc, Karo};

const vector<string> Karte={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

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

Karta StvoriKartu(int i ,int j)
{
    Karta k;
    k.boja=Boje(i);
    k.vrijednost=Karte[j];
    return k;
}
void IspisiSpil(shared_ptr<Cvor> karte)
{
  int br=0;//Prebroj cvorove
    
    
    auto temp=karte;
    if(temp->sljedeci!=nullptr)
    {
        while(temp->sljedeci!=karte){
            br++;
            temp=temp->sljedeci;
        }
      br++;
    }   
    cout<<"U spilu trenutno ima "<<br<<" karata, i to:"<<endl;
    const vector<string> boje={"Pik","Tref","Herc","Karo"}; 
    if(br==0)
    {
        for(int i=0;i<4;i++)
        {
            cout<<boje[i]<<": "<<endl;
        }
    }
   else{ auto it=karte;
    cout<<boje[(int) it->karta.boja]<<": "<<it->karta.vrijednost<<" ";
    for(auto a=karte->sljedeci;a!=karte;a=a->sljedeci)
    {
        if((int)it->karta.boja!=(int)a->karta.boja){cout<<endl; cout<<boje[(int)a->karta.boja]<<": ";it=a;}
       
        cout<<a->karta.vrijednost<<" ";
    }        
    
   }
   cout<<endl;

}

shared_ptr<Cvor> KreirajSpil()
{
    shared_ptr<Cvor> poc=nullptr;
    shared_ptr<Cvor> tren=nullptr;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            Karta k=StvoriKartu(i,j);
            shared_ptr<Cvor> novi=make_shared<Cvor>();
            novi->karta=k;
            
            if(i==0 && j==0)
                poc=novi;
            else 
                tren->sljedeci=novi;
                
            tren=novi;
            novi->sljedeci=poc;
        }
    }
    return poc;
}

void IzbaciKarte(shared_ptr<Cvor> &karte,multimap<Boje,string> &mapa)
{
    
    
     int br=0;//Prebroj cvorove
    
    auto temp=karte;
    
    while(temp->sljedeci!=karte){
        br++;
        temp=temp->sljedeci;
    }
    br++;
    if(br>52) throw logic_error("Neispravna lista");
    temp=karte;
    while(temp->sljedeci!=karte)
    {
        bool ValjaLi=false;
        for(int i=0;i<Karte.size();i++)
            if(Karte[i]==temp->karta.vrijednost) ValjaLi=true;
            temp=temp->sljedeci;
        if(ValjaLi==false) throw logic_error("Neispravna lista");
    }
    
    for(auto m=mapa.begin();m!=mapa.end();m++)
    {
        for(auto k=karte;k->sljedeci!=karte;k=k->sljedeci)
            if(m->first==k->karta.boja && m->second==k->karta.vrijednost)
            {
                m=mapa.erase(m);
                shared_ptr<Cvor> prethodni=karte;
                while(prethodni->sljedeci!=k)
                    prethodni=prethodni->sljedeci;
                
                if(k==karte)
                {
                    prethodni->sljedeci=karte->sljedeci;
                    karte=karte->sljedeci;
                }
                else prethodni->sljedeci=k->sljedeci;
                
                k->sljedeci=nullptr;
                 k=nullptr;
                k=prethodni->sljedeci;
                break;
            }
            if(m==mapa.end()) break;
    }
}

stack<pair<Boje,string>> IzbaciKarteRazbrajanjem(shared_ptr<Cvor> &karte,const short int &r,int b)
{   
    int pom=r;
    auto it=karte;
    stack<pair<Boje,string>> stek;
     if(r<1 || r>52 || b<1) throw logic_error("Neispravni elementi za izbacivanje!");
   
      int br=0;//Prebroj cvorove
    
    auto temp=karte;
    
    while(temp->sljedeci!=karte){
        br++;
        temp=temp->sljedeci;
    }
    br++;
    if(br>52) throw logic_error("Neispravna lista");
    temp=karte;
    while(temp->sljedeci!=karte)
    {
        bool ValjaLi=false;
        for(int i=0;i<Karte.size();i++)
            if(Karte[i]==temp->karta.vrijednost) ValjaLi=true;
        temp=temp->sljedeci;
        if(ValjaLi==false) throw logic_error("Neispravna lista");
    }
    
    while(b!=0)
    {   
        pom=r;
        while(pom!=1)
        {
            it=it->sljedeci;
            pom--;
        }
        stek.push(make_pair(it->karta.boja,it->karta.vrijednost));
       
        
                shared_ptr<Cvor> prethodni=karte;
                while(prethodni->sljedeci!=it)
                    prethodni=prethodni->sljedeci;
                
                if(it==karte)
                {
                    prethodni->sljedeci=karte->sljedeci;
                    karte=karte->sljedeci;
                }
                else prethodni->sljedeci=it->sljedeci;
                
                it->sljedeci=nullptr;
                 it=nullptr;
                it=prethodni->sljedeci;
        
        b--;
    }
    return stek;
}

void VratiPosljednjihNKarata(shared_ptr<Cvor> karte,stack<pair<Boje,string>> stek,int n)
{   
    if(n<0) throw domain_error("Broj n je besmislen!");
    else if(n>stek.size()) throw range_error("Nedovoljno karata u steku!");
    
     int br=0;//Prebroj cvorove
    
    auto temp=karte;
    if(temp->sljedeci!=nullptr){
    while(temp->sljedeci!=karte){
        br++;
        temp=temp->sljedeci;
    }
    br++;
    }
    if(br>52) throw logic_error("Neispravna lista");
    temp=karte;
    if(br!=0)
        while(temp->sljedeci!=karte)
        {
            bool ValjaLi=false;
            for(int i=0;i<Karte.size();i++)
                if(Karte[i]==temp->karta.vrijednost) ValjaLi=true;
            temp=temp->sljedeci;
            if(ValjaLi==false) throw logic_error("Neispravna lista");
        }
    
    if(br==0)
    {
            shared_ptr<Cvor> novi=make_shared<Cvor>();
            novi->karta.boja=stek.top().first;
            novi->karta.vrijednost=stek.top().second;
            
            karte=novi;
            
            stek.pop();
            n--;
            br++;
            
    }
    if(br==1 && stek.size()!=0)
    {   
            shared_ptr<Cvor> novi=make_shared<Cvor>();
            novi->karta.boja=stek.top().first;
            novi->karta.vrijednost=stek.top().second;
            
            auto it=karte;
            if((int)it->karta.boja<(int)stek.top().first)
            {
                novi->sljedeci=karte;
                karte->sljedeci=novi;
                karte=novi;
            }
            else 
            {
                karte->sljedeci=novi;
                novi->sljedeci=karte;
            }
            
            stek.pop();
            n--;
    }
    while(n!=0 && stek.size()!=0)
    {
        for(auto it=karte;it->sljedeci!=karte;it=it->sljedeci)
        {
            while((int)it->karta.boja<(int)stek.top().first)
                it=it->sljedeci;
                
                 while([](string a,string b){  
                                    int p,q;
                                    for(p=0;p<Karte.size();p++)
                                        if(a==Karte[p]) break;            
                                    for(q=0;q<Karte.size();q++)
                                        if(b==Karte[q]) break;            
                 
                                    if(p<q) return true;
                                    return false;
                                  }(it->karta.vrijednost,stek.top().second) && (int)stek.top().first==(int)it->karta.boja)
                                        it=it->sljedeci;
             
            shared_ptr<Cvor> novi=make_shared<Cvor>();
            novi->karta.boja=stek.top().first;
            novi->karta.vrijednost=stek.top().second;
            
            shared_ptr<Cvor> prethodni=karte;
            while(prethodni->sljedeci!=it)
                prethodni=prethodni->sljedeci;
            
             prethodni->sljedeci=novi;
             novi->sljedeci=it;
             it=novi;
            
             stek.pop();
            break;
            
        }
        
        
        
        
        n--;
    }
}

void UnistiSpil(shared_ptr<Cvor> karte)
{
    karte->sljedeci=nullptr;
    karte=nullptr;
}

int main ()
{
    int n;
    shared_ptr<Cvor> spil=KreirajSpil();
    int a,b;
    stack<pair<Boje,string>> stek;
    try
    {
        cout<<"Unesite korak razbrajanja: ";
        cin>>n;
        cout<<"Unesite broj karata koje zelite izbaciti: ";
        cin>>a;
        stek=IzbaciKarteRazbrajanjem(spil,n,a);
        IspisiSpil(spil);
        cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        cin>>b;
        VratiPosljednjihNKarata(spil,stek,b);
        IspisiSpil(spil);
        UnistiSpil(spil);
    }
    catch(domain_error e)
    {
        cout<<"Izuzetak: "<<e.what();
        UnistiSpil(spil);
    }
    catch(range_error e)
    {
         cout<<"Izuzetak: "<<e.what(); 
         UnistiSpil(spil);
    }
    catch(logic_error e)
    {
         cout<<"Izuzetak: "<<e.what();
         UnistiSpil(spil);
    }
	return 0;
}

/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<stack>

using namespace std;

enum class Boje {Pik,Tref,Herc,Karo};


 typedef multimap<Boje,string> Mapa;

 
 struct Karta
 {
     Boje boja;
     string vrijednost;
 };
 
 struct Cvor
 {
     Karta karta;
     Cvor*sljedeci;
 };
 
 Karta stvorikartu(Boje b, string s)
 {
   Karta k;
   k.boja=b; k.vrijednost=s;
   return k;
 }
 
 Cvor* KreirajSpil()
 {
  vector<string> v={"2","3","4","5","6","7","8","9","10","11","12","13","14"};
     Cvor*spil=nullptr;
     Cvor *temp=nullptr;
     int br=0;
     Karta k1=stvorikartu((Boje)br,v[0]);
     for(int i=0;i<52;i++)
     {
         if(i!=0)
          if(i%13==0)br++;
         Karta k=stvorikartu((Boje)br,v[i%13]);
         Cvor* pom=new Cvor;
         pom->karta=k;
         Karta k3=stvorikartu((Boje)br,v[3]);
         if(i!=0)temp->sljedeci=pom;
         else spil=pom;
         temp=pom;
         pom->sljedeci=spil;
     }
     return spil;
 }
 
 int sajz(Cvor* pok)
 {
     Cvor* temp=pok;
     Cvor *t1=pok;
     int br=1;
     while(t1->sljedeci!=temp){ t1=t1->sljedeci; br++;}
     return br;
 }
 
 void druga(Cvor *pok, Cvor* temp){
  int br=0;
   vector<string> v={"Pik", "Tref","Herc","Karo"};
   for(int i=1;temp!=pok;temp=temp->sljedeci)
    {
       if(br!=(int)temp->karta.boja)
       {
           cout<<endl;
           cout<<v[(int)temp->karta.boja]<<":";
           br++;
   
       } i++;
       cout<<temp->karta.vrijednost<<" ";
    }
 }
 
 void UnistiSpil(Cvor* spil)
 {
  Cvor* pom=spil;
  Cvor* pom1=pom->sljedeci;
  while(pom1->sljedeci!=spil){
   delete pom; 
   pom=pom1;
   pom1=pom1->sljedeci;
  }
  delete pom;
  delete pom1;
 }
 
 void IspisiSpil(Cvor* pok)
 {
     int br=0;
     cout<<"U spilu ima"<<sajz(pok)<<"karata,i to:";
     cout<<endl;
    Cvor* temp=pok;
    vector<string> v={"Pik", "Tref","Herc","Karo"};
    int a=(int)temp->karta.boja;
    cout<<v[a]<<":";
    cout<<temp->karta.vrijednost<<" ";
    temp=temp->sljedeci;
    druga(pok,temp);
    
 cout<<endl;
 }
 
void azuriraj(Cvor *it, Cvor *iza)
{
 while(iza->sljedeci!=it)
         iza=iza->sljedeci;
         iza->sljedeci=it->sljedeci;
         
         delete it;
         it=iza->sljedeci;
}
 
 stack<pair<Boje,string>> IzbaciKarteRazbrajanjem(Cvor* &pok,short int r,int b)
 {
     Cvor* it=pok; 
     Cvor* iza=pok;
     stack<pair<Boje,string>> s;
     for(int i=0;i<b;i++)
     {
         for(int j=0;j<=r-1;it=it->sljedeci,j++){}
         
         s.push(make_pair(it->karta.boja,it->karta.vrijednost));
         
         azuriraj(it,iza); 
     }
 
     return s;
 }
 
 bool prije(string s1,string s2, vector<string> v)
 {
    
     int ii,jj;
     for(int i=0;i<v.size();i++)
     if(s1==v[i]) ii=i;
     for(int j=0;j<v.size();j++)
     if(s2==v[j]) jj=j;
     if(ii<jj) return true;
     return false;
 }
 void azuriraj1(Cvor*iza, Cvor*n, Cvor *it){
  iza->sljedeci=n;
             n->sljedeci=it;
             it=n;
 }
 
 void pomjeri(Cvor *it, pair<Boje,string> s){
  vector<string> v={"2","3","4","5","6","7","8","9","10","J","Q","K"};
  while(prije(it->karta.vrijednost,s.second,v)&& it->karta.boja==s.first)
                 it=it->sljedeci;
 }
 
 void VratiPosljednjihNKarata(Cvor* &pok,stack<pair<Boje,string>> &s,int n)
 {
     Cvor* iza=pok;
     for(int i=0;i<n;i++)
     {
         for(Cvor* it=pok;it->sljedeci!=pok;it=it->sljedeci)
         {
             if(it->karta.boja==s.top().first)
             {
                 pomjeri(it,s.top());
                 iza=pok;
                 while(iza->sljedeci!=it)iza=iza->sljedeci;
                 Cvor *n=new Cvor;
                 n->karta.vrijednost=s.top().second;
                 n->karta.boja=s.top().first;
                 azuriraj1(iza,n,it);
                 s.pop();
                 break;
            }
     }
 }
 }

 
int main ()
{
 Cvor* spil=KreirajSpil();
    try{
    
    int n;
    cout<<"Unesite korak razbrajanja: ";
    cin>>n;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    int br;
    cin>>br;
    auto s=IzbaciKarteRazbrajanjem(spil,n,br);
    IspisiSpil(spil);
    cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    cin>>br;
    VratiPosljednjihNKarata(spil,s,br);
    IspisiSpil(spil);
     }
     catch(logic_error iz) {
      cout<<"Izuzetak: "<<iz.what();
      
     } 
     catch(domain_error iz) { 
      cout<<"Izuzetak: "<<iz.what();}
     catch(range_error iz) { 
      cout<<"Izuzetak: "<<iz.what();}
     UnistiSpil(spil);
	return 0;
}

/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
enum class Boje {Pik,Tref,Herc,Karo};
int Broji(list<pair<Boje,string>>&spil){
    int broj(1);
    auto it(spil.begin());
    while(it!=spil.end()){
        it++;
        broj++;
    }
}
void IspisiSpil(list<pair<Boje,string>>spil,Boje boja){
    auto it(spil.begin());
    //Sta ako nema te boje??
    if(boja==Boje(0)){
        while(boja!=(*it).first && it!=spil.end()) it++;
        cout<<"Pik: ";
        while(it!=spil.end()){
            if(boja==(*it).first)
            cout<<it->second<<" ";
            it++;
        }
    }
     if(boja==Boje(1)){
          while(boja!=(*it).first && it!=spil.end()) it++;
        cout<<"Tref: ";
        while(it!=spil.end()){
            if(boja==(*it).first)
            cout<<it->second<<" ";
            it++;
        }
    }
     if(boja==Boje(2)){
          while(boja!=(*it).first && it!=spil.end()) it++;
        cout<<"Herc: ";
        while(it!=spil.end()){
            if(boja==(*it).first)
            cout<<it->second<<" ";
            it++;
        }
    }
     if(boja==Boje(3)){
          while(boja!=(*it).first && it!=spil.end()) it++;
        cout<<"Karo: ";
        while(it!=spil.end()){
            if(boja==(*it).first)
            cout<<it->second<<" ";
            it++;
        }
    }
    
}
list<pair<Boje,string>>KreirajSpil(){
    list<pair<Boje,string>>parovi(52);
    auto it(parovi.begin());
    for(int i=0;i<52;i++){
        if(i<13){
            *it=make_pair(Boje(0),to_string(i+2));
            if(i==9)  *it=make_pair(Boje(0),"J");
            if(i==10) *it=make_pair(Boje(0),"Q");
            if(i==11) *it=make_pair(Boje(0),"K");
            if(i==12) *it=make_pair(Boje(0),"A");
        }
         if(i>=13 && i<26){
            *it=make_pair(Boje(1),to_string(i-11));
            if(i==22) *it=make_pair(Boje(1),"J");
            if(i==23) *it=make_pair(Boje(1),"Q");
            if(i==24) *it=make_pair(Boje(1),"K");
            if(i==25) *it=make_pair(Boje(1),"A");
        }
          if(i>=26 && i<39){
            *it=make_pair(Boje(2),to_string(i-24));
            if(i==35) *it=make_pair(Boje(2),"J");
            if(i==36) *it=make_pair(Boje(2),"Q");
            if(i==37) *it=make_pair(Boje(2),"K");
            if(i==38) *it=make_pair(Boje(2),"A");
        }
          if(i>=39 && i<52){
            *it=make_pair(Boje(3),to_string(i-37));
            if(i==48) *it=make_pair(Boje(3),"J");
            if(i==49) *it=make_pair(Boje(3),"Q");
            if(i==50) *it=make_pair(Boje(3),"K");
            if(i==51) *it=make_pair(Boje(3),"A");
        }
        it++;
        
    }
    return parovi;
}
/*list<pair<Boje,string>>NoviSpil(){
    string s;
    Boje boja;
    int j;
    int br;
    cout<<"Unesite velicinu spila: ";
    int vel;
    cin>>vel;
      list<pair<Boje,string>>parovi(vel);
      auto it(parovi.begin());
    for(int i=0;i<vel;i++){
   //     cout<<"Unesite "<<i+1<<" kartu: ";
    cin>>br;
    cin>>j;
    if(br==11){ *it=make_pair(Boje(j),"J");it++; continue;}
    if(br==12){ *it=make_pair(Boje(j),"Q");it++; continue;}
    if(br==13){ *it=make_pair(Boje(j),"K");it++; continue;}
    if(br==14){ *it=make_pair(Boje(j),"A");it++; continue;} 
    else {*it=make_pair(Boje(j),to_string(br));}
    it++;
    
    }
  
    return parovi;
} */
void IzbaciKarte(list<pair<Boje,string>>&spil,multimap<Boje,string>&m){
    if(Broji(spil)>52) logic_error("Izuzetak: Neispravna lista"); 
    auto it(spil.begin());
    auto itm(m.begin());
    while(it!=spil.end()){
        itm=m.begin();
        while(itm!=m.end()){
            if((it->first==itm->first) && ((*it).second==(*itm).second)){
                it=spil.erase(it);
              itm=m.erase(itm);
           //     continue;
            }
            else itm++;
        }
        it++;
    }
}
queue<pair<Boje,string>>IzbaciKarteRazbrajanjem(list<pair<Boje,string>>&spil,const short int &r,const int &b){
    if(r<1 || r>52 || b<1) throw logic_error("Izuzetak: Neispravni elementi za izbacivanje!");
    if(Broji(spil)>52) logic_error("Izuzetak: Neispravna lista");
    auto it1(spil.begin());
    while(it1!=spil.end()){
         if(!((*it1).first!=Boje::Pik || (*it1).first!=Boje::Tref || (*it1).first!=Boje::Herc || (*it1).first!=Boje::Karo || (*it1).second!="1" || (*it1).second!="2" || (*it1).second!="3" || (*it1).second!="4" || (*it1).second!="5" || (*it1).second!="6" || (*it1).second!="7" || (*it1).second!="8" || (*it1).second!="9" || (*it1).second!="10" || (*it1).second!="J" || (*it1).second!="Q" || (*it1).second!="K" || (*it1).second!="A")) throw logic_error("Izuzetak: Neispravne lista!");
         it1++;
    }
    queue<pair<Boje,string>>red;
    auto it(spil.begin());
    int br(1);
    int br_elem(1);
    int br_izb(0);
    
    while(it!=spil.end() && br_izb<b){
        while(it!=spil.end() && br!=r){ br_elem++;
      //     if(br_elem==52-ciklus*4 && br!=r){ it=spil.begin();ciklus=1; br++; br_elem=b;}
            it++;
            br++;
        }
        if(br_izb<b && br==r){
            br_elem++;
            red.push(*it);
            it=spil.erase(it);
            br_izb++;
            br=1;
            br++;
        }
        it++;
    }
    it--;
    return red;
} 
void VratiPrvihNKarata(list<pair<Boje,string>>&spil,queue<pair<Boje,string>>&red,int n){
      if(n<0) throw domain_error("Izuzetak: Broj n je besmislen!");
    if(n>red.size()) throw range_error("Izuzetak: Nedovoljno karata u redu!");
    if(Broji(spil)>52) logic_error("Izuzetak: Neispravna lista");
    auto it(spil.begin());
    int tmp,br_vracenih(0),nova;
    while(it!=spil.end() && br_vracenih<n){
        pair<Boje,string>element=red.front();
        if(!(element.first!=Boje::Pik || element.first!=Boje::Tref || element.first!=Boje::Herc || element.first!=Boje::Karo || element.second!="1" || element.second!="2" || element.second!="3" || element.second!="4" || element.second!="5" || element.second!="6" || element.second!="7" || element.second!="8" || element.second!="9" || element.second!="10" || element.second!="J" || element.second!="Q" || element.second!="K" || element.second!="A")) throw logic_error("Izuzetak: Neispravne karte!");
        if((*it).second=="2") tmp=2;
        if((*it).second=="3") tmp=3;
        if((*it).second=="4") tmp=4;
        if((*it).second=="5") tmp=5;
        if((*it).second=="6") tmp=6;
        if((*it).second=="7") tmp=7;
        if((*it).second=="8") tmp=8;
        if((*it).second=="9") tmp=9;
        if((*it).second=="10") tmp=10;
        if((*it).second=="J") tmp=11;
        if((*it).second=="Q") tmp=12;
        if((*it).second=="K") tmp=13;
        if((*it).second=="A") tmp=14;
        if(element.second=="2") nova=2;
        if(element.second=="3") nova=3;
        if(element.second=="4") nova=4;
        if(element.second=="5") nova=5;
        if(element.second=="6") nova=6;
        if(element.second=="7") nova=7;
        if(element.second=="8") nova=8;
        if(element.second=="9") nova=9;
        if(element.second=="10") nova=10;
        if(element.second=="J") nova=11;
        if(element.second=="Q") nova=12;
        if(element.second=="K") nova=13;
        if(element.second=="A") nova=14;
        if(element.first==(*it).first && nova==tmp-1){ spil.insert(it,element); red.pop(); br_vracenih++; it=spil.begin();}
        else if(element.first==(*it).first && nova==14 && tmp==13){spil.insert(++it,element); red.pop(); br_vracenih++;}
        it++;
    }
}
int main ()
{
    short int r;
    int b;
  queue<pair<Boje,string>> red;
  auto lista(KreirajSpil());
   multimap<Boje,string>m;
/*   m.insert({Boje(0),to_string(2)});
   m.insert({Boje(1),to_string(5)});
   m.insert({Boje(2),"J"}); */
   cout<<"Unesite korak razbrajanja: ";
   cin>>r;
   cout<<"Unesite broj karata koje zelite izbaciti: ";
   cin>>b;
   try{  red=IzbaciKarteRazbrajanjem(lista,r,b);
   cout<<"U spilu trenutno ima "<<52-b<<" karata, i to: "<<endl;
       IspisiSpil(lista,Boje(0));
       cout<<endl;
       IspisiSpil(lista,Boje(1));
       cout<<endl;
       IspisiSpil(lista,Boje(2));
       cout<<endl;
       IspisiSpil(lista,Boje(3));
   cout<<endl;
   }
   catch(logic_error e){
       cout<<e.what();
       return 0;
   }
   int n;
   cout<<"Unesite broj karata koje zelite vratiti u spil: ";
   cin>>n;
   try{
   VratiPrvihNKarata(lista,red,n);
   cout<<"U spilu trenutno ima "<<52-b+n<<" karata, i to: "<<endl;
       IspisiSpil(lista,Boje(0));
       cout<<endl;
       IspisiSpil(lista,Boje(1));
       cout<<endl;
       IspisiSpil(lista,Boje(2));
       cout<<endl;
       IspisiSpil(lista,Boje(3)); 
   }
     catch(domain_error e){
       cout<<e.what();
       return 0;
   }
   catch(range_error e){
       cout<<e.what();
       return 0;
   }
    catch(logic_error e){
       cout<<e.what();
       return 0;
   }
	return 0;
}

/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <list>
#include <map>
#include <utility>
#include <vector>
#include <queue>
#include <stdexcept>
using namespace std;
enum class Boje {Pik, Tref, Herc, Karo} boja;
 vector<string>v{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
 vector<string>v2{"Pik", "Tref", "Herc", "Karo"};

   list<pair<Boje, string>> KreirajSpil(){
      
       list<pair<Boje, string>>lista(52);
       int x=0;
       boja=Boje(0);
       int k(0);
       for(auto it=lista.begin();it!=lista.end();it++){
           *it=make_pair(boja, v[k]);
           k++;
           if(k==v.size()){
               k=0;
               x++;
               boja=Boje(x);
           }
           
       }
       return lista;
   }
   bool pom(pair<Boje,string>p, multimap<Boje, string>&m){
       for(auto it=m.begin(); it!=m.end();it++){
           if(p.first==it->first && p.second==it->second)
           return true;
       }
       return false;
   }
   int pretrazi(string s){
       for(int i=0;i<v.size();i++)
       if(s==v[i])return i;
       return -1;
   }
   
   bool smislenspil(list<pair<Boje, string>>&l){
       Boje trenutna=(*(l.begin())).first;
       int trenutni=pretrazi((*(l.begin())).second);
       for(auto it=l.begin();it!=l.end();it++){
           if(it==l.begin())continue;
           Boje procitana=it->first;
           int procitani=pretrazi(it->second);
           if((int)procitana==(int)trenutna){
               if(trenutni>=procitani)return false;
           }
           if((int)procitana<(int)trenutna)return false;
       }
       return true;
   }
    void IzbaciKarte(list<pair<Boje, string>>&l, multimap<Boje, string>&m){
    
    if(!smislenspil(l) || l.size()>52)throw logic_error("Neispravna lista!");
        for(auto it=l.begin();it!=l.end();it++){
            pair<Boje, string>p=*it;
            if(pom(*it, m)){
                it=l.erase(it);
                it=l.begin();
                for(auto it2=m.begin();it2!=m.end();it2++){
                    if(p.first==it2->first && p.second==it2->second){
                        m.erase(it2);
                    }
                }
            }
            
        }
        
    }
    
    queue<pair<string,string>>IzbaciKarteRazbrajanjem(list<pair<Boje, string>>&l, const short int &r, const int &b){
        if(r<1 || r>52 ||b<1)throw logic_error("Neispravni elementi za izbacivanje!");
        if(!smislenspil(l) || l.size()>52)throw logic_error("Neispravna lista!");
        queue<pair<string, string>>red;
        short int br(1);
        int koliko(0);
        for(auto it=l.begin();it!=l.end();){
            if(br==r) {
            koliko++;
            string pom=v2[(int)it->first];
            red.push(make_pair(pom,it->second));
            it=l.erase(it);
            br=1;
            it--;}
            else br++;
            if(koliko==b)break;
            it++;
            if(it==l.end())it=l.begin();
        }
        return red;
    
    }
    int pretraziboje(string s){
        for(int i=0;i<v2.size();i++)
        if(s==v2[i])return i;
        return -1;
    }
    void VratiPrvihNKarata(list<pair<Boje,string>>&l, queue<pair<string, string>>&red, int n){
        if(n<0)throw domain_error("Broj n je besmislen!");
        if(n>red.size())throw range_error("Nedovoljno karata u redu!");
        
        if(!smislenspil(l) || l.size()>52)throw logic_error("Neispravna lista!");
        int br(0);
        while(n!=0){
            auto element=red.front();
            red.pop();
            n--;
            int rednibrboje=pretraziboje(element.first);
            int rednibrbroja=pretrazi(element.second);
            for(auto it=l.begin();it!=l.end();it++){
                int bojaulisti=(int)it->first;
                int rednibrulisti=pretrazi(it->second);
                if(rednibrboje==bojaulisti && rednibrulisti>rednibrbroja){
                    l.insert(it, make_pair(Boje(rednibrboje), element.second));
                    break;
                }
                else if(rednibrboje==bojaulisti && rednibrbroja==v.size()-1){
                    while((int)it->first==rednibrboje)it++;
                    l.insert(it, make_pair(Boje(rednibrboje), element.second));
                    break;
                }
                /*else if(rednibrboje>bojaulisti){
                    
                    l.insert(it, make_pair(Boje(rednibrboje), element.second));
                    break;
                }*/
                
            }
        }
    }
    void ispisi(list<pair<Boje, string>> &l){
    //for(auto i=l.begin();i!=l.end();){
            
            /*if(i->first==Boje(0)){cout<<"Pik: ";
            while(i->first==Boje(0)) {cout<<i->second<<" ";
            if(i!=l.end())
            i++;}
            cout<<endl;
            }
            else if(i->first==Boje(1)){cout<<"Tref: ";
            while(i->first==Boje(1)) {cout<<i->second<<" ";
            if(i!=l.end())
            i++;}
            cout<<endl;
            }
            else if(i->first==Boje(2)){cout<<"Herc: ";
            while(i->first==Boje(2)) {cout<<i->second<<" ";
            if(i!=l.end())
            i++;}
            cout<<endl;
            }
            else {cout<<"Karo: ";
            while(i->first==Boje(3)) {cout<<i->second<<" ";
            if(i!=l.end())
            i++;}
            cout<<endl;
            }
             
    }*/
    
    cout<<"Pik: ";
   for(auto it=l.begin();it!=l.end();it++){
       if(it->first==Boje(0))cout<<it->second<<" ";
   }
     cout<<endl<<"Tref: ";
    for(auto it=l.begin();it!=l.end();it++){
       if(it->first==Boje(1))cout<<it->second<<" ";
   }
     cout<<endl<<"Herc: ";
    for(auto it=l.begin();it!=l.end();it++){
       if(it->first==Boje(2))cout<<it->second<<" ";
   
    }
     cout<<endl<<"Karo: ";
    for(auto it=l.begin();it!=l.end();it++){
       if(it->first==Boje(3))cout<<it->second<<" ";
   }
    cout<<endl;
    }
int main ()
{
    
    int k;
    cout<<"Unesite korak razbrajanja: ";
    cin>>k;
    int br;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    cin>>br;
    
    list<pair<Boje, string>>l=KreirajSpil();

    try{
    queue<pair<string, string>>red=IzbaciKarteRazbrajanjem(l, k, br);
    cout<<"U spilu trenutno ima "<<l.size()<<" karata, i to:"<<endl;
    ispisi(l);
    
        int vrati;
        cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        cin>>vrati;
        VratiPrvihNKarata(l, red, vrati);
        cout<<"U spilu trenutno ima "<<l.size()<<" karata, i to:"<<endl;
        ispisi(l);
    
    
}
    catch(domain_error f){
        cout<<"Izuzetak: "<<f.what();
    }
    catch(logic_error k){
        cout<<"Izuzetak: "<<k.what();
    }
    catch(range_error e){
        cout<<"Izuzetak: "<<e.what();
    }
    
	return 0;
}

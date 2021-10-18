/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <vector>
#include <stack>
#include <stdexcept>


using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};

vector<string> v{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

typedef list <pair <Boje, string>> Lista;

void Ispisi(const Lista &l){
    
    for(auto p = l.begin(); p != l.end(); p++){
        if((*p).first == Boje(0)) cout<<"Pik: ";
        else if((*p).first == Boje(1)) cout<<"Tref: ";
        else if((*p).first == Boje(2)) cout<<"Herc: ";
        else if((*p).first == Boje(3)) cout<<"Karo: ";
        auto k = p;
        k++;
        while((*p).first == (*k++).first){
            cout<<(*p++).second<<" ";
            if(k == l.end()) { cout<<(*p).second<<" "; break;}
        }
        if(k != l.end()) cout<<p->second<<" ";
        
        cout<<endl;
        if(k == l.end()) break;
        
    }
    
}
Lista KreirajSpil(){
   
    Lista l;
    
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < v.size(); j++){
            
            pair<Boje, string> p;
            p=make_pair(Boje(i),v[j]);
            l.push_back(p);
        }
            
    return l;
            
}
int OdrediVrijednost(string s){
    for(int i = 0; i < v.size(); i++)
        if(s == v[i]) return i;
        
    return -1;
}
bool ProvjeriListu(const Lista &l){
    
    if(l.size() > 52) return false;
    
    auto p = l.begin();
    
    for(int i = 0; i < l.size(); i++){
        
        Boje boja =  (*p++).first;
        if(p == l.end()) break;
        if(int(boja) > int((*p).first)) return false;
        p--;
        string s = (*p).second;
        
        
        int broj(OdrediVrijednost((*p++).second)), broj1;
        if((*p).first == boja) { broj1= OdrediVrijednost((*p).second);  if(broj1 < broj) return false; }
        
        p--;
        if(broj == -1 || broj1 == -1) return false;
        
        for(int j = 0; j < 4; j++){
            if((*p).first == Boje(j)) break;
            if(j == 3) return false;
        }
    
        for(int j = 0; j < v.size(); j++){
            if((*p).second == v[j]) break;
            if(j == v.size() - 1) return false;
        }
        p++;
    }
    
    return true; 
}

void IzbaciKarte(Lista &l, multimap<Boje, string> &mapa){
    
    if(!ProvjeriListu(l)) throw logic_error ("Neispravna lista!");
    
    for(auto p = l.begin(); p != l.end(); p++)
        for(auto k = mapa.begin(); k != mapa.end(); k++)
            if((*p).first == k->first && (*p).second == k->second) { l.erase(p); mapa.erase(k); }
            
}
stack <pair <Boje, string>> IzbaciKarteRazbrajanjem(Lista &l, short int r, int b){
    if(r < 1 || r >52 || b < 0) throw logic_error ("Neispravni elementi za izbacivanje!");
    if(!ProvjeriListu(l)) throw logic_error ("Neispravna lista!");

    stack <pair <Boje, string>> red;
    if(b == 0) return red;
    if(l.size() == 0) return red;
     
    int br(0);
    int br_izbacenih(0);

    for(auto p = l.begin();;p++ ){
        br++;
        if(br == r) {
            red.push(*p);
            p = l.erase(p);
            br_izbacenih++;
            if(r == 1) br = 0;
            else br = 1;
        }
    if(br_izbacenih == b) break;
    if(p == l.end()) p = l.begin(); 
    
    }
    return red;
}

void VratiPrvihNKarata(Lista &l, stack<pair <Boje, string>> &red, int n){
    
    if(n < 0) throw domain_error ("Broj n je besmislen!");
    if(n > red.size()) throw range_error ("Nedovoljno karata u redu!");
    if(!ProvjeriListu(l)) throw logic_error ("Neispravna lista!");
    
    vector<pair <Boje, string>> red1(red.size());
    
    for(int i = red.size() - 1; i >= 0; i--){
        if(OdrediVrijednost(red.top().second) == -1) throw logic_error ("Neispravne karte!");
        red1[i] = red.top();
        red.pop();
    }
    
    for(int i = 0; i < n; i++)
        for(auto p = l.begin(); p != l.end(); p++ )
            if(p->first == red1[i].first) {
                if(p->second == red1[i].second) { i--; break; }
                else{
                    
                    while(p != l.end() && OdrediVrijednost(p->second) < OdrediVrijednost(red1[i].second)){
                        if(p->first != red1[i].first) break;
                        if(p->second == red1[i].second) break;
                        p++;
                    }
                    
                    if(p == l.end()) break;
                    
                    l.insert(p,red1[i]);
                
                    break;
                }
            }
        
    
}


int main ()
{
    try{
        
        Lista l = KreirajSpil();
    
        short int a;
        cout<<"Unesite korak razbrajanja: ";
        cin>>a;
        
        int b;    
        cout<<"Unesite broj karata koje zelite izbaciti: ";
        cin>>b;
        auto red = IzbaciKarteRazbrajanjem(l,a,b);
        cout<<"U spilu trenutno ima "<<l.size()<<" karata, i to: "<<endl;
        Ispisi(l);
        
        int n;
        cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        cin>>n;
        VratiPrvihNKarata(l, red, n);
        
        cout<<"U spilu trenutno ima "<<l.size()<<" karata, i to: "<<endl;
        Ispisi(l);
    
    }
    catch(domain_error e){
        cout<<"Izuzetak: "<<e.what()<<endl;
    }
    catch(logic_error e){
        cout<<"Izuzetak: "<<e.what()<<endl;
    }
    catch(range_error e){
        cout<<"Izuzetak: "<<e.what()<<endl;
    }
	return 0;
}

#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
#include <queue>
#include <stdexcept>
#include <iterator>
using namespace std;
enum class Boje {Pik=0, Tref, Herc, Karo};
typedef list<pair<Boje,string>> ListaParova;
int Karta(pair<Boje,string> p){
    string s[]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(int i=0;i<13;i++){
        if(p.second==s[i]) return i;
    }
}
void SortirajListu(ListaParova &l){
    l.sort([](pair<Boje,string> p1,pair<Boje,string> p2){return Karta(p1)<Karta(p2);});
    l.sort([](pair<Boje,string> p1,pair<Boje,string> p2){return p1.first<p2.first;});
}
bool Sortirana(ListaParova l){
 ListaParova pomocna(l);
 SortirajListu(l);
 auto iter(pomocna.begin());
 for(auto it=l.begin();it!=l.end();it++){
     if(it->first!=iter->first || it->second!=iter->second) return false;
     iter++;
 }
 return true;
}
bool Ispravna(ListaParova &l){
    string s[]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int br(0);
    for(auto it=l.begin();it!=l.end();it++){
      for(int i=0;i<13;i++){
          if(it->second==s[i]) br++;
      }
      if(!br) return false;
      br=0;
      if(!(it->first==Boje::Pik || it->first==Boje::Tref || it->first==Boje::Herc || it->first==Boje::Karo)) return false;
    }
    return true;
}
bool IspravanRed(queue<pair<string,string>> q){
    string s[]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    string Boje[]={"Pik", "Tref", "Herc", "Karo"};
    int br1(0),br2(0);
    while(!q.empty()){
    for(int i=0;i<13;i++){
        if(q.front().second==s[i]) br1++;
    }
    for(int i=0;i<4;i++){
       if(q.front().first==Boje[i]) br2++; 
    }
    if(!br1 || !br2) return false;
    br1=0;
    br2=0;
    q.pop();
    }
    return true;
}
ListaParova KreirajSpil(){
    ListaParova l;
    string s[]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            l.push_back(make_pair(Boje(i),s[j]));
        }
    }
    return l;
}
void IzbaciKarte(ListaParova &l, multimap<Boje,string> &m){
    if(l.size()>52 || !Ispravna(l) || !Sortirana(l)) throw logic_error("Neispravna lista!");
    for(auto it=l.begin();it!=l.end();it++){
        for(auto iter=m.begin();iter!=m.end();iter++){
            if(it->first==iter->first && it->second==iter->second){
                it=l.erase(it);
                m.erase(iter);
            }
        }
    }
}
queue<pair<string,string>> IzbaciKarteRazbrajanjem(ListaParova &l, const short int &r, const int &b){
    if(l.size()>52 || !Ispravna(l) || !Sortirana(l)) throw logic_error("Neispravna lista!");
    queue<pair<string,string>> q;
    string Boje[]={"Pik", "Tref", "Herc", "Karo"};
    if(r<1 || r>52 || b<1) throw logic_error("Neispravni elementi za izbacivanje!");
        auto it=l.begin();
        for(int i=0;i<b;i++){
        if(distance(it,l.end())>=r) advance(it,r-1);
        else{
          int nova_distanca=r-distance(it,l.end());
          it=l.begin();
          advance(it,nova_distanca-1);
        }
        //if(it->first==Boje)
        q.push({Boje[static_cast<int>(it->first)],it->second});
        it=l.erase(it);
        }
        return q;
}
void VratiPrvihNKarata(ListaParova &l, queue<pair<string,string>> &q, int n){
    if(l.size()>52 || !Ispravna(l) || !Sortirana(l)) throw logic_error("Neispravna lista!");
    int vel=q.size();
    if(n>vel) throw range_error("Nedovoljno karata u redu!");
    if(n<0) throw domain_error("Broj n je besmislen!");
    if(!IspravanRed(q)) throw logic_error("Neispravne karte!");
    string Boja[]={"Pik", "Tref", "Herc", "Karo"};
    while(n){
    for(int i=0;i<4;i++)
    if(Boja[i]==q.front().first)
    l.push_back({Boje(i),q.front().second});
    q.pop();
    n--;
    }
   SortirajListu(l); 
}
int main ()
{   
    string Boja[]={"Pik", "Tref", "Herc", "Karo"};
    cout<<"Unesite korak razbrajanja: ";
    int r;
    cin>>r;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    int b;
    cin>>b;
    ListaParova l;
    l=KreirajSpil();
    queue<pair<string,string>> q;
    try{
    q=IzbaciKarteRazbrajanjem(l,r,b);
    }catch(logic_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
    cout<<"U spilu trenutno ima "<<l.size()<<" karata, i to:"<<endl;
    for(int i=0;i<4;i++){
        cout<<Boja[i]<<": ";
    for(auto it=l.begin();it!=l.end();it++){
    if(it->first==Boje(i)) cout<<it->second<<" ";
    }
    cout<<endl;
    }
    cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    int n;
    cin>>n;
    try{
    VratiPrvihNKarata(l,q,n);
    }catch(domain_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }catch(logic_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }catch(range_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
    cout<<"U spilu trenutno ima "<<l.size()<<" karata, i to:"<<endl;
    for(int i=0;i<4;i++){
    cout<<Boja[i]<<": ";
    for(auto it=l.begin();it!=l.end();it++){
    if(it->first==Boje(i)) cout<<it->second<<" ";
    }
    cout<<endl;
    }
	return 0;
}

/*#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
#include <queue>
#include <stdexcept>
#include <iterator>
using namespace std;
enum class Boje
{
    Pik=0, Tref, Herc, Karo
};
typedef list<pair<Boje,string>> ListaParova;
int Karta(pair<Boje,string> p)
{
    string s[]= {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(int i=0; i<13; i++) {
        if(p.second==s[i]) return i;
    }
}
void SortirajListu(ListaParova &l)
{
    l.sort([](pair<Boje,string> p1,pair<Boje,string> p2) {
        return Karta(p1)<Karta(p2);
    });
    l.sort([](pair<Boje,string> p1,pair<Boje,string> p2) {
        return p1.first<p2.first;
    });
}
bool Sortirana(ListaParova l)
{
    ListaParova pomocna(l);
    SortirajListu(l);
    auto iter(pomocna.begin());
    for(auto it=l.begin(); it!=l.end(); it++) {
        if(it->first!=iter->first || it->second!=iter->second) return false;
        iter++;
    }
    return true;
}
bool Ispravna(ListaParova &l)
{
    string s[]= {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int br(0);
    for(auto it=l.begin(); it!=l.end(); it++) {
        for(int i=0; i<13; i++) {
            if(it->second==s[i]) br++;
        }
        if(!br) return false;
        br=0;
        if(!(it->first==Boje::Pik || it->first==Boje::Tref || it->first==Boje::Herc || it->first==Boje::Karo)) return false;
    }
    return true;
}
bool IspravanRed(queue<pair<string,string>> q)
{
    string s[]= {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    string Boje[]= {"Pik", "Tref", "Herc", "Karo"};
    int br1(0),br2(0);
    while(!q.empty()) {
        for(int i=0; i<13; i++) {
            if(q.front().second==s[i]) br1++;
        }
        for(int i=0; i<4; i++) {
            if(q.front().first==Boje[i]) br2++;
        }
        if(!br1 || !br2) return false;
        br1=0;
        br2=0;
        q.pop();
    }
    return true;
}
ListaParova KreirajSpil()
{
    ListaParova l;
    string s[]= {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            l.push_back(make_pair(Boje(i),s[j]));
        }
    }
    return l;
}
void IzbaciKarte(ListaParova &l, multimap<Boje,string> &m)
{
    if(l.size()>52 || !Ispravna(l) || !Sortirana(l)) throw logic_error("Neispravna lista!");
    for(auto it=l.begin(); it!=l.end(); it++) {
        for(auto iter=m.begin(); iter!=m.end(); iter++) {
            if(it->first==iter->first && it->second==iter->second) {
                it=l.erase(it);
                m.erase(iter);
            }
        }
    }
}
queue<pair<string,string>> IzbaciKarteRazbrajanjem(ListaParova &l, const short int &r, const int &b)
{
    if(l.size()>52 || !Ispravna(l) || !Sortirana(l)) throw logic_error("Neispravna lista!");
    queue<pair<string,string>> q;
    string Boje[]= {"Pik", "Tref", "Herc", "Karo"};
    if(r<1 || r>52 || b<1) throw logic_error("Neispravni elementi za izbacivanje!");
    auto it=l.begin();
    int za_izbaciti(b);
    int razlika(za_izbaciti-l.size());
    if(razlika>0) za_izbaciti=l.size();
    for(int i=0; i<za_izbaciti; i++) {
        if(distance(it,l.end())>=r) advance(it,r-1);
        else {
            int nova_distanca=r-distance(it,l.end());
            it=l.begin();
            advance(it,nova_distanca-1);
        }
        //if(it->first==Boje)
        if(it!=l.end()) {
            q.push({Boje[static_cast<int>(it->first)],it->second});
            it=l.erase(it);
        }
    }
    return q;
}
void VratiPrvihNKarata(ListaParova &l, queue<pair<string,string>> &q, int n)
{
    if(l.size()>52 || !Ispravna(l) || !Sortirana(l)) throw logic_error("Neispravna lista!");
    int vel=q.size();
    if(n>vel) throw range_error("Nedovoljno karata u redu!");
    if(n<0) throw domain_error("Broj n je besmislen!");
    if(!IspravanRed(q)) throw logic_error("Neispravne karte!");
    string Boja[]= {"Pik", "Tref", "Herc", "Karo"};
    int br(0);
    while(n) {
        for(int i=0; i<4; i++) {
            if(Boja[i]==q.front().first){
                for(auto it=l.begin(); it!=l.end(); it++) {
                    if(it->first==Boje(i) && it->second==q.front().second) q.pop();
                    br++;
                    i--;
                    break;
                }
                if(!br){
                l.push_back({Boje(i),q.front().second});
                q.pop();
                }
               

            }
             br=0;
        }
        n--;
    }
    SortirajListu(l);
}
int main ()
{
    string Boja[]= {"Pik", "Tref", "Herc", "Karo"};
    cout<<"Unesite korak razbrajanja: ";
    int r;
    cin>>r;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    int b;
    cin>>b;
    ListaParova l;
    l=KreirajSpil();
    queue<pair<string,string>> q;
    try {
        q=IzbaciKarteRazbrajanjem(l,r,b);
    } catch(logic_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
    cout<<"U spilu trenutno ima "<<l.size()<<" karata, i to:"<<endl;
    for(int i=0; i<4; i++) {
        cout<<Boja[i]<<": ";
        for(auto it=l.begin(); it!=l.end(); it++) {
            if(it->first==Boje(i)) cout<<it->second<<" ";
        }
        cout<<endl;
    }
    cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    int n;
    cin>>n;
    try {
        VratiPrvihNKarata(l,q,n);
    } catch(domain_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    } catch(logic_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    } catch(range_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
    cout<<"U spilu trenutno ima "<<l.size()<<" karata, i to:"<<endl;
    for(int i=0; i<4; i++) {
        cout<<Boja[i]<<": ";
        for(auto it=l.begin(); it!=l.end(); it++) {
            if(it->first==Boje(i)) cout<<it->second<<" ";
        }
        cout<<endl;
    }
    return 0;
}*/

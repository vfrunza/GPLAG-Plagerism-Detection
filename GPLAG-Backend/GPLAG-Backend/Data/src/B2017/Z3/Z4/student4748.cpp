/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <stdexcept>
using namespace std;
enum class Boje {Pik, Tref, Herc, Karo};
typedef list<pair<Boje,string>> Spil;

Spil SortirajSpil(Spil sp){
    Spil SPIL=sp;
    for(auto it=SPIL.begin();it!=SPIL.end();it++){
    if(it->second=="J") it->second="11";
    if(it->second=="Q") it->second="12";
    if(it->second=="K") it->second="13";
    if(it->second=="A") it->second="14";
    }
    for(auto it1=SPIL.begin();it1!=SPIL.end();it1++){
        for(auto it2=it1;it2!=SPIL.end();it2++){
            
            if(it1->second>it2->second && it1->first==it2->first && it2->second.size()==1){
                pair<Boje,string> zamjenski;
                zamjenski=*it1;
                *it1=*it2;
                *it2=zamjenski;
                continue;
            }
            if(it1->second<it2->second && it1->second.size()==2 && it1->first==it2->first){
                pair<Boje,string> zamjenski;
                zamjenski=*it1;
                *it1=*it2;
                *it2=zamjenski;
            }
            if(it1->second.size()==2 && it2->second.size()==2 && it1->first==it2->first){
                if(it1->second[1]>it2->second[1]){
                pair<Boje,string> zamjenski;
                zamjenski=*it1;
                *it1=*it2;
                *it2=zamjenski;
                }
            }
        }
    }
    for(auto it=SPIL.begin();it!=SPIL.end();it++){
        if(it->second=="11") it->second="J";
        if(it->second=="12") it->second="Q";
        if(it->second=="13") it->second="K";
        if(it->second=="14") it->second="A";
    }
    return SPIL;
}

Spil KreirajSpil(){
    Spil spil;
    string S[13]{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(int i=0;i<4;i++){
        Boje boja=static_cast<Boje>(i); 
        for(int j=0;j<13;j++){
            pair<Boje,string> temp;
            temp.first=boja;
            temp.second=S[j];
            spil.push_back(temp);
        }
    }
    return spil;
}

void IzbaciKarte(Spil &s, multimap<Boje, string> &multimapa){
    Spil pomocni=s;
    pomocni=SortirajSpil(pomocni);
    if(s.size()>52 || pomocni!=s) throw logic_error("Neispravna lista");
    for(pair<Boje,string> karta: multimapa){
        for(auto it=s.begin();it!=s.end();it++){
            if(*it==karta){
                it=s.erase(it);
                pair<Boje,string> temp_karta=karta;
                multimapa.erase(karta.first);
                for(pair<Boje,string> pomk: multimapa){
                    if(pomk==temp_karta){
                        multimapa.erase(pomk.first);
                    }
                }
            }
        }
    }
}

queue<pair<string,string>> IzbaciKarteRazbrajanjem(Spil &S, const short int &r, const int &b){
    if((r<1 || r>52) || (b<1)) throw logic_error("Neispravni elementi za izbacivanje!");
    int briz(0),brk(0);
    queue<pair<string,string>> Red;
    auto itp=S.end();
    itp--;
    for(auto it=S.begin();it!=S.end();it++){
        brk++;
        if(brk==r){
            pair<string,string> priv;
            if(it->first==static_cast<Boje>(0)){
                string s="Pik";
                priv.first=s;;
            }
            else if(it->first==static_cast<Boje>(1)){
                string s="Tref";
                priv.first=s;
            }
            else if(it->first==static_cast<Boje>(2)){
                    string s="Herc";
                    priv.first=s;
            }
            else{
                string s="Karo";
                priv.first=s;
            }
            priv.second=it->second;
            Red.push(priv);
            if(S.size()>1){
                itp=S.end();
                itp--;
            }
            it=S.erase(it);
            briz++;
            brk=1;
            
        }
        
        if(briz==b) break;
        if(it==itp || it==S.end()){
            it=S.begin();
            
            brk++;
        }
    }
    return Red;
} 

void VratiPrvihNKarata(Spil &s, queue<pair<string,string>> &red, int n){
    if(n<0) throw domain_error("Broj n je besmislen!");
    if(n>red.size()) throw range_error("Nedovoljno karata u redu!");
    
    for(int i=0;i<n;i++){
        pair<string,string> privremeni;
        privremeni=red.front();
        for(auto it=s.begin();it!=s.end();it++){
            if(it->first==static_cast<Boje>(0) && privremeni.first=="Pik"){
                pair<Boje,string> ubaciga;
                ubaciga.first=static_cast<Boje>(0);
                ubaciga.second=privremeni.second;
                while(privremeni.second>it->second && it->second=="Pik"){
                    it++;
                  }
                it++;
                
                s.insert (it,ubaciga);
                
                break;
            }
            if(it->first==static_cast<Boje>(1) && privremeni.first=="Tref"){
                pair<Boje,string> ubaciga;
                ubaciga.first=static_cast<Boje>(1);
                ubaciga.second=privremeni.second;
                while(privremeni.second>it->second && it->second=="Tref"){
                    it++;
                }
                it++;
                s.insert(it,ubaciga);
                break;
            }
            if(it->first==static_cast<Boje>(2) && privremeni.first=="Herc"){
                pair<Boje,string> ubaciga;
                ubaciga.first=static_cast<Boje>(2);
                ubaciga.second=privremeni.second;
                while(privremeni.second>it->second && it->second=="Herc"){
                    it++;
                }
                it++;
                s.insert(it,ubaciga);
                break;
            }
            if(it->first==static_cast<Boje>(3) && privremeni.first=="Karo"){
                pair<Boje,string> ubaciga;
                ubaciga.first=static_cast<Boje>(3);
                ubaciga.second=privremeni.second;
                while(privremeni.second>it->second && it->second=="Karo"){
                    it++;
                }
                it++;
                s.insert(it,ubaciga);
                break;
            }
         }
        red.pop();
    }
    
}

int main ()
{
    Spil karte;
    queue<pair<string,string>> RED;
    karte=KreirajSpil();
    cout<<"Unesite korak razbrajanja: ";
    int k;
    cin>>k;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    int p;
    cin>>p;
    
    try{
    RED=IzbaciKarteRazbrajanjem(karte,k,p);
    
    }
    catch(logic_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
    cout<<"U spilu trenutno ima "<<52-p<<" karata, i to: "<<endl;
    for(auto it=karte.begin();it!=karte.end();it++){
        cout<<"Pik: ";
        while(static_cast<Boje>(0)==it->first){
            cout<<it->second<<" ";
            it++;
        }
        cout<<endl<<"Tref: ";
        while(static_cast<Boje>(1)==it->first){
            cout<<it->second<<" ";
            it++;
        }
        cout<<endl<<"Herc: ";
        while(static_cast<Boje>(2)==it->first){
            cout<<it->second<<" ";
            it++;
        }
        cout<<endl<<"Karo: ";
        while(static_cast<Boje>(3)==it->first){
            cout<<it->second<<" ";
            it++;
            if(it==karte.end()) break;
        }
       break;
    }
    cout<<endl<<"Unesite broj karata koje zelite vratiti u spil: ";
    int brkarata;
    cin>>brkarata;
    try{
    VratiPrvihNKarata(karte,RED,brkarata);
    karte=SortirajSpil(karte);

    cout<<"U spilu trenutno ima "<<karte.size()<<" karata, i to:"<<endl;
    for(auto it=karte.begin();it!=karte.end();it++){
        cout<<"Pik: ";
        while(static_cast<Boje>(0)==it->first){
            cout<<it->second<<" ";
            it++;
        }
        cout<<endl<<"Tref: ";
        while(static_cast<Boje>(1)==it->first){
            cout<<it->second<<" ";
            it++;
        }
        cout<<endl<<"Herc: ";
        while(static_cast<Boje>(2)==it->first){
            cout<<it->second<<" ";
            it++;
        }
        cout<<endl<<"Karo: ";
        while(static_cast<Boje>(3)==it->first){
            cout<<it->second<<" ";
            it++;
            if(it==karte.end()) break;
        }
        break;
    }
    }
    catch(range_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
    }
    catch(domain_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}

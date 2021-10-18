/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <cstring>
#include <set>
#include <list>
#include <stdexcept>
#include<vector>
using namespace std;

int broj_slova(string s){
    int i=0,brojac=0;
    while(i!=s.size()){
        brojac=0;
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
            while((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
                brojac++; i++;
            }
        }
        else i++;
    }
    return brojac;
}

vector<set<string>>Razvrstavanje(vector<string>imena_djece, int broj_timova){
    if(broj_timova<1 || broj_timova>imena_djece.size()) throw logic_error("Razvrstavanje nemoguce");
    //stavljamo iz vektora u listu
    list<string>lista;
    for(int i=0;i<imena_djece.size();i++) lista.push_back(imena_djece[i]);
    //npr imena_djece.size()=10, broj_timova=3,  m=3, n=1, sto znaci da ce prvi tim imati  4 clana, a ostala dva 3 clana
    int n=imena_djece.size()%broj_timova; // prvih n timova ce imati m+1 clanova
    int m=imena_djece.size()/broj_timova;//preostali timovi ce imati m clanova
    vector<set<string>>konacni;
    auto it=lista.begin();
    int izbroji=0;
        if(n!=0){ //formiramo timove (skupove) sa m+1 clanovima
            while(n!=0){ 
                set<string>tim; 
                for(int i=0;i<m+1;i++){ //krecemo se kroz kreirani skup, tim
                    if(it==lista.end())it=lista.begin();
                    tim.insert(*it); //ubacujemo frajera koji je prvi u listi u skup
                    int brojac_slova=broj_slova(*it); //brojimo koliko mu ime ima slova
                    auto pomocna=it;
                    pomocna++;
                    if(pomocna==lista.end()){it=lista.erase(it);it=lista.begin();}
                    else it=lista.erase(it); //brisemo ga
                     //da li ce sljedeci tim imati m calnova ili m+1...
                     //treba za sljedeci if
                    int joj=0;
                    if(lista.size()==0)break;
                    while(joj!=brojac_slova-1){
                            if(it==lista.end())it=lista.begin();
                              it++;
                            joj++;}
                }
                n--;
                izbroji++;
                konacni.push_back(tim); 
                if(n==0)break;
            }
        }
        if(n==0){ //formiramo timove (skupove) sa m clanova
        int ejs=broj_timova-izbroji;
            while(ejs!=0){
                set<string>tim;
                for(int i=0;i<m;i++){
                    if(it==lista.end())it=lista.begin();
                    tim.insert(*it);
                    int brojac_slova=broj_slova(*it);
                    auto pomocna=it;
                    pomocna++;
                    if(pomocna==lista.end()){it=lista.erase(it);it=lista.begin();}
                    else
                    it=lista.erase(it);
                    int joj=0;
                    if(lista.size()==0)break;
                    while(joj!=brojac_slova-1) {
                            if(it==lista.end())it=lista.begin();

                            it++; joj++; }
                }
                ejs--;
                konacni.push_back(tim); 
            }
        }
        
    return konacni;
}

int main (){
    try{
        int n;
        cout<<"Unesite broj djece: ";
        cin>>n;
        vector<string>imena_djece(n);
        cout<<"Unesite imena djece: "<<endl;
        for(int i=0;i<n;i++){
            cin>>imena_djece[i];
            //getline(cin,imena_djece[i]);
        }
        
        int broj_timova;
        cout<<"Unesite broj timova: ";
        cin>>broj_timova;
    vector<set<string>>hehe;
    hehe=Razvrstavanje(imena_djece,broj_timova);
    for(int i=0;i<hehe.size();i++){ 
        cout<<"Tim "<<i+1<<": ";
        int brojaac=0;
        for(auto x:hehe[i]){ 
         if(brojaac==hehe[i].size()-1) cout<<x;
         else cout<<x<<", ";
         brojaac++;
        }
        cout<<endl;
    }}
    catch(logic_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what()<<endl;
    }
	return 0;
}
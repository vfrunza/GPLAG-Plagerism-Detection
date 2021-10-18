/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <cstring>
#include <set>
#include <list>
#include <stdexcept>
#include<vector>
using namespace std;
struct Dijete{
    string ime;
    Dijete* sljedeci;
};
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
    try{
    Dijete *djeca=new Dijete [imena_djece.size()];
    for(int i=0;i<imena_djece.size()-1;i++){
        djeca[i].ime=imena_djece[i];
        djeca[i].sljedeci=&djeca[i+1];
    }
    djeca[imena_djece.size()-1].ime=imena_djece[imena_djece.size()-1];
    djeca[imena_djece.size()-1].sljedeci=&djeca[0];
    int n=imena_djece.size()%broj_timova; 
    int m=imena_djece.size()/broj_timova;
    vector<set<string>>konacni;
    Dijete *pokazivac=&djeca[0];
    int velicina=imena_djece.size();
    int izbroji=0;
    int pozicija=0;
        if(n!=0){ 
            while(n!=0){ 
                set<string>tim; 
                for(int i=0;i<m+1;i++){ 
                   if(pozicija==velicina)pozicija=0;
                   tim.insert(djeca[pozicija].ime); 
                    int brojac_slova=broj_slova(djeca[pozicija].ime); 
                    for(int k=pozicija;k<velicina-1;k++){
                        djeca[k].ime=djeca[k+1].ime;
                    }
                    djeca[velicina-1].sljedeci=&djeca[0];
                    velicina--;
                    int joj=0;
                    while(joj!=brojac_slova-1){
                            if(pozicija==velicina)pozicija=0;
                              pozicija++;
                            joj++;}
                }
                n--;
                izbroji++;
                konacni.push_back(tim); 
                if(n==0)break;
            }
        }
        if(n==0){ 
        int ejs=broj_timova-izbroji;
            while(ejs!=0){
                set<string>tim;
                for(int i=0;i<m;i++){
                    if(pozicija==velicina)pozicija=0;
                    tim.insert(djeca[pozicija].ime);
                    int brojac_slova=broj_slova(djeca[pozicija].ime);
                    for(int k=pozicija;k<velicina-1;k++){
                        djeca[k].ime=djeca[k+1].ime;
                    }
                    djeca[velicina-1].sljedeci=&djeca[0];
                    velicina--;
                    int joj=0;
                    if(velicina==0)break;
                    while(joj!=brojac_slova-1) {
                            if(pozicija==velicina)pozicija=0;
                            pozicija++;
                            joj++; }
                }
                ejs--;
                konacni.push_back(tim); 
            }
        }
        delete []djeca;
        
    return konacni;
}
catch(...){
throw "nema memorije";}
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
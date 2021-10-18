/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>

using namespace std;

int VratiVelicinuStringa(string s){
    int brojac(0);
    if (s.length()==0)return brojac=0;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))brojac++;
    }
    return brojac;
}

vector<set<string>> Razvrstavanje(vector<string>imena_djece,int broj_timova){
    if(broj_timova<1 || broj_timova>imena_djece.size())throw logic_error("Razvrstavanje nemoguce");
    list<string>pomocna;
    for(int i=0;i<imena_djece.size();i++){
        pomocna.push_back(imena_djece[i]);
    }
    vector<set<string>>vs;
    auto velicina=imena_djece.size();
    int br_djece_po_timu1,br_djece_po_timu2,prvi_timovi,ostali_timovi;
    if(velicina%broj_timova==0){br_djece_po_timu1=imena_djece.size()/broj_timova;br_djece_po_timu2=br_djece_po_timu1;prvi_timovi=broj_timova;ostali_timovi=prvi_timovi;}
    else {
        prvi_timovi=imena_djece.size()%broj_timova;
        br_djece_po_timu1=int(imena_djece.size()/broj_timova)+1;
        ostali_timovi=broj_timova-prvi_timovi;
        br_djece_po_timu2=int(imena_djece.size()/broj_timova);
    }
    
    list<string>::iterator it(pomocna.begin());
    set<string>skup;
    skup.insert(*it);
    int pamti=VratiVelicinuStringa(*it);
    it=pomocna.erase(it);
    if(imena_djece.size()==1 && broj_timova==1){vs.push_back(skup);return vs;}
    int koliko(1);
    int nesh(0);
    auto it2=pomocna.begin();
    for(;;) {
        if(imena_djece.size()==broj_timova&&nesh==0) {
            vs.push_back(skup);
            skup.clear();
        }
        for(;;) {
            if(imena_djece.size()==broj_timova) {
                skup.insert(*it2);
                it2=pomocna.erase(it2);
                break;
            }
        if(it2==pomocna.end()) it2=pomocna.begin();
        if(koliko!=pamti) {  koliko++; it2++; }
        else {
            skup.insert(*it2);
            pamti=VratiVelicinuStringa(*it2);
            it2=pomocna.erase(it2);
            koliko=1;
            break;
            }
        }
        if(imena_djece.size()%broj_timova==0) {
        if(skup.size()==br_djece_po_timu1) {
            nesh++;
            vs.push_back(skup);
            skup.clear();
            }
        }
        if(imena_djece.size()%broj_timova!=0) {
            if (skup.size()==br_djece_po_timu2 && nesh>=prvi_timovi) {
                nesh++;
            vs.push_back(skup);
            skup.clear();
        }
            if(skup.size()==br_djece_po_timu1) {
                nesh++;
            vs.push_back(skup);
            skup.clear();
        }
        }
        if (distance(pomocna.begin(), pomocna.end()) == 0) break;
        if (distance(pomocna.begin(), pomocna.end()) == 1)
        {
            skup.insert(*pomocna.begin());
            vs.push_back(skup);
            break;
        }
    } 
    
   return vs; 
}

int main ()
{
    try{
    cout<<"Unesite broj djece: ";
    int br_dj;cin>>br_dj;
    cout<<"Unesite imena djece: "<<endl;
    vector<string>imena;
    cin.ignore(1000,'\n');
    for(int i=0;i<br_dj;i++){
        string ime;
        getline(cin,ime);
        imena.push_back(ime);
    }
    cout<<"Unesite broj timova: ";
    int br_timova;cin>>br_timova;
    vector<set<string>>rezultat=Razvrstavanje(imena,br_timova);
    for(int i=0;i<rezultat.size();i++){
        cout<<"Tim "<<i+1<<": ";
        int brojac(0);
        for(string s:rezultat[i]){brojac++;if (brojac<rezultat[i].size())cout<<s<<", ";else cout<<s;}
        cout<<endl;
    }
}
    catch(logic_error l){
        cout<<"Izuzetak: "<<l.what();
    }
   
	return 0;
}
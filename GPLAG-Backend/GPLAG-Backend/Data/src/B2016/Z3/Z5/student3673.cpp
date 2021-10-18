/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <new>

using namespace std;

struct Dijete {
    string ime;
    Dijete *sljedeci;
};

int VratiVelicinuStringa(string s){
    int brojac(0);
    if(s.length()==0){return brojac=0;}
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))brojac++;
    }
    return brojac;
}

vector<set<string>> Razvrstavanje(vector<string>imena_djece,int broj_timova){
    if(broj_timova<1 || broj_timova>imena_djece.size())throw logic_error("Razvrstavanje nemoguce");
    //kreiranje liste djece
    Dijete *pocetak(nullptr),*prethodni;
    for(int i=0;i<imena_djece.size();i++){
        Dijete *novi(new Dijete);
        novi->ime=imena_djece[i];novi->sljedeci=nullptr;
        if(!pocetak)pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        if(i==imena_djece.size()-1)novi->sljedeci=pocetak;
    }
    vector<set<string>>vs;
    int br_djece_po_timu1,br_djece_po_timu2,prvi_timovi;
    if(imena_djece.size()%broj_timova==0){br_djece_po_timu1=imena_djece.size()/broj_timova;br_djece_po_timu2=br_djece_po_timu1;prvi_timovi=broj_timova;}
    else {
        prvi_timovi=imena_djece.size()%broj_timova;
        br_djece_po_timu1=int(imena_djece.size()/broj_timova)+1;
        br_djece_po_timu2=int(imena_djece.size()/broj_timova);
    }
    set<string>skup;
    skup.insert(pocetak->ime);
    int pamti=VratiVelicinuStringa(pocetak->ime);
    prethodni->sljedeci=pocetak->sljedeci;
    pocetak->sljedeci=nullptr;
    delete pocetak;
    pocetak=prethodni->sljedeci;
    if(imena_djece.size()==1 && broj_timova==1){vs.push_back(skup);return vs;}
    int koliko(1);
    int nesh(0);
    Dijete *it2=pocetak;
    for(;;){
        if(imena_djece.size()==broj_timova && nesh==0){
            vs.push_back(skup);
            skup.clear();
        }
        for(;;){
            if(imena_djece.size()==broj_timova){
                skup.insert(it2->ime);
                prethodni->sljedeci=it2->sljedeci;
                it2->sljedeci=nullptr;
                delete it2;
                it2=prethodni->sljedeci;
                pocetak=it2;
                break;
            }
            if(it2==pocetak && koliko==pamti){
                skup.insert(it2->ime);
                pamti=VratiVelicinuStringa(it2->ime);
                prethodni->sljedeci=it2->sljedeci;
                it2->sljedeci=nullptr;
                delete it2;
                it2=prethodni->sljedeci;
                pocetak=it2;
                koliko=1;
                break;
            }
             if(it2==prethodni && koliko==pamti){
                skup.insert(it2->ime);
                pamti=VratiVelicinuStringa(it2->ime);
                Dijete *p;
                for(p=pocetak;p!=prethodni;p=p->sljedeci){
                    if(p->sljedeci==prethodni){p->sljedeci=nullptr;break;}
                }
                prethodni->sljedeci=nullptr;
                delete prethodni;
                prethodni=p;
                prethodni->sljedeci=pocetak;
                it2=pocetak;
                koliko=1;
                break;
            }
            
             if(koliko<pamti){
                 koliko++;
                 if(it2==prethodni && koliko==pamti-1)
                 it2=it2->sljedeci;
                 else it2=it2->sljedeci;
                 
             }
            else {
                skup.insert(it2->ime);
                pamti=VratiVelicinuStringa(it2->ime);
                Dijete *p;
                for(p=pocetak;p!=it2;p=p->sljedeci){
                    if(p->sljedeci==it2)break;
                }
                p->sljedeci=it2->sljedeci;
                it2->sljedeci=nullptr;
                delete it2;
                it2=p->sljedeci;
                if(it2==pocetak)koliko=0;
                else koliko=1;
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
        if(imena_djece.size()%broj_timova!=0){
            if(skup.size()==br_djece_po_timu2 && nesh>=prvi_timovi){
                nesh++;
                vs.push_back(skup);
                skup.clear();
            }
            if(skup.size()==br_djece_po_timu1){
                 nesh++;
            vs.push_back(skup);
            skup.clear();
            }
        }
        
        if(distance(pocetak,prethodni)==0){
            skup.insert(pocetak->ime);
            vs.push_back(skup);
            pocetak->sljedeci=nullptr;
            delete pocetak;
            break;
        }
    }
    return vs;
}

int main ()
{
    try {
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
            for(string s:rezultat[i]){brojac++;if(brojac<rezultat[i].size())cout<<s<<", ";else cout<<s;}
            cout<<endl;
        }
    }
    catch(logic_error l){
        cout<<"Izuzetak: "<<l.what();
    }
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdexcept>
using namespace std;


map<string,set<int>> KreirajIndeksPojmova(string recenica)
{
    
for(int i=0;i<recenica.size();i++) {
    if(recenica[i]>='A' && recenica[i]<='Z') {
        recenica[i]+=32;
    }
}

//Prebaciti rijeci iz recenice u vektor rijeci iz recenice
    vector<string> rijeciURecenici;
    for(int i=0; i<recenica.size(); i++) {
        if((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='0' && recenica[i]<='9')) {
            string rijec;
            while(i<recenica.size() &&  ((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='0' && recenica[i]<='9'))) {
                rijec+=recenica[i];
                i++;
            }

            rijeciURecenici.push_back(rijec);
        }
    }
    
    map<string,set<int>> mapa;
    set<int> pamti_indekse;
    int pocetak=0,kraj=0;

// Hajmo naci substr iz rec i uporediti ga sa rijecju iz vektora rijeci
    for(int i=0; i<rijeciURecenici.size(); i++) {
        for(int j=0; j<recenica.size(); j++) {
            pocetak=0, kraj=0;
            if((recenica[j]>='a' && recenica[j]<='z') || (recenica[j]>='A' && recenica[j]<='Z') || (recenica[j]>='0' && recenica[j]<='9')) {
                pocetak=j;
                while((recenica[j]>='a' && recenica[j]<='z') || (recenica[j]>='A' && recenica[j]<='Z') || (recenica[j]>='0' && recenica[j]<='9')) {
                    j++;
                }
                kraj=j;
            }

            if(recenica.substr(pocetak,kraj-pocetak)==rijeciURecenici[i]) 
            mapa[rijeciURecenici[i]].insert(pocetak);
        }
    }


    return mapa;
}

set<int> PretraziIndeksPojmova(string rijec, map<string,set<int>> indeks_pojmova )
{
    if(indeks_pojmova.count(rijec)==1) return indeks_pojmova.find(rijec)->second;
    else throw logic_error("Unesena rijec nije nadjena!");
}

void IspisiIndeksPojmova(map<string,set<int>> mapa)
{
    for(auto it1=mapa.begin(); it1!=mapa.end(); it1++) {
        vector<int> skup;
        cout<<it1->first<<": ";
        for(auto it2=it1->second.begin(); it2!=it1->second.end(); it2++) {
            skup.push_back(*it2);
        }

        cout<<skup[0];
        for(int i=1; i<skup.size(); i++) {
            cout<<","<<skup[i];
        }

        cout<<endl;
    }
}

int main ()
{
    cout<<"Unesite tekst: ";
    string recenica;
    getline(cin,recenica);
    map<string,set<int>> mapa = KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(mapa);
    
    
        string rijec;
        do {
        cout<<"Unesite rijec: ";
        rijec="";
        getline(cin,rijec);
        if(rijec==".") break;
        try{
        set<int> pronadjena= PretraziIndeksPojmova(rijec,mapa);
        for(auto i: pronadjena) cout<<i<<" ";
        cout<<endl;
        
        
    }
    catch(logic_error greska) {
        cout<<greska.what()<<endl;
    }
        }while(rijec!=".");
    return 0;
}
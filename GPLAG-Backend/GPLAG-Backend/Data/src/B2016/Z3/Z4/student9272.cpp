/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stdexcept>
using std::cout;
using std::cin;
using std::vector;
using std::list;
using std::string;
using std::set;

int BrojSlova(string s){
    int brojac(0);
    for (auto i=0; i<s.size(); i++) {
        if (s.at(i)>='A' && s.at(i)<='Z') brojac++;
        else if (s.at(i)>='a' && s.at(i)<='z') brojac++;
        else if(s.at(i)>='0' && s.at(i)<='9') brojac++;
    }
    return brojac;
}

vector<set<string>> Razvrstavanje(vector<string> djeca, int broj_timova){
    if (broj_timova<1 || broj_timova>djeca.size()) throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    vector<set<string>> skup(broj_timova);
    list<string> lista;
    lista.resize(djeca.size());
    
    // KOPIRAMO VECTOR U LISTU
    
    auto j=lista.begin();
    for (auto i=djeca.begin(); i<djeca.end(); i++){
        *j=*i;
        j++;
    }
    
    // POSTAVLJAMO VELICINE KOJE CE TREBATI
    
    int n;
    int prvi_timovi;
    n=djeca.size();
    prvi_timovi = n%broj_timova;
    int clanovi_prvih_timova;
    clanovi_prvih_timova = n/broj_timova + 1 ;
    int preostali_timovi;
    preostali_timovi=broj_timova-prvi_timovi;
    int chlanovi_preostalih_timova;
    chlanovi_preostalih_timova=n/broj_timova;
    
    // POCINJEMO SA RAZVRSTAVANJEM
    
    auto poc(lista.begin());    auto kraj(--lista.end());  auto klizac(poc);
    for (int j(0);j<prvi_timovi; j++){
        for (int k(0); k<clanovi_prvih_timova; k++){
            
        
    
    //RACUNAMO BROJ SLOVA DJETETA PRED IZBACIVANJE
    int slova;
    slova=BrojSlova(*klizac);
    
    //SKLANJAMO PRVO DIJETE IZ KRUGA ALI PRIJE TOGA UVODIMO KLIZAC
   skup.at(j).insert(*klizac);
    if (klizac==poc) {
        poc++;
        klizac=lista.erase(klizac);
    } else if (klizac==kraj){
        kraj--;
        klizac=lista.erase(klizac);
        klizac=poc;
    } else {
        klizac=lista.erase(klizac);
    }
    slova--;
    //KRUZNA PETLJA ZA PRVE TIMOVE
    for (int i(0); i<slova; i++){
        if (klizac==kraj){
            klizac=poc;
        } else klizac++;
    }
}
}


    //KRUZNA PETLJA ZA PREOSTALE TIMOVE
    for (int j(prvi_timovi); j<prvi_timovi+preostali_timovi; j++){  
        for (int k(0); k<chlanovi_preostalih_timova; k++){
            int slova;
            slova=BrojSlova(*klizac);
       skup.at(j).insert(*klizac);
       if (klizac==poc){
           poc++;
           klizac=lista.erase(klizac);
       } else if (klizac==kraj) {
           kraj--;
           klizac=lista.erase(klizac);
           klizac=poc;
       } else {
           klizac=lista.erase(klizac);
       }
       slova--;
       for (int i(0); i<slova; i++){
           if (klizac==kraj) {
               klizac=poc;
           } else klizac++;
       }
}
}
    //VRACANJE SKUPA
    return skup;
    
}

int main ()
{try{
    cout << "Unesite broj djece: ";
    int br;
    cin >> br;
    cout << "Unesite imena djece: " << std::endl;
    vector<string> djeca;
    std::cin.ignore(10000,'\n');
    for (int i(0); i<br; i++){
        string s;
        std::getline(cin,s);
        djeca.push_back(s);
    }
    cout << "Unesite broj timova: ";
    int timovi;
    
    cin >> timovi;
    vector<set<string>> skup;
    skup=Razvrstavanje(djeca,timovi);
    for (int i(0); i<skup.size(); i++){
        cout << "Tim " << i+1 <<": ";
        int brojac(0);
        for (auto j=skup[i].begin(); j!=skup[i].end(); j++){
            brojac++;
          if (brojac==skup[i].size())  cout << *j << "";
          else cout << *j << ", ";
        }
     cout<<   std::endl;
    }
	return 0;
}catch(std::logic_error izuzetak){
    cout << izuzetak.what();
    return 0;
}
}
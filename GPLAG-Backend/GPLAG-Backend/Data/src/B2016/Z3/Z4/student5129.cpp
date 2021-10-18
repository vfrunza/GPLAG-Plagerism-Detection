/B2016/2017: Zadaća 3, Zadatak 4

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::set;
using std::list;

int PrebrojiIme(string s){
    int duzina(0);
    for(int i=0; i<s.length(); i++) if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) duzina++;
    return duzina-1;
}

vector<set<string>> Razvrstavanje(vector<string> imena, int br_timova){
    if(br_timova>imena.size() || br_timova<1) throw std::logic_error("Razvrstavanje nemoguce");
    
    // Formiranje liste u koju prekopiramo sva imena
    list<string> spisak;
    for(auto &ime : imena) spisak.push_back(ime);
    
    // Gledamo koji tim ima koliko clanova
    int veci, manji(spisak.size() / br_timova), brvecih(spisak.size()%br_timova);
    // Ako nisu svi iste velicine
    if(spisak.size()%br_timova){
        veci = (spisak.size() / br_timova) + 1;
        manji = (spisak.size() / br_timova);
    }
    
    // Vektor koji sadrzi broj clanova svih timova
    vector<int> clanovi(br_timova);
    for(int i=0; i<br_timova; i++){
        while(brvecih){
            clanovi[i]=veci;
            i++;
            brvecih--;
        }
        clanovi[i]=manji;
    }
    
    vector<set<string>> timovi(br_timova);
    // Brojimo koliko prvi clan ima slova
    int brojac(PrebrojiIme(*(spisak.begin())));
    // Ubacujemo prvog u prvi clan skupa (tj. prvi tim) i izbacujemo iz liste
    timovi[0].insert(*(spisak.begin()));
    spisak.erase(spisak.begin());
    
    // Tim u koji trenutno ubacujemo
    int i(0);
    // Krecemo se u krug dok ne razvrstamo svu djecu
    auto it1(spisak.begin());
    auto it2(it1);
    while(spisak.size()){
        // Kruzenje
        auto prvi(spisak.begin());
        auto zadnji(spisak.end());
        while(brojac){
            it1++;
            // Ako sko dosli iza kraja, trebamo onda biti na pocetku ponovo
            if(it1==zadnji) it1=prvi;
            brojac--;
        }
        
        // Broji koliko slova ima clan koji se izbacuje
        brojac=PrebrojiIme(*it1);
        
        // Dodaje ime u skup ako tim nije pun
        if(timovi[i].size()<clanovi[i]) timovi[i].insert(*it1);
        // Ako je tim popunjen, dodaje ali u sljedeci tim
        else{
            i++;
            timovi[i].insert(*it1);
        }
        it2=it1;
        // Brise clan iz liste
        it1=spisak.erase(it2);
        if(it1==spisak.end()) it1=spisak.begin();
    }
    
    return timovi;
}

int main (){
    cout << "Unesite broj djece: ";
    int br_djece;
    cin >> br_djece;
    
    cin.ignore(10000, '\n');
    
    cout << "Unesite imena djece: ";
    vector<string> imena;
    for(int i=0; i<br_djece; i++){
        string ime;
        getline(cin, ime);
        imena.push_back(ime);
    }
    
    cout << std::endl;
    
    cout << "Unesite broj timova: ";
    int br_timova;
    cin >> br_timova;
    
    vector<set<string>> razvrstani;
    try{
        razvrstani = Razvrstavanje(imena, br_timova);
    } catch(std::logic_error greska){
        cout << "Izuzetak: " << greska.what();
        return 0;
    }
    
    for(int i=0; i<br_timova; i++){
        cout << "Tim " << i+1 << ": ";
        auto j(razvrstani[i].begin());
        auto kraj(razvrstani[i].end()--);
        kraj--;
        while(j!=kraj){
            cout << *j << ", ";
            j++;
        }
        cout << *j << std::endl;;
    }
    
	return 0;
}
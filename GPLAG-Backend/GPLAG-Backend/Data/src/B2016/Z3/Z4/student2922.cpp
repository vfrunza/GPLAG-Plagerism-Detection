/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>
using namespace std;

int ImeDuzina(string s){
    int duzina{0};
    for(int i{0}; i<s.length(); i++ ) if ((s[i] >='A' && s[i]<='Z')
    || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9') ) duzina++;
    return duzina;
}

vector<set<string>> Razvrstavanje( vector<string> imena, int k){
    
    if(k<1 || k>imena.size()) throw logic_error("Razvrstavanje nemoguce");
    
    int n { (int)imena.size() };
    vector<int> vel_skup(k);
    //Formiranje velicine skupova
    for(int i{0}; i<k; i++){
        if(i<n%k) vel_skup[i] = n/k+1;
        else vel_skup[i] = n/k;
    }
    list<string> lista;
    for(int i{0}; i<n; i++) lista.push_back(imena[i]);
    //Sad u listi imamo svu djecu
    vector<set<string>> timovi(k);
    
    
        int pozicija{0}, pomak;
        for(int selektor_tima {0}; selektor_tima<k; selektor_tima++){
            for(int selektor_d{0}; selektor_d<vel_skup[selektor_tima]; selektor_d++ ){
                //selektor_d(ijeteta) ce se povecati tek kada dijete udje u tim
                if(selektor_d==0 && selektor_tima==0) pomak=0;
                auto poc = lista.begin(); advance(poc,pozicija);
                
                //Sad ubacujemo u "timovi" ono na sto poc pokazuje
                timovi[selektor_tima].insert(*poc);
                
                //Nalazimo mu duzinu
                //Umanjenu za jedan jer poc ce vec da predje
                //Na iduci
                pomak = ImeDuzina(*poc)-1;
                
                //A to isto izbacujemo iz liste
                poc = lista.erase(poc);
                if(lista.size()==0) break;
                
                //Potom pomak preracunavamo !!!!
                if(pozicija+pomak>=lista.size()) pozicija = (pozicija+pomak)%lista.size();
                else pozicija = pozicija+pomak;
                
                
            } 
        }
    return timovi;
    
}


int main (){
try{
    cout << "Unesite broj djece: ";
    int n;
    cin >>n;
    cin.ignore(100000,'\n');
    cout << "Unesite imena djece: "<<endl;
    std::vector<string> djeca(n);
    for (int i{0}; i<n; i++) getline(cin, djeca[i]);
    cout << "Unesite broj timova: ";
    int k; cin >> k;

    auto timovi = Razvrstavanje(djeca, k);
    for(int i{0}; i<k; i++){
        cout << "Tim "<<i+1<<": ";
        auto it_skup = timovi[i].begin();
        for(; it_skup!=timovi[i].end(); it_skup++) if (it_skup==prev(timovi[i].end())) cout << *it_skup; else cout << *it_skup<<", ";
        cout << endl;
     }
}catch(logic_error e){ cout <<"Izuzetak: "<<e.what(); }
	return 0;
}
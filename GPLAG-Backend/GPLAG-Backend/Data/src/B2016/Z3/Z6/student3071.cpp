/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <stdexcept>
#include <string>
#include <set>
#include <vector>
#include <memory>
using namespace std;

struct Dijete {
    string ime;
    shared_ptr <Dijete> sljedeci;
};

int ImeDuzina (string s){
    int duzina{0};
    for(int i{0}; i<s.length(); i++) if( (s[i]>='A' && s[i]<='Z') ||
    (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) duzina++;
    return duzina;
}

vector<set<string>> Razvrstavanje(std::vector<string> imena, int k){
    if(k<1 || k>imena.size()) throw logic_error("Razvrstavanje nemoguce");
    int n{(int)imena.size()};
    vector <int> vel_skup(k);
    for(int i{0}; i<k; i++){
        if(i<n%k) vel_skup[i] = n/k+1;
        else vel_skup[i] = n/k;
    }
    
    //Sad formiramo nasu "listu" s pametnim pokovima
    shared_ptr<Dijete> pocetak{nullptr};
    shared_ptr<Dijete> prethodni{nullptr};
    for(int i{0}; i<n; i++){
        shared_ptr<Dijete> novi (new Dijete);
        novi->ime = imena[i]; novi->sljedeci = nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
    }
    prethodni ->sljedeci = pocetak;
    
    auto glavni =pocetak;
    vector<set<string>> timovi(k);
    int pomak;
    int brojac{0};
    for(int selektor_tima{0}; selektor_tima<k; selektor_tima++){
        for(int selektor_d {0}; selektor_d<vel_skup[selektor_tima]; selektor_d++){
            if(selektor_d==0 && selektor_tima==0){
                pomak = ImeDuzina(glavni->ime)-1;
                timovi[selektor_tima].insert(glavni->ime);
                auto it = glavni;
                for(;it->sljedeci!=glavni; it = it->sljedeci);
                auto pom_za_bris = it->sljedeci;
                it->sljedeci = (it->sljedeci)->sljedeci;
                pom_za_bris = nullptr;
                glavni = it->sljedeci;
                for(int i{0}; i<pomak; i++, glavni=glavni->sljedeci);
                
                continue;
            }
            
            pomak = ImeDuzina(glavni->ime)-1;
            timovi[selektor_tima].insert(glavni->ime);
            auto it = glavni;
            for(;it->sljedeci!=glavni; it = it->sljedeci);
            auto pom_za_bris = it->sljedeci;
            it->sljedeci = (it->sljedeci)->sljedeci;
            pom_za_bris = nullptr;
            glavni = it->sljedeci;
            for(int i{0}; i<pomak; i++, glavni = glavni->sljedeci);
            if(selektor_tima == k-1 && selektor_d==vel_skup[selektor_tima]-1) glavni->sljedeci=nullptr;
        }
    }
    
    
    
    
    return timovi;
}

int main (){
    try{
        cout << "Unesite broj djece: ";
        int n;
        cin>>n;
        cin.ignore(1000000,'\n');
        cout << "Unesite imena djece: "<<endl;
        std::vector<string> djeca(n) ;
        for(int i{0}; i<n; i++) getline(cin,djeca[i]);
        cout << "Unesite broj timova: ";
        int k; cin>>k;
        
        
        auto timovi = Razvrstavanje(djeca,k);
        for(int i{0}; i<k; i++){
            cout << "Tim "<<i+1<<": ";
            auto it_skup = timovi[i].begin();
            for(;it_skup!=timovi[i].end(); it_skup++) if(it_skup == prev(timovi[i].end()))cout << *it_skup;
            else cout << *it_skup<<", ";
            cout << endl;
        }
        
        
        
    }catch(logic_error e){ cout<<"Izuzetak: "<<e.what(); }
	return 0;
}
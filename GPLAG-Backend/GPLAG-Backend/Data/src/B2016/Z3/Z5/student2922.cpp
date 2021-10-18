/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
using namespace std;

struct Dijete{
    string ime;
    Dijete *sljedeci {nullptr};
};

int ImeDuzina (string s){
    int duzina{0};
    for(int i{0}; i<s.length(); i++) if((s[i]>='A' && s[i]<='Z')
    || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) duzina++;
    return duzina;
}
vector<set<string>> Razvrstavanje(vector<string> imena, int k){
    if(k<1 ||k>imena.size()) throw logic_error("Razvrstavanje nemoguce");
    
    int n{(int)imena.size()};
    vector <int> vel_skup(k);
    for(int i{0}; i<k; i++){
        if(i<n%k) vel_skup[i] = n/k+1;
        else vel_skup[i] = n/k;
    }
    //Sad mi pravimo nasu single-linked listu
    //Od elemenata vektora "imena"
    Dijete *pocetak(nullptr), *prethodni;
    for(int i{0};i<n;i++){
        Dijete *novi(new Dijete);
        novi->ime = imena[i]; novi->sljedeci = nullptr;
        if(!pocetak) pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
    }
    
    prethodni->sljedeci = pocetak;
    //Sad pokazuju ukrug!!!
    
    
    //OR SO IT SEEMS...
    //cout << endl;
    //int l {0};
    //for(auto p = pocetak; p!=nullptr && l<15; l++, p=p->sljedeci){ cout <<p->ime<< " "; }
    //cout << endl;
    auto glavni = pocetak;
    int broj_elemenata{(int)imena.size()};
    vector<set<string>> timovi(k);
    int pomak;
    for(int selektor_tima {0}; selektor_tima<k; selektor_tima++){
        for(int selektor_d {0}; selektor_d<vel_skup[selektor_tima];selektor_d++){
            if(selektor_d==0 && selektor_tima==0 && glavni == pocetak){
                pomak = ImeDuzina(glavni->ime)-1;
                timovi[selektor_tima].insert(glavni->ime);
                auto it = glavni;
                for(; it->sljedeci!=glavni; it = it->sljedeci );
                auto pom_za_bris = it->sljedeci;
                it->sljedeci=(it->sljedeci)->sljedeci;
                delete pom_za_bris;
                glavni = it->sljedeci;
                
                for(int i{0}; i<pomak; i++, glavni = glavni->sljedeci);
                broj_elemenata--;
                continue;
            }
            pomak= ImeDuzina(glavni->ime)-1;
            timovi[selektor_tima].insert(glavni->ime)
            ;
           
           
            auto it = glavni;
            for(;it->sljedeci!=glavni; it = it->sljedeci);
            auto pom_za_bris = it->sljedeci;
            it->sljedeci = (it->sljedeci)->sljedeci;
            
            //Sad moramo izbaciti element na koji pokazuje glavni 
            //iz nase "liste"
            
            
            glavni = it->sljedeci;
            
            for(int i{0}; i<pomak; i++, glavni = glavni->sljedeci)
            ;
            
            delete pom_za_bris;
            
            
            broj_elemenata--;
        }
    }

    return timovi;
    
}
int main (){
try{
    
    cout << "Unesite broj djece: ";
    int n;
    cin >>n;
    cin.ignore(1000000,'\n');
    cout << "Unesite imena djece: "<<endl;
    vector<string> djeca(n);
    for (int i{0}; i<n ; i++ ) getline (cin, djeca[i]);
    cout << "Unesite broj timova: ";
    int k; cin >> k;
 
    auto timovi = Razvrstavanje(djeca,k);
    for (int i{0}; i<k; i++){
        cout <<"Tim "<<i+1<<": ";
        auto it_skup = timovi[i].begin();
        for(; it_skup!=timovi[i].end(); it_skup++) if (it_skup==prev(timovi[i].end())) cout << *it_skup;
        else cout <<*it_skup<<", ";
        cout <<endl;
    }
    
} catch (logic_error e){cout <<"Izuzetak: "<< e.what() ;}
	return 0;
}
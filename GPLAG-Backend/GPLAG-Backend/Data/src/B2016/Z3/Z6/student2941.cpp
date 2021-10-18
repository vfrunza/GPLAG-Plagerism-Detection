/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <stdexcept>
#include <new>
#include <memory>

using namespace std;


struct Dijete{
    string ime;
    shared_ptr<Dijete> sljedeci=nullptr;
};

template <typename T>
set<string> NapraviTim(T &pocetak,T &prethodni,int n) {
    
    set<string> tim;
    for(int i(0);i<n;i++) {
        tim.insert(pocetak->ime);
        if(pocetak==prethodni) {                //specijalni slucaj kada je n=1 a ujedno to i jedini preostali elemenat
            pocetak->sljedeci=nullptr;
            pocetak=nullptr;
            prethodni=nullptr;
            
            return tim;
        }
        int j=0,br=0;
        while(j<pocetak->ime.length()) {
            if((pocetak->ime[j]>='a' && pocetak->ime[j]<='z') || (pocetak->ime[j]>='A' && pocetak->ime[j]<='Z') || (pocetak->ime[j]>='0' && pocetak->ime[j]<='9')) br++;
            j++;
        }
        prethodni->sljedeci=pocetak->sljedeci;
        pocetak=prethodni->sljedeci;
        for(int k=br;k>1;k--) {
            pocetak=pocetak->sljedeci;
            prethodni=prethodni->sljedeci;
        }
    }
    
    return tim;
}

vector<set<string> > Razvrstavanje(vector<string> imena, int n) {
    
    if(n<1 || n>imena.size()) throw logic_error ("Razvrstavanje nemoguce");
    
    shared_ptr<Dijete> kraj;
    shared_ptr<Dijete> pocetak=nullptr;
    
    for(int i(0);i<imena.size();i++) {
        
        shared_ptr<Dijete> novo(new Dijete);
        novo->ime=imena[i];
        if(!pocetak) pocetak=novo;
        else kraj->sljedeci=novo;
        if(i+1==imena.size()) novo->sljedeci=pocetak->sljedeci;
        kraj=novo;
        
    }
    
    vector<set<string> > PovratnaVrijednost;
    int k=imena.size()%n;
    int V=imena.size()/n +1;
    int M=imena.size()/n;
    for(int i(0);i<n;i++) {
        if(i<k) {
            PovratnaVrijednost.push_back(NapraviTim(pocetak,kraj,V));
        }
        else PovratnaVrijednost.push_back(NapraviTim(pocetak,kraj,M));
    }
    return PovratnaVrijednost;
}

int main ()
{
    cout << "Unesite broj djece: ";
    int n;
    cin >>n;
    vector<string> imena;
    cout<< "Unesite imena djece: ";
    string ime;
    getline(cin,ime);
    for(int i(0);i<n;i++) {
        
        getline(cin,ime);
        imena.push_back(ime);
        
    }
    cout << "\nUnesite broj timova: ";
    int k; cin>>k;
    try{
        vector<set<string> > timovi=Razvrstavanje(imena,k);
    
    for(int i(0);i<k;i++) {
        cout<< "Tim "<<i+1<<": ";
        auto it=timovi[i].begin();
        auto it2=timovi[i].end();
        it2--;
        while(it!=timovi[i].end()) {
            if(it==it2) { cout<<*it; break; }
            cout<<*it<<", ";
            it++;
        }
        cout<<endl;
    }
    }catch(logic_error e) { cout<<"Izuzetak: "<< e.what(); return 0; }
	return 0;
}
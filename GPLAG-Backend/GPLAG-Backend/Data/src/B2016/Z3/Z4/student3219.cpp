/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <utility>
#include <set>
#include <stdexcept>

using namespace std;

template <typename T>
set<string> NapraviTim(list<string> &imena, int n, T &it) {
    
    set<string> tim;
    for(int i(0);i<n;i++) {
        tim.insert(*it);
        int j=0,br=0;
        while(j<(*it).length()) {
            if(((*it)[j]>='a' && (*it)[j]<='z') || ((*it)[j]>='A' && (*it)[j]<='Z') || ((*it)[j]>='0' && (*it)[j]<='9')) br++;
            j++;
        }
        it=imena.erase(it);
        
        if(imena.size()==0) break;
        if(it==imena.end()) it=imena.begin();
        
        for(int k=br;k>1;k--) {
            if(it==imena.end()) {
                it=imena.begin();
                if(imena.size()==1) break;
                
            }
            it++;
            
            if(it==imena.end()) {
                it=imena.begin();
            }
        }
    }
    
    return tim;
}

vector<set<string> > Razvrstavanje(vector<string> imena, int n) {
    
    if(n<1 || n>imena.size()) throw logic_error ("Razvrstavanje nemoguce");
    list<string> ListaImena;
    for(int i(0);i<imena.size();i++) {
        ListaImena.push_back(imena[i]);
    }
    vector<set<string> > PovratnaVrijednost;
    int k=imena.size()%n;
    int V=imena.size()/n +1;
    int M=imena.size()/n;
    auto it=ListaImena.begin();
    for(int i(0);i<n;i++) {
        if(i<k) {
            PovratnaVrijednost.push_back(NapraviTim(ListaImena,V,it));
        }
        else PovratnaVrijednost.push_back(NapraviTim(ListaImena,M,it));
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
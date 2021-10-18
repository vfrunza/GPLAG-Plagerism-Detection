/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>



using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;
using std::getline;
using std::set;

struct Dijete{
    string ime;
    Dijete *sljedeci;
};

vector<set<string>> Razvrstavanje (vector<string> imena, int br_tim){
    if(br_tim<1 || br_tim>imena.size())throw logic_error("Razvrstavanje nemoguce");

    
    Dijete *pocetak(nullptr), *prethodni;
    
    for(int i = 0; i<imena.size(); i++){
        
        if(i==imena.size()-1){
            Dijete *novi(new Dijete);
            novi->ime = imena[i];
            novi->sljedeci = nullptr;
            
            if(!pocetak)pocetak = novi;
            else{prethodni->sljedeci = novi;}
            prethodni = novi;
            
            novi->sljedeci = pocetak;
            continue;
        }
        Dijete * novi (new Dijete);
        novi->ime = imena[i];
        novi->sljedeci = nullptr;
        
        if(!pocetak)pocetak = novi;
        else{prethodni->sljedeci = novi;}
        prethodni = novi;
    }
    
    int broj_clanova = imena.size()/br_tim;
    vector<int> velicina_tima(br_tim, broj_clanova);
    
    int br_vecih_timova = imena.size()%br_tim;
    
    for(int k=0; k<br_vecih_timova; k++){
        velicina_tima[k] = broj_clanova + 1;
    }
    
    vector<set<string>> timovi(br_tim);
    
    for(int i=0; i<br_tim; i++){
        
        set<string> tim;
        
        for(int j=0; j<velicina_tima[i]; j++){
            
            if(i==0 && j==0){
                tim.insert(pocetak->ime);
                string ime = pocetak->ime;
                
                int pomjeranje = 0;
                for(int l=0; l<ime.length(); l++){
                    if((ime[l]>='A' && ime[l]<='Z') || (ime[l]>='a' && ime[l]<='z') || (ime[l]>='0' && ime[l]<='9'))pomjeranje++;
                    else continue;
                }
                
                prethodni->sljedeci = pocetak->sljedeci;//brisanje
                delete pocetak;
                
                if(pocetak!=prethodni)pocetak = prethodni->sljedeci;
                
                
               for(int l=0; l<pomjeranje-1; l++){
                    pocetak = pocetak->sljedeci;
                    prethodni = prethodni ->sljedeci;
                }
                
                continue;
                
            }
            
            tim.insert(pocetak->ime);
            string ime = pocetak->ime;
            
            int pomjeranje = 0;
            for(int l=0; l<ime.length(); l++){
                    if((ime[l]>='A' && ime[l]<='Z') || (ime[l]>='a' && ime[l]<='z') || (ime[l]>='0' && ime[l]<='9'))pomjeranje++;
                    else continue;
                }
                
            prethodni->sljedeci = pocetak->sljedeci;
            delete pocetak;
            
            if(pocetak!=prethodni){
                pocetak= prethodni->sljedeci;
            
            for(int m=0; m<pomjeranje-1; m++){
                prethodni=prethodni->sljedeci;
                pocetak=pocetak->sljedeci;
                
            }
            }
        }
        
        timovi[i] = tim;
    }
    
    return timovi;
}

int main ()
{
    try{
        cout<<"Unesite broj djece: ";
        int n;
        cin>>n;
        vector<string> imena;
        cout<<"Unesite imena djece: "<<endl;
        cin.ignore(1000,'\n');
        for(int i=0; i<n; i++){
            string ime;
            getline(cin,ime);
            imena.push_back(ime);
        }
        
        int br_tim;
        cout<<"Unesite broj timova: ";
        cin>>br_tim;
        
        auto konacni = Razvrstavanje(imena, br_tim);
        
        for(int i=0; i<br_tim; i++){
            cout<<"Tim "<<i+1<<": ";
            
            for(auto x : konacni[i]){
                if(x==*(--konacni[i].end())){cout<<x; break;}
                cout<<x<<", ";
            }
            cout<<endl;
        }
        
    }
    
    catch(logic_error i){
        cout<<"Izuzetak: "<<i.what();
    }
    
	return 0;
}
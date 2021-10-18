/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>
using namespace std;

struct Dijete{
    
    string ime;
    Dijete *sljedeci;

};

int DajBrojSlova(string s){
    
    int broj_slova = 0;
    for(int i = 0 ; i < s.length() ; i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') ){
            broj_slova++;
        }
    }
    
    return broj_slova;
}

vector<set<string>> Razvrstavanje(vector<string> v, int broj_timova){
    
    if(broj_timova < 1 || broj_timova > v.size()){
        throw logic_error("Razvrstavanje nemoguce");
    }
    
    vector<set<string>> timovi(broj_timova);
    
    Dijete *poc = nullptr;
    Dijete *pred = nullptr;
    for(int i = 0 ; i < v.size() ; i++){
            
        Dijete *pom = new Dijete;
        if(!poc){
            poc = pom;
        }
        else{
            pred -> sljedeci = pom;
        }
        if(i != v.size() - 1){
            pom -> sljedeci = nullptr;
        }
        else{
            pom -> sljedeci = poc;
        }
        pred = pom;
        pom -> ime = v[i];
            
    }
    
    Dijete *p = poc;
    int brojac = 0 , tim = 0;
    for(int i = 0 ; i < v.size() ; i++){
        
        brojac++;
        int broj_slova = DajBrojSlova(p -> ime);
        
        Dijete *predhodnik = p;
        while(predhodnik -> sljedeci != p){
            predhodnik = predhodnik -> sljedeci;
        }
        predhodnik -> sljedeci = p -> sljedeci;
        Dijete *brisanje = p;//
        //p = p -> sljedeci;
        timovi[tim].insert(p -> ime);
        for(int k = 0 ; k < broj_slova ; k++){
            p = p -> sljedeci;
        }
        delete brisanje;
        
        
        
        
        if(brojac > v.size() / broj_timova){
            tim++;
            brojac = 0;
        }
        if(brojac == v.size() / broj_timova){
            if(tim < v.size() % broj_timova){
                broj_slova = DajBrojSlova(p -> ime);
                continue;
            }
            tim++;
            brojac = 0;

        }
        
    }
    
    return timovi;
}

int main ()
{
    //vector<string> v{"Damir", "Ana" , "Muhamed" , "Marko" , "Ivan" , "Mirsad" , "Nikolina" , "Alen" , "Jasmina" , "Merima"};
    //Razvrstavanje(v , 3);
    
    vector<string> v;
    cout << "Unesite broj djece: ";
    int broj;
    cin >> broj;
    cout << "Unesite imena djece: " << endl;
    cin.ignore(1000 , '\n');
    for(int i = 0 ; i < broj ; i++){
        string s;
        getline(cin,s);
        v.push_back(s);
    }
    cout << "Unesite broj timova: ";
    cin >> broj;
    
    try{
        vector<set<string>> pom = Razvrstavanje(v , broj);
        
        /*for(int i = 0 ; i < broj ; i++){
            cout << "Tim " << i + 1 << ": ";
            for(auto x : pom[i]) std::cout << x << ", ";
            cout << endl;
            
        }*/
        
        for(int i = 0 ; i < broj ; i++){
            
            int broj = 0;
            for(auto it = pom[i].begin() ; it != pom[i].end() ; it++){
                broj++;
            }
            
            cout << "Tim " << i + 1 << ": ";
            int brojac = 0;
            for(auto it = pom[i].begin() ; it != pom[i].end() ; it++){
                brojac++;
                if(broj == brojac){
                    cout << *it << endl;
                }
                else{
                    cout << *it << ", ";
                }
            }
            
        }
    }
    catch(logic_error e){
        cout << "Izuzetak: " << e.what() << endl;
    }
    
	return 0;
}
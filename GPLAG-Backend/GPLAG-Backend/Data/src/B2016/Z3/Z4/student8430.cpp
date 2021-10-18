/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>
using namespace std;

void Ispisi(list<string> lista){
    auto it = lista.begin();
    while(it != lista.end()){
        cout << *it << " , ";
        it++;
    }
    cout << endl;
}

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
    list<string> lista;
    list<string>::iterator it = lista.begin();
    for(int i = 0 ; i < v.size() ; i++){
        lista.insert(it , v[i]);  
    }
    
    int tim = 0, brojac = 0;
    list<string>::iterator it1 = lista.begin();
    for(int i = 0 ; i < v.size(); i++){
        
        
        brojac++;
        int broj_slova = DajBrojSlova(*it1);
        string p = *it1;
        timovi[tim].insert(p);
        it1 = lista.erase(it1);
        
        if(it1 == lista.end()){
            it1 = lista.begin();
        }
        for(int j = 0 ; j < broj_slova - 1 ; j++){
            
            it1++;
            if(it1 == lista.end()){
                it1 = lista.begin();
            }
        }
        
        if(brojac > v.size() / broj_timova){
            tim++;
            brojac = 0;
        }
        if(brojac == v.size() / broj_timova){
            if(tim < v.size() % broj_timova){
                broj_slova = DajBrojSlova(*it1);
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
    //vector<string> v{"Damir", "Ana" , "Muhamed" , "Marko" , "Ivan" , "Mirsad" , "Nikolina" , "Alen" , "Jasmin" , "Merima"};
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
        return 0;
    }
    
    
    //for(auto x : multiskup) std::cout << x << " ";
    
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>

using namespace std;

typedef map<string, set<int>> tip;

tip KreirajIndeksPojmova(string s){
    
    if(s.empty()) return tip ();
    s.push_back(' ');
    tip rez;
    
    int brojac(0);
    
    for(auto it(s.begin()); it != s.end(); it++){
        
        string tmp;
        
        while(it != s.end() && *it == ' '){
            
            it++;
            brojac++;
        }
        
        if(it == s.end()) break;
        
        int pom(brojac);
        
        while(it != s.end() && *it != ' '){
            
            tmp.push_back(*it);
            it++;
            pom++;
        }
            rez[tmp].insert(brojac);
            brojac = pom;
            brojac++;
            
        }
        return rez;
    }
    
 set<int> PretraziIndeksPojmova(string s, tip m){
        
        auto biter(m.find(s));
        if(biter == m.end()) throw logic_error("Unesena rijec nije nadjena!");
        return biter->second;
        
    }
    
void IspisiIndeksPojmova(tip t){
    
    for(auto it(t.begin()); it != t.end(); it++){
        cout << it -> first <<": ";
        int temp(1);
        
        for(auto it2(it->second.begin()); it2 != it -> second.end(); it2++, temp++){
            cout << *it2;
            if(temp != (int)it->second.size()) cout << ",";
        }
            cout << endl;
        
    }
}
    
    

int main ()
{
    
    string recenica;
    cout << "Unesite tekst: ";
    
    getline(cin, recenica);
    
    auto kreiraj = KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(kreiraj);
    
    for(;;){
        
        string s2;
        
        cout << "Unesite rijec: ";
        getline(cin, s2);
        if(s2 == ".") break;
        try{
            
        
        for(auto x : PretraziIndeksPojmova(s2, kreiraj)) cout << x << " ";
        cout << endl;
        
        }catch(logic_error wat){
            
            cout << wat.what() << endl;
        }
    }
	return 0;
}
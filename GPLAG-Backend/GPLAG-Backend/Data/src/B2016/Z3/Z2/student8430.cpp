/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
using namespace std;

bool provjeraInterpukcije(char znak){
    
    if((znak >= ' ' && znak <= '/') || (znak >= ':' && znak <= '@')){
        return false;
    }
    return true;
    
}

map<string,set<int>> KreirajIndeksPojmova(string s){

    map<string,set<int>> m;
    string pom = s;
    for(int i = 0 ; i < s.length() ; i++){
        pom[i] = tolower(pom[i]);
    }
    
    pom = "  " + pom + "  ";
    for(int i = 1 ; i < pom.length() ; i++){
    
        //if((pom[i - 1] == ' ' && pom[i] != ' ')){
        if(provjeraInterpukcije(pom[i - 1] == false) && provjeraInterpukcije(pom[i]) == true){
            
            int p = i;
            //while(pom[p] != ' '){
            while(provjeraInterpukcije(pom[p]) == true){
                p++;
            }
            string rijec = pom.substr(i , p - i);
            m[rijec];
            auto t = m.find(rijec);
            t -> second.insert(i - 2);
            i = p;
            
        }
        
    }

    return m;
}

set<int> PretraziIndeksPojmova(string s, map<string,set<int>> m){
    
    auto t = m.find(s);
    if(t != m.end()){
        return t-> second;
    }
    throw logic_error{"Pojam nije nadjen"};
    
}

void IspisiIndeksPojmova(map<string,set<int>> m){
    
    for(auto t = m.begin() ; t != m.end() ; t++){
        
        cout << t -> first << ": ";
        int b = 0;
        for(auto pom = t -> second.begin() ; pom != t -> second.end() ; pom++){
            b++;
        }
        int k = 0;
        for(auto pom = t -> second.begin() ; pom != t -> second.end() ; pom++){
            k++;
            if(k == b){
                cout << *pom;
            }
            else{
                cout << *pom << ",";
            }
        }
        cout << endl;
        
    }
    
}

int main ()
{

   
    cout << "Unesite tekst: ";
    string s;
    getline(cin , s);
    auto pojmovi = KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(pojmovi);
    while(1){
        cout << "Unesite rijec: ";
        string unos;
        getline(cin,unos);
        if(unos.length() == 1 && unos[0] == '.'){
            break;
        }
        try{
            set<int> skup = PretraziIndeksPojmova(unos, pojmovi);
            for(auto it = skup.begin() ; it != skup.end() ; it++){
                cout << *it << " ";
            }
            cout << endl;
        }
        catch(logic_error e){
            cout << "Unesena rijec nije nadjena!" << endl;
        }
 
    }
    
    

	return 0;
}
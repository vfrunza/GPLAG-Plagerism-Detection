/B2016/2017: Zadaća 3, Zadatak 2

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>

using std::string;
using std::map;
using std::set;
using std::cin;
using std::cout;

string PretvoriUMala(string s){
    for(int i=0; i<s.length(); i++){
        if(s[i]>='A' && s[i]<='Z') s[i]=tolower(s[i]);
    }
    return s;
}

map<string, set<int>> KreirajIndeksPojmova(string tekst){
    map<string, set<int>> index;
    // Pretvorimo u mala slova tako da se ne razlikuju
    string s(PretvoriUMala(tekst));
    int i(0);
    int pocetak;
    int duzina(0);
    string rijec;
    while(i<s.length()){
        // Resetovanje duzine za novu rijec
        duzina=0;
        
        // Prelazi sve non-rijec karaktere
        while(i<s.length() && (s[i]<'a' || s[i]>'z') && (s[i]<'0' || s[i]>'9')) i++;
        
        // Sada gledamo rijec, na cijem smo pocetku trenutno
        pocetak=i;
        // Mjerenje duzine rijeci
        while(i<s.length() && ((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))){
            i++;
            duzina++;
        }
        
        // Pokupimo trenutnu rijec
        rijec=s.substr(pocetak, duzina);
        
        // Ubacimo je u mapu
        index[rijec].insert(pocetak);
    }
    
    return index;
}

set<int> PretraziIndeksPojmova(string rijec, map<string, set<int>> index){
    // Pretvori rijec u mala slova prije provjere
    string temp(PretvoriUMala(rijec));
    // Ako rijec nije u indeksu
    if(!index.count(temp)) throw std::logic_error("Pojam nije nadjen");
    
    return index[rijec];
}

void IspisiIndeksPojmova(map<string, set<int>> index){
    for(auto it(index.begin()); it!=index.end(); it++){
        cout << it->first << ": ";
        auto kraj((it->second).end()--);
        kraj--;
        auto i2((it->second).begin());
        // Sve osim zadnjeg da nema zareza poslije zadnjeg
        while(i2!=kraj){
            cout << *i2 << ",";
            i2++;
        }
        // Ispisuje zadnji bez zareza
        cout << *i2 << std::endl;
    }
}

int main (){
    // Unos
    cout << "Unesite tekst: ";
    string recenica;
    getline(cin, recenica);
    
    map<string, set<int>> index(KreirajIndeksPojmova(recenica));
    IspisiIndeksPojmova(index);
    
    for(;;){
        cout << "Unesite rijec: ";
        string rijec;
        cin >> rijec;
        if(rijec==".") break;
        
        try{
            PretraziIndeksPojmova(rijec, index);
            for(int x : index[rijec]) cout << x << " ";
        } catch(std::logic_error greska){
            cout << "Unesena rijec nije nadjena!";
        }
        cout << std::endl;
    }
    // Testni:    123   12    123     13     13    12    123
	return 0;
}
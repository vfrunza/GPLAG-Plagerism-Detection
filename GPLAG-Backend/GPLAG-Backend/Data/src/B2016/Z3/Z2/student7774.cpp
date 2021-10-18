#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::string;
using std::set;

typedef map<string,set<int>> Mapa;

bool SlovoCifra(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    return false;    
}

void UMala (string &rijec) {
    
    for (auto it = rijec.begin(); it != rijec.end(); it++) {
        if(*it >= 'A' && *it <= 'Z')
            *it += 'a' - 'A';
    }
}

Mapa KreirajIndeksPojmova(string str) {
    
    Mapa mapa;
    string rijec;
    bool ulaz(true);
    
    for (auto p = str.begin(); p != str.end(); p++) {
        if((ulaz && SlovoCifra(*p)) || (SlovoCifra(*p) && !SlovoCifra(*(p-1)))) {
            ulaz = false;        
            auto q(p);
            
            while (SlovoCifra(*q) && q != str.end()) {
                q++;
            }
            rijec = str.substr(p-str.begin(), q-p);
            UMala(rijec);
            auto it(mapa.find(rijec));
            if(it == mapa.end()) {
                int broj(p-str.begin());
                std::set<int> skup = {broj};
                mapa.insert(std::make_pair(rijec, skup));
            } else { 
                it->second.insert(p-str.begin());
            }    
            p = --q;
        }
        ulaz = false;
    }
     
    return mapa;
}

set<int> PretraziIndeksPojmova(string rijec, Mapa mapa) {
    
    auto it(mapa.find(rijec));
    
    if(it == mapa.end())
        throw std::logic_error ("Pojam nije nadjen");
        
    return it->second;    
}

void IspisiIndeksPojmova (Mapa mapa) {
    
    for (auto it = mapa.begin(); it != mapa.end(); it++){
        cout << it->first << ": ";
        set<int> skup(it->second);
        for (auto it2 = skup.begin(); it2 != skup.end() ; it2++) {
            if(++it2 != skup.end())
                cout << *--it2 << ",";
            else 
                cout << *--it2;
        }
        cout << endl;
    }
}

int main ()
{
    string recenica;
    cout << "Unesite tekst: ";
    std::getline(std::cin, recenica);
    
    Mapa mapa(KreirajIndeksPojmova(recenica));
    IspisiIndeksPojmova(mapa);
    
    
    string rijec;
    set<int> skup;
    
    for(;;) {
        cout << "Unesite rijec: ";
        std::getline(std::cin,rijec);
        
        if(rijec == ".")
            break;
            
        try {
            skup=PretraziIndeksPojmova(rijec, mapa);
        }
        catch (std::logic_error err) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
            continue;
        }
        for (auto x : skup) {
            cout << x << " ";
        }    
        cout << endl;
    }
    
	return 0;
}
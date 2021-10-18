/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <utility>
#include <stdexcept>

using std::list;
using std::queue;
using std::stack;
using std::string;
using std::pair;
using std::multimap;

enum class Boje {Pik, Tref, Herc, Karo};
const char* Values[]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
const char* Karte[]{"Pik", "Tref", "Herc", "Karo"};

typedef list<pair<Boje, string> > Spil;
typedef multimap<Boje, string> Mlti;
typedef queue<pair<string, string>> Quepass;

Spil KreirajSpil(){
    Spil s;
    
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 13; j++)
            s.push_back({Boje(i), Values[j]});
    
    return s;
}

int FindValID(string val, const char* *valarr, int n){
    int id = 0;
    bool found = false;
    for(id = 0; id < n; id++){
        if(val == valarr[id]){
            found = true;
            break;
        }
    }
    
    if(found)
        return id;
    
    return -1;
}

bool CheckList(Spil &s){
    if(s.size() > 52) return false;
    
    Spil::iterator prev = s.begin();
    Spil::iterator i = s.begin();
    
    for(++i; i != s.end(); i++, prev++){
        int ti, tj;
        if(i->first < prev->first &&
            (ti = FindValID(i->second, Values, 13), tj = FindValID(prev->second, Values, 13), (ti == -1 || tj == -1 || ti <= tj))
        )
            return false;
            
    }
    
    return true;
}

bool CheckQueue(Quepass &q){
    if(q.size() > 52) return false;
    
    int n = q.size();
    
    for(int i = 0; i < n; i++){
        int ki, kj, ti, tj;
        auto fr = q.front();
        if((ki = FindValID(fr.first, Karte, 4), kj = FindValID(fr.first, Karte, 4), (ki == -1 || kj == -1)) &&
            (ti = FindValID(fr.second, Values, 13), tj = FindValID(fr.second, Values, 13), (ti == -1 || tj == -1))
        )
            return false;
        q.pop();
        q.push(fr);
    }
    
    return true;
}

//Ne izbacuje prvi element iz mape
void IzbaciKarte(Spil &s, Mlti &m){
    if(!CheckList(s))
        throw std::logic_error("Neispravna lista!");
    
    for(Spil::iterator i = s.begin(); i != s.end(); i++){
        for(Mlti::iterator j = m.begin(); j != m.end(); j++){
            if(i->first == j->first && i->second == j->second){
                //brisanje i-tog elementa i preuzimanje iteratora na slijedeci!
                i = s.erase(i);
                i--;    //povecace se svakako slijedecu iteraciju
                j = m.erase(j);
                break;
            }
        }
    }
}

Quepass IzbaciKarteRazbrajanjem(Spil &s, short int r, int b){
    if(r < 1 || r  > 52 || b < 1)
        throw std::logic_error("Neispravni elementi za izbacivanje!");
        
    if(!CheckList(s))
        throw std::logic_error("Neispravna lista!");
    
    Quepass q;
    
    int i = 0;
    Spil::iterator it = s.begin();
    
    while(!s.empty() && i < b){
        //Iterator cycle
        int dif = std::distance(it, s.end());
        if(dif > r-1)
            std::advance(it, r-1);
        else{
            it = s.begin();
            std::advance(it, r-1 - dif);
        }
        
        q.push({Karte[int(it->first)], it->second});
        it = s.erase(it);
        
        i++;
    }
    
    return q;
}

void VratiPrvihNKarata(Spil &s, Quepass &q, int n){
    if(n < 0)
        throw std::logic_error("Broj n je besmislen!");
    
    if(n > q.size())
        throw std::range_error("Nedovoljno karata u redu!");
    
    if(!CheckQueue(q))
        throw std::logic_error("Neispravne karte!");
    
    if(!CheckList(s))
        throw std::logic_error("Neispravna lista!");
    
    
    //S razlogom su var prije petlje deklarisane
    pair<string, string> fr = q.front();
    
    if(s.empty()) {
        s.insert(s.begin(), {Boje(FindValID(fr.first, Karte, 4)), fr.second});
        q.pop();
        n-=1;
    }
    
    for(int i = 0; i < n; i++){
        //Uzmi element iz queue-a
        fr = q.front();
        q.pop();
        int idx = FindValID(fr.first, Karte, 4);
        int val = FindValID(fr.second, Values, 13);
        
        Spil::iterator it = s.begin();
        
        //Nadji gdje treba insert-ovat
        while(int(it->first) < idx || (int(it->first) == idx && FindValID(it->second, Values, 13) < val))
            it++;
        
        s.insert(it, {Boje(FindValID(fr.first, Karte, 4)), fr.second});
    }
}

void PrintSpil(Spil &s){
    Spil::iterator it = s.begin();
    for(int i = 0; i < 4; i++){
        std::cout << Karte[i] << ": ";
        while(it != s.end()){
            if(it->first != Boje(i))
                break;
            std::cout << it->second << " ";
            it++;
        }
        std::cout << std::endl;
    }
}

void PrintajSpil(Spil &s){
    Spil::iterator it = s.begin();
    for(; it != s.end(); it++)
        std::cout << Karte[int(it->first)] << it->second << std::endl;
    
}

int main () {
	Spil s = KreirajSpil();
	Quepass q;
	int r, b, n;
	
	std::cout << "Unesite korak razbrajanja: ";
	std::cin >> r;
	
	std::cout << "Unesite broj karata koje zelite izbaciti: ";
	std::cin >> b;
	
	try{
	    q = IzbaciKarteRazbrajanjem(s, r, b);
	}catch(std::exception &err){
	    std::cout << "Izuzetak: " << err.what();
	    return 0;
	}
	
	std::cout << "U spilu trenutno ima " << s.size() << " karata, i to: " << std::endl;
	PrintSpil(s);
	
	std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
	std::cin >> n;
	
	try{
	    VratiPrvihNKarata(s, q, n);
	}catch(std::exception &err){
	    std::cout << "Izuzetak: " << err.what();
	    return 0;
	}
	
	std::cout << "U spilu trenutno ima " << s.size() << " karata, i to: " << std::endl;
	PrintSpil(s);
	
	return 0;
}

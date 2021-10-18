#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <utility>
#include <stdexcept>

using std::stack;
using std::string;
using std::pair;
using std::multimap;

enum class Boje {Pik, Tref, Herc, Karo};
const char* Values[]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
const char* Karte[]{"Pik", "Tref", "Herc", "Karo"};

struct Karta{
    Boje boja;
    string vrijednost;
};

struct Cvor{
    Karta karta;
    Cvor *sljedeci;
};

typedef multimap<Boje, string> Mlti;
typedef stack<pair<string, string>> Stapass;

Cvor* KreirajSpil(){
    Cvor *pocetak = nullptr, *prethodni;
    
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 13; j++){
            //Alociraj novi cvor
            Cvor *novi = new Cvor{{Boje(i), Values[j]}, nullptr};
            //Ako je prvi cvor, postavi "pocetak" na njega
            if(!pocetak) pocetak = novi;
            //prethodni cvor pokazuje na ovaj
            else prethodni->sljedeci = novi;
            
            prethodni = novi;
        }
    
    //Uvezi listu u kruznu
    prethodni->sljedeci = pocetak;
    
    return pocetak;
}

void Increment(Cvor*&i){
    i = i->sljedeci;
}

int ListSize(Cvor* s){
    if(!s) return 0;
    
    int cnt = 1;
    Cvor* p = s;
    for(Increment(p); p != s; Increment(p)){
        cnt++;
        if(cnt > 52)
            return -1;
    }
    
    return cnt;
}

int Distance(Cvor* p1, Cvor* p2){
    int dis = 0;
    while(p1 != p2){
        Increment(p1);
        dis++;
    }
    return dis;
}

void Advance(Cvor* &p1, int n){
    for(int i = 0; i < n; i++)
        Increment(p1);
}

Cvor* Erase(Cvor* &pocetak, int n){
    Cvor* prev = pocetak;
    int lSize = ListSize(pocetak);
    
    if(n == 0) n = lSize;
    
    //Cvor prije onog za brisanje
    for(int i = 0; i < n-1; i++)
        Increment(prev);
    
    //Cvor za brisanje
    Cvor* toDel = prev;
    Increment(toDel);
    //Preusjeravanje preko onog koji se brise
    prev->sljedeci = toDel->sljedeci;
    if(toDel == pocetak) 
            pocetak = toDel->sljedeci;
    
    delete toDel;
    //Vrati pokazivac prethodni izbrisanom
    return prev;
}

void Insert(Cvor* s, Karta novi){
    Cvor* prev = s;
    Cvor* temp = s;
    
    while(true){
        Increment(temp);
        if(temp == s) break;
        Increment(prev);
    }
    
    Cvor* p = new Cvor{novi, s};
    prev->sljedeci = p;
}

void PrintSpil(Cvor* s){
    Cvor* it = s;
    for(int i = 0; i < 4; i++){
        std::cout << Karte[i] << ": ";
        std::cout << it->karta.vrijednost << " ";
        Increment(it);
        while(it != s){
            if(it->karta.boja != Boje(i))
                break;
            std::cout << it->karta.vrijednost << " ";
            Increment(it);
        }
        std::cout << std::endl;
    }
}

void UnistiSpil(Cvor *pocetak){
    if(!pocetak) return;
    
    Cvor* p = pocetak;
    Increment(p);
    while(p != pocetak){
        Cvor* sljedeci = p->sljedeci;
        delete p;
        p = sljedeci;
    }
    delete pocetak;
    pocetak = nullptr;
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

bool CheckList(Cvor* s){
    if(ListSize(s) > 52) return false;
    
    Cvor* prev = s;
    Cvor* i = s;
    
    for(Increment(i); i != s; Increment(i), Increment(prev)){
        int ti, tj;
        if(i->karta.boja < prev->karta.boja &&
            (ti = FindValID(i->karta.vrijednost, Values, 13), tj = FindValID(prev->karta.vrijednost, Values, 13), (ti == -1 || tj == -1 || ti <= tj))
        )
            return false;
            
    }
    
    return true;
}

void IzbaciKarte(Cvor* &s, Mlti &m){
    if(!CheckList(s))
        throw std::logic_error("Neispravna lista!");
    
    int lSize = ListSize(s);
    Cvor* p = s;
    
    for(int i = 0; i < lSize; i++, Increment(p)){
        for(Mlti::iterator j = m.begin(); j != m.end(); j++){
            if(p->karta.boja == j->first && p->karta.vrijednost == j->second){
                //brisanje i-tog elementa, p je na elementu prije obrisanog nakon brisanja
                p = Erase(s, i);
                i--;
                lSize--;
                j = m.erase(j);
                break;
            }
        }
    }
    
}

Stapass IzbaciKarteRazbrajanjem(Cvor* s, short int r, int b){
    if(r < 1 || r  > 52 || b < 1)
        throw std::logic_error("Neispravni elementi za izbacivanje!");
        
    if(!CheckList(s))
        throw std::logic_error("Neispravna lista!");
    
    Stapass q;
    
    int i = 0;
    Cvor* it = s;
    int lSize = ListSize(s);
    
    while(lSize > 0 && i < b){
        //Iterator cycle
        Advance(it, r-1);
        // std::cout << Karte[int(it->karta.boja)] << it->karta.vrijednost << std::endl;
        
        q.push({Karte[int(it->karta.boja)], it->karta.vrijednost});
        it = Erase(s, Distance(s, it));
        //It vraca na prethodni clan, za razliku od list.erase
        //pa povecati it...
        Increment(it);
        lSize--;
        
        i++;
    }
    
    return q;
}

void VratiPrvihNKarata(Cvor* s, Stapass &q, int n){
    if(n < 0)
        throw std::logic_error("Broj n je besmislen!");
    
    if(n > q.size())
        throw std::range_error("Nedovoljno karata u steku!");
    
    if(!CheckList(s))
        throw std::logic_error("Neispravna lista!");
    
    //S razlogom su var prije petlje deklarisane
    pair<string, string> fr = q.top();
    int lSize = ListSize(s);
    
    if(lSize > 0) {
        Insert(s, {Boje(FindValID(fr.first, Karte, 4)), fr.second});
        q.pop();
    }
    
    for(int i = 0; i < n; i++){
        //Uzmi element iz queue-a
        fr = q.top();
        q.pop();
        int idx = FindValID(fr.first, Karte, 4);
        int val = FindValID(fr.second, Values, 13);
        
        Cvor* it = s;
        
        //Nadji gdje treba insert-ovat
        while(int(it->karta.boja) < idx || (int(it->karta.boja) == idx && FindValID(it->karta.vrijednost, Values, 13) < val))
            Increment(it);
        
        Insert(it, {Boje(FindValID(fr.first, Karte, 4)), fr.second});
    }
}

int main () {
    Cvor* s = KreirajSpil();
	Stapass q;
	int r, b, n;
	
	std::cout << "Unesite korak razbrajanja: ";
	std::cin >> r;
	
	std::cout << "Unesite broj karata koje zelite izbaciti: ";
	std::cin >> b;
	
	try{
	    q = IzbaciKarteRazbrajanjem(s, r, b);
	}catch(std::exception &err){
	    std::cout << "Izuzetak: " << err.what();
	    UnistiSpil(s);
	    return 0;
	}
	
	std::cout << "U spilu trenutno ima " << ListSize(s) << " karata, i to: " << std::endl;
	PrintSpil(s);
	
	std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
	std::cin >> n;
	
	try{
	    VratiPrvihNKarata(s, q, n);
	}catch(std::exception &err){
	    std::cout << "Izuzetak: " << err.what();
	    UnistiSpil(s);
	    return 0;
	}
	
	std::cout << "U spilu trenutno ima " << ListSize(s) << " karata, i to: " << std::endl;
	PrintSpil(s);
	
	UnistiSpil(s);
	
	return 0;
}

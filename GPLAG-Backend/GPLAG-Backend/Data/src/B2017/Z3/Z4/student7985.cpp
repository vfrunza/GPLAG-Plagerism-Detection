/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <map> //multimapa
#include <list>
#include <queue> //queue = RED = FIFO
#include <string>
#include <utility> //pair

enum class Boje {Pik, Tref, Herc, Karo};
using std::multimap;
using std::domain_error;
using std::logic_error;
using std::range_error;
using std::make_pair;
using std::string;
using std::queue;
using std::list;
using std::pair;
using std::find; 
using std::cout;
using std::endl;
using std::cin;
typedef pair<Boje, string> Par;
typedef list<Par> Lista;
typedef multimap<Boje, string> Multimapa;
typedef queue<pair<string, string>> Red;

bool Legalno(Boje potencijalna_boja, string ime){
    bool ime_je_dobro(false), boja_je_dobra(false);
    Boje boje[4]{Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};
    string vrijednosti[13]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for(string x : vrijednosti) if(x == ime) ime_je_dobro = true;
    for(Boje boja : boje) if(boja == potencijalna_boja) boja_je_dobra = true;
    if(ime_je_dobro && boja_je_dobra) return true;
    return false;
}
Lista KreirajSpil(){
    Boje boje[4]{Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};
    string vrijednosti[13]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    Lista lista;
    for(int i=0; i<4; i++){
        for(int j=0; j<13; j++)
            lista.push_back(make_pair(boje[i], vrijednosti[j]));
    }
    return lista;
}
Lista::iterator Nadji(Lista::iterator p, Lista::iterator q, const pair<Boje,string> &par){
    while(p != q){
        if(p->first == par.first && p->second == par.second) return p;
        p++;
    }
    return q;
}
void IzbaciKarte(Lista &lista, Multimapa &mm){
    if(lista.size() > 52) throw logic_error("Neispravna lista!"); //..još ifova**
    for(Par &x : lista) if(!Legalno(x.first, x.second)) throw logic_error("Neispravna lista!"); //**myb
    for(auto mit = mm.begin(); mit != mm.end(); mit++){
       auto lit(lista.begin());
        lit = Nadji(lista.begin(), lista.end(), *mit);
        if(lit != lista.end()){
            lit = lista.erase(lit);
            mm.erase(mit);
        }
        
    }
}
string ImeBoje(Boje boja){
    Boje boje[4]{Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};
    string ime[4]{"Pik", "Tref", "Herc", "Karo"};
    for(int i=0; i<4; i++)  if(boja == boje[i]) return ime[i];
    return "";
}
Red IzbaciKarteRazbrajanjem(Lista &lista, const short int &korak, const int &b){
    if(b<1 || korak<1 || korak>52) throw logic_error("Neispravni elementi za izbacivanje!");
    if(lista.size() > 52) throw logic_error("Neispravna lista!"); //dodaj još..**
    for(Par &x : lista) if(!Legalno(x.first, x.second)) throw logic_error("Neispravna lista!"); //myb**
    
    Red red;
    auto lit(lista.begin());
    for(int i=0; i<b; i++){
        int j;
        for(j=1; j<korak; j++){
            lit++;
            if(lit == lista.end()) lit = lista.begin();
           
        } 
        if(j == korak){
            red.push(make_pair(ImeBoje(lit->first), lit->second));
            lit = lista.erase(lit);
        }
    }
    return red;
}
Lista VratiPrvihNKarata(Lista &lista, Red &red, int n){
    if(n < 0) throw domain_error("Broj n je besmislen!"); //??**????
    if(n > red.size()) throw range_error("Nedovoljno karata u redu!");
    for(Par &x : lista) if(!Legalno(x.first, x.second)) throw logic_error("Neispravne karte!"); //***
    if(lista.size() > 52) throw logic_error("Neispravna lista!"); //dodati..**
    
    return lista;
    
}
void IspisiListuZaBoju(const Lista &lista, const Boje &boja){
    for(Par x : lista) if(x.first == boja) cout << x.second << " ";
}

int main (){
    short int korak;
    cout << "Unesite korak razbrajanja: ";
    cin >> korak;
    int b;
    cout << "Unesite broj karata koje zelite izbaciti: ";
    cin >> b;
    Lista lista(KreirajSpil());
    Red red;
    try{
        red = (IzbaciKarteRazbrajanjem(lista, korak, b));
    }
    catch(logic_error er){
        cout << "Izuzetak: " << er.what();
        return 0;
    }
    cout << "U spilu trenutno ima " << lista.size() << " karata, i to: ";
    cout << "\nPik: "; IspisiListuZaBoju(lista, Boje::Pik);
    cout << "\nTref: "; IspisiListuZaBoju(lista, Boje::Tref);
    cout << "\nHerc: "; IspisiListuZaBoju(lista, Boje::Herc);
    cout << "\nKaro: "; IspisiListuZaBoju(lista, Boje::Karo);
    int n;
    cout << "\nUnesite broj karata koje zelite vratiti u spil: ";
    cin >> n;
    try{
        lista = VratiPrvihNKarata(lista, red, n);
    }
    catch(range_error er){
        cout << "Izuzetak: " << er.what(); return 0;
    }
    catch(domain_error er){
        cout << "Izuzetak: " << er.what(); return 0;
    }
    catch(logic_error er){
        cout << "Izuzetak: " << er.what(); return 0;
    }
    cout << "U spilu trenutno ima " << lista.size() << " karata, i to:";
    cout << "\nPik: "; IspisiListuZaBoju(lista, Boje::Pik);
    cout << "\nTref: "; IspisiListuZaBoju(lista, Boje::Tref);
    cout << "\nHerc: "; IspisiListuZaBoju(lista, Boje::Herc);
    cout << "\nKaro: "; IspisiListuZaBoju(lista, Boje::Karo);
    
	return 0;
}


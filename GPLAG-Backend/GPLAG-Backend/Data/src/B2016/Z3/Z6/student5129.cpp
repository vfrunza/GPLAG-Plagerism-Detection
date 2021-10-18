/B2016/2017: Zadaća 3, Zadatak 6

// Zadatak je lagan ali je pola 3 i nije mi do zivota

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::set;
using std::make_shared;
using std::shared_ptr;

struct Dijete{
  string ime;
  std::shared_ptr<Dijete> sljedeci;
};

int PrebrojiIme(string s){
    int duzina(0);
    for(int i=0; i<s.length(); i++) if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) duzina++;
    return duzina-1;
}

shared_ptr<Dijete> KreirajPovezanuListu(vector<string> &imena){
    shared_ptr<Dijete> prvi(nullptr);
    shared_ptr<Dijete> pok_na_prosli(nullptr);
    // Unosi sve do uslova
    for(int i=0; i<imena.size(); i++){
        // Dinamicki alociran tako da ne vracamo niz/vektor pokazivaca, jer ce prezivjeti kraj funkcije
        auto clan = make_shared<Dijete>();
        (*clan).ime = imena[i];
        // Stavljamo na nullptr jer nismo sigurni ako ce trenutni element biti zadnji
        (*clan).sljedeci = nullptr;
        
        // Ako prije nije bilo prvog, postavi trenutni clan na prvi, inace povezuje sa proslim clanom
        if(!prvi) prvi=clan;
        else (*pok_na_prosli).sljedeci = clan;
        
        // Pri sljedecoj iteraciji ce trenutni clan zapravo biti prosli, ovo nam treba za vezu
        pok_na_prosli=clan;
    }
    return prvi;
}

vector<set<string>> Razvrstavanje(vector<string> imena, int br_timova){
    if(br_timova>imena.size() || br_timova<1) throw std::logic_error("Razvrstavanje nemoguce");
    
    // Formiranje forward liste u koju prekopiramo sva imena, koristeci funkciju sa Tutorijala 8
    auto prvi = KreirajPovezanuListu(imena);
    
    // Gledamo koji tim ima koliko clanova
    int veci, manji(imena.size() / br_timova), brvecih(imena.size()%br_timova);
    // Ako nisu svi iste velicine
    if(imena.size()%br_timova){
        veci = (imena.size() / br_timova) + 1;
        manji = (imena.size() / br_timova);
    }
    
    // Vektor koji sadrzi broj clanova svih timova
    vector<int> clanovi(br_timova);
    for(int i=0; i<br_timova; i++){
        while(brvecih){
            clanovi[i]=veci;
            i++;
            brvecih--;
        }
        clanovi[i]=manji;
    }
    
    vector<set<string>> timovi(br_timova);
    // Brojimo koliko prvi clan ima slova
    int brojac(PrebrojiIme(prvi->ime));
    // Ubacujemo prvog u prvi clan skupa (tj. prvi tim) i izbacujemo iz liste
    timovi[0].insert(prvi->ime);
    // Brise prvi clan iz liste
    auto brisanje(prvi);
    prvi=prvi->sljedeci;
    brisanje=nullptr;
    
    // Tim u koji trenutno ubacujemo
    int i(0);
    // Krecemo se u krug dok ne razvrstamo svu djecu
    auto it1(prvi);
    auto prosli(prvi);
    
    while(prvi != nullptr){
        // Kruzenje
        while(brojac){
            prosli=it1;
            it1=it1->sljedeci;
            // Ako sko dosli iza kraja, trebamo onda biti na pocetku ponovo
            if(it1==nullptr) it1=prvi;
            if (prosli==it1) break;
            brojac--;
        }
        
        // Broji koliko slova ima clan koji se izbacuje
        brojac=PrebrojiIme(it1->ime);
        
        // Dodaje ime u skup ako tim nije pun
        if(timovi[i].size()<clanovi[i]) timovi[i].insert(it1->ime);
        // Ako je tim popunjen, dodaje ali u sljedeci tim
        else{
            i++;
            timovi[i].insert(it1->ime);
        }
        
        // Brise clan iz liste
        brisanje=it1;
        it1=it1->sljedeci;
        // Anti-belaj uslov da se popravi prvi clan u slucaju da se on brise
        if(brisanje==prvi) prvi = prvi->sljedeci;
        // Postavi da pokazivac od clana prije onoga sto se brise pokazuje na onaj poslije clana koji se brise, ako nije samo on ostao
        if(prosli->sljedeci != brisanje->sljedeci) prosli->sljedeci=brisanje->sljedeci;
        brisanje=nullptr;
        
        // Provjera da nije dosao na kraj
        if(it1==nullptr) it1=prvi;
        // Uslov za zadnji clan da ga obrise
        if(prvi == prvi->sljedeci){
            // Dodaje ime u skup ako tim nije pun
            if(timovi[i].size()<clanovi[i]) timovi[i].insert(it1->ime);
            // Ako je tim popunjen, dodaje ali u sljedeci tim
            else{
                i++;
                timovi[i].insert(it1->ime);
            }
            prvi=nullptr;
            it1=it1->sljedeci;
            it1=nullptr;
            prosli=nullptr;
            brisanje=nullptr;
            break;
        }
    }
    
    return timovi;
}

int main (){
    cout << "Unesite broj djece: ";
    int br_djece;
    cin >> br_djece;
    
    cin.ignore(10000, '\n');
    
    cout << "Unesite imena djece: ";
    vector<string> imena;
    for(int i=0; i<br_djece; i++){
        string ime;
        getline(cin, ime);
        imena.push_back(ime);
    }
    
    cout << std::endl;
    
    cout << "Unesite broj timova: ";
    int br_timova;
    cin >> br_timova;
    
    vector<set<string>> razvrstani;
    try{
        razvrstani = Razvrstavanje(imena, br_timova);
    } catch(std::logic_error greska){
        cout << "Izuzetak: " << greska.what();
        return 0;
    }
    
    for(int i=0; i<br_timova; i++){
        cout << "Tim " << i+1 << ": ";
        auto j(razvrstani[i].begin());
        auto kraj(razvrstani[i].end()--);
        kraj--;
        while(j!=kraj){
            cout << *j << ", ";
            j++;
        }
        cout << *j << std::endl;;
    }
    
	return 0;
}

/* Testni:
Damir
Ana
Muhamed
Marko
Ivan
Mirsad
Nikolina
Alen
Jasmina
Merima
*/
/B2016/2017: Zadaća 3, Zadatak 5

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::set;

struct Dijete{
  string ime;
  Dijete* sljedeci;
};

int PrebrojiIme(string s){
    int duzina(0);
    for(int i=0; i<s.length(); i++) if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) duzina++;
    return duzina-1;
}

vector<set<string>> Razvrstavanje(vector<string> imena, int br_timova){
    if(br_timova>imena.size() || br_timova<1) throw std::logic_error("Razvrstavanje nemoguce");
    
    // Formiranje liste u koju prekopiramo sva imena
    Dijete* prvi(nullptr);
    Dijete* pok_na_prosli(nullptr);
    string unos;
    // Za svako ime u vektoru pravimo varijablu tipa strukture Dijete, koju uvezujemo u lanac koji ce oponasati forward listu
    for(auto &unos : imena){
        // Dinamicki alociran tako da ne vracamo niz/vektor pokazivaca, jer ce prezivjeti kraj funkcije
        Dijete* clan(new Dijete);
        clan->ime = unos;
        // Stavljamo na nullptr jer nismo sigurni ako ce trenutni element biti zadnji
        clan->sljedeci = nullptr;
        
        // Ako prije nije bilo prvog, postavi trenutni clan na prvi, inace povezuje sa proslim clanom
        if(!prvi) prvi=clan;
        else pok_na_prosli->sljedeci = clan;
        
        // Pri sljedecoj iteraciji ce trenutni clan zapravo biti prosli, ovo nam treba za vezu
        pok_na_prosli=clan;
    }
    
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
    delete brisanje;
    
    // Tim u koji trenutno ubacujemo
    int i(0);
    // Krecemo se u krug dok ne razvrstamo svu djecu
    auto it1(prvi);
    auto prosli(it1);
    
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
        delete brisanje;
        
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
            delete prvi;
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
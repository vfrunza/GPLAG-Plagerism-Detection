/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <list>

using std::cin; using std::cout; using std::endl;

int PrebrojiSlova (std::string ime) {
    int broj_slova(0);
    for (int i=0; i<ime.size(); i++) {
        if ((ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9')) broj_slova++;
    }
    return broj_slova;
}

std::vector<std::multiset<std::string>> Razvrstavanje (std::vector<std::string> v_imena_djece, int broj_timova) {
    //Funkcija mora biti zasnovana na tipu list
    if (broj_timova<1 || broj_timova>v_imena_djece.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    
    //Sva imena iz vektora kopirajmo u listu
    std::list<std::string> lista_d;
    std::vector<std::multiset<std::string>> rez(broj_timova);
    
    for (int i=0; i<v_imena_djece.size(); i++) {
        lista_d.push_back(v_imena_djece[i]);
    }
    auto it(lista_d.begin()); //Iterator na prvi clan 
    auto broj_slova(PrebrojiSlova(*it));
    //Ubacimo dijete u tim
    rez[0].insert(*it);
    it=lista_d.erase(it); //Izbacili smo prvo dijete
    int b(0), br_tim(1), n(v_imena_djece.size()), k(broj_timova);
    while (lista_d.size()!=0) {
        for (int i=1; i<broj_slova; i++) {
            it++;
            if (it==lista_d.end()) it=lista_d.begin();
        }
        //It pokazuje na dijete koje moramo izbaciti
        broj_slova=PrebrojiSlova(*it);
        if (b<n%k) {
            if (br_tim<n/k+1) {
                rez[b].insert(*it);
                br_tim++;
            }
            else {
                b++;
                br_tim=1;
                rez[b].insert(*it);
            }
        }
        else {
            if (br_tim<n/k) {
                rez[b].insert(*it);
                br_tim++;
            }
            else {
                b++;
                br_tim=1;
                rez[b].insert(*it);
            }
        }
        
        it=lista_d.erase(it); //Ako smo izbrisali zadnji, iterator na predzadnji ili na prvi?
        if (it==lista_d.end()) it=lista_d.begin();
        
    }
    return rez;
}

int main ()
{
    cout << "Unesite broj djece: ";
    int n;
    cin >> n;
    cout << "Unesite imena djece: " << endl;
    std::vector<std::string> imena;
    cin.ignore(10000, '\n'); //unos brojeva pa slova?
    for (int i=0; i<n; i++) {
        std::string ime;
        std::getline(cin, ime);
        imena.push_back(ime);
    }
    cout << "Unesite broj timova: ";
    int br;
    cin >> br;
    try {
        auto vek(Razvrstavanje(imena, br)); // vektor ciji su elementi skupovi imena
        for (int i=0; i<br; i++) {
            cout << "Tim " << i+1 << ": ";
            int j(0);
            for (std::string ime:vek[i]) {
                if (j!=vek[i].size()-1) cout << ime << ", ";
                else cout << ime;
                j++;
            }
            cout << endl;
        }
    }
    catch (std::logic_error izuzetak) {
        cout << "Izuzetak: " << izuzetak.what();
        return 0;
    }
	return 0;
}
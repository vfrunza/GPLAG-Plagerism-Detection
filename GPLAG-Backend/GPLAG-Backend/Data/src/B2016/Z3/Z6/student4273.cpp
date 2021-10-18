/B2016/2017: Zadaća 3, Zadatak 6

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <memory>

using std::cin; using std::cout; using std::endl;

struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

typedef std::shared_ptr<Dijete> DijeljeniPok;

int PrebrojiSlova (std::string ime) {
    int broj_slova(0);
    for (int i=0; i<ime.size(); i++) {
        if ((ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9')) broj_slova++;
    }
    return broj_slova;
}

DijeljeniPok KreirajPovezanuListu(std::vector<std::string> imena) {
    DijeljeniPok pocetak(nullptr); DijeljeniPok prethodni(nullptr);
    for (int i=0; i<imena.size(); i++) {
        auto novi=std::make_shared<Dijete>(); //Kreiramo novi cvor, da li provjeravamo uspjesnost alokacije?
        novi->ime=imena[i]; novi->sljedeci=nullptr;
        if (!pocetak) pocetak=novi;  //Za prvi
        else prethodni->sljedeci=novi; //Za ostale
        prethodni=novi;
        if (i==imena.size()-1) {
            //Posljednje dijete pokazuje na prvo
            novi->sljedeci=pocetak; //?
        }
    }
    return pocetak;
}

std::vector<std::multiset<std::string>> Razvrstavanje (std::vector<std::string> v_imena_djece, int broj_timova) {
    if (broj_timova<1 || broj_timova>v_imena_djece.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    //Moramo koristiti rucno kreiranu povezanu listu cvorova
    auto pocetak=KreirajPovezanuListu(v_imena_djece); //Pok na pocetak liste
    std::vector<std::string> pomocni;
    std::vector<std::multiset<std::string>> rez(broj_timova);
    auto p(pocetak);
    //Prvo dijete u prvi tim
    rez[0].insert(p->ime);
    auto broj_slova(PrebrojiSlova(p->ime));
    //Uklonimo ga iz liste
    auto q(pocetak);
    while (q->sljedeci!=pocetak) {
        //Pomjeramo q na zadnji
        q=q->sljedeci;
    }
    pocetak=p->sljedeci; //Pokazuje na sljedece dijete
    q->sljedeci=pocetak;
    p=nullptr; //Brisemo prvi
    
    //Podjelimo i ostalu djecu
    int b(0), n(v_imena_djece.size()), k(broj_timova), br_tim(1);
    for (int i=0; i<(v_imena_djece.size()-1); i++) {
        auto p(pocetak);
        for (int i=0; i<broj_slova-1; i++) {
            p=p->sljedeci; //Pomjeramo na onaj el koji trebamo izbaciti
        }
        pocetak=p;
        if (b<n%k) {
            if (br_tim<n/k+1) {
                rez[b].insert(p->ime);
                br_tim++;
            }
            else {
                b++;
                br_tim=1;
                rez[b].insert(p->ime);
            }
        }
        else {
            if (br_tim<n/k) {
                rez[b].insert(p->ime);
                br_tim++;
            }
            else {
                b++;
                br_tim=1;
                rez[b].insert(p->ime);
            }
        }
        
        broj_slova=PrebrojiSlova(p->ime);
        //Uklonimo ga iz liste
        auto q(pocetak);
        while (q->sljedeci!=pocetak) {
        //Pomjeramo q na zadnji
        q=q->sljedeci;
        }
        pocetak=p->sljedeci; //Pokazuje na sljedece dijete
        q->sljedeci=pocetak;
        p=nullptr; //Brisemo prvi
    }
    pocetak->sljedeci=nullptr; //Raskidamo vezu
    pocetak=nullptr;
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
    //{"Damir", "Ana", "Muhamed", "Marko", "Ivan", "Mirsad", "Nikolina", "Alen", "Jasmina", "Merima"}
    try {
        //Razvrstavanje(imena, br);
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
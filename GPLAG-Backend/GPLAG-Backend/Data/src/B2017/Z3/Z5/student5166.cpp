/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <queue>
#include <stdexcept>
#include <utility>
#include <string>
using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};

struct Karta {
    Boje boja;
    string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor *sljedeci;
};

Cvor *KreirajSpil(){
    try {
        Cvor *pocetak (nullptr), *prethodni;
        for (int i=0; i<4; i++){
            Boje tmpboja = Boje(i);
            for (int j=2; j<=14; j++){
                Karta tmpkarta;
                string tmp;
                if (j==2) tmp = '2';
                else if (j==3) tmp = '3';
                else if (j==4) tmp = '4';
                else if (j==5) tmp = '5';
                else if (j==6) tmp = '6';
                else if (j==7) tmp = '7';
                else if (j==8) tmp = '8';
                else if (j==9) tmp = '9';
                else if (j==10) tmp = '10';
                else if (j==11) tmp = 'J';
                else if (j==12) tmp = 'Q';
                else if (j==13) tmp = 'K';
                else if (j==14) tmp = 'A';
                tmpkarta.boja = tmpboja;
                tmpkarta.vrijednost = tmp;
                Cvor *novi = nullptr;
                novi = new Cvor;
                novi -> karta = tmpkarta;
                novi -> sljedeci = nullptr;
                if (i==0 && j==2){
                    pocetak = novi;
                    prethodni = novi;
                }
                else if (i==3 && j==14){
                    prethodni -> sljedeci = novi;
                    novi -> sljedeci = pocetak;
                }
                else {
                    prethodni -> sljedeci = novi;
                    prethodni = novi;
                }
                
            }
        }
        return pocetak;
    }
    catch (bad_alloc){
        throw ("Memorijska greska");
    }
}

queue<pair<string,string>>IzbaciKarte (Cvor *&pocetak, const pair<int, int>par){
    if (par.first<1 || par.first>52 || par.second<1) throw logic_error ("Neispravni elementi za izbacivanje!");
}


int main (){
    try {
        Cvor *pok = KreirajSpil();
        int korak, brkarata;
        cout << "Unesite korak razbrajanja: ";
        cin >> korak;
        cout << "Unesite broj karata koje zelite izbaciti: ";
        cin >> brkarata;
        pair<int,int>par_izbaci;
        par_izbaci = make_pair(korak, brkarata);
        queue<pair<string,string>> red = IzbaciKarte(pok, par_izbaci);
        
    }
    catch (logic_error Izuzetak) {
        cout << "Izuzetak: " << Izuzetak.what() << endl;
    }
    catch (range_error Izuzetak){
        cout << "Izuzetak: " << Izuzetak.what() << endl;
    }
    catch (const char *c){
        cout << c << endl;
    }
    
	return 0;
}

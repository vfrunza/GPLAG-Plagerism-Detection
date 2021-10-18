#include <iostream>
#include <vector>
#include <string>
#include <limits>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

vector<int> IzdvojiGadne(vector<int> brojevi, bool gadan);
bool DaLiJeGadan(int broj);
string DecimalToTernaryReversed(int dec);
bool daLiJeBrojCifaraParan(string broj, char cifra);
bool daLiJeOpak(int broj);
bool daLiPostojiUVektoru(vector<int> vektor, int broj);
void ispisiVektor(vector<int> vektor);

int main() {
    cout << "Unesite brojeve (0 za prekid unosa): ";
    vector<int> brojevi(0);
    int broj;
    do {
        cin >> broj;
        if(broj != 0) brojevi.push_back(broj);
    } while(broj != 0);

    cout << "Opaki: ";
    ispisiVektor(IzdvojiGadne(brojevi, true));
    cout << "Odvratni: ";
    ispisiVektor(IzdvojiGadne(brojevi, false));

    return 0;
}

vector<int> IzdvojiGadne(vector<int> brojevi, bool gadan) {
    vector<int> rezultat(0);
    for(int broj : brojevi) {
        if(DaLiJeGadan(broj) && (daLiJeOpak(broj) == gadan) && !daLiPostojiUVektoru(rezultat, broj))
            rezultat.push_back(broj);
    }
    return rezultat;
}
bool DaLiJeGadan(int broj) {
    /*
    ako je broj gadan vraca true, ako nije false
    gadan je ako mu je svaka cifra parna ili neparna
    //*/
    //Ovaj zadatak se moze uraditi i bez ove funkcije
    //ali sam je napravio prije nego sto sam shvatio da ne treba
    //tako da cu je koristiti WOoo
    string stringBroj(DecimalToTernaryReversed(broj));
    bool daLiJeKolicinaCifaraParna;
    //prolazi kroz cifre
    //pri pronalasku prve cifre koja se nalazi u broju
    //postavlja parnost cifara na to da li ima paran ili neparan broj te cifre
    for(char cifra = '0'; cifra < '3'; cifra++) {
        try {
            daLiJeKolicinaCifaraParna = daLiJeBrojCifaraParan(stringBroj, cifra);
            break;
        } catch(int broj) {
            continue;
        }
    }
    for(char cifra = '0'; cifra < '3'; cifra++) {
        try {
            if(daLiJeKolicinaCifaraParna != daLiJeBrojCifaraParan(stringBroj, cifra))
                /*
                kako bi trebala izgledati tablica za ovaj uslov
                    0 0 | 0
                    0 1 | 1
                    1 0 | 1
                    1 1 | 0
                //*/
                return false;
        } catch(int broj) {
            continue;
        }
    }
    return true;
}
string DecimalToTernaryReversed(int dec) {
    if(dec==0)  return "0";
    string rezultat("");
    while(dec!=0) {
        rezultat += std::to_string(dec%3);
        dec/=3;
    }
    return rezultat;
}
bool daLiJeBrojCifaraParan(string broj, char cifra) {
    int brojac(0);
    while(0 < broj.length()) {
        if(broj.back() == cifra)
            brojac++;
        broj.pop_back();
    }
    if (brojac == 0) throw 0;
    return !(brojac%2);
}
bool daLiJeOpak(int broj) {
    //Opaki brojevi su oni koji imaju
    //paran broj cifara;
    string stringBroj(DecimalToTernaryReversed(broj));
    for(char cifra = '0'; cifra < '3'; cifra++) {
        try {
            return daLiJeBrojCifaraParan(stringBroj, cifra);
        } catch(int broj) {
            continue;
        }
    }
}
bool daLiPostojiUVektoru(vector<int> vektor, int broj) {
    for(int brojUVektoru : vektor) {
        if(broj == brojUVektoru)
            return true;
    }
    return false;
}
void ispisiVektor(vector<int> vektor) {
    for(int a : vektor)
        cout << a << " ";
    cout << endl;
}

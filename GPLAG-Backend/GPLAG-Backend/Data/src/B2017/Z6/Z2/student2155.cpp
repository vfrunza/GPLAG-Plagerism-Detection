//OVDJE JE RIJEŠEN PRIMJER 3 PARCIJALNOG ISPITA SA C2
//ZADATAK 4.
/*Napišite program koji traži od korisnika da unese niz rečenica, pri čemu se broj rečenica prethodno
unosi sa tastature. Za svaku unesenu rečenicu dinamički alocirajte prostor, uz vođenje evidencije o
adresi svake alocirane rečenice u dinamičkom nizu pokazivača na početke svake od rečenica. Nakon
toga, treba ispisati unesene rečenice sortirane u abecedni poredak (tačnije rečeno, u rastući poredak
po ASCII kodovima). Za sortiranje koristite funkciju “sort” uz pogodno definiranu funkciju kriterija.
#include <iostream>
#include <string>
#include <algorithm>


int main ()
{
    std::cout<<"Koliko recenica zelite unijeti: ";
    int n;
    std::cin>>n;
    std::string **p(nullptr);
    int a(0);
    std::cin.ignore(10000, '\n');

    std::cout<<"Unesite recenice: ";
    try {
        p = new std::string*[n] {};
        try {
            for(a = 0; a < n; a++) {
                p[a] = new std::string;
                std::getline(std::cin, *p[a]);
            }
            std::sort(p, p + n, [](std::string *x, std::string *y) {
                return *x < *y;
            });
            for(int i = 0; i < n; i++) {
                std::cout<<*p[i]<<std::endl;
            }
            for(int i = 0 ; i < n; i++)
                delete p[i];
            delete [] p;
        } catch(...) {
            for(int i = 0; i < a; i++)
                delete p[i];
            delete []p;
            throw;
        }
    } catch(...) {
        std::cout<<"Problemi sa memorijom!";
    }
    return 0;
}*/
//ZADATAK 5.
/*Napišite generičku funkciju “ZajednickiElementi” koja prima dva parametra koji su vektori sa
proizvoljnim ali istim tipom elemenata. Funkcija treba da kao rezultat vrati novi vektor koji se sastoji
od elemenata koji se javljaju i u jednom i u drugom vektoru (drugim riječima, treba formirati presjek
skupova čiji su elementi pohranjeni u vektorima koji su zadani kao parametri). Pored toga, u vektoru
koji je vraćen kao rezultat iz funkcije svi elementi treba da budu različiti (odnosno, elemente koji se
ponavljaju ne treba prepisivati više puta). Poredak brojeva pohranjenih u rezultatu nije bitan.
Napisanu funkciju demonstrirajte na isječku programa u kojem se nalazi presjek dva vektora čiji su
elementi stringovi, sa fiksno zadanim sadržajem (po vlastitom izboru).

#include <iostream>
#include <vector>

template <typename tip>

std::vector<tip> ZajednickiElementi(std::vector<tip>v1, std::vector<tip>v2)
{
    std::vector<tip>presjek;
    for(tip x : v1) {
        for(tip y : v2) {
            if(x == y) presjek.push_back(x);
        }
    }
    int vel;
    for(int i = 0; i < presjek.size(); i++) {
        vel = presjek.size();
        for(int j = i + 1; j < presjek.size() - 1; j++) {
            if(presjek.at(i) == presjek.at(j)) {
                for(int k = j; k < presjek.size() - 1; k++) {
                    presjek.at(k) = presjek.at(k + 1);
                }
                presjek.resize(vel - 1);
                i--;
            }
        }
    }
    return presjek;
}

int main()
{
    std::vector<int>v1{1,2,3,4};
    std::vector<int>v2{2,4,6,8, 1, 2, 3, 3, 3};
    std::vector<int>p(ZajednickiElementi(v1,v2));
    for(auto x : p) std::cout<<x<<" ";

    return 0;
}*/
//ZADATAK 6.
/*Napišite funkciju “IzdvojiRijec” sa dva parametra, od kojih je prvi tipa “string”, a drugi tipa “int”.
Prvi parametar predstavlja neku rečenicu, a drugi parametar redni broj riječi unutar te rečenice.
Funkcija treba da izdvoji tu riječ iz rečenice i da vrati kao rezultat tako izdvojenu riječ. Na primjer,
         ukoliko je kao prvi parametar zadan tekst “ Riba ribi grize rep ” a kao drugi parametar broj 3,
         funkcija treba kao rezultat da vrati string “grize”. Ovdje pod pojmom riječ podrazumijevamo bilo koji
         slijed uzastopnih znakova koji nisu razmaci, a ispred kojeg se eventualno nalazi razmak (ili ništa), i
         iza kojeg eventualno slijedi razmak (ili ništa). Obratite pažnju da riječi mogu biti razdvojene sa više
         uzastopnih razmaka, kao i da na početku i kraju teksta može, ali i ne mora biti razmaka. Ukoliko je
         drugi parametar manji od 1 ili veći od broja riječi u rečenici, funkcija treba baciti izuzetak. Napisanu
         funkciju demonstrirajte u testnom programu u kojem se za rečenicu unesenu sa tastature i prirodan
         broj n ispisuje n-ta riječ te rečenice (pozivom napisane funkcije).

#include <iostream>
#include <string>
#include <stdexcept>

std::string IzdvojiRijec(std::string s, int n)
{
    if(n < 1) throw std::logic_error("Neispravni parametri!");
    int broj_rijeci(0), neslovo = 1, brojac = 0, zapamti = 0;
    std::string rijec{};
    for(int i = 0; i < s.length(); i++) {
        if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) neslovo = 1;
        else if(neslovo == 1) {
            neslovo = 0;
            broj_rijeci++;

            if(n == broj_rijeci) {
                zapamti = i;
                while((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                    rijec[brojac] = s[i];
                    i++;
                    brojac++;
                }
                i = zapamti;
            }
        }
    }
    if(broj_rijeci < n) throw std::logic_error("Neispravni parametri!");
    return rijec;
}
int main()
{
    std::string s("   Riba   ribi   grize   rep   ");
    std::cout<<IzdvojiRijec(s,3)<<std::endl;
    return 0;
}*/
//ZADATAK 7.
/*Napišite funkciju koja kao jedan parametar prima neki stek realnih brojeva, a kao drugi parametar
neki realni broj. Funkcija kao rezultat treba da vrati novi stek realnih brojeva čiji su elementi jednaki
elementima izvornog steka pomnoženi sa zadanim brojem. Na primjer, ukoliko se u steku koji je
proslijeđen kao parametar nalaze brojevi 2, 5, 3 i 4 (tim redom), i ukoliko se kao drugi parametar
proslijedi broj 3, stek vraćen kao rezultat treba da sadrži brojeve 6, 15, 9 i 12 (tim redom). Podsjetimo
se da je stek kontejnerska struktura koja ne podržava ništa drugo osim operacija “push” (dodaj novi
element na vrh steka), “top” (daj element koji je na vrhu steka), “pop” (ukloni element sa vrha steka),
“size” (daj broj elemenata u steku) i “empty” (daj informaciju da li je stek prazan ili ne). Za realizaciju
ove funkcije ne smijete koristiti nikakvu pomoćnu funkciju, osim eventualno jednog pomoćnog steka
ukoliko smatrate da Vam je potreban.
#include <iostream>
#include <stack>

std::stack<double> Funkcija(std::stack<double>s, double n){
    std::stack<double>rez;
    while(!s.empty()){
        double pomocni;
        pomocni = s.top() * n;
        rez.push(pomocni);
        s.pop();
    }
    return rez;
}

int main(){
    std::stack<double>stek;
    stek.push(1);
    stek.push(2);
    stek.push(3);
    
    std::stack<double>rez(Funkcija(stek, 10));
    while(!rez.empty()){
        std::cout<<rez.top()<<" ";
        rez.pop();
    }
    return 0;
}*/
//ZADATAK 8.

#include <iostream>

int main(){
    return 0;
}
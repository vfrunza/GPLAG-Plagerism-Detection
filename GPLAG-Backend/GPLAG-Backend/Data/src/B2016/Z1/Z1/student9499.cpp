/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <limits>
std::vector<int> IzdvojiGadne(std::vector<int> gadanNiz, bool tip) {
    // true - opaki - parni, false - odvratni - ne parni
    std::vector<int> najGadniji;
    
    for (int i = 0; i < gadanNiz.size(); i++) {
        long long int broj(gadanNiz[i]); // pretvaram iz gadanNiz decimalne u ternarne
        std::vector<int> razdvojenBroj(3, 0); // u ovaj niz spremam pojedinacne brojeve od varijable 'broj'
        int rez;
        if (broj < 0) 
            broj *= -1;
        do {
            rez = broj % 3;
            razdvojenBroj[rez]++; 
            broj /= 3;
        } while (broj > 0);
        bool opak(true); // predpostavljam da su sve cifre parne i da je broj opak
        bool gadan(true);
        for (int x : razdvojenBroj) {
            if (!tip) {
                if (x % 2 != 0) 
                    gadan = false;
                else if (x != 0) { 
                    gadan = true;
                    break;
                }
            }
            else if (tip) {
                if (x % 2 == 0 && x != 0) 
                    opak = false;
                else if (x != 0) { 
                    opak = true; 
                    break; 
                }
            }
        }
        if ((opak && !gadan) || (!opak && gadan)) 
            najGadniji.push_back(gadanNiz.at(i)); // u ovom momentu nadjen je opak broj i ide dalje
    }
    std::vector<int> najGadnijiRez;
    for (int i = 0; i < najGadniji.size(); i++) {
        bool imaGa = false;
        for (int j = 0; j < najGadnijiRez.size(); j++) {
            if (najGadniji[i] == najGadnijiRez[j]) imaGa = true;
        }
        if (!imaGa)
            najGadnijiRez.push_back(najGadniji[i]);
    }
    return najGadnijiRez;
}

int main () {
    std::vector<int> niz;
    std::cout << "Unesite brojeve (0 za prekid unosa): ";
    for(;;) {
        int x;
        std::cin >> x;
        if (x == 0) break;
        niz.push_back(x);
    }
    std::vector<int> gadni (IzdvojiGadne(niz, true));
    std::cout << "Opaki: ";
    for (int x : gadni) std::cout << x << " ";
    gadni = IzdvojiGadne({std::numeric_limits<int>::min()}, false);
    std::cout << "\nOdvratni: ";
    for (int x : gadni) std::cout << x << " ";
	return 0;
}

/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> niz) {
    Matrica rez;
    int red(0);
    bool prviPut(true);
    for (int i = 1; i < niz.size(); i++) {
        if (niz[i - 1] <= niz[i]) {
            if (prviPut) {
                rez.resize(red + 1);
                rez[red].push_back(niz[i - 1]);
                prviPut = false;
            }
            rez[red].push_back(niz[i]);
        }
        else {
            prviPut = true;
            if (rez.size() != red)
                red++;
        }
    }
    return rez;
}

Matrica OpadajuciPodnizovi(std::vector<double> niz) {
    Matrica rez;
    int red(0);
    bool prviPut(true);
    for (int i = 1; i < niz.size(); i++) {
        if (niz[i] <= niz[i - 1]) {
            if (prviPut) {
                rez.resize(red + 1);
                rez[red].push_back(niz[i - 1]);
                prviPut = false;
            }
            rez[red].push_back(niz[i]);
        }
        else {
            prviPut = true;
            if (rez.size() != red)
                red ++;
        }
    }
    return rez;
}

int main () {
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> niz(n);
	for (int i = 0; i < n; i++)
	    std::cin >> niz[i];
	Matrica rez;
	rez = RastuciPodnizovi(niz);
	std::cout << "Maksimalni rastuci podnizovi:\n";
	for (std::vector<double> x : rez){
	    for (int y : x)
	        std::cout << y << " ";
	   std::cout << "\n";
	}
	rez = OpadajuciPodnizovi(niz);
	std::cout << "Maksimalni opadajuci podnizovi:\n";
	for (std::vector<double> x : rez){
	    for (int y : x)
	        std::cout << y << " ";
	   std::cout << "\n";
	}
	return 0;
}   
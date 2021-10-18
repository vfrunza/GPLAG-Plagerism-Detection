/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

typedef vector<vector<double>> Matrica;

void print(vector<double> v) {
	for (double e : v) {
		cout << e << " ";
	}
	cout << std::endl;
	
}

void printMatrica(Matrica nizovi) {
	for (vector<double> v : nizovi) {
		print(v);
	}
}

Matrica mmp(vector<double> elems, bool sign) {
	Matrica nizovi;
	
	int len(elems.size());
	if (len == 0) return nizovi; // moze i za len < 2
	
	double prev(elems[0]);
	bool open(false);
	for (int i(1); i < len; i++) {
		double e(elems[i]);
		
		if ((sign && prev <= e) || (!sign && prev >= e)) {
			// Dodajemo broj u novi ili stari podniz
			if (!open) { // Dodajemo novi podniz, koji sadrzi prijasnji broj
				nizovi.push_back(vector<double> {prev});
				open = true;
			}
			nizovi[nizovi.size() - 1].push_back(e); // Dodajemo broj
		} else {
			open = false; // Zatvaramo podniz
		}
		
		prev = e;
	}
	
	return nizovi;
}

Matrica RastuciPodnizovi(vector<double> elems) {
	return mmp(elems, true);
}

Matrica OpadajuciPodnizovi(vector<double> elems) {
	return mmp(elems, false);
}

int main () {

	vector<double> v;
	cout << "Unesite broj elemenata vektora: ";
	int i(0), n;
	double b;
	for ((cin >> n, cout << "Unesite elemente vektora: "); i < n; i++) {
		cin >> b;
		v.push_back(b);
	}
	
	cout << "Maksimalni rastuci podnizovi: \n";
	printMatrica(RastuciPodnizovi(v));
	cout << "Maksimalni opadajuci podnizovi: \n";
	printMatrica(OpadajuciPodnizovi(v));
	
	return 0;
}
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

using std::vector;
using std::cout;
using std::cin;

void print(vector<int> v) {
	for (int n : v) {
		cout << n << " ";
	}
	cout << std::endl;
	
}

bool Opaki(vector<int> cif) {
	return !((cif[0] & 1) || (cif[1] & 1) || (cif[2] & 1));
}

bool Odvratni(vector<int> cif) {
	for (int n : cif) {
		if ((n > 0) && !(n&1)) return false;
	}
	
	return true;
}

vector<int> Cifre(int n) {
	vector<int> broj{0, 0, 0}; // Mogao je i enum
	
	long long m(std::abs((long long) n)); // m je mogao biti i unsigned int
	do { // U slucaju m == 0
		broj[m % 3]++;
		m /= 3;
	} while (m > 0);
	
	return broj;
}

vector<int> IzdvojiGadne(vector<int> brojevi, bool b) {
	
	vector<int> rez;
	
	int len(brojevi.size());
	for (int i(0); i < len; i++) {
		int j(0), n(brojevi[i]);
		while (j < i && n != brojevi[j]) { // Test za duplikat
			j++;
		}
		
		if (i == j) { // Ako nije duplikat
			bool cond(false);
			if (b) { // Testirati za opake
				if (Opaki(Cifre(n))) cond = true;
			} else { // Testirati za gadne
				if (Odvratni(Cifre(n))) cond = true;
			}
			
			if (cond) rez.push_back(n);
		}
	}
	
	return rez;
}

int main () {
	
	vector<int> v;

	int n(0);
	cout << "Unesite brojeve (0 za prekid unosa): ";
	while((cin >> n) && n != 0) {
		v.push_back(n);
	}
	
	cout << "Opaki: ";
	print(IzdvojiGadne(v, 1));
	cout << "Odvratni: ";
	print(IzdvojiGadne(v, 0));
	
	return 0;
}


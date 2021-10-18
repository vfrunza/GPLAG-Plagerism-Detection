/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

typedef std::vector<int> vi;

vi cifre(int x) {	
	vi rez = {0, 0, 0};
	long long a = x;
	if (a < 0) a = -a;
	for (;;) {
		int cifra = a % 3;
		rez[cifra]++;
		a /= 3;
		if (a == 0) break;
	}
	return rez;
}

vi IzdvojiGadne(vi in, bool opaki) {
	vi rez;
	for (int x : in) {
		bool valja = true;
		for (int i : cifre(x)) {
			if (i == 0) continue;
			if (i % 2 != (opaki ? 0 : 1)) 
				valja = false;
		}
		if (!valja) continue;
		for (int y : rez)
			if (x == y) {
				valja = false;
				break;
			}
		if (valja) rez.push_back(x);
	}
	return rez;
}

int main() {
	using std::cout;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	vi in;
	
	for (;;) {
		int x;
		std::cin >> x;
		if (x == 0) break;
		in.push_back(x);
	}
	
	cout << "Opaki: ";
	for (int x : IzdvojiGadne(in, true)) 
		cout << x << " ";
		
	cout << "\nOdvratni: ";
	for (int x : IzdvojiGadne(in, false)) 
		cout << x << " ";

	return 0;
}
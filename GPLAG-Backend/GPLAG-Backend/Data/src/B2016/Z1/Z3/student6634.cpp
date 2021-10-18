/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

using std::vector;
typedef vector<double> vd;

vector<vd> podnizovi(vd in, bool rastuci) {
	vector<vd> rez;
	bool monoton = false;
	vd podniz;
	auto vel = in.size();
	for (unsigned long long i = 1; i < vel; i++) {
		double trenutni = in[i], prosli = in[i-1];
		bool dobar = rastuci ? prosli <= trenutni : prosli >= trenutni;
		if (monoton && dobar) 
			podniz.push_back(trenutni);
		if (monoton && !dobar) {
			monoton = false;
			rez.push_back(podniz);
			podniz = {};
		}
		if (!monoton && dobar) {
			monoton = true;
			podniz.push_back(prosli);
			podniz.push_back(trenutni);
		}
	}
	if (podniz.size() != 0)
		rez.push_back(podniz);
	return rez;
}

vector<vd> RastuciPodnizovi(vd in) {
	return podnizovi(in, true);
}

vector<vd> OpadajuciPodnizovi(vd in) {
	return podnizovi(in, false);
}

int main() {
	using std::cout;
	using std::cin;
	
	cout << "Unesite broj elemenata vektora: ";
	int n;
	cin >> n;
	
	if (n < 0) return 0;
	
	cout << "Unesite elemente vektora: ";
	vd in(n);
	
	for (int i = 0; i < in.size(); i++)
		cin >> in[i];
	
	cout << "Maksimalni rastuci podnizovi: \n";
	for (auto const niz : RastuciPodnizovi(in)) {
		for (auto x : niz)
			cout << x << " ";
		cout << '\n';
	}
	
	cout << "Maksimalni opadajuci podnizovi: \n";
	for (auto const niz : OpadajuciPodnizovi(in)) {
		for (auto x : niz)
			cout << x << " ";
		cout << '\n';
	}
	
	return 0;
}
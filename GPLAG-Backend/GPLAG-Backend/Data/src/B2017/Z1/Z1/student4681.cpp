/*B 2017/2018, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

bool proslo(int n) {
	for(int i = 2; i <= std::sqrt(n); i++)
		if(n%i == 0 || n < 0) return false;
	if(n > 1) return true;
	if(n <= 1) return false;
}

bool returntri(double nume) {
	vector<double> tri;
	int numtri(0), count(0);
	int num = nume;
	do {
		tri.insert(tri.begin(), num%3);
		numtri += num%3 * std::pow(10,count);
		num /= 3;
		count++;
	} while(num!=0);
	if(tri.size()%2 == 0) {
		for(int i = 0; i < tri.size()/2; i++)
			if(tri.at(i) != tri.at(tri.size()-1-i)) return false;
	} else {
		for(int i = 0; i < (tri.size()-1)/2; i++)
			if(tri.at(i) != tri.at(tri.size()-1-i)) return false;
	}

	return true;
}

vector<double> IzdvojiSimetricneTernarne(vector<double> input, bool prosl) {
	vector<double> output(0), tri(0);
	bool pass = true;
	for(int i = 0; i < input.size(); i++)
		if((proslo(input.at(i)) && prosl) || (!proslo(input.at(i)) && !prosl))
			if(output.size() == 0) output.push_back(input.at(i));
			else { for(int j = 0; j < output.size(); j++)
					if(input.at(i) == output.at(j)) pass = false;
						if(pass) output.push_back(input.at(i));}
	vector<double> final(0);
	for(double x : output)
		if(returntri(x)) final.push_back(x);
	return final;
}

int main () {
	int i;
	vector<double> input(0);
	cout << "Unesite elemente vektora (-1 za kraj): ";
	for(;;) {
		cin >> i;
		if(i != -1) input.push_back(i);
		else break;
	}
	cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	cin >> i;
	while(i > 1 || i < 0) {
		cout << "Neispravan unos! Unesite ponovo: ";
		cin >> i;
	}
	bool prosl = false;
	if(i == 1) prosl = true;
	bool first = true;
	if(prosl) {
		if(IzdvojiSimetricneTernarne(input,prosl).size() == 0) cout << "Nema prostih simetricnih brojeva u vektoru.";
		else {
			cout << "Prosti simetricni brojevi iz vektora su: ";
			for(double x : IzdvojiSimetricneTernarne(input, prosl)) {
				if(first) {
					cout << x;
					first = false;
				} else cout << ", " << x;
			}
			cout << ".";
		}
	} else {
		if(IzdvojiSimetricneTernarne(input,prosl).size() == 0) cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else {
			cout << "Slozeni simetricni brojevi iz vektora su: ";
			for(double x : IzdvojiSimetricneTernarne(input, prosl)) {
				if(first) {
					cout << x;
					first = false;
				} else cout << ", " << x;
			}
			cout << ".";
		}
	}
	return 0;
}
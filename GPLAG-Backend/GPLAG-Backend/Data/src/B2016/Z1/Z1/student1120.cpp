/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>

std::vector<int> Pretvori3(int broj) {
	std::vector<int> v;
	
	if (broj < 0) {
		broj = -broj;
	}

	do {
		v.push_back(broj % 3);
		broj /= 3;
	} while (broj > 0);
	
	return v;
}

bool DaLiSadrzi(const std::vector<int> &v, int broj) {
	for (int x : v) {
		if (x == broj) {
			return true;
		}
	}
	
	return false;
}

bool DaLiJeOpak(int broj) {
	std::vector<int> cifre = Pretvori3(broj);
	std::vector<int> ponavljanja(3, 0);
	
	for (int c : cifre) {
		ponavljanja[c]++;
	}
	
	for (int p : ponavljanja) {
		if (p != 0 && p % 2 == 1) {
			return false;
		}
	}
	
	return true;
}

bool DaLiJeOpasan(int broj) {
	std::vector<int> cifre = Pretvori3(broj);
	std::vector<int> ponavljanja(3, 0);
	
	for (int c : cifre) {
		ponavljanja[c]++;
	}
	
	for (int p : ponavljanja) {
		if (p != 0 && p % 2 == 0) {
			return false;
		}
	}
	
	return true;
}

std::vector<int>IzdvojiGadne(std::vector<int>v, bool a)
{
	std::vector<int> rez;

	for (int x : v) {
		if (a && DaLiJeOpak(x) && !DaLiSadrzi(rez, x)) {
			rez.push_back(x);
		} else if (!a && DaLiJeOpasan(x) && !DaLiSadrzi(rez, x)) {
			rez.push_back(x);
		}
	}
	
	return rez;
}

int main ()
{
	std::vector<int> v;

	std::cout<<"Unesite brojeve (0 za prekid unosa): Opaki: ";
	
	int broj;
	do {
		std::cin >> broj;
		
		if (broj != 0) {
			v.push_back(broj);
		}
	} while (broj != 0);
	
	auto opaki = IzdvojiGadne(v, true), opasni = IzdvojiGadne(v, false);
	
	for (int i : opaki) {
		std::cout << i << " ";
	}
	std::cout<<std::endl<<"Odvratni: ";
	for (int i : opasni) {
		std::cout << i << " ";
	}

	return 0;
}
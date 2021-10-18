/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool n) {
	std::vector<int> v1;
	int niz[3]{0,0,0};
	int broj;
	bool gadni, opaki, test;
	for (int i = 0; i < v.size(); i++) {
		test = true;
		for (int j = 0; j < i; j++) if (v[i] == v[j]) {
			test = false;
			break;
		}
		if (!test) continue;
		broj = v[i];
		int brojac(0);
		while (broj != 0 || brojac == 0) {
			niz[int(std::abs(broj%3))]++;
			broj/=3;
			brojac++;	
		}
		opaki = true;
		gadni = true;
		for (int j = 0; j < 3; j++) {
			if (niz[j]%2 != 0) opaki = false;
			else if (niz[j] != 0 && niz[j]%2 == 0) gadni = false; 
		}
		if ((n && opaki) || (!n && gadni)) v1.push_back(v[i]);
		for (int j = 0; j < 3; j++) niz[j] = 0;
	}
	return v1;
}

int main ()
{
	std::vector<int> v;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int broj;
	do {
		std::cin >> broj;
		while(!std::cin) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cin >> broj;
		}
		if (broj != 0) v.push_back(broj);
	} while (broj != 0);
	std::vector<int> k(IzdvojiGadne(v, true));
	std::cout << "Opaki: ";
	for(int i = 0; i < k.size(); i++) std::cout << k[i] << " ";
	k = IzdvojiGadne(v, false);
	std::cout << "\nOdvratni: ";
	for(int i = 0; i < k.size(); i++) std::cout << k[i] << " ";
	return 0;
}
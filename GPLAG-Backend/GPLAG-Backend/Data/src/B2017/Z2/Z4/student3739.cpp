/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <type_traits>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <string>

int BrojProstihFaktora (int x) {
	int brojac(0);
	for (int i=2; i<=x; i++) {
		if (x%i==0) {
			brojac++;
			x/=i;
			i=1;
		}
	}
	return brojac;
}

bool ViseProstihFaktora (int x, int y) {
	return (BrojProstihFaktora(x)>BrojProstihFaktora(y) || (BrojProstihFaktora(x)==BrojProstihFaktora(y) && x>y));
}

int f (int x, int y) { return -2*x+y; } 


template <typename Tip1, typename Tip2, typename Tip3>
void SortirajPodrucjeVrijednosti (Tip1 pocetak_prvog, Tip1 kraj_prvog, Tip2 pocetak_drugog, Tip3 pocetak_treceg, typename std::remove_reference<decltype(*pocetak_treceg)>::type f(typename std::remove_reference<decltype(*pocetak_prvog)>::type, typename std::remove_reference<decltype(*pocetak_prvog)>::type), bool funckija_za_sortiranje(typename std::remove_reference<decltype(*pocetak_prvog)>::type, typename std::remove_reference<decltype(*pocetak_prvog)>::type)) {
	
	auto temp(pocetak_prvog);
	auto kraj_drugog(pocetak_drugog);
	auto kraj_treceg(pocetak_treceg);
	while (temp!=kraj_prvog) {
		temp++; kraj_drugog++; kraj_treceg++;
	}
	
	std::sort(pocetak_prvog, kraj_prvog, funckija_za_sortiranje);
	std::sort(pocetak_drugog, kraj_drugog, funckija_za_sortiranje);
	
	auto trazeni(pocetak_treceg);
	typename std::remove_reference<decltype(*pocetak_treceg)>::type pomocni;
	
	while (pocetak_prvog!=kraj_prvog) {
		trazeni=std::find(pocetak_treceg, kraj_treceg, f(*pocetak_prvog, *pocetak_drugog));
		if (trazeni==kraj_treceg) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		pomocni=*pocetak_treceg;
		*pocetak_treceg=*trazeni;
		*trazeni=pomocni;
		pocetak_prvog++; pocetak_drugog++; pocetak_treceg++;
	}
	
	return;
}

void Unesi (std::vector<int> &v, std::string s) {
	std::cout << "Unesite elemente " << s << " vektora: ";
	for (int i=0; i<v.size(); i++) {
		std::cin >> v.at(i);
		for (int j=0; j<i; j++) {
			if (v.at(i)==v.at(j)) {
				i--;
				break;
			}
		}
	}
}

int main ()
{
	int n;
	std::vector<int> v1, v2, v3;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	v1.resize(n); v2.resize(n); v3.resize(n);
	
	Unesi(v1, "prvog");
	Unesi(v2, "drugog");
	Unesi(v3, "treceg");
	
	try {
		
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), f, ViseProstihFaktora);
		
		std::cout << std::endl << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:" << std::endl;
		for (int i=0; i<n; i++) std::cout << "f(" << v1.at(i) << ", " << v2.at(i) << ") = " << v3.at(i) << std::endl;
		
	}
	catch (std::exception &izuzetak) {
		std::cout << std::endl << "Izuzetak: " << izuzetak.what();
	}
	
	return 0;
}
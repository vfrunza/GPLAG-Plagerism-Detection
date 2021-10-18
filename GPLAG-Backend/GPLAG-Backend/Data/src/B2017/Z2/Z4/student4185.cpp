#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cmath>

bool DaLiJeProst (int n)
{
	bool prost(true);
	if(n < 0) n *= -1;
	int x = sqrt(abs(n));
	for(int i = 2; i <= x; i++) {
		if(n%i == 0) {
			prost = false;
			break;
		}
	}
	return prost;
}

template<typename Tip1, typename Tip2, typename Tip3, typename fun1, typename fun2>
void SortirajPodrucjeVrijednosti(Tip1 pocetak1, Tip1 kraj1, Tip2 pocetak2, Tip3 pocetak3, fun1 f1, fun2 f2)
{
	std::sort(pocetak1, kraj1, f2);
	Tip3 pocetak3_kopija1(pocetak3),pocetak3_kopija(pocetak3);
	int duzina(0);
	Tip1 Kopija_pocetak1(pocetak1), Kopija_kraj1(kraj1);
	
	while(Kopija_pocetak1 != Kopija_kraj1) { 
		duzina++;
		Kopija_pocetak1++;
	}
	std::sort(pocetak2, pocetak2 + duzina, f2);
	
	bool ima_ga(false);
	int brojac(0);
	
	while(pocetak1 != kraj1) {
	pocetak3_kopija1 = pocetak3;
		for(int i = 0; i < duzina; i++) {
			if(*pocetak3_kopija1 == f1(*pocetak1, *pocetak2)) {
				ima_ga = true;
				if(brojac != i) {
					auto tmp(*pocetak3_kopija1);
					*pocetak3_kopija1 = *(pocetak3_kopija1 - i + brojac);
					*(pocetak3_kopija1 - i + brojac) = tmp;
					break;
				}
			}
			pocetak3_kopija1++;
		}
		if(!ima_ga) throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
		ima_ga = false;
		pocetak2++;
		pocetak1++;
		brojac++;
	}
	
}

int main ()
{
	std::vector<int> v1, v2, v3;
	int n(0);
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	std::cout << "Unesite elemente prvog vektora: ";
	int elem(0);
	bool ima_ga(false);
	for(;;) {
		std::cin >> elem;
		for(int j = 0; j < v1.size(); j++) {
			if(elem == v1[j]) ima_ga = true;
		}
		if(!ima_ga) v1.push_back(elem);
		ima_ga = false;	
		if(v1.size() == n) break;
	}
	
	std::cout << "Unesite elemente drugog vektora: ";
	for(;;) {
		std::cin >> elem;
		for(int j = 0; j < v2.size(); j++) {
			if(elem == v2[j]) ima_ga = true;
		}
		if(!ima_ga) v2.push_back(elem);
		ima_ga = false;
		if(v2.size() == n) break;
	}
	std::cout << "Unesite elemente treceg vektora: ";
	for(;;) {
		std::cin >> elem;
		for(int j = 0; j < v3.size(); j++) {
			if(elem == v3[j]) ima_ga = true;
		}
		if(!ima_ga) v3.push_back(elem);
		ima_ga = false;
		if(v3.size() == n) break;
	}
	try {
	SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), [] (int &x, int &y) { return -2*x + y;}, [] (int x, int y) -> bool {
		int brojac1(0), brojac2(0), kopijax(x), kopijay(y);
		for(int i = 2; i <= x; i++) {
			if(DaLiJeProst(i)) {
				if(kopijax%i == 0) {
					brojac1 ++;
					kopijax /= i;
					i--;
					if(kopijax == 1 || kopijax == -1) break;
				}
			}
		}
		for(int i = 2; i <= y; i++) {
			if(DaLiJeProst(i)) {
				if(kopijay%i == 0) {
					brojac2 ++;
					kopijay /= i;
					i--;
					if(kopijay == 1 || kopijay == -1) break;
				}
			}
		}
		if(brojac2 == brojac1) return x > y;
		return brojac1 > brojac2;
		
	});
	std::cout << std::endl << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: " << std::endl;
			for(int i = 0; i < n; i++) {
				std::cout << "f(" << v1[i] << ", " << v2[i] << ") = " << v3[i] <<std::endl;
			}
	
	} catch (std::logic_error Izuzetak) {
		std::cout << std::endl <<"Izuzetak: " << Izuzetak.what();
	}
	
	return 0;
}
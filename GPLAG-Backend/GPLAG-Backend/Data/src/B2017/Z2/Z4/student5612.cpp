#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

int BrojProstihFaktora(int broj)
{
	int broj_prostih_faktora(0);
	for(int i = 2; i < broj/i; i++) {
		while(broj % i == 0) {
			broj_prostih_faktora++;
			broj = broj / 2;
		}
	}
	if(broj > 1) {
		broj_prostih_faktora++;
	}
	return broj_prostih_faktora;
}

/*
bool OpadajuciPoBrojuProstihFaktora(int x, int y)
{
	if(BrojProstihFaktora(x) == BrojProstihFaktora(y)) {
		if(x > y) return x;
		return y;
	} else {
		if(BrojProstihFaktora(x) > BrojProstihFaktora(y)) return x;
		return y;
	}
}
*/

template <typename TIP1, typename TIP2, typename TIP3>
void SortirajPodrucjeVrijednosti(TIP1 *pocetak_bloka1, TIP1 *iza_kraja_bloka1,
                                 TIP2 *pocetak_bloka2, TIP3 *pocetak_bloka3, TIP3 f(TIP1, TIP2),
                                 bool g(TIP1, TIP2))
{
	TIP1 *pomocni1(pocetak_bloka1);
	TIP1 *pomocni2(iza_kraja_bloka1);

	int broj_elemenata_u_blokovima(0);
	while(pomocni1 != pomocni2) {
		broj_elemenata_u_blokovima++;
	}

	TIP2 *iza_kraja_bloka2(pocetak_bloka2 + broj_elemenata_u_blokovima);
	TIP3 *iza_kraja_bloka3(pocetak_bloka3 + broj_elemenata_u_blokovima);

	std::sort(pocetak_bloka1,iza_kraja_bloka1,g);
	std::sort(pocetak_bloka2,iza_kraja_bloka2,g);

	int index1(0);
	while(pocetak_bloka1 != iza_kraja_bloka1 && pocetak_bloka2 != iza_kraja_bloka2) {

		auto vrijednost(f(*pocetak_bloka1,*pocetak_bloka2));
		int index2(0);
		while(pocetak_bloka3 != iza_kraja_bloka3) {
			if(*pocetak_bloka3 == vrijednost) {
				std::cout << "f(" << *pocetak_bloka1 << "," << *pocetak_bloka2 << ") = " << vrijednost << std::endl;
				break;
				//Treba premjestiti da isti index
			}
			index2++;
			pocetak_bloka3++;
		}
		pocetak_bloka1++;
		pocetak_bloka2++;
		index1++;
	}
}

int main ()
{
	std::cout << "Unesite broj elemenata: ";
	int broj_elemenata;
	std::cin >> broj_elemenata;


	std::cout << "Unesite elemente prvog vektora: ";
	std::vector<int> s1;
	do {
		int element;
		std::cin >> element;
		int i(0);
		for(; i < s1.size(); i++) {
			if(s1.at(i) == element)
				break;
		}
		if(i == s1.size()) s1.push_back(element);
	} while(s1.size() != broj_elemenata);


	std::cout << "Unesite elemente drugog vektora: ";
	std::vector<int> s2;
	do {
		int element;
		std::cin >> element;
		int i(0);
		for(; i < s2.size(); i++) {
			if(s2.at(i) == element)
				break;
		}
		if(i == s2.size()) s2.push_back(element);
	} while(s2.size() != broj_elemenata);


	std::cout << "Unesite elemente treceg vektora: ";
	std::vector<int> s3;
	do {
		int element;
		std::cin >> element;
		int i(0);
		for(; i < s3.size(); i++) {
			if(s3.at(i) == element)
				break;
		}
		if(i == s3.size()) s3.push_back(element);
	} while(s3.size() != broj_elemenata);

	std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: " << std::endl;

	SortirajPodrucjeVrijednosti(&s1[0],&s1[s1.size()],&s2[0],&s3[0],[](int x, int y) {
		return -2*x + y;
	},
	[](int x, int y) -> bool {
		if(BrojProstihFaktora(x) == BrojProstihFaktora(y)) {
			if(x > y) return x;
			return y;
		} else {
			if(BrojProstihFaktora(x) < BrojProstihFaktora(y)) return y;
			return x;
		}
	});

	return 0;
}
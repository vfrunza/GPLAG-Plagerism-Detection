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
#include <algorithm>
#include <stdexcept>
#include <vector>

using namespace std;

int F (int x, int y) {
	return (- 2 * x + y);
}

int BrojProstihFaktora (int broj) {
	int brojac(0);
	if (broj == 1) brojac++;
	else {
		int k = broj % 2;
			while(k == 0) {
				int b = broj / 2;
				brojac++;
				broj = b;
				k = broj % 2;
			}
			for (int i = 3 ; i <= broj ; i += 2) {
				int m = broj % i;
					while (m == 0) {
						int c = broj / i;
						brojac++;
						broj = c;
						m = broj % i;
					}
			}
	}
	return brojac;
}

bool FunkcijaKriterija (int broj1, int broj2) {
	if (BrojProstihFaktora(broj1) == BrojProstihFaktora(broj2)){
		return broj1 > broj2;
	}
		return BrojProstihFaktora(broj1) > BrojProstihFaktora(broj2);
}

template <typename IterTip1, typename IterTip2, typename IterTip3>
void SortirajPodrucjeVrijednosti (IterTip1 pok_na_poc1, IterTip1 pok_na_kraj1, IterTip2 pok_na_poc2, IterTip3 pok_na_poc3,
decltype(*pok_na_poc3 + *pok_na_poc3) f (decltype(*pok_na_poc1 + *pok_na_poc2)m, decltype(*pok_na_poc1 + *pok_na_poc2)n), bool f2 (decltype(*pok_na_poc1 + *pok_na_poc2)m,decltype(*pok_na_poc1 + *pok_na_poc2)n)) {
	int broj_el(0);
	IterTip1 pom = pok_na_poc1;
	while (pom != pok_na_kraj1) {
		broj_el++;
		pom++;
	}
	IterTip2 pom1 = pok_na_poc2;
	for (int i = 0 ; i < broj_el ; i++)
		pom1++;
	IterTip1 pom_za_sort1 = pok_na_poc1;
	IterTip2 pom_za_sort2 = pok_na_poc2;
	sort(pom_za_sort1, pok_na_kraj1, f2);
	sort(pom_za_sort2, pom1, f2);
	
	int index;
	IterTip1 pomocni_na_prvi_blok = pok_na_poc1;
	IterTip2 pomocni_na_drugi_blok = pok_na_poc2;
	IterTip3 pomocni_na_treci_blok = pok_na_poc3;
	IterTip3 pomocni_na_kraj_treceg = pok_na_poc3;
		for (int j = 0 ; j < broj_el ; j++)
			pomocni_na_kraj_treceg++;
	for (int i = 0 ; i < broj_el ; i++) {
		decltype (*pok_na_poc2 + *pok_na_poc2) vrijednost = f(*pomocni_na_prvi_blok, *pomocni_na_drugi_blok);
		index = i;
		IterTip3 it = find(pomocni_na_treci_blok, pomocni_na_kraj_treceg, vrijednost);
		if (it != pomocni_na_kraj_treceg) {
			decltype(*pok_na_poc3 + *pok_na_poc3) tmp;
			IterTip3 pomocni_3(pok_na_poc3);
				for (int k = 0 ; k < index ; k++)
					pomocni_3++;
				tmp = *it;
				*it = *pomocni_3;
				*pomocni_3 = tmp;
		}
		else {
			throw logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
		}
		pomocni_na_prvi_blok++;
		pomocni_na_drugi_blok++;
		
	}
	
}

int main ()
{
	try {
		cout << "Unesite broj elemenata: ";
		int broj;
		cin >> broj;
		vector<int> prvi(broj), drugi(broj), treci(broj);
		cout << "Unesite elemente prvog vektora: ";
		int element1;
		for (int i = 0 ; i < broj ; i++) {
			cin >> element1;
			bool postoji1(false);
			for (int j = 0 ; j < broj ; j++) {
				if (prvi[j] == element1) {
					postoji1 = true;
					i--;
					break;
				}
			}
			if (!postoji1)
				prvi[i] = element1;
		}
					
		cout << "Unesite elemente drugog vektora: ";
		int element2;
		for (int i = 0 ; i < broj ; i++) {
			cin >> element2;
			bool postoji2(false);
			for (int j = 0 ; j < broj ; j++) {
				if (drugi[j] == element2){
					postoji2 = true;
					i--;
					break;
				}
			}
			if (!postoji2)
				drugi[i] = element2;
		}
		
		cout << "Unesite elemente treceg vektora: ";
		int element3;
		for (int i = 0 ; i < broj ; i++) {
			cin >> element3;
			bool postoji3(false);
			for (int j = 0 ; j < broj ; j++) {
				if (treci[j] == element3) {
					postoji3 =true;
					i--;
					break;
				}
			}
			if (!postoji3)
				treci[i] = element3;
		}
			
		SortirajPodrucjeVrijednosti(prvi.begin(), prvi.end(), drugi.begin(), treci.begin(), F, FunkcijaKriterija);
		cout << endl << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: " << endl;
		for (int i = 0 ; i < broj ; i++) {
			cout << "f(" << prvi[i] << ", " << drugi[i] << ") = " << treci[i] << endl;
		}
	}
	catch (logic_error izuzetak) {
		cout << endl << "Izuzetak: " << izuzetak.what();
	}
	
	return 0;
}
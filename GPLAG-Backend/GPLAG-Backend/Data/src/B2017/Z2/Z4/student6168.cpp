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
#include <vector>
#include <stdexcept>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
typedef std::vector<int> Vektor ;

Vektor UnosVektora (int n)
{
	Vektor vek;
	for (int i(0); i<n; i++) {
		int broj;
		cin >> broj;
		if (std::find(vek.begin(), vek.end(), broj)==vek.end())
			vek.push_back(broj);
		else
			i--;
	}
	return vek;
}

int BrojProstihFaktora (int broj)
{

	int max(broj/2+1), brojac(1);
	for (int i(2); i<max; i++) {
		if(broj%i==0) brojac++;
	}
	return brojac+1;
}

bool SortirajPoBrojuProstihFaktora (int prvi, int drugi)
{
	if(BrojProstihFaktora(prvi) == BrojProstihFaktora(drugi))
		return prvi>drugi;
	return BrojProstihFaktora(prvi) > BrojProstihFaktora(drugi);
}

int VrijednostFunkcije (int x, int y)
{
	return -2*x+y;
}


template <typename Tip1, typename Tip2, typename Tip3, typename Tip4, typename Tip5>

void SortirajPodrucjeVrijednosti(Tip1 p1, Tip1 k1, Tip2 p2, Tip3 p3, Tip4 f1, Tip5 f2)
{
	int brojac(k1-p1);
	std::sort(p1, k1, f2);
	std::sort(p2, p2+brojac, f2);
	int preklapanja(0);
	for (int i(0); i<brojac; i++) {
		int vrijednost = f1(p1[i], p2[i]);
		bool provjera = false;
		for (int j(0); j<brojac; j++) {
			if (vrijednost == p3[j]) {
				provjera = true;
			}
		}
		if(provjera) preklapanja++;
	}
	if (preklapanja!=brojac) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");

	for(int i(0); i<brojac; i++) {
		int vrijednost = f1(p1[i], p2[i]);
		for (int j(0); j<brojac; j++) {
			if (vrijednost == p3[j]) {
				auto temp(p3[i]);
				p3[i] = p3[j];
				p3[j] = temp;
			}
		}
	}
}

int main ()
{
	cout << "Unesite broj elemenata: ";
	int n;
	cin >> n;
	Vektor v1, v2, v3;
	cout << "Unesite elemente prvog vektora: ";
	v1 = UnosVektora(n);
	cout << "Unesite elemente drugog vektora: ";
	v2 = UnosVektora(n);
	cout << "Unesite elemente treceg vektora: ";
	v3 = UnosVektora(n);

	try {
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), VrijednostFunkcije, SortirajPoBrojuProstihFaktora);
	}

	catch (std::logic_error &izuzetak) {
		cout << endl << "Izuzetak: " << izuzetak.what();
		return 0;
	}

	cout << endl << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: " << endl;
	for (int i(0); i<n; i++) {
		cout << "f(" << v1[i] << ", " << v2[i] << ") = " << v3[i] << endl;
	}

	return 0;
}
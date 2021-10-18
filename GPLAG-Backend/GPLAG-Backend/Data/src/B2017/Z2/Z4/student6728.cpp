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
#include <type_traits>
#include <stdexcept>
#include <vector>

int f (int x, int y) {
	return (-2*x+y);
}


int BrojProstihFaktora(int x) {
	
	int broj(0);
	for (int i=1; i<=x; i++)
		if (x%i==0) broj++;

	return broj;
}


bool Kriterij (int x, int y) {
	
	if (BrojProstihFaktora(x)>BrojProstihFaktora(y)) return true;
	if (BrojProstihFaktora(x)==BrojProstihFaktora(y)) {
		if (x>y) return true;
		return false;
	}
	return false;
}


void u_nos(std::vector<int> &v, int n) {
	for (int i=0; i<n; i++)	{
		int element;
		std::cin >> element;
		bool ima(0);
		for (int j=0; j<v.size(); j++)
			if (v[j]==element) ima=1;
		if (ima==0) v.push_back(element);
		else i--;
	}
}


template <typename tip1, typename tip2, typename tip3>
void SortirajPodrucjeVrijednosti (tip1 p1, tip1 p2, tip2 p3, tip3 p4, decltype(*p4+*p4) f(decltype(*p1+*p1) x, decltype(*p1+*p1) y), bool kriterij(decltype(*p1+*p1) x, decltype(*p1+*p1) y)) {
	
	typedef typename std::remove_reference<decltype(*p4)>::type TipElementa3;
	
	std::sort(p1, p2, kriterij);
	int velicina(p2-p1);
	std::sort(p3, p3+velicina, kriterij);
	
	tip3 p;
	for (int i=0; p1<p2; p1++, p3++, i++) {
		TipElementa3 rezultat=f(*p1, *p3);
		bool ima(false);
		for (p=p4; p<p4+velicina; p++)
			if (*p==rezultat) {
				ima=true;
				break;
			}
		if (ima==false) throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
		else {
			TipElementa3 pomocna=p4[i];
			p4[i]=*p;
			*p=pomocna;
		}
	}
}


int main ()
{
	int n;
	
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	std::vector<int> v1, v2, v3;
	std::cout << "Unesite elemente prvog vektora: ";
	u_nos(v1, n);
	std::cout << "Unesite elemente drugog vektora: ";
	u_nos(v2, n);
	std::cout << "Unesite elemente treceg vektora: ";
	u_nos(v3, n);
	
	try {
		SortirajPodrucjeVrijednosti(std::begin(v1), std::end(v1), std::begin(v2), std::begin(v3), f, Kriterij);
	
		std::cout << std::endl << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: " << std::endl;
	
		for (int i=0; i<n; i++)
			std::cout << "f(" << v1[i] << ", " << v2[i] << ") = " << v3[i] << std::endl;
	}
	catch (std::logic_error e) {
		std::cout << std::endl << "Izuzetak: " << e.what(); 
	}
	
	return 0;
}
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
#include <cmath>
#include <algorithm>

bool ProstBroj(int a)
{
	if(a<=1) return false;
	for(int i(std::sqrt(a)); i>1; i--) if(a%i==0) return false;
	return true;
}

int BrojProstihFaktora(int a)
{
	int broj(0);
	for(int i(std::sqrt(a)); i>1; i--) {
		if(a%i==0 && ProstBroj(i)) {
			broj++;
			a/=i;
			i=std::sqrt(a)+1;
		}
	}
	return broj;
}

int fun1( int a, int b)
{
	return b-2*a;
}

bool fun2(int a, int b)
{
	int br1(BrojProstihFaktora(a)), br2(BrojProstihFaktora(b));
	if(br1==br2) return a>b;
	return br1>br2;
}

template <typename Tip1, typename Tip2, typename Tip3>
void SortirajPodrucjeVrijednosti(Tip1 prvi, Tip1 kraj, Tip2 drugi, Tip3 treci,
                                 typename std::remove_reference<decltype(treci[0])>::type f(typename std::remove_reference<decltype(prvi[0])>::type x, typename std::remove_reference<decltype(drugi[0])>::type y),
                                 bool g(typename std::remove_reference<decltype(prvi[0])>::type x, typename std::remove_reference<decltype(drugi[0])>::type y))
{
	std::sort(prvi, kraj, g);
	Tip1 pom1(prvi);
	Tip2 kraj2(drugi);
	while(pom1!=kraj) {
		pom1++;
		kraj2++;
	}
	std::sort(drugi, kraj2, g);
	pom1=prvi;
	Tip2 pom2(drugi);
	Tip3 kraj3(treci);
	while(pom1!=kraj) {
		pom1++;
		kraj3++;
	}
	pom1=prvi;
	while(pom1!=kraj) {
		auto a(f(*pom1, *pom2));
		auto s(std::find(treci, kraj3, a));
		if(s==kraj3) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		s=std::copy_backward(treci, s, s+1);
		*treci=a;
		pom1++;
		pom2++;
	}
	std::reverse(treci, kraj3);
}

int main ()
{
	std::cout << "Unesite broj elemenata: ";
	int n;
	std::cin >> n;
	try {
		std::vector<int> prvi(n), drugi(n), treci(n);
		std::cout << "Unesite elemente prvog vektora: ";
		for(int i(0); i<n; i++) {
			std::cin >> prvi.at(i);
			for(int j(0); j<i; j++) if(prvi.at(i)==prvi.at(j)) i--;
		}
		std::cout << "Unesite elemente drugog vektora: ";
		for(int i(0); i<n; i++) {
			std::cin >> drugi.at(i);
			for(int j(0); j<i; j++) if(drugi.at(i)==drugi.at(j)) i--;
		}
		std::cout << "Unesite elemente treceg vektora: ";
		for(int i(0); i<n; i++) {
			std::cin >> treci.at(i);
			for(int j(0); j<i; j++) if(treci.at(i)==treci.at(j)) i--;
		}
		SortirajPodrucjeVrijednosti(prvi.begin(), prvi.end(), drugi.begin(), treci.begin(), fun1, fun2);
		std::cout << "\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke:";
		for(int i(0); i<prvi.size(); i++) {
			std::cout << "\nf(" << prvi.at(i) << ", " << drugi.at(i) << ") = " << treci.at(i);
		}
	} catch(std::bad_alloc) {
		std::cout << "\nIzuzetak: Nedovoljno memorije";
	} catch(std::logic_error p) {
		std::cout << "\nIzuzetak: " << p.what();
	}
	return 0;
}
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

template <typename IterTip1, typename IterTip2, typename IterTip3, typename TIP1, typename TIP3>
void SortirajPodrucjeVrijednosti (IterTip1 pocetak, IterTip1 iza_kraja, IterTip2 pocetak2, IterTip3 pocetak3, TIP3 f(TIP1, TIP1), bool g(TIP1, TIP1)) {
	std::sort(pocetak, iza_kraja, g); //sortira prvi blok elemenata
	std::sort(pocetak2, pocetak2 + (iza_kraja-pocetak), g);
	while(pocetak != iza_kraja) {
		f(pocetak, pocetak2);
		pocetak++;
		pocetak2++;
	}
}

int main ()
{
	return 0;
}
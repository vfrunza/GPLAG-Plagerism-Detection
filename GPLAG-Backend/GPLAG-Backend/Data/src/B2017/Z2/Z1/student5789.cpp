/*B 2017/2018, Zadaća 2, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <list>
template <typename Tip>
void SortirajListu(std::list<Tip> &niz)
{
	auto it1(niz.begin());
    auto it2(niz.end());
	while(it1!=it2)
	{
		auto it3(it1);
		it3++;
		if(*it1<*it3) std::swap(*it1,*it3);
		it1++;
	}
}
int main ()
{
	return 0;
}
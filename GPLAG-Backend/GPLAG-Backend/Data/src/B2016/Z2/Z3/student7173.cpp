/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>

int main ()
{
	int niz[1], *p = niz;
	std::vector<int> v{1};
	//int *b = &v[0];
	v.resize(0);
	auto a = v.begin();
	std::cout << *a;
	//std::cout << *b;
	return 0;
}
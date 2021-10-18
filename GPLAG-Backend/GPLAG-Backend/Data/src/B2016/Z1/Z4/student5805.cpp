/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
int main ()
{
	std::vector<std::vector<int>> a;
	a.resize(10);
	for(int i = 0; i < 10; i++)	a[i].resize(5);
	std::cout << a.size() << a[0].size();
	return 0;
}
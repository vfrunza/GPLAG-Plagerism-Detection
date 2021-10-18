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
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
	
	vector<int> v1{5,8,4,7};
	
	vector<int> v2{1,2,3,4};
	
	auto p = new int[5]{5,8};
	
	for(int i = 0; i < 5;i++) cout<<*p++<<" ";
	
	return 0;
}
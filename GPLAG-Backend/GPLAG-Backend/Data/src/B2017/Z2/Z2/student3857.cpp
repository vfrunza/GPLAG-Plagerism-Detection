/*B 2017/2018, Zadaća 2, Zadatak 2
	
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
#include <type_traits>
#include <deque>
#include <stdexcept>
#include <algorithm>


bool DaLiJeProst (int n) // Ovu funkciju sam kopirao sa tutorijala 2; licno sam je napisao i radi ustede vremena je nisam ponovo kucao
{
	bool status = true;
	n=fabs(n);
	if (n>1) {
		for (int i=2; i<=std::sqrt(n); ++i) {
			if (n%i==0) {

				status = false;
				break;
			}

		}
	} else status = false;
	return status;
}






template <typename Tip1, typename Tip2>



int main ()
{
	return 0;
}
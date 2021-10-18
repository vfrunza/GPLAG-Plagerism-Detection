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
int main()
{
 int t;
 std::cout << "Unesite broj sati: ";
 std::cin >> t;
 double A = 10 + 0.5*t;
 double B = 0.8*t;
 (A>B)? std::cout << "Isplatnija je druga firma." : std::cout << "Isplatnija je prva firma.";
 return 0;
}
//(ako je A>B ispisuje prvu recenicu, za A<B ispisuje da je isplatnija prva firma)
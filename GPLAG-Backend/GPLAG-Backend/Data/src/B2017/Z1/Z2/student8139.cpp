/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>


int main ()
{
	
	try
{
	std::vector<std::vector<double>> m{{1, 2, 3}, {4, 5, 6}, {7, 8}};
	NajvecaPlaninaMatrice(m);
}
catch (const std::domain_error &e)
{
	std::cout << "Izuzetak: " << e.what() << std::endl;
}
catch(...)
{
	std::cout << "Pogrešan izuzetak!";
}
	return 0;
}
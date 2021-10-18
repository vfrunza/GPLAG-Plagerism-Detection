/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
bool prosti(int n)//PROVJERITI DA LI JE TAČNA !!!!!!!
{
	if(n == 1)
	   return false;
	for(int i = 2; i < n; i++)
	{
		if(n%i == 0)
		   return true;
	}
	return false;
}

bool ternarni(int broj)
{
	//Pretvaranje broja u ternarni i onda provjeravati da li je simetrican
	//vratiti true ili false u slucaju da je broj simetrican
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> vek, bool slozen)
{
	std::vector<int> novi;
	int vel = vek.size();
	

	
}


int main ()
{
	return 0;
}
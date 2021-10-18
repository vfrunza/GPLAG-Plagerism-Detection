/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include<iostream>
#include<vector>
#include<limits>

bool DaLiJeProst(int m)
{
	if(m<=1)
	m*=-1;

	for(int i=2 ; (unsigned int)(i*i)<=m ; i++)
	{
		if(m%i==0)
		 std::cout<<"Nema prostih brojeva!";
	}
	return m;
}
int main ()
{int a;
std::cout<<"Unesite elemente vektora (-1 za kraj): Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
std::cin>>a;
	return 0;
}
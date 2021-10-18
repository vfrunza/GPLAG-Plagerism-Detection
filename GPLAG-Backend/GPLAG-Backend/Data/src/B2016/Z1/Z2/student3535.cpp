/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica ;
 Matrica KreirajMatricu(int a,int b)
{
	return Matrica(a,std::vector<b>);
}

Matrica UnosMatrice(int br_redova,int br_kolona)
{
	auto m(KreirajMatricu(br_redova,br_kolona));
	int i,j,broj;
	for(i=0;i<br_redova;i++)
	{
		for(j=0;j<br_kolona;j++)
		{
			std::cout << "Elemnt (" <<i+1<<","<<j+1<<")" <<std::endl;
			std::cin >> broj;
			m[i][j].push_back(broj);
		}
	}
	return m;
}


int main ()
{
	
	int m,n;
	std::cout << "Unesite dva cijela broja m i n" << std::endl;
	std::cin >>m>>n ;
	auto matrica(UnosMatrice(m,n));
	return 0;
}
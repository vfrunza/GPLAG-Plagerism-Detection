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

int main ()
{
	
	int n,m;
	int k;
	std::cout << "Unesite dimenziju (x/y/z): ";
	do{
		std::cin >> n;
		if(n<0){
			std::cout << "Dimenzija nije ispravna, unesite opet: ";
			std::cin.clear();
			std::cin.ignore(1000,'\n');
		}}while(n<0);
	std::cout << "Unesite elemente kontejnera: ";
	for(int i=0;i<2*n*n;i++){
		std::cin >> m;
	}
	std::cout << "Unesite smjer kretanja [0 - 5]: ";
	do{
		std::cin >> k;
		if(k<0 || k>5){
			std::cout << "Smjer nije ispravan, unesite opet: ";
			std::cin.clear();
			std::cin.ignore(1000,'\n');
		}}while(k<0 || k>5);
	
	if(k){
		std::cout << "\nIzuzetak: 3D kontejner ne zadovoljava uvjet neparnosti";
	}
	
	
	
	
	
	
	return 0;
}
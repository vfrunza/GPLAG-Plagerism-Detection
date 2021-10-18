/*B 2017/2018, Zadaća 2, Zadatak 3
	
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
	int n;
	int m;
	int k;
	std::vector <int> v;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	if(n!=0){
	for(int i=0;i<n;i++){
		std::cin >> m;
		v.push_back(m);
		
	}}
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";;
	std::cin >> k;
	if(k==1 && n!=0){
		std::cout << "Izuzetak: Neispravan vektor!";
	}
	else if(n==0){
		std::cout << "Izuzetak: Prazan vektor!";
	}
	else{
		std::cout << "Izuzetak: Neispravan vektor!";
	}
	
	return 0;
}
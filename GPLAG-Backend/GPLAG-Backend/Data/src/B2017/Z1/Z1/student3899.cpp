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

void IzdvojiSimetricneTernarne(std::vector<int>a, bool prost) {
	std::vector<int>slozeni_brojevi;
	std::vector<int>prosti_brojevi;
	int broj;
	std::cin>>broj;
	for(int i=2; i<broj; i++) {
		if(broj%i==0){
			prost=false;
			slozeni_brojevi.push_back(broj);
			}
		else{
			prost=true;
			prosti_brojevi.push_back(broj); 
			}}
//	if (true) {
// pretvaranje iz decimalnog u ternarni
//	int p
	
	}

int main ()
{
	int broj;
	std::cout<<"Unesite brojeve: ";
	std::cin>>broj;
	return 0;
}
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
#include <cmath>
using namespace std;

bool isPrime (unsigned int a) {
	bool prost = true;
	if (a<=1) 
	prost=false;
	return prost;
	
	for (int i=2; i<=sqrt(a); i++) {
		
		if (a%i == 0) {
			prost = false;
			return prost;
		}
	}
	
}


IzdvojiSimetricneTernarne(vector<unsigned int> v, bool a);
{
	vector<unsigned int> prosti;
	vector<unsigned int> slozeni;

for (int i=0; i<v.size(); i++) {
	
	if(a) {
		if (isPrime(v.at(i))){
			prosti.pushback(v.at(i));
			
		}
	}
	
	if (!a) {
		if ( !(isPrime(v.at(i)))) {
			slozeni.pushback(v.at(i));
		}
		
		
	}
}


	int main () {

		return 0;
	}
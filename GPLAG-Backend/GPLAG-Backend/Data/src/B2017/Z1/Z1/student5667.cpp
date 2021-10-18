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
#include <iomanip>

bool Prost (int n){
	if(n < 0){
		n = n * (-1);
	}
	if(n == 0 || n == 1) return false;
	for(int i(2); i <= sqrt(n); i++){
		if(n % i == 0) return false;
	}
	return true;
}

std::vector<int> ProstiBrojevi(std::vector<int> c){
	std::vector<int> a;
	for(int i(0); i<c.size(); i++){
		if(Prost(c.at(i))) c.push_back(i) ;
		if(i == c.size()) break;
	}
	return a;
}

std::vector<int> Ternarni(std::vector<int> a){
	std::vector<int> d;
	int r;
	for(int i(0); i < a.size(); i++){
			int brojac(0);
			while(a.at(i) > 0){
			brojac++;
			r = a.at(i) % 3;
			a.at(i) /= 10;
			
		for(int j(0); j < d.size(); j++){
			d[j].resize(brojac);
			d[j].push_back(r);
		}
		}

		std::vector<int> vektor;
		vektor.push_back(n);
	}

	return vektor;
}

std::vector<int> IzdvojiSimetricneTernare(std::vector<int> a, bool b){
	a = ProstiBrojevi(a);
	Ternarni(a);
	int n = a.size();
	std::vector<int>simetricni;
	for(int i(0); i<n; i++){
		for(int y : a){
			if(x == a.at(i).size()-1-j){
				simetricni.push_back(a.at(j));
			}
		}
	}
	return simetricni;
}

int main () {
	
	
	return 0;
}
/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <deque>
#include <vector>


		bool StepenDvojke (int a) {
			
			for (int i=1; i<a; i*=2) {
				
				if (i==a)  return true;
			}
				return false;
		}

			std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, bool gore) {
		    int	brojacredova=0;
			std::vector<int> podniz;
			std::deque<std::vector<int>> kraj (brojacredova,podniz);
			
		
			if (gore) {
			
			for (int i=0; i<v.size(); i++) {
				
				int a=v.at(i);
			
				if (StepenDvojke(a)) {
			
					for (int j=(i+1); j<v.size()-1; j++) {
						a=v.at(i);
						int b=v.at(j);
						if(StepenDvojke(b) && a<=b ) 
						podniz.push_back(a);
						podniz.push_back(b);
						i=j;
				}
				 } else break;
				 brojacredova++;
				 kraj.resize(brojacredova);
				 kraj.push_back(podniz);
			}
		 } else {
				
				
				for (int i=0; i<v.size(); i++) {
					
					int c=v.at(0);
					
					if(StepenDvojke(c)) 
						
						podniz.push_back(c);
						
						for (int j=(i+1); j<v.size(); j++) {
							
						int d=v.at(j);
						if (StepenDvojke(d) && c>=d) {
							
						podniz.push_back(d);
					
					} else break;
				
					i=j;
						}				
					kraj.push_back(podniz);
					brojacredova++;
				} 
			} 
		 return kraj;
}

int main () {
	
	int n;
	
	std::cout << "Unesite broj elemenata vektora: " << std::endl;
	std::cin >> n;
	std::cout << "Unesi elemente vektora: ";
	std::vector<int> unos(n);
	
	for (int i=0; i<n; i++) {
		int broj;
		std::cin >> broj;
		unos.push_back(broj);
	}
	
	
	std::deque<std::vector<int>> Raste(MaksimalniPodnizoviStepenaDvojke(unos,true));
	std::deque<std::vector<int>> Opada(MaksimalniPodnizoviStepenaDvojke(unos,false));
	
	
	
	std::cout << "Rastuci: ";
		
	for (std::vector<int> red: Raste) { 
		for (int x: red) {
		std::cout << x;
	}
}
	return 0;
}
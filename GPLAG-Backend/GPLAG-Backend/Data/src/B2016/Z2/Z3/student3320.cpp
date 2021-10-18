/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <deque>
#include <vector>

template<typename tip1, typename tip2>

std::vector<std::vector<int>>UvrnutiPresjek(tip1 &x, tip1 &y, tip2 &a, tip2 &b, f) {
	
	return 
}

int main () {
	int POMOC;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int a;
	std::cin >> a;
	std::deque<int>kontejner1;
	
	for(int i=0; i<a; i++) {
		int temp;
		std::cin >> temp;
		kontejner1.push_back(temp);
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	int b;
	std::cin >> b;
	std::deque<int>kontejner2;
	
	for(int i=0; i<b; i++) {
		POMOC=1;
		int temp;
		std::cin >> temp;
		for(int j=0; j<kontejner1.size(); j++) {
			if(temp==kontejner1[j]) {
				POMOC=0;
			}
		}
		if(POMOC) kontejner2.push_back(temp);
	}
	
	std::cout << "Uvrnuti presjek kontejnera: ";
	std::vector<std::vector<int>>Matrica;
	Matrica=(std::begin(kontejner1), std::end(kontejner1), std::begin(kontejner2), std::end(kontejner2), )
	

	return 0;
}
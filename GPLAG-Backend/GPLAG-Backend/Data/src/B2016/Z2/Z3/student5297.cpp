/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

template <typename Tip, typename TipF, typename Tip1, typename Tip2>
std::vector<std::vector<TipF>> UvrnutiPresjek (Tip1 pocetak1, Tip1 kraj1, Tip2 pocetak2, Tip2 kraj2, TipF f (Tip)) {
	std::vector<std::vector<TipF>> matrica;
	while(pocetak1!=kraj1) {
		auto clan1=*pocetak1;
		auto poc2=pocetak2;
		while(poc2!=kraj2) {
			auto clan2=*poc2;
			if(f(clan1)==f(clan2)) {
				std::vector<TipF> vektor;
				vektor.push_back(clan1);
				vektor.push_back(clan2);
				vektor.push_back(f(clan1));
				bool nema(false);
				for(int i(0); i<matrica.size(); i++) {
					if(matrica[i][0]==vektor[0]) {
						for(int j(1); j<vektor.size(); j++) {
							if(matrica[i][j]==vektor[j] && nema==false) {
								nema=true;
							}
						}
					}
				}
				if(nema==false) matrica.push_back(vektor);
			}
			poc2++;
		}
		auto kra2=kraj2;
		kra2--;
		auto clan=*kra2;
		if(f(clan1)==f(clan)) {
			std::vector<TipF> vektorcic;
			vektorcic.push_back(clan1);
			vektorcic.push_back(clan);
			vektorcic.push_back(f(clan));
			bool nema(false);
			for(int i(0); i<matrica.size(); i++) {
				if(matrica[i][0]==vektorcic[0]) {
					for(int j(1); j<vektorcic.size(); j++) {
						if(matrica[i][j]==vektorcic[j] && nema==false) {
							nema=true;
						}
					}
				}
			}
			if(nema==false) matrica.push_back(vektorcic);
		}
		pocetak1++;
	}
	auto clan1=*pocetak1;
	kraj2--;
	auto clan2=*kraj2;
	if(f(clan1)==f(clan2)) {
		std::vector<TipF> vektor;
		vektor.push_back(clan1);
		vektor.push_back(clan2);
		vektor.push_back(f(clan1));
		bool nema(false);
		for(int i(0); i<matrica.size(); i++) {
			if(matrica[i][0]==vektor[0]) {
				for(int j(1); j<vektor.size(); j++) {
					if(matrica[i][j]==vektor[j] && nema==false) {
						nema=true;
					}
				}
			}
		}
		if(nema==false) matrica.push_back(vektor);
	}
	return matrica;
}



int SumaDjelilaca (int x) {
	int suma(0);
	do {
		suma+=abs(x%10);
		x/=10;
	} while(x!=0);
	return suma;
}

int main () {
	std::vector<int> v1;
	std::vector<int> v2;
	int br1, br2;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> br1;
	for(int i(0); i<br1; i++) {
		int broj;
		std::cin >> broj;
		v1.push_back(broj);
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> br2;
	for(int i(0); i<br2; i++) {
		int broj;
		std::cin >> broj;
		v2.push_back(broj);
	}
	
	auto matrica(UvrnutiPresjek<int, int>(v1.begin(), v1.end(), v2.begin(), v2.end(), SumaDjelilaca)); /*[] (int x) -> int {
		int suma(0);
		do {
			suma+=abs(x%10);
			x/=10;
		} while(x!=0);
		return suma;
	}));*/
	std::sort(matrica.begin(), matrica.end()); /*, [] (auto vektor1, auto vektor2) -> bool {
		if(vektor1[2]==vektor2[2]) {
			if(vektor1[1]==vektor2[1]) {
				return vektor1[0]<vektor2[0];
			}
			return vektor1[1]<vektor2[1];
		}
		return vektor1[2]<vektor2[2];
	});*/
	for(int i(0); i<matrica.size(); i++) {
		for(int j(0); j<matrica[i].size(); j++) {
			std::cout << matrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
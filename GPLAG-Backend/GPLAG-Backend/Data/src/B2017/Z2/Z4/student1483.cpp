/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cmath>

bool DaLiJeProst(int x){
	if(x < 2) return false;
	
	for(int i = 2; i < x; i++){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

int broj_prostih(int x){
	int brojac = 0;
	if(x == 1 || x == 0) return 1;
	x = abs(x);
	
	int i(2);
	while(x){
		if(i > x) return brojac;
		if(DaLiJeProst(i) && x % i == 0){
			brojac++;
			x /= i;
			i = 1;
		}
	
		i++;
	}
	return brojac;
}


bool sortiranje(int x, int y){
	if(broj_prostih(x) == broj_prostih(y)) return x > y;
	else return broj_prostih(x) > broj_prostih(y);
}

int funkcija(int x, int y){
	return -2*x + y;
}

template <typename IterTip1, typename IterTip3, typename IterTip4>
	void SortirajPodrucjeVrijednosti(IterTip1 it1, IterTip1 it2, IterTip3 it3, IterTip4 it4, decltype(*it4+0) F(decltype(*it1 + 0), decltype(*it3 + 0)), bool S(decltype(*it1 + 0), decltype(*it3 + 0))){
		//Sortiranje prvog bloka
		int broj_elemenata = it2 - it1;
		std::sort(it1, it2, S);
		
		/*for(int i = 0; i < broj_elemenata; i++){
			std::cout << *(it1 + i) << " ";
		}*/
		std::cout << std::endl;
		//Sortiranej drugog bloka
		std::sort(it3, it3 + broj_elemenata, S);
		/*for(int i = 0; i < broj_elemenata; i++){
			std::cout << *(it3 + i) << " ";
		}*/
		
		for(int i(0); i < broj_elemenata; i++){
			//Određivanje vrijednosti funkcije
			decltype(*it4 + 0) vrijednost = F(*(it1 + i),*(it3 + i));
			//Provjera da li je vrijednost u skupu S3
			bool DaLiJeUS3(false);
			int e;
			for(e = 0; e < broj_elemenata; e++){
				if(vrijednost == *(it4 + e)){
					DaLiJeUS3 = true;
					break;
				}
			}
			if(!DaLiJeUS3) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
			//U ovom trenutku znamo da dobijena vrijednost priprada rangu funkcije
			//Još nam preostaje da isprepomještamo vrijednosti ranga
			decltype(*it4 + 0) temp = *(it4 + i);
			*(it4 + i) = vrijednost;
			*(it4 + e) = temp;
			
			
		}
		
	}

int main (){
	try{
		int broj_elemenata;
		std::cout << "Unesite broj elemenata: ";
		//std::cout << broj_prostih(-5) << " " << broj_prostih(1) << std::endl;
		std::cin >> broj_elemenata;
		std::vector<int> v1,v2,v3;
		std::cout << "Unesite elemente prvog vektora: ";
		
		int brojac(0);
		do{
			int unos;
			std::cin >> unos;
			bool ima_ga = false;
			for(int a : v1){
				if(unos == a) ima_ga = true;
			}
			if(!ima_ga){
				v1.push_back(unos);
				brojac++;
			}
		}while(brojac < broj_elemenata);
		
		
		std::cout << "Unesite elemente drugog vektora: ";
		
		brojac = 0;
		do{
			int unos;
			std::cin >> unos;
			bool ima_ga = false;
			for(int a : v2){
				if(unos == a) ima_ga = true;
			}
			if(!ima_ga){
				v2.push_back(unos);
				brojac++;
			}
		}while(brojac < broj_elemenata);
		
		std::cout << "Unesite elemente treceg vektora: ";
		brojac = 0;
		do{
			int unos;
			std::cin >> unos;
			bool ima_ga = false;
			for(int a : v3){
				if(unos == a) ima_ga = true;
			}
			if(!ima_ga){
				v3.push_back(unos);
				brojac++;
			}
		}while(brojac < broj_elemenata);
		
		std::cout << std::endl;
		
		std::vector<int>::iterator it1(v1.begin());
		std::vector<int>::iterator it2(v1.end());
		std::vector<int>::iterator it3(v2.begin());
		std::vector<int>::iterator it4(v3.begin());
		
		SortirajPodrucjeVrijednosti(it1, it2, it3, it4, funkcija, sortiranje);
		
		std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:" << std::endl;
		for(int i = 0; i < broj_elemenata; i++){
			std::cout << "f(" << *(it1 + i) << ", " << *(it3 + i) << ") = " << *(it4 + i) << std::endl;
		}
		
		
	}catch(std::logic_error &e){
		std::cout <<"Izuzetak: "<< e.what() << std::endl;
	}
	return 0;
}
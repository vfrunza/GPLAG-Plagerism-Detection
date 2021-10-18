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
#include <deque>

bool DaLiJeProst(int broj) {
	
	for (int i = 2; i <= std::sqrt(broj); i++) {
		if (broj%i == 0) {
			return false;
		}
	}
	return true;
}

bool DaLiJeSimetrican (int Broj) { 
	
	std::deque<int> dek;
	
	while (Broj != 0) {
		dek.push_front(Broj%3);
		Broj /= 3;
	}
	
	for (int i = 0, j = dek.size() - 1; i < j; i++, j--) {
		if (dek.at(i) != dek.at(j)) {
			return false;
		}
	}
	return true;
	
}


std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> DobijeniVektor, bool HocuProste) {
	
	std::vector<int> NoviVektor;
		
		if (HocuProste) {
			
			for (int i = 0; i < DobijeniVektor.size(); i++) {
				
				int TestBroj = std::abs(DobijeniVektor.at(i));
				bool ImaGa(false);
		
				if(DaLiJeProst(TestBroj) && (DaLiJeSimetrican(TestBroj))) {
					
					for (auto x : NoviVektor) {
						if (x == DobijeniVektor.at(i)) ImaGa = true;
					}
					if(!ImaGa) {
						NoviVektor.push_back(DobijeniVektor.at(i));
					}
				}
			}
			return NoviVektor;
	    }
	    else {
	    	
	    	for (int i = 0; i < DobijeniVektor.size(); i++) {
				
				int TestBroj = std::abs(DobijeniVektor.at(i));
				bool ImaGa(false);
				
				if(!DaLiJeProst(TestBroj) && (DaLiJeSimetrican(TestBroj))) {
					
					for (auto x : NoviVektor) {
						if (x == DobijeniVektor.at(i)) ImaGa = true;
					}
					if(!ImaGa) {
						NoviVektor.push_back(DobijeniVektor.at(i));
					}
				}
			}
			return NoviVektor;
	    }
}

int main ()
{
	int n,a;
	
	std::vector<int> Pocetni;
	
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	
	while (std::cin >> n, n != -1) {
		Pocetni.push_back(n);
	}
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> a;
	while(a != 0 && a != 1){
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> a;
	}
	
	std::vector<int> Konacni = IzdvojiSimetricneTernarne(Pocetni, a);
   
	if(a == 1) {
		if(Konacni.size() == 0) {
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
	    for (auto x : Konacni) {
			if(x == Konacni.at(Konacni.size()-1)) std::cout << x << ".";
			else{
				std::cout << x << ", ";
			}
	    }	
	}
	else{
		if(Konacni.size() == 0) {
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for (auto x : Konacni) {
			if(x == Konacni.at(Konacni.size()-1)) std::cout << x << ".";
			else{
				std::cout << x << ", ";
			}
		}
	}
	return 0;
}

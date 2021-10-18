/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>

bool ProvjeraOp (int broj) {
	int ostatak(0);
	std::vector<long long int> brojac(3, 0);
	do{
		ostatak=broj%3;
		if(ostatak<0) ostatak*=-1;
		broj/=3;
		brojac[ostatak]++;
	}while(broj!=0); 
	for(int i(0); i<brojac.size(); i++) {
		if(brojac[i]==0) continue;
		else if(brojac[i]%2==0) continue;
		else return false;
	}
	return true;
}

bool ProvjeraOd (int broj) {
	int ostatak(0);
	std::vector<long long int> brojac(3, 0);
	if(broj==0) return false;
	do{
		ostatak=broj%3;
		if(ostatak<0) ostatak*=-1;
		broj/=3;
		brojac[ostatak]++;
	}while(broj!=0); 
	for(int i(0); i<brojac.size(); i++) {
		if(brojac[i]==0) continue;
		else if(brojac[i]%2==1) continue;
		else return true;
	}
	return false;
}

std::vector<int> IzdvojiGadne (std::vector<int> stari, bool vrijednost) {
	bool parnost(true);
	std::vector<int> novi;
	int petlja(0);
	if(vrijednost) {
		for(int element: stari) {
			parnost=ProvjeraOp(element);
			if(parnost==vrijednost) {
				if(petlja==0) {
					novi.push_back(element);
					petlja++;
				} else {
					int postoji(0);
					for(int i: novi) {
 						if(i!=element) continue;
						else if(i==element) {
							postoji=1;
							break;
						}
					}
					if(postoji==0) novi.push_back(element);
				}
			}
		} 
	} else if(vrijednost==false) {
		for(int element: stari) {
			parnost=ProvjeraOd(element);
			if(parnost==vrijednost) {
				if(petlja==0) {
					novi.push_back(element);
					petlja++;
				} else {
					int postoji(0);
					for(int i: novi) {
						if(i!=element) continue;
						else if(i==element) {
							postoji=1;
							break;
						}
					}
					if(postoji==0) novi.push_back(element);
				}
			}
		}
	}
	return novi;
}

void Ispisi (std::vector<int> vektor) {
	for(int i(0); i<vektor.size(); i++) {
		std::cout << vektor[i] << " ";
		if(i==vektor.size()-1) break;
	}
}


int main () {
	std::vector<int> vektor;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(;;) {
		int element;
		std::cin >> element;
		if(!std::cin) {
			std::cout << "Niste unijeli broj!" << std::endl;
			std::cin.clear();
			std::cin.ignore(100000, '\n');
		}
		else if(element==0) {
			break;
		}	
		else { 
			vektor.push_back(element);
		} 
	}
	auto opaki(IzdvojiGadne(vektor, true));
	auto odvratni(IzdvojiGadne(vektor, false));
	std::cout << "Opaki: ";
	Ispisi(opaki);
	std::cout << std::endl << "Odvratni: ";
	Ispisi(odvratni);
	return 0;
}
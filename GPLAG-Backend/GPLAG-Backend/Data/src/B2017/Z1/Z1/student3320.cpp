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
#include <iomanip>
#include <limits>
#include <cmath>
#include <deque>


bool DaLiJeProst(int n) { 	//Provjera jel prost ili slozen
	n=abs(n);
	if(n==2) return true;
//	int test;
//	test=sqrt(n)+1; //samo testiranje
	for(int i=2; i<sqrt(n)+1; i++) {
		if(n%i==0) return false;
	}
	return true;
}

bool Simetrija(int n) {			//Provjera funkcija za simetrijom 
	std::vector<int>temp;
	int brojac, broj;
	int cuvar;
	
	cuvar=abs(n);
		
	brojac=0;
	do {
		broj=pow(3, brojac);
		if(broj==std::numeric_limits<int>::max()) return false;
		brojac++;
	}while(broj<=cuvar);
	brojac--;
	brojac--;//max eksponent uspostavljen 
		
	while(brojac>=0) {
		for(int i=2; i>=0; i--) {
			if(((pow(3,brojac))*i)>cuvar) continue;
			else {
				temp.push_back(i); 	//formiramo vector ternarnih cifara
				cuvar=cuvar-((pow(3,brojac))*i);
				brojac--;
				break;
			}
		}	
	}
	
	for(int i=0; i<temp.size(); i++) {
		if(temp.at(i)!=temp.at(temp.size()-i-1)) return false;
		else continue;
	}
	return true;
}

std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>brojevi, bool uslov) {	 //Funkcija koja se vraca u main 
	std::vector<int>prosti; 	//dva vectora gdje ce se spasavat brojevi odvojeno
	std::vector<int>slozeni;
	
	for(int i=0; i<brojevi.size(); i++) {							//petlja za razdvajanje brojeva po vectorima
		if(brojevi.at(i)<=1 && brojevi.at(i)>=-1) continue;
		if(DaLiJeProst(brojevi.at(i))) {
			prosti.push_back(brojevi.at(i));
		} else {
			slozeni.push_back(brojevi.at(i));
		}
	}
	
	if(uslov) {										//provjeravanje brojeva na simetriju u ternarnoj bazi
		for(int i=0; i<prosti.size(); i++) {
			if(Simetrija(prosti.at(i))) continue;
			else {
				prosti.erase(prosti.begin()+i);			//brise ako nije ternarni
				i--;
			}
		}
	} else {
		if(!uslov) {
			for(int i=0; i<slozeni.size(); i++) {
				if(Simetrija(slozeni.at(i))) continue;	
				else {
					slozeni.erase(slozeni.begin()+i);		//brise ako nije ternarni
					i--;
				}		
			}
		}
	}
	
	if(uslov) return prosti;
	return slozeni;
}

int main () {
	std::vector<int>brojevi;
	std::vector<int>rez;
	int test;
	
	int broj;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin >> broj;
		if(broj==std::numeric_limits<int>::max()) continue;
		if(broj!=-1) brojevi.push_back(broj);
	}while(broj!=-1);
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> test;
izuzetak:	
	if(test==0 || test==1) {
		goto dalje;
	} else {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin.clear();
		std::cin >> test;
		goto izuzetak;
	}
dalje:	
	rez=IzdvojiSimetricneTernarne(brojevi, test);
	
	if(test==1) {
		if(rez.size()==0) {
			std::cout << "Nema prostih simetricnih brojeva u vektoru."; 
			return 0;
		} else {
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<rez.size(); i++) {
				if(i!=rez.size()-1) {
					std::cout << rez.at(i) << ", ";
				} else {
					std::cout << rez.at(i) << ".";
				}
			}
		}
	} else {
		if(test==0) {
			if(rez.size()==0) {
				std::cout << "Nema slozenih simetricnih brojeva u vektoru."; 
				return 0;
			} else {
				std::cout << "Slozeni simetricni brojevi iz vektora su: ";
				for(int i=0; i<rez.size(); i++) {
					if(i!=rez.size()-1) {
						std::cout << rez.at(i) << ", ";
					} else {
						std::cout << rez.at(i) << ".";
					}
				}
			}
		}
	}
	return 0;
} 


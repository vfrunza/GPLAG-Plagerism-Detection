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
#include <vector>
#include <deque>
#include <cmath>

const double epsilon=0.000000000001;

enum Smjer{Rastuci=1,Opadajuci};

bool Stepen_broja_dva(int n){
	
	for(int i=0; i<n; i++){
		if(fabs(log(n)/log(2)-i)<epsilon) return true;
	}
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> vektor, Smjer s){
	std::deque<std::vector<int>> dek;
	if(s==Rastuci){	
		for(int i=0; i<vektor.size(); i++){
			if(vektor.at(i)>0 && Stepen_broja_dva(vektor.at(i))){
				std::vector<int> podniz;
				for(;;){
					i++;
					if(i>=vektor.size()) break;
					else if(vektor.at(i)>=vektor.at(i-1) && Stepen_broja_dva(vektor.at(i)) && podniz.size()==0){
						podniz.push_back(vektor.at(i-1));
						podniz.push_back(vektor.at(i));
					}
					else if(vektor.at(i)>=vektor.at(i-1) && Stepen_broja_dva(vektor.at(i))) podniz.push_back(vektor.at(i));
					else{
						i--;
						break;
					} 
				}
				if(podniz.size()>0) dek.push_back(podniz);	
			}	
		}
	}
	else{
		if(vektor.size()>0){
			for(int i=int(vektor.size())-1; i>=0; i--){
				if(vektor.at(i)>0 && Stepen_broja_dva(vektor.at(i))){
					std::vector<int> podniz;
					for(;;){
						i--;
						if(i<0) break;
						else if(vektor.at(i)>=vektor.at(i+1) && Stepen_broja_dva(vektor.at(i)) && podniz.size()==0){
							podniz.insert(podniz.begin(), vektor.at(i+1));
							podniz.insert(podniz.begin(), vektor.at(i));
						}
						else if(vektor.at(i)>=vektor.at(i+1) && Stepen_broja_dva(vektor.at(i))) podniz.insert(podniz.begin(), vektor.at(i));
						else{
							i++;
							break;
						} 
					}
					if(podniz.size()>0) dek.push_front(podniz);	
				}
			}
		}
	}

	return dek;
}

int main ()
{
	std::deque<std::vector<int>> Stepeni_dvojke;
	std::cout << "Unesite broj elemenata vektora: ";
	int broj_elmenata;
	std::cin >> broj_elmenata;
	std::vector<int> niz;
	std::cout << "Unesite elemente vektora: ";
	if(broj_elmenata>0){	
		for(;;){
			int broj;
			std::cin >> broj;
			niz.push_back(broj);
			if(niz.size()==broj_elmenata) break;
		}
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int s;
	std::cin >> s;
	Smjer smjer=Smjer(s);
	Stepeni_dvojke=MaksimalniPodnizoviStepenaDvojke(niz, smjer);
	if(smjer==Rastuci){	
		std::cout << "Maksimalni rastuci podnizovi:\n";
		for(int i=0; i<Stepeni_dvojke.size(); i++){
			for(int j=0; j<Stepeni_dvojke.at(i).size(); j++){
				std::cout << Stepeni_dvojke.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	}
	else{
		std::cout << "Maksimalni opadajuci podnizovi:\n";
		for(int i=0; i<Stepeni_dvojke.size(); i++){
			for(int j=0; j<Stepeni_dvojke.at(i).size(); j++){
				std::cout << Stepeni_dvojke.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	}
	return 0;
}
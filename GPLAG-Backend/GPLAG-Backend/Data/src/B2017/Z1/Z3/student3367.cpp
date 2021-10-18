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
enum Smjer { Rastuci = 1, Opadajuci = 2};
bool daLiJeStepenDvojke(int broj){
	int n = 1;
	while(n <= broj){
		if(n == broj) return true;
		n*=2;
	}
	return false;
}
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> vektor, Smjer smjer){
	std::deque<std::vector<int>> dek;
	if(smjer == Rastuci){
		for(int i = 0; i < vektor.size()-1; i++){
			if(daLiJeStepenDvojke(vektor.at(i))){
				int j = i+1;
				if(vektor.at(j) > vektor.at(i)){
					if(daLiJeStepenDvojke(vektor.at(j))){
						std::vector<int> v;
						v.push_back(vektor.at(i));
					
						while(vektor.at(j) > vektor.at(j-1) && daLiJeStepenDvojke(vektor.at(j))){
							v.push_back(vektor.at(j));
							if(j == vektor.size()-1) break;
							j++;
						}
						dek.push_back(v);
						i = j -1;
					}
					
				}
			}
		}
	}
	else {
		for(int i = 0; i < vektor.size()-1; i++){
			if(daLiJeStepenDvojke(vektor.at(i))){
				int j = i+1;
				if(vektor.at(j) < vektor.at(i)){
					if(daLiJeStepenDvojke(vektor.at(j))){
						std::vector<int> v;
						v.push_back(vektor.at(i));
						while(vektor.at(j) < vektor.at(j-1) && daLiJeStepenDvojke((vektor.at(j))) && j < vektor.size()){
							
							v.push_back(vektor.at(j));
							if( j == vektor.size()-1) break;
							j++;
						}
						
						dek.push_back(v);
						i = j-1;
					}
				}
			}
		}
	}
	return dek;
}
int main ()
{
	int n; 
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin>> n; 
	std::vector<int> v;
	std::cout << "Unesite elemente vektora: ";
	while(n>0){
		int k = 0;
		std::cin>>k;
		v.push_back(k);
		n--;
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> n;
	Smjer s;
	if(n == 1) s= Rastuci;
	else s = Opadajuci;
	std::deque<std::vector<int>> dek = MaksimalniPodnizoviStepenaDvojke(v, s);
	if(n == 1) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	if(n == 2) std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i = 0; i < dek.size(); i++){
		for(int j = 0; j < dek.at(i).size(); j++)
			std::cout << dek.at(i).at(j) << " ";
		std::cout << std::endl;
	}
	return 0;
}
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
#include <cstdio>
#include <deque>
#include <cstdio>
#include <cmath>
enum Smjer{Rastuci=1,Opadajuci=2};
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> p,Smjer x){
	
	std::vector<int> vektor;
	for(int i=0;i<p.size();i++){
		if(p.at(i)<0){
			continue;
		}
		for(int j=1;j<=p.at(i);j*=2){
			if(j==p.at(i)){
				vektor.push_back(p.at(i));
				break;
			}
		}
	}
	std::deque<std::vector<int>> rez;
	std::vector<int> guranje;
	if(x==1){
	for(int i=0;i<vektor.size();i++){
		if(i==vektor.size()-1){
				if(guranje.size()!=0 && guranje.size()!=1){
					rez.push_back(guranje);
				}
				break;
			}
		if(guranje.size()==0){
		guranje.push_back(vektor.at(i));}
		if(vektor.at(i)<=vektor.at(i+1)){
			guranje.push_back(vektor.at(i+1));
			continue;
		}
		else if(guranje.size()!=1){
			rez.push_back(guranje);
		}
		guranje.resize(0);
		}}
		
	else if(x==2){
		for(int i=0;i<vektor.size();i++){
			if(i==vektor.size()-1){
				if(guranje.size()!=0 && guranje.size()!=1){
					rez.push_back(guranje);
				}
				break;
			}
		if(guranje.size()==0){
		guranje.push_back(vektor.at(i));}
		if(vektor.at(i)>=vektor.at(i+1)){
			guranje.push_back(vektor.at(i+1));
			continue;
		}
		else if(guranje.size()!=1){
			rez.push_back(guranje);
			
		}
		guranje.resize(0);
		}
		
	}	
		return rez;
	}
	


	int main(){	
		
		std::vector<int> s;
		Smjer k;
		int brojElemenata=0;
		int opcija=0;
		int n;
		std::cout << "Unesite broj elemenata vektora: ";
		std::cin >> brojElemenata;
		std::cout << "Unesite elemente vektora: ";
		for(int i=0;i<brojElemenata;i++){
			
			std::cin>>n;
			s.push_back(n);
		}
		std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
		std::cin>>opcija;
		if(opcija==1){
			k=Rastuci;
			std::deque<std::vector<int>> Finito(MaksimalniPodnizoviStepenaDvojke(s,k));
			std::cout << "Maksimalni rastuci podnizovi:\n";
			for(int i=0;i<Finito.size();i++){
				for(int j=0;j<Finito.at(i).size();j++){
					std::cout << Finito.at(i).at(j);
					std::cout << " ";
				}
				std::cout << "\n";
			}
		}
		else if(opcija==2){
			k=Opadajuci;
			std::deque<std::vector<int>> Finito(MaksimalniPodnizoviStepenaDvojke(s,k));
			std::cout << "Maksimalni opadajuci podnizovi:\n";
			for(int i=0;i<Finito.size();i++){
				for(int j=0;j<Finito.at(i).size();j++){
					std::cout << Finito.at(i).at(j);
					std::cout << " ";
				}
				
			std::cout << "\n";
		}}
	return 0;
}
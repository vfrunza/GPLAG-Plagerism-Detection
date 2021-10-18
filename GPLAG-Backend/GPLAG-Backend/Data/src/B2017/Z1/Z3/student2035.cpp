#include <iostream>
#include <vector>
#include <deque>

enum Smjer{Rastuci, Opadajuci};

bool DaLiJeStepenDvojke(int x) {
	if (x<1) return false; 
	while(x) {
	if(x==1) return true;
	if(x%2!=0) return false; 
	x=x/2;  }
	return true;
}


std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer neki_smjer) {
	std::deque<std::vector<int>> rezultat;
	int velicina(1);
	bool bio_rastuci(false); 
	bool bio_opadajuci(false);
	bool prvi_ulaz(true);
	if(neki_smjer==Rastuci) {
	for(unsigned int i=1; i<v.size(); i++) {
		if(!DaLiJeStepenDvojke(v.at(i))) continue; 
		if(v.at(i-1)<=v.at(i)) {
			if(!DaLiJeStepenDvojke(v.at(i-1))) continue;
			bio_rastuci=true; 
			rezultat.resize(velicina); 
			if(prvi_ulaz) rezultat.at(velicina-1).push_back(v.at(i-1));
			prvi_ulaz=false;
			rezultat.at(velicina-1).push_back(v.at(i)); 
			
		}
		else {
			if(bio_rastuci) {velicina++;
				bio_rastuci=false;
			}
			
			prvi_ulaz=true;
		}
	} }
	else if(neki_smjer==Opadajuci) {
		for(unsigned int i=1; i<v.size(); i++) {
			if(!DaLiJeStepenDvojke(v.at(i))) continue; 
			if(v.at(i-1)>=v.at(i))	 {
				if(!DaLiJeStepenDvojke(v.at(i-1))) continue; 
				bio_opadajuci=true;
				rezultat.resize(velicina);
				if(prvi_ulaz) rezultat.at(velicina-1).push_back(v.at(i-1));
				rezultat.at(velicina-1).push_back(v.at(i));
				prvi_ulaz=false;
			}	
			else {
				if(bio_opadajuci) {
					velicina++; 
					bio_opadajuci=false;
				}
				prvi_ulaz=true;
			}
		}
		
	}
	
	return rezultat; 
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: "; 
	int n; 
	std::cin >> n; 
	if(n<0) return 0; //ne znam sta u ovoj situaciji da radis, procitaj ponovno zadatak
	std::vector<int> vektor(n); 
	std::cout << "Unesite elemente vektora: "; 
	for(unsigned int i=0; i<n; i++)
	std::cin >> vektor.at(i);
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: "; 
	short a;
	std::cin >> a;
	if(a==1) {
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl; 
		std::deque<std::vector<int>> dek(MaksimalniPodnizoviStepenaDvojke(vektor, Rastuci)) ;
		for(auto a : dek) {
			for(auto x : a)
			std::cout << x << " ";
			std::cout << std::endl; 
		}
		
	}
	
	if(a==2) {
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl; 
		std::deque<std::vector<int>> dek(MaksimalniPodnizoviStepenaDvojke(vektor, Opadajuci)); 
		for (auto a : dek) {
			for(auto x : a)
			std::cout << x << " ";
			std::cout << std::endl; 
		}
	}
	
	
	return 0;
}
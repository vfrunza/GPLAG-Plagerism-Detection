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

enum Smjer {Rastuci=1, Opadajuci};
Smjer trenutni_smjer;

bool StepenBrojaDva (int n){
	if(n<=0) return false;
	if(n==1) return true;
	while(n>2 && n%2==0) n/=2;
	if(n%2==0) return true;
	return false;
}


std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> a, Smjer trenutni_smjer){
	std::vector<int> pomocni;
	std::deque<std::vector<int>> podnizovi;
	
	if(trenutni_smjer==Rastuci){
		for(int i=0; i<a.size()-1; i++){
		/*	if((a.at(i)<=a.at(i+1)) && (StepenBrojaDva(a.at(i))==true) && (StepenBrojaDva(a.at(i+1))==true)){
				pomocni.push_back(a.at(i));
			}
			else if((StepenBrojaDva(a.at(i)) && !(StepenBrojaDva(a.at(i+1))) && StepenBrojaDva(a.at(i-1))) ||
			(StepenBrojaDva(a.at(i)) && a.at(i)>a.at(i+1) && StepenBrojaDva(a.at(i-1)))){
				pomocni.push_back(a.at(i));
			}*/
			if(a.at(i)<=a.at(i+1) && StepenBrojaDva(a.at(i))){
					pomocni.push_back(a.at(i));
				
			}
			else{
				if(StepenBrojaDva(a.at(i)))
					pomocni.push_back(a.at(i));
					
				if(pomocni.size()>=2)
					podnizovi.push_back(pomocni);
				
				pomocni.clear();
			}
		}
		if(StepenBrojaDva(a.at(a.size()-1)))
			pomocni.push_back(a.at(a.size()-1));
		if(pomocni.size()>=2)
			podnizovi.push_back(pomocni);
		
		pomocni.clear();
		
		
	}
	else {
		for(int i=0; i<a.size()-1; i++){
			
			if(a.at(i)>=a.at(i+1) && StepenBrojaDva(a.at(i))){
					pomocni.push_back(a.at(i));
				
			}
			else{
				if(StepenBrojaDva(a.at(i)))
					pomocni.push_back(a.at(i));
				if(pomocni.size()>=2)
					podnizovi.push_back(pomocni);
				
				pomocni.clear();
			}
		}
		if(StepenBrojaDva(a.at(a.size()-1)))
			pomocni.push_back(a.at(a.size()-1));
		if(pomocni.size()>=2)
			podnizovi.push_back(pomocni);
		
		pomocni.clear();
		
		
	}
		
	
	return podnizovi;
}

int main ()
{
	std::cout<< "Unesite broj elemenata vektora: ";
	int n;
	std::cin>> n;
	//Ubaciti za n<0
	std::cout<< "Unesite elemente vektora: ";
	std::vector<int> a;
	for(int i=0; i<n; i++){
		int b;
		std::cin>> b;
		a.push_back(b);
	}
	std::cout<< "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int x;
	std::cin>> x;
	
	std::deque<std::vector<int>> podnizovi;
	if(x==1){
		podnizovi=MaksimalniPodnizoviStepenaDvojke(a, Rastuci);
		std::cout<< "Maksimalni rastuci podnizovi:\n";
		for(std::vector<int> v : podnizovi){
			for(int i : v){
				std::cout << i << " ";
			}
			std::cout << std::endl;
		}
	}
	else {
		podnizovi=MaksimalniPodnizoviStepenaDvojke(a, Opadajuci);
		std::cout<< "Maksimalni opadajuci podnizovi: \n";
		for(std::vector<int> v : podnizovi){
			for(int i : v){
				std::cout << i << " ";
			}
			std::cout << std::endl;
		}
	}	
	
	return 0;
}
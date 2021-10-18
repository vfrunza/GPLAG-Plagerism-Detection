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


enum Smjer {Rastuci = 1, Opadajuci = 2}; 

bool JeLiStepenDvojke(int n){
	if(n<1) return false;
	int t = 1; 
	while(t <= n){
		if(n == t) return true; 
		t *=  2; 
	}
	return false; 
}

bool JeLiVeciRastuci(int a1, int a2){
	if(a1 >= a2) return true; 
	return false; 
}

bool JeLiVeciOpadajuci(int a1, int a2){
	if(a1 > a2) return true; 
	return false; 
}


std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s){
	std::deque<std::vector<int>> dek; 
	if(s==1){
		int k(0); 
		std::vector<int> pomocni; 
	for(int i = 0; i < v.size(); i++){
		
		if(JeLiStepenDvojke(v.at(i)) && (pomocni.size()==0 || JeLiVeciRastuci(v.at(i), v.at(i-1)))){
			pomocni.push_back(v.at(i)); 
			if(i == v.size() - 1 && pomocni.size() > 1)	{
				dek.resize(dek.size()+1);
					for(int j = 0; j < pomocni.size(); j++){
						dek.at(k).push_back(pomocni.at(j));
					} 
					k++; 
			}
			
		} 
		else{
				if(pomocni.size() > 1){
					dek.resize(dek.size()+1);
					for(int j = 0; j < pomocni.size(); j++){
						dek.at(k).push_back(pomocni.at(j));
					} 
					k++; 
				} 
			if(JeLiStepenDvojke(v.at(i)))	i--; 
				pomocni.clear(); 
			}
	}
	}
	
	else {
		int k(0); 
		std::vector<int>pomocni;
		for(int i = 0; i < v.size(); i++){
			
			if(JeLiStepenDvojke(v.at(i)) && (pomocni.size() == 0 || !JeLiVeciOpadajuci(v.at(i), v.at(i-1))) ){
				pomocni.push_back(v.at(i)); 
				if(i == v.size() - 1 && pomocni.size() > 1)	{
				dek.resize(dek.size()+1);
					for(int j = 0; j < pomocni.size(); j++){
						dek.at(k).push_back(pomocni.at(j));
					} 
					k++; 
			}
			}
			else{
				if(pomocni.size() > 1){
					dek.resize(dek.size()+1); 
					for(int j = 0; j < pomocni.size(); j++) dek.at(k).push_back(pomocni.at(j));
					k++; 
				}
				if(JeLiStepenDvojke(v.at(i))) i--; 
				pomocni.clear(); 
			}
		}
	}
	
	return dek; 
}

int main(){
	std::cout << "Unesite broj elemenata vektora: "; 
	int n; 
	std::cin >> n; 
	std::cout << "Unesite elemente vektora: "; 
	std::vector<int> v; 
	for(int i = 0; i < n; i++){
		int k; 
		std::cin >> k; 
		v.push_back(k); 
	}
	int k;
	Smjer s; 
	
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: "; 
	std::cin >> k; 
	if(k == 1) s = Rastuci; 
	else s = Opadajuci; 
	std::deque<std::vector<int>> dek; 
	
	if(s == Rastuci){
		dek = MaksimalniPodnizoviStepenaDvojke(v, s); 
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl; 
	for(int i = 0; i < dek.size(); i++){
		for(int j = 0; j < dek.at(i).size(); j++) std::cout << dek.at(i).at(j) << " "; 
		std::cout << std::endl; 
	}
	}
	else{
		dek = MaksimalniPodnizoviStepenaDvojke(v, s); 
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl; 
	for(int i = 0; i < dek.size(); i++){
		for(int j = 0; j < dek.at(i).size(); j++) std::cout << dek.at(i).at(j) << " "; 
		std::cout << std::endl; 
	}
	}
	
	
	return 0; 
}


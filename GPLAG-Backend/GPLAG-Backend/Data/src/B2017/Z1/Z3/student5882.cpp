//B 2017/2018, Zadaća 1, Zadatak 3
#include <iostream>
#include <vector>
#include <deque>

enum class Smjer{Rastuci, Opadajuci};

bool StepenDvojke(int n){
	while (n != 0) {
		if( n==1 || n==-1 ) return true;
		if( n%2 != 0 ) return false;
		n/=2;
	}
	return true;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer S){
	std::deque<std::vector<int>> vrati;
		for(int i=0; i<v.size(); i++){
			if(v.at(i)>0 && StepenDvojke(v.at(i))){
			    for(int j=i+1; j<=v.size(); j++){
		    		if( j==v.size() || (S==Smjer::Rastuci && v.at(j)<=v.at(j-1)) || (S==Smjer::Opadajuci && v.at(j)>=v.at(j-1)) || !StepenDvojke(v.at(j)) || v.at(j)<=0 ){
			    		if(j-i > 1){
			    			std::vector<int> pomocni;
			    			for(int k=i; k<j; k++){ 
			    				pomocni.push_back(v.at(k));
			    			}
			    			vrati.push_back(pomocni);
			    		}
			    		i=j-1;
			    		break;
		    		}
	     		}
			}
		}
	return vrati;
}

int main (){
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	std::vector<int> v;
	for(int i=0; i<n; i++){
		int z;
		std::cin >> z;
		v.push_back(z);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	for(;;){
	    std::cin >> n;
    	if(n==1 || n==2) break;
		std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	Smjer S;
	if(n==1) S=Smjer::Rastuci;
	else S=Smjer::Opadajuci;
	std::deque<std::vector<int>> ispisi{MaksimalniPodnizoviStepenaDvojke(v, S)};
	if(ispisi.size()>0){
    	if(n==1) std::cout << "Maksimalni rastuci podnizovi: ";
    	else std::cout << "Maksimalni opadajuci podnizovi: ";
    	for(int i=0; i<ispisi.size(); i++){
    		std::cout << std::endl;
    		for(int j=0; j<ispisi.at(i).size(); j++) std::cout << ispisi.at(i).at(j) << " ";
    	}
    	return 0;
	}
	if(n==1) std::cout << "Nema maksimalno rastucih podnizova.";
	else std::cout << "Nema maksimalno opadajucih podnizova.";
	return 0;
}
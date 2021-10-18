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

enum Smjer {Rastuci=0, Opadajuci
};


bool stependva(int x) {
	return((x>0)&&!(x&(x-1)));
}


std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> s2, Smjer value){

std::deque<std::vector<int>> output;
std::vector<int> temp;
bool uslov;


	for(int i(0); i < s2.size()-1; ++i) {
		uslov = (((s2.at(i) > s2.at(i+1)) && (s2.at(i) != s2.at(i+1))) == (static_cast<bool>(value)));
		
		if(uslov && (stependva(s2.at(i))) && (stependva(s2.at(i+1)))) {
			temp.push_back(s2.at(i));
		}
			
		else if(!temp.empty()) {
			temp.push_back(s2.at(i));
			output.push_back(temp);
			temp.clear();
		}
	}

	if(!temp.empty()) {
		temp.push_back(s2.at(s2.size()-1));
		output.push_back(temp);
		temp.clear();
	}
	



	return output;
}


int main ()
{	int n;
	int unos;

	std::vector<int> niz;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	
	for(int i=0; i<n; i++){
		int a;
		std::cin >> a;
		niz.push_back(a);
	}
	
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> unos;
	if(unos==1){
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		for(auto el : MaksimalniPodnizoviStepenaDvojke(niz, Rastuci)){
			for( auto ele : el)
				std::cout << ele << " ";
			std::cout << "\n";
		}
		
	}
	else if(unos==2){
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for(auto el : MaksimalniPodnizoviStepenaDvojke(niz, Opadajuci)){
			for( auto ele : el)
				std::cout << ele << " ";
			std::cout << "\n";
		}
	}
	
	return 0;
}
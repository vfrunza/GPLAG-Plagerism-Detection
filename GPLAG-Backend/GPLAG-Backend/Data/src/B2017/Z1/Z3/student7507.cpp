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

enum Smjer{Rastuci=1, Opadajuci};

bool StepenDvojke(int broj){
	if(broj == 1) return true;
	for(int i=0; i<broj; i++){
		if (pow(2,i) == broj){
			return true; 
			break;
		}
	}
	return false;
}


std::deque<std::vector<int>> RastuciPodnizovi (std::vector<int> v){
	std::deque<std::vector<int>> rast;
	if(v.size() == 0) return rast;
	
	int i(0), p(0), q(0), j(0);
	do{
		if(i<v.size()-1 && v.at(i) <= v.at(i+1)){
		p=i;
		while (i<v.size()-1 && v.at(i) <= v.at(i+1)) {
			i++;
		}
		q=i;
		}
	if(p != q){
		rast.push_back(std::vector<int>());
		for(;p<=q; p++){
			rast[j].push_back(v.at(p));
		}
		j++;
		q=0;
		p=0;
	}
	i++;
	}while(i<v.size()-1);
	return rast;
}

std::deque<std::vector<int>> OpadajuciPodnizovi(std::vector<int> v){
	std::deque<std::vector<int>> opad;
	if(v.size()==0) return opad;
	
	int i(0), p(0), q(0), j(0);
	do{ 
		if(i<v.size()-1 && v.at(i)>=v.at(i+1)){
			p=i;
			while(i<v.size()-1 && v.at(i) >= v.at(i+1)){
				i++;
			}
			q=i;
		}
		if(p != q){
			opad.push_back(std::vector<int>());
			for(; p<=q; p++){
				opad[j].push_back(v.at(p));
			}
			j++;
			q=0; p=0;
		}
		i++;
	}while(i<v.size()-1);
	return opad;
}
/*std::deque<std::vector<int>> RastuciPodnizovi(std::vector<int>v){
	std::deque<std::vector<int>> rast;
	std::vector<int> pom;
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v.size(); j++){
			if(v.at(j) < v.at(j+1)) pom.push_back(v.at(j));
		}
	rast[i].push_back(pom);
	}
	return rast;
}

std::deque<std::vector<int>> OpadajuciPodnizovi(std::vector<int> v){
	std::deque<std::vector<int>> opad;
	std::vector<int> pom ;
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v.size(); j++){
			if(v.at(j) > v.at(j+1)) pom.push_back(v.at(j));
		}
		opad[i].push_back(pom);
	}
	return opad;
}*/

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, enum Smjer s){
	std::deque<std::vector<int>> tacni, netacni;
	std::vector<int> neki_vektor, probni1, probni2;
	
	for(int i=0; i<v.size(); i++){
		if(StepenDvojke(v.at(i)) == true)
		neki_vektor.push_back(v.at(i));
	}
	
	
	if(s==1){
		tacni = RastuciPodnizovi(neki_vektor);
		return tacni;
	} 
	else {
		netacni = OpadajuciPodnizovi(neki_vektor);
		return netacni;
	}
}

int main ()
{
    std::vector<int> v;
    std::deque<std::vector<int>> rastuci, opadajuci;
    int n, nesto;

	int broj;
	
	std::cout << "Unesite broj elemenata vektora: " ;
	std::cin >> n;
	
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		std::cin >> broj;
		v.push_back(broj);
	}
	
	//std::cin >> std::ws;
	
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> nesto;
	
	if(nesto == 1){
		rastuci = MaksimalniPodnizoviStepenaDvojke(v, Rastuci);
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		for(int i=0; i<rastuci.size(); i++){
			for(auto y: rastuci[i]){
				std::cout << y << " ";
		}
		std::cout << std::endl;
	}
	}
	else if(nesto == 2){
		opadajuci = MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for(int i=0; i<opadajuci.size(); i++){
			for(auto x:opadajuci[i]){
				std::cout << x << " ";
		}
		std::cout << std::endl;
	}
	}
	return 0;
}
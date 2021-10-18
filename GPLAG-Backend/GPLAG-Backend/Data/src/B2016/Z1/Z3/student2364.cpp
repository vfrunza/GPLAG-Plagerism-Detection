#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector <std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v){

	Matrica M;
	if(v.size() == 0) return M;
	int index(0);
	for(int i(0); i < v.size()-1 ; i++){
		if(v.at(i) <= v.at(i+1)){
			M.resize(index+1);
			M.at(index).push_back(v.at(i));
		while(v.at(i) <= v.at(i+1)){
			M.at(index).push_back(v.at(i+1));
			i++;
			if(i == v.size() - 1)break;
		}
		index++;
	}
}
	
	return M;
}

Matrica OpadajuciPodnizovi(std::vector<double> v){
	
	Matrica M;
	if(v.size() == 0) return M;
	int index(0);
	for(int i(0); i < v.size() -1; i++){
		if(v.at(i) >= v.at(i+1)){
			M.resize(index +1);
			M.at(index).push_back(v.at(i));
			while(v.at(i+1) <= v.at(i)){
				M.at(index).push_back(v.at(i+1));
				i++;
				if(i == v.size() - 1) break;
			}
			index++;
		}
	}
	return M;
}

int main(){
	
	int broj_elemenata;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj_elemenata;
	
	double element;
	std::vector <double> vektor;
	std::cout << "Unesite elemente vektora: ";
	for(int i(0); i < broj_elemenata; i++){
	std::cin >> element;
	vektor.push_back(element);
	}
	
	Matrica M(RastuciPodnizovi(vektor));
	
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	
	for(int i(0); i < M.size(); i++){
		for(int j(0); j< M.at(i).size(); j++){
	    	std::cout << M.at(i).at(j) << " ";
	    	
		}
		std::cout << std::endl;
	}
	
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	
	Matrica K(OpadajuciPodnizovi(vektor));
	
	for(int i(0); i < K.size(); i++){
		for(int j(0); j < K.at(i).size(); j++){
			std::cout << K[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}
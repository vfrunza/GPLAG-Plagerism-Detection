#include <iostream> 
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> niz){
	std::vector<std::vector<double>> matrica ;
	std::vector<double> podniz ;
	for(int i=0; i<niz.size();i++){
		while((i+1)<niz.size() && niz[i] <= niz[i+1]){
			podniz.push_back(niz[i]);
			i++;
		}
		if(podniz.size()!=0){
			podniz.push_back(niz[i]);
			matrica.push_back(podniz);
			podniz.resize(0);
		}
	}
	return matrica;
}

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> niz){
	std::vector<std::vector<double>> matrica ;
	std::vector<double> podniz ;
	for(int i=0; i<niz.size();i++){
		while((i+1)<niz.size() && niz[i] >= niz[i+1]){
			podniz.push_back(niz[i]);
			i++;
		}
		if(podniz.size()!=0){
			podniz.push_back(niz[i]);
			matrica.push_back(podniz);
			podniz.resize(0);
		}
	}
	return matrica;

	
}

int main ()
{
	int n;
	
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> niz;
	
	for(int i=0;i<n;i++){
		double element;
		std::cin >> element;
		niz.push_back(element);
	}
	
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	std::vector<std::vector<double>> rastuci(RastuciPodnizovi(niz));
	for(int i=0; i<rastuci.size();i++){
		for(int j=0;j<rastuci[i].size();j++){
			std::cout << rastuci[i][j] << " " ;
		}
		std::cout << std::endl;
	}

	
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	std::vector<std::vector<double>> opadajuci(OpadajuciPodnizovi(niz));
	for(int i=0; i<opadajuci.size();i++){
		for(int j=0;j<opadajuci[i].size();j++){
			std::cout << opadajuci[i][j] << " " ;
		}
		std::cout << std::endl;
	}
	
	return 0;
}
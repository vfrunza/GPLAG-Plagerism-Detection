#include <iostream>
#include <vector>
#include <iomanip>

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> a){
	std::vector<double> temp;
	std::vector<std::vector<double>> rezultat;
	bool istina=false;

	for (int i = 0; i < a.size()-1; i++) {
		if (a[i] <= a[i+1] && !istina) {

			temp.clear();
			temp.push_back(a[i]);
			istina = true;
		}
		else if (a[i] <= a[i+1] && istina) {

			temp.push_back(a[i]);
			
		}
		else if (a[i] > a[i+1] && istina) {

			temp.push_back(a[i]);
			rezultat.push_back(temp);
			istina = false;
		}
	} 
	if (a[a.size()-2] <= a[a.size()-1] && istina) {
		
			temp.push_back(a[a.size()-1]);
			rezultat.push_back(temp);
			istina = false;
	}
	return rezultat;
}

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> a){
	std::vector<double> temp;
	std::vector<std::vector<double>> rezultat;
	bool istina=false;

	for (int i = 0; i < a.size()-1; i++) {
		if (a[i] >= a[i+1] && !istina) {
		
			temp.clear();
			temp.push_back(a[i]);
			istina = true;
		}
		else if (a[i] >= a[i+1] && istina) {
		
			temp.push_back(a[i]);
			
		}
		else if (a[i] < a[i+1] && istina) {
		
			temp.push_back(a[i]);
			rezultat.push_back(temp);
			istina = false;
		}
	} 
	if (a[a.size()-2] >= a[a.size()-1] && istina) {
	
			temp.push_back(a[a.size()-1]);
			rezultat.push_back(temp);
			istina = false;
	}
	return rezultat;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	std::cout << "Unesite elemente vektora: ";
	
	std::vector<double> a;
	for (int i = 0; i < n; i++) {
		int broj;
		std::cin >> broj;
		a.push_back(broj);
	}
	
	std::vector<std::vector<double>> Rastuci = RastuciPodnizovi(a);
	
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for (int i = 0; i < Rastuci.size(); i++) { 
		for (int j = 0; j < Rastuci[i].size(); j++) {
			if (j == Rastuci[i].size() - 1) {
				std::cout << std::setprecision(12) << Rastuci[i][j];
				break;
			}
			
			std::cout << Rastuci[i][j] << " ";
		}
		std::cout << std::endl;
	}//Printanje rastucih
	
	std::vector<std::vector<double>> Opadajuci = OpadajuciPodnizovi(a);
	
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for (int i = 0; i < Opadajuci.size(); i++) { 
		for (int j = 0; j < Opadajuci[i].size(); j++) {
			if (j == Opadajuci[i].size() - 1) {
				std::cout << Opadajuci[i][j];
				break;
			}
			
			std::cout << Opadajuci[i][j] << " ";
		}
		std::cout << std::endl;
	}//Printanje rastucih
	
	return 0;
}
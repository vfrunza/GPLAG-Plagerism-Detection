/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector <double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> vektor){
	Matrica povratna_matrica;
	if(vektor.size() == 0) return povratna_matrica;
	std::vector<double> moguci_vektor;
	int red(0);
	for(int i=0; i<vektor.size()-1; i++){
		if(vektor.at(i)<=vektor.at(i+1)){
			povratna_matrica.resize(red+1);
			povratna_matrica.at(red).push_back(vektor.at(i));
			while(vektor.at(i)<=vektor.at(i+1)){
				povratna_matrica.at(red).push_back(vektor.at(i+1));
				i++;
				if(i==vektor.size()-1) break;
			}
			red++;
		}
	}
	return povratna_matrica;
}

Matrica OpadajuciPodnizovi(std::vector<double> vektor){
	Matrica povratna_matrica;
	if(vektor.size() == 0) return povratna_matrica;
	std::vector<double> moguci_vektor;
	int red(0);
	for(int i=0; i<vektor.size()-1; i++){
		if(vektor.at(i)>=vektor.at(i+1)){
			povratna_matrica.resize(red+1);
			povratna_matrica.at(red).push_back(vektor.at(i));
			while(vektor.at(i+1)<=vektor.at(i)){
				povratna_matrica.at(red).push_back(vektor.at(i+1));
				i++;
				if(i==vektor.size()-1) break;
			}
			red++;
		}
	}
	return povratna_matrica;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int num(0);
	std::cin >> num;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> vektor;
	double temp(0);
	for (int i = 0; i < num; i++) {
		std::cin >> temp;
		vektor.push_back(temp);
	}
	std::vector<std::vector<double>> rastuci {RastuciPodnizovi(vektor)}, opadajuci {OpadajuciPodnizovi(vektor)};
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for (int i = 0; i < rastuci.size(); i++) {
		for (int j = 0; j < rastuci.at(i).size(); j++) {
			std::cout << rastuci.at(i).at(j)<< " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for (int i = 0; i < opadajuci.size(); i++) {
		for (int j = 0; j < opadajuci.at(i).size(); j++) {
			std::cout << opadajuci.at(i).at(j)<< " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi (std::vector<double> vektor){
	Matrica matrica(5, std::vector<double>(5));
	int i{0},j{1},k{0},l{0};
	bool prvi_prolaz(true);
	while(i<vektor.size() && j<vektor.size()) {
		double broj_1(vektor[i]),broj_2(vektor[j]);
		
		if(prvi_prolaz) {
			if(broj_1<broj_2){
			matrica[k][l]=broj_1;
			matrica[k][l+1]=broj_2;
			prvi_prolaz=false;
			l+=2;
			continue;
			}
		}
		if(broj_1<broj_2){
			matrica[k][l]=broj_2;
		}
		else{
			l=0;
			k++;
		}
		i++;
		j++;
	}
	
	return matrica;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int broj_elemenata;
	std::cin >> broj_elemenata;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> ulazni_vektor;
	for(int i{0} ; i<broj_elemenata ; i++){
		int element;
		std::cin >> element;
		ulazni_vektor.push_back(element);
	}
	
	std::cout << "Maksimalni rastuci podnizovi: \n";
	auto matrix = RastuciPodnizovi(ulazni_vektor);
	for(int i{0} ; i<matrix.size() ; i++) {
		for (int j{0} ; j<matrix[0].size() ; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: ";
	
	return 0;
}
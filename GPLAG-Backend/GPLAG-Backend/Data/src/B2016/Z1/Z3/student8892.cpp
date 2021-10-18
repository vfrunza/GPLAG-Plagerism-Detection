/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <iomanip>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi (std::vector<double> v){
	Matrica m;
	int i = 0;
	
	while (i != v.size()){
		std::vector < double> v1;
		if (i != v.size() - 1 && v[i + 1] >= v[i]){
			while (i != v.size() - 1 && v[i + 1] >= v[i]){
				v1.push_back(v[i]);
				i++;
				if (i + 1 <= v.size() - 1 && v[i] > v[i + 1] && v[i] >= v[i - 1]){
					v1.push_back(v[i]);
				}
				if (i == v.size() - 1 && v[i] >= v[i - 1]){
					v1.push_back(v[i]);
					break;
					}
				}
				m.push_back(v1);
			}
			else i++;
		}
		return m;
	}

Matrica OpadajuciPodnizovi (std::vector<double> v){
	Matrica m;
	int i = 0;
	
	while ( i != v.size()){
		std::vector< double> v1;
		if (i != v.size() - 1 && v[i + 1] <= v[i]){
			while (i != v.size() - 1 && v[i + 1] <= v[i]){
				v1.push_back(v[i]);
				i++;
				if (i + 1 <= v.size() - 1 && v[i] < v[i + 1] && v[i] <= v[i - 1]){
					v1.push_back(v[i]);
				}
				if (i == v.size() - 1 && v[i] <= v[i - 1]){
					v1.push_back(v[i]);
					break;
				}
			}
			m.push_back(v1);
		}
		else i++;
	}
	return m;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	double element;
	std::vector<double> v;
	for (int i = 0; i < n; i++){
		std::cin >> element;
		v.push_back(element);
	}
	Matrica a = RastuciPodnizovi(v);
	Matrica b = OpadajuciPodnizovi(v);
	
	std::cout <<"Maksimalni rastuci podnizovi: \n";
	for (int i = 0; i < a.size(); i++){
		std::cout<< std::endl;
		for (int j = 0; j < a.at(i).size(); j++){
			if (i == a.size() - 1  && j == a.at(i).size() - 1 ){
				std::cout << a[i][j];
			}
			else{
			std::cout << a[i][j] << " ";
			}
			
		}
	}
	std:: cout << std::endl;
	std::cout<< "Maksimalni opadajuci podnizovi: \n";
	for (int i = 0; i < b.size(); i++){
		for (int j = 0; j < b.at(i).size(); j++){
			if ( i == b.size() - 1  && j == b.at(i).size() - 1){
				std::cout << b[i][j];
			}
			else{
			std::cout << b[i][j] << " ";
			}
			
		}
	
	}

	return 0;
}
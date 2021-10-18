 /*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>


std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	
	std::vector<std::vector<double>> Rezultat;
	std::vector<double> temp;
	
	for(int i=1; i<v.size(); i++){
		
		if(v[i-1] <= v[i])
			temp.push_back(v[i-1]);
			
		if(v[i-1] > v[i] && temp.size() != 0){
				temp.push_back(v[i-1]);
				Rezultat.resize(Rezultat.size()+1);
				Rezultat.push_back(temp);
				temp.clear();
			}
		if(i == v.size()-1 && v[i-1] <= v[i] && temp.size() != 0){
			temp.push_back(v[i]);
			Rezultat.resize(Rezultat.size()+1);
			Rezultat.push_back(temp);
			temp.clear();
		}
	}

	return Rezultat;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> Rezultat;
	std::vector<double> temp;
	
	for(int i=1; i<v.size(); i++){
		
		if(v[i-1] >= v[i])
			temp.push_back(v[i-1]);
		
		if(v[i-1] < v[i] && temp.size() != 0){
				temp.push_back(v[i-1]);
				Rezultat.resize(Rezultat.size()+1);
				Rezultat.push_back(temp);
				temp.clear();
		}
	
		if(i == v.size()-1 && temp.size() != 0 && v[i-1] >= v[i]){
					temp.push_back(v[i]);
					Rezultat.resize(Rezultat.size()+1);
					Rezultat.push_back(temp);
					temp.clear();
		}
	}
		
	return Rezultat;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	double element;
	
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> v;
	
	for(int i=0; i<n; i++){
		std::cin >> element;
		v.push_back(element);
	}
	
	std::vector<std::vector<double>> a;
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	a = RastuciPodnizovi(v);
	
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	std::vector<std::vector<double>> b;
	b = OpadajuciPodnizovi(v);
	
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<b[i].size(); j++){
			std::cout << b[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}
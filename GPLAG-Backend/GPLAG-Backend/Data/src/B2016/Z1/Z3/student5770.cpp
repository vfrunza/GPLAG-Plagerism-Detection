#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> rez;
	for(int i = 0; i < v.size() - 1; i++){
		if(v[i] <= v[i+1]){
			int j;
			std::vector<double> pom;
			for(j = i; j < v.size() - 1; j++){
				if(v[j]<=v[j+1]){
					pom.push_back(v[j]);
				}
				else break;
			}
			if(i!=j) pom.push_back(v[j]);
			rez.push_back(pom);
			i = j;
		}
	}
	return rez;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> rez;
	for(int i = 0; i < v.size() - 1; i++){
		if(v[i] >= v[i+1]){
			int j = i;
			std::vector<double> pom;
			for(j = i; j < v.size() - 1; j++){
				if(v[j]>=v[j+1]){
					pom.push_back(v[j]);
				}
				else break;
			}
			if(i!=j) pom.push_back(v[j]);
			rez.push_back(pom);
			i = j;
		}
	}
	return rez;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<double> v;
	double x;
	std::cout << "Unesite elemente vektora: ";
	for(int i = 0; i < n ; i++){
		std::cin >> x;
		v.push_back(x);
	}
	std::vector<std::vector<double>> v1 = RastuciPodnizovi(v);
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(int i = 0; i < v1.size(); i++){
		for(auto x : v1[i]) std::cout << x << " ";
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	std::vector<std::vector<double>> v2 = OpadajuciPodnizovi(v);
	for(int i = 0; i < v2.size(); i++){
		for(auto x : v2[i]) std::cout << x << " ";
		std::cout << std::endl;
	}
	return 0;
}
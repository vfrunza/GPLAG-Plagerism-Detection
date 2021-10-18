#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica podniz;
	for(unsigned int i = 0; i < v.size(); i++){
		std::vector<double> p;
		int j(i);
		if(j + 1 < v.size() && v[j + 1] >= v[j]){
			while(j + 1 < v.size() && v[j + 1] >= v[j]){
				p.push_back(v[j]);
				j++;
			}
		p.push_back(v[j]);
		podniz.push_back(p);
		i = j;
		}
	}
	return podniz;
}

Matrica OpadajuciPodnizovi(std::vector<double> v){
	Matrica podniz;
	for(unsigned int i = 0; i < v.size(); i++){
		std::vector<double> p;
		int j(i);
		if(j + 1 < v.size() && v[j + 1] <= v[j]){
			while(j + 1 < v.size() && v[j + 1] <= v[j]){
				p.push_back(v[j]);
				j++;
			}
		p.push_back(v[j]);
		podniz.push_back(p);
		i = j;
		}
	}
	return podniz;
}
int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> v(n);
	for(unsigned int i = 0; i < n; i++)
	   std::cin >> v[i];
	std::cout << "Maksimalni rastuci podnizovi:"<<std::endl;
	Matrica rastuci;
	rastuci = RastuciPodnizovi(v);
	for(unsigned int i = 0; i < rastuci.size(); i++){
		for(double x : rastuci[i]) std::cout << x << " ";
		std::cout << std::endl;
	}
	
	std::cout<< "Maksimalni opadajuci podnizovi:"<<std::endl;
	Matrica opadajuci;
	opadajuci = OpadajuciPodnizovi(v);
	for(unsigned int i = 0; i < opadajuci.size();i++){
		for(double x : opadajuci[i]) std::cout << x << " ";
		std::cout << std::endl;
	}

  return 0;
}
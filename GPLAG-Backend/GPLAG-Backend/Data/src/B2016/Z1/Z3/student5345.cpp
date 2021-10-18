#include <vector>
#include <iostream>
#include <algorithm>


std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> p) {
	std::vector<std::vector<double>> ret;
	std::vector<double> tmp;
	
	for (int i = 0; i < p.size(); i++) {
		if (i == 0 || p[i] < p[i - 1]) {
			if (tmp.size() > 1) ret.push_back(tmp);
			tmp.clear();
		}
		
		tmp.push_back(p[i]);
	}
	
	if (tmp.size() > 1) ret.push_back(tmp);
	
	return ret;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> p) {
	std::vector<std::vector<double>> ret;
	std::vector<double> tmp;
	
	for (int i = 0; i < p.size(); i++) {
		if (i == 0 || p[i] > p[i - 1]) {
			if (tmp.size() > 1) ret.push_back(tmp);
			tmp.clear();
		}
		
		tmp.push_back(p[i]);
	}
	
	if (tmp.size() > 1) ret.push_back(tmp);
	
	return ret;
}

int main ()
{
	int cnt;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> cnt;

	std::cout << "Unesite elemente vektora: ";
	std::vector<double> in(cnt);
	for (int i = 0; i < cnt; i++) {
		std::cin >> in[i];
	}
	
	auto rastuci = RastuciPodnizovi(in);
	auto opadajuci = OpadajuciPodnizovi(in);
	
	std::cout << "Maksimalni rastuci podnizovi:\n";
	for (int i = 0; i < rastuci.size(); i++) {
		for (int j = 0; j < rastuci[i].size(); j++)
			std::cout << rastuci[i][j] << " ";
		std::cout << std::endl;
	}
	
	std::cout << "Maksimalni opadajuci podnizovi:\n";
	for (int i = 0; i < opadajuci.size(); i++) {
		for (int j = 0; j < opadajuci[i].size(); j++)
			std::cout << opadajuci[i][j] << " ";
		std::cout << std::endl;
	}
	
	return 0;
}
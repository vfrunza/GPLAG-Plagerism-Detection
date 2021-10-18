#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Mat;
Mat RastuciPodnizovi(std::vector<double> v) {
	Mat m(1);
	int k(0);
	bool a(true);
	if(v.size()==0) return m;
	for(int i(0); i<v.size()-1; i++) {
		if(v[i]<=v[i+1] and a) {
			m[k].push_back(v[i]);
			m[k].push_back(v[i+1]);
			a=false;
		} else if(v[i]<=v[i+1]) {
			m[k].push_back(v[i+1]);
		} else if(v[i]>=v[i+1] and !a) {
			k++;
			m.resize(k+1);
			a=true;
		}
		if(i==v.size()-2) break;
	}
	return m;
}
Mat OpadajuciPodnizovi(std::vector<double> v) {
	Mat m(1);
	int k(0);
	bool a(true);
	if(v.size()==0) return m;
	for(int i(0); i<v.size()-1; i++) {
		if(v[i]>=v[i+1] and a) {
			m[k].push_back(v[i]);
			m[k].push_back(v[i+1]);
			a=false;
		} else if(v[i]>=v[i+1]) {
			m[k].push_back(v[i+1]);
		} else if(v[i]<=v[i+1] and !a) {
			k++;
			m.resize(k+1);
			a=true;
		}
		if(i==v.size()-2) break;
	}
	return m;
}
int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	while(!std::cin) {
	 	std::cin.clear();
	 	std::cin.ignore(10000, '\n');
	 	std::cin >> n;
	}
	try {
	if(n<0) throw n;
	}
	catch(int n) {
		std::cout << "IZUZETAK!";
		return 0;
	}
	std::vector<double> v(n);
	std::cout << "Unesite elemente vektora: ";
	for(int i(0); i<v.size(); i++) {
		std::cin >> v[i];
		while(!std::cin) {
	 		std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cin >> v[i];
		}
	}
	
	Mat m1(RastuciPodnizovi(v));
	Mat m2(OpadajuciPodnizovi(v));
	
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(auto red : m1) {
		for(auto x : red)
			std::cout << x <<" ";
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(auto red : m2) {
		for(auto x : red)
			std::cout << x <<" ";
		std::cout << std::endl;
	}
	return 0;
}
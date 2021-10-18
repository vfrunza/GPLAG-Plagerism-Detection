#include <iostream>
#include <vector>

typedef std::vector<std::vector<double> > Matrica;

void IspisMatrice(Matrica m) {
	for(std::vector<double> red:m){
		for(double i : red)
			std::cout << i << " ";
		std::cout << std::endl;
	}
}

Matrica RastuciPodnizovi(std::vector<double> v) {
	Matrica m;
	std::vector<double> pomocni;
	int j;
	for(int i=0; i<v.size(); i++) {
		for(j=i; j<v.size(); j++) {
			if(j==v.size()-1) {
				if(v[j]>=v[j-1]) {
					pomocni.push_back (v[j]);
					break;
				} else break;
			}
			if(v[j]<=v[j+1])
				pomocni.push_back (v[j]);
			if(v[j]>v[j+1] && j!=0 && v[j]>=v[j-1]) {
				pomocni.push_back(v[j]);
				break;
			}
			if(v[j]>v[j+1]) break;
		} 
		i=j;
		if(!pomocni.empty())
			m.push_back(pomocni);
		pomocni.clear();
	}
	return m;	
}

Matrica OpadajuciPodnizovi(std::vector<double> v) {
	Matrica m;
	std::vector<double> pomocni;
	int j;
	for(int i=0; i<v.size(); i++) {
		for(j=i; j<v.size(); j++) {
			if(j==v.size()-1) {
				if(v[j]<=v[j-1]) {
					pomocni.push_back (v[j]);
					break;
				} else break;
			}
			if(v[j]>=v[j+1])
				pomocni.push_back (v[j]);
			if(v[j]<v[j+1] && j!=0 && v[j]<=v[j-1]) {
				pomocni.push_back(v[j]);
				break;
			}
			if(v[j]<v[j+1]) break;
		} 
		i=j;
		if(!pomocni.empty())
			m.push_back(pomocni);
		pomocni.clear();
	}
	return m;
}

int main () {
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	if(n<0) {
		std::cout << "Broj elemenata mora biti nenegativan!";
		return 0;
	}
	std::vector<double> v(n);
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin >> v[i]; 
	}
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	IspisMatrice(RastuciPodnizovi(v));
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	IspisMatrice(OpadajuciPodnizovi(v));
	
	return 0;
}
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi (std::vector<double> v) {
	int k=0,br=1;
	std::vector<double> help;
	Matrica a;
	for(int i=1;i<v.size();i++) {
		if(v[i]>=v[i-1]) {
			k++;
			help.push_back(v[i-1]);
			while(v[i]>=v[i-1]) {
				br++;
				help.push_back(v[i]);
				if(i==v.size()-1) break;
				i++;
			}
			if(br>=2) {
				a.resize(k);
				a[k-1].resize(br);
				for(int i=0;i<a[k-1].size();i++) a[k-1][i]=help[i];
			}
		}
		br=1;
		help.resize(0);
	}
	return a;
}

Matrica OpadajuciPodnizovi (std::vector<double> v) {
	int k=0,br=1;
	std::vector<double> help;
	Matrica a;
	for(int i=1;i<v.size();i++) {
		if(v[i]<=v[i-1]) {
			k++;
			help.push_back(v[i-1]);
			while(v[i]<=v[i-1]) {
				br++;
				help.push_back(v[i]);
				if(i==v.size()-1) break;
				i++;
			}
			if(br>=2) {
				a.resize(k);
				a[k-1].resize(br);
				for(int i=0;i<a[k-1].size();i++) a[k-1][i]=help[i];
			}
		}
		br=1;
		help.resize(0);
	}
	return a;
}

int main () {
	std::vector<double> v;
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::cout << "Unesite elemente vektora: " ;
	for(int i=0;i<n;i++) {
		double d;
		std::cin >> d;
		v.push_back(d);
	}
	Matrica a=OpadajuciPodnizovi(v);
	Matrica b=RastuciPodnizovi(v);
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl ;
	for(int i=0;i<b.size();i++) {
		for(int j=0;j<b[i].size();j++) {
			std::cout << b[i][j] << " " ;
		}
		std::cout << std::endl ;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl ;
	for(int i=0;i<a.size();i++) {
		for(int j=0;j<a[i].size();j++) {
			std::cout << a[i][j] << " " ;
		}
		std::cout << std::endl ;
	}
	return 0;
}
/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> IzbaciPodnizove(std::vector<std::vector<double>> m) {
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m.size(); j++) {
			if (j==i || m[i].size() == m[j].size()) continue;
			for (int k=0; k<m[j].size(); k++) {
				if (m[i][0] == m[j][k]) {
					int x=k;
					bool ima_ga = true;
					for (int l=0; l<m[i].size(); l++) {
						if (m[i][l] != m[j][x]) ima_ga = false;
						x++;
						if (l == m[i].size()-1) break;
						if (x > m[j].size()-1) {
							ima_ga = false;
							break;
						}
					}
					if (ima_ga) m.erase(m.begin() + i);
				}
			}
		}
	}	
	return m;
}

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v) {
	std::vector<std::vector<double>> m;
	if (v.size()==0) return m;
	for (int i=0; i<v.size()-1; i++) {
		if (v[i] <= v[i+1]) {
			std::vector<double> pom;
			while (v[i] <= v[i+1]) {
				pom.push_back(v[i]);
				i++;
				if (i >= (v.size()-1)) break;
			}
			pom.push_back(v[i]);
			m.push_back(pom);
		}
	}
	
	std::vector<std::vector<double>> m1 = IzbaciPodnizove(m);

	return m;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v) {
	std::vector<std::vector<double>> m;
	if (v.size()==0) return m;
	for (int i=0; i<v.size()-1; i++) {
		if (v[i] >= v[i+1]) {
			std::vector<double> pom;
			while (v[i] >= v[i+1]) {
				pom.push_back(v[i]);
				i++;
				if (i >= (v.size() - 1)) break;
			}
			pom.push_back(v[i]);
			m.push_back(pom);
		}
	}
	
	std::vector<std::vector<double>> m1 = IzbaciPodnizove(m);
	
	return m;
}

int main ()
{
	int n{};
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> v;
	std::cout<<"Unesite elemente vektora: ";
	for (int i=0; i<n; i++) {
		double broj{};
		std::cin>>broj;
		v.push_back(broj);
	}
	std::vector<std::vector<double>> m = RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: \n";
	for (auto x:m) {
		for (auto y:x)
			std::cout<<y<<" ";
		std::cout<<std::endl;
	}
	
	std::vector<std::vector<double>> m1 = OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: \n";
	for (auto x:m1) {
		for (auto y:x)
			std::cout<<y<<" ";
		std::cout<<std::endl;
	}
	
	return 0;
}
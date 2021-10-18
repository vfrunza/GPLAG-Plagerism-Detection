/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi (std::vector<double> v) {
	Matrica rezz;
	std::vector<double> pom;
	pom.push_back(v[0]);
	for(int i = 1; i < v.size(); i++) {
		if(v[i] >= v[i - 1]) {
			//std::cout << v[i] << " " << v[i - 1] << std::endl;
			pom.push_back(v[i]);
		}
		
		else {
			//pom.push_back(v[i - 1]);
			if(pom.size() > 1 && pom.size() < v.size()) {
				rezz.push_back(pom);
			}
			pom.clear();
			pom.push_back(v[i]);
		}
		
	}
	if(pom.size() > 1) rezz.push_back(pom);
	return rezz;
}

Matrica OpadajuciPodnizovi (std::vector<double> v) {
	Matrica rezz;
	std::vector<double> pom;
	pom.push_back(v[0]);
	for(int i = 1; i < v.size(); i++) {
		if(v[i] <= v[i - 1]) {
			//std::cout << v[i] << " " << v[i - 1] << std::endl;
			pom.push_back(v[i]);
		}
		
		else {
			//pom.push_back(v[i - 1]);
			if(pom.size() > 1 && pom.size() < v.size()) {
				rezz.push_back(pom);
			}
			pom.resize(0);
			pom.push_back(v[i]);
		}
		
	}
	if(pom.size() > 1 ) rezz.push_back(pom);
	return rezz;
}


int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<double> vektor(n);
	std::cout << "Unesite elemente vektora: ";
	for(int i = 0; i < n; i++) {
		double broj;
		std::cin >> broj;
		vektor[i] = broj;
	}
	Matrica mat(RastuciPodnizovi(vektor));
	std::cout << "Maksimalni rastuci podnizovi: ";
	std::cout << std::endl;
	for(int i = 0; i < mat.size(); i++) {
		for(int j = 0; j < mat[i].size(); j++) {
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	//std::cout << std::endl;
	Matrica mat1(OpadajuciPodnizovi(vektor));
	std::cout << "Maksimalni opadajuci podnizovi: ";
	std::cout << std::endl;
	for(int i = 0; i < mat1.size(); i++) {
		for(int j = 0; j < mat1[i].size(); j++) {
			std::cout << mat1[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
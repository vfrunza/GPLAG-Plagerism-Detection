/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v) {
	std::vector<std::vector<double>> v_1;
	for (int i=0; i<v.size()-1; i++) {
		int j;
		for (j=i+1; j<v.size(); j++)  {
			if (v[j-1]>v[j]) {
				break; 
			}
		}
		if (j-i>1) {
			v_1.push_back(std::vector<double>({}));
			for(int k=i; k<j; k++) {
				v_1[v_1.size()-1].push_back(v[k]);
			}
			i=j;
		}
	}
	return v_1;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v) {
	std::vector<std::vector<double>> v_2;
	for (int i=0; i<v.size()-1; i++) {
		int j;
		for (j=i+1; j<v.size(); j++) {
			if (v[j-1]<v[j]) {
				break;
			}
		}
			if (j-i>1) {
				v_2.push_back(std::vector<double>({}));
				for (int k=i; k<j; k++) {
					v_2[v_2.size()-1].push_back(v[k]);
				}
				i=j;
			}
	}
	return v_2;	
}
int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> v (n);
	for (int i=0; i<n; i++) {
		std::cin >> v[i];
	}
	// ispis
	/*for (int i=0; i<n; i++) {
		std::cout << v[i] << " ";
	}*/
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	std::vector<std::vector<double>> v_1(RastuciPodnizovi(v));
	for (int i=0; i<v_1.size(); i++) {
		for (int j=0; j<v_1[0].size(); j++) {
			std::cout << v_1[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	std::vector<std::vector<double>> v_2(OpadajuciPodnizovi(v));
	for (int i=0; i<v_2.size(); i++) {
		for (int j=0; j<v_2[0].size(); j++) {
			std::cout << v_2[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
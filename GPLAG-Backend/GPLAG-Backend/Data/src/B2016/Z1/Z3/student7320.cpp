/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

// UBACITI POREDJENJE REALNIH BROJEVA!!!!
// UBACIO :)
#include <iostream>
#include <vector>
#include <cmath>

#define pb push_back

bool JesuLiJednaki(double x, double y, double epsilon = 1e-13) {
	return std::fabs(x - y) <= epsilon * (std::fabs(x) + std::fabs(y));
}

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v) {
	
	std::vector<std::vector<double>> ret;
	
	for (int i = 0; i < v.size(); i++) {
		int curr_el = i;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[curr_el] <= v[j] || JesuLiJednaki(v[curr_el], v[j])) curr_el = j;
			else break;
		}
		if (curr_el - i > 0) {
			std::vector<double> ZaDodati;
			for (int j = i; j <= curr_el; j++) ZaDodati.pb(v.at(j));
			ret.pb(ZaDodati);
		}
		i = curr_el;
	}
	return ret;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v) {
	
	std::vector<std::vector<double>> ret;
	
	for (int i = 0; i < v.size(); i++) {
		int curr_el = i;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[j] <= v[curr_el] || JesuLiJednaki(v[j], v[curr_el])) curr_el = j;
			else break;
		}
		if (curr_el - i > 0) {
			std::vector<double> ZaDodati;
			for (int j = i; j <= curr_el; j++) ZaDodati.pb(v.at(j));
			ret.pb(ZaDodati);
		}
		i = curr_el;
	}
	return ret;
}
int main ()
{
	int n;
	double tmp;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<double> vect;
	std::cout << "Unesite elemente vektora: ";
	for (int i = 0; i < n; i++) {
		std::cin >> tmp;
		vect.pb(tmp);
	}
	std::vector<std::vector<double>> sol1, sol2;
	sol1 = RastuciPodnizovi(vect);
	std::cout << "Maksimalni rastuci podnizovi: \n";
	for (int i = 0; i < sol1.size(); i++) {
		for (int j = 0; j < sol1[i].size(); j++)
			std::cout << sol1[i][j] << " ";
		std::cout << "\n";
	}
	
	sol2 = OpadajuciPodnizovi(vect);
	std::cout << "Maksimalni opadajuci podnizovi: \n";
	for (int i = 0; i < sol2.size(); i++) {
		for (int j = 0; j < sol2[i].size(); j++) 
			std::cout << sol2[i][j] << " ";
		std::cout << "\n";
	}
	return 0;
}
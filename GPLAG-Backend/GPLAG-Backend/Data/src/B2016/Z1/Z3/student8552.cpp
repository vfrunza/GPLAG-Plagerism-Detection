/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using std::vector;

vector<vector<double>> RastuciPodnizovi (vector<double> niz) {
	vector<vector<double>> mat_rastucih;
	vector<double> pomocni;
	for (int i=0; i<niz.size()-1; i++) {
		if (niz[i]<=niz[i+1]) {
			pomocni.resize(0);
			while (i<niz.size()-1 && niz[i]<=niz[i+1]) {
				pomocni.push_back(niz[i]);
				i++;
			}
			pomocni.push_back(niz[i]);
			mat_rastucih.push_back(pomocni);
		}
	}
	return mat_rastucih;
}

vector<vector<double>> OpadajuciPodnizovi (vector<double> niz) {
	vector<vector<double>> mat_opadajucih;
	vector<double> pomocni;
	for (int i=0; i<niz.size()-1; i++) {
		if (niz[i]>=niz[i+1]) {
			pomocni.resize(0);
			while (i<niz.size()-1 && niz[i]>=niz[i+1]) {
				pomocni.push_back(niz[i]);
				i++;
			}
			pomocni.push_back(niz[i]);
			mat_opadajucih.push_back(pomocni);
		}
	}
	return mat_opadajucih;
}

int main ()
{
	int br_el;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> br_el;
	vector<double> niz(br_el);
	std::cout << "Unesite elemente vektora: ";
	for (int i=0; i<br_el; i++)
		std::cin >> niz[i];
	vector<vector<double>> rastuci(RastuciPodnizovi(niz));
	std::cout << "Maksimalni rastuci podnizovi:" << std::endl;
	for (int i=0; i<rastuci.size(); i++) {
		for (int j=0; j<rastuci[i].size(); j++)
			std::cout << rastuci[i][j] << " ";
		std::cout << std::endl;
	}
	vector<vector<double>> opadajuci(OpadajuciPodnizovi(niz));
	std::cout << "Maksimalni opadajuci podnizovi:" << std::endl;
	for (int i=0; i<opadajuci.size(); i++) {
		for (int j=0; j<opadajuci[i].size(); j++)
			std::cout << opadajuci[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}
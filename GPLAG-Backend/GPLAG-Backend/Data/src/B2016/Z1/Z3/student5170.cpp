/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
typedef std::vector<double> Vektor;
typedef std::vector<std::vector<double>> VekVek;

VekVek RastuciPodnizovi (Vektor vektor)
{
	VekVek povratni;
	int n(0),j;
	for (int i=0; i<vektor.size()-1; i++) {
		if (vektor[i+1]>=vektor[i]) {
			for (j=i+1; j<vektor.size(); j++) {
				if (vektor[j]<vektor[j-1]) break;
			}
			n++;
			povratni.resize(n);
			for (int k=i; k<j; k++) povratni[n-1].push_back(vektor[k]);
			i=j-1;
		}
	}
	return povratni;
}

VekVek OpadajuciPodnizovi (Vektor vektor)
{
	VekVek povratni;
	int n(0),j;
	for (int i=0; i<vektor.size()-1; i++) {
		if (vektor[i+1]<=vektor[i]) {
			for (j=i+1; j<vektor.size(); j++) {
				if (vektor[j]>vektor[j-1]) break;
			}
			n++;
			povratni.resize(n);
			for (int k=i; k<j; k++) povratni[n-1].push_back(vektor[k]);
			i=j-1;
		}
	}
	return povratni;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	int x;
	Vektor vektor(n);
	for (int i=0; i<n; i++) {
		std::cin >> x;
		vektor[i]=x;
	}
	VekVek rastuci(RastuciPodnizovi(vektor));
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for (int i=0; i<rastuci.size(); i++) {
		for (int j=0; j<rastuci[i].size(); j++) {
			std::cout << rastuci[i][j] << " ";
		}
		std::cout << std::endl;
	}
	VekVek opadajuci(OpadajuciPodnizovi(vektor));
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for (int i=0; i<opadajuci.size(); i++) {
		for (int j=0; j<opadajuci[i].size(); j++) {
			std::cout << opadajuci[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
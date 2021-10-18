/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

bool Rastuci (std::vector<double> v1)
{

	if (v1.size() < 2) return false;

	for (int i = 0; i < v1.size()-1; i++) {
		if (v1[i] > v1[i+1]) return false;
	}
	return true;
}

bool Opadajuci (std::vector<double> v1)
{

	if (v1.size() < 2) return false;

	for (int i = 0; i < v1.size()-1; i++) {
		if (v1[i] < v1[i+1]) return false;
	}
	return true;
}

std::vector<double> Vrativector(std::vector<double> v1,int pocetak, int kraj)
{
	std::vector<double> v2;
	for (int i = pocetak; i <= kraj; i++) {
		v2.push_back(v1[i]);
	}
	return v2;
}

Matrica RastuciPodnizovi (std::vector<double> v1)
{
	if (v1.size() < 2) return Matrica {};
	Matrica b(0);
	std::vector<double> v2(0);

	int pocetak(0);
	int kraj(2);


	for (int i = 0; i < v1.size()-1; i++) {
		pocetak = i;
		kraj = i+1;
		if (!v2.empty()) v2.clear();
		if (Rastuci(Vrativector(v1,pocetak,kraj)) == true) {
			v2 = Vrativector(v1,pocetak,kraj);
			
			while (kraj < v1.size() && Rastuci(Vrativector(v1,pocetak,kraj)) == true ) {
				v2 = Vrativector(v1,pocetak,kraj);
				kraj++;
			}
			b.push_back(v2);
			i = kraj;
			i--;
		}
	}

	return b;
}

Matrica OpadajuciPodnizovi(std::vector<double> v1)
{
	if (v1.size() < 2) return Matrica {};
	Matrica b(0);
	std::vector<double> v2(0);

	int pocetak(0);
	int kraj(2);


	for (int i = 0; i < v1.size()-1; i++) {
		pocetak = i;
		kraj = i+1;
		if (!v2.empty()) v2.clear();
		if (Opadajuci(Vrativector(v1,pocetak,kraj)) == true) {
			v2 = Vrativector(v1,pocetak,kraj);
			
			while (kraj < v1.size() && Opadajuci(Vrativector(v1,pocetak,kraj)) == true ) {
				v2 = Vrativector(v1,pocetak,kraj);
				kraj++;
			}
			b.push_back(v2);
			i = kraj;
			i--;
		}
	}

	return b;
}

int main ()
{
	Matrica a;
	
	
	int n(0);
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	
	std::vector<double> v(n);
	for (auto &i : v) {
		std::cin >> i;
	}
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	
	a = RastuciPodnizovi(v);
	for (auto i : a) {
		for (auto i2 : i) {
			std::cout << i2 <<" ";
		}
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	a = OpadajuciPodnizovi(v);
	for (auto i : a) {
		for (auto i2 : i) {
			std::cout << i2 <<" ";
		}
		std::cout << std::endl;
	}
	return 0;
}

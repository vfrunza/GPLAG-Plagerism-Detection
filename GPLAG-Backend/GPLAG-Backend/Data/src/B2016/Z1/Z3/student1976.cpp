//B 2016/2017, Zadaća 1, Zadatak 3
#include <iostream>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
typedef std::vector<double> Vektor;
typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi (Vektor v)
{
	Matrica mat;
	Vektor temp;

	for(int i = 0; i < v.size(); i++) {

		if(i != v.size() - 1 && v.at(i) <= v.at(i+1)) {
			temp.push_back(v.at(i));
			if((i + 1) != v.size() - 1 && v.at(i+1) > v.at(i+2)) {    //slucaj u kojem se podniz sastoji samo od dva elementa
				temp.push_back(v.at(i+1));                            //upisujem podniz u red matrice
				mat.push_back(temp);                                  //cistim pomocni vektor jer smo dosli do kraja podniza
				temp.clear();
			} else if((i + 1) == v.size() - 1 && v.at(i) <= v.at(i+1)) { //slucaj kada dodjemo do zadnjeg elementa u nizu
				temp.push_back(v.at(i+1));
				mat.push_back(temp);
				temp.clear();
			}
		}
	}
	return mat;
}

Matrica OpadajuciPodnizovi (Vektor v)
{
	Matrica mat;
	Vektor temp;

	for(int i = 0; i < v.size(); i++) {

		if (i != v.size() - 1 && v.at(i) >= v.at(i+1)) {              //postupak primjenjen za trazenje max monotono rastuceg podniza
			temp.push_back(v.at(i));                                  //ponavljam prilikom trazenja max monotono opadajuceg podniza
			if((i + 1) != v.size() -1 && v.at(i+1) < v.at(i+2)) {
				temp.push_back(v.at(i+1));
				mat.push_back(temp);
				temp.clear();
			} else if((i + 1) == v.size() - 1 && v.at(i) >= v.at(i+1)) {
				temp.push_back(v.at(i+1));
				mat.push_back(temp);
				temp.clear();
			}
		}
	}
	return mat;
}

int main ()
{
	int n;
	cout << "Unesite broj elemenata vektora: ";
	cin >> n;
	if(n < 0) cout << "Velicina niza mora biti nenegativna!";

	cout << "Unesite elemente vektora: ";
	Vektor a;
	int br(0);
	double x;

	for(;;) {
		cin >> x;
		if(!cin) {
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		a.push_back(x);
		br++;

		if(br == n) break;
	}

	auto rastuci = std::move(RastuciPodnizovi(a));
	cout << "Maksimalni rastuci podnizovi: " << endl;
	for(int i = 0; i < rastuci.size(); i++) {
		for(int j = 0; j < rastuci[i].size(); j++)
			cout << std::setprecision(12) << rastuci.at(i).at(j) << " ";
		cout << endl;
	}

	auto opadajuci = std::move(OpadajuciPodnizovi(a));
	cout << "Maksimalni opadajuci podnizovi: " << endl;
	for(int i = 0; i < opadajuci.size(); i++) {
		for(int j = 0; j < opadajuci.at(i).size(); j++)
			cout << opadajuci.at(i).at(j) << " ";
		cout << endl;
	}

	return 0;
}
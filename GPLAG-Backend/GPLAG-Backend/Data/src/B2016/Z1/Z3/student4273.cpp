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

using std::cin; using std::cout; using std::endl; using std::vector;
typedef vector<vector<double>> Matrica;

/*Matrica KreirajMatricu (int br_redova, int br_kolona) {
	return Matrica(br_redova, std::vector<double>(br_kolona));
}*/

Matrica RastuciPodnizovi(vector<double> v) {
	Matrica m; int brojac(0); //Broji podnizove
	for (int i=0; i<v.size()-1; i++) {
		if (v[i]<=v[i+1]) {
			//Pronasli smo podniz
			m.resize(brojac+1); //Novi red za vektor
			while (i<(v.size()-1) && v.at(i)<=v.at(i+1)) {
				m[brojac].push_back(v[i]);
				i++;
			}
			if (i!=v.size())
			{m[brojac].push_back(v[i]);
			brojac++;}
		}
	}
	return m;
}
Matrica OpadajuciPodnizovi(vector<double> v) {
	Matrica m; int brojac(0); //Broji podnizove
	for (int i=0; i<v.size()-1; i++) {
		if (v[i]>=v[i+1]) {
			//Pronasli smo podniz
			m.resize(brojac+1); //Novi red za vektor
			while (i<v.size()-1 && v[i]>=v[i+1] && i<v.size()-1) { //pazi da ne izlazis iz opsega!
				m[brojac].push_back(v[i]);
				i++;
			}
			m[brojac].push_back(v[i]);
			brojac++;
		}
	}
	return m;
}
int main ()
{
	int n(0);
	cout << "Unesite broj elemenata vektora: ";
	cin >> n;
	cout << "Unesite elemente vektora: ";
	vector<double> v;
	for (int i=0; i<n; i++) {
		double broj(0);
		cin >> broj;
		v.push_back(broj);
	}
	Matrica m;
	m=RastuciPodnizovi(v);
	cout << "Maksimalni rastuci podnizovi: " << endl;
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m[i].size(); j++) {
			cout << std::setprecision(12) << m[i][j] << " ";
		}
		cout << endl;
	}
	m=OpadajuciPodnizovi(v);
	cout << "Maksimalni opadajuci podnizovi: " << endl;
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m[i].size(); j++) {
			cout << std::setprecision(12) << m[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<double>> Matrica;

Matrica RastuciPodnizovi(vector<double> v) {
	Matrica mat;
	vector<double> pom;
	
	for (int i = 0; i < v.size() - 1; i++) {
		pom.resize(0);
		int p(i);
		
		if (v[i] <= v[i + 1]) {
			while (v[i] <= v[i + 1] && i < v.size() - 2) i++;
			
			int k(i);
			if (i == v.size() - 2) k++;
			//k++;
			
			for (int j = p; j <= k; j++) {
				pom.push_back(v[j]);
			}
			
			mat.push_back(pom);
		}
	}
	
	/*cout << "Maksimalni rastuci podnizovi: \n";
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[i].size(); j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}*/
	
	return mat;
}

Matrica OpadajuciPodnizovi(vector<double> v) {
	vector<double> pom;
	Matrica mat;
	
	for (int i = 0; i < v.size() - 1; i++) {
		int p(i);
		pom.resize(0);
		
		if (v[i] >= v[i + 1]) {
			while (v[i] >= v[i + 1] && i < v.size() - 2) ++i;
			
			int k(i);
			if (i == v.size() - 2) k++;
			//k++;
			
			for (int j = p; j <= k; j++) {
				pom.push_back(v[j]);
			}
			
			mat.push_back(pom);
		}
	}
	
	/*cout << "Maksimalni opadajuci podnizovi: \n";
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[i].size(); j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}*/
	
	return mat;
}

int main ()
{
	int n;
	cout << "Unesite broj elemenata vektora: ";
	cin >> n;
	
	vector<double> v;
	cout << "Unesite elemente vektora: ";
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	Matrica rastuci(RastuciPodnizovi(v));
	
	cout << "Maksimalni rastuci podnizovi: \n";
	for (int i = 0; i < rastuci.size(); i++) {
		for (int j = 0; j < rastuci[i].size(); j++) {
			cout << rastuci[i][j] << " ";
		}
		cout << endl;
	} cout << endl;
	
	Matrica opadajuci(OpadajuciPodnizovi(v));
	
	cout << "Maksimalni opadajuci podnizovi: \n";
	for (int i = 0; i < opadajuci.size(); i++) {
		for (int j = 0; j < opadajuci[i].size(); j++) {
			cout << opadajuci[i][j] << " ";
		}
		cout << endl;
	} cout << endl;
	
	return 0;
}
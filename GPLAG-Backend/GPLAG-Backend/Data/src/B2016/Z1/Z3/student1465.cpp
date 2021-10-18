/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;
typedef vector<vector<double>> Matrica;

Matrica RastuciPodnizovi(vector<double> niz) {
	Matrica rastuci_podnizovi;
	int pocetak_podniza;
	bool poceo_podniz = false;
	
	for(int i = 0; i < niz.size() - 1; i++) {
		if(!poceo_podniz && niz.at(i) <= niz.at(i+1)) {
			poceo_podniz = true;
			pocetak_podniza = i;
		}
		if(poceo_podniz && niz.at(i) > niz.at(i+1))
		{
			vector<double> novi_podniz;
			for(int j = pocetak_podniza; j <= i; j++)
			{
				novi_podniz.push_back(niz.at(j));
			}
			
			rastuci_podnizovi.push_back(novi_podniz);
			poceo_podniz = false;
		}
	}
	if (poceo_podniz)
	{
		vector<double> novi_podniz;
			for(int j = pocetak_podniza; j < niz.size(); j++)
			{
				novi_podniz.push_back(niz.at(j));
			}
			rastuci_podnizovi.push_back(novi_podniz);
			poceo_podniz = false;
	}
	return rastuci_podnizovi;
}


Matrica OpadajuciPodnizovi(vector<double> niz) {
	Matrica opadajuci_podnizovi;
	int pocetak_podniza;
	bool poceo_podniz = false;
	for(int i = 0; i < niz.size() - 1; i++) {
		if(!poceo_podniz && niz.at(i) >= niz.at(i+1)) {
			poceo_podniz = true;
			pocetak_podniza = i;
		}
		if(poceo_podniz && niz.at(i) < niz.at(i+1)) 
		{
			vector<double> novi_podniz;
			for(int j = pocetak_podniza; j <= i; j++) {
				novi_podniz.push_back(niz.at(j));
			}
			
			opadajuci_podnizovi.push_back(novi_podniz);
			poceo_podniz = false;
		}
	}
	if(poceo_podniz)
	{
		vector<double> novi_podniz;
		for(int j = pocetak_podniza; j < niz.size(); j++) {
			novi_podniz.push_back(niz.at(j));
		}
		opadajuci_podnizovi.push_back(novi_podniz);
		poceo_podniz = false;
	}
	return opadajuci_podnizovi;
}
int main ()
{
	int n;
	cout << "Unesite broj elemenata vektora: ";
	cin >> n;
	cout << "Unesite elemente vektora: ";
	vector<double> niz;
	int broj;
	for(int i = 0; i <n; i++) {
		cin >> broj;
		niz.push_back(broj);
	}
	cout << "Maksimalni rastuci podnizovi: ";
	cout << endl;
	Matrica a = RastuciPodnizovi(niz);
	for (int i = 0; i < a.size(); i++){
		for(int j = 0; j < a.at(i).size(); j++)
		{
			cout << a.at(i).at(j) << " ";
		}
		cout << endl;
	}
	cout << "Maksimalni opadajuci podnizovi: ";
	cout << endl;
	Matrica b = OpadajuciPodnizovi(niz);
	for(int i = 0; i < b.size(); i++) {
		for(int j = 0; j < b.at(i).size(); j++) {
			cout << b.at(i).at(j) << " ";
		}
		cout << endl;
	}
	return 0;
}
/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

typedef vector<vector<double>> matrica;

matrica NajvecaPlaninaMatrice(matrica total) {
	matrica montblanc;
	vector<matrica> alpe;
	int m = total.size(), n = total.at(0).size();
	if(total.empty()) return montblanc;
	try {
		for(int i = 0; i < total.size(); i++) {
			vector<double> planina;
			vector<double> data;
			if(m > 2 && n > 2) {
				
			} else {
				
			}
		}
	} catch (std::domain_error) {
		cout << "Izuzetak: Matrica nije korektna";
	}
	
	return montblanc;
}

int main ()
{
	matrica najveca;
	int m, n;
	cout << "Unesite dimenzije matrice (m i n): ";
	cin >> m >> n;
	if(m < 0 || n < 0) { cout << "Dimenzije matrice moraju biti nenegativne!"; return 0;}
	najveca.resize(m);
	cout << "Unesite elemente matrice: ";
	int count(0);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++) {
			double element;
			cin >> element;
			najveca.at(i).push_back(element);
		}
	cout << "Najveca planina unesene matrice je: "<< endl;
	if(!NajvecaPlaninaMatrice(najveca).empty())
	for(int i = 0; i < NajvecaPlaninaMatrice(najveca).size(); i++) {
		for(int j = 0; j < NajvecaPlaninaMatrice(najveca).at(i).size(); j++) cout << std::setw(6) << NajvecaPlaninaMatrice(najveca).at(i).at(j);
		cout << endl; }
	return 0;
}
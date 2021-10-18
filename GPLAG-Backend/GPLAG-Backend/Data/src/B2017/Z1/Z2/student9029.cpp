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
using namespace std;

int main ()
{
	
	int a,b;
	cout << "Unesite a: ";
	cin >> a;
	cout << "Unesite b: ";
	cin >> b;
	vector<vector<double>> m(a,vector<double>(b));
	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			cin >> m[i][j];
		}
	}
	cout << "Unesite matricu: ";
	cout << endl;
	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
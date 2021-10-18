/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

using std::cout;
using std::cin;

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int m, int n){
	return Matrica (m, std::vector<double>(n));
}
Matrica UnesiMatricu (int m, int n){
	auto M (KreirajMatricu (m, n));
	for (int i(0);i<m;i++){
		for(int j(0);j<n;j++){
			cin >> M[i][j];
			if ()
		}
	}
	return M;
}

int main ()
{
	int m, n;
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> m >> n;
	cout << "Unesite elemente matrice: ";
//	try{
		auto M (UnesiMatricu (m,n));
//	}
	
	return 0;
}
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
using std::domain_error;
using std::setw;

typedef vector<vector<double>> Matrica;

double Vrati_zbir_koncentricnog_kvadrata(Matrica M, int m, int n) {
	
	double zbir(0);
	
	for(int i(m); i < n + 1; i++) 
		for(int j(m); j < n + 1; j++)
			if(i == m || i == n  || ((j == m || j == n)  && (i > m && i < n))) zbir += M.at(i).at(j);
	
	return zbir;
}


Matrica NajvecaPlaninaMatrice(Matrica M) {
	Matrica N;
	
	if(M.size() == 0 || M.at(0).size() == 0) return N;
		
	for(int i(0); i < M.size() - 1; i++) {
		if(M.at(i + 1).size() != M.at(i).size() ) throw domain_error ("Matrica nije korektna");
	}
	
	if(M.size() < 3 && M.at(0).size() < 3) {
		int max(M.at(0).at(0));
		for(int i(0); i < M.size(); i++) 
			for(int j(0); j < M.at(0).size(); j++)
				if(max < M.at(i).at(j)) max = M.at(i).at(j);
		
		N.resize(1);
		N.at(0).push_back(max);
		return N;
	}
	
	double pom(0), pom2(1000);
	
	for(int i(1); i < M.size() - 1; i++) 
		for(int j(1); j < M.at(0).size() - 1; j++) {
			double vrh(M.at(i).at(j));
			int jj(-1), ii(-1);

			pom = Vrati_zbir_koncentricnog_kvadrata(M, i - 1, j + 1);
			
			if(vrh > pom) {
				ii = i - 1;
				jj = j + 1;
			do{
				pom = Vrati_zbir_koncentricnog_kvadrata(M, i - 1, j + 1);
				if( i > 1  && j < M.at(0).size() - 1) {
					i--;
				    j++;
					pom2 = Vrati_zbir_koncentricnog_kvadrata(M, i - 1, j + 1);
				
					ii = i + 1; 
					jj = j - 1;
				}
			}
			
			while(pom2 < pom && i < M.size()  && j < M.at(0).size());
			}
			
			if(jj != -1 && ii != -1) {
				N.resize(jj - ii + 1);
				for(int i(0); i < N.size(); i++)
					N.at(i).resize(jj - ii + 1);
			
			
				for(int i(0); i < jj - ii + 1; i++) {
					int jjj(ii);
					for(int j(0); j < jj - ii + 1; j++){
						N.at(i).at(j) = M.at(ii + i).at(jjj);
						jjj++;
					}
				}
			}
		}
	
	
	return N;
	
}


int main ()
{
	int m, n;
	cout << "Unesite dimenzije matrice (m i n): ";
	cin >> m >> n;
	
	if(m < 0 || n < 0) {
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	Matrica M(m, vector<double> (n));
	cout << "Unesite elemente matrice: ";
	for(int i(0); i < m; i++) {
		for(int j(0); j < n; j++) {
			cin >> M.at(i).at(j);
		}
	}

	try {
		Matrica N(NajvecaPlaninaMatrice(M));
		cout << "\nNajveca planina unesene matrice je: " << endl;
	
		for(auto red : N) {
			for(auto x : red) cout << setw(6) << x ;
			cout << endl;
		}
	}
	
	catch(domain_error izuzetak) {
		cout << izuzetak.what();
	}
	
	return 0;
}
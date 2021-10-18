/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>


using namespace std;

typedef vector<vector<double>> matrica;



matrica h(matrica m1){
	
	int tmp;
	
	for(int i = 0; i < m1.size();i++) {
		
		for(int j = 0; j < m1[i].size() / 2; j++){
			
			int n = m1[i].size();
			
			tmp = m1[i][j];
			m1[i][j] = m1[i][n - 1];
			m1[i][n - 1] = tmp;
		}
	}
	
	return m1;
}

matrica v(matrica m1){
	
	int tmp;
	
	for(int i = 0; i < m1.size() / 2;i++) {
		
		for(int j = 0; j < m1[i].size(); j++){
			
	
			
			tmp = m1[i][j];
			m1[i][j] = m1[m1.size() - i - 1][j];
			m1[m1.size() - i - 1][j] = tmp;
		}
	}
	
	return m1;
}

matrica hv(matrica m1) {
	
	m1 = h(m1);
	m1 = v(m1);
	
	return m1;
	
}


matrica OgledaloMatrica(matrica m1){
	
	for(int i = 1; i < m1.size(); i++) {
		
		for(int j = 0; j < m1[i].size(); j++) {
			
			if(m1[i].size() != m1[i - 1].size()) throw domain_error("Matrica nije korektna");
			
		}
	}
	
	matrica nul(0, vector<double>(0));
	
	if(m1.size() == 0 && m1[0].size() == 0) return nul;
	
	
	matrica hor(h(m1));
	matrica ver(v(m1));
	matrica horver(hv(m1));
	
	int n = 3 * m1.size();
	int n2 = 3 * m1[0].size();
	
	matrica m;
	
	m.resize(n);
	
		int pomoc = m.size() / 3;
		
	for(int i = 0; i < m.size(); i++) m[i].resize(n2);
	

	
	for(int i = 0; i < m.size(); i++){
		
		for(int j = 0; j < m[i].size(); j++) {
			
			int pomoc2 = m[i].size() / 3;
			
			if(i < pomoc && j < pomoc2) m[i][j] = horver[i][j];
			else if((i >= pomoc && i < pomoc * 2) && j < pomoc2) m[i][j] = hor[i - pomoc][j];
			else if((i >= pomoc && i < pomoc * 3) && j < pomoc2) m[i][j] = horver[i - pomoc * 2][j];
			
			else if((i < pomoc) && j < pomoc2 * 2) m[i][j] = ver[i][j - pomoc2];
			else if((i < pomoc * 2) && j < pomoc2 * 2) m[i][j] = m1[i - pomoc][j - pomoc2];
			else if((i < pomoc * 3) && j < pomoc2 * 2) m[i][j] = ver[i - pomoc * 2][j - pomoc2];
			
			else if((i < pomoc) && j >= pomoc * 2) m[i][j] = horver[i][j - pomoc2 * 2];
			else if((i < pomoc * 2) && j >= pomoc2 * 2) m[i][j] = hor[i - pomoc][j - pomoc2 * 2];
			else m[i][j] = horver[i - pomoc * 2][j - pomoc2 * 2];
			
			
			
		}
	}
	
	return m;
	
}

int main ()
{
	int m,n;
	
	
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> m >> n;
	
	if(m <= 0 || n <= 0) {
		if(m == 0 && n == 0) {
			cout << "Unesite elemente matrice: " << endl << "Rezultantna matrica: " << endl;
			return 0;
		}
		else if(m <0 || n < 0) {cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	}
	
	matrica mat(m, vector<double>(n));
	
	cout << "Unesite elemente matrice: ";
	
	for(int i = 0; i < mat.size(); i++) {
		
		for(int j = 0; j < mat[i].size(); j++) {
			
			cin >> mat[i][j];
			
		}
	}
	
	cout << endl;
	
	try{ 
		
	matrica rezmat = OgledaloMatrica(mat);
	
	cout << "Rezultantna matrica: " << endl;
	
	for (const auto &red : rezmat)
	{
		for (const auto &i : red)
			std::cout << setw(4) << right <<  i;
		std::cout << std::endl ;
	}
	
	}catch(domain_error izuzetak) {
		
		cout << izuzetak.what();
	}
	
	return 0;
}
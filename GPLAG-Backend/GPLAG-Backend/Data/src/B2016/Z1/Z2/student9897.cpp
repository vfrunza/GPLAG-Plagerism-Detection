/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica; 
typedef std::vector<double> Vektor; 

Matrica OgledaloMatrica (Matrica mat) {
	
	Matrica m; 
	
	m.resize(3*mat.size()); 
	
	for (int i=0; i<m.size(); i++) {
		m[i].resize(3*mat.size()); 
	}
	Matrica hm; 
	hm.resize(mat.size()); 
	for(int i=0; i<hm.size(); i++) {
		hm[i].resize(mat.size()); 
	}
	
	for (int i=hm.size(); i>=0; i--) {
		for (int j=hm.size(); j>=0; j--) {
			hm[i][j]=mat[i][j];
		}
	}
	for (int i=0; i<m.size(); i++) {
		for(int j=0; j<m[i].size(); j++) {
			m[i].push_back(hm[i][j]);
		}
	}

	
	return m; 
}

int main ()
{
	
	int a,b; 
	
	std::cout << "Unesite broj m: "; 
	std::cin >> a; 
	
	std::cout << "Unesite broj n: "; 
	std::cin >> b; 
	
	std::cout << "Unesite elemente matrice: "; 
	
	Matrica mat(a, Vektor(b)); 
	
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat[i].size(); j++) {
			
			std::cin >> mat[i][j]; 

		}
	}
	
	Matrica m;
	m=OgledaloMatrica(mat); 
	
	for (int i=0; i<m.size(); i++) {
		
		std::cout << std::endl;
		
		for (int j=0; j<m[i].size(); j++) {
			
			std::cout << m[i][j] << " "; 

		}
	}
	
	return 0;
}
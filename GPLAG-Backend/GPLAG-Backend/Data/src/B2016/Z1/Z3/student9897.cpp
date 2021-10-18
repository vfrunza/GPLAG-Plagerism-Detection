/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica; 

Matrica RastuciPodnizovi (std::vector<double> v) {
	
	Matrica mat; 
	std::vector <double> k; 
	
	int br(0); 
	int br1(0);

	for (int i=0; i<v.size(); i++) {

			if (v[i]<v[i+1]) {
				k.push_back(v[i]); 
					br++; 
			}
			
		    if (v[i]<v[i+1] && v[i+1]>v[i+2]) {
				k.push_back(v[i+1]);
				br1++;
			} 

			else {
				continue;
			}
	}	
	
	int n; 
	n=(br-br1); 
	
	for (int i=0; i<k.size(); i++) {
		if (k[i]<k[i+1]) { 
			mat.resize(i); 
		}
	}

	for (int i=0; i<n; i++) {
			mat[i].resize(n);
		}
		
		
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat[i].size(); j++) {
			
			mat[j][i]=k[i];
		}
	}

	return mat; 
}

int main ()
{
	int n; 
	std::cout << "Unesite broj elemenata vektora: "; 
	std::cin >> n; 
	
	std::vector <double> v(n); 
	std::cout << "Unesite elemente vektora: "; 
	
	for (int i=0; i<v.size(); i++) {
		std::cin >> v.at(i); 
	}
	
	Matrica mat; 
	mat=RastuciPodnizovi(v);
	
	std::cout << "Maksimalni rastuci podnizovi: ";
	
	for (int i=0; i<mat.size(); i++) {
		std::cout << std::endl; 
		for (int j=0; j<mat[i].size(); j++) {
			std::cout << mat[i][j] << " "; 
		}
	}
	
	return 0;
}
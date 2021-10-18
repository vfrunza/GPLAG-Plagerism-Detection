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

typedef std::vector<std::vector<double>> double_matrica;

double_matrica horizontalno(double_matrica a){

	double_matrica x;
	
	for(int i=0; i<a.size(); i++){
		std::vector<double> temp;
		for(int j=a[i].size()-1; j>=0; j--){
			temp.push_back(a[i][j]);
		}
		x.push_back(temp);
	}
	
	return x;
	
}

double_matrica vertikalno(double_matrica a){
	double_matrica x;
	for(int i=a.size()-1; i>-1; i--){
		std::vector<double> temp;
		for(int j=0; j<a[0].size(); j++){
			temp.push_back(a[i][j]);
		}
		x.push_back(temp);
	}
	return x;
}

double_matrica kombinovana(double_matrica a){
	return vertikalno(horizontalno(a));
}

double_matrica OgledaloMatrica(double_matrica x){
	
	double_matrica H, V, HV, X, y, z;
	X = x;
	H = horizontalno(x);
	V = vertikalno(x);
	HV = kombinovana(x);
	
	x.resize(0);
	
	x.insert(x.begin(), HV.begin(), HV.end());
	x.insert(x.end(), H.begin(), H.end());
	x.insert(x.end(), HV.begin(), HV.end());
	
	y.insert(y.begin(), V.begin(), V.end());
	y.insert(y.end(), X.begin(), X.end());
	y.insert(y.end(), V.begin(), V.end());
	
	z.insert(z.begin(), HV.begin(), HV.end());
	z.insert(z.end(), H.begin(), H.end());
	z.insert(z.end(), HV.begin(), HV.end());
	
	for(int i=0; i<y.size(); i++){
		for(int j=0; j<y[0].size(); j++){
			x[i].push_back(y[i][j]);
		}
	}
	
	for(int i=0; i<z.size(); i++){
		for(int j=0; j<z[0].size(); j++){
			x[i].push_back(z[i][j]);
		}
	}
	return x;
}

int main ()
{
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin >> m >> n;
	if(m < 0 || n < 0){
	std::cout << "Dimenzije matrice moraju biti nenegativne!";
	return 0;
	}
	std::cout << "Unesite elemente matrice: ";
	
	double element;
	double_matrica x;
	
	
	for(int i=0; i<m; i++){
		std::vector<double> temp;
		for(int j=0; j<n; j++){
			std::cin >> element;
			temp.push_back(element);
		}
		x.push_back(temp);
	}

	std::cout << std::endl << "Rezultantna matrica: " << std::endl;
	
	double_matrica y = OgledaloMatrica(x);
	
	for(int i=0; i<y.size(); i++){
		for(int j=0; j<y[0].size(); j++){
			std::cout << std::setw(4) << y[i][j];
		}
		std::cout << std::endl;
	}
	
	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

typedef std::vector<std::vector<double>> Matrica;


void IspisiMatricu(Matrica m)
{
	auto i = m.size();
	auto j = i;
	for(i=0; i< m.size(); i++) { 
		for(j=0; j<m[i].size(); j++)
			std::cout << std::setprecision(12) << m[i][j] << " ";
		std::cout << std::endl;
	}
}

bool JesuLiJednaki(double x, double y){
	double Eps = 1e-10;
	return std::fabs(x-y) <= Eps * (std::fabs(x) + std::fabs(y));
}

Matrica RastuciPodnizovi(const std::vector <double> v)
{
	if(v.size()==0) {
		Matrica m;
		return m;
	}
	 
	Matrica Matrix;
	auto k = v.size();
	k=0;
	auto i = v.size();
	for(i=0; i < v.size(); i++) {

		if(i == v.size()-1) break;

		if(i<v.size()-1 && (v[i] <= v[i+1])){
			Matrix.resize(k+1);

			while(i<v.size()-1 && (v[i] <= v[i+1] )){
				Matrix[k].push_back(v[i]);
				i++;
			}
			Matrix[k].push_back(v[i]);
			k++;
		}
		
		if(i == v.size()-1) --i;
	}
	return Matrix;
}

Matrica OpadajuciPodnizovi (const std::vector <double> v)
{
	if(v.size()==0) {
		Matrica m;
		return m;
	}
	
	Matrica Matrix;
	auto k = v.size();
	k=0;
	auto i = v.size();
	for(i=0; i < v.size(); i++) {

		if(i == v.size()-1) break;

		if(i<v.size()-1 && (v[i] >= v[i+1])){
			Matrix.resize(k+1);

			while(i<v.size()-1 && (v[i] >= v[i+1])){
				Matrix[k].push_back(v[i]);
				i++;
			}
			Matrix[k].push_back(v[i]);
			k++;
		}
		
		if(i == v.size()-1) --i;
	}
	return Matrix;
}

int main ()
{
	std::vector <double> vektor;
	int broj;
	double element;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj;
	if(broj <= 0) return 0;
	std::cout << "Unesite elemente vektora: ";
	for(unsigned long long int i=0; i<broj; i++) {
		std::cin >> element;
		vektor.push_back(element);
	}
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	IspisiMatricu(RastuciPodnizovi(vektor));
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	IspisiMatricu(OpadajuciPodnizovi(vektor));	

	return 0;
}
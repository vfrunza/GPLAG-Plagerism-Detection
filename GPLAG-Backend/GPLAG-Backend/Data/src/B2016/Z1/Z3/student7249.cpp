/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v) {
	Matrica A;
	for(int i=0; i<v.size();) {
		std::vector<double> V=v;
		V.resize(0);
		int br(0);
		for(int j=i; j<v.size()-1; j++) {
			if(v[j]<=v[j+1]) {
				V.push_back(v[j]);
				br++;
				if(j==v.size()-2) {
					V.push_back(v[j+1]);
					br++;
					break;
				}
				if(v[j+1]>v[j+2]) {
					V.push_back(v[j+1]);
					br++;
				}
			}
			else break;
		}
		if(br==0) i++;
		else i+=br;
		if(V.size()==0) continue;
		A.push_back(V);
	}
	return A;
}

Matrica OpadajuciPodnizovi(std::vector<double> v) {
	Matrica A;
	for(int i=0; i<v.size();) {
		std::vector<double> V=v;
		V.resize(0);
		int br(0);
		for(int j=i; j<v.size()-1; j++) {
			if(v[j]>=v[j+1]) {
				V.push_back(v[j]);
				br++;
				if(j==v.size()-2) {
					V.push_back(v[j+1]);
					br++;
					break;
				}
				if(v[j+1]<v[j+2]) {
					V.push_back(v[j+1]);
					br++;
				}
			}
			else break;
		}
		if(br==0) i++;
		else i+=br;
		if(V.size()==0) continue;
		A.push_back(V);
	}
	return A;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	int i(0);
	std::vector<double> v;
	while(i<n) {
		double x;
		std::cin >> x;
		v.push_back(x);
		i++;
	}
	Matrica A=RastuciPodnizovi(v);
	Matrica B=OpadajuciPodnizovi(v);
	int a(0);
	for(int i=0; i<A.size(); i++) {
		if(A[i].size()>a) {
			a=A[i].size();
		}
	}
	for(int i=0; i<A.size(); i++) {
		if(A[i].size()!=a) {
			A.erase(A.begin()+i);
			i--;
		}
	}
	a=0;
	for(int i=0; i<B.size(); i++) {
		if(B[i].size()>a) {
			a=B[i].size();
		}
	}
	for(int i=0; i<B.size(); i++) {
		if(B[i].size()!=a) {
			B.erase(B.begin()+i);
			i--;
		}
	}
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(std::vector<double> x : A) {
		for(double y : x) std::cout << std::setprecision(12) << y << " ";
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(std::vector<double> x : B) {
		for(double y : x) std::cout << std::setprecision(12) << y << " ";
		std::cout << std::endl;
	}
	return 0;
}
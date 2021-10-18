/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include <vector>
#include <iostream>
#include <cmath>

typedef std::vector<std::vector<double>> Matrix;

Matrix OpadajuciPodnizovi(std::vector<double>v )
{
	Matrix mat;
	std::vector<double> v1;
	for(int i=0; i<v.size()-1; i++) {
		v1.resize(0);
		if( v[i]>=v[i+1] ) {
			v1.push_back(v[i]);
			while(i<v.size()-1 && v[i]>=v[i+1] ) {
				v1.push_back(v[i+1]);
				i++;
			}
		}
		if(v1.size()>=2)  mat.push_back(v1);
	}
	return mat;
}

Matrix RastuciPodnizovi(std::vector<double> v)
{
	Matrix mat;
	std::vector<double> v1;
	for(int i=0; i<v.size()-1; i++) {
		v1.resize(0);
		if( v[i]<=v[i+1] ) { 
			v1.push_back(v[i]); 
			while ( i<v.size()-1 && v[i]<=v[i+1] ) {
				i++;
				v1.push_back(v[i]);
				
			}
		}  
		if(v1.size()>=2)  mat.push_back(v1); }
	return mat;
}

int main ()
{
	std::vector<double> v;
	Matrix mat1, mat2;
	int n,x;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin>>x;
		v.push_back(x);
	}
	std::vector<double> v2;
	v2=v;
	mat2=OpadajuciPodnizovi(v2);
	mat1=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	if(mat1.size()!=0) {
		for(int i=0; i<mat1.size(); i++ )  {
			for(int j=0; j<mat1[i].size(); j++) {
				std::cout<<mat1[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	if(mat2.size()!=0) {
		for(int i=0; i<mat2.size(); i++) {
			for(int j=0; j<mat2[i].size(); j++) {
				std::cout<<mat2[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}

	return 0;
}
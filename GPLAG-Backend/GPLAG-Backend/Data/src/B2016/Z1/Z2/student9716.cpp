/*B 2016/2017, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica mat)
{
	Matrica mat1;
	Matrica mat2;
	Matrica mat3;
	if(mat.size()==0) { return mat; }
		int x=mat[0].size();
	std::vector<double> v, v1, v2;
	mat1.resize(mat.size());
	for(int i=0; i<mat1.size(); i++) {
		mat1[i].resize(x*3);
	}

	int j;

	for(int i=0; i<mat.size(); i++) {
		v1.resize(0);
		v.resize(0);
		v2.resize(0);
		j=0;
		while(j<x) {
			v.push_back(mat[i][j]);
			j++;
		}
		for(int k=v.size()-1; k>=0; k--) v1.push_back(v[k]);
		v2=v1;
		for(int k=0; k<v.size(); k++) v1.push_back(v[k]);
		for(int k=0; k<v2.size(); k++) v1.push_back(v2[k]);
		mat1[i]=v1;
	}
	mat2.resize(mat1.size());
	for(int i=0; i<mat1.size(); i++) mat2[i]=mat1[i];

	int i=0;
	int k=mat1.size()-1;
	while(i<=k/2) {
		v=mat1[i];
		v1=mat1[k];
		mat1[i]=v1;
		mat1[k]=v;
		i++;
		k--;
	}
	mat3.resize(mat1.size());
	for(int i=0; i<mat1.size(); i++) mat3[i]=mat1[i];

	int n=mat.size();
	mat1.resize(n+n);
	for(int i=n; i<mat1.size(); i++) {
		for(int j=0; j<mat2.size(); j++) {
			mat1[i]=mat2[j];
			i++;
		}
	}
	int m=mat1.size();
	mat1.resize(mat1.size()+n);

	for(int j=0; j<mat3.size(); j++) {
		mat1[m]=mat3[j];
		m++;
	}




	return mat1;
}


int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica mat, mat1;
	std::cout<<"Unesite elemente matrice: ";
	mat.resize(m);
	for(int i=0; i<m; i++) mat[i].resize(n);
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin>>mat[i][j];
		}
	}

	mat1=OgledaloMatrica(mat);
	std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
	for(int i=0; i<mat1.size(); i++) {
		for(int j=0; j<mat1[i].size(); j++) {
			std::cout<<std::setw(4)<<mat1[i][j];
		}
		std::cout<<std::endl;
	}
	return 0;
}
#include <iostream>
#include <vector>

std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double>v) {
	std::vector<std::vector<double>>mat;
	std::vector<int>brojac(v.size(),0);
    int j;
	for (int i=0; i<v.size()-1; i++) {
		j=i;
		while (j<v.size()-1 && v[j]<=v[j+1]) {
			brojac[i]++;
			j++;
		}
	}
	int min=0,min1=0;
	for (int i=0; i<brojac.size(); i++) {
		if (brojac[i]>=min) {
			min=brojac[i];
			min1=brojac[i]; //koliko ima elemenata
		}
		
	}
	if (min==0) return mat;
	int ima=0;
	for (int i=0; i<brojac.size(); i++) {
		if (min==brojac[i]) ima++;
	}
	mat.resize(ima);
	for (int i=0; i<mat.size(); i++) {
		mat[i].resize(min1+1);
	}

	int m=-1;
	for (int i=0; i<v.size(); i++) {
		int index=i;
		if (brojac[i]==min) {
			for (int k=0; k<min1+1; k++) {
				mat[m+1][k]=v[index];
				index++;
			}
			m++;
		}
	}
	return mat;
}
std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double>v) {
	std::vector<std::vector<double>>mat;
	std::vector<int>brojac(v.size(),0);
    int j;
	for (int i=0; i<v.size()-1; i++) {
		j=i;
		while (j<v.size()-1 && v[j]>=v[j+1]) {
			brojac[i]++;
			j++;
		}
	}
	int min=0, min1=0;
	for (int i=0; i<brojac.size(); i++) {
		if (brojac[i]>=min) {
			min=brojac[i];
			min1=brojac[i];
		}
	}
	if (min==0) return mat;
	int ima=0;
	for (int i=0; i<brojac.size(); i++) {
		if (min==brojac[i]) ima++;
	}
	mat.resize(ima);
	for (int i=0; i<mat.size(); i++) {
		mat[i].resize(min1+1);
	}
	int m=-1;
	for (int i=0; i<v.size(); i++) {
		int index=i;
		if (brojac[i]==min) {
			for (int k=0; k<min1+1; k++) {
				mat[m+1][k]=v[index];
				index++;
			}
			m++;
		}
	}

	return mat;
}
int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double>v;
	double a;
	std::cout<<"Unesite elemente vektora: ";
	for (int i=0; i<n; i++) {
		std::cin>>a;
		v.push_back(a);
	}
	std::vector<std::vector<double>>mat;
	mat=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat[i].size(); j++)
			std::cout<<mat[i][j]<<" ";
		std::cout<<std::endl;

	}
	std::vector<std::vector<double>>mat1;
	mat1=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for (int i=0; i<mat1.size(); i++) {
		for (int j=0; j<mat1[i].size(); j++) {
			std::cout<<mat1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
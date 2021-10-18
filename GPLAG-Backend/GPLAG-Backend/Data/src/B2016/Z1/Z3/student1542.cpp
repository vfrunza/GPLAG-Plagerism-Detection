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
#include <cmath>

bool stepeni_broja_dva(double  vektor)
{

	bool stepen(false);
	for(int j = 0; j < 30; j++) {
		if(j*log(2) == log(vektor))
			stepen=true;
	}
	return stepen;
}
std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double>v)
{
	std::vector<double>v1;

	int br(0);
	int razlika(0);
	int pocetak(0),kraj(0),brojac(0);
	for(int i=0; i<v.size(); i++) {
		if(i<v.size()-1 && v[i]<=v[i+1]) {
			pocetak=i;
			while(i<v.size()-1 && v[i]<=v[i+1] ) {
				i++;
				kraj=i;
			}

			for(int j=pocetak; j<=kraj; j++)
				if(stepeni_broja_dva(v[j])==0) {
					br=j;
					break;
				}
			std::cout<<br<<" # ";
			if(br!=0)
				razlika=kraj-br+1;
			if(br!=0 && kraj-pocetak==1)razlika=kraj-br+2;
			v1.push_back(pocetak);
			v1.push_back(kraj-razlika);

			razlika=0;
			br=0;
		}
	}

	for(int i=0; i<v1.size(); i++)
		std::cout<<v1[i]<<" ++ ";
	std::vector<std::vector<double>>matrica(v1.size()/2);
	for(int i=0; i<matrica.size(); i++) {
		for(int j=v1[brojac]; j<=v1[brojac+1]; j++)
			matrica[i].push_back(v[j]);

		brojac+=2;
	}
	return matrica;
}
std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double>v)
{
	std::vector<double>v1;
	int pocetak(0),kraj(0),brojac(0),razlika(0),br(0);
	for(int i=0; i<v.size(); i++) {
		if(i<v.size()-1 && v[i]>=v[i+1]) {
			pocetak=i;
			while(i<v.size()-1 && v[i]>=v[i+1]) {
				i++;
				kraj=i;
			}
			for(int j=pocetak; j<=kraj; j++)
				if(stepeni_broja_dva(v[j])==0) {
					br=j;
					break;
				}
			//std::cout<<br<<" # ";
			if(br!=0)
				razlika=kraj-br+1;
			if(br!=0 && kraj-pocetak==1)razlika=kraj-br+2;
			v1.push_back(pocetak);
			v1.push_back(kraj-razlika);

			razlika=0;
			br=0;
		}
	}


	std::vector<std::vector<double>>mat(v1.size()/2);
	for(int i=0; i<mat.size(); i++) {
		for(int j=v1[brojac]; j<=v1[brojac+1]; j++)
			mat[i].push_back(v[j]);
		brojac+=2;
	}

	return mat;
}
int main ()
{
	std::vector<std::vector<double>>m1,m2;
	std::vector<double>v1,v2;
	int n1;
	double e;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n1;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n1; i++) {
		std::cin>>e;
		v1.push_back(e);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	m1=(RastuciPodnizovi(v1));
	for(int i=0; i<m1.size(); i++) {
		for(int j=0; j<m1[i].size(); j++) {
			std::cout<<m1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;

	m2=(OpadajuciPodnizovi(v1));
	for(int i=0; i<m2.size(); i++) {
		for(int j=0; j<m2[i].size(); j++) {
			std::cout<<m2[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
using namespace std;

std::vector<std::vector<double>> h(std::vector<std::vector<double>> matrica)
{
	std::vector<std::vector<double>> nova;
	for(int i=0; i<matrica.size(); i++) {
		std::vector<double> red;
		for(int j=0; j<matrica[i].size(); j++) {
			red.push_back(matrica[i][matrica[i].size()-j-1]);
		}
		nova.push_back(red);
	}
	return nova;
}
std::vector<std::vector<double>> v(std::vector<std::vector<double>> matrica)
{
	std::vector<std::vector<double>> nova;
	for(int i=0; i<matrica.size(); i++) {
		std::vector<double> red;
		for(int j=0; j<matrica[i].size(); j++) {
			red.push_back(matrica[matrica.size()-i-1][j]);
		}
		nova.push_back(red);
	}
	return nova;
}
std::vector<std::vector<double>> hv(std::vector<std::vector<double>> matrica)
{
	std::vector<std::vector<double>> nova;
	for(int i=0; i<matrica.size(); i++) {
		std::vector<double> red;
		for(int j=0; j<matrica[i].size(); j++) {
			red.push_back(matrica[matrica.size()-i-1][matrica[i].size()-j-1]);
		}
		nova.push_back(red);
	}
	return nova;
}
vector<vector<double>> OgledaloMatrica(vector<vector<double>> matrica) {
	//baci izuzetak ako je grbava matrica
	if(matrica.size()!=0)
	{
	for(int i=0;i<matrica.size()-1;i++)
	{
		if(matrica[i].size()!=matrica[i+1].size()) throw domain_error("Matrica nije korektna");
	}
	}
	std::vector<std::vector<double>> nova;
	std:vector<std::vector<double>> hv1,v1,h1;
	hv1=hv(matrica);
	v1=v(matrica);
	h1=h(matrica);
	int brojRedova=matrica.size();
	int brojacRedova=0,brojacKolona=0;
	int brojac=0;
	int brojKolona;
	if(matrica.size()!=0)
	brojKolona=matrica[0].size();
	else brojKolona=0;
	for(int i=0;i<3*brojRedova;i++)
	{
		
		std::vector<double> red;
		 for(int j=0;j<3*brojKolona;j++)
		 {
		 	if(brojacKolona>=brojKolona) brojacKolona=0;
		 	if(brojacRedova>=brojRedova) brojacRedova=0;
		 	if(i<brojRedova && j<brojKolona || i<brojRedova && j>=2*brojKolona || i>=2*brojRedova && j>=2*brojKolona || i>=2*brojRedova && j<brojKolona)
		 	{
		 	//	ide matrica hv;
		 	red.push_back(hv1[brojacRedova][brojacKolona]);
		 	}
		 	else if(i<2*brojRedova && i>=brojRedova &&(j<brojKolona || j>=2*brojKolona))
		 	{
		 		//sad ide ona horizonalna
		 		red.push_back(h1[brojacRedova][brojacKolona]);
		 	}
		 	else if(j<2*brojKolona && j>=brojKolona &&(i<brojRedova || i>=2*brojRedova))
		 	{
		 		//sad ide ona vertikalna
		 		red.push_back(v1[brojacRedova][brojacKolona]);
		 	}
		 	else
		 	{
		 		//ide obicna
		 		red.push_back(matrica[brojacRedova][brojacKolona]);
		 	}
		 	
		 	brojacKolona++;
		 	}
			brojacRedova++;
			nova.push_back(red);
		 }
	return nova;
}

int main ()
{
	std::vector<vector<double>> matrica;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin>>m>>n;
	if(m<0 || n<0)
	{
	std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	}
	else
	{
	matrica.resize(m);
	for(int i=0; i<matrica.size(); i++) {
		matrica[i].resize(n);
	}
	std::cout<<"Unesite elemente matrice:";
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin>>matrica[i][j];
			if(std::cin.fail()) throw std::domain_error("Unesen znak koji nije broj!");
		}
	}
	matrica=OgledaloMatrica(matrica);
	std::cout<<endl<<"Rezultantna matrica: "<<endl;
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[i].size(); j++) {
			if(j==0)
			std::cout<<std::setw(4)<<matrica[i][j]<<" ";
			else
			std::cout<<std::setw(3)<<matrica[i][j]<<" ";
			
		}
		std::cout<<std::endl;
	}
	return 0;
	}
}
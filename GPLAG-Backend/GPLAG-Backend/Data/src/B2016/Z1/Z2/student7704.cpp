/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

std::vector<std::vector<double>> HorMatrica(std::vector<std::vector<double>> v){
	std::vector<std::vector<double>> v2;
	v2.resize(v.size());
	for(int i=0;i<v.size();i++){
		for(int j=v[i].size()-1;j>=0;j--){
			v2[i].push_back(v[i][j]);
		}
	}
	return v2;
}

std::vector<std::vector<double>> VerMatrica(std::vector<std::vector<double>> v){
	std::vector<std::vector<double>> v2;
	v2.resize(v.size());
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			v2[v.size()-i-1].push_back(v[i][j]);
		}
	}
	return v2;
}
std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> v){
	if(v.size()!=0){
		int test=v[0].size();
		for(int i=0;i<v.size();i++)
		if(test!=v[i].size()) throw std::domain_error("Matrica nije korektna");
	}
	std::vector<std::vector<double>> v1,v2,v3,v4;
	v1=HorMatrica(v);
	v2=VerMatrica(v);
	v3=VerMatrica(v1);
	int br=v.size();
	int k;
	if(v.size()>=1) k=v[0].size();
	v4.resize(3*br);
	for(int i=0;i<br;i++){
		for(int j=0;j<k;j++){
			v4[i].push_back(v3[i][j]);
			v4[br+i].push_back(v1[i][j]);
			v4[2*br+i].push_back(v3[i][j]);
		}
	}
	for(int i=0;i<br;i++){
		for(int j=0;j<k;j++){
			v4[i].push_back(v2[i][j]);
			v4[br+i].push_back(v[i][j]);
			v4[2*br+i].push_back(v2[i][j]);
		}
	}
	for(int i=0;i<br;i++){
		for(int j=0;j<k;j++){
			v4[i].push_back(v3[i][j]);
			v4[br+i].push_back(v1[i][j]);
			v4[2*br+i].push_back(v3[i][j]);
			
		}
	}
	return v4;
}

int main ()
{
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>n>>m;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double>> v;
	v.resize(n);
	int k;
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			std::cin>>k;
			v[i].push_back(k);
		}
	}
	std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
	v=OgledaloMatrica(v);
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			std::cout<<std::setw(4)<<v[i][j];
		}
		std::cout<<std::endl;
	}
	return 0;
}
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

std::vector<std::vector<double>> vertikalno(std::vector<std::vector<double>> matrica) {
	std::vector<std::vector<double>> m;
	for(int i(matrica.size()-1);i>=0;i--)
		m.push_back(matrica[i]);
	return m;
}

std::vector<std::vector<double>> horizontalno(std::vector<std::vector<double>> matrica) {
	std::vector<std::vector<double>> m;
	std::vector<double> red;
	for(int i(0);i<matrica.size();i++){
		for(int j(matrica[i].size()-1);j>=0;j--){
			red.push_back(matrica[i][j]);
		}
		m.push_back(red);
		red.resize(0);
	}
	return m;
}

std::vector<std::vector<double>> kombinovano(std::vector<std::vector<double>> matrica) {
	matrica = horizontalno(matrica);
	matrica = vertikalno(matrica);
	return matrica;
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> matrica) {
	if(!matrica.size()) return matrica;
	for(int i(0);i<matrica.size();i++)
		if(matrica[i].size() != matrica[0].size())
			throw std::domain_error("Matrica nije korektna");
	std::vector<std::vector<double>> m1(horizontalno(matrica));
	std::vector<std::vector<double>> m2(vertikalno(matrica));
	std::vector<std::vector<double>> m3(kombinovano(matrica));
	std::vector<std::vector<double>> rezultat;
	std::vector<double> red;
	red.resize(0);
	for(int i(0);i<matrica.size();i++) {
		for(int j(0);j<matrica[i].size();j++){
			red.push_back(m3[i][j]);
		}
		for(int j(0);j<matrica[i].size();j++){
			red.push_back(m2[i][j]);
		}
		for(int j(0);j<matrica[i].size();j++){
			red.push_back(m3[i][j]);
		}
			std::cout<<std::endl;
		rezultat.push_back(red);
		red.resize(0);
	}
	red.resize(0);
	for(int i(0);i<matrica.size();i++) {
		for(int j(0);j<matrica[i].size();j++){
			red.push_back(m1[i][j]);
		}
		for(int j(0);j<matrica[i].size();j++){
			red.push_back(matrica[i][j]);
		}
		for(int j(0);j<matrica[i].size();j++){
			red.push_back(m1[i][j]);
		}
		rezultat.push_back(red);
		red.resize(0);
	}
	red.resize(0);
	for(int i(0);i<matrica.size();i++) {
		for(int j(0);j<matrica[i].size();j++){
			red.push_back(m3[i][j]);
		}
		for(int j(0);j<matrica[i].size();j++){
			red.push_back(m2[i][j]);
		}
		for(int j(0);j<matrica[i].size();j++){
			red.push_back(m3[i][j]);
		}
		rezultat.push_back(red);
		red.resize(0);
	}
	return rezultat;
}

int main ()
{
	int a,b;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>a>>b;
	if(a<0 || b<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!"<<std::endl;
		return 0;
	}
	std::vector<std::vector<double>> m(a,std::vector<double>(b,0));
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	for(int i(0);i<a;i++)
		for(int j(0);j<b;j++)
			std::cin>>m[i][j];
	std::vector<std::vector<double>> o(OgledaloMatrica(m));
	std::cout<<"Rezultantna matrica: "<<std::endl;
	for(int i(0);i<o.size();i++){
		for(int j(0);j<o[i].size();j++)
			std::cout<<std::setw(4)<<o[i][j];
			std::cout<<std::endl;
	}
	return 0;
}
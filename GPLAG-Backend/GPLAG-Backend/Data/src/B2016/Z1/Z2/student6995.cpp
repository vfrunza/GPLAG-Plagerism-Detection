#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;
bool DaLiJeGrbava(Matrica m){

	for(int i(1);i < m.size();i++){
		if(m[i].size() != m[i-1].size()) return true;
	}

	
	return false;
}

Matrica OgledaloMatrica(Matrica m){
	Matrica x;
	if(DaLiJeGrbava(m)){
		throw std::domain_error("Matrica nije korektna");
	}
	
	x.resize(3*m.size());
	for(int i(0);i < x.size();i++){
		x[i].resize(3*m[0].size());
	}
	for(int i(0);i < m.size();i++){
		for(int j(0);j < m[0].size();j++){
//horizontalno vertikalna matrica
		x[i][j]=m[m.size() - 1 -i][m[0].size() - 1 -j];
		x[i][j+2*m[0].size()] = m[m.size() - 1 -i][m[0].size() - 1 -j];
		x[i+2*m.size()][j+2*m[0].size()] = m[m.size() - 1 -i][m[0].size() - 1 -j];
		x[i+2*m.size()][j] = m[m.size() - 1 -i][m[0].size() - 1 -j];
//matrica
		x[i+m.size()][j+m[0].size()]=m[i][j];
//vertikalna matrica
		x[i][j+m[0].size()]=m[m.size()-1-i][j];
		x[i+2*m.size()][j+m[0].size()]=m[m.size()-1-i][j];
//horizontalna matrica
		x[i+m.size()][j]=m[i][m[0].size()-1-j];
		x[i+m.size()][j+2*m[0].size()]=m[i][m[0].size()-1-j];
		
		}
	}
	return x;
}
int main ()
{
try{
int m,n;
Matrica x;
std::cout << "Unesite dimenzije matrice (m n): ";

	std::cin >> m >> n;
	if(m < 0 || n < 0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
x.resize(m);
for(int i(0);i < x.size();i++) {
	x[i].resize(n);
}
std::cout << "Unesite elemente matrice: ";
for(int i(0);i < x.size();i++){
	for(int j(0);j < x[0].size();j++){
		
		std::cin >> x[i][j];
		
	} 
}
auto ogledalo(OgledaloMatrica(x));
std::cout << "\nRezultantna matrica: \n";

for(auto y : ogledalo){
	for(auto z : y) std::cout << std::setw(4) << z;
	std::cout << std::endl;
}
}catch(std::domain_error izuzetak){
	std::cout << "Izuzetak: " << izuzetak.what();
}

	return 0;
}
/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <stdexcept>
bool jeLiGrbava(std::vector<std::vector<double>> matrica){
	if(matrica.size()!=0){
		int x=matrica[0].size();
		for(int i=0;i<matrica.size();i++)
			if(matrica[i].size()!=x) return true;
		return false;
	}
	return false;
}
std::vector<std::vector<double>> VertikalnaMatrica(std::vector<std::vector<double>> matrica){
	if(jeLiGrbava(matrica)) throw std::domain_error("Matrica nije korektna");
	std::vector<double> temp;
	int x=matrica.size()-1;
	for(int i(0);i<matrica.size()/2;i++){
		temp=matrica[i];
		matrica[i]=matrica[x-i];
		matrica[x-i]=temp;
	}
	return matrica;
}
std::vector<std::vector<double>> HorizontalnaMatrica(std::vector<std::vector<double>> matrica){
	if(jeLiGrbava(matrica)) throw std::domain_error("Matrica nije korektna");
	for(int i(0);i<matrica.size();i++){
		int x=matrica[i].size()-1;
		for(int j(0);j<matrica[i].size()/2;j++){
			double temp=matrica[i][j];
			matrica[i][j]=matrica[i][x-j];
			matrica[i][x-j]=temp;
		}
	}
	return matrica;
}
std::vector<std::vector<double>> KombinovanaMatrica(std::vector<std::vector<double>> matrica){
	try{
		matrica=HorizontalnaMatrica(matrica);
		matrica=VertikalnaMatrica(matrica);
	}
	catch(std::domain_error e){
		throw e;
	}
	return matrica;
}
std::vector<double> Saberi(std::vector<double> prvi, std::vector<double> drugi, std::vector<double> treci){
	std::vector<double> povratni=prvi;
	for(int i=0;i<drugi.size();i++) povratni.push_back(drugi[i]);
	for(int i=0;i<treci.size();i++) povratni.push_back(treci[i]);
	return povratni;
}
std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> matrica){
	std::vector<std::vector<double>> povratna;
	try{
		std::vector<std::vector<double>> hor,ver,komb;
		hor=HorizontalnaMatrica(matrica); 
		ver=VertikalnaMatrica(matrica);
		komb=KombinovanaMatrica(matrica);
		for(int i=0;i<hor.size();i++) povratna.push_back(Saberi(komb[i],ver[i],komb[i]));
		for(int i=0;i<hor.size();i++) povratna.push_back(Saberi(hor[i],matrica[i],hor[i]));
		for(int i=0;i<hor.size();i++) povratna.push_back(Saberi(komb[i],ver[i],komb[i]));
	}
	catch(std::domain_error e){
		throw e;
	}
	return povratna;
}
int main ()
{
	try{
		std::cout<<"Unesite dimenzije matrice (m n): ";
		int m,n;
		std::cin>>m>>n;
		if(m<0 || n<0){
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		std::vector<std::vector<double>> matrica(m,std::vector<double>(n));
		std::cout<<"Unesite elemente matrice: \n";
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				std::cin>>matrica[i][j];
			}
		}
		matrica=OgledaloMatrica(matrica);
		std::cout<<"Rezultantna matrica: \n";
		for(int i=0;i<matrica.size();i++){
			for(int j=0;j<matrica[i].size();j++){
				std::cout<<std::setw(4)<<matrica[i][j];
			}
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error e){
		std::cout<<e.what();
	}
	return 0;
}
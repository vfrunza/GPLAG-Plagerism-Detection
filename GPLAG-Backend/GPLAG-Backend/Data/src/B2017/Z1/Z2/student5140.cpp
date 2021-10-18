/*B 2017/2018, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include <vector>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;

double suma(Matrica matrica){
	double suma(0);
	for(int i=0;i<(matrica.size()/3);i++){
		for(int j=0;j<(matrica.at(i).size/3);j++){
			if(i!=j) suma+=matrica.at(i).at(j);
		}
	}
	return suma;
}

Matrica NajvecaPlaninaMatrice(Matrica matrica)
{
	Matrica najvecaPlanina, mozdaNajvecaPlanina;
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica.at(i).size(); i++) {
			double suma(0);
			int pamti;
			
			
			std::cout<<std::endl<<suma<<std::endl;
			if(matrica.at(pamti).at(pamti)>suma){
				int brojac_i(0);
				for(int k=i-1;k<=i+1;k++){
					for(int l=i-1;l<=i+1;l++){
					mozdaNajvecaPlanina.push_back(std::vector<double> (0));
						mozdaNajvecaPlanina.at(brojac_i).push_back(matrica.at(k).at(l));
					}
					brojac_i++;
				}
			}
			return mozdaNajvecaPlanina;
			suma=0;
		}
	}

return najvecaPlanina;
}


int main ()
{
	int visina, sirina;
	std::cout<<"Unesite visinu matrice: ";
	std::cin>>visina;
	std::cout<<"Unesite sirinu matrice: ";
	std::cin>>sirina;
	std::cout<<"Unesite matricu: ";
	
	std::vector<std::vector<double>> matrica(visina, std::vector<double> (sirina));
	for(int i=0; i<visina; i++) {
		for(int j=0; j<sirina; j++) {
			std::cin>>matrica.at(i).at(j);
		}
	}
	Matrica najvecaPlanina(NajvecaPlaninaMatrice(matrica));
	for(int i=0; i<najvecaPlanina.size(); i++) {
		for(int j=0; j<najvecaPlanina.at(i).size(); j++) {
			std::cout<<std::setw(3)<<najvecaPlanina.at(i).at(j);
		}
		std::cout<<std::endl;
	}
	return 0;
}
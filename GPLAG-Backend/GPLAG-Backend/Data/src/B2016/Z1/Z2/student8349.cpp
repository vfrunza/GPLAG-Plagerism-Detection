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
std::vector<std::vector<double>>OgledaloMatrica (std::vector<std::vector<double>>matrica){
	//empty
	if(matrica.size()==0)	return matrica;
	int duzina(matrica.size());
	int sirina(matrica[0].size());
	//grbava matrica
	for(int i=0; i<duzina; i++){
		for(int j=0; j<sirina; j++){
			if(matrica[i].size()!=sirina)
				throw std::domain_error("Matrica nije korektna");
		} 
	}
	//m praznih redova
	for(int i=0; i<duzina; i++){
		if(matrica[i].size()==0){
			std::vector<std::vector<double>>prazna(3*matrica.size(),std::vector<double>(0));
			return prazna;
		}
	}
	std::vector<std::vector<double>>hv(duzina, std::vector<double>(sirina));
	std::vector<std::vector<double>>h(duzina, std::vector<double>(sirina));
	std::vector<std::vector<double>>v(duzina, std::vector<double>(sirina));
	std::vector<std::vector<double>>ogledalce(duzina*3, std::vector<double>(sirina*3));
	//horizontalno ogledalo
	for(int i=0; i<int(duzina); i++){
		int k(0);
		for(int j=int(sirina)-1; j>=0; j--){
			h[i][k]=matrica[i][j];
			k++;
		}
	}
	//vertikalno ogledalo 
	int temp_v(0);
	for(int i=duzina-1; i>=0; i--){
		for(int j=0; j<sirina; j++){
			v[temp_v].at(j)=matrica[i][j];
		}
		temp_v++;
	}
	//kombinovano ogledalo
	int temp_hv(0);
	for(int i=duzina-1; i>=0; i--){
		for(int j=0; j<sirina; j++){
			hv[temp_hv][j]=h[i][j];
		}
		temp_hv++;
	}
	//pisi glavnu
	for(int i=0; i<matrica.size(); i++){
		for(int j=0; j<matrica[i].size(); j++){
			ogledalce[i+matrica.size()][j+matrica[i].size()]=matrica[i][j];
		}
	}
	//pisi horizontalnu
	for(int i=0; i<matrica.size(); i++){
		for(int j=0; j<matrica[i].size(); j++){
			ogledalce[i+matrica.size()][j]=h[i][j];
			ogledalce[i+matrica.size()][j+2*matrica[i].size()]=h[i][j];
		}
	}
	//pisi vertikalnu
	for(int i=0; i<int(matrica.size()); i++){
		for(int j=0; j<int(matrica[i].size()); j++){
			ogledalce[i][j+matrica[i].size()]=v[i][j];
			ogledalce[i+2*matrica.size()][j+matrica[i].size()]=v[i][j];
		}
	}
	//pisi u veliku (kombinovana)
	for(int i=0; i<matrica.size(); i++){
		for(int j=0; j<matrica[i].size(); j++){
			ogledalce[i][j]=hv[i][j];
			ogledalce[i+2*matrica.size()][j]=hv[i][j];
			ogledalce[i][j+2*matrica[i].size()]=hv[i][j];
			ogledalce[i+2*matrica.size()][j+2*matrica[i].size()]=hv[i][j];
		}
	}

	return ogledalce;
}
int main ()
{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cin.ignore(10000, '\n');
	//ocisti spremnik (just in case) i unos
	std::vector<std::vector<double>>matrica(m, std::vector<double>(n));
	std::cout<<"Unesite elemente matrice:";
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin>>matrica[i][j];
		}
	}
	std::vector<std::vector<double>>ogledalce;
	try{
		ogledalce=OgledaloMatrica(matrica);
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
		return 0;
	}
	//ispis
	std::cout<<"\nRezultantna matrica:"<<std::endl;
	for(int i=0; i<3*m; i++){
		for(int j=0; j<3*n; j++){
			std::cout<<std::setw(4)<<ogledalce[i][j];
		}
		std::cout<<std::endl;
	}
	
	return 0;
}
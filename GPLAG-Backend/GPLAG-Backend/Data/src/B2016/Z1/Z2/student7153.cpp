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

std::vector<std::vector<double>> HorizontalnaMatrica (std::vector<std::vector<double>> matrica){
	
	for(int i = 0 ; i < matrica.size() ; i++){
		for(int j = 0 ; j < matrica.at(i).size(); j++){
			
		}
	}
	return matrica;
}

std::vector<std::vector<double>> VertikalnaMatrica ( std::vector<std::vector<double>> matrica){
	for (int i = 0 ; i < matrica.size(); i++){
		for (int j = 0 ; j < matrica.size(); j++){
			std::vector<std::vector<double>> pomocna;
			pomocna = (matrica[0][0]);
			matrica[0][0] = (matrica[matrica.size() - 1][0]);
			matrica[matrica.size() - 1][0] = (pomocna);
		}
	}
	return matrica;
}

std::vector<std::vector<double>> KombinovanaMatrica ( std::vector<std::vector<double>> matrica){
	for (int i = 0 ; i < matrica.size(); i++){
		for (int j = 0 ; j < matrica.size(); j++){
			std::vector<std::vector<double>> pomocna;
			pomocna = (matrica[0][0]);
			matrica[0][0] = (matrica[matrica.size() - 1][0]);
			matrica[matrica.size() - 1][0] = (pomocna);
		}
			std::vector<std::vector<double>> pomocna_mat;
			pomocna_mat = (matrica[0][0]);
			matrica[0][0] = (matrica[0][matrica.size() - 1]);
			matrica[0][matrica.size() - 1] = (pomocna_mat);
	}
	return matrica;
}


std::vector<std::vector<double>> OgledaloMatrica ( std::vector<std::vector<double>> nekamatrica){
	std::vector<std::vector<double>> horizontalna(HorizontalnaMatrica(nekamatrica));
	std::vector<std::vector<double>> vertikalna(VertikalnaMatrica(nekamatrica));
	std::vector<std::vector<double>> kombinovana(KombinovanaMatrica(nekamatrica));
	
	for (int i = 0 ; i < nekamatrica.size() ; i++){
		for(int j = 0 ; j < nekamatrica.at(i).size() ; j++) {
			if ( i == 0 && i == nekamatrica.size() - 1 ) std::cout<<kombinovana<<vertikalna<<kombinovana<<std::cout<<"\n";
			else std::cout<<horizontalna<<" "<<nekamatrica<<" "<<horizontalna<<std::cout<<"\n";
		} 
	}
		
	return nekamatrica;
}

int main() {
	int m,n;
	
	std::cout<<"Unesite dimenzije matrice: ";
	std::cin>>m>>n;
	
	std::vector<std::vector<double>> matrica;
	for (int i = 0 ; i < m ; i++){
		for (int j = 0 ; j < n ; j++){
			int x; 
			std::cin>>x;
			matrica.at(i).pushback(x);
		}
	}
	
	std::vector<std::vector<double>> ogledalce(OgledaloMatrica(matrica));
	
	for (int i = 0 ; i < ogledalce.size(); i++){
		for(int j = 0 ; j < ogledalce.size(); j++){
			std::cout<<ogledalce.at(i).at(j);
			
		}
	}
	
	return 0;
}

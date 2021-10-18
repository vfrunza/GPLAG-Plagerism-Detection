/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;


Matrica RastuciPodnizovi(std::vector<double> a){
	Matrica mat;
	if(a.size() == 0 || a.size() == 1) return mat;
	int pocetak(-1), kraj(-1), broj_r_mat(0);
	for(int i=1 ; i<a.size() ; i++){
		bool zadnji_clan(false);
		if( a.at(i-1)<=a.at(i) ){  // prvi < od drugog -- > double std::abs(a.at(i-1) - std::abs(a.at(i) < 1./10000
			pocetak = i-1;
			while(a.at(i-1)<=a.at(i)) {
				if(i!=a.size()-1) i++;
				else {
					zadnji_clan=true;
					break;
				}
			} 
				
		}
		if(zadnji_clan) kraj=i;
		else kraj=i-1;
		
		if((pocetak < kraj)&&(pocetak!=-1)){
			broj_r_mat++;
			mat.resize(broj_r_mat );
			mat[broj_r_mat-1].resize(kraj-pocetak + 1);
			int l(0);
			for(int j=pocetak; j<=kraj;j++){
				mat[broj_r_mat-1][l] = a.at(j);
				l++;
			}
			pocetak=-1;
			kraj=-1;
		}
	}
	
	return mat;
}


Matrica OpadajuciPodnizovi(std::vector<double> a){
		Matrica mat;
	if(a.size() == 0 || a.size() == 1) return mat;
	int pocetak(-1), kraj(-1), broj_r_mat(0);
	for(int i=1 ; i<a.size() ; i++){
		bool zadnji_clan(false);
		if( a.at(i-1)>=a.at(i) ){
			pocetak = i-1;
			while(a.at(i-1)>=a.at(i)) {
				if(i!=a.size()-1) i++;
				else {
					zadnji_clan=true;
					break;
				}
			} 
				
		}
		if(zadnji_clan) kraj=i;
		else kraj=i-1;
		
		if((pocetak < kraj)&&(pocetak!=-1)){
			broj_r_mat++;
			mat.resize(broj_r_mat );
			mat[broj_r_mat-1].resize(kraj-pocetak + 1);
			int l(0);
			for(int j=pocetak; j<=kraj;j++){
				mat[broj_r_mat-1][l] = a.at(j);
				l++;
			}
			pocetak=-1;
			kraj=-1;
		}
	}
	
	return mat;
}
int main (){
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> a;
	for(int i=0; i<n ; i++){
		double b;
		std::cin >> b;
		a.push_back(b);
	}
	Matrica Ispis_1 , Ispis_2;
	Ispis_1 = RastuciPodnizovi(a);
	Ispis_2 = OpadajuciPodnizovi(a);
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(int i=0; i< Ispis_1.size() ; i++){
		for(int j=0; j<Ispis_1[i].size() ; j++){
			std::cout << Ispis_1 [i][j] << " ";
		}
		std::cout<<std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i=0; i< Ispis_2.size() ; i++){
		for(int j=0; j<Ispis_2[i].size() ; j++){
			std::cout << Ispis_2 [i][j] << " ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}
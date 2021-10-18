/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector> 

std::vector<std::vector<double>> RastuciPodnizovi (const std::vector<double> &v){
	std::vector<std::vector<double>> matrica;
	std::vector<double> redovi;
	int brojac(0), zapamti[100];
	redovi.resize(0);
	redovi.push_back(v[0]);
	for(int i=1; i<v.size(); i++){
		if(v[i-1]<=v[i]){
			redovi.push_back(v[i]);
			if(i==v.size()-1){
				zapamti[brojac]=redovi.size();
				brojac++;
				redovi.resize(0);
				redovi.push_back(v[i]);
			}
		}
		else if(redovi.size()!=1){
			zapamti[brojac]=redovi.size();
			brojac++;
			redovi.resize(0);
			redovi.push_back(v[i]);
		}
		else{
			redovi.resize(0);
			redovi.push_back(v[i]);
		}
	}
	
	matrica.resize(brojac);
	for(int i=0; i<brojac; i++)
		matrica[i].resize(zapamti[i]);
		
	brojac=0;
	redovi.resize(0);
	redovi.push_back(v[0]);
	for(int i=1; i<v.size(); i++){
		if(v[i]>=v[i-1]){
			redovi.push_back(v[i]);
			if(i==v.size()-1){
				brojac++;
				for(int j=brojac-1; j<brojac; j++)
					for(int k=0; k<redovi.size(); k++)
						matrica[j][k] = redovi[k];
				redovi.resize(0);
				redovi.push_back(v[i]);
			}
		}
		else if(redovi.size()!=1){
			brojac++;
			for(int j=brojac-1; j<brojac; j++)
				for(int k=0; k<redovi.size(); k++)
					matrica[j][k] = redovi[k];
			redovi.resize(0);
			redovi.push_back(v[i]);
		}
		else{
			redovi.resize(0);
			redovi.push_back(v[i]);
		}
	}
	return matrica;
}

void IspisiMatricu (const std::vector<std::vector<double>> &mat){
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[i].size(); j++){
			std::cout<<mat[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}

std::vector<std::vector<double>> OpadajuciPodnizovi (const std::vector<double> &v){
	int brojac(0), zapamti[100];
	std::vector<std::vector<double>> matrica;
	std::vector<double> redovi;
	redovi.resize(0);
	redovi.push_back(v[0]);
	for(int i=1; i<v.size(); i++){
		if(v[i]<=v[i-1]){
			redovi.push_back(v[i]);
			if(i==v.size()-1){
				zapamti[brojac]=redovi.size();
				brojac++;
				redovi.resize(0);
				redovi.push_back(v[i]);
			}
		}
		else if(redovi.size()!=1){
			zapamti[brojac]=redovi.size();
			brojac++;
			redovi.resize(0);
			redovi.push_back(v[i]);
		}
		else{
			redovi.resize(0);
			redovi.push_back(v[i]);
		}
	}
	matrica.resize(brojac);
	for(int i=0; i<brojac; i++)
		matrica[i].resize(zapamti[i]);
	brojac=0;
	redovi.resize(0);
	redovi.push_back(v[0]);
	for(int i=1; i<v.size(); i++){
		if(v[i]<=v[i-1]){
			redovi.push_back(v[i]);
			if(i==v.size()-1){
				brojac++;
				for(int j=brojac-1; j<brojac; j++)
					for(int k=0; k<redovi.size(); k++)
						matrica[j][k] = redovi[k];
				redovi.resize(0);
				redovi.push_back(v[i]);
			}
		}
		else if(redovi.size()!=1){
			brojac++;
			for(int j=brojac-1; j<brojac; j++)
				for(int k=0; k<redovi.size(); k++)
					matrica[j][k] = redovi[k];
			redovi.resize(0);
			redovi.push_back(v[i]);
		}
		else{
			redovi.resize(0);
			redovi.push_back(v[i]);
		}
	}
	return matrica;
}


int main(){
	std::vector<std::vector<double>> matrica;
	std::vector<double> v;
	int broj_elemenata, n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj_elemenata;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<broj_elemenata; i++){
		std::cin>>n;
		v.push_back(n);
	}
	std::cout <<"Maksimalni rastuci podnizovi: "<<std::endl;
	matrica=RastuciPodnizovi(v);
	IspisiMatricu(matrica);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	matrica=OpadajuciPodnizovi(v);
	IspisiMatricu(matrica);
	return 0;
	
}
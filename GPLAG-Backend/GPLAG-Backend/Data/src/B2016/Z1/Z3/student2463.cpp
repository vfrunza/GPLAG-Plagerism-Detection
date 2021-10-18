#include<iostream>
#include<vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> niz){
	Matrica mat;
	std::vector<double> temp;
	temp.push_back(niz[0]);
	int brojac=1;
	do{
		if(niz[brojac]>=niz[brojac-1])
			temp.push_back(niz[brojac]);
		else{
			if(temp.size()>1){
				mat.push_back(temp);
			}
			temp.resize(0);
			temp.push_back(niz[brojac]);
		}
		brojac++;
		if(temp.size()>1 && brojac == niz.size()) mat.push_back(temp);
	}while(brojac<niz.size());
	
	
	return mat;
}

Matrica OpadajuciPodnizovi(std::vector<double>niz){
	int brojac=1;
	Matrica mat;
	std::vector<double> temp;
	temp.push_back(niz[0]);
	do{
		if(niz[brojac]<=niz[brojac-1]){
			temp.push_back(niz[brojac]);
		}
		else{
			if(temp.size()>1) mat.push_back(temp);
			
			temp.resize(0);
			temp.push_back(niz[brojac]);
			
		}
		brojac++;
	}while(brojac<niz.size());
	if(temp.size()>1) mat.push_back(temp);
	return mat;
}

int main(){
	int n,broj;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	
	std::vector<double> vektor;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin>>broj;
		vektor.push_back(broj);
	}
	
	Matrica m1=RastuciPodnizovi(vektor);
	Matrica m2=OpadajuciPodnizovi(vektor);
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0;i<m1.size();i++){
		for(int j=0;j<m1[i].size();j++){
			std::cout<<m1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0;i<m2.size();i++){
		for(int j=0;j<m2[i].size();j++){
			std::cout<<m2[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
#include<iostream>
#include<vector>
#include<stdexcept>
typedef std::vector<std::vector<double> > matrice ;

matrice kreirajmat(int m, int n){
	return matrice(m,std::vector<double>(n));
}

int brpodnizovarastuci(std::vector<double> v){
	int br=0;
	for(int i=0;i<v.size()-1;i++){
		if(v[i]<=v[i+1]) {
			br++;
			while(v[i]<=v[i+1]){
				i++;
				if(i==v.size()-1) break;
			} 
		}
	}
	return br;
}
int brpodnizovaopadajuci(std::vector<double> v){
	int br=0;
	for(int i=0;i<v.size()-1;i++){
		if(v[i]>=v[i+1]) {
			br++;
			while(v[i]>=v[i+1]) {
				i++;
				if(i==v.size()-1) break;
			}
		}
	}
	return br;
}

matrice RastuciPodnizovi(std::vector<double> v){
	matrice rez;
	if(v.size()==0) return rez;
	int x=brpodnizovarastuci(v),tr=0;
	rez.resize(x);
	std::vector<int> kolone ;
	std::vector<double> pom=v;
	for(int i=0;i<v.size()-1;i++){
		int k=1;
		while (v[i]<=v[i+1]) {
			k++;
			i++;
			if(i==v.size()-1) {break; tr=1;}
		}
		if(k!=1){
		kolone.push_back(k);
		}
		if(tr) break;
		
	}
	for(int i=0;i<x;i++) rez[i].resize(kolone[i]);
	for(int i=0;i<pom.size()-2;i++){
		if(pom[i+1]<pom[i] && pom[i+1]>pom[i+2]){
			pom.erase(pom.begin()+1+i);
			i--;
		}
	}
	int a=0;
	for(int i=0;i<rez.size();i++){
		for(int j=0;j<rez[i].size();j++){
			double b=pom[a];
			rez[i][j]=b;
			a++;
		}
	}
	return rez;
}

matrice OpadajuciPodnizovi(std::vector<double> v){
	matrice rez;
	if(v.size()==0) return rez;
	int x=brpodnizovaopadajuci(v);
	rez.resize(x);
	std::vector<int> kolone ;
	std::vector<double> pom=v;
	for(int i=0;i<v.size()-1;i++){
		int k=1;
		while (v[i]>=v[i+1]) {
			k++;
			i++;
			if(i==v.size()-1) break;
		}
		if(k!=1){
		kolone.push_back(k);
		}
		
	}
	for(int i=0;i<x;i++) rez[i].resize(kolone[i]);
	for(int i=0;i<pom.size()-2;i++){
		if(pom[i+1]>pom[i] && pom[i+1]<pom[i+2]){
			pom.erase(pom.begin()+i+1);
			i--;
		}
	}
	if(pom[0]<pom[1]) pom.erase(pom.begin());
	int a=0;
	for(int i=0;i<rez.size();i++){
		for(int j=0;j<rez[i].size();j++){
			double b=pom[a];
			rez[i][j]=b;
			a++;
		}
	}
	return rez;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: " ;
	int n;
	std::cin>>n;
	std::cout << "Unesite elemente vektora: " ;
	std::vector<double> vec;
	for(int i=0;i<n;i++) {
		double x;
		std::cin>>x;
		vec.push_back(x);
	}
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	matrice rast=RastuciPodnizovi(vec) ;
	for(int i=0;i<rast.size();i++){
		for(int j=0;j<rast[i].size();j++){
			std::cout << rast[i][j] <<" ";
		}
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	matrice opad=OpadajuciPodnizovi(vec) ;
	for(int i=0;i<opad.size();i++){
		for(int j=0;j<opad[i].size();j++){
			std::cout << opad[i][j] <<" ";
		}
		std::cout << std::endl;
	}
	return 0;
}
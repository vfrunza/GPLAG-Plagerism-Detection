#include <iostream>
#include <vector>
typedef std::vector<std::vector<double>> Matrica;


int broj_rastucih(std::vector<int> v){
	int broj_nizova{};
	for(int i=0; i<v.size()-1;i++){
		while(v[i]<=v[i+1]){
			i++;
			broj_nizova++;
		}
	}
	return broj_nizova;
}
Matrica KreirajMatricu(int n=0){
	return Matrica(n, std::vector<double>(0));
}
Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica A{KreirajMatricu()};
	int duzina=v.size(),skok{};
	for(int i=0; i<duzina-1; i++){
		std::vector<double> pom{};
		bool ubacilo{false};
		if(v[i]<=v[i+1] && i<duzina){
			for(int j=i; j<duzina; j++){
				while(j<duzina-1 && v[j]<=v[j+1]){
					pom.push_back(v[j]);
					j++;
				}
				skok=j;
				pom.push_back(v[j]);
				ubacilo=true;
				break;
			}
			i=skok;
		}
	if(ubacilo){	
	A.push_back(pom);}	
	}
	return A;
}
Matrica OpadajuciPodnizovi(std::vector<double> v){
	Matrica A{KreirajMatricu()};
	int duzina=v.size(),skok{};
	for(int i=0; i<duzina-1; i++){
		std::vector<double> pom{};
		bool ubacilo{false};
		if(v[i]>=v[i+1] && i<duzina){
			for(int j=i; j<duzina; j++){
				while(j<duzina-1 && v[j]>=v[j+1]){
					pom.push_back(v[j]);
					j++;
				}
				skok=j;
				pom.push_back(v[j]);
				ubacilo=true;
				break;
			}
			i=skok;
		}
	if(ubacilo){	
	A.push_back(pom);}	
	}
	return A;
}

void IspisiMatricu(Matrica A){
	for(int i=0;i<A.size();i++){
		for(int j=0; j<A[i].size();j++){
			std::cout<<A[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
int main (){
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	double broj{};
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> a{};

	for(int i=0;i<n;i++){
		std::cin>>broj;
		a.push_back(broj);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	Matrica M{RastuciPodnizovi(a)};
	IspisiMatricu(M);
	
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	Matrica B{OpadajuciPodnizovi(a)};
	IspisiMatricu(B);
	
	
	return 0;
}
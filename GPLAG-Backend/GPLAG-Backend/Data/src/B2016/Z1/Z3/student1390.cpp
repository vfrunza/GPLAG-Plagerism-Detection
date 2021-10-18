/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> mat;
	int broj(0);
		int a(0);
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size();j++){
			if(v[i]!=v[j]){
				a=1;
				break;
			}
		}
	}
	if(a==0){
		std::vector<std::vector<double>>vektor;
		vektor.resize(1);
			for(int j=0;j<v.size();j++){
				vektor[0].push_back(v[j]);
			}
			return vektor;
	}
	for(int i=0;i<v.size()-1;i++){
		for(int j=i+1;j<v.size();j++){
			if(j==v.size()-1 && i==v.size()-2){
				if(v[j]>v[i])broj++;
			}
			while(v[j]>v[i]){
				i++;
				continue;
			}
			
			if(v[i]>v[j]){
				if(i==0)continue;
				if(v[j-1]>v[i-1]){
					broj++;
					j=v.size();
				}
				else i++;
			}
		}
	}
	mat.resize(broj);
	int pomocni(0);
	for(int i=0;i<v.size()-1;i++){
		for(int j=i+1;j<v.size();j++){
			while(v[j]>v[i]){
				if(i==v.size()-2 && j==v.size()-1){
					if(v[j-1]<v[i-1])mat[pomocni].push_back(v[j-1]);
					if(v[j-1]>v[i-1])mat[pomocni].push_back(v[i]);
					if(v[j]>v[i])mat[pomocni].push_back(v[j]);
					break;
				}
				mat[pomocni].push_back(v[i]);
				i++;
				continue;
				
			}
			if(v[i]>=v[j]){
				if((i==0))continue;
				if(v[i-1]>v[j-1]){
					i++;
					continue;
				}
				if(v[j-1]>v[i-1]){
					mat[pomocni].push_back(v[i]);
					j=v.size();
				}
			}
		}
		pomocni++;
		if(pomocni==broj)break;
	}

	return mat;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> mat;
	int broj(0);
	int a(0);
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size();j++){
			if(v[i]!=v[j]){
				a=1;
				break;
			}
		}
	}
	if(a==0){
		std::vector<std::vector<double>>vektor;
		vektor.resize(1);
			for(int j=0;j<v.size();j++){
				vektor[0].push_back(v[j]);
			}
			return vektor;
	}
	for(int i=0;i<v.size()-1;i++){
		for(int j=i+1;j<v.size();j++){
			if(j==v.size()-1 && i==v.size()-2){
				if(v[j]<v[i])broj++;
				if(v[i-1]>v[j-1])broj++;
			}
			while(v[j]<v[i]){
				i++;
				continue;
			}
			
			if(v[i]<v[j]){
				if(i==0){
					i++;
					continue;
				}
				if(v[j-1]<v[i-1]){
					broj++;
					j=v.size();
				}
				else i++;
			}
		}
	}
	mat.resize(broj);
	int pomocni(0);
	for(int i=0;i<v.size()-1;i++){
		for(int j=i+1;j<v.size();j++){
			while(v[j]<v[i]){
				if(i==v.size()-2 && j==v.size()-1){
					if(v[j-1]>v[i-1])mat[pomocni].push_back(v[j-1]);
					if(v[j-1]<v[i-1])mat[pomocni].push_back(v[i]);
					if(v[j]<v[i])mat[pomocni].push_back(v[j]);
					break;
				}
				mat[pomocni].push_back(v[i]);
				i++;
				continue;
				
			}
			if(v[i]<=v[j]){
				if((i==0)){
					i++;
					continue;
				}
				if(v[i-1]<v[j-1]){
					i++;
					continue;
				}
				if(v[j-1]<v[i-1]){
					mat[pomocni].push_back(v[i]);
					j=v.size();
				}
			}
		}
		pomocni++;
		if(pomocni==broj)break;
	}
	

	return mat;
}
int main ()
{
	int a;
	double b;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>a;
	std::vector<double> v;
	int i(0);
	std::cout << "Unesite elemente vektora: " ;
	do{
		std::cin>>b;
		v.push_back(b);
		i++;
	}while(i<a);
	std::vector<std::vector<double>>Matrica;
	Matrica=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	int pomocni1(0);
	for(int i=0;i<Matrica.size();i++){
		for(int j=0;j<Matrica[pomocni1].size();j++){
			std::cout << std::setprecision(12) << Matrica[i][j] << " ";
		}
		std::cout << std::endl;
		pomocni1++;

	}
	std::vector<std::vector<double>>Matrica2;
	Matrica2=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	int pomocni(0);
	for(int i=0;i<Matrica2.size();i++){
		for(int j=0;j<Matrica2[pomocni].size();j++){
			std::cout << std::setprecision(12) << Matrica2[i][j] << " ";
		}
		std::cout << std::endl;
		pomocni++;
	}
	
	return 0;
}
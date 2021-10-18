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
typedef std::vector<std::vector<double>>MAT;

MAT RastuciPodnizovi(std::vector<double>vektor){
int vel;
MAT vrati;
	std::vector<double>temp;
	vektor.resize(vektor.size()+1);
	for(int i=0;i<vektor.size()-1;i++){
		if(i<vektor.size() && vektor[i]<=vektor[i+1])
		temp.push_back(vektor[i]);
 	else if(vektor[i]>vektor[i+1]){
		temp.push_back(vektor[i]);
		if(temp.size()!=1 && temp.size()!=0) vrati.push_back(temp);
		temp.resize(0);
		vel++;
	}
}

return vrati;
}
MAT OpadajuciPodnizovi(std::vector<double>vektor){
	MAT vrati;
	std::vector<double>temp;
		vektor.resize(vektor.size()+1);
vektor[vektor.size()-1]=vektor.size();
	for(int i=0;i<vektor.size()-1;i++){
		if(i<vektor.size() && vektor[i]>=vektor[i+1])
		temp.push_back(vektor[i]);
		else if(vektor[i]<vektor[i+1]){
			temp.push_back(vektor[i]);
			if(temp.size()!=0 && temp.size()!=1) vrati.push_back(temp);
			temp.resize(0);
		}
	}
	return vrati;
}
int main(){
	std::cout<<"Unesite broj elemenata vektora: ";
	int broj;
	std::cin>>broj;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double>Vektor(broj);
	for(int i=0;i<broj;i++){
		std::cin>>Vektor[i];
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	MAT prvipoziv;
	prvipoziv=RastuciPodnizovi(Vektor);
	
	for(int i=0;i<prvipoziv.size();i++){
		for(int j=0;j<prvipoziv[i].size();j++){
			std::cout<<prvipoziv[i][j]<<" ";
		
		}
			std::cout<<std::endl;
}
std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
MAT drugipoziv;
drugipoziv=OpadajuciPodnizovi(Vektor);
for(int i=0;i<drugipoziv.size();i++){
	for(int j=0;j<drugipoziv[i].size();j++){
		std::cout<<drugipoziv[i][j]<<" ";
	}
	std::cout<<std::endl;
}
	return 0;
}
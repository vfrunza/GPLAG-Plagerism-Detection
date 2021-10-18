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
#include <cmath>
#define epsilon 0.0000000001
typedef std::vector<std::vector<double>> Matrica;

Matrica OpadajuciPodnizovi(std::vector<double> vektor){
	std::vector<double> novi,prazni;
	Matrica rastuci;
	for(int i=0;i<vektor.size();i++){
		novi=prazni;
		while(i+1<vektor.size() &&( vektor[i]>vektor[i+1] || fabs(vektor[i]-vektor[i+1])<epsilon)){
			novi.push_back(vektor[i]);
			i++;
		}
		if(novi.size()!=0)novi.push_back(vektor[i]);
		if(novi.size()>=2)rastuci.push_back(novi);
	}
	return rastuci;
}
Matrica RastuciPodnizovi(std::vector<double> vektor){
	std::vector<double> novi,prazni;
	Matrica opadajuci;
	for(int i=0;i<vektor.size();i++){
		novi=prazni;
		while(i+1<vektor.size() && (vektor[i]<vektor[i+1] || fabs(vektor[i]-vektor[i+1])<epsilon)){
			novi.push_back(vektor[i]);
			i++;
			//if(i+1<vektor.size() && vektor[i]>vektor[i+1])novi.push_back(vektor[i]);
		}
		if(novi.size()!=0)novi.push_back(vektor[i]);
		if(novi.size()>=2)opadajuci.push_back(novi);
	}
	return opadajuci;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> vektor(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<vektor.size();i++){
		std::cin>>vektor[i];
	}
	Matrica rastuci(RastuciPodnizovi(vektor));
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0;i<rastuci.size();i++){
		for(int j=0;j<rastuci[i].size();j++){
			std::cout<<rastuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	Matrica opadajuci(OpadajuciPodnizovi(vektor));
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0;i<opadajuci.size();i++){
		for(int j=0;j<opadajuci[i].size();j++){
			std::cout<<std::setprecision(12)<<opadajuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}
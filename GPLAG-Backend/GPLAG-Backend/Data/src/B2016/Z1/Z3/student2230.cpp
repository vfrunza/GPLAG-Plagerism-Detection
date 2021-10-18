/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<double> VektorDouble;
typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi (VektorDouble vektor){
	Matrica matrica;

	for(int i(0);i<vektor.size()-1;i++){
		VektorDouble pomocni;
		if(vektor[i+1]>=vektor[i]){
			pomocni.push_back(vektor[i]);
			while(vektor[i+1]>=vektor[i] && i!=vektor.size()-2){
				pomocni.push_back(vektor[i+1]);
				i++;
			}
			i++;
			if(vektor[i]>=pomocni[pomocni.size()-1]) pomocni.push_back(vektor[i]);
			matrica.push_back(pomocni);	
			i--;
		}
	}
	return matrica;
}

Matrica OpadajuciPodnizovi(VektorDouble vektor){
	Matrica matrica;
	
	for(int i(0);i<vektor.size()-1;i++){
		VektorDouble pomocni;
		if(vektor[i+1]<=vektor[i]){
			pomocni.push_back(vektor[i]);
			while(vektor[i+1]<=vektor[i] && i!=vektor.size()-2){
				pomocni.push_back(vektor[i+1]);
				i++;
			}
			i++;
			if(vektor[i]<=pomocni[pomocni.size()-1]) pomocni.push_back(vektor[i]);
			matrica.push_back(pomocni);
			i--;
		}
	}
	return matrica;
}

int main ()
{
	int broj;
	double n;
	VektorDouble vektor;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj;
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0);i<broj;i++){
		std::cin>>n;
		vektor.push_back(n);
	}
	std::cout<<"Maksimalni rastuci podnizovi: ";
	std::cout<<std::endl;
	Matrica matrica1=RastuciPodnizovi(vektor);
	for(int i(0);i<matrica1.size();i++){
		for(int j(0);j<matrica1[i].size();j++){
			std::cout<<matrica1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: ";
	std::cout<<std::endl;
	Matrica matrica2=OpadajuciPodnizovi(vektor);
	for(int i(0);i<matrica2.size();i++){
		for(int j(0);j<matrica2[i].size();j++){
			std::cout<<matrica2[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
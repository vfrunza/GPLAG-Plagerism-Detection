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

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> vektor){
	std::vector<double> pomocni;
	
	int max1 = vektor.at(0);
	for(int i = 0 ; i < vektor.size() ; i++){
		int max2 = vektor.at(i);
		if( max1 > max2){
			max1 = vektor.at(i);
			continue;
		} else if(max1 < vektor.at(i)){
			max1 = vektor.at(i);
			pomocni.push_back(max1);
		}
	}
	
	std::vector<std::vector<double>> rastuca;
	for(int i = 0 ; i < rastuca.size(); i++){
		for(int j = 0 ; j < rastuca.at(i).size(); j++){
			rastuca.push_back(pomocni);
			if (j = rastuca.size() -1) std::cout<<" ";
		}
		
	}
	return rastuca;
}

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> vektor){
	std::vector<std::vector<double>> opadajuca;
	int max = vektor.at(0);
	for(int i = 0 ; i < vektor.size(); i++){
		if (vektor.at(i) < max) max = vektor.at(i);
		for(int j = 0 ; j < opadajuca.size() ; j++){
			for(int k = 0 ; k < opadajuca.at(i).size(); k++){
				opadajuca.at(i).push_back(max);
			}
		}
	}
	return opadajuca;
}

int main(){
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> glavni;
	std::cout<<"Unesite elemente vektora: ";
	for(int i = 0 ; i < n ; i++){
		int x;
		std::cin>>x;
		glavni.push_back(x);
	}
	
	std::vector<std::vector<double>> rastucipodniz(RastuciPodnizovi(glavni));
	std::cout<<"Maksimalni rastuci podnizovi: ";
	if(rastucipodniz.size() == 0 ) std::cout<<std::endl;
	else{
		for(int i = 0 ; i < rastucipodniz.size();i++){
		for(int j = 0 ; j < rastucipodniz.at(i).size(); j++){
			std::cout<<rastucipodniz.at(i).at(j)<<" ";
		}
	
}
	}
	
	std::vector<std::vector<double>> opadajucipodniz(OpadajuciPodnizovi(glavni));
	std::cout<<"\nMaksimalni opadajuci podnizovi: ";
	for(int k = 0 ; k < opadajucipodniz.size(); k++){
		for(int z = 0 ; z < opadajucipodniz.at(k).size(); z++){
			std::cout<<opadajucipodniz.at(k).at(z)<<" ";
		}
	}
		

return 0;
}
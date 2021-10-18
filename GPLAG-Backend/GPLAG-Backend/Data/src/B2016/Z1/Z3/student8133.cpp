#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v) {
	std::vector<std::vector<double>> podnizovi;
	for(int i=1; i<v.size(); i++){
		std::vector<double> temp;
		temp.push_back(v[i-1]);
		while(v[i]>=v[i-1] && i<v.size()) {
			temp.push_back(v[i]);
			i++;
			if(i>=v.size()){
				break;
			}
		}
		if(temp.size()>1) {
			podnizovi.push_back(temp);
			i--;
		}
	}
	return podnizovi;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v) {
	std::vector<std::vector<double>> podnizovi;
	for(int i=1; i<v.size(); i++) {
		std::vector<double> temp;
		temp.push_back(v[i-1]);
		while(v[i]<=v[i-1] && i<v.size()){
			temp.push_back(v[i]);
			i++;
			if(i>=v.size()){
				break;
			}
		}
		if(temp.size()>1){
			podnizovi.push_back(temp);
			i--;
		}
	}
	return podnizovi;
}
int main() {
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double>vek(n);
	for(int i=0; i<n; i++){
		std::cin>>vek[i];
	}
	std::vector<std::vector<double>> R(RastuciPodnizovi(vek)), O(OpadajuciPodnizovi(vek));
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0; i<R.size(); i++){
		for(int j=0; j<R[i].size(); j++) {
			std::cout<<R[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0; i<O.size(); i++){	
		for(int j=0; j<O[i].size(); j++){
			std::cout<<O[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
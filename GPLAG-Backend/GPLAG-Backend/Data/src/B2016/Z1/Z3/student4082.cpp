#include <iostream>
#include <vector>


std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> vec){
	std::vector<std::vector<double>> mat(0);
	std::vector<double> pomocni;
	
	for(int i(1); i < vec.size(); i++){
		if(vec[i-1] > vec[i] && pomocni.size() != 0){
			pomocni.push_back(vec[i-1]);
			mat.resize(mat.size()+1);
			mat.push_back(pomocni);
			pomocni.resize(0);
		}
		if(vec[i-1] <= vec[i]){
			pomocni.push_back(vec[i-1]);
		}
		if(vec[i] >= vec[i-1] && i == vec.size() - 1){
			pomocni.push_back(vec[i]);
			mat.resize(mat.size()+1);
			mat.push_back(pomocni);
			pomocni.resize(0);
		}
	}
	
	return mat;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> vec){
	std::vector<std::vector<double>> mat(0);
	std::vector<double> pomocni;
	
	for(int i(1); i < vec.size(); i++){
		if(vec[i-1] < vec[i] && pomocni.size() != 0){
			pomocni.push_back(vec[i-1]);
			mat.resize(mat.size()+1);
			mat.push_back(pomocni);
			pomocni.resize(0);
		}
		if(vec[i-1] >= vec[i]){
			pomocni.push_back(vec[i-1]);
		}
		if(vec[i] <= vec[i-1] && i == vec.size() - 1){
			pomocni.push_back(vec[i]);
			mat.resize(mat.size()+1);
			mat.push_back(pomocni);
			pomocni.resize(0);
		}
	}
	
	return mat;
}

int main ()
{
	std::vector<std::vector<double>> matA, matB;
	std::vector<double> nizB;
	int n;
	double tmp;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0); i < n; i++){
		std::cin>>tmp;
		nizB.push_back(tmp);
	}
	matA = RastuciPodnizovi(nizB);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i(0); i < matA.size(); i++){
		for(int j(0); j < matA[i].size(); j++){
			std::cout<<matA[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	matB = OpadajuciPodnizovi(nizB);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i(0); i < matB.size(); i++){
		for(int j(0); j < matB[i].size(); j++){
			std::cout<<matB[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	
	
	return 0;
}
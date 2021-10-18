#include <iostream>
#include <vector>

std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double>v){
	std::vector<std::vector<double>> mat;
	if(v.size()==0) return mat;
	std::vector<double>v2;

	for(int i=0; i<v.size(); i++){
	while(i!=v.size()-1 && v[i+1]>=v[i]){
		v2.push_back(v[i]);	
		i++;
	}
	if((i==v.size()-1 && v[i]>=v[i-1]) || (i!=v.size()-1 && i!=0 && v[i]>=v[i-1])){
		v2.push_back(v[i]);	
		mat.push_back(v2);
		v2.resize(0);
	}
	else continue;
	
	}
	return mat;
}

std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double>v){
	std::vector<std::vector<double>> mat;
	if(v.size()==0) return mat;
	std::vector<double>v2;

	for(int i=0; i<v.size(); i++){
	while(i!=v.size()-1 && v[i+1]<=v[i]){
		v2.push_back(v[i]);	
		i++;
	}
	
	if((i==v.size()-1 && v[i]<=v[i-1]) || (i!=v.size()-1 && i!=0 && v[i]<=v[i-1])){
		v2.push_back(v[i]);	
		mat.push_back(v2);
		v2.resize(0);
	}
	
	else continue;
	}
	return mat;
}



int main ()
{
	std::vector<double>v;
	std::vector<double>v4;

	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	double a;
	for(int i=0; i<n; i++){
		std::cin>>a;
		v.push_back(a);
		v4.push_back(a);
	}
	std::cout<<"Maksimalni rastuci podnizovi: ";
	std::cout<<std::endl;
	std::vector<std::vector<double>>v2;
	v2=RastuciPodnizovi(v);
    for(int i=0; i<v2.size(); i++){
		for(int j=0; j<v2.at(i).size(); j++)
	    std::cout<<v2.at(i).at(j)<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: ";
	std::cout<<std::endl;
	v2=OpadajuciPodnizovi(v4);
	for(int i=0; i<v2.size(); i++){
		for(int j=0; j<v2.at(i).size(); j++)
	    std::cout<<v2.at(i).at(j)<<" ";
		std::cout<<std::endl;
	}

	return 0;
}
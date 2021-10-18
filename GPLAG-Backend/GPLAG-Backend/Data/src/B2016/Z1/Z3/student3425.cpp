#include <iostream>
#include <vector>
#define d 0.00001

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> m(1);
	
	int count=0;
	for(int i=0;i<v.size()-1;i++){
		if(i>=v.size()-1 || i+1>=v.size())
		break;
			if(v[i]<=v[i+1]){
			int j=i+1;
		 
			while(v.at(i)<=v.at(j)  ){
				
		m[count].push_back(v[i]);
		i++; j++;
		if(i==v.size()-1 || j==v.size())
				break;
	}
	m[count].push_back(v[i]);
	count ++;
	m.resize(count+1);
			}
		}
	return m;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> m(1);
	int count =0;
	for(int i=0;i<v.size()-1;i++){
		if(i>=v.size()-1)
		break;
		if(v.at(i)>=v.at(i+1)){
			int j=i+1;
			if(j>=v.size())
			break;
			while(v[i]>=v[j] ){
				m[count].push_back(v[i]);
				i++; j++;
				if(i==v.size()-1 || j==v.size())
				break;
			}
			m[count].push_back(v[i]);
				count++;
				m.resize(count+1);
			
		}
	}
	return m;
}
int main(){
	std::vector<std::vector<double>> m,h;
	std::vector<double> v;
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		v.resize(i+1);
	std::cin>> v[i];
	}
	m=RastuciPodnizovi(v);
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size();j++){
			std::cout << m[i][j]<<" ";
		}
		if(i!=m.size()-1)
		std::cout << std::endl;
	}
	h=OpadajuciPodnizovi(v);
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i=0;i<h.size();i++){
		for(int j=0;j<h[i].size();j++){
			std::cout << h[i][j]<<" ";
		}
		std::cout<< std::endl;
	}

	
	return 0;
}
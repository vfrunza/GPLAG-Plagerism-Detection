/B 2016/2017, Zadaća 1, Zadatak 3
#include<iostream>
#include<vector>
std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double>v){
	std::vector<double>temp;
	std::vector<double> rez;
	std::vector<std::vector<double>>a;

		for(int i=0;i<v.size();i++){
			if((i<int(v.size())-1 && v[i]<=v[i+1])||(i>0  && v[i]>=v[i-1])){
				temp.push_back(v[i]);
			}
			if(i<int(v.size())-1 && v[i]>v[i+1]){
				 a.push_back(temp);
				 temp.resize(0);
			}
		}
	a.push_back(temp);
		return a;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double>v){
	std::vector<double>temp;
	std::vector<double> rez;
	std::vector<std::vector<double>>a;

		for(int i=0;i<v.size();i++){
			if((i<int(v.size())-1 && v[i]>=v[i+1])||(i>0  && v[i]<=v[i-1])){
				temp.push_back(v[i]);
			}
			if(i<int(v.size())-1 && v[i]<v[i+1]){
				 a.push_back(temp);
				 temp.resize(0);
			}
		}
	a.push_back(temp);
		return a;
}

int main () {
	std::vector<double>v;
	std::vector<double>rez;
	int n;
	double a;
	std::cout<<"Unesite broj elemenata vektora: "<<std::endl;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	
	for(int i=0;i<n;i++){
		std::cin>>a;
		v.push_back(a);
		
	}
	std::vector<std::vector<double>>r;
	r=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: ";
	for(int i=0;i<r.size();i++){
		for(int j=0;j<r[i].size();j++){
		 std::cout<<r[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::vector<std::vector<double>>s;
	s=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: ";
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s[i].size();j++){
		std::cout<<s[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}
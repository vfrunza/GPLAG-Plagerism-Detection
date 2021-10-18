#include <iostream>
#include <vector>
typedef std::vector <std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica m;
	std::vector<double> vek;
	for(int i(0); i<int(v.size());i++){
		if(i+1 < int(v.size()) && i==0 && v[i]<=v[i+1]){
			vek.push_back(v[i]);
			continue;
		}
		if((i+1)<int(v.size()) && i-1>=0 && ((v[i]>=v[i-1] && v[i]<=v[i+1]) || (v[i]<=v[i-1] && v[i]<=v[i+1]))){
			vek.push_back(v[i]);
			continue;
		}
		if(i-1>=0 && ((i+1<int(v.size()) && v[i]>=v[i-1] && v[i]>=v[i+1]) || (i==int(v.size()-1) && v[i]>=v[i-1]))){
			vek.push_back(v[i]);
			m.push_back(vek);
			vek.resize(0);
			continue;
		}
	}
	return m;
}

Matrica OpadajuciPodnizovi(std::vector<double> v){
	Matrica m;
	std::vector<double> vek;
	for(int i(0); i<int(v.size()); i++){
		if(i+1<int(v.size()) && i==0 && v[i]>=v[i+1]){
			vek.push_back(v[i]);
			continue;
		}
		if(i-1>=0 && i+1< int(v.size()) && ((v[i]<=v[i-1] && v[i]>=v[i+1]) || (v[i]>=v[i-1] && v[i]>=v[i+1]))){
			vek.push_back(v[i]);
			continue;
		}
		if(i-1>=0 && (((i+1)<int(v.size()) && v[i]<=v[i-1] && v[i]<= v[i+1]) || (i==int(v.size()-1) && v[i]<=v[i-1]))){
			vek.push_back(v[i]);
			m.push_back(vek);
			vek.resize(0);
			continue;
			
		}
	}
	return m;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n, i(0);
	std::cin>>n;
	std::vector<double> v(n);
	std::cout << "Unesite elemente vektora: ";
	while(i<n){
		std::cin>>v[i];
		i++;
	}
	std::cout << "Maksimalni rastuci podnizovi: "<< std::endl;
	Matrica M(RastuciPodnizovi(v));
	for(auto x : M){
		for(auto y : x){
			std::cout<< y<< " ";
		}
		std::cout  << std::endl;
	}
	Matrica N(OpadajuciPodnizovi(v));
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(auto x: N){
		for(auto y : x) std::cout << y << " ";
		std::cout << std::endl;
	}
	
	return 0;
}
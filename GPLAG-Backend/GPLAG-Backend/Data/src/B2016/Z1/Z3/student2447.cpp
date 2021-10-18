#include<iostream>
#include<vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double>v){
	
	std::vector<std::vector<double>>matrica;
	
	std::vector<double>v1;
	std::vector<double>v2;
	
	int posljednji_clan=int(v.size())-1;
	
	for(int i=0;i<posljednji_clan;i++){
		if(v[i]<=v[i+1]){
			v1.push_back(v[i]);
		}else if(i!=0 && v[i-1]<=v[i] && v[i+1]<=v[i]){
			v1.push_back(v[i]);
			}
			if(i==posljednji_clan-1 && v[i]<=v[i+1]){
				v1.push_back(v[i+1]);
			}
			if(v1.size()>0 && (i!=0 && v[i-1]<=v[i] && v[i+1]<=v[i] || i==posljednji_clan-1)){
				matrica.push_back(v1);
				v1.resize(0);
			}
		
	}
	return matrica;		
}


std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double>v){
	
	std::vector<std::vector<double>> matrica;
	std::vector<double>v1;
	
	int posljednji_clan=int(v.size()-1);
	
	for(int i=0;i<posljednji_clan;i++){
		if(v[i]>=v[i+1]){
			v1.push_back(v[i]);
		}else if(i!=0 && v[i-1]>=v[i] && v[i+1]>=v[i]){
			v1.push_back(v[i]);
			
		}if(i==posljednji_clan-1 && v[i]>=v[i+1]){
			v1.push_back(v[i+1]);
			
		}
		if(v1.size()>0 && (i!=0 && v[i-1]>=v[i] && v[i+1]>=v[i] || i==posljednji_clan-1)){
			matrica.push_back(v1);
			v1.resize(0);
		}
	}
	
	return matrica;
	
}


int main ()
{
	int n;
	double a;
	std::vector<std::vector<double>> x1,x2;
	
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double>vektor ;
	
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin>>a;
		vektor.push_back(a);
	}
	
	x1=RastuciPodnizovi(vektor);
	x2=OpadajuciPodnizovi(vektor);
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	
	for(int i=0;i<x1.size();i++){
		for(int j=0;j<x1[i].size();j++){
			std::cout<<x1.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	
	
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	
	for(int i=0;i<x2.size();i++){
		for(int j=0;j<x2[i].size();j++){
			std::cout<<x2.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}
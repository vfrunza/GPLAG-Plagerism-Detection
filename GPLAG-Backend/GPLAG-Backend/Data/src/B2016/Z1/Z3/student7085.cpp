#include <iostream>
#include <vector>
#include <iomanip>


typedef std:: vector<std:: vector<double>> matrica;

matrica RastuciPodnizovi(std:: vector<double> v){
	matrica m;
	std:: vector<double> redovi;
	bool ima=1; int nj;
	for(int i=1; i<v.size();i++){
		redovi.resize(0);
		while(v[i-1]<=v[i]){
		if(i==v.size()-1) {redovi.push_back(v[i-1]); ima=0; nj=i; break;}
		redovi.push_back(v[i-1]);
		i++;
		}
		if(ima==0) redovi.push_back(v[nj]);
		else redovi.push_back(v[i-1]);
	    
		if(redovi.size()>1) m.push_back(redovi);
	}
	return m;
}
	
matrica OpadajuciPodnizovi(std:: vector<double> v){
		matrica m;
		bool ima=1; int nj;
	std:: vector<double> redovi;
	for(int i=1; i<v.size();i++){
		redovi.resize(0);
		while(v[i-1]>=v[i]){
			if(i==v.size()-1) {redovi.push_back(v[i-1]); ima=0; nj=i; break;}
		redovi.push_back(v[i-1]);
		i++;
		}
		if(ima==0) redovi.push_back(v[nj]);
		else redovi.push_back(v[i-1]);
		if(redovi.size()>1) m.push_back(redovi);
	}
	return m;
	
}
int main ()
{
	int n;
	double a;
	std:: vector<double> v;
	std:: cout<< "Unesite broj elemenata vektora: ";
	std:: cin>>n;
	std:: cout<< "Unesite elemente vektora: ";
	do{
		std:: cin>>a;
		if(v.size()<n) v.push_back(a);
	}while(v.size()<n);
	std:: cout<< "Maksimalni rastuci podnizovi: "<< std:: endl;
	auto m(RastuciPodnizovi(v));
	for(std:: vector<double> i:m){
		for(double j:i){
			std:: cout<<std::setprecision(12)<< j<<" ";
		} std:: cout<< std:: endl;
	}
	std:: cout<< "Maksimalni opadajuci podnizovi: "<< std:: endl;
	 m=OpadajuciPodnizovi(v);
	 for(std:: vector<double> i:m){
		for(double j:i){
			std:: cout<<std::setprecision(12)<< j<<" ";
		} std:: cout<< std:: endl;
	}
	return 0;
}
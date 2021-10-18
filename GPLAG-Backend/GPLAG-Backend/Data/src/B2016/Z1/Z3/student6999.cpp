#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> matrica;

matrica RastuciPodnizovi(std::vector<double> v){
	matrica izlaz;
	if(v.size() == 0) return izlaz;
	izlaz.resize(1);
	int j(1),i(0);
	for(;;){
		while((v.at(j-1) <= v.at(j))&& ((j) <= (v.size()-1)))
		{
			izlaz.at(i).push_back(v.at(j-1));
			j++;
			if(j >= v.size()) break;
		}
		
		if(izlaz.at(i).size() == 0){
			j++;
			if(j>(v.size()-1)) return izlaz;
			continue;
		}
		if(v.at(j-2) <= v.at(j-1)){
			izlaz.at(i).push_back(v.at(j-1));
			i++;	j++;
			izlaz.resize(i+1);
		}
		if(j >= v.size()) break;
	}
	return izlaz;
}

matrica OpadajuciPodnizovi(std::vector<double> v){
	matrica izlaz;
	if(v.size() == 0) return izlaz;
	izlaz.resize(1);
	int j(1),i(0);
	for(;;){
		while((v.at(j-1) >= v.at(j)) && (j <= (v.size()-1)))
		{
			izlaz.at(i).push_back(v.at(j-1));
			j++;
			if(j >= v.size()) break;
		}	
		if(izlaz.at(i).size()==0){
			j++;
			if(j>(v.size()-1)) return izlaz;
			continue;
		}
		if(v.at(j-2) >= v.at(j-1)){
			izlaz.at(i).push_back(v.at(j-1));
			i++;	j++;
			izlaz.resize(i+1);
		}
		if(j>=v.size()) break;
	
	}

	return izlaz;
}

int main ()
{
	try{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>> n;
	if(n<0) throw "Broj elemenata vektora mora biti nenegativan broj!";
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> v;
for(int i=0; i<n;i++){
		double temp;
		std::cin>> temp;
		v.push_back(temp);
	}
	matrica rastuci;
	matrica opadajuci;
	rastuci = RastuciPodnizovi(v);
	opadajuci = OpadajuciPodnizovi(v);
	int maxravel=0;
	for(int i=0; i<rastuci.size();i++){
		if(rastuci[i].size() > maxravel) maxravel=rastuci[i].size();
	}
	int maxopvel=0;
	for(int i=0;i<opadajuci.size();i++){
		if(opadajuci[i].size() > maxopvel) maxopvel=opadajuci[i].size();
	}
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0;i<rastuci.size();i++){
		if(rastuci[i].size() == maxravel){
			for(int j=0;j<rastuci[i].size();j++){
				std::cout<<std::setprecision(12)<<rastuci[i][j]<<" ";
			}std::cout<<std::endl;
		}
	}
	std::cout<<std::endl;
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0;i<opadajuci.size();i++){
		if(opadajuci[i].size() == maxopvel){
			for(int j=0;j<opadajuci[i].size();j++){
				std::cout<<std::setprecision(12)<<opadajuci[i][j]<<" ";
			}std::cout<<std::endl;
		}
		
	}
	}catch(const char a[]){
		std::cout<<a;
	}
	
	return 0;
}
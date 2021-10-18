/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>



std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> RP;
	std::vector<double> rp;
	for(int i=0; i<v.size(); i++){
		while(i<(v.size()-1) && v[i]<=v[i+1]){
			rp.push_back(v.at(i));
			i++;
		}
		if(i<v.size() && v[i]>=v[i-1] && i!=0){
			rp.push_back(v.at(i));
		}
		if(rp.size()>0){
			RP.push_back(rp);
			rp.resize(0);
		}
		
	}
	
	return RP;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> OP;
	std::vector<double> op;
	for(int i=0; i<v.size(); i++){
		while(i<(v.size()-1) && v[i]>=v[i+1]){
			op.push_back(v.at(i));
			i++;
		}
		if(i<v.size() && i>0 && v[i]<=v[i-1] ){
			op.push_back(v.at(i));
		}
		if(op.size()>0){
			OP.push_back(op);
			op.resize(0);
		}
	}
	
	return OP;	
}

int main ()
{
	int n;
	std::cout<< "Unesite broj elemenata vektora: ";
	std::cin>> n;
	std::vector<double> v;
	std::cout<< "Unesite elemente vektora: ";
	double element;
	for(int i=0; i<n; i++){
		std::cin>> element;
		v.push_back(element);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> RP=RastuciPodnizovi(v);
	for(int i=0; i<RP.size(); i++){
		for(int j=0; j<RP[i].size(); j++){
			std::cout<<std::left<<std::setprecision(12)<<RP[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> OP=OpadajuciPodnizovi(v);
	for(int i=0; i<OP.size(); i++){
		for(int j=0; j<OP[i].size(); j++){
			std::cout<<std::left<<std::setprecision(12)<<OP[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> podnizovi;
	if(v.size()==0 || v.size()==1)
		return podnizovi;
	std::vector<double> pomocni;
	int i;
	for(i=0; i<v.size()-1; i++){
		if(v.at(i)<=v.at(i+1)){
			pomocni.push_back(v.at(i));
		}
		else{
			if(i>0 && v.at(i)>=v.at(i-1))
				pomocni.push_back(v.at(i));
			if(pomocni.size()>1){
				podnizovi.push_back(pomocni);
				pomocni.resize(0);
			}
		}
	}
	if(i==v.size()-1 && v.at(i)>=v.at(i-1))
			pomocni.push_back(v.at(i));
	podnizovi.push_back(pomocni);
	return podnizovi;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> podnizovi;
	if(v.size()==0 || v.size()==1)
		return podnizovi;
		std::vector<double> pomocni;
	int i;
	for(i=0; i<v.size()-1; i++){
		if(v.at(i)>=v.at(i+1)){
			pomocni.push_back(v.at(i));
		}
		else{
			if(i>0 && v.at(i)<=v.at(i-1))
				pomocni.push_back(v.at(i));
			if(pomocni.size()>1){
				podnizovi.push_back(pomocni);
				pomocni.resize(0);
			}
		}
	}
	if(i==v.size()-1 && v.at(i)<=v.at(i-1))
		pomocni.push_back(v.at(i));
	podnizovi.push_back(pomocni);
	return podnizovi;
}

int main (){
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> v;
	double element;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		std::cin>>element;
		v.push_back(element);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> ispis1(RastuciPodnizovi(v));
	for(std::vector<double> i: ispis1){
		for(int j: i){
			std::cout<<j<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> ispis2(OpadajuciPodnizovi(v));
	for(std::vector<double> k: ispis2){
		for(int l: k){
			std::cout<<l<<" ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}
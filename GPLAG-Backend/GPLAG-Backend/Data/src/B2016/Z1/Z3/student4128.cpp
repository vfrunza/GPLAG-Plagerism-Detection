#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> niz;

niz RastuciPodnizovi(std::vector<double> v){
	niz rastuci;
	for(int i=0;i<v.size()-1;i++){
		int duzina_niza(1);
		for(int j=i;j<v.size()-1;j++){
			if(v[j]<=v[j+1]){
				duzina_niza++;
			}
				else break;
			}
			if(duzina_niza!=1){
			std::vector<double> pomocni;
			for(int k=i;k<i+duzina_niza;k++){
			pomocni.push_back(v[k]);
			}
			rastuci.push_back(pomocni);
		}
		i+=(duzina_niza-1);
		}
		return rastuci;
	}

niz OpadajuciPodnizovi(std::vector<double> v){
	niz opadajuci;
	for(int i=0;i<v.size()-1;i++){
		int duzina_niza(1);
		for(int j=i;j<v.size()-1;j++){
			if(v[j]>=v[j+1]){
				duzina_niza++;
			}
				else break;
			}
			if(duzina_niza!=1){
			std::vector<double> pomocni;
			for(int k=i;k<i+duzina_niza;k++){
			pomocni.push_back(v[k]);
			}
			opadajuci.push_back(pomocni);
		}
		i+=(duzina_niza-1);
		}
		return opadajuci;
	}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin>>v[i];
	}
	niz rastuci(RastuciPodnizovi(v));
	niz opadajuci(OpadajuciPodnizovi(v));
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	if(rastuci.size()!=0){
		for(int i=0;i<rastuci.size();i++){
			for(int j=0;j<rastuci[i].size();j++){
				std::cout<<rastuci[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	if(opadajuci.size()!=0){
		for(int i=0;i<opadajuci.size();i++){
			for(int j=0;j<opadajuci[i].size();j++){
				std::cout<<opadajuci[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}
	
	
	
	return 0;
}
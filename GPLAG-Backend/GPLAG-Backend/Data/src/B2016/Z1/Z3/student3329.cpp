/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica vrati;
	int brojac(0); int br_red(0);
	int poc=0; int duzina=v.size();
	for(int i=0; i<duzina-1; i++){
		if(v.at(i)<=v.at(i+1)){
			if(brojac==0) poc=i; brojac++;
		}
		if(brojac>0 && (i==duzina-2 || v.at(i+1)>v.at(i+2))){
			br_red++; vrati.resize(br_red);
			for(int j=poc; j<=poc+brojac; j++){
				vrati.at(br_red-1).push_back(v.at(j));
			}
			brojac=0;
		}
	}
	return vrati;
}

Matrica OpadajuciPodnizovi(std::vector<double> v){
	Matrica vrati;
	int brojac(0); int br_red(0);
	int poc=0; int duzina=v.size();
	for(int i=0; i<duzina-1; i++){
		if(v.at(i)>=v.at(i+1)){
			if(brojac==0) poc=i; brojac++;
		}
		if(brojac>0 && (i==duzina-2 || v.at(i+1)<v.at(i+2))){
			br_red++; vrati.resize(br_red);
			for(int j=poc; j<=poc+brojac; j++){
				vrati.at(br_red-1).push_back(v.at(j));
			}
			brojac=0;
		}
	}
	return vrati;
}

int main (){
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> v; double unos;
	for(int i=0; i<n; i++){
		std::cin>>unos;
		v.push_back(unos);
	}
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	Matrica a=RastuciPodnizovi(v);
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a.at(i).size(); j++){
			std::cout<<a.at(i).at(j)<<" ";
		}
		if(i!=a.size()-1)
		std::cout<<std::endl;
	}
	std::cout<<std::endl<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	Matrica b=OpadajuciPodnizovi(v);
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<b.at(i).size(); j++){
			std::cout<<b.at(i).at(j)<<" ";
		}
		if(i!=b.size()-1)
		std::cout<<std::endl;
	}
	return 0;
}
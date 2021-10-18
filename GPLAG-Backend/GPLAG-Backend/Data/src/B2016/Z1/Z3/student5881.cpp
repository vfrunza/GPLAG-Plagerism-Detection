#include <iomanip>
#include <vector>
#include <iostream>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica m;
	int brojac(1);
	m.resize(brojac);
	bool novi_red(false);
	bool novi_vector(true);
	for(int i=0; i<v.size()-1; i++){
		if(novi_red){ 
			brojac++;
			m.resize(brojac);
			novi_red=false;
			novi_vector=true;
		}
		if(v[i]<=v[i+1]){
			if(novi_vector){
				m[brojac-1].push_back(v[i]);
				novi_vector=false;
			}
			m[brojac-1].push_back(v[i+1]);
			continue;
		}
		else{
			if(m[brojac-1].size()==0) novi_red=false;
			else novi_red=true;
			continue;
		}
	}
	return m;
}

Matrica OpadajuciPodnizovi(std::vector<double> v){
	Matrica m;
	int brojac(1);
	m.resize(brojac);
	bool novi_red(false);
	bool novi_vector(true);
	for(int i=0; i<v.size()-1; i++){
		if(novi_red){
			brojac++;
			m.resize(brojac);
			novi_red=false;
			novi_vector=true;
		}
		if(v[i]>=v[i+1]){
			if(novi_vector){
				m[brojac-1].push_back(v[i]);
				novi_vector=false;
			}
			m[brojac-1].push_back(v[i+1]);
			continue;
		}
		else{
			if(m[brojac-1].size()==0) novi_red=false;
			else novi_red=true;
			continue;
		}
	}
	return m;
}

int main ()
{
	std::vector<double> v;
	int broj_elemenata;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj_elemenata;
	v.resize(broj_elemenata);
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<v.size(); i++) std::cin >> v[i];
	auto rastuci(RastuciPodnizovi(v));
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(int i=0; i<rastuci.size(); i++){
		for(int j=0; j<rastuci[i].size(); j++){
			std::cout << rastuci[i][j] << std::setprecision(12) << " ";
		}
		std::cout << std::endl;
	}
	auto opadajuci(OpadajuciPodnizovi(v));
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i=0; i<opadajuci.size(); i++){
		for(int j=0; j<opadajuci[i].size(); j++){
			std::cout << opadajuci[i][j] << std::setprecision(12) << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
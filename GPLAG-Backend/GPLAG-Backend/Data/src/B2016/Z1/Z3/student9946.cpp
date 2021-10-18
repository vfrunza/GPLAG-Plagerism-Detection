#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef std::vector<std::vector<double>> TipVektorVektora ;



TipVektorVektora RastuciPodnizovi(std::vector<double> realniBrojevi)
{
	std::vector<double> rastuciPodNiz;
	TipVektorVektora rezultatRastucegPodniza;

	for (int i = 0; i <realniBrojevi.size(); i++) {
		if(i==(realniBrojevi.size()-1) && realniBrojevi[realniBrojevi.size()-2]<=realniBrojevi[realniBrojevi.size()-1] ) {
			rastuciPodNiz.push_back(realniBrojevi[i]);
			rezultatRastucegPodniza.push_back(rastuciPodNiz);
			break;
		}
		if(i!=realniBrojevi.size()-1) {
			if(realniBrojevi[i]<=realniBrojevi[i+1]) {
				rastuciPodNiz.push_back(realniBrojevi[i]);
			}
			if(realniBrojevi[i]>realniBrojevi[i+1]&& rastuciPodNiz.size()>=1) {
				rastuciPodNiz.push_back(realniBrojevi[i]);
				rezultatRastucegPodniza.push_back(rastuciPodNiz);
				rastuciPodNiz.clear();
			}
		}
	}
	return rezultatRastucegPodniza;
}
TipVektorVektora OpadajuciPodnizovi(std::vector<double> realniBrojevi)
{
	std::vector<double> opadajuciPodNiz;
	TipVektorVektora rezultatOpadajucegPodniza;

	for (int i = 0; i <realniBrojevi.size(); i++) {
		if(i==(realniBrojevi.size()-1) && realniBrojevi[realniBrojevi.size()-2]>=realniBrojevi[realniBrojevi.size()-1] ) {
			opadajuciPodNiz.push_back(realniBrojevi[i]);
			rezultatOpadajucegPodniza.push_back(opadajuciPodNiz);
			break;
		}
		if(i!=realniBrojevi.size()-1) {
			if(realniBrojevi[i]>=realniBrojevi[i+1]) {
				opadajuciPodNiz.push_back(realniBrojevi[i]);
			}
			if(realniBrojevi[i]<realniBrojevi[i+1]&& opadajuciPodNiz.size()>=1) {
				opadajuciPodNiz.push_back(realniBrojevi[i]);
				rezultatOpadajucegPodniza.push_back(opadajuciPodNiz);
				opadajuciPodNiz.clear();
			}
		}
	}
	return rezultatOpadajucegPodniza;
}


int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int velicinaNiza;
	std::cin>>velicinaNiza;

	std::cout << "Unesite elemente vektora: ";
	std::vector<double> niz;
	for(int i=0; i<velicinaNiza; i++) {
		std::string ulaz;
		std::cin >> ulaz;
		niz.push_back(std::stod(ulaz));

	}


	std::cout << "Maksimalni rastuci podnizovi: "<<std::endl;
	TipVektorVektora rezultat = RastuciPodnizovi(niz);
	for (int i = 0; i < rezultat.size(); i++) {
		for (int j = 0; j < rezultat[i].size(); j++) {
			std::cout << rezultat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: "<<std::endl;
	 rezultat = OpadajuciPodnizovi(niz);
	for (int i = 0; i < rezultat.size(); i++) {
		for (int j = 0; j < rezultat[i].size(); j++) {
			std::cout << rezultat[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
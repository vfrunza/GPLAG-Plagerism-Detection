#include <iostream>
#include <vector>
#include <deque>

typedef std::vector<int> Vektor ;
typedef std::deque<Vektor> Dek ;

enum Smjer {Rastuci=1, Opadajuci=2};

bool DaLiJeStepen(int broj)
{
	if (broj==1) return true;
	while (broj!=1) {
		if (broj%2!=0)
			return false;
		broj/=2;
	}
	return true;
}

Dek MaksimalniPodnizoviStepenaDvojke(Vektor v, Smjer monotonost)
{
	int j(0);
	Dek vrati_dek;
	
	if (monotonost==1) {
		
	for (int i = 0; i < v.size(); i++) {
		Vektor neki_pomocni;
		if (DaLiJeStepen(v.at(i))) {
			neki_pomocni.push_back(v.at(i));
			i++;
		} else continue;

		while (i != v.size() && DaLiJeStepen(v.at(i)) && v.at(i) > v.at(i-1)) {
			neki_pomocni.push_back(v.at(i));
			i++;
		}
		if (neki_pomocni.size()>1) {
			vrati_dek.resize(j+1);
			vrati_dek.at(j) = neki_pomocni;
			j++;
		}
		i--;
	}
}
	if (monotonost==2) {
		
	for (int i = 0; i < v.size(); i++) {
		Vektor neki_pomocni;
		if (DaLiJeStepen(v.at(i))) {
			neki_pomocni.push_back(v.at(i));
			i++;
		} else continue;

		while (i!=v.size() && DaLiJeStepen(v.at(i)) && v.at(i) < v.at(i-1)) {
			neki_pomocni.push_back(v.at(i));
			i++;
		}
		if (neki_pomocni.size()>1) {
			vrati_dek.resize(j+1);
			vrati_dek.at(j) = neki_pomocni;
			j++;
		}
		i--;
	}
}
	return vrati_dek;

}

int main ()
{
	Vektor v1;
	Dek d;
	std::cout << "Unesite broj elemenata vektora: ";
	int broj;
	std::cin >> broj;
	std::cout << "Unesite elemente vektora: ";
	for (int i = 0; i < broj; i++) {
		int pomocni_broj;
		std::cin >> pomocni_broj;
		v1.push_back(pomocni_broj);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	Smjer monotonost;
	int promjenjiva;
	std::cin >> promjenjiva;
	if (promjenjiva==1){
		monotonost=Rastuci;
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	} 
	else if(promjenjiva==2){
	monotonost=Opadajuci;
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	} 
	d=MaksimalniPodnizoviStepenaDvojke(v1, monotonost);
	for (int i = 0; i < d.size(); i++) {
		for (int j = 0; j < d.at(i).size(); j++) {
			std::cout << d.at(i).at(j)<< " ";
		}
		std::cout  << std::endl;
	}
	return 0;
}
/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> vektor){
	int kraj, pocetak;
	std::vector<std::vector<double>> Povratna;
	for(int i = 0; i < vektor.size() - 1; i++){
		pocetak = i;
//		std::cout << "Pocetak: " << pocetak << std::endl;
		for(int k = pocetak; k < vektor.size() - 1; k++)
		if(vektor.at(k) <= vektor.at(k + 1))
			i++;
		else
		break;
		
		kraj = i + 1;
//		std::cout << "Kraj: " << kraj << std::endl;
		
		std::vector<double> tmp;		
		for(int j = pocetak; j < kraj; j++)
			tmp.push_back(vektor.at(j));
		
		if(tmp.size() > 1)
		Povratna.push_back(tmp);
		
	}
	
	return Povratna;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> vektor){
	int kraj, pocetak;
	std::vector<std::vector<double>> Povratna;
	for(int i = 0; i < vektor.size() - 1; i++){
		pocetak = i;
		
		for(int k = pocetak; k < vektor.size() - 1; k++)
		if(vektor.at(k) >= vektor.at(k + 1))
		i++;
		else
		break;
		
		kraj = i + 1;
		
		std::vector<double> tmp;
		for(int j = pocetak; j < kraj; j++)
			tmp.push_back(vektor.at(j));
		
		if(tmp.size() > 1)	
		Povratna.push_back(tmp);
		
	}

	return Povratna;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int broj_elemenata;
	std::cin >> broj_elemenata;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> vektor;
	for(int i = 0; i < broj_elemenata; i++){
		double temp;
		std::cin >> temp;
		vektor.push_back(temp);
	}
	std::vector<std::vector<double>> Test;
	Test = RastuciPodnizovi(vektor);
	std::cout << "Maksimalni rastuci podnizovi: \n";
	for(int i = 0; i < Test.size(); i++){
		for(int j = 0; j < Test.at(i).size(); j++){
			std::cout << Test.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	Test = OpadajuciPodnizovi(vektor);
	std::cout << "Maksimalni opadajuci podnizovi: \n";
	for(int i = 0; i < Test.size(); i++){
		for(int j = 0; j < Test.at(i).size(); j++){
			std::cout << Test.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
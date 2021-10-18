/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> IzdvojiPodniz(int pocetak, int kraj, std::vector<double> niz, std::vector<std::vector<double>> rezultat) {
	std::vector<double> podniz;
	if(pocetak == kraj){
		return rezultat;
	}
	// std::cout <<" Podniz pocinje na " << pocetak << " i zavrsava na" << kraj << std::endl;
	for (int i=pocetak; i<=kraj; i++) {
		podniz.push_back(niz[i]);
	}
	rezultat.push_back(podniz);
	return rezultat;
}
std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> niz){
	std::vector<std::vector<double>> rezultat;
	// rezultat.push_back(niz);
	int velicina_niza = niz.size();
	
	int pocetni_idx = 0;
	for (int i=1; i<velicina_niza; i++) {
		// ako je element nad kojim se nalazimo manji od prethodnog
		if (niz[i] < niz[i-1]) {
			rezultat = IzdvojiPodniz(pocetni_idx, i-1, niz, rezultat);
			pocetni_idx = i;
		}
		//ako je element na kojem se nalazimo zadnji element niza
		if (i == velicina_niza-1) {
			rezultat = IzdvojiPodniz(pocetni_idx, i , niz, rezultat);
		}
	}
	// std::cout << std::endl;
	
	return rezultat;
	
}

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> niz) {
	std::vector<std::vector<double>> rezultat;
	// rezultat.push_back(niz);
	int velicina_niza = niz.size();
	
	int pocetni_idx = 0;
	for (int i=1; i<velicina_niza; i++) {
		//ako je elemnt nad kojim se nalazimo veci od prethodnog
		if (niz[i] > niz[i-1]) {
			rezultat = IzdvojiPodniz(pocetni_idx, i-1, niz, rezultat);
			pocetni_idx = i;
		}
		//ako je elemnt na kojem se nalazimo zadnji element niza
		if (i == velicina_niza-1) {
			rezultat = IzdvojiPodniz(pocetni_idx, i, niz, rezultat);
		}
		
	}
	// std::cout << std::endl;
	return rezultat;
}

int main()
{
	// std::vector<int> brojevi { 1, 3, 2, 6, 7, 9, 10, 4, 3, 1, 7};
	std::vector<double> brojevi2;
	
	int broj_elemenata;
	int element;
	
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj_elemenata;
	std::cout << "Unesite elemente vektora: ";
	for (int i=0; i<broj_elemenata; i++) {
		std::cin >> element;
		brojevi2.push_back(element);
	}
	
	std::cout << "Maksimalni rastuci podnizovi:" << std::endl;
	std::vector<std::vector<double>> rezultat1 = RastuciPodnizovi(brojevi2);
	for (int i=0; i<rezultat1.size(); i++) {
		for (int j=0; j<rezultat1[i].size(); j++) {
			std::cout << rezultat1[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "Maksimalni opadajuci podnizovi:" << std::endl;
	std::vector<std::vector<double> > rezultat2 = OpadajuciPodnizovi(brojevi2);
	for (int i=0; i<rezultat2.size(); i++) {
		for (int j=0; j<rezultat2[i].size(); j++) {
			std::cout << rezultat2[i][j] << " ";
	}
	std::cout << std::endl;
	}
	

}


#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <iomanip>
#include <type_traits>

enum class SmjerKretanja
{
    NaprijedNazad=0, NazadNaprijed=1, GoreDolje=2, DoljeGore=3, LijevoDesno=4, DesnoLijevo=5
};

template <typename Kontejner>
Kontejner PjescaniSat(Kontejner kont, SmjerKretanja smjer)
{
	Kontejner rez;
	if (kont.size()==0 || kont.at(0).size()==0 || kont.at(0).at(0).size()==0)
		return rez;
	for (int i = 0; i < kont.size(); i++) {
		for (int j = 0; j < kont.at(i).size(); j++)
			if (kont.at(i).size()!=kont.at(i).at(j).size() || kont.at(i).size()!=kont.size())
				throw std::domain_error("3D matrica nema oblik kocke");
	}
	for (int i = 0; i < kont.size(); i++)
		if (kont.at(i).size()%2==0)
			throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");


	int ipocetak(0), ikraj(kont.size()), jpocetak(0), jkraj(kont.at(0).size()), kpocetak(0), kkraj(kont.at(0).at(0).size()), idirection(1), jdirection(1), kdirection(1), zamjeni(0);
	if (smjer == SmjerKretanja::DoljeGore) {
		jpocetak=kont.at(0).size()-1;
		jkraj=0;
		jdirection=-1;
	} else if (smjer == SmjerKretanja::DesnoLijevo) {
		jpocetak=kont.at(0).size()-1;
		jkraj=0;
		jdirection=-1;
		zamjeni=1;
	} else if (smjer == SmjerKretanja::LijevoDesno) {
		zamjeni=1;
	} else if (smjer == SmjerKretanja::NaprijedNazad) {
		zamjeni=2;
	} else if (smjer == SmjerKretanja::NazadNaprijed) {
		jpocetak=kont.at(0).size()-1;
		jkraj=0;
		jdirection=-1;
		zamjeni=2;
	}

	for (int i = ipocetak; i != ikraj; i+=idirection) {
		typename std::remove_reference<decltype(kont.at(0))>::type pomocna_matrica;
		int poc(-1);
		bool kontrola(true);
		for (int j = jpocetak; (jdirection==-1 && j != jkraj-1) || (jdirection==1 && j!=jkraj); j+=jdirection) {
			typename std::remove_reference<decltype(kont.at(0).at(0))>::type pomocni_vektor;
			if (j-jdirection==kont.at(0).size()/2 || !kontrola) {
				poc--;
				kontrola=false;
			} else
				poc++;
			for (int k = kpocetak + poc; (kdirection==-1 && k!=kkraj-1-poc) || (kdirection==1 && k!=kkraj-poc); k+=kdirection) {
				if (zamjeni==1)
					pomocni_vektor.push_back(kont.at(i).at(k).at(j));
				else if (zamjeni==2)
					pomocni_vektor.push_back(kont.at(j).at(i).at(k));
				else
					pomocni_vektor.push_back(kont.at(i).at(j).at(k));
			}
			pomocna_matrica.push_back(pomocni_vektor);
		}
		rez.push_back(pomocna_matrica);
	}

	return rez;
}

int main ()
{
	int vel;
	std::cout << "Unesite dimenziju (x/y/z): ";
	do {
		std::cin >> vel;
	} while (vel<0 && std::cout << "Dimenzija nije ispravna, unesite opet: ");
	std::vector<std::deque<std::deque<int>>> matrica;
	matrica.resize(vel);
	for (int i = 0; i < vel; i++) {
		matrica.at(i).resize(vel);
		for (int j = 0; j < vel; j++)
			matrica.at(i).at(j).resize(vel);
	}
	std::cout << "Unesite elemente kontejnera: ";
	for (int i = 0; i < vel; i++) {
		for (int j = 0; j < vel; j++) {
			for (int k = 0; k < vel; k++)
				std::cin >> matrica.at(i).at(j).at(k);
		}
	}
	int smjer;
	std::cout << "Unesite smjer kretanja [0 - 5]: ";
	do {
		std::cin >> smjer;
	} while((smjer<0 || smjer>5) && std::cout << "Smjer nije ispravan, unesite opet: ");
	
	std::vector<std::deque<std::deque<int>>> rez;
	try {
		rez=PjescaniSat(matrica,SmjerKretanja(smjer));
	} catch (const std::exception &error) {
		std::cout << "\nIzuzetak: " << error.what();
		return -1;
	}

	std::cout << "\nPjescani sat unesene matrice je:" << std::endl;
	for (int i = 0; i < rez.size(); i++) {
		int br(0);
		for (int j = 0; j < rez.at(i).size(); j++) {
			if (j==0 || j==rez.at(i).size()-1)
				br=0;
			else if (j<=rez.at(i).size()/2)
				br+=2;
			else
				br-=2;
			for (int k = 0; k < rez.at(i).at(j).size(); k++) {
				if (k==0 && br!=0)
					std::cout << std::setw(2*br+4) << rez.at(i).at(j).at(k);
				else
					std::cout << std::setw(4) << rez.at(i).at(j).at(k);
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}

/*
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
26 27 28 29 30
31 32 33 34 35

-9 -8 -7 -6 -5
-4 -3 -2 -1 17
14 25 28 30 35
19 -8 54 78 65
22 11 72 16 67

89 28 17 56 55
64 93 12 81 17
14 25 28 31 35
19 44 53 72 65
22 18 72 16 69

36 37 38 42 43
39 40 41 44 45
46 47 48 55 56
49 50 51 57 58
52 53 54 59 60

61 62 63 67 68
64 65 66 69 70
71 72 73 80 82
74 75 76 81 83
77 78 79 84 85
*/
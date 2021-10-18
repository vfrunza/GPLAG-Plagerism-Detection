/*B 2017/2018, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include <vector>
#include <deque>

typedef std::deque<std::vector<int>> Deque;

enum Smjer {Rastuci,Opadajuci};

bool DaLiJeStepenDvojke(int n)                   
{
	if(n==1) return true;
	if(n<=0) return false;
	while(n!=1) {
		if(n%2!=0) return false;
		n/=2;
	}

	return true;
}

Deque MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer smjer)
{
	Deque dek;
	int br_vek(0);

	if(smjer==Rastuci) {
		for(int i=0; i<v.size(); i++) {                                                                       
			if(i+1<v.size() && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1)) && v.at(i)<=v.at(i+1)) {
				dek.resize(1+br_vek);
				dek.at(br_vek).push_back(v.at(i));                 //Ako dva susjedna clana ispunjavaju uslove, ubacujemo ih u vektor, pomjeramo "i" 
				dek.at(br_vek).push_back(v.at(i+1));			  //Ulazimo u drugu petlju i izvrsavamo je sve dok su uslovi ispunjeni, ujedno pomjeramo i "i"
				i++;
				for(int j=i+1; j<v.size(); j++) {
					if(DaLiJeStepenDvojke(v.at(j)) && v.at(j-1)<=v.at(j)) {
						dek.at(br_vek).push_back(v.at(j));
						i++;
					} else break;
				}
				br_vek++;
			}
		}
	} else {
		for(int i=0; i<v.size(); i++) {                                                                       
			if(i+1<v.size() && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1)) && v.at(i)>=v.at(i+1)) {
				dek.resize(1+br_vek);
				dek.at(br_vek).push_back(v.at(i));                 
				dek.at(br_vek).push_back(v.at(i+1));			 
				i++;
				for(int j=i+1; j<v.size(); j++) {
					if(DaLiJeStepenDvojke(v.at(j)) && v.at(j-1)>=v.at(j)) {
						dek.at(br_vek).push_back(v.at(j));
						i++;
					} else break;
				}
				br_vek++;
			}
		}
	}

	return dek;
}

int main ()
{
	int broj_el;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj_el;

	std::vector<int> v(broj_el);
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<broj_el; i++) {
		std::cin >> v.at(i);
	}

	int smjer;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> smjer;
	while(smjer!=1 && smjer!=2) {
		std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";   
		std::cin >> smjer;
	}

	if(smjer==1) {                                                                      
		Deque dek=std::move(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
		
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		for(int i=0; i<dek.size(); i++) {
			for(int j=0; j<dek.at(i).size(); j++) {
				std::cout << dek.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	} else {
		Deque dek=std::move(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci));

		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for(int i=0; i<dek.size(); i++) {
			for(int j=0; j<dek.at(i).size(); j++) {
				std::cout << dek.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	}

	return 0;
}

/*/*B 2017/2018, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
/*#include <iostream>
#include <vector>
#include <deque>

typedef std::deque<std::vector<int>> Deque;

enum Smjer {Rastuci=1,Opadajuci};

bool DaLiJeStepenDvojke(int n)                   
{
	if(n==1) return true;
	if(n<=0) return false;
	while(n!=1) {
		if(n%2!=0) return false;
		n/=2;
	}

	return true;
}

Deque MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, int smjer)
{
	Deque dek;
	int br_vek(0);

	if(smjer==1) {
		for(int i=0; i<v.size(); i++) {                                                                       
			if(i+1<v.size() && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1)) && v.at(i)<=v.at(i+1)) {
				dek.resize(1+br_vek);
				dek.at(br_vek).push_back(v.at(i));                 //Ako dva susjedna clana ispunjavaju uslove, ubacujemo ih u vektor, pomjeramo "i" 
				dek.at(br_vek).push_back(v.at(i+1));			  //Ulazimo u drugu petlju i izvrsavamo je sve dok su uslovi ispunjeni, ujedno pomjeramo i "i"
				i++;
				for(int j=i+1; j<v.size(); j++) {
					if(DaLiJeStepenDvojke(v.at(j)) && v.at(j-1)<=v.at(j)) {
						dek.at(br_vek).push_back(v.at(j));
						i++;
					} else break;
				}
				br_vek++;
			}
		}
	} else {
		for(int i=0; i<v.size(); i++) {                                                                       
			if(i+1<v.size() && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1)) && v.at(i)>=v.at(i+1)) {
				dek.resize(1+br_vek);
				dek.at(br_vek).push_back(v.at(i));                 
				dek.at(br_vek).push_back(v.at(i+1));			 
				i++;
				for(int j=i+1; j<v.size(); j++) {
					if(DaLiJeStepenDvojke(v.at(j)) && v.at(j-1)>=v.at(j)) {
						dek.at(br_vek).push_back(v.at(j));
						i++;
					} else break;
				}
				br_vek++;
			}
		}
	}

	return dek;
}

int main ()
{
	int broj_el;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj_el;

	std::vector<int> v(broj_el);
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<broj_el; i++) {
		std::cin >> v.at(i);
	}

	int smjer;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> smjer;
	while(smjer!=1 && smjer!=2) {
		std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";   
		std::cin >> smjer;
	}

	if(smjer==1) {                                                                      
		Deque dek=std::move(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
		
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		for(int i=0; i<dek.size(); i++) {
			for(int j=0; j<dek.at(i).size(); j++) {
				std::cout << dek.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	} else {
		Deque dek=std::move(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci));

		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for(int i=0; i<dek.size(); i++) {
			for(int j=0; j<dek.at(i).size(); j++) {
				std::cout << dek.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	}

	return 0;
}*/
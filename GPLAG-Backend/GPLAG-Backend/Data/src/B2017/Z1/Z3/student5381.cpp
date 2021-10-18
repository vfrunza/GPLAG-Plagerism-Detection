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


bool stepen_dvojke(int a)
{
	if(a<=0) return false;
	if (a & (a-1)) return false; // rezultat operatora "i" po bitima dva cijela broja od cega je jedan stepen dvojke a drugi manji od njega za jedan je nula po bitima
	return true;
}

enum Smjer {Rastuci=1, Opadajuci=0};

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int>brojevi, Smjer s)
{
	std::deque<std::vector<int>> monotoni;
	if(brojevi.size()==0) return monotoni; // u slucaju da je f-ji poslan prazan slijed brojeva, ona vraca prazan dek

	for(int i=0; i<brojevi.size(); i++) {

		std::vector<int> pomocni; // vektor "pomocni" ce sluziti za kreiranje vektora monotonih podnizova koji ce se kasnije naci u finalnom deku

		if(stepen_dvojke(brojevi.at(i))) {

			pomocni.push_back(brojevi.at(i));

			while(i<brojevi.size() && stepen_dvojke(brojevi.at(i))) {

				i++;
				if(i==brojevi.size() || !stepen_dvojke(brojevi.at(i))) break;

				if(s==Opadajuci && stepen_dvojke(brojevi.at(i)) && brojevi.at(i)<brojevi.at(i-1))
					pomocni.push_back(brojevi.at(i));

				else if (s==Rastuci && stepen_dvojke(brojevi.at(i)) && brojevi.at(i)>brojevi.at(i-1))
					pomocni.push_back(brojevi.at(i));
				else {
					i--; // ukoliko nisu ispunjeni uslovi za nastavak razmatranog niza prekinuti dodavanje u njega, ali prethodno vratiti indeks nazad za jedan
					break; // jer vec razmotreni broj moze takodjer biti stepen dvojke ali ne ispunjavati ostale navedene uslove
				}
			}
		}
		if(pomocni.size()>1) monotoni.push_back(pomocni); // vektor mora imati najmanje dva elementa da bi bio podniz

		if(i==brojevi.size()) break;
	}

	return monotoni;
	// u slucaju da niz ne sadrzi nijedan trazeni montoni podniz, u deku "montoni" se nece nalaziti nijedan vektor, tj f-ja ce vratiti prazan dek
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;

	std::vector<int>v(n);

	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin >> v.at(i);
	}

	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int monotoni;
	std::cin >> monotoni;
	Smjer smjer;
	if(monotoni==1) smjer=Rastuci;
	else smjer=Opadajuci;

	std::deque<std::vector<int>> trazeni_dek(MaksimalniPodnizoviStepenaDvojke(v, smjer));
	if(smjer==Opadajuci) std::cout << "Maksimalni opadajuci podnizovi: "<<std::endl;
	else std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(int i=0; i<trazeni_dek.size(); i++) {
		{
			for(int j=0; j<trazeni_dek.at(i).size(); j++) if(j<trazeni_dek.at(i).size()) std::cout << trazeni_dek.at(i).at(j)<<" ";
				else std::cout << trazeni_dek.at(i).at(j) << std::endl;

		}
		std::cout << std::endl;
	}
	return 0;
}
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
#include <deque>
#include <cmath>

enum Smjer {Rastuci=1, Opadajuci=2} smjer;

int stepenDvojke (int broj)
{

	if(broj>0)
		broj=broj/2;

	return broj;
}

std:: deque<int> MaksimalniPodnizoviStepenaDvojke (std:: deque<int> VektorCijelih,  enum Smjer)
{

	for(int i(0); i<VektorCijelih.size(); i++) {
		if(stepenDvojke(i)) {
			while (VektorCijelih.at(i)<VektorCijelih.at(i+1)) {
				for(int i(0); i<VektorCijelih.size(); i++ ) {
                    if(i>VektorCijelih.size()) break;
					VektorCijelih.push_back(i);
				}

			}
			std:: cout << VektorCijelih.at(i);
			
			if(VektorCijelih.at(i)>VektorCijelih.at(i+1)) {

				do {
					for(int i(0); i<VektorCijelih.size(); i++) {


						VektorCijelih.push_back(i);
					}
				} while(smjer!=2);
			}
		}
	}
	return VektorCijelih;
}

int main ()
{
	//enum Smjer {Rastuci=1, Opadajuci=2} smjer;
	int n, broj;
	std:: deque<int> v;

	std:: cout << "Unesite broj elemenata vektora: ";
	std:: cin >> n;
	std:: cout << "Unesite elemente vektora: ";
	for(int i(0); i<n; i++) {
		std:: cin >> broj;
		v.push_back(broj);
	}
	//std:: cout << "Unesite:  1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";

	//	std:: cin >> broj;


	std:: deque<int> maxPodniz=MaksimalniPodnizoviStepenaDvojke(v, smjer);

	for(int i(0); i<n; i++) {
		std:: cout << maxPodniz.at(i);
	}
	return 0;
}
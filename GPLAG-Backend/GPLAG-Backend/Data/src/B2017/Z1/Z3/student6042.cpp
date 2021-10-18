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
#include <cmath>
#include <deque>

enum Smjer {Rastuci=1, Opadajuci=2};


bool DaLiJeStepen2(int broj)
{
	bool logicka(false);
	int i;
	for(i=1; i<=broj; i*=2) {
		if(i==broj) {
			logicka=true;
		}
	}
	return logicka;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s)
{

	std::deque<std::vector<int>> b;
	if(s==Rastuci) {
		int i;
		for(i=0; i<v.size(); i++) {                           //uzima elemente iz vektora
			std::vector<int> a;
			bool l(DaLiJeStepen2(v.at(i)));                       //provjerava da li je taj element stepen 2
			if(l==true) {                                          //ako jeste, ubacuje taj element u vektor a
				a.push_back(v.at(i));
				for(int j=i+1; j<v.size(); j++) {                     //ide od sljedbenika tog elementa u vektoru
					i++;                                           
					if(v.at(j)>v.at(j-1)) {                             //ako je taj sljedbenik veci od svog prethodnika
						bool lo=DaLiJeStepen2(v.at(j));                 //provjerava da li je on stepen 2
						if(lo==false) {                                 //ako nije, prekida petlju, tj. ne provjerava dalje
							break;
						} else {
							a.push_back(v.at(j));                     //ako jest stepen, ubacuje taj broj u vektor
						}
					} else {                                         // ako broj nije veci od svog prethodnika, prekida petlju
						break;
					}
				}
				if(a.size()>=2) {
					b.push_back(a);
					i--;

				}
			}
		}
	} else if(s==Opadajuci) {                        //trazenje opadajucih podnizova
		int m, n;
		for(m=0; m<v.size(); m++) {
			std::vector<int> a;
			bool l(DaLiJeStepen2(v.at(m)));
			if(l==true) {
				a.push_back(v.at(m));
				for(n=m+1; n<v.size(); n++) {
					if(v.at(n)<v.at(n-1)) {
						bool logic=DaLiJeStepen2(v.at(n));
						if(logic==false) {
							break;
						} else {
							a.push_back(v.at(n));
						}
					} else {
						break;
					}
				}
				m=n-1;
				if(a.size()>=2) {
					b.push_back(a);
				}
			}
		}
	}


	return b;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";

	std::vector<int> k;
	for(int i=0; i<n; i++) {
		int unos;
		std::cin>>unos;
		k.push_back(unos);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove:";
	int m;
	std::cin>>m;
	if(m==1) {
		std::deque<std::vector<int>> c(MaksimalniPodnizoviStepenaDvojke(k, Rastuci));
		std::cout<<" Maksimalni rastuci podnizovi: "<<std::endl;
		for(std::vector<int> red: c) {

			for(int x: red) {
				std::cout<<x<<" ";
			}
			std::cout<<std::endl;
		}
	}


	else if(m==2) {
		std::deque<std::vector<int>> s(MaksimalniPodnizoviStepenaDvojke(k, Opadajuci));
		std::cout<<" Maksimalni opadajuci podnizovi: "<<std::endl;
		for(std::vector<int> red: s) {
			for(int y: red) {
				std::cout<<y<<" ";
			}
			std::cout<<std::endl;

		}
	}
	return 0;
}
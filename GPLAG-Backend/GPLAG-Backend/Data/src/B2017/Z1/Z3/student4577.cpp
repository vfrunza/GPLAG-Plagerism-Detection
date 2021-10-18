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
#include <vector>
#include <cmath>
typedef std::deque<std::vector<int>> TrazenaKonstrukcija;


enum Smjer{Rastuci=1,Opadajuci=2};



bool DNN(int n)
{
	//U ovoj funkciji provjeravamo da li je odredjeni element vektora stepen dvojke.

	if(n<=0) return false;
	if(log2(n)==int(log2(n))) return true;
	return false;
}

TrazenaKonstrukcija MaksimalniPodnizoviStepenaDvojke(std::vector <int> v,Smjer smjer)
{

	TrazenaKonstrukcija Trazeni;
	int NoviRed=0;

	if(smjer==1) {
		for(int i=0; i<v.size(); i++) {
			if(DNN(v.at(i))) {
				NoviRed++;
				Trazeni.resize(NoviRed);
				Trazeni.at(NoviRed-1).push_back(v.at(i));
				int j;
				for(j=i+1; j<v.size(); j++) {
					if(DNN(v.at(j)) && v.at(j)>=v.at(j-1)) Trazeni.at(NoviRed-1).push_back(v.at(j));
					else break;
				}
				i=j-1;
				if(Trazeni.at(NoviRed-1).size()==1) {
					NoviRed--;
					Trazeni.resize(NoviRed);
				}
			}
		}
		return Trazeni;
	}

	if(smjer==2) {
		for(int i=0; i<v.size(); i++) {
			if(DNN(v.at(i))) {
				NoviRed++;
				Trazeni.resize(NoviRed);
				Trazeni.at(NoviRed-1).push_back(v.at(i));
				int j;
				for(j=i+1; j<v.size(); j++) {
					if(DNN(v.at(j)) && v.at(j)<=v.at(j-1)) Trazeni.at(NoviRed-1).push_back(v.at(j));
					else break;
				}
				i=j-1;
				if(Trazeni.at(NoviRed-1).size()==1) {
					NoviRed--;
					Trazeni.resize(NoviRed);
				}
			}
		}
		return Trazeni;
	}

}









int main ()
{

	//Unos broja elemenata, samih elemenata vektora i unos smjera podnizova.

	std::cout<<"Unesite broj elemenata vektora: ";
	int br_elemenata;
	std::cin>>br_elemenata;

	std::vector <int> Unos(br_elemenata);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<Unos.size(); i++) std::cin>>Unos.at(i);

	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int smjer_podnizova;
	std::cin>>smjer_podnizova;

	//U funkciju MaksimalniPodnizoviStepenaDvojke saljemo uneseni vektor i smjer podnizova, a za rezultat dobijamo dek vektora ciji redovi predstavljaju maksimalne (odnosno minimalne) podnizove stepena dvojke.

    TrazenaKonstrukcija REZULTAT;

	if(smjer_podnizova==1) REZULTAT=MaksimalniPodnizoviStepenaDvojke(Unos,Smjer(Rastuci));
	else if(smjer_podnizova==2) REZULTAT=MaksimalniPodnizoviStepenaDvojke(Unos,Smjer(Opadajuci));

	if(smjer_podnizova==1) {
		std::cout<<"Maksimalni rastuci podnizovi: ";
		std::cout<<std::endl;
		for(int i=0; i<REZULTAT.size(); i++) {
			for(int j=0; j<REZULTAT.at(i).size(); j++) std::cout<<REZULTAT.at(i).at(j)<<" ";
			std::cout<<std::endl;
		}
	}

	if(smjer_podnizova==2) {
		std::cout<<"Maksimalni opadajuci podnizovi: ";
		std::cout<<std::endl;
		for(int i=0; i<REZULTAT.size(); i++) {
			for(int j=0; j<REZULTAT.at(i).size(); j++) std::cout<<REZULTAT.at(i).at(j)<<" ";
			std::cout<<std::endl;
		}
	}

	return 0;
}
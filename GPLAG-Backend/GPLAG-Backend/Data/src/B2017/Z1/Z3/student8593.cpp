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
#include<deque>
#include<vector>

bool DaLiJeStepenDvojke(int broj)
{
	int stepen(1);
	while(stepen<=broj) {
		if(stepen==broj)  return true;
		stepen*=2;
	}
	return false;

}
enum Smjer {Rastuci,Opadajuci};
std::deque<std::vector<int>>MaksimalniPodnizoviStepenaDvojke(std::vector<int>vektor,Smjer,Smjer )
{
	std::deque<std::vector<int>>rezultat;
	for(int i(0); i<vektor.size(); i++) {
		std::vector<int>pomocni;
		if(vektor.at(i)<vektor.at(i+1))
			pomocni.push_back(vektor.at(i));
		while((i<vektor.size()-1)&& vektor.at(i)<=vektor.at(i+1)) {
			pomocni.push_back(vektor.at(i+1));
			i++;

		}




		int BrojStepenaDvojke(0);
		for(int j(0); j<pomocni.size(); j++) {
			if(DaLiJeStepenDvojke(pomocni.at(j))==true)
				BrojStepenaDvojke++;


			else {
				break;
			}
		}

		if(BrojStepenaDvojke>1) {
			pomocni.resize(BrojStepenaDvojke);
			rezultat.push_back(pomocni);
		}
	}
	return rezultat;
}
int main ()
{

	std::deque<std::vector<int>>e;
	int a,n,elementi;

	std::vector<int>vektor;

	Smjer smjer = static_cast<Smjer>(a);
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;

	std::cout<<"Unesite elemente vektora: ";


	for(int i(0); i<n; i++) {
		std::cin>>elementi;
		vektor.push_back(elementi);
	}


	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>a;
	e=MaksimalniPodnizoviStepenaDvojke(vektor,smjer,smjer);
	if(a==1) {
		std::cout<<"Maksimalni rastuci podnizovi: ";
		for(int i(0); i<e.size(); i++) {
			for(int j(0); j<e.at(i).size(); j++)
				std::cout<<e.at(i).at(j)<<" ";
			std::cout<<std::endl;
		}
	}

	if(a==2) {
		std::cout<<"Maksimalni opadajuci podnizovi: ";
		for(int i(0); i<e.size(); i++) {
			for(int j(0); j<e.at(i).size(); j++)
				std::cout<<e.at(i).at(j)<<" ";
			std::cout<<std::endl;
			std::cout<<" ";
		}
	}
	std::cout<<std::endl;



	return 0;
}
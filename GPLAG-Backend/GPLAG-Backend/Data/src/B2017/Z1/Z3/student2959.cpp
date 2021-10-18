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
#include <cmath>

enum Smjer {Opadajuci, Rastuci};

bool StepenDvojke(int broj)
{
	const double Eps(1e-10);
	for(int i=0; i<=broj; i++) {
		if(pow(2,i)>broj) break;
		if(std::fabs(broj-pow(2,i))<=Eps*(std::fabs(broj)+std::fabs(pow(2,i)))) 
			return true;
	}
	return false;
}

bool Operacija(Smjer s, int a, int b)
{
	if(s==Rastuci && a<=b) return true;
	else if(s==Rastuci) return false;
	if(s==Opadajuci && a>=b) return true;
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s)
{
	std::deque<std::vector<int>> d;
	if(v.size()==0) return d;
	int brojac(0);
	for(int i=0; i<v.size()-1; i++) {
		if(StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1)) && Operacija(s,v.at(i),v.at(i+1))) {
			d.push_back(std::vector<int>(1,v.at(i)));
			int j;
			for(j=i+1; j<v.size(); j++) {
				if(!(StepenDvojke(v.at(j))) || !(Operacija(s,v.at(j-1),v.at(j)))) {
					brojac++;
					break;
				} else
					d.at(brojac).push_back(v.at(j));
			}
			i=j-1;
		}
	}
	return d;
}


int main ()
{
	int vel;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>vel;
	std::vector<int> v(vel);
	std::cout<<"Unesite elemente vektora: ";
	for (int i=0; i<vel; i++)
		std::cin>>v.at(i);
	int c;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>c;
	Smjer s;
	if(c==1) s=Rastuci;
	else s=Opadajuci;
	std::deque<std::vector<int>> d=MaksimalniPodnizoviStepenaDvojke(v,s);
	if(c==1) std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	else std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0; i<d.size(); i++) {
		for(int j=0; j<d.at(i).size(); j++) {
			std::cout<<d.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}


	return 0;
}
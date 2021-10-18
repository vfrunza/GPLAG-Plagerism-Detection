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
#include <iomanip>
typedef std::vector<int> Intvektor;
typedef std::deque<std::vector<int>> Intdek;
enum Smjer {Rastuci=1,Opadajuci=2};
bool StepenDvojke(int x)
{
	if(x<=0)
		return false;
	while(x!=1) {
		if(x%2==1) return false;
		x=x/2;
	}
	return true;
}
Intdek MaksimalniPodnizoviStepenaDvojke(Intvektor v,enum Smjer s)
{
	int br(0);
	Intdek d(0);
	if(v.size()==0) return d;//za slucaj da je vektor v prazan,mada je vjerovatno ovaj uslov pokupljen na kraju
	for(int i=0; i<v.size(); i++) {
		if(s==1) {
			if(StepenDvojke(v.at(i))) {
				int k(i);
				while(k+1<v.size() && StepenDvojke(v.at(k+1)) && v.at(k+1)>=v.at(k)) k++;//dodala sam i znak jednakosti
				if(k!=i) { //znaci da je nasao bar dva susjedna koja zadovoljavaju gornji uslov
					br++;
					d.resize(br);//nasli smo bar dva elementa koja mozemo ubacit u jedan red deka pa je potrebno prosirit matricu
					for(int t=i; t<=k; t++) {
						d.at(br-1).push_back(v.at(t));
					}
					i=k;//da u narednom koraku kad poveca i ne razmatra ponovo elemente koje smo ubacili nego da nastavi dalje od zadnjeg koji je zadovoljio uslov

				}

			}
		} else if(s==2) {
			if(StepenDvojke(v.at(i))) {
				int k(i);
				while(k+1<v.size() && StepenDvojke(v.at(k+1)) && v.at(k+1)<=v.at(k)) k++;//naknadno dodala znak "="
				if(k!=i) { //znaci da je nasao bar dva susjedna koja zadovoljavaju gornji uslov
					br++;
					d.resize(br);//nasli smo bar dva elementa koja mozemo ubacit u jedan red deka pa je potrebno prosirit matricu
					for(int t=i; t<=k; t++) {
						d.at(br-1).push_back(v.at(t));
					}

				}
				i=k;//da ne prolazi i opet kroz elemente koje smo vec ubacili
			}

		}
	}

	return d;
}


int main ()
{

	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	Intvektor v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin>>v.at(i);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int p;
	std::cin>>p;
	Smjer s;
	s=Smjer(p);
	Intdek d(MaksimalniPodnizoviStepenaDvojke(v,s));
	if(p==1 && d.size()>0) std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	
	else if(p==2 && d.size()>0) std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0; i<d.size(); i++) {
		for(int j=0; j<d.at(i).size(); j++)
			std::cout<<d.at(i).at(j)<< " ";
		std::cout<<std::endl;
	}

	return 0;
}
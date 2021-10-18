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
#include <iomanip>
enum Smjer {Opadajuci,Rastuci};
typedef std::vector<int> Vektor ;
typedef std::deque<std::vector<int>> DekV;
bool StepenDvojke(int broj)
{
	if(broj<=0) return false;
	while(broj!=0) {
		if(broj%2==1 && broj!=1) return false;
		broj/=2;
	}
	return true;
}
DekV MaksimalniPodnizoviStepenaDvojke( Vektor brojevi,bool istina)
{
		DekV M;
	Vektor V;
	for(int i(0); i<brojevi.size(); i++) {
		if(StepenDvojke(brojevi.at(i))) {
			// U Slucaju Rastucih
			if(istina) {
				if(i>0 &&(V.size())!=0 ) {
					if(brojevi.at(i)>=brojevi.at(i-1) ) V.push_back(brojevi.at(i));
					else if(V.size()<2) {
						V.resize(0);
					} else {
						M.push_back(V);
						V.resize(0);
					}
					if(V.size()==0) V.push_back(brojevi.at(i));
				} else V.push_back(brojevi.at(i));
			}
			//U slucaju Opadajucih
			else {
				if(i>0 && (V.size())!=0) {
					if(brojevi.at(i)<=brojevi.at(i-1)) V.push_back(brojevi.at(i));
					else if(V.size()<2) {
						V.resize(0);
					} else {
						M.push_back(V);
						V.resize(0);
					}
					if(V.size()==0) V.push_back(brojevi.at(i));
				} else V.push_back(brojevi.at(i));
			}
		} else {
			if(V.size()<2) V.resize(0);
			M.push_back(V);
			V.resize(0);
		}
	}
	if(V.size()<2) {
		V.resize(0);
	}
	M.push_back(V);
	return M;
}
DekV MaksimalniPodnizoviStepenaDvojke( Vektor brojevi,Smjer zadani)
{
	DekV M;
	Vektor V;
	for(int i(0); i<brojevi.size(); i++) {
		if(StepenDvojke(brojevi.at(i))) {
			// U Slucaju Rastucih
			if(zadani) {
				if(i>0 &&(V.size())!=0) {
					if(brojevi.at(i)>=brojevi.at(i-1)) V.push_back(brojevi.at(i));
					else if(V.size()<2) {
						V.resize(0);
					} else {
						M.push_back(V);
						V.resize(0);
					}
					if(V.size()==0) V.push_back(brojevi.at(i));
				} else V.push_back(brojevi.at(i));
			}
			//U slucaju Opadajucih
			else {
				if(i>0 && (V.size())!=0) {
					if(brojevi.at(i)<=brojevi.at(i-1)) V.push_back(brojevi.at(i));
					else if(V.size()<2) {
						V.resize(0);
					} else {
						M.push_back(V);
						V.resize(0);
					}
					if(V.size()==0) V.push_back(brojevi.at(i));
				} else V.push_back(brojevi.at(i));
			}
		} else {
			if(V.size()<2) V.resize(0);
			M.push_back(V);
			V.resize(0);
		}
	}
	if(V.size()<2) {
		V.resize(0);
	}
	M.push_back(V);
	return M;
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	Vektor v;
	for(int i=0; i<n; i++) {
		int unos;
		std::cin>>unos;
		v.push_back(unos);
	}
	int a;
	do{
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>a;
	}while(a!=1 && a!=2);
	if(a==1) {
		DekV A(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
		std::cout <<"Maksimalni rastuci podnizovi: "<< std::endl;
		for(auto v: A) {
			for(int x: v) {
				std::cout<<x<<" ";
			}
			std::cout<<std::endl;
		}
	}
	if(a==2) {
		DekV A(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci));
		std::cout <<"Maksimalni opadajuci podnizovi: "<< std::endl;
		for(auto v: A) {
			for(int x: v) {
				std::cout<<x<<" ";
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}
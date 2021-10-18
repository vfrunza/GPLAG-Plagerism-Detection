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
typedef std::vector<int> vektor;
enum Smjer { Rastuci, Opadajuci };
bool StepenDvojke(int x)
{
	if(x==1) return true;
	if(x<=0 || x%2!=0) return false;

	bool k(true);
	for(;;) {

		if(x%2!=0) {
			k=false;
			break;
		}
		x=x/2;
		if(x==1) break;
	}
	return k;
}


std::deque<vektor> MaksimalniPodnizoviStepenaDvojke(vektor v, Smjer koji)
{
	std::deque<vektor> d;
	vektor p;
	if(koji==Rastuci) {
		for(int i=0 ; i<v.size()-1 ; i++) {
			if(v.at(i)<v.at(i+1) && StepenDvojke(v.at(i))==true) p.push_back(v.at(i));
			if(v.at(i)>=v.at(i+1) && StepenDvojke(v.at(i))==true) p.push_back(v.at(i));
			if(i==v.size()-2 && v.at(i)<v.at(i+1) && StepenDvojke(v.at(i))==true && StepenDvojke(v.at(i+1))==true ) {
				p.push_back(v.at(i+1));
				d.push_back(p);
				p.resize(0);
			}
			if(i==v.size()-2 && v.at(i)<v.at(i+1) && StepenDvojke(v.at(i+1))==false ) {
				if(p.size()>1) d.push_back(p);
			}
			if(!(v.at(i)<v.at(i+1) && StepenDvojke(v.at(i))==true) && p.size()>1) {

				d.push_back(p);
				p.resize(0);
			}
			if(!(v.at(i)<v.at(i+1) && StepenDvojke(v.at(i))==true) && p.size()<2) p.resize(0);
		}
	}

	else if(koji==Opadajuci) {
		for(int i=0 ; i<v.size()-1 ; i++) {
			if(v.at(i)>v.at(i+1) && StepenDvojke(v.at(i))==true) p.push_back(v.at(i));
			if(v.at(i)<=v.at(i+1) && StepenDvojke(v.at(i))==true) p.push_back(v.at(i));
			if(i==v.size()-2 && v.at(i)>v.at(i+1) && StepenDvojke(v.at(i))==true && StepenDvojke(v.at(i+1))==true ) {
				p.push_back(v.at(i+1));
				d.push_back(p);
				p.resize(0);
			}
			if(i==v.size()-2 && v.at(i)>v.at(i+1) && StepenDvojke(v.at(i+1))==false ) {
				if(p.size()>1) d.push_back(p);
			}
			if(!(v.at(i)>v.at(i+1) && StepenDvojke(v.at(i))==true) && p.size()>1) {
				d.push_back(p);
				p.resize(0);
			}
			if(!(v.at(i)>v.at(i+1) && StepenDvojke(v.at(i))==true) && p.size()<2) p.resize(0);
		}
	}

	return d;
}

int main ()
{

	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	vektor v;
	for( int i = 0 ; i<n ; i++) {
		int x;
		std::cin>>x;
		v.push_back(x);
	}
	int k;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>k;
	if(k==1) {
		std::deque<vektor> d(MaksimalniPodnizoviStepenaDvojke(v,Rastuci)) ;
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		for(int i=0 ; i<d.size() ; i++) {
			for(int j=0 ; j<d.at(i).size() ; j++)
				std::cout<<d.at(i).at(j)<<" ";
			std::cout<<std::endl;
		}

	}

	if(k==2) {
		std::deque<vektor> d(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci)) ;
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		for(int i=0 ; i<d.size() ; i++) {
			for(int j=0 ; j<d.at(i).size() ; j++)
				std::cout<<d.at(i).at(j)<<" ";
			std::cout<<std::endl;
		}

	}

	return 0;
}
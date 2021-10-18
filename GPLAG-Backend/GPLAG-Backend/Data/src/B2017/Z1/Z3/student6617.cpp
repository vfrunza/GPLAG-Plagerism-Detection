#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <cmath>

typedef std::vector<int> vektor;
typedef std::deque<std::vector<int>> dek;
enum Smjer{Rastuci=1, Opadajuci=2};

bool Jelistepen2(int n) {
	long int granica(std::numeric_limits<long>::max());
	if(n%2!=0 || n<=0) return false;
	if(n==1) return true;
	for(long int i=0; i<granica; i++) {
		if(n==static_cast<long int>(pow(2, i))) return true;
		if(n<int(pow(2, i))) return false;
	}
	return false;
}

dek MaksimalniPodnizoviStepenaDvojke(vektor v, Smjer s)
{
	dek d(1);
	int brojac(1), init(0), opc(s);
	for(int i=0; i<v.size(); i++) {
		brojac=1;
		if(Jelistepen2(v.at(i))) {
			int j(i+1);
			for(j=i+1; j<v.size(); j++) {
				if(Jelistepen2(v.at(j))) {
					if(opc==1) {
						if(v.at(j)>=v.at(j-1)) {
							brojac++;
							if(brojac==2) {
								d.at(init).push_back(v.at(j-1));
								d.at(init).push_back(v.at(j));
							} else {
								d.at(init).push_back(v.at(j));
							}
						} else break;
					}
					else {
						if(v.at(j)<=v.at(j-1)) {
							brojac++;
							if(brojac==2) {
								d.at(init).push_back(v.at(j-1));
								d.at(init).push_back(v.at(j));
							} else {
								d.at(init).push_back(v.at(j));
							}
						} else break;
					}
				}
			}
			i=j-1;
			init++;
			d.resize(init+1);
		}
	}
	return d;
}


int main ()
{
	int br_elemenata;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>br_elemenata;
	vektor vekt;
	int n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<br_elemenata; i++) {
		std::cin>>n;
		vekt.push_back(n);
	}
	int opcija;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>opcija;
	Smjer sm;
	if(opcija==1) sm=Rastuci;
	else sm=Opadajuci;
	dek p(MaksimalniPodnizoviStepenaDvojke(vekt,sm));
	if(opcija==1) std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	else std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0; i<p.size(); i++) {
		for(int j=0; j<p.at(i).size(); j++) {
			std::cout<<p.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
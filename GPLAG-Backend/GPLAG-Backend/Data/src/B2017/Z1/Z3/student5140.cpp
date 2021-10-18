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
#include <cstdbool>
#include <deque>

typedef std::deque<std::vector<int>> dekVektora;
enum Smjer {Rastuci=1, Opadajuci=2};

bool JeLiStepenDvojke(int n)
{
	bool stepenDvojke=false;
	if(n==1) return true;
	while(n>1) {
		if(n%2==0)
			stepenDvojke=true;
		else {
			stepenDvojke=false;
			break;
		}
		n/=2;
	}
	if(stepenDvojke) return true;
	return false;
}

dekVektora MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer odabir)
{
	dekVektora dek;
	
	if(odabir==Rastuci) {
		int max(0);
		int brojac(0);
		bool prvi(true);
		dek.push_back(std::vector<int> (0));
		for(int i=0; i<dek.size(); i++) {
			max=0;
			int brojacJot(0);
			for(int j=brojac; j<v.size(); j++) {
				brojac++;
				if(JeLiStepenDvojke(v.at(j))) {
					if(v.at(j)>=max) {
						if(brojacJot==0 && !prvi) dek.push_back(std::vector<int> (0));
						prvi=false;
						dek.at(i).push_back(v.at(j));
						max=v.at(j);
						brojacJot++;
					} else {
						if(brojacJot==1) dek.erase(dek.begin()+i);
						else dek.push_back(std::vector<int> (0));
						if(dek.size()!=0) i++;
						j--;
						brojacJot=0;
						max=0;
					}
				}
				else {dek.push_back(std::vector<int> (0));
					i++;
					brojacJot=0;
				}
			}
		}
	}

	std::vector<int> vektor;
	int brojac(0);
	for(int i=0; i<v.size(); i++) {
		if(JeLiStepenDvojke(v.at(i))) {vektor.push_back(v.at(i));
			brojac++;
		}
	}
	int max(1);
	for(int i=0;i<vektor.size();i++){
		if(vektor.at(i)>max) max=vektor.at(i);
	}
	
	if(odabir==Opadajuci) {
		int min(max);
		int brojac(0);
		bool prvi(true);
		dek.push_back(std::vector<int> (0));
		for(int i=0; i<dek.size(); i++) {
			min=max;
			int brojacJot(0);
			for(int j=brojac; j<v.size(); j++) {
					brojac++;
				if(JeLiStepenDvojke(v.at(j))) {
					if(v.at(j)<=min) {
						if(brojacJot==0 && !prvi) dek.push_back(std::vector<int> (0));
						prvi=false;
						dek.at(i).push_back(v.at(j));
						min=v.at(j);
						brojacJot++;
					} else {
						if(brojacJot==1) dek.erase(dek.begin()+i);
						else dek.push_back(std::vector<int> (0));
						if(dek.size()!=0)i++;
						j--;
						brojacJot=0;
						min=max;
					}
				}
				else {dek.push_back(std::vector<int> (0));
					i++;
					brojacJot=0;
				}
			}
		}
	}
	
	for(int i=0;i<dek.size();i++){
			if(dek.at(i).size()==0 || dek.at(i).size()==1){
				dek.erase(dek.begin()+i); 
				i--;
			}
	}
	return dek;
}

int main ()
{
	int n;
	
	
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		int x;
		std::cin>>x;
		v.push_back(x);
	}
	int odabir;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>odabir;
	if(odabir==int(Rastuci)) {
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		dekVektora dek(MaksimalniPodnizoviStepenaDvojke(v, Rastuci));
		for(int i=0; i<dek.size(); i++) {
			for(int j=0; j<dek.at(i).size(); j++) {
				std::cout<<dek.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
		/*std::cout<<dek.size();*/
	}
	if(odabir==int(Opadajuci)) {
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		dekVektora dek(MaksimalniPodnizoviStepenaDvojke(v, Opadajuci));
		for(int i=0; i<dek.size(); i++) {
			for(int j=0; j<dek.at(i).size(); j++) {
				std::cout<<dek.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}
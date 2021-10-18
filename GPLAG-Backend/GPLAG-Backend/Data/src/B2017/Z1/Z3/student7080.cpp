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

int StepenDvojke(int broj)
{
	bool logicko(true);
	int temp;
	if(broj==1) return true;    //jer je 2 na 0 =1
	if(broj<1) return false;

	while(broj!=1) {
		temp=broj%2;
		if(temp!=0) return false;
		broj/=2;
	}
	return logicko;
}

enum Smjer {Rastuci=1,Opadajuci=2} s;
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer n)
{
	std::deque<std::vector<int>> novi;
	std::vector<int> pomocni;
	if(v.size()==0 or v.size()==1) return novi;
	int j(0);
	while(  j<v.size() and StepenDvojke(v.at(j))==false) { //Dolazimo do onog clana koji jeste ustvari stepen dvojke
		if(j<v.size()-1) j++;
		else return novi;
	}

	pomocni.push_back(v.at(j));
	if(j<v.size()-1) j++; //predjemo na sljedeci clan
	if(n==1) {
		for(int i (j); i<v.size(); i++) {
			while(i<v.size() and StepenDvojke(v.at(i))==true and v.at(i-1)<=v.at(i)) {
				pomocni.push_back(v.at(i));
				if(i<v.size()-1)	i++;
				else break;
			}
			if(pomocni.size()>1) {
				novi.push_back(pomocni);
			}
			pomocni.resize(0);
			while (i<v.size()-1 and StepenDvojke(v.at(i))==false) {
				i++;
			}
			pomocni.push_back(v.at(i));
		}
	} else if(n==2) {
		for(int i(j); i<v.size(); i++) {
			while(i<v.size() and StepenDvojke(v.at(i))==true and v.at(i-1)>=v.at(i)) {
				pomocni.push_back(v.at(i));
				if(i<v.size()-1)i++;
				else break;
			}
			if(pomocni.size()>1) {
				novi.push_back(pomocni);
			}
			pomocni.resize(0);
			while(i<v.size()-1 and StepenDvojke(v.at(i))==false ) {
				i++;
			}
			pomocni.push_back(v.at(i));
		}
	}

return novi;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: " ;
	int n;
	std::cin >> n;
	std::cout << "Unesite elemente vektora: " ;
	std::vector<int>  v;
	int broj;
	for (int i(0); i<n; i++) {
		std::cin >> broj;
		v.push_back(broj);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: " ;
	int a;
	std::cin >> a;
	s=Smjer(a);
	if(s==1) {
		std::cout << "Maksimalni rastuci podnizovi: "<< std::endl;
	} else if(s==2) {
		std::cout << "Maksimalni opadajuci podnizovi: "<< std::endl;
	}
	std::deque<std::vector<int>> dek(MaksimalniPodnizoviStepenaDvojke(v,s));
	for(int i(0); i<dek.size(); i++) {
		for(int j(0); j<dek.at(i).size(); j++) {
			std::cout << dek.at(i).at(j) << " " ;
		}
		std::cout << std::endl;
	}

	return 0;
}
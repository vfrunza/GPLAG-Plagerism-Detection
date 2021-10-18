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
#include <cmath>
#include <vector>
#include <deque>


enum Smjer { Opadajuci, Rastuci };

bool StepenDvojke (int broj) {
	
	for(int i=0;;i++) {
		
		if(pow(2,i) == broj) return true;
		if(pow(2,i) > broj) break;
		
	}
	
	return false;
}

std::vector<int> MonPodniz(std::vector<int> v, int indeks, Smjer u) {
	
	std::vector<int> rez;
	std::vector<int> prazan;
	int maxi(v[indeks]);
	
	if(u) {
		
		for(int i=indeks; i<v.size(); i++) {
			if(!StepenDvojke(v.at(i))) break;
			if(i<=v.size()-1) {
				
				if(v.at(i) >= maxi) {
					
					rez.push_back(v.at(i));
					maxi = v.at(i);
				}
				
				else break;
				
			}
		}
	}
	
	else {
		
		for (int i=indeks; i<v.size(); i++) {
			if(!StepenDvojke(v.at(i))) break;
			if(i<=v.size()-1) {
				
				if(v.at(i) <= maxi) {
					
					rez.push_back(v.at(i));
					maxi = v.at(i);
					
				}
				
				else break;
				
			}
		}
		
	}
	
	if(rez.size() == 1) return prazan;
	
	return rez;
	
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer u) {
	
	std::deque<std::vector<int>> rez;
	
	for (int i=0; i<v.size(); ) {
		std::vector<int> n (MonPodniz(v, i, u));
		rez.push_back(n);
		
		if(n.size() > 0)
			i+=n.size();
			else i+=n.size()+1;
	}
	
	return rez;
	
}
int main ()
{
	try {
	std::cout << "Unesite broj elemenata vektora: ";
	int broj;
	std::cin >> broj;
	std::cout << "Unesite elemente vektora: ";
	std::vector<int> v;
	int brojevi;
	for (int i=0; i<broj; i++) {
		std::cin >> brojevi;
		v.push_back(brojevi);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int varijabla;
	std::cin >> varijabla;
	Smjer t;
	if (varijabla == 1) t=Rastuci;
	else t=Opadajuci;
	
	if (t) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	else std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	
	std::deque<std::vector<int> > k;
	k = MaksimalniPodnizoviStepenaDvojke(v,t);
	
	
	for (int i = 0; i < k.size(); i++) {
		for (int j = 0; j < k[i].size(); j++) {
		    std::cout << k[i][j] << " ";
		}
		std::cout << std::endl;
	}
	}
	catch (...) {
		
	}
	
	return 0;
	
}

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

enum Smjer {Rastuci,Opadajuci};
std::deque<std::vector<int>>MaksimalniPodnizoviStepenaDvojke(std::vector<int> a, Smjer b){
	std::vector<int> c;
	bool fir(true),alone(true);
	std::deque<std::vector<int>> r;
	for (int k = 0;k<a.size();k++){
		if ((a.at(k) & (a.at(k) - 1)) == 0 && b == Rastuci && a.at(k) != 0){
		if (fir == true){
					fir = false;
					c.push_back(a.at(k)); 
				} else if (a.at(k) >= c.at(c.size() - 1)){
				c.push_back(a.at(k));
				alone = false;
			
			 } else if (fir == false && alone == true){
				c.clear();
				alone = true;
				c.push_back(a.at(k));
				
			} else if(!(c.size() == 0)){
			if (alone == false){
				r.push_back(c);
				c.clear();
				fir = false;
				alone = true;
				c.push_back(a.at(k));
			}
			  }
			 if (k == a.size() - 1 && alone == false){
			 	if (c.size() != 0){
			 		r.push_back(c);
			 	}
			 }
		} else if ((a.at(k) & (a.at(k) - 1)) == 0 && b == Opadajuci && a.at(k) != 0){
			if (fir == true){
					fir = false;
					c.push_back(a.at(k)); 
				} else if (a.at(k) <= c.at(c.size() - 1)){
				c.push_back(a.at(k));
				alone = false;
			
			 } else if (fir == false && alone == true){
				c.clear();
				alone = true;
				c.push_back(a.at(k));
				
			} else if(!(c.size() == 0)){
			if (alone == false){
				r.push_back(c);
				c.clear();
				fir = false;
				alone = true;
				c.push_back(a.at(k));
			}
			  }
			  if (k == a.size() -1 && alone ==false){
			 	if (c.size() != 0){
			 		r.push_back(c);
			 	}
			 }
		} else {
			if ((c.size() > 1)){
				r.push_back(c);
			}
			c.clear();
			fir = true;
			alone = true;
		}
	}
	return r;
}
int main ()
{
	std::deque<std::vector<int>> r;
	std::vector<int> c;
	int a,b;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> a;
	std::cout << "Unesite elemente vektora: ";
	for(int k = 0;k<a;k++){
		std::cin >> b;
		c.push_back(b);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> a;
	if (a == 1){
		r = MaksimalniPodnizoviStepenaDvojke(c,Rastuci);
		if (!(r.size() == 0)){
			std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		}
		for(std::vector<int> row : r){
			for(int k : row){
				std::cout << k << " ";
			}
			std::cout << std::endl;
		}
	} else if (a == 2){
		r = MaksimalniPodnizoviStepenaDvojke(c,Opadajuci);
		if (!(r.size() == 0)){
			std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		}
		for(std::vector<int> row : r){
			for(int k : row){
				std::cout << k << " ";
			}
			std::cout << std::endl;
		}
	}
	return 0;
}
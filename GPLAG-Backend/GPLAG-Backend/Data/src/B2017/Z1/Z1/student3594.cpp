/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <cmath>
#include <vector>
#include <iostream>
bool Prost(int n){
	if (n <= 1){
		return false;
	}
	for (int x = 2; x <= sqrt(n);x++){
		if (n % x == 0){
			return false;
		}
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> a,bool b){
	std::vector<int> c;
	std::vector<int> d;
	bool neg;
	int temp;
	int t;
	neg = false;
		for(int x : a){
			c.clear();
			t = x;
			temp = 0;
			
			if (b == true && Prost(x) == true){
				while (x != 0){
				temp = x % 3;
				c.push_back(temp);
				x = (x - (x % 3)) / 3; 
				}
				}else if (b == false && Prost(x) != true){
				while (x != 0){
				temp = x % 3;
				c.insert(c.begin(),temp);
				x = (x - (x % 3)) / 3; 
				
			}
				} else {
					continue;
				}
			while (c.size() != 0){
				if (c.size() == 0){
					break;
				}
				if (c.size() == 1){
					c.pop_back();
				} else if (c.at(0) == c.at(c.size() - 1)){
					c.erase(c.begin(), c.begin()+1);
					c.pop_back();
				} else {
					break;
				}
				}
			if (c.size() == 0 ){
				for(int p : d) {
					if (p == t){
						neg = true;
					}
				}
				if (neg == false){
				d.push_back(t);
				}
				neg = false;
			}
			}
				return d;
			}
		
	
		
int main ()
{
	int a;
	std::vector<int>b;
	std::vector<int>c;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	while (1){
		std::cin >> a;
		if (a == -1){
			break;
		} else {
			b.push_back(a);
		}
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> a;
	if (a == 1 || a == 0){
	if (a == 1){
		c = IzdvojiSimetricneTernarne(b,true);
		if (c.size() == 0){
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		} else {
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for (int k : c){
			if(k == c.at(c.size() - 1)){
				std::cout << k << ".";
			} else {
				std::cout << k << ", ";
			}
		}
		}
	} else {
	
	
		c  = IzdvojiSimetricneTernarne(b,false);
		if (c.size() == 0){
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		} else {
				std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for (int k : c){
			if(k == c.at(c.size() - 1)){
				std::cout << k << ".";
			} else {
			std::cout << k << ", ";
			}
		}
		}
	}
	} else {
			while (1){
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> a;
		if (a ==1 || a == 0){
			break;
		}
	}
	if (a == 1){
		c = IzdvojiSimetricneTernarne(b,true);
		if (c.size() == 0){
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		} else {
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for (int k : c){
			if(k == c.at(c.size() - 1)){
				std::cout << k << ".";
			} else {
				std::cout << k << ", ";
			}
		}
		}
	} else {
	
	
		c  = IzdvojiSimetricneTernarne(b,false);
		if (c.size() == 0){
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		} else {
				std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for (int k : c){
			if(k == c.at(c.size() - 1)){
				std::cout << k << ".";
			} else {
			std::cout << k << ", ";
			}
		}
		}
	}
	}
	return 0;
}
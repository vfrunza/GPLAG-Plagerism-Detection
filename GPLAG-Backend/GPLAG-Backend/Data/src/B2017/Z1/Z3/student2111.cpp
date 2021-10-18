#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

bool StepenDvojke(int broj) {
	bool stepen(false);
	for(int i=0; i<15; i++) {
		if(i*log(2)==log(broj)) {
			stepen=true;
		}
	}
	return stepen;
}



std::vector<int> IzdvojiRastucePodnizove(std::vector <int> v, int n) {
	std::vector<int> v1(0);
	int i(n-1);

	if(v.size()<=0) return v;
	
	if(n==v.size()) return v1;
	
	do {
		i++;

	} while(i!=v.size()-1 && !(v.at(i)<=v.at(i+1) && (StepenDvojke(v.at(i))==true && StepenDvojke(v.at(i+1))==true))); //da se krece kroz niz kad nije zadovoljeno

	if(i==v.size()-1) return v1; //vraca prazan vektor jer nije nadjeno nista
	i--;


	do {
		i++;
		v1.push_back(v.at(i));

	} while(i!=v.size()-1 && v.at(i)<=v.at(i+1)  && StepenDvojke(v.at(i))==true && StepenDvojke(v.at(i+1))==true);

	v1.push_back(i);

	return v1;
}


std::vector<int> IzdvojiOpadajucePodnizove(std::vector<int> v, int n) {
	std::vector <int> v1(0);
	int i(n-1);

	if(v.size()<=0) return v; //1 4 2 4 32 16 10 4 8 4 2 1 2 1 7
	if(n==v.size()) return v1;

	do {
		i++;

	} while(i!=v.size()-1 && !(v.at(i)>=v.at(i+1) && (StepenDvojke(v.at(i))==true && StepenDvojke(v.at(i+1))==true)));

	if(i==v.size()-1) return v1;
	i--;

	do {
		i++;
		v1.push_back(v.at(i));
	} while(i!=v.size()-1 && v.at(i)>=v.at(i+1) && StepenDvojke(v.at(i))==true && StepenDvojke(v.at(i+1))==true);

	v1.push_back(i);

	return v1;
}


enum Smjer {Rastuci=1, Opadajuci=0};

std::deque<std::vector <int>> MaksimalniPodnizoviStepenaDvojke (std::vector <int> v, enum Smjer rastuci) {
	std::deque<std::vector<int>> d;
	std::vector<int> v1;
	std::vector<int> v2 ;


	int i(0);
	
	if(rastuci==1) {
		while (i < v.size()) {
			v1 = IzdvojiRastucePodnizove(v, i);
			if(v1.size() != 0) {
				i = v1.at(v1.size()-1);

					v1.pop_back();
				d.push_back(v1);
			} else break;
		}
	} else {
		while(i<v.size()) {
			v1=IzdvojiOpadajucePodnizove(v, i);
			if(v1.size()!=0) {
				i=v1.at(v1.size()-1);

					v1.pop_back();
				d.push_back(v1);
			} else break;
		}
	}
	return d;
}



int main () {
	

	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;

	std::cout << "Unesite elemente vektora: ";
	std::vector <int> A(0);

	while(n-->0) {
		int v;
		std::cin >> v;
		//if(v==0.0) break;
		A.push_back(v);
	}

    std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    int a;
    
   do {
    std::cin >> a;
    if(a!=1 && a!=2) std::cout << "Neispravan unos! Unesite ponovo: ";
    } while((a!=1) && (a!=2));
    
   
   // Smjer b;
   //b = Smjer(a);
    
    
	std::deque<std::vector<int>> B(0), C(0);
	
	
	if(a==1) {
		B = MaksimalniPodnizoviStepenaDvojke(A, Rastuci); //(A,b)
		if(B.size()>0) {
			std::cout << "Maksimalni rastuci podnizovi:\n";
			for (auto c : B) {
				for (auto x : c) {
					std::cout << x << " ";
					
				}
				std::cout << std::endl;
			}
		} else std::cout << "Nema maksimalnih rastucih podnizova!";
	}

    if(a==2) {
    	C = MaksimalniPodnizoviStepenaDvojke(A, Opadajuci);
		if(C.size()>0) {
			std::cout << "Maksimalni opadajuci podnizovi:\n";
			for (auto c : C) {
				for (auto x : c) {
					std::cout << x << " ";
					
				}
				std::cout << std::endl;
			}
		} else std::cout << "Nema maksimalnih rastucih podnizova!";
    }
	

	return 0;
}

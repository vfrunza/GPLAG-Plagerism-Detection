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

enum Smjer {Rastuci, Opadajuci};


bool StepenDvojke (int n) {
	if (n<=0) return false;
	if (n==1) return true;
	int stepen(1);
	for (int i(0); i<n; i++) {
		stepen*=2;
		if (stepen==n) return true;
	}
return false;
}

std::deque<std::vector <int>> MaksRastuci (std::vector <int> v) {

	std::deque<std::vector<int>> d;
	int br(0);
	
	for (int i(0); i<v.size()-1; i++) {
		if (v.at(i+1)>=v.at(i) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))) {
			d.push_back(std::vector<int> {});
			
			while (i<v.size()-1 && v.at(i+1)>=v.at(i) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))) {
				d[br].push_back(v.at(i));
				i++;
			}
			d[br].push_back(v.at(i));
			br++;
		}
	}
return d;
}

std::deque<std::vector <int>> MaksOpadajuci (std::vector <int> v) {
	//std::vector<int> krajnji;
	std::deque<std::vector<int>> d; int br(0);
	for (int i(0); i<v.size()-1; i++) {
		if (v.at(i+1)<=v.at(i) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))) {
			d.push_back(std::vector<int> {});
			while (i<v.size()-1 && v.at(i+1)<=v.at(i) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))) {
				d[br].push_back(v.at(i));
				i++;
			}
			d[br].push_back(v.at(i));
			br++;
		}
	}
return d;
}


std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int>v, enum Smjer jeste) {
	std::deque<std::vector<int>> dekR(MaksRastuci(v)), dekO(MaksOpadajuci(v));
	
	if (jeste==Rastuci) return dekR;
	else return dekO;
	
}

int main ()
{

    int vel;
    std::cout << "Unesite broj elemenata vektora: ";
    std::cin >> vel;
    
    std::cout << "Unesite elemente vektora: ";
    std::vector<int> v; int n;
    for (int i(0); i<vel; i++)  {
      std::cin >>  n;
      v.push_back(n);
    }
     
    int broj;  
    std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    std::cin >> broj;
  
    
    if (broj==1) {
    	std::deque<std::vector<int>> d(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
    	std::cout << "Maksimalni rastuci podnizovi: "<<std::endl;
        for (int i(0); i<d.size(); i++) {
    	for (int j(0); j<d.at(i).size(); j++) {
    		std::cout << d.at(i).at(j) << " "; 
    	}
    	std::cout<<std::endl;
    }
    }
    
    if (broj==2) {
    	std::deque<std::vector<int>> d(MaksimalniPodnizoviStepenaDvojke(v, Opadajuci));
    	std::cout << "Maksimalni opadajuci podnizovi: "<<std::endl;
        for (int i(0); i<d.size(); i++) {
    	for (int j(0); j<d.at(i).size(); j++) {
    		std::cout << d.at(i).at(j) << " "; 
    	}
    	std::cout<<std::endl;
    }
    }
    
	return 0;
}
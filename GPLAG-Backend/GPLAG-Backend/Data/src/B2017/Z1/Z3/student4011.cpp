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
#include <deque>
#include <vector>


bool jeLiStepenDvojke(int broj){
	
	int n=1;
	
	while(1){
		if(n==broj)
			return true;
		else if(n>broj)
			return false;
		n*=2;
	}
}

enum Smjer {Rastuci, Opadajuci};

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer smjer){

std::deque<std::vector<int>> rez;

if((int)smjer==0){

	for(int i=0;i<v.size();i++){
		
		if(jeLiStepenDvojke(v.at(i))){
			std::vector<int> niz;
			niz.push_back(v.at(i));
			i++;
			while(i<v.size() && jeLiStepenDvojke(v.at(i)) && v.at(i)>v.at(i-1)){
				niz.push_back(v.at(i));
				i++;
			}
			if(niz.size()>1)
				rez.push_back(niz);
			i--;
		}
	}
	
}
else {
	for(int i=0;i<v.size();i++){
		
		if(jeLiStepenDvojke(v.at(i))){
			std::vector<int> niz;
			niz.push_back(v.at(i));
			i++;
			while(i<v.size() && jeLiStepenDvojke(v.at(i)) && v.at(i)<v.at(i-1)){
				niz.push_back(v.at(i));
				i++;
			}
			if(niz.size()>1)
				rez.push_back(niz);
			i--;
		}
	}
}
	return rez;;
}


int main ()
{
	int br_elemenata=0, izbor=0, broj=0;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> br_elemenata;
	std::cout << "Unesite elemente vektora: ";
	std::vector<int> v(br_elemenata);
	for (int i=0; i<br_elemenata; i++) {
		std::cin >> broj;
		v.at(i)=broj;
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> izbor;
	Smjer s=Smjer(izbor-1);
	auto x = MaksimalniPodnizoviStepenaDvojke(v,s);
	if (izbor==1) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	else std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i=0;i<x.size();i++){
		for(int j=0;j<x.at(i).size();j++){
			std::cout<<x.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
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

enum Smjer{Rastuci, Opadajuci};

bool DaLiJeStepenDvojke (int broj){
	long long int n(broj);
	for(long long int i=1; i<=n; i*=2){
		if(i==n)return true;
		if(n/2<i)break;
	}
	return false;
}

bool VeciManji (int a, int b, bool uslov){
	if(uslov)return a<=b;
	else return a>=b;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> niz, Smjer smjer){ 
	std::deque<std::vector<int>> rjesenje;
	bool uslov;
	if(smjer==Rastuci)uslov=true;
	else uslov=false;
	//std::vector<int> samo_stepeni_dvojke;
/*	for(int i=0; i<niz.size(); i++){
		if(DaLiJeStepenDvojke(niz.at(i)))samo_stepeni_dvojke.push_back(niz.at(i));
	}*/
	for(int i=0; i<niz.size()-1; i++){ //size-1 mozdaaa
		if(VeciManji(niz.at(i), niz.at(i+1), uslov) && DaLiJeStepenDvojke(niz.at(i)) && DaLiJeStepenDvojke(niz.at(i+1))){
			std::vector<int> privremeni;
			privremeni.push_back(niz.at(i));
			int j;
			for(j=i+1; j<niz.size()-1; j++){
				if(VeciManji(niz.at(j), niz.at(j+1), uslov) && DaLiJeStepenDvojke(niz.at(j)) && DaLiJeStepenDvojke(niz.at(j+1))){
					privremeni.push_back(niz.at(j));
				}else break;
			}
			i=j;
			privremeni.push_back(niz.at(i));//ili ovde j stavit
			rjesenje.push_back(privremeni);
		}
	}
	
	return rjesenje;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<int> brojevi(n);
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		std::cin >> brojevi.at(i);
	}
	int broj;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> broj;
	Smjer uslov;
	if(broj==1)uslov=Rastuci;
	else if(broj==2)uslov=Opadajuci;
	std::deque<std::vector<int>> nizovi(MaksimalniPodnizoviStepenaDvojke(brojevi, uslov));
	if(uslov==Rastuci)std::cout << "Maksimalni rastuci podnizovi:\n";
	else std::cout << "Maksimalni opadajuci podnizovi:\n";
	for(int i=0; i<nizovi.size(); i++){
		for(int j=0; j<nizovi.at(i).size(); j++){
			std::cout << nizovi.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}
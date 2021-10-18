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
#include <cmath>

using std::vector;
using std::deque;

enum Smjer {Rastuci=1,Opadajuci=2};

bool stepenDvojke(int n) {
	for(int i=0;i<=n;i++) {
		if(n==int(pow(2,i)))
			return true;
	}
	return false;
}

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> niz , Smjer smjer) {
	
	deque<vector<int>> podnizovi;
	vector<int> pomocni;
	int i=0;
	while(i<niz.size()) { // Glavna petlja
		int clan = niz.at(i);
		if(smjer==Rastuci) { // Trazi rastuci podniz
			while(i<niz.size() && niz.at(i)>=clan && stepenDvojke(niz.at(i)) ) {
				pomocni.push_back(niz.at(i));
				clan=niz.at(i);
				i++;
			}
				
		}
		else if(smjer==Opadajuci) { // Trazi opadajuci podniz
			while(i<niz.size() && niz.at(i)<=clan && stepenDvojke(niz.at(i)) ) {
				pomocni.push_back(niz.at(i));
				clan=niz.at(i);
				i++;
			}
		}
		// Ako je nadjen podniz sa barem dva elementa , ubaci ga u dek..
		if(pomocni.size()>=2)
			podnizovi.push_back(pomocni);
		else if(pomocni.size()==0) // Nije nadjen podniz , idi na sljedeci element niza
			i++;
		pomocni.resize(0);
	}
	return podnizovi;
}


int main ()
{
	vector<int> v;
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	v.resize(n);
	for(int i=0;i<n;i++) {
		std::cin>>v.at(i);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int izbor;
	std::cin>>izbor;
	deque<vector<int>> dek = MaksimalniPodnizoviStepenaDvojke(v,Smjer(izbor));
	if(izbor==1) 
		std::cout<<"Maksimalni rastuci podnizovi: \n";
	else if(izbor==2) 
		std::cout<<"Maksimalni opadajuci podnizovi: \n";
	for(vector<int> podniz : dek ) {
		for(int x : podniz ) 
			std::cout<<x<<" ";
	   	std::cout<<std::endl;
	}
	
	return 0;
}
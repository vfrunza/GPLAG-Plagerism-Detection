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

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::deque;

enum Smjer {Rastuci, Opadajuci};

bool dva(int n) {
	while(n!=1) {
		n/=2;
		if(n%2!=0 && n!=1) return false;
	}
	return true;
}

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> brojevi, Smjer smjer) {
	deque<vector<int>> output;
	vector<int> number;
	bool newone = true;
	for(int i = 0; i < brojevi.size(); i++) {
		if(!dva(brojevi.at(i))) {
			if(number.size() > 1) output.push_back(number);
			number.clear();
			newone = true;
			continue;
		}
		if(newone) { number.push_back(brojevi.at(i)); newone = false; continue; }
		if(smjer == Rastuci) {
			if(number.at(number.size()-1) < brojevi.at(i)) number.push_back(brojevi.at(i));
			else {
				if(number.size() > 1) output.push_back(number);
				number.clear();
				number.push_back(brojevi.at(i));
				continue;
			}
		} else {
			if(number.at(number.size()-1) > brojevi.at(i)) number.push_back(brojevi.at(i));
			else {
				if(number.size() > 1) output.push_back(number);
				number.clear();
				number.push_back(brojevi.at(i));
				continue;
			}
		}
	}
	output.push_back(number);
	return output;
}

int main () {
	cout<<"Unesite broj elemenata vektora: ";
	int brojelem;
	cin >> brojelem;
	cout << "Unesite elemente vektora: ";
	vector<int> elementi;
	int count(0);
	while(count != brojelem) {
		int el;
		cin >> el;
		elementi.push_back(el);
		count++;
	}
	cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int type(0);
	cin >> type;
	if(type == 1) {
		cout << "Maksimalni rastuci podnizovi: " << endl;
		for(vector<int> subelem : MaksimalniPodnizoviStepenaDvojke(elementi, Rastuci)) {
			for(int x : subelem) cout << x <<" ";
		cout << endl;
		}
	} else if (type == 2) { cout << "Maksimalni opadajuci podnizovi: " << endl;
		for(vector<int> subelem : MaksimalniPodnizoviStepenaDvojke(elementi, Opadajuci)) {
			for(int x : subelem) cout << x <<" ";
		cout << endl;
		}
	}
	return 0;
}
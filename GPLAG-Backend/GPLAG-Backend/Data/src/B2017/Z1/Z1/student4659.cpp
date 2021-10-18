/*B 2017/2018, Zadaća 1, Zadatak 1
	
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

using namespace std;

bool ProstBroj(int x){
	if(x == 1)
		return true;
		
	for(int i=2; i<x; i++)
		if(x%i==0)
			return false;
			
	return true;
}

int ObrnutiBroj(int m) {
	int obrnuti = 0;
	int tmp = m;
	
	while(tmp) {
		obrnuti += tmp%10;
		obrnuti *= 10;
		tmp /= 10;
	}
	
	obrnuti /= 10;
	
	return obrnuti;
}

bool SimetricanBroj(int m) {
	return m == ObrnutiBroj(m);
}

int DecToTer(int m){
	int n = 0;
	
	int tmp = m;
	
	while(tmp) {
		n += tmp%3;
		tmp /= 3;
		n *= 10;
	}
	
	n /= 10;
	
	return ObrnutiBroj(n);
}

vector<int> IzdvojiSimetricneTernarne(vector<int> ulaz, bool prosti){
	vector<int> pov;
	
	for(int i=0; i<ulaz.size(); i++) {
		int tmp = ulaz.at(i);
		
		if(tmp < 0)
			tmp *= -1;
			
		if(prosti == ProstBroj(tmp) && SimetricanBroj(DecToTer(tmp)))
			pov.push_back(ulaz.at(i));
	}
	
	vector<int> rez;
	
	for(int i=0; i<pov.size(); i++){
		bool exists = false;
		
		for(int j=0; j<rez.size(); j++) {
			if(rez.at(j) == pov.at(i))
				exists = true;
		}
		
		if(!exists)
			rez.push_back(pov.at(i));
	}
	
	return rez;
}

int main ()
{
	/*vector<int> test = {191, 233, 43, -313, 142, 13, 121, 678, -151, 23, -12, 727, 173};
	
	vector<int> rez = IzdvojiSimetricneTernarne(test, true);

	for(int i=0; i<rez.size(); i++)
		cout << rez.at(i) << ", ";*/
	vector<int> v;
	
	cout << "Unesite elemente vektora (-1 za kraj): ";
	
	for(;;) {
		int x;
		cin >> x;
		if(x == -1)
			break;
		
		v.push_back(x);
	}
	
	cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	
	int prost;
	
	for(;;) {
		cin >> prost;
		if(prost != 0 && prost != 1) {
			cout << "Neispravan unos! Unesite ponovo: ";
		}
		else 
			break;
	}
	
	vector<int> rez;
	
	if(prost == 0) 
		rez = IzdvojiSimetricneTernarne(v, false);
	else if(prost == 1)
		rez = IzdvojiSimetricneTernarne(v, true);
		
	if(rez.size() == 0) {
		if(prost == 0) {
			cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		else if(prost == 1) {
			cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
	}
	else {
		if(prost == 0) {
			cout << "Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<rez.size() - 1; i++) 
				cout << rez.at(i) << ", ";
			
			cout << rez.at(rez.size() - 1) << ".";
		}
		else if(prost == 1) {
			cout << "Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<rez.size() - 1; i++) 
				cout << rez.at(i) << ", ";
			
			cout << rez.at(rez.size() - 1) << ".";
		}
	}
}
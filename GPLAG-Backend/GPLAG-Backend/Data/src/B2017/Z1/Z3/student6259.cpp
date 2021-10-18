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

using std::cout;
using std::cin;
using std::vector;
using std::deque;
using std::endl;

typedef vector<int> vektor;
typedef deque<vektor> dek_vektora;

enum Smjer {Rastuci, Opadajuci};

bool Da_li_je_stepen_dvojke(int n) {
	
	if(n > 0) {
		double L(log(n) / log(2));
		if(L - int(L) < 0.0001)  return true;
	}
	
	return false;
}

dek_vektora MaksimalniPodnizoviStepenaDvojke(vektor v, Smjer a) {
	dek_vektora dek;
	
	if(v.size() != 0) {
		if(a == Rastuci) {

			for(int i(0); i < v.size() - 1; i++) {
				vektor v1;
				if(Da_li_je_stepen_dvojke(v.at(i))) {
					v1.push_back(v.at(i));
				
					for(int j(i + 1); j < v.size(); j++) {
						if(Da_li_je_stepen_dvojke(v.at(j)) ) {
							if(v.at(j - 1) < v.at(j)) v1.push_back(v.at(j));
					
							else {
								i = j - 1;
								break;
							}
						}
					
						else {
							i = j - 1;
							break;
						}
					
						if(j == v.size() - 1) i = j;
			
					}
				
					if(v1.size() > 1) dek.push_back(v1);
			
				}
		
			}
		
			return dek;
		}

	
		for(int i(0); i < v.size(); i++) {
			vektor v1;
			if(Da_li_je_stepen_dvojke(v.at(i))) {
				v1.push_back(v.at(i));
			
				for(int j(i + 1); j < v.size(); j++) {	
					if(Da_li_je_stepen_dvojke(v.at(j))) {
						if(v.at(j) < v.at(j - 1)) v1.push_back(v.at(j));
						else {
							i = j - 1;
							break;
						}
					}
				
					else {
						i = j - 1;
						break;
					}
			
				if(j == v.size() - 1) i = j;
				
				}
			
				if(v1.size() > 1) dek.push_back(v1);
			}
		}
	}
	
	return dek;
	
}

void Ispisi_deque (dek_vektora dek) {
	
	for(int i(0); i < dek.size(); i++) {
		for(int j(0); j < dek.at(i).size(); j++) {
			cout << dek.at(i).at(j)<< " ";
		}
		
		cout << endl;
		
	}
	
}

int main ()
{
	int br_elemenata, a, broj;
	cout << "Unesite broj elemenata vektora: ";
	cin >> br_elemenata;
	
	vektor v;
	cout << "Unesite elemente vektora: ";
	for(int i(0); i < br_elemenata; i++) {
		cin >> a;
		v.push_back(a);
	}

	cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin >> broj;
	
	
	
	if(broj == 1) {
		dek_vektora dek(MaksimalniPodnizoviStepenaDvojke(v, Rastuci));
		cout << "Maksimalni rastuci podnizovi: " << endl;
		Ispisi_deque(dek);
	}
	
	else {
		cout << "Maksimalni opadajuci podnizovi: " << endl;
		dek_vektora dek(MaksimalniPodnizoviStepenaDvojke(v, Opadajuci));
		Ispisi_deque(dek);
	}
	
		return 0;
}
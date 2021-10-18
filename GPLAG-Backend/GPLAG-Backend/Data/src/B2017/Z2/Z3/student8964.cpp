/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>

bool JeLiPeriodican (std::vector<int> v) {
	int period = 1; //1 2 3 1 2 3 1
	while(v.at(0) != v.at(period)) period++;
	if(period >= v.size()) return false;
	for(int i(0); i < v.size(); i++) {
		if(i+period < v.size())
		if(v.at(i) != v.at(j+i)) return false;
	}
	return true;
}

int OsnovniPeriod (std::vector<int> v) {
	if(JeLiPeriodican(v)) {
		int period = 1;
		while(v.at(0) != v.at(period)) period++;
	}
	return period;
}

void Dopuni (std::vector<int> &v) {
	if(JeLiPeriodican(v)) {
		int period = OsnovniPeriod(v);
		for(int i(0); i < v.size(); i++) {
			if(v.at(period) == v.at(v.size()-1)) break;
			else if(v.at(i) == v.at(v.size()-1) {
				int broj = period - i;
				while(broj > 0) {
				v.push_back(v.at(i+1));
				i++;
				broj--;
			}
		}
	}
}

AlocirajFragmentirano (const std::vector<int> &v, int &koliko_puta) {
	
}

AlocirajKontinualno ()

int main ()
{
	return 0;
}
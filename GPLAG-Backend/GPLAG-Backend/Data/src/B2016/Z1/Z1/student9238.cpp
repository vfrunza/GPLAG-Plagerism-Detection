#include <vector>
#include <iostream>

using namespace std;
int ostatak, broj_ponavljanja=0;

vector<int> IzdvojiGadne (vector<int>v, bool opaki) {
	// pretvaranje broja iz dekadnog u ternarni sistem
	for(int i=0; i<v.size(); i++) {
		ostatak=i%3;
		i=i/3;
		int brojac=0;
		//prolazim kroz clanove vektora i trazim koliko puta se ponavlja svaka cifra
		bool odvratni;
		for(int j=0; j<v.size(); j++) {
		for(int k=j+1; k<v.size(); k++) {
			if(v[j]==v[k]) {
				brojac[v[k]]++;
			}
		}
	}
	for(int j : brojac) {
		if(j!=0) broj_ponavljanja++;
	}
		if(broj_ponavljanja%2==0) { opaki=true;
		odvratni=false;
	}
	else {
		opaki=false;
		odvratni=true;
	}
}
}
int main () {
	int broj;
	while(broj!=0) {
	cout << "Unesite brojeve (0 za prekid unosa):  ";
	}
	if(broj==0) return 0;

	auto opaki=IzdvojiGadne(v,true), odvratni=IzdvojiGadne(v, false);
	cout << "Opaki: ";
	for (const auto &x: opaki) cout << x << " ";
	cout << endl << "Odvratni: ";
	for(cont auto &x: odvratni) cout << x << " ";
	return 0;
}
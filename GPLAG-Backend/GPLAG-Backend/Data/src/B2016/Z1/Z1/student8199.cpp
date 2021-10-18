/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

using namespace std;


//Funkcija provjerava da li je broj uopce gadan tako sto broji koliko se puta ponavljaju cifre 1 2 i 0
int DaLiJeGadan (int n) {
	int br0 = 0;
	int br1 = 0;
	int br2 = 0;
	long int x = abs(n);
	
	
	while (x != 0) {
		if (x % 3 == 0) br0++;
		if (x % 3 == 1) br1++;
		if (x % 3 == 2) br2++;
		
		x /= 3;
	}
	if ((br0 % 2 == 0 || br0 == 0) && (br1 % 2 == 0 || br1 == 0) && (br2 % 2 == 0 || br2 == 0)) {
		return 1;
	}
	else if ((br0 % 2 != 0 || br0 == 0) && (br1 % 2 != 0 || br1 == 0) && (br2 % 2 != 0 || br2 == 0)) {
		return 2;
	}
	else {
		return 0;
	}
}

//Odvaja opake i odvratne brojeve ovisno od bool vrijednosti koja je poslana
vector<int> DaLiJeOpak(vector<int> v, bool NT) {
	vector<int> opaki;
	vector<int> odvratni;
	
	for (int i = 0; i < v.size(); i++) {
		if (DaLiJeGadan(v[i]) == 1) {
			opaki.push_back(v[i]);
		}
		else if (DaLiJeGadan(v[i] == 2)) {
			odvratni.push_back(v[i]);
		}
		else continue ;
	}
	
	if (NT == true) return opaki;
	if (NT == false) return odvratni;
}

//Izbacuje duple brojeve
vector<int> dupli (vector<int> v) {
	int s(v.size());
	
	for (int i = 0; i < s; i++) {
		int br(0);
		for (int j = i; j < s; j++) {
			if (v[j] == v[i]) {
				br++;
				if (br > 1) {
					for (int k = j; k < s - 1; k++) {
					v[k] = v[k + 1];
					}
					j--;
					s--;
				}
				/*j--;
				s--;*/
			}
		}
	}
	v.resize(s);
	return v;
}

/*Glavna funkcija koja prvo poziva funkciju koja vraca sve gadne pa onda poziva
funkciju kkoja vraca opake ili dovratne ovisno od bool vrijednosti*/
vector<int> IzdvojiGadne (vector<int> v, bool NT) {
	vector<int> gadni;
	vector<int> opaki;
	vector<int> odvratni;
	
	for (int i = 0; i < v.size(); i++) {
		if (DaLiJeGadan(v[i])) {
			gadni.push_back(v[i]);
		}
	}
	
	gadni = dupli(gadni);
	for (int i = 0; i < v.size(); i++) {
		if (NT == true) {
			opaki = DaLiJeOpak(gadni, NT);
		}
		else if (NT == false) {
			odvratni = DaLiJeOpak(gadni,NT);
		}
		else continue ;
	}
	
	if (NT == true) return opaki;
	if (NT == false) return odvratni;
}

int main ()
{
	int n;
	vector<int> v;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	do {
		cin>>n;
		if (n != 0) v.push_back(n);
	} while (n != 0);
	
	
	vector<int> opaki;
	vector<int> odvratni;
	
	bool NT(true);
	opaki = IzdvojiGadne(v, NT);
	
	NT = false;
	odvratni = IzdvojiGadne(v, NT);
	
	cout << "Opaki: ";
	for (int i = 0; i < opaki.size(); i++) {
		cout << opaki[i] << " ";
	}
	cout << endl;
	
	cout << "Odvratni: ";
	for (int i = 0; i < odvratni.size(); i++) {
		cout << odvratni[i] << " ";
	}
	cout << endl;
	
	return 0;
}
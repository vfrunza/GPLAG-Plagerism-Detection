/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector> //Ne zaboravi ukljuciti!
#include <cmath>

using std::cin; using std::cout; using std::endl; using std::vector;

//Funkcija koja pretvara broj iz baze deset u bazu tri
/*unsigned long long BrojUTernarni (int n) {
	unsigned long long rezultat(0);
	long broj=fabs(n); int i(0); //zbog prekoracenja long broj-npr. min int!
	//Brojevi su cijeli, u obzir uzimamo i negativne?!
	do {
		rezultat+=broj%3*(long long) pow(10,i);
		broj/=3;
		i++;
	}
	while (broj!=0);
	return rezultat;
}*/

bool DaLiJeOpak (int n) {
	int broj(n);
	bool opaki(true); //pretpostavimo da je opak
	vector<int> histogram(3, 0); //Vektor brojaca za cifre 0, 1 i 2
	//Prebrojimo cifre
	do {
		int cifra;
		cifra=fabs(broj%3);
		histogram[cifra]++;
		broj/=3;
	}
	while (broj!=0);
	//Ispitajmo da li je broj opak
	for (int i=0; i<3; i++) {
		if (histogram[i]%2!=0) {
			opaki=false;
			break;
		}
	}
	if (opaki) return true;
	return false; //Nije opak
}

bool DaLiJeOdvratan (int n) {
	int broj(n);
	vector<int> histogram(3, 0); //Vektor brojaca za cifre 0, 1 i 2
	do {
		int cifra;
		cifra=fabs(broj%3);
		histogram[cifra]++;
		broj/=3;
	}
	while (broj!=0);
	//Ispitajmo da li je broj odvratan
	for (int i=0; i<3; i++) {
		if (histogram[i]%2!=1 && histogram[i]!=0) { //ne zaboravi za uslov ako se broj ne javlja!
			return false; //nije odvratan! nije neparan
		}
	}
	return true; //nije doslo do prekida petlje, dakle odvratan je!
}

vector<int> IzdvojiGadne (vector<int> v, bool logicka) {
	vector<int> rezultat;
	if (logicka==true) { //Izdvajamo opake
	for (int i=0; i<v.size(); i++) {
		if (DaLiJeOpak(v.at(i))) rezultat.push_back(v[i]); 
	}
	}
	else { //Izdvajamo odvratne
	    for (int i=0; i<v.size(); i++) {
		if (DaLiJeOdvratan(v.at(i))) rezultat.push_back(v[i]);
	}
	}
	//Izbacimo ponavljanja
	if (rezultat.size()!=0 && rezultat.size()>1) {
	for (int i=0; i<rezultat.size()-1; i++) {
		for (int j=i+1; j<rezultat.size(); j++) { //Pazi da ne izlazis iz opsega!
			if (rezultat[i]==rezultat[j]) { //Izbacimo ponavljanje
				for (int k=j; (k+1)<rezultat.size(); k++)
				rezultat[k]=rezultat[k+1];
				rezultat.resize(rezultat.size()-1);
				j--; //Da provjerimo i element koji se sada pomjerio!
			}
		}
	}
	}
	return rezultat;
}

int main()
{
	cout << "Unesite brojeve (0 za prekid unosa): ";
	vector<int> vek1, vek;
	int broj(0);
	do {
		cin >> broj;
 		if (broj != 0)
		vek1.push_back(broj);
	}
	while (broj!=0);
	
	cout << "Opaki: ";
	vek=IzdvojiGadne(vek1, true);
	for (int i=0; i<vek.size(); i++) {
		cout << vek[i] << " ";
	}
	
	cout << "\nOdvratni: ";
	vek=IzdvojiGadne(vek1, false);
	for (int i=0; i<vek.size(); i++) {
		cout << vek[i] << " ";
	}
	return 0;
}
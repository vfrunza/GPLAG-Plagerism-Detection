//B 2016/2017, Zadaća 1, Zadatak 1

#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<int> Vektor;

//funkcija vraća 0 kad nije ništa, 1 kad je odvratan i 2 kad je opak
int OpakIliOdvratan (int ispitanik){
	int nule{}, jedinice{}, dvice{}; 	//brojači cifara u ternarnom brojnom sistemu
	do {
		switch (abs(ispitanik % 3)) {	//jer neg br % 3 ne odg mom switch case-u
			case 0:
				nule++; 
				break;
			case 1:
				jedinice++; 
				break;
			case 2:
				dvice++; 
				break;
		}
		ispitanik /= 3;
	} while (ispitanik != 0);
	//def..da se svaka cifra koja se javlja u njima javlja paran (za opake tj neparan za odvratne) broj puta
	if (nule % 2 == 0 && jedinice % 2 == 0 && dvice % 2 == 0) return 2; 															//opak
	if ((nule % 2 != 0 || nule == 0) && (jedinice % 2 != 0 || jedinice == 0) && (dvice % 2 != 0 || dvice == 0 )) return 1; 			//means odvratan
	return 0; 																														//ni opak ni odvratan
}

Vektor IzdvojiGadne(Vektor v, bool opak){
	Vektor vGadni;
	bool isti; // služit će mi da se ne bi ponavljali elementi vektora
	for (int i{}; i < v.size(); i++){
		if ( ((OpakIliOdvratan(v[i]) == 2 && opak) || (OpakIliOdvratan(v[i]) == 1 && !opak)) ) {
			isti = false; //!!! pretpostaviti da su false (i svaki put vratiti prepostavku)
			for (int j{}; j < vGadni.size(); j++){
				if (v[i] == vGadni[j]){
					isti = true;
					break;
				}
			}
			if (!isti) vGadni.push_back(v[i]);
		}
	}
	return vGadni;
}

int main (){
	int n;
	using std::cout; using std::cin;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	Vektor vBuckuris;
	do {
		cin >> n;
		if (n != 0) vBuckuris.push_back(n); 
	} while (n != 0);
	
	cout << "Opaki: ";
	bool opak(true);
	Vektor vOpaki(IzdvojiGadne(vBuckuris, opak));
	for(int i{}; i < vOpaki.size(); i++)
		cout << vOpaki[i] << " ";

	Vektor vOdvratni(IzdvojiGadne(vBuckuris, !opak)); //odvratni su i !opak
	cout << std::endl << "Odvratni: ";
	for(int i(0); i < vOdvratni.size(); i++)
		cout << vOdvratni[i] << " ";
	return 0;
}

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int stepen(int baza, int eksponent) {
	
	int rez(1);
	
	for(int i = 0; i < eksponent; i++){
		
		rez *= baza;
	}
	return rez;
}


int Ternarni(int n){
	
	int brojac(0), brojac2(0), ostatak, ternarni(0), tmp(n);
	
	while(tmp != 0) {
		
		tmp /= 3;
		brojac++;
	}
	
	if(brojac >= 10) return 221;		// ako broj ima vise cifara od broja cifara max integera vracamo ternarni broj koji nije ni odvratan ni gadan
										// kako bi preskocili njegov ispis
	while(n != 0) {
		
		ostatak = n % 3;
		n /= 3;
		
		ternarni += ostatak * stepen(10, brojac2);
		
		brojac2++;
	}
	
	return ternarni;
}

int ParanNeparan(int cifre[]){
	
	int paran(0);
	
	for(int i = 0; i < 3; i++){
		
		if(cifre[i] % 2 == 0 && cifre[i] != 0) {
			
			paran = 1;
			
			for(int j = 1; j < 3; j++) {
				
				if(cifre[j] % 2 != 0 && cifre[j] != 0){
					paran = 2;
					return paran;
				} else paran = 1;
			}
		} else if(cifre[i] % 2 != 0 && cifre[i] != 0){
			
			paran = 0;
			
			for(int j = 1; j < 3; j++) {
				
				if(cifre[j] % 2 == 0 && cifre[j] != 0){
					
					paran = 2;
					return paran;
				} else paran = 0;
			}
		}
	}
	
	return paran;
}


bool ProvjeraIsti(vector<int> brojevi, int broj) {
	
	bool isti(false);
	int br(0);
	
	for(int i = 0; i < brojevi.size(); i++) {
		
		if(broj == brojevi[i]) {
			
			br++;
		}
	}
	
	if(br >= 1) isti = true;
	
	return isti;
}

vector<int> IzdvojiGadne(vector<int> brojevi, bool opak) {
	
	
	int ternarni, cifra, paran;
	int cifre[3] = {};							// niz od 3 cifre jer je baza 4 (suvisno koristiti vektor jer necemo mijenjati dimenziju niza)
	bool isti(false);
	vector<int> v, v2;
	vector<int> brojevi2;
	brojevi2 = brojevi;
	
	for(int i = 0; i < brojevi.size(); i++) {
		
		brojevi2[i] = abs(brojevi[i]);
		ternarni = Ternarni(brojevi2[i]);
		
		while(ternarni != 0){
			
			cifra = ternarni % 10;
			cifre[cifra]++;			// histogram za brojanje cifara
			ternarni /= 10;
		}
		
		for(int j = 0; j < 3; j++) {
			
			paran = ParanNeparan(cifre);
			
			if(paran == 1){
				
				isti = ProvjeraIsti(v, brojevi[i]);						// 1 = paran
				if(isti) break;											// 0 = neparan
				v.push_back(brojevi[i]);								// 2 = ni paran ni neparan
				break;
			} else if(paran == 0){
				
				isti = ProvjeraIsti(v2, brojevi[i]);
				if(isti) break;
				v2.push_back(brojevi[i]);
				break;
			}
			
		}
		
		for(int j = 0; j < 3; j++) {
			
			cifre[j] = 0;
		}
	}
	
	if(opak) return v;
	else return v2;
	
	
}

int main ()
{
	
	int n;
	vector<int> v, parni, neparni;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	
	do{
		
		cin >> n;
		if(n != 0) v.push_back(n);
	}while(n != 0);
	
	
	parni = IzdvojiGadne(v, true);
	neparni = IzdvojiGadne(v, false);
	cout << "Opaki: ";
	for(int i : parni) cout << i << " ";
	cout << endl << "Odvratni: ";
	for(int i : neparni) cout << i << " ";
	
	
	return 0;
}
#include <stdio.h>

int daj_prost () {
	static tekuciProst = 1;
	int temp = tekuciProst + 1;
	int nadjenProst = 0;
	
	while(nadjenProst == 0) {
		int prostJe = 1;
		int i;
		for(i = 2; i < temp/2 + 1; i++) {
			if(temp % i == 0) {
				prostJe = 0;
				break;
			}
		}
		
		if(prostJe == 1) {
			tekuciProst = temp;
			return temp;
		}
		else {
			temp++;
		}
	}
}
int main() {
	int i, A, B, suma = 0;
	int unosIspravan = 1;
	do {
		unosIspravan = 1;
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A >= B){
			printf("A nije manje od B. \n");
			unosIspravan=0;
		}
		else if(A <= 0) {
			printf("A nije prirodan broj. \n");
			unosIspravan = 0;
		}
		else if(B <= 0) {
			printf("B nije prirodan broj. \n");
			unosIspravan = 0;
		}
	}
	while(unosIspravan == 0);
		
		int uslovZaustavljanja = 1;
		while(uslovZaustavljanja == 1) {
			int sljedeciProstBroj =  daj_prost();
			if(sljedeciProstBroj > A && sljedeciProstBroj < B) suma += sljedeciProstBroj;
			else if(sljedeciProstBroj > B) {
				uslovZaustavljanja = 0;
			}
		}
		printf("Suma prostih brojeva izmedju %d i %d je %d. \n", A, B, suma);
	
	return 0;
}


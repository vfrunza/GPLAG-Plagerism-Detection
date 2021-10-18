#include <stdio.h>
#include <math.h>

void zaokruzi1(float* niz, int broj_el) {

	int i; 
	
	for(i=0; i<broj_el; i++) {
		
		niz[i] *= 10;
		niz[i] = round (niz[i]);
		niz[i] = niz[i]/10;
	}
}

void preslozi(float* niz, int broj_el, int K) {
	
	int i = 0;
	int brojac = 0;
	int j, kopija_int, cifra, suma;
	float temp;
	
	zaokruzi1(niz, broj_el);
	
	while(brojac!=broj_el) {
		
		suma = 0;
		kopija_int = 10*niz[i];
		
		do{
		
		cifra = fabs(kopija_int%10);
		suma = suma+cifra;
		kopija_int = kopija_int/10;
		
		}while(kopija_int!=0);
	
			if(suma<K) {
		
				for(j=i; j<broj_el-1; j++) {
			
					temp = niz[j];
					niz[j] = niz[j+1];
					niz[j+1] = temp;
			
				}
		
					i--;
			}		
	
					i++;
					brojac++;
	
	}	
}

int main() {
	
	int i;
	float niz[4];
	
	for(i=0; i<4; i++) {
		
		scanf("%f ", &niz[i]);
		
	}
	
	preslozi(niz, 4, 4);
	
	for(i=0; i<4; i++) {
		
		printf("%g ", niz[i]);
	}
	
	return 0;
}

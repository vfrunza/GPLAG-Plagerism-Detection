#include <stdio.h>
#include <math.h>

#define N 10

int apsolutnaVrijednost(int n) {
	if(n < 0) return -n;
	else return n;
}

int sumaCifara(int broj) {
	int suma = 0;
	
	while(broj != 0) {
		suma += apsolutnaVrijednost(broj % 10);
		broj /= 10;
	}
	return suma;
}

int daLiJeFibonaccijev(int t) {
	double root5 = sqrt(5);
	double phi = (1 + root5) / 2;
	int idx;
	idx = (long)floor(log(t*root5) / log(phi) + 0.5 );
	long u = (long)floor(pow(phi, idx) / root5 + 0.5 );
	
	if(u == t) return 1;
	else return 0;
}
void ubaci(int niz[]) {
	int i = 0;
	
	for(i = 2*N - 1; i>0; i--) {
		if(i % 2 == 0) niz[i] = niz[i/2];
	}
	
	for(i = 1; i < 2*N; i++) {
		if(i % 2 == 1) niz[i] = sumaCifara(niz[i-1]);
	}
	

}
int izbaci (int niz[]) {
	int brojEl = 2*N;
	int i;
	for(i = 0; i < brojEl; i++) {
		if(daLiJeFibonaccijev(niz[i]) == 1) {
			int j = i;
			for(j = i; j < 2*N-1; j++) {
				niz[j] = niz[j+1];
			}
			i--;
			brojEl--;
		}
	}
	return brojEl;
}

void ispisiniz(int niz[]) {
	printf("\n");
	int i;
	for(i = 0; i < 10; i++) {
		printf("%d", niz[i]);
	}
}

int main() {
	
	int i;
	int niz[2 * N];
	printf("Unesite niz od 10 brojeva: ");
	for(i = 0; i < N; i++) {
		scanf("%d", &niz[i]);
	}
	
	ubaci(niz);
	
	int brEl = izbaci(niz);
	
	
	printf("Modificirani niz glasi: ");
	for(i = 0; i < brEl; i++) {
		
		if(i==brEl-1){
			printf("%d.",niz[i]);
		}
		else{
			printf("%d, ",niz[i]);
		}
		
	}
	return 0;
}
	

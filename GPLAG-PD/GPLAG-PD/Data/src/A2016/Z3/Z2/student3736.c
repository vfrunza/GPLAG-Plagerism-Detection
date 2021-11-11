#include <stdio.h>

int suma_cifri(int broj) {
	int suma=0;
	while(broj) {
		suma+=(broj%10);
		broj/=10;
	}
	if(suma<0) suma*=-1;
	return suma;
}

int fibonacci(int broj) {
	int niz[10000];
	int i, istina=0;
	if (broj==1) return 1;
	niz[0]=1; 
	niz[1]=1;
	for(i=2; i<10000; i++) {
		niz[i]=niz[i-1]+niz[i-2];
		if(broj==niz[i]) { 
			istina=1;
			break;
		}
		if(niz[i]>broj) break;
	}
	return istina;
}

void ubaci(int *niz, int vel) {
	int i, k=0;
	int *poz, *kraj;
	for(i=0; i<vel*2; i+=2){
		poz=niz+i+1;
		kraj=niz+vel+k;
		while(kraj>poz) {
			*(kraj)=*(kraj-1);
			kraj--;
		}
		*poz=suma_cifri(niz[i]);
		k++;
	}
}

int izbaci(int* niz, int vel) {
	int i;
	int *poz, *kraj;
	for(i=0; i<vel; i++) {
		if (fibonacci(niz[i])) {
			poz=niz+i;
			kraj=niz+vel-1;
			while(kraj>poz) {
				*poz=*(poz+1);
				poz++;
			}
			vel--;
			i--;
		}
	}
	return vel;
}

int main() {
	int niz[20];
	int vel, i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d", &niz[i]);
	}
	ubaci(niz, 10);
	vel=izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<vel-1; i++) {
		printf("%d, ", niz[i]);
	}
	printf("%d.", niz[vel-1]);
	return 0;
}

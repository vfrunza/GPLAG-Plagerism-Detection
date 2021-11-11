#include <stdio.h>
#include <math.h>
int zbir_cifara (int broj) {
	int suma=0, brojCifara=0, broj1, i;
	broj1=fabs(broj);
	while(broj1!=0) {
		broj1/=10;
		brojCifara++;
	}
	for(i=0; i<brojCifara; i++) {
		broj1 = broj % 10;
		suma+=broj1;
		broj = (int)broj/10;
	}
	return fabs(suma);
}
void ubaci (int niz[], int vel) {
	int i, j=1;
	for(i=0; i<vel; i++) {
		niz[vel*2-2*j] = niz[vel-j];
		j++;
	}
	for(i=1; i<vel*2; i+=2) {
		niz[i] = zbir_cifara(niz[i-1]);
	}
}
int izbaci (int niz[], int vel) {
	int i, j;
	for(i=0; i<vel; i++) {
		int prethodna1, prethodna2, zbir;
		prethodna1 = 0;
		prethodna2 = 1;
		zbir = 0;
		for(j=0; ; j++) {
			zbir = prethodna1 + prethodna2;
			prethodna1 = prethodna2;
			prethodna2 = zbir;
			if(niz[i]<zbir) {
				break;
			}	
			else if(niz[i]==zbir) {
				int k=0;
				vel--;
				for(k=i; k<vel; k++) {
				niz[k] = niz[k+1];
				}
				i--;
				break;
			}
			else continue;
		}
	}
	return vel;
}
int main() {
	int niz[20]={0}, i, vel=10, velNovogNiza;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<vel; i++) {
		scanf("%d", &niz[i]);
	}
	printf("Modificirani niz glasi: ");
	ubaci(niz, vel);
	velNovogNiza=izbaci(niz, 20);
	for(i=0; i<velNovogNiza-1; i++) {
		printf("%d, ", niz[i]);
	}
	printf("%d.", niz[velNovogNiza-1]);
	return 0;
}
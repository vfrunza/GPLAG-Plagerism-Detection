#include <stdio.h>

/* Globalna promjenjljiva koja cuva velicinu niza i mijenja se u funkcijama ubaci/izbaci */
int VELICINA=10;

int suma_cifara(int broj) {
	int suma=0, cifra;
	if(broj<0) broj=-broj;
	while(broj!=0) {
		cifra=broj%10;
		suma+=cifra;
		broj=broj/10;
	}
	return suma;
}

int max_element(int niz[], int vel) {
	int najveci=niz[0], i;
	for(i=0; i<vel; i++) {
		if(niz[i]>najveci)
			najveci=niz[i];
	}
	
	return najveci;
}


void ubaci(int niz[], int vel) {
	int k;
	for(k=vel-1; k>=0; k--)
		niz[k*2]=niz[k];
		
	for(k=0; k<vel; k++)
		niz[(k*2)+1]=suma_cifara(niz[k*2]);
		VELICINA=20;
}

int izbaci(int niz[], int vel) {
	int i, j, F_broj, max_el;
	int p=0,q=1;
	
	
	max_el=max_element(niz, vel);
	F_broj=p+q;
	while(F_broj<=max_el) {
		
		for(i=0; i<vel; i++) {
			if(niz[i]==F_broj) {
				for(j=i; j<vel-1; j++) 
					niz[j]=niz[j+1];
			vel--;
			i--;
			}
		}
		p=q; q=F_broj;
		
		F_broj=p+q;
	}
	
return vel;	
}

int main() {
	int i, n;
	int niz[20];
	
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<VELICINA; i++)
		scanf("%d", &niz[i]);
	
	ubaci(niz, VELICINA);
	n=izbaci(niz, VELICINA);
	printf("Modificirani niz glasi: ");
	for(i=0; i<n; i++) {
		if(i==n-1)
			printf("%d.", niz[i]);
		else
		printf("%d, ", niz[i]);
	}
	
	return 0;
}

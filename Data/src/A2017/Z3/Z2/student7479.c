#include <stdio.h>
#include <math.h>

void zaokruzi1 (float *niz, int n) {
	int i;
	for (i=0; i<n; i++) {
		*niz=*niz*10;
		*niz= (round) (*niz);
		*niz=*niz/10;
		niz++;
	}
}

void preslozi (float *niz, int n, int k) {
	int i, j, suma, broj, temp;
	float tmp=0;
	float *q, *p;
	zaokruzi1(niz,n);
	for (i=0; i<n; i++) {
		suma=0;
		broj=0;
		temp=*niz*10;
		while (temp>0) {
			if (temp<0) {
				temp=temp*(-1);
			}
			broj=temp%10;
			suma+=broj;
			temp=temp/10;
		}
		if (suma<k) {
			q=niz;
			p=(niz+1);
			tmp=*niz;
			for (j=0; j<n-2; j++) {
				*q=*p;
				q++;
				p++;
			}
			*p=tmp;
		} else {
			niz++;
		}
	}
}

int main() {
	float niz[100];
	int n, i, k;
	printf ("Unesite velicinu niza: ");
	scanf ("%d", &n);
	printf ("Unesite clanove niza: ");
	for (i=0; i<n; i++){
		scanf ("%f", &niz[i]);
	}
	printf ("Unesite k: ");
	scanf ("%d", &k);
	preslozi(niz,n,k);
	for(i=0; i<n; i++) {
		printf ("%g ", niz[i]);
	}
	return 0;
}

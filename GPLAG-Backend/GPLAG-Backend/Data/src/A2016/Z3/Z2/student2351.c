#include <stdio.h>
#include <stdlib.h>
int izbaci (int*niz, int vel) {
	int prvi=1,drugi=1,treci;
	int j,k,p=0;
	while (prvi>0) {
		treci=prvi+drugi;
		prvi=drugi;
		drugi=treci;
		for (j=0; j<vel; j++) {
			if (p==1) {
				p=0; j--; }
				if (prvi==niz[j]) {
					for (k=j; k<vel-1; k++)
					niz[k]=niz[k+1];
					vel--;
					if(j==0) p++;
					else j--;
				}
			}
		}
		return vel;
}

int saberi_cifre (int broj) {
	int cifra,suma=0;
	while (broj!=0) {
		cifra=broj%10;
		broj/=10;
		suma+=cifra; 
	}
	return abs(suma);
}

int ubaci (int* niz, int vel) {
	int i,n,j;
	for (i=0; i<vel; i++) {
		for (j=vel; j>i+1; j--) {
			niz[j]=niz[j-1];
		}
		vel++;
		n=saberi_cifre(niz[i]);
		niz[i+1]=n;
		i++;
	}
    return vel;	
}

int main () { 
	int niz[100],i,vel=10;
	printf("Unesite niz od 10 brojeva: ");
	for (i=0; i<vel; i++)  
	scanf("%d", &niz[i]);  
	vel=ubaci(niz,vel);
	vel=izbaci(niz,vel);
	printf("Modificirani niz glasi:");
	for(i=0; i<vel; i++) {
		if (i+1==vel)
		printf(" %d.", niz[i]);
		else printf(" %d,", niz[i]); }
		return 0;
}


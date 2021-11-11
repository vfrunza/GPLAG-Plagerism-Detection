#include<stdio.h>
void ubaci (int niz[], int velicina) {
	int i, a, c, suma=0, j=velicina-1;
	for(i=2*velicina-2; i>=0; i-=2) { /* Pravi prazna mjesta izmedju clanova */
		niz[i]=niz[j];
		j--;
	}
	for(i=1; i<2*velicina; i+=2) { /* Ubaca nove elemente na prazna mjesta */
		a=niz[i-1];
		if(a<0) a=a*(-1);
		while(a!=0) {
			c=a%10;
			suma+=c;
			a=a/10;
		}
		niz[i]=suma;
		suma=0;
	}
}

int izbaci (int niz[], int velicina) {
	int i, j; 
	int x=1, y=1, z, ind=0;
	for(i=0; i<velicina; i++) { /* Izbaca elemente Fibonaccijevog niza */
		for(;;) {
			z=x+y;
			x=y;
			y=z;
			if(niz[i]==z || niz[i]==1) {
				ind=1;
				break;
			}
			if(z>niz[i]) break;
		}
		x=1;
		y=1;
		if(ind==1) {
			for(j=i; j<velicina-1; j++) {
				niz[j]=niz[j+1];
			}
			velicina--;
			i--;
		}
		ind=0;
	}
	return velicina;
}
int main () {
	int niz[100], i, vel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d", &niz[i]);
	}
	ubaci (niz, 10);
	vel=izbaci (niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<vel; i++) {
	    if(i==vel-1) {
			printf("%d.", niz[i]);
		} else if(vel==1) {
			printf("%d.", niz[i]);
		} else {
			printf("%d, ", niz[i]);
		}
	}
	return 0;
}
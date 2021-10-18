#include <stdio.h>

/* suma cifara */
int suma(int n) {
	int x=0, a;
	if(n==0) {
		return 0;
	}
	while(n!=0) {
		if(n>0) {
			a=n%10;
			x+=a;
			n=n/10;
		}
		else {
			a=n%10;
			x-=a;
			n=n/10;
		}
	}
	return x;
}

void ubaci(int* niz, int vel) {
	int i, a, j;
/*i petljom pozivamo funkciju suma i postavljamo sumu cifara na kao sljedeci clan niza, a j petljom pomjeramo clanove za jedno mjesto unaprijed*/
	for(i=0; i<2*vel; i+=2) {
		a=suma(niz[i]);
		for(j=vel*2-1; j>i+1; j--) {
			niz[j]=niz[j-1];
		}
		niz[i+1]=a; 
	}
}



int izbaci(int* niz, int vel) {
	int i=0, j, c, max, a=1, b=1 ;
	
	/* trazenje maksimalnog clana */
	max=niz[0];
	for(i=1; i<vel; i++) {
		if(niz[i]>max) {
			max=niz[i];
		}
	}
	
	do {
		c=a+b;
		a=b;
		b=c;
		/*Uporedjujemo clanove niza sa Fibonnacijevim clanovima niza: ako su jednaki, velicina se smanjuje za jedan*/
		for(i=0; i<vel; i++) {
			if(niz[i]==c || niz[i]==1) {
				for(j=i; j<vel-1; j++) {
					niz[j]=niz[j+1];
				}
				vel--;
				i--;
			}
		}
	} while (c<=max);
	return vel;
}



int main() {
	int niz[20], i, k;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d", &niz[i]);
	}
	ubaci(niz, 10);
	k=izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<k; i++) {
		if(i!=k-1) {
			printf("%d, ", niz[i]);
		}	
		else printf("%d.", niz[i]);
	}
	return 0;
}
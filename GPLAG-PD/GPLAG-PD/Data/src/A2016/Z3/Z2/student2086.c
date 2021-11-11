#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define bre1 10
#define bre12 20
void ubaci (int *niz, int size) {
	int n, dig, num1, num2=0;
	for (n=size-1; n>=0; n--) {
		*(niz+2*n)=*(niz+n);
	}
	for (n=0; n<size*2; n++) {
		if (n%2==1) {
			num1=*(niz+n-1);
			while (num1!=0) {
				dig=num1%10;
				num2+=dig;
				num1/=10;
			}
			num2=abs(num2);
			*(niz+n)=num2;
			num2=0;
		}
	}
}

int izbaci (int*niz, int size) {
	int n, m, p, first=0, second=1, next;
	for (n=0; n<size; n++) {
		first=0;
		second=1;
		for (m=1; m<10000; m++) {
			if (m==1) {
				next=m;
			} else {
				next=first+second;
				first=second;
				second=next;
			}
			if (*(niz+n)==next) {
				for (p=n; p<size-1; p++) {
					*(niz+p)=*(niz+p+1);
				}
				size--;
				n--;
				break;
			}
		}
	}
	return size;
}

int main () {
	int niz[20], n, x;
	
	/*UNOS */
	printf ("Unesite niz od 10 brojeva: ");
	for (n=0; n<10; n++) {
		scanf ("%d", &niz[n]);
	}
	
	/*POZIVANJE FUNKCIJE "UBACI"*/
	ubaci (niz, bre1);
	
	/*POZIVANJE FUNKCIJE "IZBACI"*/
	x=izbaci (niz, bre12);
	
	printf ("Modificirani niz glasi: ");
	for (n=0; n<x; n++) {
		if (n<(x-1)) {
			printf ("%d, ", niz[n]);
		} else {
			printf ("%d. ", niz[n]);
		}
	}
	return 0;
}
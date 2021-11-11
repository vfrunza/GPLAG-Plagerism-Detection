#include <stdio.h>
#define N 100

int digitsum (int broj) {
    int suma=0, digit;
    
    if(broj<0)
		broj*=-1;
    
    while (broj >= 1) {
        digit = broj%10;
        suma+=digit;
        broj/=10;
    }
    
    return suma;
} 

int isFibonacci (int broj) {
	
	int fibs[N], i, flag = 0;
	
	fibs[0] = 1;
	fibs[1] = 1;
	for (i = 2; i < N; i++) {
		fibs[i] = fibs[i-1] + fibs[i-2];
	}
	
	for (i = 0; i < N; i++) {
		if (fibs[i] == broj) {
			flag = 1;
		}
		if (fibs[i] > broj) {
			break;
		}
	}
	
	return flag;
}

void ubaci (int niz[], int vel) {
	
	int original, insert, i, j;
	vel*=2;
	
	for (i = 0; i < vel; i+=2) {
		original = niz[i];
		insert = digitsum(original);
		for (j = vel-1; j > i; j--) {
			niz[j] = niz [j-1];
		}
		niz[i+1] = insert;
	}
}

int izbaci (int niz[], int mod) {
	
	int i, j;
	
	for (i = 0; i < mod; i++) {
		if (isFibonacci(niz[i]) == 1) {
			for (j = i; j < mod - 1; j++) {
				niz[j] = niz[j+1];
			}
			mod--;
			i--;
		}
	}
	
	return mod;
}

int main() {
	
	int niz[20]={0}, i, mod=20;
	
	printf ("Unesite niz od 10 brojeva: ");
	for (i = 0; i < 10; i++) {
	    scanf ("%d", &niz[i]);
	}
	
	ubaci(niz,10);
	mod = izbaci(niz,20);
	
	printf ("Modificirani niz glasi: ");
	for (i = 0; i < mod; i++) {
		if (i != mod-1) printf ("%d, ", niz[i]);
		else printf ("%d.", niz[i]);
	}
	
	return 0;
}
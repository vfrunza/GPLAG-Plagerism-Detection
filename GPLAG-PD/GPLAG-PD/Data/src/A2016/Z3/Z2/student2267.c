#include <stdio.h>
#include <math.h>


void ubaci (int *P, int n) {
	int i;
	int nizA[100];
	int *q;
	int suma = 0;
	int k;
	q = P;
	for (i=0;i<n;i++) {
		nizA[i] = *q;
		q++;
	}
	q = P;
	for (i=0;i<n;i++) {
		*q = nizA[i];
		q +=2;
	}
	for (i=0;i<n;i++) {
		k = *P;
		suma = 0;
		while (fabs(k) > 0) {
			 suma+= k% 10;
			 k /= 10;
		}
		suma = fabs(suma);
		P++;
		*P = suma;
		P++;
	}
}

int izbaci (int niz[], int n) {
	int i;
	int j;
    int a = 1, b = 1, c = 1 ;
    int nizB[50] = {1,1};
    int k;
    for (i=2;i<50;i++) {
    	c = a + b;
    	b = c;
    	a = c - a;
    	nizB[i] = c;
    }
    for (i=0;i<n;i++) {
    	for (j=0;j<50;j++) {
    		if (niz[i] == nizB[j]) {
    			for(k=i; k<n-1; k++) {
    				niz[k] = niz[k+1];
    			}
    			n--;
    				i--;
    				break;
    		}
    	}
    }
    return n;
}

int main() {
	int niz[20] = {0}, q = 20, w, e = 10;
	int i;
	printf("Unesite niz od 10 brojeva: ");
	for (i=0;i<10;i++) {
		scanf("%d", &niz[i]);
	}
	ubaci(&niz[0], e);
	w = izbaci(&niz[0], q);
	printf("Modificirani niz glasi: ");
	for(i=0;i < w;i++) {
		if (i<w-1) {
			printf("%d, ", niz[i]);
		} else {
			printf("%d.", niz[i]);
		}
	}
	return 0;
}

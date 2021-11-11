#include <stdio.h>
#include <math.h>


void ubaci (int *p, int n){
	int i, j=0, niz[100], *t, k, s=0;
	t = p;
	for (i=0; i<n; i++){
		niz[i] = *t;
		t++;

	}
	t = p;
	for (i=0; i<n; i++){
		*t = niz[j];
		j++;
		t+=2;
	}
	for (i=0; i<n; i++){
		k = *p;
		k = fabs(k);
		s=0;
		while (k > 0){
			s+=k%10;
			k/=10;
		}
		p++;
		*p = s;
		p++;
	}
}

int izbaci (int niz[], int n){
	int i, j, k, a=1, b=1, c=1;
	int nizf[50]={1,1};
	for (i=2; i<50; i++){
		c=a+b;
		b=c;
		a=c-a;
		nizf[i]=c;
	}
	for (i=0; i<n; i++){
		for (j=0; j<50; j++){
			if (niz[i]==nizf[j]){
				for (k=i; k<n-1; k++){
					niz[k]=niz[k+1];
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
	int i, niz[20] = {0}, n, x, k;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++){
		scanf ("%d", &niz[i]);
	}
	n=20;
	k=10;
	ubaci(niz, k);
	x=izbaci(niz, n);
	printf ("Modificirani niz glasi: ");
	for (i=0; i<x; i++){
		if (i<x-1){
			printf ("%d, ", niz[i]);
		} else {
			printf ("%d.", niz[i]);
		}
	}
	return 0;
}
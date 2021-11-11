#include <stdio.h>

int suma(int broj) {
	if (broj<0) broj*=-1;
	int s, cifra;
	s=0;
	while(broj) {
		cifra=broj%10;
		s+=cifra;
		broj/=10;
	}
	return s;
}

int je_li_fib(int broj) {
	int niz[20000]={0};
	int i;
	niz[0]=1;
	niz[1]=1; 
	for(i=2; i<20000; i++) {
		niz[i]=niz[i-1]+niz[i-2];
		if(niz[i]==broj) return 1;
		if(niz[i]>broj) break;
	}
	return 0;
}

void ubaci(int *niz, int n) {
	int i=0;
	int *poc=niz, *kraj=niz+n-1, *k, *p;
	while (i<n) {
		k=kraj+i;
		p=poc;
		while(k>p) {
			*(k+1)=*k;
			k--;
		}
		*(p+1)=suma(*poc);
		poc+=2;
		i++;
	}
	
}


int izbaci(int *niz, int n) { 
	int i, j;
	for(i=0; i<n; i++) {
		if(*(niz+i)==1 || je_li_fib(*(niz+i))==1) {
			for(j=i; j<n-1; j++) {
				*(niz+j)=*(niz+j+1);
			}
			i--;
			n--;
		}
	}
	return n;
}

int main() {
	int niz[20];
	int i, n=10;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<n; i++) {
		scanf("%d", &niz[i]);
	}
	ubaci(niz, n);
	n=izbaci(niz, 2*n);
	printf("Modificirani niz glasi: ");
	for(i=0; i<n-1; i++) {
		printf("%d, ", niz[i]);
	}
	printf("%d.", niz[n-1]);
	return 0;
}

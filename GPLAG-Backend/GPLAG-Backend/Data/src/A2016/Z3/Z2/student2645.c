#include <stdio.h>
#include <stdlib.h>
void ubaci(int* niz, int vel) {
	
	int c, broj=vel, *p, i;
	for(i=0; i<vel; i++) {
		int suma=0;
		int x=abs(*niz);
		while(x!=0) {
		c=x%10;
		suma+=c;
		x=x/10;
		}
		
		p=niz+broj;
		while(niz<p) {
			*p=*(p-1);
			p--;
		}
		p++;
		*p=suma;
		niz=niz+2;
		broj--;
	}
}

int Fib(int a) {
	int x=1;
	int y=1, b;
	if(a==1) return 1;
	while(y<=a) {
		b=x;
		x=y;
		y=b+x;
		if(y==a) return 1;
	}
	return 0;
}

int izbaci(int* niz, int vel) {
	int i, *p, *q, *r;
	int *pom=niz;
	int x=vel;
	r=niz+vel;
	for(i=0; i<x; i++) {
		if(Fib(*pom)==1) {
			p=pom;
			q=pom+1;
			while(q<pom+vel) {
				*p=*q;
				p++;
				q++;
			}
			vel--;
			pom--;
		}
		pom++;
	}
	return vel;
}


int main() {
	int i,x; 
	int niz[20];
	
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d", &niz[i]);
	}
	ubaci(niz,10) ;
	x=izbaci(niz,20);
	
	printf("Modificirani niz glasi:");
	for(i=0; i<x-1; i++) {
		printf(" %d,", niz[i]);
	}
	printf(" %d.", niz[x-1]) ;
	return 0;
}

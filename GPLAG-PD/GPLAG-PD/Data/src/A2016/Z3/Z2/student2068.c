#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int da_li_je_fibonacci(int x) {
	int a3=0, a2=1, a1=1;
	if(x==1) return 1;
	while(a3<=x) {
		/* ako je npr. x=2^31-5 prekoracit ce se vrijednost inta i preci u negativne brojeve, stoga ako se to desi odmah znamo da broj nije prost */
		if(a3<0) return 0;
		a3=a1+a2;
		if(a3==x) return 1;
		a1=a2;
		a2=a3;
	}
	return 0;
}

int suma_cifara(int x) {
	int i=1, suma=0;
	x=abs(x);
	while(x!=x%i) {
		suma+=(x%(10*i)-x%(i))/i;
		i*=10;
	}
	return suma;
}

void ubaci(int *a, int duzina) {
	int i;
	for(i=duzina-1; i>=0; i--) {
		*(a+2*i)=*(a+i);
	}
	for(i=1; i<=2*duzina; i+=2) {
		*(a+i)=suma_cifara(*(a+i-1));
	}
}

int izbaci(int *a, int duzina) {
	int i, j;
	for(i=0; i<duzina; i++) {
		if(da_li_je_fibonacci(*(a+i))) {
			for(j=i; j<duzina-1; j++) {
				*(a+j)=*(a+j+1);
			}
			duzina--;
			i--;
		}
	}
	return duzina;
}

int main() {
	int a[25], i, duzina=10;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<duzina; i++) {
		scanf("%d", a+i);
	}
	ubaci(a, duzina);
	duzina*=2;
	duzina=izbaci(a, duzina);
	printf("Modificirani niz glasi: ");
	for(i=0; i<duzina; i++) {
		if(i==duzina-1) printf("%d.", a[i]);
		else printf("%d, ", a[i]);
	}
	return 0;
}

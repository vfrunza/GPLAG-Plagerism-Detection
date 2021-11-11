#include <stdio.h>
#define BR_EL 10

int suma_cifara(int broj){
	int suma = 0;
	if(broj < 0)
		broj *= -1;
	while(broj>0) {
		suma+=(broj%10);
		broj/=10;
	}
	return suma;
}


void ubaci(int *niz, int brel) {
	int i, n = brel;
	int j = 0;
	int *p = niz;
	for(i = 0; i < brel*2; i+=2){
        n = brel + j;
		for(; n > i+1; n--)
			p[n] = p[n-1];
		p[i+1] = suma_cifara(p[i]);
		j ++;
	}
}

int fib(int broj){
	int a, b, temp = 0;
	a = b = 1;
	while(b<broj){
		temp = b;
		b += a;
		a = temp;
	}
	return (broj == b);
}

int izbaci(int *niz, int brel) {
	int *p = niz;
	int i=0, j=0;
	for(;i<brel;i++){
		if(fib(p[i])){
			for( j = i; j < brel-1; j ++)
				p[j] = p[j+1];
			brel --;
			i--;
		}
	}
	return brel;	
}

int main() {

	int niz[BR_EL*2],i, n=0;
	printf("Unesite niz od 10 brojeva: ");

	for(i=0;i<BR_EL;i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz, BR_EL);
	n=izbaci(niz,BR_EL*2);
	printf("Modificirani niz glasi: ");
	for(i = 0; i<n; i++){
		if(i != n-1)
			printf("%d, ", niz[i]);
		else
			printf("%d.",niz[i]);
	}
	return 0;
}

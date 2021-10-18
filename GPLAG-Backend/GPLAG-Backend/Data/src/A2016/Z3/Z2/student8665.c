#include <stdio.h>

int SumaCifara(int n) {
	int suma=0;
	if(n<0) n*=(-1);
	while(n>0) {
		suma+=n%10;
		n/=10;
	}
	return suma;
}

void ubaci(int *niz, int vel) {
	int pomocni1[10],pomocni2[10],i,indeks1=0,indeks2=0;
	for(i=0; i<vel; i++) {
		pomocni1[i]=niz[i];
		pomocni2[i]=SumaCifara(niz[i]);
	}
	for(i=0; i<2*vel; i++) {
		if(i%2==0) {
			niz[i]=pomocni1[indeks1];
			indeks1++;
		}
		else {
			niz[i]=pomocni2[indeks2];
			indeks2++;
		}
	
	}
}

int Fibonacci(int n) {
	int broj1=1,broj2=1,broj3=1;
	for(;;) {
		if(n==broj3) return 1;
		if(broj3>n) return 0;
		broj3=broj1+broj2;
		broj1=broj2;
		broj2=broj3;
	}
}
int izbaci(int* niz, int vel) {
	int i,j;
	for(i=0; i<vel; i++) {
		if(Fibonacci(niz[i])==1) {
			for(j=i; j<vel-1; j++)
				niz[j]=niz[j+1];
			vel--;
			i--;
		}
	}
	return vel;
}
int main() {
	int niz[20],i=0,broj=1;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d", &niz[i]);
	}
	ubaci(niz,10);
	broj=izbaci(niz,20);
	if(broj==0) {
		printf("Prazan niz.");
		return 0;
	}
	printf("Modificirani niz glasi: ");
	for(i=0; i<broj-1; i++) {
		printf("%d, ", niz[i]);
	}
	printf("%d.", niz[broj-1]);
	return 0;
}	


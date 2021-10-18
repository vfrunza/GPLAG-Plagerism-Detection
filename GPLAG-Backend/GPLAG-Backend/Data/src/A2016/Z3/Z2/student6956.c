#include <stdio.h>
int Fibonacci(int n) {
	int broj1=1,broj2=1,broj3;
	if(n==1) return 1;
	for(;;) {
		broj3=broj1+broj2;
		broj1=broj2;
		broj2=broj3;
		if(n==broj3) return 1;
		if(broj3>n) return 0;
	}
}
int zbir(int x) {
	int sabrani=0;
	if(x<0) x*=(-1);
	while(x>0) {
		sabrani+=x%10;
		x/=10;
	}
	return sabrani;
}
void ubaci(int *niz,int velicina) {
	int pomocni1[10],pomocni2[10],i,indeks1=0,indeks2=0;
	for(i=0;i<velicina;i++) {
		pomocni1[i]=niz[i];
		pomocni2[i]=zbir(niz[i]);
	}
	for(i=0;i<2*velicina;i++) {
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
int izbaci(int *niz,int velicina) {
	int i,j;
	for(i=0;i<velicina;i++) {
		if(Fibonacci(niz[i])==1) {
			for(j=i;j<velicina-1;j++) 
				niz[j]=niz[j+1];
			velicina--;
			i--;
		}
	}
	return velicina;
}
int main() {
	int i,niz[20],n=1;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++) {
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	n=izbaci(niz,20);
	if(n==0) {
		printf("Prazan niz.");
		return 0;
	}
	printf("Modificirani niz glasi: ");
	for(i=0;i<n-1;i++) {
		printf("%d, ",niz[i]);
	}
	printf("%d.",niz[n-1]);
	return 0;
}

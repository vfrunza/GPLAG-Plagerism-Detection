#include <stdio.h>
#include <math.h>

int suma_cifara(int broj) {
	int k,suma=0;
	if(broj < 0) broj = fabs(broj);
	while(broj!=0) { 
	k=broj%10;
	broj/=10;
	suma+=k;
	}
	return suma;
}

void ubaci(int* niz, int vel) {
	int i,k=0,j=0;
	int niz1[100], niz2[100];
	for(i=0;i<vel;i++) {
		niz1[i]=niz[i];
	}
	for(i=0;i<vel;i++) {
		niz2[i]=suma_cifara(niz[i]);
	}
	for(i=0;i<2*vel;i++) {
		if(i%2==0) {
			niz[i]=niz1[j];
			j++;
		}
		else {
			niz[i]=niz2[k];
			k++;
		}
	}
	
}

int fibonaci(int br) {
	int broj1=1,broj2=1,broj3;
	if(br==1) return 1;
	while(1) {
		broj3=broj1+broj2;
		if(broj3==br) return 1;
		if(broj3>br) return 0;
		broj1=broj2;
		broj2=broj3;
	}
}


 int izbaci(int* niz, int vel) {
	int i,j;
	for(i=0;i<vel;i++) {
		if(fibonaci(niz[i])) {
			for(j=i;j<vel-1;j++) 
				niz[j]=niz[j+1];
			vel--;
			i--;
		}
	}
	return vel;
} 
int main() {
	int niz[20],i,n;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++) {
	scanf("%d", &niz[i]);
	}
	ubaci(niz,10);
	n = izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<n;i++) {
		if(i<n-1) printf("%d, ", niz[i]);
		else printf("%d.", niz[i]);
	}
	return 0;
}

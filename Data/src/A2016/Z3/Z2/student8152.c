#include <stdio.h>

int suma_cifara(int n) {
	int sum=0;
	if(n<0) n*=(-1);
	while(n>0) {
		sum+=n%10;
		n/=10;
	}
	return sum;
}

int da_li_je_fibonacci(int n) {
	int prvi=1,drugi=1,treci=1;
	while(1==1) {
		if(drugi==n) return 1;
		if(drugi>n) return 0;
		treci=prvi+drugi;
		prvi=drugi;
		drugi=treci;
	}
}

void ubaci(int* niz, int velicina) {
	int i,pomocni[100];
	for(i=0;i<velicina;i++) {
		pomocni[i]=niz[i];
	}
	for(i=velicina-1;i>=0;i--) {
		niz[2*i]=pomocni[i];
		niz[2*i+1]=suma_cifara(pomocni[i]);
	}
}

int izbaci(int* niz, int velicina) {
	int i,j;
	for(i=0;i<velicina;i++) {
		if(da_li_je_fibonacci(niz[i])) {
			for(j=i;j<velicina-1;j++)
				niz[j]=niz[j+1];
			velicina--;
			i--;
		}
	}
	return velicina;
}

int main() {
	int niz[20],i,n;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++) {
		scanf("%d", &niz[i]);
	}
	ubaci(niz,10);
	n=izbaci(niz,20);
	if(n==0) printf("Prazan niz.");
	printf("Modificirani niz glasi: ");
	for(i=0;i<n-1;i++) {
		printf("%d, ", niz[i]);
	}
	printf("%d.", niz[n-1]);
	return 0;
}

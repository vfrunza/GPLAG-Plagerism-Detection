#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SumaCifara(int n){
	int suma=0;
	int k;
	do{
		int a=n%10;
		suma+=a;
		n/=10;
	}
	while(n!=0);
	k=abs(suma);
	return k;
}

int fibonacci(int n){
	int f1=1, f2=1;
	int i;
	if(n==1) return 1;
	for(i=0; i<n; i++){
		int f3;
		f3=f1+f2;
		f1=f2;
		f2=f3;
		if(n==f3) return 1;
	}
	return 0;
}

void ubaci(int niz[], int vel){
	int i, j;
	for(i=0; i<vel; i++){
		for(j=vel; j>i+1; j--){
			niz[j]=niz[j-1];
		}
		niz[i+1]=SumaCifara(niz[i]);
		i++;
		vel++;
	}
}

int izbaci (int niz[], int vel){
	int i;
	for(i=0; i<vel; i++){
		if(fibonacci(niz[i])==1){
			int j;
			for(j=i; j<vel-1; j++){
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}
	return vel;
}

int main() {
	int niz[21];
	int i, vel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz, 10);
	vel = izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<vel; i++){
		if(i<vel-1){
			printf("%d, ", niz[i]);
		}
		if(i==vel-1){
			printf("%d.", niz[i]);
		}
	}
	return 0;
}

#include <stdio.h>
#include<math.h>

int cifre(int a){
	return a%10;
}

int pomocna(int broj, int *niz2, int vel2)
{
	int a=0;
	//int pret=0;
	int i;
	int n=0;
	int j=1;
	int pret=1;
	int neg=0;
	if(broj<0) {
		neg=1;
		broj*=-1;
	}
	while(broj!=0){
		n=cifre(broj);
		for(i=0; i<vel2; i++){
			if(n==niz2[i]){
				pret=0;
			}
		}
		if(pret){
			a+= n*j;
			j*=10;
		}
		pret=1;
		broj/=10;
	}
	if(neg) a*=-1;
	return a;
	/*
	

	while(n!=0) {
		a=n%10;
		for(i=0; i<vel2; i++)  {
			if(niz2[i]!=a) break;
			pret=1;
		}
		n/=10;
	}
	if(pret) return 1;
	return 0;*/
	
}
int provjer(int niz2[], int vel2){
	int i=0,j=0; 
	for(i=0; i<vel2; i++){
		if(niz2[i]<0) return 0;
		if(niz2[i]>9) return 0;
	}
	for(i=0; i<vel2-1; i++){
		for(j=i+1; j<vel2; j++)
		if(niz2[i]==niz2[j]) return 0;
	}
	return 1;
}

int izbaci_cifre(int * niz, int vel,int * niz2, int vel2)
{
	int rez;
	//int n;
	int i;
	int pret=0;
	int broj=0;

	for(i=0; i<vel; i++) {
		broj=niz[i];
		rez=pomocna(broj, niz2, vel2);
		niz[i]=rez;
		/*if(rez) {
			for(k=i; k<vel; k++)
				niz[k]=0;
		}*/
	}
	pret=provjer(niz2, vel2);
	return pret;
	
}

int main()
{/*
	int niz[10], niz2[10];
	int rez;
	int vel;
	int i, j;
	printf("ona voli moje redove");
	for(j=0; j<4; j++)
		scanf("%d", &niz[j]);
	scanf("%d", &niz2[j]);
	rez=izbaci_cifre(*niz, *niz2, vel,vel);
	for(i=0; i<4; i++)
		printf("%d", niz[i]);*/
		int brojevi[] = {12345, -12345};
int cifre[] = {3,5};
int i;
izbaci_cifre(brojevi, 2, cifre, 2);
printf("%d %d", brojevi[0], brojevi[1]);
	return 0;
}

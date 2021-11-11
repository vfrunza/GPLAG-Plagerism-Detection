#include <stdio.h>
#include <stdlib.h>
/*Funkcija koja provjerava da li ja broj Fibonaccijev broj*/
int fibonaci (int x) {
	int i=2,j,niz[42],fib=0;
	niz[0]=1;
	niz[1]=2;
	/*Pravljenje niza Fibonaccijevih brojeva*/
	do{
		niz[i]=niz[i-1]+niz[i-2];
		i++;
	}while(niz[i-1]<x);
	/*Poredjenje broja sa clanovima niza Fibonaccijevih brojeva*/
	for(j=0;j<i;j++)
	if (x==niz[j]) {fib=1; break;}
	if (fib) return 1;
	else return 0;
}
/*Funkcija koja nakon uzima clan niza i iza njega ubacuje sumu cifara tog clana niza*/
void ubaci (int niz[],int n) {
	int i,j,y,a=1,noviniz[20]={0},suma=0,x;
	noviniz[0]=niz[0];
	/*Umetanje 0 izmedju svaka dva clana niza*/
	for (i=2;i<2*n;i+=2) {
		for (j=a;j<n;j++){
			noviniz[i]=niz[j]; break;
		} a++;
	}
	/*Suma cifara jednog clana niza postaje sljedeci clan niza*/
	for (i=0;i<2*n;i+=2){
		y=noviniz[i];
		while(abs(y)>0){
			x=abs(y)%10;
			y=y/10;
			suma=suma+x;
			noviniz[i+1]=suma;
		} suma=0;
	}
	for (i=0;i<2*n;i++){
		niz[i]=noviniz[i];
	}
}
/*Funkcija koja iz niza izbacuje sve Fibonaccijeve brojeve*/

int izbaci (int *niz,int n){
	int i,j;
	for (i=0;i<n;i++){
		if (fibonaci(niz[i])==1){
			for (j=i;j<n-1;j++)
				niz[j]=niz[j+1];
			n--;i--;
		}
	}
	return n;
}
/*Main funkcija u kojoj se unosi niz te pozivaju funkcije koje uneseni niz modifikuju*/

int main() {
	int n,niz[20],i,p;
	n=10;
	printf("Unesite niz od %d brojeva: ",n);
	/*Unos niza*/
	for (i=0;i<n;i++) {
		scanf("%d",&niz[i]);
	}
	/*Pozivanje funkcije ubaci a potom i funkcije izbaci*/
	ubaci(niz,n);
	p=izbaci(niz,2*n);
	printf("Modificirani niz glasi: ");
	/*Ipis modifikovanog niza*/
	for (i=0;i<p;i++){
		if (i==p-1)
		printf("%d.",niz[i]);
		else printf("%d, ",niz[i]);
	}

	return 0;
}

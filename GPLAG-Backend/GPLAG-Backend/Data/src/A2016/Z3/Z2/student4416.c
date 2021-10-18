/*Zadatak: Ubaci zbir cifara svakog člana niza nakon tog člana */
/* Izbaci sve članove niza koji su Fibonaccijevi brojevi */
#include <stdio.h>
#include <stdlib.h>
/* Funkcija koja sabira cifre unesenog broja */
int zbir_cifara(int x){
	int zbir=0;
	x=abs(x);
	do{
		zbir=zbir+x%10;
		x=x/10;
	} while (x>0);
	return zbir;
}
/* Funkcija koja u niz ubacuje zbir cifara svakog člana niza nakon tog člana */
void ubaci(int niz[],int n){
	int i,k;
	for (k=1;k<2*n;k=k+2){
		for (i=2*n-2;i>=k-1;i--){
			niz[i+1]=niz[i];
		}
		niz[k]=zbir_cifara(niz[k-1]);
	}
}
/* Funkcija koja izbacuje sve članove niza koji su Fibonaccijevi brojevi */
int izbaci(int niz[],int n){
	int i,j,k,test,fib[46];
	fib[0]=1;
	fib[1]=1;
	for (i=2;i<46;i++)
		fib[i]=fib[i-1]+fib[i-2];
	for (i=0;i<n;i++){
		test=0;
		for (j=0;j<46;j++){
			if (niz[i]==fib[j]){
				test=1;
				break;
			}
		}
		if (test==1){
				for (k=i;k<n-1;k++){
					niz[k]=niz[k+1];
				}
			n--;
			i--;
		}
	}
	return n;
}
int main() {
	int niz[20],i,n;
	for (i=0;i<20;i++)
		niz[i]=0;
	printf("Unesite niz od 10 brojeva: ");
	for (i=0;i<10;i++)
		scanf("%d",&niz[i]);
	for(i=10;i<20;i++)
		niz[i]=0;
	ubaci(niz,10);
	n=izbaci(niz,20);
	printf ("Modificirani niz glasi: ");
	for (i=0;i<n-1;i++)
		printf ("%d, ",niz[i]);
	printf ("%d.",niz[n-1]);
	return 0;
}

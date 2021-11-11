#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int ubaci(int a[], int dim){
	int i, j, k, brojac=0, suma=0, dim2;
	k=0;
	
	/* Pomjeranje clanova niza */
	for(j=0; j<dim; j++){
		for(i=2*dim-1; i>k; i--)
			a[i]=a[i-1];
		k+=2; 
	}
	
	/* Ubacivanje suma cifara clanova u niz */
	for(i=0; i<dim*2; i++){
		brojac=0;
		suma=0;
		if(i%2!=0){
			while(1){
				if(a[i-1]/(int)pow(10,brojac)==0)
					break;
				brojac++;
			}
			for(j=brojac; j>0; j--)
				suma+=((a[i-1]%(int)pow(10,j))/(int)pow(10,j-1));
			a[i]=abs(suma);
		}
	}
	dim2=2*dim;
	return dim2;
}

int izbaci(int a[], int dim){
	int i, fibbroj1, fibbroj2, fibbroj3, j, max;
	fibbroj1=0;
	fibbroj2=1;
	fibbroj3=fibbroj1+fibbroj2;
	
	/* Trazenje najveceg clana niza */
	for(i=0; i<dim; i++){
		if(i==0)
			max=a[i];
		if(a[i]>max)
			max=a[i];
	}
	/* Izbacivanje clanova koji pripadaju Fibonaccijevom nizu */
	while(fibbroj3<=max){
		for(i=0; i<dim; i++){
			if(a[i]==fibbroj3){
			  for(j=i; j<dim-1; j++)
			  	a[j]=a[j+1];
			  dim--;
			  i--;
			}
		}
		fibbroj1=fibbroj2;
		fibbroj2=fibbroj3;
		fibbroj3=fibbroj1+fibbroj2;
	}
	return dim;
}

int main() {
	int a[20], i, dim=0;
	
	/* Unos elemenata niza */
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++){
		scanf("%d", &a[i]);
		dim++;
	}
	/* Pozivanje funkcija */
	dim=ubaci(&a, dim);
	dim=izbaci(&a, dim);
	
	/* Ispis modificiranjog niza */
	if(dim==0)
		printf("Prazan niz");
	if(dim!=0){
		printf("Modificirani niz glasi: ");
		for(i=0; i<dim; i++){
			if(i==dim-1)
				printf("%d.", a[i]);
			else
				printf("%d, ", a[i]);
		}
	}
	return 0;
}


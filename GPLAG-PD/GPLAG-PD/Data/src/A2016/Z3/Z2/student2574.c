#include <stdio.h>
#include <stdlib.h>
void ubaci (int* A, int velicina) {
	int i=0, j=0, Z[10], B[20];
	int zbir=0, TEMP=0;
	for (i=0; i<velicina; i++) {
		Z[i]=A[i];
		B[i]=Z[i];
	}
	j=2;
	/*Pomicanje elemenata za 2 mjesta zbog upisa sume cifara*/
	for (i=1; i<velicina; i++) {
		B[j]=Z[i];
		j=j+2;
	}
	for (i=0; i<2*velicina; i=i+2) {
		zbir=0;
		TEMP=B[i];
		/*Računanje zbira cifara*/
		while (TEMP!=0) {
			zbir=zbir+TEMP%10;
			TEMP/=10;
		}
		B[i+1]=abs(zbir); /*Upisivanje zbira na odgovarajuću poziciju u nizu*/
	}
	/*Postavljanje pokazivača na novi niz iz funkcije ubaci*/
	for (i=0; i<2*velicina; i++) {
		*(A+i)=B[i];
	}
}
int izbaci (int* A, int velicina) {
	int i=0, j=0;
	int x=0, y=0, log=0;
	for (i=0; i<velicina;) {
		x=1;  
		y=1;
		do {
			if (log==1)
				i--;
			log=0;
			if (i<0) 
				i++;
			/*Provjeravanje da li su prvi članovi 1*/
			if (A[i]==x || A[i]==y) {
				for (j=i; j<velicina-1; j++) {
					A[j]=A[j+1];
				}
				i--;
				velicina--;
			}
			/*Formulisanje Fibonaccijevog niza*/
			x=x+y;
			y=x+y;
			if (i<0) {  /*Sprječavanje izlaska van opsega*/
				i++;
				log=1;
			}
		}
		while (A[i]>=x);  /*Izbacivanje članova Fibonaccijevog nizaa*/
		i++;
		if (i==velicina && log==1) /*Sprječavanje krahiranja zbog i<velicina*/
			i--;
	}
	return velicina;
}
int main() {
	int A[20], i=0, velicina=10;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++) {
		scanf ("%d", &A[i]);
	}
	ubaci(A, velicina);
	velicina=izbaci(A, 20);
	printf ("Modificirani niz glasi: ");
	/*Ispisivanje niza*/
	for (i=0; i<velicina; i++) {
		if(i!=velicina-1)	
			printf ("%d, ", A[i]);
			else 
				printf ("%d.", A[i]);
	}
	return 0;
}






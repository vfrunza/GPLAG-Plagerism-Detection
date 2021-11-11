/*Zadatak: Izracunati zbir prostih brojeva od a do b */
#include <stdio.h>
/* Funkcija koja vraća uzastopne proste brojeve */
int daj_prost(){
	static int i=1;
	int j,prost;
	do {
		prost=1;	
		i++;	
		for (j=2;j<i;j++)
			if (i%j==0) {
				prost=0;
				break;
			}		
	} while (prost==0);
	return i;
}
int main() {
	int suma=0,x,k,j,a,b;
/* Unos brojeva a i b */	
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if (a<1)
			printf ("A nije prirodan broj.\n");
		else if (a>=b)	
			printf ("A nije manje od B.\n");
	} while (a<1 || a>=b);
/* Sabiranje prostih brojeva koji pripadaju intervalu */	
	do{
		x=daj_prost();	
		for (j=a+1;j<b;j++) {
			if (j==x)
				suma=suma+j;
		}
	} while (x<b);
	printf ("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);			
	return 0;
}

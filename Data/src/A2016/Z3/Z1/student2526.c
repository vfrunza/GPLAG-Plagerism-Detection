#include <stdio.h>
/* Funkcija koja izbacuje svaki slijedeci prost broj */
int daj_prost() {
	int prost=1,i;
	static int broj=1;
    while(1){
    	broj++;
    	if (broj==2){
    		return broj;
    	}
    	else {
    		for (i=2;i<broj;i++){
    			if (broj%i==0){
    				prost=0;
    				break;
    			}
    		}
    		if (prost){
    			return broj;
    		}
    		else {
    			prost=1;
    		}
    		
    	}
    }
}
int main() {
	int A,B,suma=0,broj=0;
	
	/* Unos intervala */
	
	do{
		printf ("Unesite brojeve A i B: ");
	    scanf ("%d",&A);
	    scanf ("%d",&B);
	    if (A<1){
	    	printf ("A nije prirodan broj.\n");
	    }
	    else if (A>=B){
	    	printf ("A nije manje od B.\n");
	    }
		
	}while(A<1||A>=B || B<=0);
	
	/* Racunanje sume prostih brojeva u intervalu */ 
	
	while (broj<B){
		broj=daj_prost();
		if (broj>A&&broj<B){
			suma+=broj;
		}
	}
	
	/* Ispis sume */ 
	
	printf ("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	
	return 0;
}

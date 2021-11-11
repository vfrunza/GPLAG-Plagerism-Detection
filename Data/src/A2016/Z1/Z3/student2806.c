#include <stdio.h>

int main() {
	char slovo;
	int sumaC=0, sumaB=0, sumaS=0, sumaV=0, sumaP=0; 
	double suma=0, procenat;
	printf("Unesite vozila: ");
	do
	{
	    scanf ("%c", &slovo);
	    if (slovo=='c' || slovo=='C') {
	        sumaC++;
	        suma++;
	        
	    } else if (slovo=='b' || slovo=='B') {
	        sumaB++;
	        suma++;
	        
	    } else if (slovo=='s' || slovo=='S') {
	        sumaS++;
	        suma++;
	        
	    } else if (slovo=='v' || slovo=='V') {
	        sumaV++;
	        suma++;
	        
	    } else if (slovo=='p' || slovo=='P') {
	        sumaP++;
	        suma++;
	        
	    } else if (slovo=='k' || slovo=='K') {
	    	break;
	    } else {
	    	printf ("Neispravan unos\n");
	    }
	} while (slovo!='k' || slovo!='K');

	printf ("Ukupno evidentirano %g vozila.\n", suma);
	if (suma==0) {
		printf ("Najpopularnija boja je crna (0.00%%).");
	} else if (sumaC>=sumaB && sumaC>=sumaS && sumaC>=sumaV && sumaC>=sumaP) {
		procenat=sumaC*100/suma;
		printf ("Najpopularnija boja je crna (%.2lf%%).", procenat);
	} else if (sumaB>=sumaC && sumaB>=sumaS && sumaB>=sumaV && sumaB>=sumaP) {
		procenat=sumaB*100/suma;
		printf ("Najpopularnija boja je bijela (%.2lf%%).", procenat);
	} else if (sumaS>=sumaC && sumaS>=sumaB && sumaS>=sumaV && sumaS>=sumaP) {
		procenat=sumaS*100/suma;
		printf ("Najpopularnija boja je siva (%.2lf%%).", procenat);
	} else if (sumaV>=sumaC && sumaV>=sumaS && sumaV>=sumaB && sumaV>=sumaP) {
		procenat=sumaV*100/suma;
		printf ("Najpopularnija boja je crvena (%.2lf%%).", procenat);
	} else if (sumaP>=sumaC && sumaP>=sumaS && sumaP>=sumaV && sumaP>=sumaB) {
		procenat=sumaP*100/suma;
		printf ("Najpopularnija boja je plava (%.2lf%%).", procenat);
	} 
return 0;
}
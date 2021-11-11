
#include <stdio.h>

int main() {
	
	int sumaC=0, sumaB=0, sumaS=0, sumaV=0, sumaP=0;
	float sumauk=0, pr;
	char a;
	
	printf ("Unesite vozila: ");
	
	do { 
		scanf("%c", &a);
		
		if (a=='k' || a=='K')break;
		
		else if(a=='c' || a=='C') {
			sumaC++;
			sumauk++;
		} else if (a=='b' || a=='B') {
			sumaB++;
			sumauk++;
		} else if (a=='s' || a=='S') {
			sumaS++;
			sumauk++;
		} else if (a=='v' || a=='V') {
			sumaV++;
			sumauk++;
		} else if (a=='p' || a=='P') {
			sumaP++;
			sumauk++;
		} else { 
			printf("Neispravan unos\n");
		}
		
		
	}  while(a!='k' || a!='K'); 
	
	
		printf("Ukupno evidentirano %.f vozila.\n",sumauk);
	
		if(sumauk==0) { 
			printf("Najpopularnija boja je crna (0.00%%).");
		} else if (sumaC>=sumaB && sumaC>=sumaS && sumaC>=sumaV && sumaC>=sumaP) { 
			pr=(sumaC*100)/sumauk;
			printf("Najpopularnija boja je crna (%.2f%%).", pr);
		} else if (sumaB>=sumaC && sumaB>=sumaS && sumaB>=sumaV && sumaB>=sumaP) { 
			pr=(sumaB*100)/sumauk;
			printf("Najpopularnija boja je bijela (%.2f%%).", pr);
		} else if (sumaS>=sumaB && sumaS>=sumaC && sumaS>=sumaV && sumaS>=sumaP) { 
			pr=(sumaS*100)/sumauk;
			printf("Najpopularnija boja je siva (%.2f%%).", pr);
		} else if (sumaV>=sumaB && sumaV>=sumaS && sumaV>=sumaC && sumaV>=sumaP) { 
			pr=(sumaV*100)/sumauk;
			printf("Najpopularnija boja je crvena (%.2f%%).", pr);
		} else if (sumaP>=sumaC && sumaP>=sumaB && sumaP>=sumaS && sumaB>=sumaV) { 
			pr=(sumaP*100)/sumauk;
			printf("Najpopularnija boja je plava (%.2f%%).", pr);
		}
		


	
	return 0;
}
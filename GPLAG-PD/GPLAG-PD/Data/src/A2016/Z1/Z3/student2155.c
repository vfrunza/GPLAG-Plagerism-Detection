#include <stdio.h>

int main() {
	char i;
	float C,B,S,V,P,suma;
	C = 0;
	B = 0;
	S = 0;
	V = 0;
	P = 0;
	suma = 0;
	float cp,bp,sp,vp,pp;
	printf("Unesite vozila: ");
	do{
		 greska: scanf("%c", &i);
		if(i == 'c' || i == 'C' || i == 'b' || i =='B' || i == 's' || i == 'S' || i == 'v' || i == 'V' || i == 'p' || i == 'P'){
		if(i == 'C' || i == 'c'){
			C++;
			suma++;
		}
		if(i == 'b' || i == 'B'){
			B++;
			suma++;
		}
		if(i == 's' || i == 'S'){
			S++;
			suma++;
		}
		if(i == 'v' || i == 'V'){
			V++;
			suma++;
		}
		if(i == 'p' || i == 'P'){
			P++;
			suma++;
		}}else if(i !='k' && i != 'K'){
			printf("Neispravan unos\n");
			goto greska;
		}
		
			
		}while(i != 'k' && i != 'K');
		if(C != 0)cp = (C/suma)*100;
		else cp = 0;
		if(B != 0) bp = (B/suma)*100;
		else bp == 0;
		if (S != 0)sp = (S/suma)*100;
		else sp == 0;
		if(V != 0)vp = (V/suma)*100;
		else vp == 0;
		if(P != 0)pp = (P/suma)*100;
		else pp == 0;
		printf("Ukupno evidentirano %g vozila.", suma);
	if(C >= B && C >= S && C >= V && C >= P ){
	printf("\nNajpopularnija boja je crna (%.2f%%).", cp);
	
	}else if(B >= S && B >= V && B >= P){
		printf("\nNajpopularnija boja je bijela (%.2f%%).", bp);
	}else if(S >= V && S >= P  ){
		printf("\nNajpopularnija boja je siva (%.2f%%).", sp);
	}else if(V >= P){
		printf("\nNajpopularnija boja je crvena (%.2f%%).", vp);
	}else{
		printf("\nNajpopularnija boja je plava (%.2f%%).", pp);
	}
	return 0;
	}

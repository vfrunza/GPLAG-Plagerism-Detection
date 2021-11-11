#include <stdio.h>
int main() {
    char A;
    float C=0, B=0, S=0, V=0, P=0, I=0;
    float U;
    printf ("Unesite vozila: ");
    do {
       scanf("%c", &A);
		if (A=='c' || A=='C'){
		I++;C++;}
		else if (A=='b' || A=='B'){
		I++;B++;}
		else if (A=='s' || A=='S'){
		I++;S++;}
		else if (A=='v' || A=='V'){
		I++;V++;}
		else if (A=='p' || A=='P'){
		I++;P++;}
		else if (A=='k' || A=='K');
		else{
        printf ("Neispravan unos\n");}
		}
		while (A!='k' && A!='K');
		printf ("Ukupno evidentirano %g vozila.",I);
		if (I==0){
		    printf ("\nNajpopularnija boja je crna (0.00%%).");
		return 0;}
		
		if (C>=B && C>=S && C>=V && C>=P){
			U=(C/I)*100;
			printf ("\nNajpopularnija boja je crna (%.2f%%).",U);
			return 0;
		}
		if (B>=C && B>=S && B>=V && B>=P){
			U=(B/I)*100;
			 printf ("\nNajpopularnija boja je bijela (%.2f%%).",U);
			 return 0;
		}
		if (S>=B && S>=C && S>=V && S>=P){
			U=(S/I)*100;	
			 printf ("\nNajpopularnija boja je siva (%.2f%%).",U);
			 return 0;
		}
		if (V>=B && V>=S && V>=C && V>=P){
			U=(V/I)*100;	
			 printf ("\nNajpopularnija boja je crvena (%.2f%%).",U);
			 return 0;
		}
		if (P>=B && P>=S && P>=V && P>=C){
			U=(P/I)*100;	
			 printf ("\nNajpopularnija boja je plava (%.2f%%).",U);
			 return 0;
		}
	return 0;
}
		




#include <stdio.h>


int main() 
{
	int brUK=0, brC=0, brB=0, brS=0, brV=0, brP=0;

	int max;
	float max1, br;
    float pr=0;
	char znak;
	int crna=1,bijela=0,siva=0,crvena=0,plava=0;
	printf("Unesite vozila: ");

	do
	{


		scanf("%c",&znak);

		if(znak=='C' || znak=='c') {brUK++; brC++;}
		else if(znak=='B' || znak=='b') {brUK++; brB++;}
		else if(znak=='S' || znak=='s') {brUK++; brS++;}
		else if(znak=='V' || znak=='v') {brUK++; brV++;}
		else if(znak=='P' || znak=='p') {brUK++; brP++;}
		else if(znak=='K' || znak=='k') {break;}
		else{printf("Neispravan unos\n");}
	} while(1==1);
	max=brC;
	if(brB>max) {max=brB; crna=0; bijela=1; siva=0; crvena=0; plava=0;}
	if(brS>max) {max=brS; crna=0; bijela=0; siva=1; crvena=0; plava=0;}
	if(brV>max) {max=brV; crna=0; bijela=0; siva=0; crvena=1; plava=0;}
	if(brP>max) {max=brP; crna=0; bijela=0; siva=0; crvena=0; plava=1;}
	printf("Ukupno evidentirano %d vozila.",brUK);
	max1=max; br=brUK;
	pr=(max1*100)/br;
    if(brUK==0) pr=0;
	if(crna==1) printf("\nNajpopularnija boja je crna (%.2f%%).",pr);
	else if(bijela==1) printf("\nNajpopularnija boja je bijela (%.2f%%).",pr);
	else if(siva==1) printf("\nNajpopularnija boja je siva (%.2f%%).",pr);
	else if(crvena==1) printf("\nNajpopularnija boja je crvena (%.2f%%).",pr);
	else printf("\nNajpopularnija boja je plava (%.2f%%).",pr);


	return 0;
}

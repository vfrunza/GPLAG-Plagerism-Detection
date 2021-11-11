#include <stdio.h>

int main() {
	char slovo;
	float brcr=0, brpl=0, brsiv=0, brb=0, brcrv=0;
	int bruk=0;
	float cp, pp, bp, sp, crvp;
	printf ("Unesite vozila: ");
	scanf ("%c", &slovo);

	while (slovo!='k'&& slovo!='K') {
	if (slovo=='c' || slovo=='C')
	{brcr++;
	bruk++;}
	else if (slovo=='b' || slovo=='B')
	{brb++;
	bruk++;}
	else if (slovo=='s' || slovo=='S')
	{brsiv++;
	bruk++;}
	else if (slovo=='p' || slovo=='P')
	{brpl++;
	bruk++;}
	else if (slovo=='v' || slovo=='V')
	{brcrv++;
	bruk++;}
	else {printf("Neispravan unos\n");}
	scanf ("%c", &slovo);
	}
	if(bruk!=0)	{
		cp=(brcr/bruk)*100;
		bp=(brb/bruk)*100;
		sp=(brsiv/bruk)*100;
		crvp=(brcrv/bruk)*100;
		pp=(brpl/bruk)*100;}
	else {
		cp=0;
		bp=0;
		sp=0;
		crvp=0;
		pp=0;}
	
	printf ("Ukupno evidentirano %d vozila.\n", bruk);
	if (cp>=bp && cp>=sp && cp>=crvp && cp>=pp){
	printf("Najpopularnija boja je crna (%.2f%%).", cp);}
	else if (bp>cp && bp>=sp && bp>=crvp && bp>=pp)
	printf("Najpopularnija boja je bijela (%.2f%%).", bp);
	else if (sp>cp && sp>bp && sp>=crvp && sp>=pp)
	printf("Najpopularnija boja je siva (%.2f%%).", sp);
	else if (crvp>cp && crvp>bp && crvp>sp && crvp>=pp)
	printf("Najpopularnija boja je crvena (%.2f%%).", crvp);
	else 
	printf("Najpopularnija boja je plava (%.2f%%).", pp);
	
	

	
	return 0;
}

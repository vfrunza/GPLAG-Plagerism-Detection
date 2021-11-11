#include <stdio.h>

int main ()
{
	char boja;
	int brojacC=0,brojacB=0, brojacS=0, brojacV=0, brojacP=0, max=0, uk=0;
	float postotak;
	printf ("Unesite vozila: ");
	do {
	scanf ("%c", &boja);
	if (boja !='c' && boja!='C' && boja!='b' && boja!='B' && boja!='s' && boja!='S' && boja!='v' && boja!='V' && boja!='p' && boja!='P' && boja!='k' && boja!='K')
	{
	    printf ("Neispravan unos\n");
	}

if ((boja == 'C') || (boja == 'c')) brojacC++; 
if ((boja == 'B') || (boja == 'b')) brojacB++;
if ((boja == 'S') || (boja == 's')) brojacS++;
if ((boja == 'V') || (boja == 'v')) brojacV++;
if ((boja == 'P') || (boja == 'p')) brojacP++;

} while (boja!='k' && boja!='K');


uk=brojacC+brojacB+brojacS+brojacV+brojacP;

printf ("Ukupno evidentirano %d vozila.\n", uk);


if (brojacC>=brojacB && brojacC>=brojacS && brojacC>=brojacV && brojacC>=brojacP) max=brojacC;
else if (brojacB>brojacC && brojacB>=brojacS && brojacB>=brojacV && brojacB>=brojacP) max=brojacB;
else if (brojacS>brojacC && brojacS>brojacB && brojacS>=brojacV && brojacS>=brojacV) max=brojacS;
else if (brojacV>brojacC && brojacV>brojacB && brojacV>brojacS && brojacV>=brojacP) max=brojacV;
else if (brojacP>brojacC && brojacP>brojacB && brojacP>brojacS && brojacP>brojacV) max=brojacP;

postotak=((float)max/uk)*100;

if (max>=1)
{
if (max==brojacC) 
{printf ("Najpopularnija boja je crna (%.2f%%).", postotak);}
else if (max==brojacB)
{printf ("Najpopularnija boja je bijela (%.2f%%).", postotak);}
else if (max==brojacS)
{printf ("Najpopularnija boja je siva (%.2f%%).", postotak);}
else  if (max==brojacV)
{printf ("Najpopularnija boja je crvena (%.2f%%).", postotak);}
else if (max==brojacP)
{printf ("Najpopularnija boja je plava (%.2f%%).", postotak);}
}

else { printf ("Najpopularnija boja je crna (0.00%%).");}
return 0;


}



#include <stdio.h>

int main() {
	char bo;
	double l,su;
	int max, cr, bi, si, vv, pl;
	su=0;
	cr=0;
	bi=0;
	si=0;
	vv=0;
	pl=0;
	
	printf ("Unesite vozila: ");
	
	do {

	scanf ("%c", &bo);
	if (bo=='c' || bo=='C' || bo=='b' || bo=='B' || bo=='s' || bo=='S' || bo=='v' || bo=='V' || bo=='p' || bo=='P' || bo=='k' || bo=='K')
	{
		if (bo=='c' || bo=='C')
		{
			cr++;
		}
		
		else if (bo=='b' || bo=='B')
		{
			bi++;
		}
		
		else if (bo=='s' || bo=='S')
		{
			si++;
		}
		
		else if (bo=='v' || bo=='V')
		{
			vv++;
		}
		
		else if (bo=='p' || bo=='P')
		
		{
			pl++;
		}
		
	}
	
	
	else if (bo!='c' || bo!='C' || bo!='b' || bo!='B' || bo!='s' || bo!='S' || bo!='v' || bo!='V' || bo!='p' || bo!='P' || bo!='k' || bo!='K')
	{
		printf ("Neispravan unos\n");
	}
	
	}
	
	while (bo!='k' && bo!='K');
	
	su=cr+bi+si+vv+pl;
	
	max=cr;
	if (bi>max) {max=bi;}
	if (si>max) {max=si;}
	if (vv>max) {max=vv;}
	if (pl>max) {max=pl;}
	
	l=(max*100)/su;
	
	if  (su==0)
	{
		printf ("Ukupno evidentirano 0 vozila.\nNajpopularnija boja je crna (0.00%).");
		return 0;
	}
	else {
		printf ("Ukupno evidentirano %g vozila. ", su);
	}
	if (max==cr)
	{
		printf ("\nNajpopularnija boja je crna (%.2f%).", l);
	}
	else if (max==bi)
	{
		printf ("\nNajpopularnija boja je bijela (%.2f%).", l);
	}
	else if (max==si)
	{
		printf ("\nNajpopularnija boja je siva (%.2f%).", l);
	}
	else if (max==vv)
	{
		printf ("\nNajpopularnija boja je crvena (%.2f%).", l);
	}
	else if (max==pl)
	{
		printf ("\nNajpopularnija boja je plava (%.2f%).", l);
	}
	
	
	
	
	
	
	return 0;
}

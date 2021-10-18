#include <stdio.h>

int main() {
	char x;
	int cr, bi, si, crv, pl, n, q;
	int max;
	double Bmax, s, y;
	cr=0;
	bi=0; 
	si=0;
	crv=0; 
	pl=0; 
	n=0; q=1;
	printf("Unesite vozila: ");
	while (q>0)
	{
		scanf ("%c", &x);
		if (x=='C'|| x=='c') 
		{
			cr=cr+1; 
			n=n+1;
		}
		else if (x=='B'||x=='b') 
		{
			bi=bi+1;
			n=n+1;
		}
		else if (x=='S'||x=='s') 
		{
			si=si+1; 
			n=n+1;
		}
		else if (x=='V'||x=='v') 
		{
			crv=crv+1;
			n=n+1;
		}
		else if (x=='P'||x=='p') 
		{
			pl=pl+1; 
			n=n+1;
		}
		else if (x=='K'||x=='k') 
		{
			break;
		}
		else 
		{
			printf ("Neispravan unos\n");
		}
	}
	printf ("Ukupno evidentirano %d vozila.\n", n);
	max=cr;
	if (max<bi) {max=bi;}
	if (max<si) {max=si;}
	if (max<crv) {max=crv;}
	if (max<pl) {max=pl;}
	printf ("Najpopularnija boja je ");
	if (max==cr) {printf ("crna ");}
	else if (max==bi) {printf ("bijela ");}
	else if (max==si) {printf ("siva ");}
	else if (max==crv) {printf ("crvena ");}
	else if (max==pl) {printf ("plava ");}
	if (n==0)
	{
		s=1;
	}
	else
	{
		s=n;
	}
	Bmax=max;
	y=(Bmax/s)*100;
	printf ("(%.2f%%).", y);
	return 0;
}

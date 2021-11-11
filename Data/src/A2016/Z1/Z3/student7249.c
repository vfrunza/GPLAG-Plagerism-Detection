#include <stdio.h>

int main() {
	char automobil='A';
	double NoC=0, NoB=0, NoS=0, NoV=0, NoP=0, procent, UkNoEvidVozila=0;
	printf("Unesite vozila: ");
	while(automobil!='K' || automobil!='k')
	{ 	scanf("%c", &automobil);
		if(automobil=='c' || automobil=='C')
		{NoC++; UkNoEvidVozila++;}
		else if(automobil=='b' || automobil=='B')
	    {NoB++; UkNoEvidVozila++;}
	    else if(automobil=='s' || automobil=='S')
	    {NoS++; UkNoEvidVozila++;}
	    else if(automobil=='v' || automobil=='V')
	    {NoV++; UkNoEvidVozila++;}
	    else if(automobil=='p' || automobil=='P')
	    {NoP++; UkNoEvidVozila++;}
	    else if(automobil=='k' || automobil=='K') break;
	    else {printf("Neispravan unos\n");}
	}
	if(UkNoEvidVozila==0)
	{
		printf("Ukupno evidentirano %g vozila.", UkNoEvidVozila);
		printf("\nNajpopularnija boja je crna (0.00%%).");
	}
	else 
	{
		printf("Ukupno evidentirano %g vozila.", UkNoEvidVozila);
		if(NoC>=NoB && NoC>=NoS && NoC>=NoV && NoC>=NoP)
		{
			procent=(100*NoC)/UkNoEvidVozila;
			printf("\nNajpopularnija boja je crna (%.2f%%).", procent);
		}
		else if(NoB>=NoC && NoB>=NoS && NoB>=NoV && NoB>=NoP)
		{
			procent=(100*NoB)/UkNoEvidVozila;
			printf("\nNajpopularnija boja je bijela (%.2f%%).", procent);
		}
		else if(NoS>=NoC && NoS>=NoB && NoS>=NoV && NoS>=NoP)
		{
			procent=(100*NoS)/UkNoEvidVozila;
			printf("\nNajpopularnija boja je siva (%.2f%%).", procent);
		}
		else if(NoV>=NoC && NoV>=NoB && NoV>=NoS && NoV>=NoP)
		{
			procent=(100*NoV)/UkNoEvidVozila;
			printf("\nNajpopularnija boja je crvena (%.2f%%).", procent);
		}
		else if(NoP>=NoC && NoP>=NoB && NoP>=NoV && NoP>=NoS)
		{
			procent=(100*NoP)/UkNoEvidVozila;
			printf("\nNajpopularnija boja je plava (%.2f%%).", procent);
		}
	}
	return 0;
}

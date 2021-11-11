#include <stdio.h>

int main() 
{
	char c;
	int x=0, i;
	float C=0, B=0, S=0, V=0, P=0; 
	float CC, BB, SS, VV, PP;
	
	printf("Unesite vozila: ");
	
	for(i=0; i<100; i++)
	{
		scanf("%c", &c);
		
		if(c=='C' || c=='c') 
		{
			C++;
			x++;
		}
		else if(c=='B' || c=='b')
		{
			B++;
			x++;
		}
		else if(c=='S' || c=='s') 
		{
			S++;
			x++;
		}
		else if(c=='V' || c=='v') 
		{
			V++;
			x++;
		}
		else if(c=='P' || c=='p') 
		{
			P++;
			x++;
		}
		else if(c=='k' || c=='K') break;
		
		else printf("Neispravan unos\n");
		
	}
	
	printf("Ukupno evidentirano %d vozila.", x);
	printf("\n");
	
	CC=C/(C+B+S+V+P)*100;
	BB=B/(C+B+S+V+P)*100;
	SS=S/(C+B+S+V+P)*100;
	VV=V/(C+B+S+V+P)*100;
	PP=P/(C+B+S+V+P)*100;
	
	if(x==0) printf("Najpopularnija boja je crna (0.00%%).");
	else if(CC>=BB && CC>=VV && CC>=SS && CC>=PP) printf("Najpopularnija boja je crna (%.2f%%).", CC);
	else if(BB>=CC && BB>=VV && BB>=SS && BB>=PP) printf("Najpopularnija boja je bijela (%.2f%%).", BB);
	else if(SS>=CC && SS>=BB && SS>=VV && SS>=PP) printf("Najpopularnija boja je siva (%.2f%%).", SS);
	else if(VV>=CC && VV>=BB && VV>=SS && VV>=PP) printf("Najpopularnija boja je crvena (%.2f%%).", VV);
	else if(PP>=CC && PP>=BB && PP>=VV && PP>=SS) printf("Najpopularnija boja je plava (%.2f%%).", PP);
	
	return 0;
}

#include <stdio.h>

int main() 
{
	int C=0, B=0, S=0, V=0, P=0, ukupno;
	char K;
	printf("Unesite vozila: ");
	while((K=getchar())!='K' && K!='k')
	{
		if(K=='C' || K=='c') 
		{
			C++;
		}
		else if(K=='B' || K=='b')
		{
			B++;
		}
		else if(K=='S' || K=='s')
		{
			S++;
		}
		else if(K=='V' || K=='v')
		{
			V++;
		}
		else if(K=='P' || K=='p')
		{
			P++;
		}
		else
		{
			printf("Neispravan unos\n");
		}
	}
	ukupno=C+B+S+V+P;
	printf("Ukupno evidentirano %d vozila.\n", ukupno);
	if(ukupno==0)
	{
		printf("Najpopularnija boja je crna (0.00%%).");
	}
	else if(C>=B && C>=S && C>=V && C>=P)
	{
		printf("Najpopularnija boja je crna (%.2f%%).", (float)C/ukupno*100);
	}
	else if(B>=C && B>=S && B>=V && B>=P)
	{
		printf("Najpopularnija boja je bijela (%.2f%%).", (float)B/ukupno*100);
	}
	else if(S>=C && S>=B && S>=V && S>=P)
	{
		printf("Najpopularnija boja je siva (%.2f%%).", (float)S/ukupno*100);
	}
	else if(V>=C && V>=B && V>=S && V>=P)
	{
		printf("Najpopularnija boja je crvena (%.2f%%).", (float)V/ukupno*100);
	}
	else if(P>=C && P>=B && P>=S && P>=V)
	{
		printf("Najpopularnija boja je plava (%.2f%%).", (float)P/ukupno*100);
	}
	
	return 0;
}

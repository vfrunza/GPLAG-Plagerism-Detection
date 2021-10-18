#include <stdio.h>

int main() {
	int C=0, S=0, B=0, V=0, P=0;
	int i=0, brojac=0;
	char boja;
	
	printf("Unesite vozila: ");
	do
	{
		scanf("%c", &boja);
		i++;
		if(boja=='c' || boja=='C') C++;
		else if(boja=='s' || boja=='S') S++;
		else if(boja=='b' || boja=='B') B++;
		else if(boja=='p' || boja=='P') P++;
		else if(boja=='v' || boja=='V') V++;
		else if(boja!='C' && boja!='c' && boja!='S' && boja!='s' && boja!='b' && boja!='B' && boja!='V' && boja!='v' && boja!='P' && boja!='p' &&
		boja!='k' && boja!='K') brojac++;
		
		
	}while((boja=='C' || boja=='c' || boja=='S' || boja=='s' || boja=='b' || boja=='B' || boja=='V' || boja=='v' || boja=='P' || boja=='p') && ( boja!='k' || boja!='K'));
	
	i--;

	while(brojac>0)
	{
		printf("Neispravan unos\n");
		brojac--;
	}
	
	
	printf("Ukupno evidentirano %d vozila.", i);
	
	float j=i*1.0;
	
	printf("\n");
	
	
	if(C>=S && C>=B && C>=V && C>=P)
	{
		if(i==0) printf("Najpopularnija boja je crna (0.00%).");
		else printf("Najpopularnija boja je crna (%.2f%%).",(C/j)*100);
	}
	else if(S>=C && S>=B && S>=V && S>=P) 
	{
		if(i==0) printf("Najpopularnija boja je siva (0.00%).");
		else printf("Najpopularnija boja je siva (%.2f%%).", (S/j)*100);
	}
	else if(B>=C && B>=S && B>=V && B>=P)
	{
		if(i==0) printf("Najpopularnija boja je bijela (0.00%).");
		else printf("Najpopularnija boja je bijela (%.2f%%).", (B/j)*100);
	}
	else if(V>=C && V>=S && V>=B && V>=P) 
	{
		if(i==0) printf("Najpopularnija boja je crvena (0.00%).");
		else printf("Najpopularnija boja je crvena (%.2f%%).", (V/j)*100);
	}
	else 
	{
		if(i==0) printf("Najpopularnija boja je plava (0.00%).");
		else printf("Najpopularnija boja je plava (%.2f%%).", (P/j)*100);
	}
	
	return 0;
}

#include <stdio.h>

int main() {
	int C=0,B=0,S=0,V=0,P=0,E;
	char c;
	printf("Unesite vozila: ");
	while(1)
	{
		scanf("%c",&c);
		if(c=='K'||c=='k'||c=='\n') break;
		if(c=='C'||c=='c') C++;
		else if(c=='B'||c=='b') B++;
		else if(c=='S'||c=='s') S++;
		else if(c=='P'||c=='p') P++;
		else if(c=='V'||c=='v') V++;
		else printf("Neispravan unos\n");
	}
	
	E = C+B+S+P+V;
	printf("Ukupno evidentirano %d vozila.\n",E);
	E = 0;
	if(C>E) E=C;
	if(B>E) E=B;
	if(S>E) E=S;
	if(P>E) E=P;
	if(V>E) E=V;
	if(E==0) 
	{
		printf("Najpopularnija boja je crna (0.00%%).");
		return 0;
	}
	if(C==E) 
	{
		printf("Najpopularnija boja je crna (%.2f%%).",(double)C/(C+S+B+V+P)*100);
	}
	else if(B==E) 
	{
		printf("Najpopularnija boja je bijela (%.2f%%).",(double)B/(C+S+B+V+P)*100);
	}
	else 	if(S==E) 
	{
		printf("Najpopularnija boja je siva (%.2f%%).",(double)S/(C+S+B+V+P)*100);
	}
	
	else	if(V==E) 
	{
		printf("Najpopularnija boja je crvena (%.2f%%).",(double)V/(C+S+B+V+P)*100);
	}
	else 	if(P==E) 
	{
		printf("Najpopularnija boja je plava (%.2f%%).",(double)P/(C+S+B+V+P)*100);
	}
	
	return 0;
}

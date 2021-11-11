#include <stdio.h>

int main() 
{
	int brC=0,brP=0,Uk=0,brV=0,brB=0,brS=0;
	char V,C,P,c,p,A,B,b,S,s;
	float ProcV,ProcC,ProcP,ProcB,ProcS;
	
	printf("Unesite vozila: ");
	while(1)
	{
		scanf("%c",&A);
		if(A=='K' || A=='k')
			break;
		else if(A=='C' || A=='c')
			brC++;
		else if(A=='P' || A=='p')
			brP++;
		else if(A=='V' || A=='v')	
			brV++;
		else if(A=='B' || A=='b')
			brB++;
		else if(A=='S' || A=='s')
			brS++;	
		else
			printf("Neispravan unos\n");
	}
	Uk=brS+brB+brC+brP+brV;
	printf("Ukupno evidentirano %d vozila.\n",Uk);
	
	if(brV>brP && brV>brC && brV>brB && brV>brS)
	{
		ProcV=((float)brV/Uk)*100;
		printf("Najpopularnija boja je crvena (%.2f%%).",ProcV);
	}
	else if(brC>brP && brC>brV && brC>brB && brC>brS)
	{
		ProcC=((float)brC/Uk)*100;
		printf("Najpopularnija boja je crna (%.2f%%).",ProcC);
	}
	else if(brP>brV && brP>brC && brP>brB && brP>brS)
	{
		ProcP=((float)brP/Uk)*100;
		printf("Najpopularnija boja je plava (%.2f%%).",ProcP);
	}
	else if(brB>brV && brB>brC && brB>brP && brB>brS)
	{
		ProcB=((float)brB/Uk)*100;
		printf("Najpopularnija boja je bijela (%.2f%%).",ProcB);
	}
	else if(brS>brV && brS>brC && brS>brB && brS>brP)
	{
		ProcS=((float)brS/Uk)*100;
		printf("Najpopularnija boja je siva (%.2f%%).",ProcS);
	}
	else if(Uk==0)
	{
		Uk++;
		ProcC=((float)brC/Uk)*100;
		printf("Najpopularnija boja je crna (%.2f%%).",ProcC);
	}
	else if(brC==brS || brC==brP || brC==brB || brC==brV)
	{
		ProcC=((float)brC/Uk)*100;
		printf("Najpopularnija boja je crna (%.2f%%).",ProcC);
	}
	else if(brS==brC || brS==brP || brS==brB || brS==brV)
	{
		ProcS=((float)brS/Uk)*100;
		printf("Najpopularnija boja je siva (%.2f%%).",ProcS);	
	}

	return 0;
}

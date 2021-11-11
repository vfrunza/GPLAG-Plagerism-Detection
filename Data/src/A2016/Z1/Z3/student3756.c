#include <stdio.h>
#include <math.h>
#define eps 0.0001
int main() {

float pcrna, pbijela, psiva, pcrvena, pplava, maks=0;
int ukupno, crna=0, bijela=0, siva=0, crvena=0, plava=0; 
char slovo;
printf("Unesite vozila: ");
	while ((slovo=getchar())!='K' && slovo!='k')
{	
	if(slovo == 'c' || slovo == 'C')
	crna++;
	else if(slovo == 'b' || slovo == 'B')
	bijela++;
	else if(slovo == 's' || slovo == 'S')
	siva++;
	else if(slovo == 'v' || slovo == 'V')
	crvena++;
	else if(slovo == 'p' || slovo == 'P')
	plava++;
	else 
	{ printf("Neispravan unos\n");
	}
}
	
	ukupno = crna + bijela + siva + crvena + plava;

	printf("Ukupno evidentirano %d vozila.\n",ukupno);
	
	pcrna = (crna/(float)ukupno)*100;
	pbijela = (bijela/(float)ukupno)*100;
	psiva = (siva/(float)ukupno)*100;
	pcrvena = (crvena/(float)ukupno)*100; 
	pplava = (plava/(float)ukupno)*100;
	
	if(ukupno==0)
	printf("Najpopularnija boja je crna (0.00%%).");
	
	else
	{if(pcrna>maks)
	maks=pcrna;
	if(pbijela>maks)
	maks=pbijela;
	if(psiva>maks)
	maks=psiva;
	if(pcrvena>maks)
	maks=pcrvena;
	if (pplava>maks)
	maks=pplava;
	}
	if (fabs(maks-pcrna)<eps)
	printf("Najpopularnija boja je crna (%.2f%%).", pcrna);
	else if(fabs(maks-pbijela)<eps)	
	printf("Najpopularnija boja je bijela (%.2f%%).", pbijela);
	else if(fabs(maks-psiva)<eps)
	printf("Najpopularnija boja je siva (%.2f%%).", psiva);
	else if(fabs(maks-pcrvena)<eps)
	printf("Najpopularnija boja je crvena (%.2f%%).", pcrvena);
	else if(fabs(maks-pplava)<eps)
	printf("Najpopularnija boja je plava (%.2f%%).", pplava);
		
		
	return 0;
}





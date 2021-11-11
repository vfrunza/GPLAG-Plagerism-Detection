#include <stdio.h>

int main() 
{
	char a;
	int suma=0, sumab=0, sumav=0, sumac=0, sumap=0, sumas=0;
	printf ("Unesite vozila: ");
	for(;;)
	{
		scanf("%c", &a);
	    if (a!='b' && a!='B' && a!='C'&& a!='c' && a!='S' && a!='s' && a!='V' && a!='v' && a!='P' && a!='p' && a!='k' && a!='K')
	    {printf("Neispravan unos\n");}
		if (a=='k' || a=='K') break;
		if (a=='b' || a=='B' || a=='C'|| a=='c' || a=='S' || a=='s' || a=='V' || a=='v' || a=='P' || a=='p') 
		{suma++;}
		if (a=='b' || a=='B') 
		{sumab++;}
		if (a=='v' || a=='v') 
		{sumav++;}
		if (a=='C' || a=='c') 
		{sumac++;}
		if (a=='S' || a=='s') 
		{sumas++;}
		if (a=='P' || a=='p') 
		{sumap++;}
	}
	    

	printf("Ukupno evidentirano %d vozila. \n", suma);
	if(suma==0) 
	{printf("Najpopularnija boja je crna (0.00%%).");}
	else {
		if(sumac>=sumab && sumac>=sumas && sumac>=sumav && sumac>=sumap) 
		{printf("Najpopularnija boja je crna (%.2f%%).", ((float)sumac/suma)*100);}
	
	if(sumab>sumac && sumab>=sumas && sumab>=sumav && sumab>=sumap) 
	{printf("Najpopularnija boja je bijela (%.2f%%).", ((float)sumab/suma)*100);}
	if(sumas>sumac && sumas>sumab && sumas>=sumav && sumas>=sumap) 
	{printf("Najpopularnija boja je siva (%.2f%%).", ((float)sumas/suma)*100);}
	if(sumav>sumac && sumav>sumab && sumav>sumas && sumav>=sumap) 
	{printf("Najpopularnija boja je crvena (%.2f%%).", ((float)sumav/suma)*100);}
	if(sumap>sumab && sumap>sumas && sumap>sumav && sumap>sumac) 
	{printf("Najpopularnija boja je plava (%.2f%%).", ((float)sumap/suma)*100);}
	}
	
	return 0;
}

#include <stdio.h>

int main() 
{
	char voz='X';
	int suma=0, sumab=0, sumav=0, sumac=0, sumap=0, sumas=0;
	printf ("Unesite vozila: ");
	for(;;)
	{
		scanf("%c", &voz);
	    if (voz!='b' && voz!='B' && voz!='C'&& voz!='c' && voz!='S' && voz!='s' && voz!='V' && voz!='v' && voz!='P' && voz!='p' && voz!='k' && voz!='K') {printf("Neispravan unos\n");}
		if (voz=='k' || voz=='K') break;
		if (voz=='b' || voz=='B' || voz=='C'|| voz=='c' || voz=='S' || voz=='s' || voz=='V' || voz=='v' || voz=='P' || voz=='p') suma++;
		if (voz=='b' || voz=='B') sumab++;
		if (voz=='v' || voz=='v') sumav++;
		if (voz=='C' || voz=='c') sumac++;
		if (voz=='S' || voz=='s') sumas++;
		if (voz=='P' || voz=='p') sumap++;
		
		
	}
	    

	printf("Ukupno evidentirano %d vozila. \n", suma);
	if(suma==0) {printf("Najpopularnija boja je crna (0.00%%).");}
	else {
		if(sumac>=sumab && sumac>=sumas && sumac>=sumav && sumac>=sumap) {printf("Najpopularnija boja je crna (%.2f%%).", ((float)sumac/suma)*100);}
	
	if(sumab>sumac && sumab>=sumas && sumab>=sumav && sumab>=sumap) {printf("Najpopularnija boja je bijela (%.2f%%).", ((float)sumab/suma)*100);}
	if(sumas>sumac && sumas>sumab && sumas>=sumav && sumas>=sumap) {printf("Najpopularnija boja je siva (%.2f%%).", ((float)sumas/suma)*100);}
	if(sumav>sumac && sumav>sumab && sumav>sumas && sumav>=sumap) {printf("Najpopularnija boja je crvena (%.2f%%).", ((float)sumav/suma)*100);}
	if(sumap>sumab && sumap>sumas && sumap>sumav && sumap>sumac) {printf("Najpopularnija boja je plava (%.2f%%).", ((float)sumap/suma)*100);}
	}
	
  

	return 0;
}

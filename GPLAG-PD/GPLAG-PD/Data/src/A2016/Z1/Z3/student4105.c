#include <stdio.h>

int main() {
	char c;
	int crni_brojac=0, bijeli_brojac=0, sivi_brojac=0, crveni_brojac=0, plavi_brojac=0, ukupno_evidentirano=0;
	printf("Unesite vozila: ");
	
	for(;;) 
	{
		scanf("%c", &c);
		if(c=='C' || c=='c') crni_brojac++; 
		else if(c=='B' || c=='b') bijeli_brojac++;
		else if(c=='S' || c=='s') sivi_brojac++;
		else if(c=='V' || c=='v') crveni_brojac++;
		else if(c=='P' || c=='p') plavi_brojac++;
		else if(c=='K' || c=='k') break;
		else if(c=='\n') continue;
		else {printf("Neispravan unos ") ; printf("\n");}
		
		
	}
	ukupno_evidentirano=crni_brojac+bijeli_brojac+sivi_brojac+crveni_brojac+plavi_brojac;
	printf("Ukupno evidentirano %d vozila.", ukupno_evidentirano);
	printf("\n");
	if(ukupno_evidentirano==0)
	{
		printf("Najpopularnija boja je crna (0.00%%).");
	}
	else if(crni_brojac>=bijeli_brojac && crni_brojac>=sivi_brojac && crni_brojac>=crveni_brojac && crni_brojac>=plavi_brojac) 
	{	float x=(float)(crni_brojac)*100 / (ukupno_evidentirano);
		printf("Najpopularnija boja je crna (%.2f%%).", x);
	}
	else if(bijeli_brojac>=crni_brojac && bijeli_brojac>=sivi_brojac && bijeli_brojac>=crveni_brojac && bijeli_brojac>=plavi_brojac)
		printf("Najpopularnija boja je bijela (%.2f%%).", ((float)(bijeli_brojac) / (ukupno_evidentirano)) * 100);
	else if(sivi_brojac>=crni_brojac && sivi_brojac>=bijeli_brojac && sivi_brojac>=crveni_brojac && sivi_brojac>=plavi_brojac)
		printf("Najpopularnija boja je siva (%.2f%%).", ((float)(sivi_brojac) / (ukupno_evidentirano)) * 100);
	else if(crveni_brojac>=crni_brojac && crveni_brojac>=bijeli_brojac && crveni_brojac>=sivi_brojac && crveni_brojac>=plavi_brojac)
		printf("Najpopularnija boja je crvena (%.2f%%).", ((float)(crveni_brojac) / (ukupno_evidentirano)) * 100);
	else if(plavi_brojac>=crni_brojac && plavi_brojac>=bijeli_brojac && plavi_brojac>=sivi_brojac && plavi_brojac>=crveni_brojac)
		printf("Najpopularnija boja je plava (%.2f%%).", ((float)(plavi_brojac) / (ukupno_evidentirano)) * 100);
	
	
	return 0;
}

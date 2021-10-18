#include <stdio.h>


int main() {
	char boja_auta;
	float crna=0, bijela=0, siva=0, crvena=0, plava=0, broj_auta=0, procenat;
	printf("Unesite vozila: ");
	do
	{
		scanf("%c", &boja_auta);
		if(boja_auta=='B'||boja_auta=='b')
		{
			bijela++;
			continue;
		}
		else if(boja_auta=='s'||boja_auta=='S')
		{
			siva++;
			continue;
		}
		else if(boja_auta=='C'||boja_auta=='c')
		{
			crna++;
			continue;
		}
		else if(boja_auta=='V'||boja_auta=='v')
		{
			crvena++;
			continue;
		}
		else if(boja_auta=='p'||boja_auta=='P') 
		{
			plava++;
			continue;
		}
		else if(boja_auta=='k' || boja_auta=='K')
		{
			break;
		}
		else if(boja_auta!='b'||boja_auta!='B'||boja_auta!='s'||boja_auta!='S'||boja_auta!='c'||boja_auta!='C'||boja_auta!='v'||boja_auta!='V'||boja_auta!='p'||boja_auta!='P')
		{
			printf("Neispravan unos\n");

		}
		
		
	}while(boja_auta!='k' || boja_auta!='K');
	broj_auta=crvena+crna+plava+siva+bijela;
	printf("Ukupno evidentirano %g vozila.\n", broj_auta);
	if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava)
	{
		procenat=(crna/broj_auta)*100;
		printf("Najpopularnija boja je crna (%.2f%%).", procenat);
	}else 
	if(bijela>=crna && bijela>=siva && bijela>=plava && bijela>=crvena)
	{
		procenat=(bijela/broj_auta)*100;
		printf("Najpopularnija boja je bijela (%.2f%%).", procenat);
	}else 
	if(siva>=crna && siva>=bijela && siva>=plava && siva>=crvena)
	{
		procenat=(siva/broj_auta)*100;
		printf("Najpopularnija boja je siva (%.2f%%).", procenat);
	}else 
	if(plava>=crna && plava>=siva && plava>=bijela && plava>=crvena)
	{
		procenat=(plava/broj_auta)*100;
		printf("Najpopularnija boja je plava (%.2f%%).", procenat);
	}else 
	if(crvena>=crna && crvena>=siva && crvena>=plava && crvena>=bijela)
	{
		procenat=(crvena/broj_auta)*100;
		printf("Najpopularnija boja je crvena (%.2f%%).", procenat);
	}
/*C - crna
  B - bijela
  S - siva
  V - crvena
  P - plava 
  K - kraj unosa
*/
	
	return 0;
}

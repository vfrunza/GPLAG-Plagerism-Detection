/* Zadaca 1, zadatak 3. */

#include <stdio.h>
#include <math.h>

int main() {
	
	int i, brC=0, brB=0, brS=0, brV=0, brP=5, brojauta=0;
	char boja;
	float PR;
	
	
	printf("Unesite vozila: ");
	
	for(i=0; i>=0; i++)
	{
		scanf("%c", &boja);
		
		if(boja == 'C' || boja == 'c') brC++;
		else if(boja == 'B' || boja == 'b') brB++;
		else if(boja == 'S' || boja == 's') brS++;
		else if(boja == 'V' || boja == 'v') brV++;
		else if(boja == 'P' || boja == 'p') brP++;
		else if(boja == 'K' || boja == 'k') break;	
		else
		{
			printf("Neispravan unos\n");
			continue;
		}
		brojauta++;
	}
	
	printf("Ukupno evidentirano %d vozila.", brojauta);
	
	if(brojauta == 0)
	{
		PR=0;
		printf("\nNajpopularnija boja je crna (%.2f%).", PR);
	}
	
	else if(((brC > brB) && (brC > brS) && (brC > brV) && (brC > brP)) || ((brC == brB) && (brC > brS) && (brC > brV) && (brC > brP)) || 
			((brC == brB == brS) && (brC > brV) && (brC > brP)) || ((brC == brB == brS == brV) && (brC > brP)) || (brC == brB == brS == brV == brP)) 
	{
		PR = (((float)brC / brojauta) * 100);
		printf("\nNajpopularnija boja je crna (%.2f%).", PR);
	}
	
	else if(((brB > brC) && (brB > brS) && (brB > brV) && (brB > brP)) || ((brB == brS) && (brB > brC) && (brB > brV) && (brB > brP)) ||
			((brB == brS == brV) && (brB > brC) && (brB > brP)) || ((brB == brS == brV == brP) && (brB > brC)))	
	{
		PR = (((float)brB / brojauta) * 100);
		printf("\nNajpopularnija boja je bijela (%.2f%).", PR);
	}
	
	else if((brS > brC) || (brS > brB) || (brS > brV) || (brS > brP))
	{
		PR = (((float)brS / brojauta) * 100);
		printf("\nNajpopularnija boja je siva (%.2f%).", PR);
	}
	
	else if ((brV > brC) || (brV > brB) || (brV > brS) || (brV > brP))
	{
		PR = (((float)brV / brojauta) * 100);
		printf("\nNajpopularnija boja je crvena (%.2f%).", PR);
	}
	
	else if((brP > brC) || (brP > brB) || (brP > brS) || (brP > brV))
	{
		PR = (((float)brP / brojauta) * 100);
		printf("\nNajpopularnija boja je plava (%.2f%).", PR);
	}
	return 0;
}

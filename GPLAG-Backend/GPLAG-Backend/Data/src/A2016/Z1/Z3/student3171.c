#include <stdio.h>
#include <math.h>

int main() {
	
	char vozilo='v';
	float brC=0, brB=0, brS=0, brV=0, brP=0, br=0;
	float  x, y;
	x=0;
	
	
	printf("Unesite vozila: ");
	while(vozilo!='k' || vozilo!='K')
	{
		scanf("%c", &vozilo);
		
		if(vozilo=='k' || vozilo=='K') break;
		
		else if(vozilo=='c' || vozilo=='C') 
		{brC++;
		br++;}
		else if(vozilo=='b' || vozilo=='B') 
		{brB++;
		br++;}
		else if(vozilo=='s' || vozilo=='S') 
		{brS++;
		br++;}
		else if(vozilo=='v' || vozilo=='V') 
		{brV++;
		br++;}
		else if(vozilo=='p' || vozilo=='P') 
		{brP++;
		br++;}
		
		else printf("Neispravan unos\n");
	}
	
	
	if(brP>=brC && brP>=brB && brP>=brS && brP>=brV) x=brP;
	else if(brV>=brC && brV>=brB && brV>=brS && brV>=brP) x=brV;
	else if(brS>=brC && brS>=brB && brS>=brV && brS>=brP) x=brS;
	else if(brB>=brC && brB>=brP && brB>=brS && brB>=brV) x=brB;
	else x=brC;
	
	
	printf("Ukupno evidentirano %0.f vozila.\n", br);
	
	if(br==0) 
	{
		printf("Najpopularnija boja je crna (0.00%%).", y);
	}
	else {
	
	if(brC>=brP && brC>=brB && brC>=brS && brC>=brV) 
		{
			y=(x/br)*100;
			printf("Najpopularnija boja je crna (%.2f%%).", y);
		}
	
		
	else if(brB>=brC && brB>=brP && brB>=brS && brB>=brV) 
		{
			y=(x/br)*100;
			printf("Najpopularnija boja je bijela (%.2f%%).", y);
		}	
		
	else if(brS>=brC && brS>=brB && brS>=brP && brS>=brV) 
		{
			y=(x/br)*100;
			printf("Najpopularnija boja je siva (%.2f%%).", y);
		}
		
	else if(brV>=brC && brV>=brB && brV>=brS && brV>=brP) 
		{
			y=(x/br)*100;
			printf("Najpopularnija boja je crvena (%.2f%%).", y);
		}
	
	else if(brP>=brC && brP>=brB && brP>=brS && brP>=brV) 
		{
			y=(x/br)*100;
			printf("Najpopularnija boja je plava (%.2f%%).", y);
		}
	}
	
	return 0;
}

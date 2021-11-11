#include <stdio.h>

int main() {
	char vozilo;
	int i=0,crni=0,crveni=0,bijeli=0,sivi=0,plavi=0;
	float postotak;
	printf("Unesite vozila: ");
	scanf("%c",&vozilo);

	
		while(vozilo!='k' && vozilo!='K')
		{
			
			
				
				if(vozilo=='C' || vozilo=='c')
				{
				
					crni++;
					i++;
				}
				else if(vozilo=='B' || vozilo=='b')
				{
					bijeli++;
					i++;
				}
				else if(vozilo=='V' || vozilo=='v')
				{
					crveni++;
					i++;
				}
				else if(vozilo=='s' || vozilo=='S')
				{
					sivi++;
					i++;
				}
				else if(vozilo=='p' || vozilo=='P')
				{
					plavi++;
					i++;
				}
			
			
		else if(vozilo=='k' || vozilo=='K')
		{
			break;
		}
		else 
		{
			printf("Neispravan unos\n");
			
		}
		scanf("%c",&vozilo);
		}
	

	printf("Ukupno evidentirano %d vozila.\n",i);
	
	if(crni>plavi && crni>crveni && crni>sivi && crni>bijeli)
	{
		postotak=(crni*1.00/i*1.00)*100;
	printf("Najpopularnija boja je crna (%.2f%).",postotak);
		
	}
	else if(bijeli>crni && bijeli>plavi && bijeli>crveni && bijeli >sivi)
	{
	    postotak=(bijeli*1.00/i*1.00)*100;
	    printf("Najpopularnija boja je bijela (%.2f%).",postotak);
	}
	else if(crveni>bijeli && crveni>crni && crveni>sivi && crveni>plavi)
	{
		postotak=(crveni*1.00/i*1.00)*100;
		printf("Najpopularnija boja je crvena (%.2f%).",postotak);
	}
	else if(plavi>crveni && plavi>crni && plavi>bijeli && plavi>sivi)
	{
		postotak=(plavi*1.00/i*1.00)*100;
		printf("Najpopularnija boja je plava (%.2f%).",postotak);
	}
	else if(sivi>plavi && sivi>crni && sivi>crveni && sivi>bijeli)
	{
		postotak=(sivi*1.00/i*1.00)*100;
		printf("Najpopularnija boja je siva (%.2f%).",postotak);
	}
	if(i==0)
	printf("Najpopularnija boja je crna (0.00%).");
	return 0;
}

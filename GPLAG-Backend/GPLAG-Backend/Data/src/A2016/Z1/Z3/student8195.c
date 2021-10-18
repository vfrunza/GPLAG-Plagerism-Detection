#include <stdio.h>

#define SLOVO_C 99
#define SLOVO_c 67
#define SLOVO_K 75
#define SLOVO_k 107
#define SLOVO_S 83
#define SLOVO_s 115
#define SLOVO_B 66
#define SLOVO_b 98
#define SLOVO_V 86
#define SLOVO_v 118
#define SLOVO_p 112
#define SLOVO_P 80

int main() {
	int j=0,crnaCount = 0,bijelaCount = 0,sivaCount=0,crvenaCount=0,plavaCount=0;
	char n;
	int i = 0; 
	printf("Unesite vozila: ");
	double ukupniProcenatCrna = 0.00,ukupniProcenatbijela = 0.00,ukupniProcenatsiva = 0.00,ukupniProcenatcrvena = 0.00,ukupniProcenatplava = 0.00;
	while(1){
		scanf("%c", &n);
		i = (int) n;
		
		if((i == SLOVO_k || i == SLOVO_K)){
			break;
		}
		switch(i){
			case SLOVO_C:
			case SLOVO_c:
				crnaCount++;
				j++;
			break;
			case SLOVO_S:
			case SLOVO_s:
				sivaCount++;
				j++;
			break;
			case SLOVO_B:
			case SLOVO_b:
				bijelaCount++;
				j++;
			break;
			case SLOVO_V:
			case SLOVO_v:
				crvenaCount++;
				j++;
			break;
			case SLOVO_P:
			case SLOVO_p:
				plavaCount++;
				j++;
			break;
			
			default:
				printf("Neispravan unos\n");
			break;
		}
		
	}
	

	printf ("Ukupno evidentirano %d vozila.",j);
	
	ukupniProcenatplava=(double)(((double)plavaCount/(double)j)*100.0);
	ukupniProcenatCrna=(double)(((double)crnaCount/(double)j)*100.0);
	ukupniProcenatcrvena=(double)(((double)crvenaCount/(double)j)*100.0);
	ukupniProcenatbijela=(double)(((double)bijelaCount/(double)j)*100.0);
	ukupniProcenatsiva=(double)(((double)sivaCount/(double)j)*100.0);
	
	 if ((plavaCount==0)&&(crvenaCount==0)&&(crnaCount==0)&&(bijelaCount==0)&&(sivaCount==0))
{	printf ("\nNajpopularnija boja je crna (%.2f%%).",0.00);
	return 0;
	
}
		else if ((ukupniProcenatCrna>=ukupniProcenatplava)&&(ukupniProcenatCrna>=ukupniProcenatsiva)&&(ukupniProcenatCrna>=ukupniProcenatbijela)&&(ukupniProcenatCrna>=ukupniProcenatcrvena))
	{printf ("\nNajpopularnija boja je crna (%.2f%%).",ukupniProcenatCrna);
	
	return 0; }

		else if ((ukupniProcenatbijela>=ukupniProcenatplava)&&(ukupniProcenatbijela>=ukupniProcenatsiva)&&(ukupniProcenatbijela>=ukupniProcenatcrvena))
{   printf ("\nNajpopularnija boja je bijela (%.2f%%).",ukupniProcenatbijela);
	return 0;
	
}
		else if ((ukupniProcenatsiva>=ukupniProcenatplava)&&(ukupniProcenatsiva>=ukupniProcenatcrvena))
	{
		printf ("\nNajpopularnija boja je siva (%.2f%%).",ukupniProcenatsiva);
	return 0;
		
	}
		else if ((ukupniProcenatcrvena>=ukupniProcenatplava)){
	printf ("\nNajpopularnija boja je crvena (%.2f%%).",ukupniProcenatcrvena);
	return 0; 
			
		}
	  else {
	printf ("\nNajpopularnija boja je plava (%.2f%%).",ukupniProcenatplava);
	return 0;
	  	
	  }
		
		
	
		
			
	
	
	
		
	
	
	return 0;
}

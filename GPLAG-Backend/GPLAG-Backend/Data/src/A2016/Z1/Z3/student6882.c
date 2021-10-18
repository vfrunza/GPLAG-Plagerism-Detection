#include <stdio.h>


int main() {

	int broj_auta=0;
	int max_se_ponavlja=0;
	double postotak=0;
	char auta='a';

	int brojacC=0;
	int brojacB=0;
	int brojacS=0;
	int brojacV=0;
	int brojacP=0;
	printf ("Unesite vozila: ");
	 while (auta)
	 {
		scanf("%c",&auta);
		if (auta=='C' || auta=='c') brojacC++;
		else if (auta=='B' || auta =='b') brojacB++;
		else if (auta=='S' || auta =='s') brojacS++;
		else if (auta=='V' || auta =='v') brojacV++;
		else if (auta=='P' || auta =='p') brojacP++;
		else if(auta=='k' || auta=='K') break;
		else  {
				printf ("Neispravan unos\n");
				
			}
		broj_auta=brojacC+brojacB+brojacS+brojacV+brojacP;
	 }


	if(brojacC>=brojacB && brojacC>=brojacS && brojacC>=brojacV && brojacC>=brojacP){
		max_se_ponavlja=brojacC;
	
		
		postotak=((double)(max_se_ponavlja*100))/broj_auta;
			if (max_se_ponavlja!=0) {
			
	printf ("Ukupno evidentirano ");
	printf("%d",broj_auta);
	printf(" vozila.");
	printf ("\n");
	printf ("Najpopularnija boja je crna ");
	printf ("(");
	printf ("%.2f",postotak);
	printf ("%%).");
			}
			else
			{
					printf ("Ukupno evidentirano 0 ");

	printf("vozila.");
	printf ("\n");
	printf ("Najpopularnija boja je crna ");
	printf ("(0.00%%).");


			}
			
	

	}
	else if (brojacB>brojacC && brojacB>=brojacS && brojacB>=brojacV && brojacB>=brojacP)
	{	max_se_ponavlja=brojacB;
	postotak=((double)(max_se_ponavlja*100))/broj_auta;
	printf ("Ukupno evidentirano ");
	printf("%d",broj_auta);
	printf(" vozila.");
	printf ("\n");
	printf ("Najpopularnija boja je bijela ");
	printf ("(");
	printf ("%.2f",postotak);
	printf ("%%).");


	}

	else if (brojacS>brojacC && brojacS>brojacB && brojacS>=brojacV && brojacS>=brojacP)
	{max_se_ponavlja=brojacS;
			postotak=((double)(max_se_ponavlja*100))/broj_auta;
	printf ("Ukupno evidentirano ");
	printf("%d",broj_auta);
	printf(" vozila.");
	printf ("\n");
	printf ("Najpopularnija boja je siva ");
	printf ("(");
	printf ("%.2f",postotak);
	printf ("%%).");
	}

	else if (brojacV>brojacC && brojacV>brojacB && brojacV>brojacS && brojacV>=brojacP)
	{
			max_se_ponavlja=brojacV;
					postotak=((double)(max_se_ponavlja*100))/broj_auta;
	printf ("Ukupno evidentirano ");
	printf("%d",broj_auta);
	printf(" vozila.");
	printf ("\n");
	printf ("Najpopularnija boja je crvena ");
	printf ("(");
	printf ("%.2f",postotak);
	printf ("%%).");
	}


	else
	{
		max_se_ponavlja=brojacP;
	postotak=((double)(max_se_ponavlja*100))/broj_auta;
			printf ("Ukupno evidentirano ");
	printf("%d",broj_auta);
	printf(" vozila.");
	printf ("\n");
	printf ("Najpopularnija boja je plava ");
	printf ("(");
	printf ("%.2f",postotak);
	printf ("%%).");
	}




	return 0;
}

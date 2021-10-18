#include <stdio.h>

int main() {
	/*NOTE: Po autotestu radi ali treba provjeriti jos par puta*/
	
	/*Variable declaration*/
	char input;
	float crnaAuta, bijelaAuta, sivaAuta, crvenaAuta, plavaAuta, sumaAuta, postotak;
	
	/*Inicijalizacija*/
	crnaAuta = 0;
	bijelaAuta = 0;
	sivaAuta = 0;
	crvenaAuta = 0;
	plavaAuta = 0;
	sumaAuta = 0;
	postotak = 0;

	printf("Unesite vozila: ");
	do{
		scanf ("%c", &input);
		
		if ((input == 'c') || (input == 'C'))
		{
			crnaAuta++;
			continue;
		}
		else if ((input == 'b') || (input == 'B'))
		{
			bijelaAuta++;
			continue;
		}
		else if ((input == 's') || (input == 'S'))
		{
			sivaAuta++;
			continue;
		}
		else if ((input == 'v') || (input == 'V'))
		{
			crvenaAuta++;
			continue;
		}
		else if ((input == 'p') || (input == 'P'))
		{
			plavaAuta++;
			continue;
		}
		else if ((input!= 'c' && input !='C')&&(input!= 'b' && input !='B')&&(input!= 's' && input !='S')&&(input!= 'v' && input !='V')&&(input!= 'p' && input !='P')&&(input!='k' && input !='K'))
		{
			printf("Neispravan unos\n");
			continue;
		}
	} while ((input!='k') && (input!='K'));
	
	sumaAuta = crnaAuta + bijelaAuta + sivaAuta + crvenaAuta + plavaAuta;
	printf("Ukupno evidentirano %g vozila.", sumaAuta);
	
	if (sumaAuta == 0){
		postotak = 0;
		printf("\nNajpopularnija boja je crna (%.2f%%).", postotak);
	}
	else if (crnaAuta >= bijelaAuta && crnaAuta >= sivaAuta && crnaAuta >= crvenaAuta && crnaAuta >= plavaAuta)
		{
			postotak = crnaAuta * 100 / (bijelaAuta + crvenaAuta + sivaAuta + plavaAuta + crnaAuta);
			printf("\nNajpopularnija boja je crna (%.2f%%).", postotak);
		}
		
	else if (bijelaAuta >= sivaAuta && bijelaAuta > crnaAuta && bijelaAuta >= crvenaAuta && bijelaAuta >= plavaAuta)
		{
			postotak = bijelaAuta * 100 / (bijelaAuta + crvenaAuta + sivaAuta + plavaAuta + crnaAuta);
			printf("\nNajpopularnija boja je bijela (%.2f%%).", postotak);
		}
	else if (sivaAuta > bijelaAuta && sivaAuta > crnaAuta && sivaAuta >= crvenaAuta && sivaAuta >= plavaAuta)
		{
			postotak = sivaAuta * 100 / (bijelaAuta + crvenaAuta + sivaAuta + plavaAuta + crnaAuta);
			printf("\nNajpopularnija boja je siva (%.2f%%).", postotak);
		}
	
	else if (crvenaAuta > bijelaAuta && crvenaAuta > crnaAuta && crvenaAuta > sivaAuta && crvenaAuta >= plavaAuta)
		{
			postotak = crvenaAuta * 100 / (bijelaAuta + crvenaAuta + sivaAuta + plavaAuta + crnaAuta);
			printf("\nNajpopularnija boja je crvena (%.2f%%).", postotak);
		}
	else if (plavaAuta > bijelaAuta && plavaAuta > crnaAuta && plavaAuta > crvenaAuta && plavaAuta > sivaAuta)
		{
			postotak = plavaAuta * 100 / (bijelaAuta + crvenaAuta + sivaAuta + plavaAuta + crnaAuta);
			printf("\nNajpopularnija boja je plava (%.2f%%).", postotak);
		}

	
	return 0;

}
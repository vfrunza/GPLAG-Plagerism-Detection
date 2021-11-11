#include <stdio.h>

int main() {
	int bc, bb, bs, bv, bp,broj_vozila;
	double postotak;
	char boja;
	bc=0, bb=0, bs=0, bv=0, bp=0;
	printf("Unesite vozila: ");
	for( ; ; ) 
	{
	   scanf("%c", &boja);
	   if(boja=='c' || boja=='C')
   	bc++;
    else if(boja=='B' || boja=='b')
    bb++;
    else if(boja=='S' || boja=='s')
    bs++;
    else if(boja=='V' || boja=='v')
    bv++;
    else if(boja=='P' || boja=='p')
    bp++;
    else if(boja=='k' || boja=='K')
    break;
    else
    printf("Neispravan unos\n");
	}
	broj_vozila=bc+bb+bs+bv+bp;
	printf("Ukupno evidentirano %d vozila.\n",broj_vozila);
		if(broj_vozila==0)
		printf("Najpopularnija boja je crna (0.00%%).");
		else if(bc>=bb && bc>=bs && bc>=bv && bc>=bp)
		{
		postotak=bc*100.00/broj_vozila;
		printf("Najpopularnija boja je crna (%.2f%%).", postotak);
		}
		else if(bb>=bc && bb>=bs && bb>=bv && bb>=bp)
		{
		 postotak=bb*100.00/broj_vozila;
		printf("Najpopularnija boja je bijela (%.2f%%).", postotak);
		}
		else if(bs>=bc && bs>=bb && bs>=bv && bs>=bp)
		{
		 postotak=bs*100.00/broj_vozila;
		printf("Najpopularnija boja je siva (%.2f%%).", postotak);
		}
		else if(bv>=bc && bv>=bs && bv>=bb && bv>=bp)
		{
		 postotak=bv*100.00/broj_vozila;
		printf("Najpopularnija boja je crvena (%.2f%%).", postotak);
		}
		else 
		{
		 postotak=bp*100.00/broj_vozila;
		printf("Najpopularnija boja je plava (%.2f%%).", postotak);
		}
	return 0;
}
